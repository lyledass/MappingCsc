// ChampDate545.cpp: implementation of the CChampDate545 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDate545.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDate545::CChampDate545(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDate545::~CChampDate545() {
}

void CChampDate545::SetVal(const SYSTEMTIME* pVal) {
	long	lval;
	SYSTEMTIME	val;

	if (pVal && GetVal(&val) && (memcmp(pVal, &val, sizeof(SYSTEMTIME)) != 0)) {

		lval = 0;
		lval = (pVal->wDay & 0x1F) << 9;
		lval += (pVal->wMonth & 0x0F) << 5;
		lval += (pVal->wYear - GetFirstYear()) & 0x1F;

		SetInstLongValue(lval);
	}
}

bool CChampDate545::GetVal(SYSTEMTIME* pVal) const {
	long			val;
	long			day;
	long			month;
	bool			bRes;

	bRes = false;
	if (pVal) {
	val = GetInstLongValue();

	month = (val >> 5) & 0x0F;
	day = (val >> 9) & 0x1F;

		memset(pVal, 0, sizeof(SYSTEMTIME));
		pVal->wYear = (WORD) ((val & 0x1F) + 1997);	// AAALIB (val & 0x1F) + AfxGetTpvParam().GetFirstYear(),
		pVal->wMonth = (WORD) (month? month : 1);
		pVal->wDay = (WORD) (day? day : 1);

		bRes = true;
	}

	return bRes;
}

CChamp*	CChampDate545::MakeCopie(CChamp* lpParentCopie) const {
	CChampDate545*	res = new CChampDate545(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}
