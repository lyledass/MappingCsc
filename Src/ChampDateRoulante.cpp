// ChampDateRoulante.cpp: implementation of the CChampDateRoulante class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateRoulante.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateRoulante::CChampDateRoulante(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateRoulante::~CChampDateRoulante() {
}

void CChampDateRoulante::SetVal(const SYSTEMTIME* pVal) {
	long			lval;
	SYSTEMTIME		dtRef;
	long			dayOfYear;

	if (pVal) {
		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = pVal->wYear;
		dtRef.wMonth = 1;
		dtRef.wDay = 1;

		dayOfYear = GetSystemTimeDayDiff(pVal, &dtRef);
		lval = dayOfYear + ((pVal->wYear % 10) * 366);

		if (GetInstLongValue() != lval) {
			SetInstLongValue(lval);
		}
	}
}

bool CChampDateRoulante::GetVal(SYSTEMTIME* pVal) const {
	long			val;
	SYSTEMTIME		dtNow;
	bool			bRes;

	bRes = false;
	if (pVal) {
		GetSystemTime(&dtNow);

		val = GetInstLongValue();

		int a = val / 366;
		if (a < 100) {
			if (a < 10) {
				int u = dtNow.wYear % 10; 
				int	d = (dtNow.wYear % 100) - u;
				if (u == 9)
					a = a? a + d : d + 10;
				else 
					a = (a > (u + 1))? d - 10 : a + d;
			}
			a += (a < 50) ? 2000 : 1900; 
		}

		memset(pVal, 0, sizeof(*pVal));
		pVal->wYear = a;
		pVal->wMonth = pVal->wDay = 1;

		bRes = AddSystemTimeDay(pVal, (val % 366) - 1);
	}

	return bRes;
}

CChamp*	CChampDateRoulante::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateRoulante*	res = new CChampDateRoulante(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

