// ChampDateC.cpp: implementation of the CChampDateC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateC.h>
#include <TkCore/Conversion/Conversion.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateC::CChampDateC(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateC::~CChampDateC() {
}

void CChampDateC::SetVal(const SYSTEMTIME* pVal) {
	long lDiff;

	if (pVal) {
		lDiff = _DateToDateC(pVal);
		SetInstLongValue(lDiff);
	}	
}

bool CChampDateC::GetVal(SYSTEMTIME* pVal) const {
	long				lVal;
	bool				bRes;

	bRes = false;
	if (pVal) {
		lVal = GetInstLongValue();
		if(_DateCToDate(lVal, pVal)) {
			bRes = true;
		}
	}

	return bRes;
}

CChamp*	CChampDateC::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateC*	res = new CChampDateC(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}
/*
// ---------------------------------------------------------------------------
// Format Natif du type de date
// ---------------------------------------------------------------------------
//
// Nombre de jours depuis le 1 er Janvier 1997 (qui vaut Zéro)
//
unsigned long CChampDateC::GetValFormated() const {
	// Date de référence
	COleDateTime t(1997,1,1,0,0,0);
	COleDateTimeSpan t2 = GetVal() - t;

	return (long)t2.GetTotalDays();
}

bool CChampDateC::SetValFormated(long val) {
	COleDateTime		ref (1997, 1, 1, 0, 0, 0);
	COleDateTimeSpan	diff;
	diff.SetDateTimeSpan(val, 0, 0, 0);
	ref += diff;
	SetVal(ref);

	return true;
}
*/
INT64 CChampDateC::GetImageValue() const {
	long	val;

	val = 0;
	if (!IsValNone()) {
		val = GetInstLongValue();
	}
	
	return val;
}

void CChampDateC::SetImageValue(INT64 lVal) {
	SetInstLongValue(lVal);
}