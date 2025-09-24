// ChampDateIso.cpp: implementation of the CChampDateIso class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateIso.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateIso::CChampDateIso(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateIso::~CChampDateIso() {
}

void CChampDateIso::SetVal(const SYSTEMTIME* pVal) {
	SYSTEMTIME		dtRef;
	long			diff;
		
	if (pVal && GetVal(&dtRef) && (memcmp(pVal, &dtRef, sizeof(dtRef)) != 0)) {
		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = GetFirstYear();
		dtRef.wMonth = 1;
		dtRef.wDay = 1;

		diff = GetSystemTimeDayDiff(pVal, &dtRef);
		SetInstLongValue(diff);
	}
}

bool CChampDateIso::GetVal(SYSTEMTIME* pVal) const {
	long				val;
	SYSTEMTIME			dtRef;
	bool				bRes;

	bRes = false;
	if (pVal) {
		val = GetInstLongValue();

		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = GetFirstYear();
		dtRef.wMonth = 1;
		dtRef.wDay = 1;

		if (AddSystemTimeDay(&dtRef, val)) {
			memcpy(pVal, &dtRef, sizeof(dtRef));
			bRes = true;
		}
	}

	return bRes;
}

CChamp*	CChampDateIso::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateIso*	res = new CChampDateIso(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

