// ChampDateMinute.cpp: implementation of the CChampDateMinute class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateMinute.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateMinute::CChampDateMinute(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescr)
	: CChampDate(lpParent, lpcFieldDescr)
{
}

CChampDateMinute::~CChampDateMinute() {
}

void CChampDateMinute::SetVal(const SYSTEMTIME* pVal) {
	SYSTEMTIME		dtVal;
	long			dayOfYear;
	long			lval;


	if (pVal) {
		memset(&dtVal, 0, sizeof(dtVal));
		dtVal.wYear = pVal->wYear;
		dtVal.wMonth = 1;
		dtVal.wDay = 1;
		dayOfYear = GetSystemTimeDayDiff(pVal, &dtVal);

		lval = ((dayOfYear * 24 + pVal->wHour) * 60) + pVal->wMinute;


		if (GetInstLongValue() != lval) 
			SetInstLongValue(lval);
	}
}

bool CChampDateMinute::GetVal(SYSTEMTIME* pVal) const {
	SYSTEMTIME			dtNow;
	SYSTEMTIME			dtVal;
	long				lval;
	long				jour;
	bool				bRes;

	bRes = false;
	if (pVal) {
		GetSystemTime(&dtNow);

		memset(&dtVal, 0, sizeof(dtVal));

		lval = GetInstLongValue();

		dtVal.wYear = dtNow.wYear;
		dtVal.wMonth = 1;
		dtVal.wDay = 1;
		dtVal.wMinute = (WORD) (lval % 60);
		dtVal.wHour = (WORD) ((lval / 60) % 24);

		jour = lval / (60 * 24);

		if (AddSystemTimeDay(&dtVal, jour - 1)) {
			memcpy(pVal, &dtVal, sizeof(dtVal));
		
			bRes = true;
		}
	}

	return bRes;
}

CChamp*	CChampDateMinute::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateMinute* res = new CChampDateMinute(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

