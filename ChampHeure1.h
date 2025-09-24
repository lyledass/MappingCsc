// ChampHeure1.h: interface for the CChampHeure1 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_HEURE1_H
#define __CSCMAPPING__CHAMP_HEURE1_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampHeure.h"

class CChampHeure1 : public CChampHeure  
{
public:
	CChampHeure1(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampHeure1();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_HEURE1_H
