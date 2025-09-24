// ChampDateMinute.h: interface for the CChampDateMinute class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_MINUTE_H
#define __CSCMAPPING__CHAMP_DATE_MINUTE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateMinute : public CChampDate  
{
public:
	CChampDateMinute(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescr);
	virtual ~CChampDateMinute();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_DATE_MINUTE_H
