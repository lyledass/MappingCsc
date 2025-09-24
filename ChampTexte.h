// ChampTexte.h: interface for the CChampTexte class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_TEXTE_H
#define __CSCMAPPING__CHAMP_TEXTE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampTexte : public CChampSimple  
{
public:
	CChampTexte(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampTexte();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;

	inline UINT	GetCharLength() const;
	void	SetVal(LPCSTR szTextVal);
	bool	GetVal(LPSTR szTextVal, size_t textLen) const;

	virtual	bool	ToText(LPTSTR szTextVal, size_t textLen) const;
};

#endif // __CSCMAPPING__CHAMP_TEXTE_H
