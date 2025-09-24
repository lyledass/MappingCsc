// ChampDate545.cpp: implementation of the CChampDateMk3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateMk3.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateMk3::CChampDateMk3(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateMk3::~CChampDateMk3() {
}

void CChampDateMk3::SetVal(const SYSTEMTIME* pVal) {
	long	lval;
	SYSTEMTIME	val;

	if (pVal && GetVal(&val) && (memcmp(pVal, &val, sizeof(SYSTEMTIME)) != 0)) {
		lval = 0;
		lval = (pVal->wDay) << 16;
		lval += (pVal->wMonth) << 8  &0xFF;
		lval += (pVal->wYear + 1989) & 0xFF;


		SetInstLongValue(lval);
	}
}

bool CChampDateMk3::GetVal(SYSTEMTIME* pVal) const {
	long			val;
	long			day;
	long			month;
	bool			bRes;

	bRes = false;
	if (pVal) {
	val = GetInstLongValue();

	day = (val >> 16);
	month  = (val >> 8)  &0xFF;

		memset(pVal, 0, sizeof(SYSTEMTIME));
		pVal->wYear = (WORD) ((val & 0xFF) + 1989);	// AAALIB (val & 0x1F) + AfxGetTpvParam().GetFirstYear(),
		pVal->wMonth = (WORD) (month? month : 1);
		pVal->wDay = (WORD) (day? day : 1);

		bRes = true;
	}

	return bRes;
}

CChamp*	CChampDateMk3::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateMk3*	res = new CChampDateMk3(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}
