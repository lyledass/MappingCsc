// ChampConst.cpp: implementation of the CChampConst class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampConst.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampConst::CChampConst(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescr)
	: CChampSimple(lpParent, lpcFieldDescr)
{
	SetInstLongValue(m_descripteur.header.prop.defVal);
	//m_instance.modified = FALSE;
}

CChampConst::~CChampConst()
{
}

CChamp*	CChampConst::MakeCopie(CChamp*	lpParentCopie) const {
	CChampConst* res = new CChampConst(lpParentCopie, &m_descripteur);
	
	return CChampSimple::MakeInstanceCopie(lpParentCopie, res);
}

bool CChampConst::ToText(LPTSTR szTextVal, size_t textLen) const {
	bool	bRes;

	bRes = false;
	if (szTextVal) {
		_stprintf_s(szTextVal, textLen, _T("%lli"), GetInstLongValueEx());

		bRes = true;
	}
	return bRes;
}

