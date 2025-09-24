// ChampDateNDot.h: interface for the CChampDateNDot class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_NDOT_H
#define __CSCMAPPING__CHAMP_DATE_NDOT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateNDot : public CChampDate
{
public:
	CChampDateNDot(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampDateNDot();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const;

	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);
};

#endif // __CSCMAPPING__CHAMP_DATE_NDOT_H
