// ChampDateMk3.h: interface for the CChampDateMk3 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_MK3_H
#define __CSCMAPPING__CHAMP_DATE_MK3_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateMk3 : public CChampDate  
{
public:
	CChampDateMk3(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);

	virtual ~CChampDateMk3();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const;
};

#endif // __CSCMAPPING__CHAMP_DATE_Mk3_H
