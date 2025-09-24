// Champ.cpp: implementation of the CChamp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <Champ.h>
#include <MapDef.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChamp::CChamp(CChamp*	lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescrEx) {
	m_lpParent = lpParent;

	memset(&m_descripteur, 0, sizeof(m_descripteur));

	if (lpcFieldDescrEx) {
		// on copie les infos de header
		memcpy(&m_descripteur.header, &(lpcFieldDescrEx->header), FIELD_DESCR_EX_SIZEOFHEADER_V3);
		m_descripteur.header.posCount = 0;
		m_descripteur.header.condCount = 0;
		m_descripteur.bFixedEndPos = lpcFieldDescrEx->bFixedEndPos;

		// on alloue et on copie les informations de positions
		if ((lpcFieldDescrEx->header.posCount > 0) && (lpcFieldDescrEx->posList)) {
			m_descripteur.posList = new FIELD_POSITION [lpcFieldDescrEx->header.posCount];
			if (m_descripteur.posList) {
				m_descripteur.header.posCount = lpcFieldDescrEx->header.posCount;
				memcpy(m_descripteur.posList, lpcFieldDescrEx->posList, m_descripteur.header.posCount * sizeof(FIELD_POSITION));
			}
		}

		// on alloue et on copie les informations de conditions
		if ((lpcFieldDescrEx->header.condCount > 0) && (lpcFieldDescrEx->condDefValList)) {
			m_descripteur.condDefValList = new FIELD_CONDITIONVAL [lpcFieldDescrEx->header.condCount];
			if (m_descripteur.condDefValList) {
				m_descripteur.header.condCount = lpcFieldDescrEx->header.condCount;
				memcpy(m_descripteur.condDefValList, lpcFieldDescrEx->condDefValList, m_descripteur.header.condCount * sizeof(FIELD_CONDITIONVAL));
			}
		}
	}
}

CChamp::~CChamp() {
	m_lpParent = NULL;

	// on désaloue les positions
	if ((m_descripteur.header.posCount > 0) && m_descripteur.posList) {
		delete [] m_descripteur.posList;
		m_descripteur.posList = NULL;
	}

	if ((m_descripteur.header.condCount > 0) && m_descripteur.condDefValList) {
		delete [] m_descripteur.condDefValList;
		m_descripteur.condDefValList = NULL;
	}
}

long CChamp::GetCodeImage() const {
	return m_descripteur.header.logicalInfo.codeImg;
}

bool CChamp::IsPositionFixe() const {
	return ((m_descripteur.header.posCount > 0) && m_descripteur.posList);
}

MAPFIELDS_IDNEEDED CChamp::GetNeededType() {
	return (MAPFIELDS_IDNEEDED) m_descripteur.header.prop.dNeeded;
}

bool CChamp::UpdateFromModifiedCopy(const CChamp*	lpCopie) {
	bool	res;

	res = false;
	if (lpCopie) {
		// on test si on a les mêmes descripteurs
		//res = (memcmp(&m_descripteur, &lpCopie->m_descripteur, FIELD_DESCR_EX_SIZEOFHEADER) == 0);
		res = (m_descripteur.header.unidFieldId == lpCopie->m_descripteur.header.unidFieldId);
	}
	
	return res;
}

void CChamp::SetToDefautBitmapVal(){
}

const CChamp* CChamp::GetParent() const {
	return m_lpParent;
}

LPTSTR CChamp::GetFriendlyName(WORD fieldId) const {
	LPTSTR		szName;
	LPCTSTR		szGroup;
	LPCTSTR		szId;
	int			i;

	szName = NULL;

	szGroup = NULL;
	for (i = 0; (i < (sizeof(MAPEDIT_FIELDTYPELIST) / sizeof(MAPEDIT_FIELDTYPELIST[0]))) && !szGroup; i++) {
		if ((fieldId / 0x0100) == MAPEDIT_FIELDTYPELIST[i].typeId) {
			szGroup = MAPEDIT_FIELDTYPELIST[i].szName;
		}
	}

	szId = NULL;
	for (i = 0; (i < (sizeof(MAPEDIT_FIELDLIST) / sizeof(MAPEDIT_FIELDLIST[0]))) && !szId; i++) {
		if (fieldId == MAPEDIT_FIELDLIST[i].fieldId) {
			szId = MAPEDIT_FIELDLIST[i].name;
		}
	}

	if (szGroup && szId) {
		stprintf_alloc(&szName, _T("%s %s"), szGroup, szId);
		if (szName)
			_tcsReplace(szName, _tcslen(szName) + 1, _T("'"), _T(" "));
	}

	return szName;
}

LPTSTR CChamp::GetFriendlyType(WORD type, WORD subType) const {
	LPTSTR				szType;
	MAPEDIT_TYPEVAL*	pTypeInfo;
	int					i;
	int					j;

	szType = NULL;
	pTypeInfo = NULL;

	for (i = 0; (i < TYPE_COUNT) && !pTypeInfo; i++) {
		if (type == MAPEDIT_TYPE_LIST[i].defaultFieldExVal.type) {

			if (MAPEDIT_TYPE_LIST[i].subTypeList && (MAPEDIT_TYPE_LIST[i].subTypeListLen > 0)) {
				for (j = 0; (j < MAPEDIT_TYPE_LIST[i].subTypeListLen) && !pTypeInfo; j++) {
					if (subType == MAPEDIT_TYPE_LIST[i].subTypeList[j].defaultFieldExVal.subType) {
						pTypeInfo = &(MAPEDIT_TYPE_LIST[i].subTypeList[j]);
					}
				}				
			}
			else
				pTypeInfo = &(MAPEDIT_TYPE_LIST[i]);
		}
	}
	
	if (pTypeInfo) {
		stprintf_alloc(&szType, _T("%s"), pTypeInfo->name);
	}

	return szType;
}
