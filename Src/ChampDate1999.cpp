// ChampDate1999.cpp: implementation of the CChampDate1999 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDate1999.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDate1999::CChampDate1999(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDate1999::~CChampDate1999() {
}

void CChampDate1999::SetVal(const SYSTEMTIME* pVal) {
	SYSTEMTIME		dtRef;
	long			diff;
		
	if (pVal && GetVal(&dtRef) && (memcmp(pVal, &dtRef, sizeof(dtRef)) != 0)) {
		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = 1999;
		dtRef.wMonth = 1;
		dtRef.wDay = 1;

		diff = GetSystemTimeDayDiff(pVal, &dtRef);
		SetInstLongValue(diff);
	}
}

bool CChampDate1999::GetVal(SYSTEMTIME* pVal) const {
	long				val;
	SYSTEMTIME			dtRef;
	bool				bRes;

	bRes = false;
	if (pVal) {
		val = GetInstLongValue();

		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = 1999;
		dtRef.wMonth = 1;
		dtRef.wDay = 1;

		if (AddSystemTimeDay(&dtRef, val)) {
			memcpy(pVal, &dtRef, sizeof(dtRef));
			bRes = true;
		}
	}

	return bRes;
}

CChamp*	CChampDate1999::MakeCopie(CChamp* lpParentCopie) const {
	CChampDate1999*	res = new CChampDate1999(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}
