// ChampHeure2.h: interface for the CChampHeure2 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_HEURE2_HALF_H
#define __CSCMAPPING__CHAMP_HEURE2_HALF_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampHeure.h"

class CChampHeure2Half : public CChampHeure  
{
public:
	CChampHeure2Half(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampHeure2Half();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_HEURE2_HALF_H
