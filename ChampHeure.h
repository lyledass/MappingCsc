// ChampHeure.h: interface for the CChampHeure class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_HEURE_H
#define __CSCMAPPING__CHAMP_HEURE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampHeure : public CChampDate  
{
public:
	CChampHeure(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampHeure();

	virtual void	SetVal(const SYSTEMTIME* pVal) = 0;
	virtual bool	GetVal(SYSTEMTIME* pVal) const = 0;

	virtual bool	ToText(LPTSTR szTextVal, size_t textLen) const;

	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);

protected :

};

#endif // __CSCMAPPING__CHAMP_HEURE_H
