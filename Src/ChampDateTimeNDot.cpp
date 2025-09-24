// ChampDateC.cpp: implementation of the CChampDateC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateTimeNDot.h>
#include <TkCore/Conversion/Conversion.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateTimeNDot::CChampDateTimeNDot(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateTimeNDot::~CChampDateTimeNDot() {
}

#define	MAKEBYTE(uLoNibble, uHiNibble)	((((BYTE)(uHiNibble) & 0x0f) << 4) | ((BYTE)(uLoNibble) & 0x0f))
#define	GETNIBBLE(uiVal, nNibble)	((BYTE)((uiVal)>>((nNibble)*4)) & 0x0f)

void CChampDateTimeNDot::SetVal(const SYSTEMTIME* pVal) {
	UINT64	uiVal;

	if (pVal) {
		assert(pVal->wYear >= 2000 && pVal->wYear <= 2000+99);

		uiVal = MAKEBYTE((pVal->wYear-2000)%10, (pVal->wYear-2000)/10);
		uiVal <<= 8;
		uiVal |= MAKEBYTE((pVal->wMonth)%10, (pVal->wMonth)/10);
		uiVal <<= 8;
		uiVal |= MAKEBYTE((pVal->wDay)%10, (pVal->wDay)/10);
		uiVal <<= 8;
		uiVal |= MAKEBYTE((pVal->wHour)%10, (pVal->wHour)/10);
		uiVal <<= 8;
		uiVal |= MAKEBYTE((pVal->wMinute)%10, (pVal->wMinute)/10);

		SetInstLongValue(uiVal);
	}	
}

bool CChampDateTimeNDot::GetVal(SYSTEMTIME* pVal) const {
	UINT64	uiVal;
	bool	bRes = false;
	BYTE	digits[10];

	if (pVal) {
		uiVal = GetInstLongValueEx();

		bRes = true;

		for(int i=0; i<10 && bRes; ++i) {
			digits[10-i-1] = GETNIBBLE(uiVal, i);
			if (digits[10-i-1] > 9) {
				TRACE_ERROR(_T("NDotDateTime invalid : %llu"), uiVal);
				bRes = false;
			}
		}

		if (bRes) {
			memset(pVal, 0, sizeof(*pVal));

			pVal->wYear = (WORD)2000 + (10*digits[0] + digits[1]);
			pVal->wMonth = 10*digits[2] + digits[3];
			pVal->wDay = 10*digits[4] + digits[5];
			pVal->wHour = 10*digits[6] + digits[7];
			pVal->wMinute = 10*digits[8] + digits[9];
		}
	}

	return bRes;
}

CChamp*	CChampDateTimeNDot::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateTimeNDot*	res = new CChampDateTimeNDot(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

INT64 CChampDateTimeNDot::GetImageValue() const {
	return CChampSimple::GetImageValue();
}

void CChampDateTimeNDot::SetImageValue(INT64 lVal) {
	CChampSimple::SetImageValue(lVal);
}
