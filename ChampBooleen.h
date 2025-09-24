// ChampBooleen.h: interface for the CChampBooleen class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_BOOLEEN_H
#define __CSCMAPPING__CHAMP_BOOLEEN_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampBooleen : public CChampSimple  
{
public:
	CChampBooleen(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampBooleen();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;

	void	SetVal(bool b);
	bool	GetVal() const;

	virtual bool	NotToText(LPTSTR szTextVal, size_t textLen) const;
	virtual bool	ToText(LPTSTR szTextVal, size_t textLen) const;
};

#endif // __CSCMAPPING__CHAMP_BOOLEEN_H
