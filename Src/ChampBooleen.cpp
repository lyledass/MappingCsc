// ChampBooleen.cpp: implementation of the CChampBooleen class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampBooleen.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampBooleen::CChampBooleen(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampSimple(lpParent, lpcFieldDescrEx)
{
}

CChampBooleen::~CChampBooleen() {
}

CChamp*	CChampBooleen::MakeCopie(CChamp* lpParentCopie) const {
	CChampBooleen*	res = new CChampBooleen(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

void CChampBooleen::SetVal(bool b) {
	if (m_instance.value) {
		if (b != GetVal()) {
			if (m_descripteur.header.prop.bBitLeftToRight)
				bitRGet(m_instance.value, m_descripteur.header.prop.len, b);
			else
				bitGet(m_instance.value, m_descripteur.header.prop.len, b);

			m_instance.modified = TRUE;
		}
	}
}

bool CChampBooleen::GetVal() const {
	bool bRes;

	bRes = false;

	if (m_instance.value) {
		if (m_descripteur.header.prop.bBitLeftToRight)
			bitRSet(m_instance.value, m_descripteur.header.prop.len, bRes);
		else
			bitSet(m_instance.value, m_descripteur.header.prop.len, bRes);
	}
	
	return bRes;
}

bool CChampBooleen::NotToText(LPTSTR szTextVal, size_t textLen) const {
	bool	bRes;

	bRes = false;

	if (szTextVal) {
		if (GetVal())
			_tcsncpy_s(szTextVal, textLen, _T("non"), _TRUNCATE); // LngGetMsg(TI_NON);
		else
			_tcsncpy_s(szTextVal, textLen, _T("oui"), _TRUNCATE); // LngGetMsg(TI_OUI);

		bRes = true;
	}

	return bRes;
}

bool CChampBooleen::ToText(LPTSTR szTextVal, size_t textLen) const {
	bool	bRes;

	bRes = false;

	if (szTextVal) {
		if (GetVal())
			_tcsncpy_s(szTextVal, textLen, _T("oui"), _TRUNCATE); // LngGetMsg(TI_OUI);
		else
			_tcsncpy_s(szTextVal, textLen, _T("non"), _TRUNCATE); // LngGetMsg(TI_NON);

		bRes = true;
	}

	return bRes;
}
