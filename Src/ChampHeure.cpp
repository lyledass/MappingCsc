// ChampHeure.cpp: implementation of the CChampHeure class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampHeure.h>
#include <TkCore/Conversion/Conversion.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampHeure::CChampHeure(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampHeure::~CChampHeure() {
}

bool CChampHeure::ToText(LPTSTR szTextVal, size_t textLen) const {
	SYSTEMTIME		dateTime;
	bool			bRes;

	bRes = false;

	if (szTextVal) {
		if (!IsValNone()) {
			if (GetVal(&dateTime)) {
				bRes = GetTimeFormat(LOCALE_SYSTEM_DEFAULT, TIME_FORCE24HOURFORMAT, &dateTime, NULL, szTextVal, textLen) ? true : false;
			}
		}
		else {
			_tcsncpy_s(szTextVal, textLen, _T(""), _TRUNCATE);
			bRes = true;
		}
	}

	return bRes;	// TODO return LngGetMsg(MSG_MAPPING__HeureNull);
}

INT64 CChampHeure::GetImageValue() const {
	long	val;
	SYSTEMTIME	dtDate;

	val = 0;
	if (!IsValNone()) {
		if (GetVal(&dtDate)) {
			val = _HeureToLong(&dtDate);
		}
	}
	
	return val;
}

void CChampHeure::SetImageValue(INT64 lVal) {
	SYSTEMTIME	dtDate;

	if(_LongToHeure((long)lVal, &dtDate)) {
		SetVal(&dtDate);
	}
}