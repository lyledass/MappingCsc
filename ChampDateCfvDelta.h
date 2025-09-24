// ChampDateC.h: interface for the CChampDateC class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_DATE_CFVDELTA_H
#define __CSCMAPPING__CHAMP_DATE_CFVDELTA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampDate.h"

class CChampDateCfvDelta : public CChampDate  
{
public:
	CChampDateCfvDelta(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx, DWORD dfvCardUnid);
	virtual ~CChampDateCfvDelta();

	virtual void		 SetVal(const SYSTEMTIME* pVal);
	virtual bool		 GetVal(SYSTEMTIME* pVal) const;
	virtual CChamp*		 MakeCopie(CChamp* lpParentCopie) const;

	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);

protected :
	bool			GetCardDfv(SYSTEMTIME* pDfvCard) const;

	DWORD			m_dfvCardUnid;
};

#endif // __CSCMAPPING__CHAMP_DATE_CFVDELTA_H
