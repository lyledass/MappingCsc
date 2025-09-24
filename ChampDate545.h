// ChampDate545.h: interface for the CChampDate545 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_545_H
#define __CSCMAPPING__CHAMP_DATE_545_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDate545 : public CChampDate  
{
public:
	CChampDate545(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);

	virtual ~CChampDate545();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const;
};

#endif // __CSCMAPPING__CHAMP_DATE_545_H
