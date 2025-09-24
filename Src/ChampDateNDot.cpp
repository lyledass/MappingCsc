// ChampDateNDot.cpp: implementation of the CChampDateC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateNDot.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateNDot::CChampDateNDot(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateNDot::~CChampDateNDot() {
}

#define	MAKEBYTE(uLoNibble, uHiNibble)	((((BYTE)(uHiNibble) & 0x0f) << 4) | ((BYTE)(uLoNibble) & 0x0f))
#define	GETNIBBLE(uiVal, nNibble)	((BYTE)((uiVal)>>((nNibble)*4)) & 0x0f)

void CChampDateNDot::SetVal(const SYSTEMTIME* pVal) {
	ULONG	ulVal;

	if (pVal) {
		assert(pVal->wYear >= 2000 && pVal->wYear <= 2000+99);

		ulVal = MAKEBYTE((pVal->wYear-2000)%10, (pVal->wYear-2000)/10);
		ulVal <<= 8;
		ulVal |= MAKEBYTE((pVal->wMonth)%10, (pVal->wMonth)/10);
		ulVal <<= 8;
		ulVal |= MAKEBYTE((pVal->wDay)%10, (pVal->wDay)/10);

		SetInstLongValue(ulVal);
	}
}

bool CChampDateNDot::GetVal(SYSTEMTIME* pVal) const {
	bool	bRes;
	ULONG	ulVal;
	BYTE	digits[6];

	bRes = false;
	if (pVal) {
		ulVal = (ULONG)GetInstLongValue();

		bRes = true;

		for(int i=0; i<6 && bRes; ++i) {
			digits[6-i-1] = GETNIBBLE(ulVal, i);
			if (digits[6-i-1] > 9) {
				TRACE_ERROR(_T("NDotDate invalid : %lu"), ulVal);
				bRes = false;
			}
		}

		if (bRes) {
			memset(pVal, 0, sizeof(*pVal));

			pVal->wYear = (WORD)2000 + (10*digits[0] + digits[1]);
			pVal->wMonth = 10*digits[2] + digits[3];
			pVal->wDay = 10*digits[4] + digits[5];
		}
	}

	return bRes;
}

CChamp*	CChampDateNDot::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateNDot*	res = new CChampDateNDot(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

INT64 CChampDateNDot::GetImageValue() const {
	return CChampSimple::GetImageValue();
}

void CChampDateNDot::SetImageValue(INT64 lVal) {
	CChampSimple::SetImageValue(lVal);
}
