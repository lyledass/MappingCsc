// ChampDateC.h: interface for the CChampDateC class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATEC_H
#define __CSCMAPPING__CHAMP_DATEC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateC : public CChampDate  
{
public:
	CChampDateC(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampDateC();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const;

	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);
};

#endif // __CSCMAPPING__CHAMP_DATEC_H
