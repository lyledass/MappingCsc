// ChampPlanningHebdo.h: interface for the CChampPlanningHebdo class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_PLANNING_HEBDO_H
#define __CSCMAPPING__CHAMP_PLANNING_HEBDO_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampPlanningHebdo : public CChampSimple  
{
public:
	CChampPlanningHebdo(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampPlanningHebdo();


	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;
	virtual void	SetVal(long val);

	virtual bool	ToText(LPTSTR szTextVal, size_t textLen) const;

	DWORD GetVal() const;
	void SetValJour(BYTE jour, bool matin, bool apresmidi);

protected:	
};

#endif // __CSCMAPPING__CHAMP_PLANNING_HEBDO_H
