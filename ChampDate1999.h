// ChampDate1999.h: interface for the CChampDate1999 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE1999_H
#define __CSCMAPPING__CHAMP_DATE1999_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDate1999 : public CChampDate  
{
public:
	CChampDate1999(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescr);
	virtual ~CChampDate1999();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_DATE1999_H
