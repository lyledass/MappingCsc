// ChampDateHeure.h: interface for the CChampDateHeure class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_HEURE_H
#define __CSCMAPPING__CHAMP_DATE_HEURE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateHeure : public CChampDate  
{
public:
	CChampDateHeure(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampDateHeure();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;

	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const ;

	virtual INT64		GetImageValue() const;
	virtual void		SetImageValue(INT64 lVal);

protected:

	enum {
		Date = 0,
		Heure,
	};
};

#endif // __CSCMAPPING__CHAMP_DATE_HEURE_H
