// ChampDateHeure.cpp: implementation of the CChampDateHeure class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateHeure.h>

#define VAL_PIVOT	600000
#define ANNEE_MAX	2

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateHeure::CChampDateHeure(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateHeure::~CChampDateHeure() {
}

void CChampDateHeure::SetVal(const SYSTEMTIME* pVal) {
	// On ne sait pas vraiment déterminer le type, 
	// on ne peut donc pas écrire une date
	BYTE type = Date;
	SYSTEMTIME	dtRef;
	long		dayOfYear;

	if (pVal && GetVal(&dtRef) && (memcmp(pVal, &dtRef, sizeof(dtRef)) != 0)) {
		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = pVal->wYear;
		dtRef.wMonth = 1;
		dtRef.wDay = 1;
		dayOfYear = GetSystemTimeDayDiff(pVal, &dtRef);

		if (type == Heure) {
			long mi = (((dayOfYear * 24) + pVal->wHour) * 60) + pVal->wMinute;
			SetInstLongValue(mi);
		}
		else {
			long lval = dayOfYear - 1 + ((pVal->wYear % 10) * 366) + VAL_PIVOT;
			SetInstLongValue(lval);
		}
	}
}

bool CChampDateHeure::GetVal(SYSTEMTIME* pVal) const {
	long			val;
	BYTE			type;
	SYSTEMTIME		dtNow;
	SYSTEMTIME		dtRef;
	long			dayOfYear;
	bool			bRes;

	bRes = false;

	if (pVal) {
		memset(pVal, 0, sizeof(SYSTEMTIME));

		GetSystemTime(&dtNow);

		memset(&dtRef, 0, sizeof(dtRef));
		dtRef.wYear = pVal->wYear;
		dtRef.wMonth = 1;
		dtRef.wDay = 1;
		dayOfYear = GetSystemTimeDayDiff(&dtNow, &dtRef);

		val = GetInstLongValue();

		if (val <= VAL_PIVOT) {
			// val est une heure
			type = Heure;
			long nbMinutes = (((dayOfYear * 24) + dtNow.wHour) * 60);
			int	 j, h, m;
			j = val / (24 * 60);
			h = (val % (24 * 60)) / 60;
			m = (val % (24 * 60)) % 60;
		
			pVal->wDay = 1;
			pVal->wMonth = 1;
			pVal->wHour = h;
			pVal->wMinute = m;
			if (val > nbMinutes) {
				// le support a été composté l'année dernière
				pVal->wYear = dtNow.wYear - 1;
			}
			else
				pVal->wYear = dtNow.wYear;

				bRes = AddSystemTimeDay(pVal, j) ? true : false;
		}
		else {
			// val est une date
			type = Date;
			int unite = (dtNow.wYear % 10);
			int	decennie = (dtNow.wYear % 100) - unite;
		
			int j, u;
			j = (val - VAL_PIVOT) % 366;
			u = (val - VAL_PIVOT) / 366;

			if (u == unite)
				u += decennie;
			else {
				if (unite < u) {
					if ((unite + ANNEE_MAX) <= u)
						u += decennie;
					else
						u += decennie - 10;
				}
				else {
					if (u < (u + ANNEE_MAX - 9))
						u += decennie + 10;
					else
						u += decennie;
				}
			}

			u += (u < 50)? 2000 : 1900;

			pVal->wYear = u;
			pVal->wMonth = 1;
			pVal->wDay = 1;

			bRes = AddSystemTimeDay(pVal, j) ? true : false;
		}
	}

	return bRes;
}

CChamp*	CChampDateHeure::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateHeure*	res = new CChampDateHeure(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

INT64 CChampDateHeure::GetImageValue() const {
	long	val;
	SYSTEMTIME	dtVal;

	val = 0;
	if (!IsValNone()) {
		val = GetInstLongValue();

		memset(&dtVal, 0, sizeof(dtVal));
		if (GetVal(&dtVal)) {

			if (val <= VAL_PIVOT) {
				val = (dtVal.wHour * 10000) + (dtVal.wMinute * 100) + dtVal.wSecond; 
			}
			else {
				val = (dtVal.wYear * 10000) + (dtVal.wMonth * 100) + dtVal.wDay; 		
			}
		}
	}
	
	return val;
}

void CChampDateHeure::SetImageValue(INT64 lVal) {
	SYSTEMTIME		dtVal;

	if (lVal) {
		memset(&dtVal, 0, sizeof(dtVal));
		
		if (lVal <= VAL_PIVOT) {
			dtVal.wYear = (WORD) (lVal / 1000);
			dtVal.wMonth = (WORD) ((lVal % 10000) / 100);
			dtVal.wDay = (WORD) (lVal % 100);

			SetVal(&dtVal);
		}
		else {
			dtVal.wHour = (WORD) (lVal / 1000);
			dtVal.wMinute = (WORD) ((lVal % 10000) / 100);
			dtVal.wSecond = (WORD) (lVal % 100);

			SetVal(&dtVal);
		}
	}
}
/*
unsigned long CChampDateHeure::GetValFormated() const {
	return 0;
}
*/