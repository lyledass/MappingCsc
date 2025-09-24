// ChampEnsemble.cpp: implementation of the CChampEnsemble class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampEnsemble.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampEnsemble::CChampEnsemble(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx, bool bAtomic)
	: CChamp(lpParent, lpcFieldDescrEx)
{
	m_champs = new CChamp* [lpcFieldDescrEx->header.prop.len];
	if (m_champs)
		memset(m_champs, NULL, lpcFieldDescrEx->header.prop.len * sizeof(CChamp*));

	m_bModified = FALSE;
	m_bAtomic = bAtomic;
}

CChampEnsemble::~CChampEnsemble() {
	if (m_champs) {
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			if (m_champs[i]) {
				delete m_champs[i];
				m_champs[i] = NULL;
			}
		}
		delete [] m_champs;
		m_champs = NULL;
	}
}

CChamp*	CChampEnsemble::GetChamp(int index) const {
	if (m_champs && (0 <= index) && (index < m_descripteur.header.prop.len))
		return m_champs [index];

	return NULL;
}

void CChampEnsemble::SetChamp(int index, CChamp* champ) {
	if ((0 <= index) && (index < m_descripteur.header.prop.len)) {
		m_champs[index] = champ;
	}
	else {
		TRACE_WARN(_T("[CChampEnsemble] SetChamp outOfBound index : %i"), index);
	}
}

CChamp*	CChampEnsemble::MakeCopie(CChamp*	lpParentCopie) const {
	CChampEnsemble* copie;
	
	copie = new CChampEnsemble(lpParentCopie, &m_descripteur, m_bAtomic);

	return MakeSetCopie(copie);
}

void CChampEnsemble::ResetFields(BYTE fieldIdType, int fieldInst) {
	for (int i = 0; i < m_descripteur.header.prop.len; i++) {
		if (m_champs[i])
			m_champs[i]->ResetFields(fieldIdType, fieldInst);
	}

}

void CChampEnsemble::Reset() {
	// on regarde si l'ensemble est actif ou non (en vérifiant les conditions associées)...
/*	if (IsConditionsFullFilled()) {
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			if (m_champs[i])
				m_champs[i]->Reset();
		}
	}
*/
	for (int i = 0; i < m_descripteur.header.prop.len; i++) {
		if (m_champs[i])
			m_champs[i]->Reset();
	}
}

bool CChampEnsemble::IsNull() const {
	for (int i = 0; i < m_descripteur.header.prop.len; i++) {
		if (m_champs[i] && !m_champs[i]->IsNull())
			return false;
	}
	
	return true;
}

CChampEnsemble*	CChampEnsemble::MakeSetCopie(CChampEnsemble* copie) const {
	if (copie) {
		for (int i = 0; i < copie->m_descripteur.header.prop.len; i++) {
			copie->m_champs[i] = NULL;	
			if (m_champs[i])
				copie->m_champs[i] = m_champs[i]->MakeCopie(copie);
		}

		copie->m_bModified = m_bModified;
	}

	return copie;
}

bool CChampEnsemble::UpdateFromModifiedCopy(const CChamp*	lpCopie) {
	bool				res;
	CChampEnsemble*		lpSetCopie;

	res = CChamp::UpdateFromModifiedCopy(lpCopie);
	if (res) {
		// on met à jour chacun des champs
		lpSetCopie = (CChampEnsemble*) lpCopie;
		if (lpSetCopie) {
			if (lpSetCopie->m_bModified) {
				res = true;
				for (int i = 0; i < m_descripteur.header.prop.len; i++) {
					if (m_champs[i]) {
						res = res && m_champs[i]->UpdateFromModifiedCopy(lpSetCopie->m_champs[i]);
					}
				}
			}
		}
	}

	return res;
}

class CVirtualMappingIO : public IMappingIO {
public:
	CVirtualMappingIO(size_t uiBitsLen, BIT* pData) : m_pData(pData), m_uiBitsLen(uiBitsLen) {}
	virtual ~CVirtualMappingIO() {}

	virtual TCRD_RESULT Read(unsigned int iP1, unsigned int iP2, size_t uDataLen, LPBIT pOutData, TUserData userData) {
		if (m_pData && m_uiBitsLen >= (iP2+uDataLen)) {
			memcpy(pOutData, &m_pData[iP2], uDataLen);
			return CRD_RESULT_OK;
		} else {
			return CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);
		}
	}

	virtual TCRD_RESULT Write(unsigned int iP1, unsigned int iP2, size_t uDataLen, LPCBIT pInData, TUserData userData) {
		if (m_pData && m_uiBitsLen >= (iP2+uDataLen)) {
			memcpy_s(&m_pData[iP2], m_uiBitsLen-iP2, pInData, uDataLen);
			return CRD_RESULT_OK;
		} else {
			return CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);
		}
	}

	virtual bool IsPosP2InBits() const {
		return true;
	}

private:
	BIT*	m_pData;
	size_t	m_uiBitsLen;
};

TCRD_RESULT CChampEnsemble::ReadAtomicField(	IMappingIO *pMappingIO,
												TUserData	userData,
												const FIELD_POSITION*	lpPos, 
												const CChampReadParam*	pParam)
{
	size_t			uiBitsLen = 0;
	TCRD_RESULT		res = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_ERROR);

	if (pMappingIO && lpPos) {

		uiBitsLen = GetFieldBitsLen(true);

		// Read every child field
		if (uiBitsLen > 0) {
			BIT* pData = new BIT[uiBitsLen];
			if (pData) {
				res = pMappingIO->Read(lpPos->fileId, lpPos->filePos, uiBitsLen, pData, userData);

				if (res == CRD_RESULT_OK) {
					TRACE_BITS_READ(m_descripteur, pData, uiBitsLen, lpPos);

					CVirtualMappingIO	virtualMappingIO(uiBitsLen, pData);
					FIELD_POSITION		fieldPos;
					fieldPos.fileId = FIELD_POS_UNFIXED;
					fieldPos.filePos = 0;

					for (int i = 0; (i < m_descripteur.header.prop.len) && res == CRD_RESULT_OK; i++) {
						CChamp* pChamp = GetChamp(i);
						if (pChamp) {
							res = pChamp->ReadFromSmartCard(&virtualMappingIO, NULL, &fieldPos, pParam);
						}
					}
				}

				delete[] pData;
			}
		} else {
			TRACE_DEBUG(_T("Nothing to read"));
			res = CRD_RESULT_OK;
		}
	}

	return res;
}

TCRD_RESULT CChampEnsemble::WriteAtomicField(	IMappingIO *pMappingIO,
												TUserData	userData,
												const FIELD_POSITION*	lpPos)
{
	size_t			uiBitsLen = 0;
	TCRD_RESULT		res = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_ERROR);

	if (pMappingIO && lpPos) {

		uiBitsLen = GetFieldBitsLen(true);

		// Read every child field
		if (uiBitsLen > 0) {
			BIT* pData = new BIT[uiBitsLen];
			if (pData) {
				memset(pData, 0, uiBitsLen);

				CVirtualMappingIO	virtualMappingIO(uiBitsLen, pData);
				bool	bPosRelativeChange = false;
				FIELD_POSITION		fieldPos;

				fieldPos.fileId = FIELD_POS_UNFIXED;
				fieldPos.filePos = 0;

				res = CRD_RESULT_OK;
				for (int i = 0; (i < m_descripteur.header.prop.len) && res == CRD_RESULT_OK; i++) {
					CChamp* pChamp = GetChamp(i);
					if (pChamp) {
						res = pChamp->WriteToSmartCard(&virtualMappingIO, NULL, &fieldPos, bPosRelativeChange);
					}
				}

				if (res == CRD_RESULT_OK) {
					res = pMappingIO->Write(lpPos->fileId, lpPos->filePos, uiBitsLen, pData, userData);
					if (res == CRD_RESULT_OK) {
						TRACE_BITS_WRITTEN(m_descripteur, pData, uiBitsLen, lpPos);
					}
				}

				delete[] pData;
			}
		} else {
			TRACE_DEBUG(_T("Nothing to write"));
			res = CRD_RESULT_OK;
		}
	}

	return res;
}

TCRD_RESULT CChampEnsemble::ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData	userData,
										LPFIELD_POSITION		lpPos, 
										const CChampReadParam*	pParam) 
{
	FIELD_POSITION	pos;
	bool			errCrc;
	TCRD_RESULT		crdRes;

	crdRes = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);

	// on regarde si l'ensemble est actif ou non (en vérifiant les conditions associées)...
//	if (IsConditionsFullFilled()) {

		// on lit les champs dans l'ordre
		if ((m_descripteur.header.posCount > 0) && (m_descripteur.posList)) {
			// on a des positions fixes, on lit dans les différentes positions
			// jusqu'à ce qu'on ait pas d'erreur de CRC
			errCrc = false;
			for (WORD copie = 0; copie < m_descripteur.header.posCount; copie++) {
				memcpy(&pos, &(m_descripteur.posList[copie]), sizeof(pos));

				if (m_bAtomic) {
					crdRes = ReadAtomicField(pMappingIO, userData, &pos, pParam);
				} else {
					crdRes = CRD_RESULT_OK;
					for (int i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
						if (GetChamp(i))
							crdRes = m_champs[i]->ReadFromSmartCard(pMappingIO, userData, &pos, pParam);
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
		else if (!m_bAtomic) {
			// on a une position relative, on lit par rapport à la position fournie par la fonction
			if (lpPos) {
				memcpy(&pos, lpPos, sizeof(pos));
			}

			crdRes = CRD_RESULT_OK;
			for (int i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
				if (GetChamp(i))
					crdRes = m_champs[i]->ReadFromSmartCard(pMappingIO, userData, lpPos ? &pos : NULL, pParam);
			}

			if (lpPos) {
				// on met à jour la position de la prochaine lecture
				memcpy(lpPos, &pos, sizeof(pos));
			}
		} else {
			TRACE_ERROR(_T("Field UNID %lu has no fixed position but it is an atomic Data/Field"), m_descripteur.header.unidFieldId);
			crdRes = CRD_RESULT_MAKE(CRD_ERROR_UNKNOWN, RDR_OK);
		}
//	}

	return crdRes;
}

TCRD_RESULT CChampEnsemble::WriteToSmartCard(IMappingIO *pMappingIO,	TUserData	userData,
											LPFIELD_POSITION			lpPos, 
											bool&						bPosRelativeChange)
{
	FIELD_POSITION	pos;
	TCRD_RESULT		crdRes;

	crdRes = CRD_RESULT_OK;

	// on regarde si l'ensemble est actif ou non (en vérifiant les conditions associées)...
//	if (IsConditionsFullFilled()) {
		// on écrit les champs dans l'ordre de parsing
		if ((m_descripteur.header.posCount > 0) && (m_descripteur.posList)) {
			// on a des positions fixes, on écrit dans toutes les positions
			// jusqu'à ce qu'on ait pas d'erreur de CRC
			if (m_bModified) {
				crdRes = CRD_RESULT_OK;
				for (WORD copie = 0; (copie < m_descripteur.header.posCount) && (crdRes == CRD_RESULT_OK); copie++) {
					memcpy(&pos, &(m_descripteur.posList[copie]), sizeof(pos));
					
					// On a une position fixe, donc le champs suivant n'est pas décalé
					bPosRelativeChange = false;

					if (m_bAtomic) {
						crdRes = WriteAtomicField(pMappingIO, userData, &pos);
					} else {
						for (int i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK); i++) {
							if (GetChamp(i)) {
								crdRes = m_champs[i]->WriteToSmartCard(pMappingIO, userData, &pos, bPosRelativeChange);
							}
						}
					}
				}
			}
		}
		else {
			if (lpPos) {
				// on a une position relative, on écrit par rapport à la position fournie par la fonction
				memcpy(&pos, lpPos, sizeof(pos));
			}

			crdRes = CRD_RESULT_OK;
			for (int i = 0; (i < m_descripteur.header.prop.len) && (crdRes == CRD_RESULT_OK) ; i++) {
				if (GetChamp(i)) {
					crdRes = m_champs[i]->WriteToSmartCard(pMappingIO, userData, lpPos ? &pos : NULL, bPosRelativeChange);
				}
			}

			if (lpPos) {
				// on met à jour la position de la prochaine écriture
				memcpy(lpPos, &pos, sizeof(pos));
			}
		}
//	}
	
	return crdRes;
}

void CChampEnsemble::WriteToSmartCardCommit() {
	CChamp*		lpSubField;

	// on regarde si l'ensemble est actif ou non (en vérifiant les conditions associées)...
//	if (IsConditionsFullFilled()) {
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			lpSubField = GetChamp(i);
			if (lpSubField)
				lpSubField->WriteToSmartCardCommit();
		}

		m_bModified = FALSE;
//	}
}

void CChampEnsemble::SetModified(bool modified) {
	CChamp*		lpSubField;

	if (m_champs) {
		// on regarde si l'ensemble est actif ou non (en vérifiant les conditions associées)...
		//if (IsConditionsFullFilled()) {
			for (int i = 0; i < m_descripteur.header.prop.len; i++) {
				lpSubField = GetChamp(i);
				if (lpSubField) {
					lpSubField->SetModified(modified);
				}
			}

			// TEST :
			m_bModified = modified? TRUE : FALSE;
		//}
	}
}

bool CChampEnsemble::IsModified()
{
	bool	bRes = false;

	CChamp*		lpSubField;

	bRes = m_bModified? true : false;

	if (!bRes) {
		for (int i = 0; i < m_descripteur.header.prop.len && !bRes; i++) {
			lpSubField = GetChamp(i);
			if (lpSubField) {
				bRes = lpSubField->IsModified();
			}
		}
	}

	return bRes;
}
	
void CChampEnsemble::SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance) {
	CChamp*		lpSubField;

	if (m_champs) {
		if (   (m_descripteur.header.logicalInfo.instance == instance)
			&& (fieldIdMin <= m_descripteur.header.logicalInfo.fieldId)
			&& (m_descripteur.header.logicalInfo.fieldId < fieldIdMax))
		{
			m_bModified = modified? TRUE : FALSE;
		}

		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			lpSubField = GetChamp(i);
			if (lpSubField) {
				lpSubField->SetModifiedGroup(modified, fieldIdMin, fieldIdMax, instance);
			}
		}
	}	
}

bool CChampEnsemble::IsModifiedGroup(WORD fieldIdMin, WORD fieldIdMax, WORD instance)
{
	bool		bRes = false;
	CChamp*		lpSubField;

	if (m_champs) {
		if (   (m_descripteur.header.logicalInfo.instance == instance)
			&& (fieldIdMin <= m_descripteur.header.logicalInfo.fieldId)
			&& (m_descripteur.header.logicalInfo.fieldId < fieldIdMax))
		{
			bRes = m_bModified ? true : false;
		}

		for (int i = 0; i < m_descripteur.header.prop.len && !bRes; i++) {
			lpSubField = GetChamp(i);
			if (lpSubField) {
				bRes = lpSubField->IsModifiedGroup(fieldIdMin, fieldIdMax, instance);
			}
		}
	}
	return bRes;
}

#define		FOREACH_CHILD_FIELD(subField, command)	{\
	CChamp*		subField;\
	if (m_champs) {\
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {\
			subField = GetChamp(i);\
			if (subField) {\
				command;\
			}\
		}\
	}\
}

bool CChampEnsemble::GetImage(CListExt<long>* pCodeImgList) const {
	bool bRes = true;

	FOREACH_CHILD_FIELD(lpSubField, if (!lpSubField->GetImage(pCodeImgList)) bRes = false;);

	return bRes;
}

void CChampEnsemble::SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam) {
	FOREACH_CHILD_FIELD(lpSubField, lpSubField->SetImage(pCodeImgList, pParam));
}

bool CChampEnsemble::GetImage(CListExt<INT64>* pCodeImgList) const {
	bool bRes = true;

	FOREACH_CHILD_FIELD(lpSubField, if (!lpSubField->GetImage(pCodeImgList)) bRes = false;);

	return bRes;
}

void CChampEnsemble::SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam) {
	FOREACH_CHILD_FIELD(lpSubField, lpSubField->SetImage(pCodeImgList, pParam));
}

CChamp*	CChampEnsemble::GetChampById(WORD fieldId, int fieldInst) const {
	CChamp*		fieldRes;
	CChamp*		lpSubField;

	fieldRes = NULL;

	if (   (m_descripteur.header.logicalInfo.fieldId == fieldId)
		&& (m_descripteur.header.logicalInfo.instance == fieldInst))
	{
		return (CChamp*) this;
	}

	// on cherche dans les enfants de l'ensemble s'il est actif
//	if (IsConditionsFullFilled()) {
	for (int i = 0; i < m_descripteur.header.prop.len; i++) {
		lpSubField = GetChamp(i);
		if (lpSubField) {
			fieldRes = lpSubField->GetChampById(fieldId, fieldInst);
			if (fieldRes) {
				return fieldRes;
			}
		}
	}			
//	}

	return fieldRes;
}
	
CChamp*	CChampEnsemble::GetChampByUNId(DWORD fieldUNId, BYTE lookFlag, const CChamp* excluded) const {
	CChamp*		fieldRes;
	int			i;
	BOOL		bGoon;
	CChamp*		lpSubField;

	fieldRes = NULL;

	if (lookFlag == LOOKFIELD_DOWN) {
		// on cherche dans les enfants de l'ensemble s'il est actif
//		if (IsConditionsFullFilled()) {
			for (i = 0; i < m_descripteur.header.prop.len; i++) {
				lpSubField = GetChamp(i);
				if (lpSubField) {
					fieldRes = lpSubField->GetChampByUNId(fieldUNId, LOOKFIELD_DOWN);
					if (fieldRes) {
						return fieldRes;
					}
				}
			}			
//		}
	}
	else if (lookFlag == LOOKFIELD_UP) {
		// on regarde dans les enfants de l'ensemble pour trouver le champ
		bGoon = TRUE;
		for (i = 0; (i < m_descripteur.header.prop.len) && bGoon; i++) {
			lpSubField = GetChamp(i);
			if (lpSubField) {
				if (excluded && (excluded == lpSubField)) {
					// on a trouvé l'enfant d'où provient la demande,
					// on arrête la recherche dans les enfants
					bGoon = FALSE;
				}
				else {
					fieldRes = lpSubField->GetChampByUNId(fieldUNId, LOOKFIELD_DOWN);
					if (fieldRes)
						return fieldRes;
				}
			}
		}

		// on a pas trouvé le champs dans les enfants, 
		// on regarde dans le parent en excluant ce champ
		if (m_lpParent) {
			fieldRes = m_lpParent->GetChampByUNId(fieldUNId, LOOKFIELD_UP, this);
		}
	}

	return fieldRes;
}

void CChampEnsemble::ParentNotifyModified() {
	if (!m_bModified) {
		// l'ensemble n'était pas marqué comme modifié,
		// on le marque comme tel
		m_bModified = TRUE;

		// on indique au parent que cette ensemble a été modifié
		if (m_lpParent) {
			m_lpParent->ParentNotifyModified();
		}
	}
}

void CChampEnsemble::SetToDefautBitmapVal(){
	for (int i = 0; i < m_descripteur.header.prop.len; i++) {
		if (GetChamp(i))
			m_champs[i]->SetToDefautBitmapVal();
	}
}

LPTSTR CChampEnsemble::ToXml() const {
	LPTSTR		szXml;
	LPTSTR		szChildXml;
	LPTSTR		szFieldXml;
	LPTSTR		szTmp;
	CChamp*		pSubField;

	szXml = NULL;
	if (m_champs) {

		szChildXml = NULL;
		for (int i = 0; i < m_descripteur.header.prop.len; i++) {
			pSubField = GetChamp(i);
			if (pSubField) {
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

		if (szChildXml)
			stprintf_alloc(&szXml, _T("<Data>\r\n%s\r\n</Data>"), szChildXml);
		//else
		//	stprintf_alloc(&szXml, _T("<Data>\r\n%s\r\n</Data>"), szChildXml);
	}

	return szXml;
}

bool CChampEnsemble::BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos)
{
	FIELD_POSITION	pos;
	bool			bRes;

	bRes = false;
	if (pGenericFunction) {
		if ((m_descripteur.header.posCount > 0) && (m_descripteur.posList)) {
			bRes = true;
			for (WORD copie = 0; copie < m_descripteur.header.posCount; copie++) {
				memcpy(&pos, &(m_descripteur.posList[copie]), sizeof(pos));
				for (int i = 0; (i < m_descripteur.header.prop.len) && bRes; i++) {
					if (GetChamp(i))
						bRes = m_champs[i]->BrowseTreeGeneric(pGenericFunction, pArgsIn, pArgsOut, &pos);
				}
			}
		} else if (pActualPos) {
			bRes = true;
			// on a une position relative, on lit par rapport à la position fournie par la fonction
			memcpy(&pos, pActualPos, sizeof(pos));
			for (int i = 0; (i < m_descripteur.header.prop.len) && bRes; i++) {
				if (GetChamp(i))
					bRes = m_champs[i]->BrowseTreeGeneric(pGenericFunction, pArgsIn, pArgsOut, &pos);
			}
			// on met à jour la position de la prochaine lecture
			memcpy(pActualPos, &pos, sizeof(pos));
		}
	}
	return bRes;
}

size_t CChampEnsemble::GetFieldBitsLen(bool bOnlyPhysical) const {
	size_t	uiTotalLen = 0;

	for(UINT i=0; i<m_descripteur.header.prop.len; ++i) {
		if (GetChamp(i)) {
			uiTotalLen += GetChamp(i)->GetFieldBitsLen(bOnlyPhysical);
		}
	}

	return uiTotalLen;
}
