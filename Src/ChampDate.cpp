// ChampDate.cpp: implementation of the CChampDate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDate.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDate::CChampDate(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampSimple(lpParent, lpcFieldDescrEx)
{
}

CChampDate::~CChampDate() {
}

bool CChampDate::ToText(LPTSTR szTextVal, size_t textLen) const {
	SYSTEMTIME		dateTime;
	bool			bRes;

	bRes = false;
	if (szTextVal) {
	if (!IsValNone() && !IsValMax()) {
			if (GetVal(&dateTime)) {
				if (GetDateFormat(LOCALE_SYSTEM_DEFAULT, DATE_SHORTDATE, &dateTime, NULL, szTextVal, textLen)>0) {
					bRes = true;
				}
			}
		}
		else
			_tcsncpy_s(szTextVal, textLen, _T(""), _TRUNCATE);

		bRes = true;
	}

	return bRes;	// TODO return LngGetMsg(MSG_MAPPING__DateNull);
}



int	CChampDate::GetFirstYear() const {
	#pragma message("TODO : 1ere annee des dates a gerer proprement\n")
	return 1997;
}

//long CChampDate::GetValLong() const {
//	return GetInstLongValue();
//}

INT64 CChampDate::GetImageValue() const {
	long	val;
	SYSTEMTIME	dateTime;

	val = 0;
	if (!IsValNone()) {
		if (GetVal(&dateTime))
			val = (dateTime.wYear * 10000) + (dateTime.wMonth * 100) + dateTime.wDay; 
	}
	
	return val;
}

void CChampDate::SetImageValue(INT64 lVal) {
	SYSTEMTIME	dateTime;

	memset(&dateTime, 0, sizeof(dateTime));
	dateTime.wYear = (WORD) (lVal / 10000);
	dateTime.wMonth = ((WORD) (lVal % 10000) / 100);
	dateTime.wDay = (WORD) (lVal % 100);

	SetVal(&dateTime);
}

long CChampDate::GetSystemTimeDayDiff(const SYSTEMTIME* pVal, const SYSTEMTIME* pRef) const {
	long			diff;
	ULARGE_INTEGER	ulVal;
	ULARGE_INTEGER	ulRef;
	__int64			ulDiff;
	
	diff = 0;
	
	if (   SystemTimeToFileTime(pVal, (FILETIME*) &ulVal)
		&& SystemTimeToFileTime(pRef, (FILETIME*) &ulRef))
	{
		ulDiff = ulVal.QuadPart - ulRef.QuadPart;
		// ulDiff est la différence de 100 nanosecondes ! (on / par 10000000 pour les secondes !) 
		diff = (long) (((ulDiff / 10000000) / 60 / 60 / 24));
	}

	return diff;
}

bool CChampDate::AddSystemTimeDay(SYSTEMTIME* pVal, long dayCount) const {
	ULARGE_INTEGER	ulVal;
	__int64			ulDiff;
	bool			bRes;

	bRes = false;

	if (pVal) {
		if (SystemTimeToFileTime(pVal, (FILETIME*) &ulVal)) {
			ulDiff = dayCount;
			ulDiff *= ((__int64) 24 * (__int64) 60 * (__int64) 60 * (__int64) 10000000);
			ulVal.QuadPart += ulDiff;

			bRes = FileTimeToSystemTime((FILETIME*) &ulVal, pVal) ? true : false;
		}
	}

	return bRes;
}

bool CChampDate::RemoveSystemTimeDay(SYSTEMTIME* pVal, long dayCount) const {
	ULARGE_INTEGER	ulVal;
	__int64			ulDiff;
	bool			bRes;

	bRes = false;

	if (pVal) {
		if (SystemTimeToFileTime(pVal, (FILETIME*) &ulVal)) {
			ulDiff = dayCount;
			ulDiff *= ((__int64) 24 * (__int64) 60 * (__int64) 60 * (__int64) 10000000);
			ulVal.QuadPart -= ulDiff;

			bRes = FileTimeToSystemTime((FILETIME*) &ulVal, pVal) ? true : false;
		}
	}

	return bRes;
}
