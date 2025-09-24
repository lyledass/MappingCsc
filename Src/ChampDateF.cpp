// ChampDateF.cpp: implementation of the CChampDateF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateF.h>

INT	BCDToInt(INT bcdNum, BYTE nbHalfByte) {
	// transforme 0x1234 en 1234
	INT		res;
	INT		pow10;

	res = 0;
	pow10 = 1;

	for (int i = 0; i < nbHalfByte; i++) {
		res += ((bcdNum >> (4 * i)) & 0xF) * pow10;
		pow10 *= 10;
	}

	return res;
}

INT IntToBCD(INT intNum, BYTE nbDigit) {
	// transforme 1234 en 0x1234
	INT		res;

	res = 0;
	for (int i = 0; i < nbDigit; i++) {
		res |= (((intNum % 10) & 0x0F) << (4 * i));
		intNum /= 10;
	}

	return res;
}

#define BCDWORDTOWORD(x)	BCDToInt(x, 4)
#define BCDBYTETOBYTE(x)	BCDToInt(x, 2)
#define WORDTOBCDWORD(x)	IntToBCD(x, 4)
#define BYTETOBCDBYTE(x)	IntToBCD(x, 2)


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CChampDateF::CChampDateF(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
}

CChampDateF::~CChampDateF() {
}

void CChampDateF::SetVal(const SYSTEMTIME* pVal) {
	long lval = 0;
	SYSTEMTIME		dtRef;

	if (pVal && GetVal(&dtRef) && (memcmp(pVal, &dtRef, sizeof(dtRef)) != 0)) {
		lval = WORDTOBCDWORD(pVal->wYear) & 0xFFFF;
		lval <<= 8;
		lval += BYTETOBCDBYTE(pVal->wMonth) & 0xFF;
		lval <<= 8;
		lval += BYTETOBCDBYTE(pVal->wDay) & 0xFF;

		SetInstLongValue(lval);
	}
}

bool CChampDateF::GetVal(SYSTEMTIME* pVal) const {
	long			val;
	bool			bRes;

	bRes = false;
	
	if (pVal) {
		memset(pVal, 0, sizeof(SYSTEMTIME));
	
		val = GetInstLongValue();
		if (val) {
			pVal->wYear = BCDWORDTOWORD(val >> 16);
			pVal->wMonth = BCDBYTETOBYTE(val >> 8);
			pVal->wDay = BCDBYTETOBYTE(val);
		}
		bRes = true;
	}

	return bRes;
}

CChamp*	CChampDateF::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateF*	res = new CChampDateF(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}
/*
// ---------------------------------------------------------------------------
// Format Natif du type de date
// ---------------------------------------------------------------------------
//
// Date au format AAAAMMJJ
//
unsigned long CChampDateF::GetValFormated() const {
	return 	( (GetVal().GetYear() * 10000) + (GetVal().GetMonth() * 100) + GetVal().GetDay() );
}

bool CChampDateF::SetValFormated(long val) {
	COleDateTime date(val / 10000, (val % 10000) / 100, val % 100, 0, 0, 0);
	SetVal(date);
	
	return true;
}
*/