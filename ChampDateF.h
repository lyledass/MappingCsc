// ChampDateF.h: interface for the CChampDateF class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATEF_H
#define __CSCMAPPING__CHAMP_DATEF_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateF : public CChampDate  
{
public:
	CChampDateF(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampDateF();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const ;
};

#endif // __CSCMAPPING__CHAMP_DATEF_H
