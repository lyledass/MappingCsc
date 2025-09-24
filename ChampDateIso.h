// ChampDateIso.h: interface for the CChampDateIso class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_ISO_H
#define __CSCMAPPING__CHAMP_DATE_ISO_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateIso : public CChampDate  
{
public:
	CChampDateIso(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescr);
	virtual ~CChampDateIso();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_DATE_ISO_H
