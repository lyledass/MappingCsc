// ChampCase.h: interface for the CChampCase class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_CASE_H
#define __CSCMAPPING__CHAMP_CASE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampEnsemble.h"

class CChampCase : public CChampEnsemble  
{
public:
	CChampCase(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescr);
	virtual ~CChampCase();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;
};

#endif // __CSCMAPPING__CHAMP_CASE_H