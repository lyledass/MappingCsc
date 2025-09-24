// ChampDate.h: interface for the CChampDate class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_H
#define __CSCMAPPING__CHAMP_DATE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// #include <AfxDisp.h>
#include "ChampSimple.h"

class CChampDate : public CChampSimple
{
public:
	virtual ~CChampDate();

	virtual void		 SetVal(const SYSTEMTIME* pVal) = 0;
	virtual bool		 GetVal(SYSTEMTIME* pVal) const = 0;

	virtual bool		ToText(LPTSTR szTextVal, size_t textLen) const;

	//long				GetValLong() const;

	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);

protected :
	virtual int		GetFirstYear() const;
	virtual	long	GetSystemTimeDayDiff(const SYSTEMTIME* pVal, const SYSTEMTIME* pRef) const;
	virtual	bool	AddSystemTimeDay(SYSTEMTIME* pVal, long dayCount) const;
	virtual	bool	RemoveSystemTimeDay(SYSTEMTIME* pVal, long dayCount) const;

	CChampDate(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
};

#endif // __CSCMAPPING__CHAMP_DATE_H
