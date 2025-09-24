// ChampDateC.cpp: implementation of the CChampDateC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampDateCfvDelta.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampDateCfvDelta::CChampDateCfvDelta(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx, DWORD dfvCardUnid)
	: CChampDate(lpParent, lpcFieldDescrEx)
{
	m_dfvCardUnid = dfvCardUnid;
}

CChampDateCfvDelta::~CChampDateCfvDelta() {
}

void CChampDateCfvDelta::SetVal(const SYSTEMTIME* pVal) {
	SYSTEMTIME		dtDfvCard;
	SYSTEMTIME		dtDfvTmp;
	long			diff;

	if (pVal && GetVal(&dtDfvTmp) && (memcmp(pVal, &dtDfvTmp, sizeof(dtDfvTmp)) != 0)) {
		memset(&dtDfvCard, 0, sizeof(dtDfvCard));
		memset(&dtDfvTmp, 0, sizeof(dtDfvTmp));

		// Pour la comparaison, on garde uniquement la date, pas l'heure
		dtDfvTmp.wDay = pVal->wDay;
		dtDfvTmp.wDayOfWeek = pVal->wDayOfWeek;
		dtDfvTmp.wMonth = pVal->wMonth;
		dtDfvTmp.wYear = pVal->wYear;

		if (GetCardDfv(&dtDfvCard)) {
			// Date Delta = Dfv carte - Dfv champ
			diff = GetSystemTimeDayDiff(&dtDfvCard, &dtDfvTmp);
			if (diff >= 0) {
				SetInstLongValue(diff);
			}
		}
	}
}

bool CChampDateCfvDelta::GetVal(SYSTEMTIME* pVal) const {
	long				val;
	SYSTEMTIME			dtDfvCard;
	bool				bRes;

	bRes = false;
	if (pVal) {
		memset(&dtDfvCard, 0, sizeof(dtDfvCard));
		if (GetCardDfv(&dtDfvCard)) {
			val = GetInstLongValue();

			//On enlève le nombre de jours à la DFV
			if (RemoveSystemTimeDay(&dtDfvCard, val)) {
				memcpy(pVal, &dtDfvCard, sizeof(dtDfvCard));
				bRes = true;
			}
		}
	}

	return bRes;
}

CChamp*	CChampDateCfvDelta::MakeCopie(CChamp* lpParentCopie) const {
	CChampDateCfvDelta*	res = new CChampDateCfvDelta(lpParentCopie, &m_descripteur, m_dfvCardUnid);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

INT64 CChampDateCfvDelta::GetImageValue() const {
	long	val;

	val = 0;
	if (!IsValNone()) {
		val = GetInstLongValue();
	}
	
	return val;
}

void CChampDateCfvDelta::SetImageValue(INT64 lVal) {
	SetInstLongValue(lVal);
}

bool CChampDateCfvDelta::GetCardDfv(SYSTEMTIME* pDfv) const {
	CChampDate*		pDfvCard;
	bool			bRes;

	bRes = false;
	if (m_dfvCardUnid && pDfv && m_lpParent) {
		pDfvCard = (CChampDate*) m_lpParent->GetChampByUNId(m_dfvCardUnid, LOOKFIELD_UP, this);
		if (pDfvCard) {
			if (pDfvCard->GetVal(pDfv)) {
				bRes = true;
			}
		}
	}

	return bRes;
}
