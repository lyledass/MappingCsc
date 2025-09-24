// ChampBitmap.cpp: implementation of the CChampBitmap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampBitmap.h>

LPFIELD_POSITION CopyPosList(LPCFIELD_POSITION pPos, size_t uiCount) {
	LPFIELD_POSITION	pRes = NULL;
	if (pPos) {
		pRes = new FIELD_POSITION[uiCount];
		if (pRes && uiCount>0) {
			memcpy_s(pRes, uiCount*sizeof(pRes[0]), pPos, uiCount*sizeof(pRes[0]));
		}
	}

	return pRes;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampBitmap::CChampBitmap(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescrEx) 
	: CChampEnsemble(lpParent, lpcFieldDescrEx, false), m_bAuthorizeAutoCompute(true)
{
	FIELD_DESCR_EX_V3	bmpDescr;

	// on créé un champ nombre de la taille de l'ensemble pour stocké le bitmap
	// celui-ci :	- a une position relative par rapport à cet ensemble
	//				- prend les conditions associées au descripteur de cet ensemble

	memcpy(&bmpDescr.header, &lpcFieldDescrEx->header, FIELD_DESCR_EX_SIZEOFHEADER_V3);
	bmpDescr.header.prop.type = TYPE_NOMBRE;
	// Copy the pos list, that can be used to read the bitmap field
	bmpDescr.header.posCount = lpcFieldDescrEx->header.posCount;
	bmpDescr.posList = CopyPosList(lpcFieldDescrEx->posList, bmpDescr.header.posCount);
	bmpDescr.condDefValList = lpcFieldDescrEx->condDefValList;

	m_bitmap = new CChampNombre(this, &bmpDescr, false);

	// on désaloue la condition qui a été associée dans le constructeur à l'ensemble
	if ((m_descripteur.header.condCount > 0) && m_descripteur.condDefValList) {
		delete [] m_descripteur.condDefValList;
		m_descripteur.condDefValList = NULL;
		m_descripteur.header.condCount = 0;
	}
}

CChampBitmap::CChampBitmap(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcSetDescrEx, LPCFIELD_DESCR_EX_V3 lpcFieldBitmapDescrEx) 
	: CChampEnsemble(lpParent, lpcSetDescrEx, false), m_bAuthorizeAutoCompute(true)
{
	m_bitmap = NULL;	
	if (lpcFieldBitmapDescrEx) {
		m_bitmap = new CChampNombre(this, lpcFieldBitmapDescrEx, false);
	}

	// on désaloue la condition qui a été associée dans le constructeur à l'ensemble
	if ((m_descripteur.header.condCount > 0) && m_descripteur.condDefValList) {
		delete [] m_descripteur.condDefValList;
		m_descripteur.condDefValList = NULL;
		m_descripteur.header.condCount = 0;
	}
}

CChampBitmap::~CChampBitmap() {
	if (m_bitmap) {
		delete m_bitmap;
		m_bitmap = NULL;
	}
}

void CChampBitmap::SetChamp(int index, CChamp* champ) {
	if ((0 <= index) && (index < m_descripteur.header.prop.len)) {
		m_champs[index] = champ;
		if (champ && champ->m_descripteur.header.prop.bNotInBitmap) {
			// Ce champ ne participe pas au bitmap, on réduit la longueur du champ bitmap
			if (m_bitmap) {
				m_bitmap->m_descripteur.header.prop.len -= 1;
				// nb : on ne réalloue pas le tableau de bits pour l'ajuster à la taille
				// puisque la taille a seulement été diminuée
			}
		}
	}
	else {
		TRACE_WARN(_T("[CChampEnsemble] SetChamp outOfBound index : %i"), index);
	}	
}

TCRD_RESULT CChampBitmap::ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData	userData, 
												LPFIELD_POSITION		lpPos, 
												const CChampReadParam*	pParam) 
{
	FIELD_POSITION	pos;
	int				i;
	TCRD_RESULT		crdRes;
	bool			errCrc;
	bool			bBitmapInit = true;
	int				bitmapBit;
	BOOL			bNotInBitmap;

	crdRes = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);

	// on lit les champs dans l'ordre
	// il serait tentant de faire appel ici à la méthode ReadFromSmartCard de CChampEnsemble
	// mais on ne peut pas car dans le cas de positions fixe, on aurait un décalage du à la présence du bitmap...
	if ((m_descripteur.header.posCount > 0) && (m_descripteur.posList)) {

		// on a des positions fixes, on lit dans les différentes positions
		// jusqu'à ce qu'on ait pas d'erreur de CRC
		errCrc = false;
		for (WORD copie = 0; copie < m_descripteur.header.posCount; copie++) {
			memcpy(&pos, &(m_descripteur.posList[copie]), sizeof(pos));

			// on lit le bitmap depuis la carte
			if (m_bitmap) {
				// CBO : Modif pour la prise en compte de bitmap virtuel dans le mapping
				if (m_descripteur.header.prop.bVirtual == FALSE){
					// on lit le bitmap depuis la carte
					crdRes = m_bitmap->ReadFromSmartCard(pMappingIO, userData, &pos, pParam);
				} else {
					// on va activer les champs en fonctions des conditions du mappings
					m_bitmap->SetToDefautVal();
					crdRes = CRD_RESULT_OK;
				}

/*
				// on vérifie qu'il correspond aux champs lus/écrits par le mapping
				for (i = 0; i < m_descripteur.header.prop.len; i++) {
					if ((*m_bitmap)[i]) {
						if (!m_champs[i]) {
							// on lance une exception
						}
					}
				}
*/

				if (crdRes != CRD_RESULT_OK) {
					return crdRes;
				}

				bitmapBit = 0;
				// on lit les champs définis par le bitmap
				for (i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
					bNotInBitmap = FALSE;
					if (GetChamp(i)) {
						bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;

						if (bNotInBitmap || (*m_bitmap)[bitmapBit]/* || GetChamp(i)->IsPositionFixe()*/) {
							// le bit du bitmap est actif,
							// ou le champ ne participe pas au bitmap
							// If the field has a fixed position and can be read outside the bitmap, it should be "Not in bitmap". ou le champ du bitmap à une position fixée (on peut donc le lire même si le bit est à 0)
							crdRes = GetChamp(i)->ReadFromSmartCard(pMappingIO, userData, &pos, pParam);
						}
					}

					if (!bNotInBitmap)
						bitmapBit++;
				}
			}

			if ((GET_RDR_RESULT(crdRes) == RDR_OK) && (GET_CRD_STATUS(crdRes) == CRD_ERROR_CRC)) {
				// on continu la lecture, pour voir si l'on a plus de chance avec la position suivante
				errCrc = true;
			}
			else {
				// on arrête la lecture dès que l'on a réussi à lire correctement le bloc complet
				// ou en cas d'erreur (non CRC)
				return crdRes;
			}
		}

		if (errCrc) {
			// on a lu tous les champs et on a eu des erreurs de CRC,
			// on indique que la carte est défectueuse
			return CRD_RESULT_MAKE(CRD_ERROR_CRC, RDR_OK);
		}
	}
	else {
		// on a une position relative, on lit par rapport à la position fournie par la fonction
		memcpy(&pos, lpPos, sizeof(pos));

		// on lit le bitmap depuis la carte
		if (m_bitmap) {
			// CBO : Modif pour la prise en compte de bitmap virtuel dans le mapping
			if (m_descripteur.header.prop.bVirtual == FALSE)
				// on lit le bitmap depuis la carte
				crdRes = m_bitmap->ReadFromSmartCard(pMappingIO, userData, &pos, pParam);
			else
				// on va activer les champs en fonctions des conditions du mappings
				m_bitmap->SetToDefautVal();

			crdRes = CRD_RESULT_OK;
			bitmapBit = 0;
			for (i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
				bNotInBitmap = FALSE;
				if (GetChamp(i)) {
					bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;

					if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {
						// le bit du bitmap est actif,
						// ou le champ du bitmap à une position fixée (on peut donc le lire même si le bit est à 0)
						crdRes = GetChamp(i)->ReadFromSmartCard(pMappingIO, userData, &pos, pParam);
					}
				}

				if (!bNotInBitmap)
					bitmapBit++;
			}
		}


		// on met à jour la position de la prochaine lecture
		memcpy(lpPos, &pos, sizeof(pos));
	}

	return crdRes;
}

TCRD_RESULT CChampBitmap::WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData	userData,
											LPFIELD_POSITION			lpPos, 
											bool&						bPosRelativeChange)
{
	FIELD_POSITION	pos;
	TCRD_RESULT		crdRes;
	int			bitmapBit;
	BOOL			bNotInBitmap;

	crdRes = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);

	bPosRelativeChange = ComputeBitmapVal() || m_bModified || bPosRelativeChange;
	/*
	if (m_bitmap->m_instance.modified) {
		// le bitmap a été modifié,
		// on marque tout les champs de l'ensemble comme modifié
		SetModified(true);
	}
	*/

	// on écrit les champs dans l'ordre de parsing
	if ((m_descripteur.header.posCount > 0) && (m_descripteur.posList)) {
		// on a des positions fixes, on écrit dans toutes les positions
		// jusqu'à ce qu'on ait pas d'erreur de CRC
		crdRes = CRD_RESULT_OK;
		for (WORD copie = 0; (copie < m_descripteur.header.posCount) && (crdRes == CRD_RESULT_OK); copie++) {
			memcpy(&pos, &(m_descripteur.posList[copie]), sizeof(pos));
			
			// On a une position fixe, donc le champs suivant n'est pas décalé
			bPosRelativeChange = false;

			// on écrit le bitmap
			crdRes = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);
			if (m_bitmap) {
				crdRes = m_bitmap->WriteToSmartCard(pMappingIO, userData, &pos, bPosRelativeChange);
			}

			if (crdRes == CRD_RESULT_OK) {
				bitmapBit = 0;
				for (int i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
					bNotInBitmap = FALSE;
					if (GetChamp(i)) {
						bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;

						if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {
							// le bit du bitmap est actif,
							// ou le champ du bitmap à une position fixée (on peut donc l'écrire même si le bit est à 0)
						
							crdRes = GetChamp(i)->WriteToSmartCard(pMappingIO, userData, &pos, bPosRelativeChange);
						}
					}

					if (!bNotInBitmap)
						bitmapBit++;
				}
			}
			else {
				TRACE_ERROR(_T("Write Bitmap failed"));
			}
		}
	}
	else {
		// on a une position relative, on écrit par rapport à la position fournie par la fonction
		memcpy(&pos, lpPos, sizeof(pos));

		// on écrit le bitmap
		crdRes = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);
		if (m_bitmap) {
			crdRes = m_bitmap->WriteToSmartCard(pMappingIO, userData, &pos, bPosRelativeChange);
		}

		if (crdRes == CRD_RESULT_OK) {
			bitmapBit = 0;
			for (int i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
				bNotInBitmap = FALSE;
				if (GetChamp(i)) {
					bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;
					if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {
						// le bit du bitmap est actif,
						// ou le champ du bitmap à une position fixée (on peut donc l'écrire même si le bit est à 0)

						// on écrit le champ
						crdRes = GetChamp(i)->WriteToSmartCard(pMappingIO, userData, &pos, bPosRelativeChange);
					}
				}

				if (!bNotInBitmap)
					bitmapBit++;
			}
		}
		else {
			TRACE_ERROR(_T("Write Bitmap failed"));
		}

		// on met à jour la position de la prochaine écriture
		memcpy(lpPos, &pos, sizeof(pos));
	}

	return crdRes;
}

void CChampBitmap::WriteToSmartCardCommit() {
	// on écrit le bitmap
	if (m_bitmap) {
		m_bitmap->WriteToSmartCardCommit();
	}

	// on écrit les champs de l'ensemble
	CChampEnsemble::WriteToSmartCardCommit();
}

CChamp*	CChampBitmap::MakeCopie(CChamp* lpParentCopie) const {
	CChampBitmap* copie;
	
	// on copie le Bitmap
	copie = new CChampBitmap(lpParentCopie, &m_descripteur, NULL);
	if (copie) {
		// on alloue le champ bitmap avec une copie de l'autre
		copie->m_bitmap = (CChampNombre*) m_bitmap->MakeCopie(copie);

		CChampEnsemble::MakeSetCopie(copie);
	}


	return copie;
}

bool CChampBitmap::ComputeBitmapVal() {
	BYTE	bitVal;
	int		bitmapBit;
	int		oldValBitmap;
	bool	bBitmapValHasChanged = false;
	BOOL	bNotInBitmap;
	CChampNombre *pOldBitmap;

	if (m_bitmap && m_bAuthorizeAutoCompute) {

		// CBO : gestion des profils Intercode 2 reprise des modifs de JFL
		// JFL 04/04/08 : on enregistre l'ancienne valeur du bitmap pour voit s'il va être modifier
		oldValBitmap = m_bitmap->GetVal();
		pOldBitmap = (CChampNombre*)m_bitmap->MakeCopie(NULL);

		if (m_bitmap->m_descripteur.header.condCount > 0) {
			m_bitmap->SetToDefautVal();
		}
		else if (m_bModified) {
			// au moins un des champs de l'ensemble composant le bitmap a été modifié,
			// on calcul la valeur du bitmap
			bitmapBit = 0;
			for (int i = 0; i < m_descripteur.header.prop.len; i++) {
				bitVal = 0;
				bNotInBitmap = FALSE;
				if (GetChamp(i)) {
					bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;
					if(!bNotInBitmap){
						//Le champ est dans le bitmap
						if (!GetChamp(i)->IsNull()) {
							// le champ n'est pas nul
							bitVal = 1;
						} else if (pOldBitmap && (*pOldBitmap)[bitmapBit]) {
							// On ne désactive pas un champ déjà activé
							bitVal = 1;
						}
					}
				}
				if (!bNotInBitmap) {
					m_bitmap->SetBitVal(bitmapBit, bitVal);
					bitmapBit++;
				}
			}

			if(m_bitmap->GetVal()!= 0){
				//Un des champs du bitmap est non null, on met donc à jour les champs obligatoires
				bitmapBit = 0;
				for (int i = 0; i < m_descripteur.header.prop.len; i++) {
					bitVal = 0;
					bNotInBitmap = FALSE;
					if (GetChamp(i)) {
						bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;
						if(!bNotInBitmap){
							if (GetChamp(i)->GetNeededType() == MAPNEEDED_NEEDEDTOINIT) {
								// le champ doit être présent
								bitVal = 1;
								m_bitmap->SetBitVal(bitmapBit, bitVal);
							}
						}
					}
					if (!bNotInBitmap) {
						bitmapBit++;
					}
				}
			}
		}
		// CBO : gestion des profils Intercode 2 reprise des modifs de JFL
		//JFL 04/04/08 : on vérifie si le bitmap a changé
		if(oldValBitmap != m_bitmap->GetVal())
		{
			bBitmapValHasChanged = true;
		}

		if (pOldBitmap) {
			delete pOldBitmap;
			pOldBitmap = NULL;
		}
	}	

	return bBitmapValHasChanged;
}



void CChampBitmap::ResetFields(BYTE fieldIdType, int fieldInst) {
	// On reset les sous-champs
	CChampEnsemble::ResetFields(fieldIdType, fieldInst);

	// On reset le bitmap
	m_bitmap->ResetFields(fieldIdType, fieldInst);
}

void CChampBitmap::Reset() {
	// On reset les sous-champs
	CChampEnsemble::Reset();

	// On reset le bitmap
	if (m_bitmap) {
		m_bitmap->Reset();
	}
}

bool CChampBitmap::IsNull() const {
	if (!m_bitmap->IsNull())
		return false;

	for (int i = 0; i < m_descripteur.header.prop.len; i++) {
		if (GetChamp(i) && !GetChamp(i)->IsNull())
			return false;
	}
	
	return true;
}

void CChampBitmap::SetValNone() {
	m_bitmap->SetValNone();
}

void CChampBitmap::SetModified(bool modified) {
	if (m_bitmap) {
		m_bitmap->SetModified(modified);
	}

	CChampEnsemble::SetModified(modified);
}

bool CChampBitmap::IsModified()
{
	bool bRes = false;

	if (m_bitmap) {
		bRes = m_bitmap->IsModified();
	}

	if(!bRes){
		bRes = CChampEnsemble::IsModified();
	}

	return bRes;
}

void CChampBitmap::SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance) {
	if (m_bitmap) {
		m_bitmap->SetModifiedGroup(modified, fieldIdMin, fieldIdMax, instance);
	}

	CChampEnsemble::SetModifiedGroup(modified, fieldIdMin, fieldIdMax, instance);
}

bool CChampBitmap::UpdateFromModifiedCopy(const CChamp*	lpCopie) {
	bool				res;
	CChampBitmap*		lpSetCopie;

	res = CChampEnsemble::UpdateFromModifiedCopy(lpCopie);
	if (res) {

		lpSetCopie = (CChampBitmap*) lpCopie;
		if (lpSetCopie) {

			// on met à jour le bitmap
			res = m_bitmap->UpdateFromModifiedCopy(lpSetCopie->m_bitmap);
			if (res && m_bitmap->IsNull())
				ComputeBitmapVal();
		}
	}

	return res;
}

CChamp*	CChampBitmap::GetChampById(WORD fieldId, int fieldInst) const {
	CChamp*		fieldRes;
	CChamp*		lpSubField;
	long		bitmapVal;
	int			bitmapBit;
	BOOL		bNotInBitmap;

	fieldRes = NULL;
	
	// on a une demande ascendante qui ne vient pas du bitmap, ou une demande descendante
	// on test le bitmap,
	if (m_bitmap) {
		fieldRes = m_bitmap->GetChampById(fieldId, fieldInst);
		if (fieldRes) {
			return fieldRes;
		}

		// on regarde dans les enfants
		// return CChampEnsemble::GetChampById(fieldId, fieldInst);
		// TOTEST :
		bitmapVal = m_bitmap->GetInstLongValue();
		//SNO 20/05/09 Dans le cas où le bitmap à des conditions et une valeur nul
		//Le bitmap a de grande chande de ne pas être initialisé, on fait donc un compute 
		if (m_bitmap->m_descripteur.header.condCount > 0 
			&& bitmapVal == 0){
			//&& m_bitmap->m_descripteur.header.prop.bVirtual == FALSE){
			((CChampBitmap*)this)->ComputeBitmapVal();
			bitmapVal = m_bitmap->GetInstLongValue();
		}

		bitmapBit = 0;
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {

			bNotInBitmap = FALSE;
			lpSubField = GetChamp(i);
			if (lpSubField) {
				bNotInBitmap = lpSubField->m_descripteur.header.prop.bNotInBitmap;
				// Si bitmap <> 0, alors on l'utilise pour n'accèder qu'aux champs actifs
				// Si bitmap == 0, alors par défaut on permet l'accès à tous les champs.
				//SNO => Seulement si le bitmap n'a aucune conditions

				if ((m_bitmap->m_descripteur.header.condCount == 0 && bitmapVal == 0) 
					|| bNotInBitmap 
					|| (*m_bitmap)[bitmapBit]
					|| lpSubField->GetNeededType() == MAPNEEDED_NEEDEDTOACCESS) { //Champs toujours accessible
					// le bitmap n'a pas de valeur,
					// ou le champs ne participe pas au bitmap
					// ou le bit est activé
					fieldRes = lpSubField->GetChampById(fieldId, fieldInst);
					if (fieldRes) {
						return fieldRes;
					}
				}
			}

			if (!bNotInBitmap) 
				bitmapBit++;
		}
	}

	return NULL;
}

CChamp*	CChampBitmap::GetChampByUNId(DWORD fieldUNId, BYTE lookFlag, const CChamp* excluded) const {
	CChamp*		fieldRes;

	fieldRes = NULL;
	
	if ((lookFlag == LOOKFIELD_UP) && excluded && (excluded == m_bitmap)) {
		// on a une recharche ascendante qui vient du bitmap, on passe directement la demande au parent
		if (m_lpParent) {
			fieldRes = m_lpParent->GetChampByUNId(fieldUNId, LOOKFIELD_UP, this);
		}
	}
	else {
		// on a une demande ascendante qui ne vient pas du bitmap, ou une demande descendante
		// on test le bitmap,
		if (m_bitmap) {
			fieldRes = m_bitmap->GetChampByUNId(fieldUNId, LOOKFIELD_DOWN);
			if (fieldRes) {
				return fieldRes;
			}
		}

		// on test les enfant et/ou le parent.
		fieldRes = CChampEnsemble::GetChampByUNId(fieldUNId, lookFlag, excluded);
	}

	return fieldRes;
}

#define BITMAPFIELD_GET_IMAGE(pCodeImgList, bRes)	{long		i;\
	int			bitmapBit;\
	BOOL	bNotInBitmap;\
\
	if (m_bitmap) {\
		m_bitmap->GetImage(pCodeImgList);\
		\
		bitmapBit = 0;\
		for (i = 0; i < m_descripteur.header.prop.len; i++) {\
\
			bNotInBitmap = FALSE;\
			if (GetChamp(i)) {\
				bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;\
\
				if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {\
					/* le bit du bitmap est actif,
					/* ou le champs ne participe pas au bitmap
					/* ou le champ du bitmap à une position fixée (on peut donc le lire même si le bit est à 0)*/\
					if (!GetChamp(i)->GetImage(pCodeImgList)) {\
						bRes = false;\
					}\
				}\
			}\
\
			if (!bNotInBitmap) \
				bitmapBit++;\
		}\
	}\
}

bool CChampBitmap::GetImage(CListExt<long>* pCodeImgList) const {
	bool	bRes = true;

	BITMAPFIELD_GET_IMAGE(pCodeImgList, bRes);

	return bRes;
}

bool CChampBitmap::GetImage(CListExt<INT64>* pCodeImgList) const {
	bool	bRes = true;

	BITMAPFIELD_GET_IMAGE(pCodeImgList, bRes);

	return bRes;
}

#define	BITMAPFIELD_SET_IMAGE(pCodeImgList, pParam)	{\
	CChampEnsemble::SetImage(pCodeImgList, pParam);\
\
	if (m_bitmap) {\
		m_bitmap->SetImage(pCodeImgList, pParam);\
		if (m_bitmap->IsNull()) {\
			ComputeBitmapVal();\
		}\
	}\
}

void CChampBitmap::SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam) {
	BITMAPFIELD_SET_IMAGE(pCodeImgList, pParam);
}

void CChampBitmap::SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam) {
	BITMAPFIELD_SET_IMAGE(pCodeImgList, pParam);
}

void CChampBitmap::SetToDefautBitmapVal() {
	int		bitmapBit;
	BOOL	bNotInBitmap;

	ComputeBitmapVal();

	bitmapBit = 0;
	for (int i = 0; i < m_descripteur.header.prop.len; i++) {

		bNotInBitmap = FALSE;
		if (GetChamp(i)) {
			bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;

			if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {
				// le bit du bitmap est actif,
				// ou le champ du bitmap à une position fixée (on peut donc l'écrire même si le bit est à 0)
					
				GetChamp(i)->SetToDefautBitmapVal();
			}
		}

		if (!bNotInBitmap)
			bitmapBit++;
	}
}

void CChampBitmap::SetAuthorizeAutoCompute(bool bAuthorizeAutoCompute) {
	m_bAuthorizeAutoCompute = bAuthorizeAutoCompute;
}

LPTSTR CChampBitmap::ToXml() const {
	LPTSTR		szXml;
	LPTSTR		szChildXml;
	LPTSTR		szFieldXml;
	LPTSTR		szTmp;
	CChamp*		pSubField;
	TCHAR		szBitVal[255];
	int			bitmapBit;
	BOOL		bNotInBitmap;

	szXml = NULL;
	if (m_champs && m_bitmap) {
		szChildXml = NULL;
		memset(szBitVal, 0, sizeof(szBitVal));

		// On met le caractère espace dans tous les caractères par défaut
		// Sinon vu que dans la boucle suivante on part du milieu de la chaine
		// et qu'on n'inscrit rien si le sous-champ est virtuel,
		// on risque d'avoir un caractère \0 en début de chaine.
		// Là au moins on aure un espace.
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			szBitVal[i] = _T(' ');
		}
		
		bitmapBit = 0;
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			//szBitVal[m_descripteur.header.prop.len - bitmapBit - 1] = _T(' ');

			bNotInBitmap = FALSE;
			pSubField = GetChamp(i);
			if (pSubField) {
				bNotInBitmap = pSubField->m_descripteur.header.prop.bNotInBitmap;
				if (!bNotInBitmap) {
					szBitVal[m_descripteur.header.prop.len - bitmapBit - 1] = _T('0');
				}

				if (bNotInBitmap || (*m_bitmap)[bitmapBit] || pSubField->IsPositionFixe()) {
					if (!bNotInBitmap) {
						szBitVal[m_descripteur.header.prop.len - bitmapBit - 1] = _T('1');
					}

					szFieldXml = pSubField->ToXml();
					if (szFieldXml) {

						szTmp = NULL;
						if (szChildXml)
							stprintf_alloc(&szTmp, _T("%s\r\n%s"), szChildXml, szFieldXml);
						else
							stprintf_alloc(&szTmp, _T("%s"), szFieldXml);

						if (szTmp) {
							free(szChildXml);
							szChildXml = szTmp;
						}

						free(szFieldXml);
					}
				}
			}
			else {
				// Si le champ est null, on considère qu'il n'est pas virtuel
				// Mais que c'est un champ avec taille à 0
				szBitVal[m_descripteur.header.prop.len - bitmapBit - 1] = _T('0');
			}
			if (!bNotInBitmap)
				bitmapBit++;
		}

		if (!m_descripteur.header.prop.bVirtual) {
			// Bitmap réél, on l'affiche	
			if (szChildXml) {
				stprintf_alloc(	&szXml, _T("<Bitmap value='%sb'>\r\n%s\r\n</Bitmap>"), 
								szBitVal,
								szChildXml);
			}
			else {
				stprintf_alloc(	&szXml, _T("<Bitmap value='%sb'></Bitmap>"), 
								szBitVal);
			}
		}
		else {
			// Bitmap virtuel, on n'affiche	que les enfants
			if (szChildXml) {
				stprintf_alloc(	&szXml, _T("%s"), 
								szChildXml);
			}
		}
	}

	return szXml;
}

bool CChampBitmap::BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos)
{
	FIELD_POSITION	pos;
	int				i;
	bool			bRes;
	int				bitmapBit;
	BOOL			bNotInBitmap;

	bRes = false;
	if (pGenericFunction && m_bitmap) {
		//initialisation du bitmap pour la VPC
		if(m_descripteur.header.prop.bVirtual == TRUE){
			ComputeBitmapVal();
		}
		// on lit les champs dans l'ordre
		// il serait tentant de faire appel ici à la méthode ReadFromSmartCard de CChampEnsemble
		// mais on ne peut pas car dans le cas de positions fixe, on aurait un décalage du à la présence du bitmap...
		if ((m_descripteur.header.posCount > 0) && (m_descripteur.posList)) {
			bRes = true;
			// on a des positions fixes, on exécute la fonction sur les différentes positions
			for (WORD copie = 0; (copie < m_descripteur.header.posCount) && bRes; copie++) {
				memcpy(&pos, &(m_descripteur.posList[copie]), sizeof(pos));

				// on applique la fonction au champ bitmap
					bRes = m_bitmap->BrowseTreeGeneric(pGenericFunction, pArgsIn, pArgsOut, &pos);

					bitmapBit = 0;
					// on lit les champs définis par le bitmap
					for (i = 0; (i < m_descripteur.header.prop.len) && bRes; i++) {
						bNotInBitmap = FALSE;
						if (GetChamp(i)) {
							bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;

							if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {
								// le bit du bitmap est actif,
								// ou le champ ne participe pas au bitmap
								// ou le champ du bitmap à une position fixée (on peut donc le lire même si le bit est à 0)
								bRes = GetChamp(i)->BrowseTreeGeneric(pGenericFunction, pArgsIn, pArgsOut, &pos);
							}
						}

						if (!bNotInBitmap)
							bitmapBit++;
					}
			}
		} else if (pActualPos) {
			bRes = true;
			// on a une position relative, on lit par rapport à la position fournie par la fonction
			memcpy(&pos, pActualPos, sizeof(pos));
			// on lit le bitmap depuis la carte
				bRes = m_bitmap->BrowseTreeGeneric(pGenericFunction, pArgsIn, pArgsOut, &pos);

				bitmapBit = 0;
				for (i = 0; (i < m_descripteur.header.prop.len) && bRes; i++) {
					bNotInBitmap = FALSE;
					if (GetChamp(i)) {
						bNotInBitmap = GetChamp(i)->m_descripteur.header.prop.bNotInBitmap;

						if (bNotInBitmap || (*m_bitmap)[bitmapBit] || GetChamp(i)->IsPositionFixe()) {
							// le bit du bitmap est actif,
							// ou le champ du bitmap à une position fixée (on peut donc le lire même si le bit est à 0)
							bRes = GetChamp(i)->BrowseTreeGeneric(pGenericFunction, pArgsIn, pArgsOut, &pos);
						}
					}
					if (!bNotInBitmap)
						bitmapBit++;
				}
			// on met à jour la position de la prochaine exécution
			memcpy(pActualPos, &pos, sizeof(pos));
		}
	}

	return bRes;
}

size_t CChampBitmap::GetFieldBitsLen(bool bOnlyPhysical) const {
	size_t	uiTotalLen = 0;

	// Size of the bitmap field
	if (m_bitmap) {
		uiTotalLen = m_bitmap->GetFieldBitsLen(bOnlyPhysical);
	}

	for(UINT i=0; i<m_descripteur.header.prop.len; ++i) {
		if (GetChamp(i)) {
			uiTotalLen += GetChamp(i)->GetFieldBitsLen(bOnlyPhysical);
		}
	}

	return uiTotalLen;
}
