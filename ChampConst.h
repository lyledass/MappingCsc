// ChampConst.h: interface for the CChampConst class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_CONST_H
#define __CSCMAPPING__CHAMP_CONST_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampConst : public CChampSimple  
{
public:
	CChampConst(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescr);
	virtual ~CChampConst();

	virtual CChamp*	MakeCopie(CChamp*	lpParentCopie) const;

	virtual bool	ToText(LPTSTR szTextVal, size_t textLen) const;
/*
	virtual void	InitConstValues(bool bForceModified);
	virtual bool	ResetConstValuesFromCopies(const CChamp* lpInitialCopie, const CChamp* lpModifiedCopie);
*/
};

#endif // __CSCMAPPING__CHAMP_CONST_H
