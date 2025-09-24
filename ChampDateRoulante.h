// ChampDateRoulante.h: interface for the CChampDateRoulante class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_ROULANTE_H
#define __CSCMAPPING__CHAMP_DATE_ROULANTE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateRoulante : public CChampDate  
{
public:
	CChampDateRoulante(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampDateRoulante();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_DATE_ROULANTE_H
