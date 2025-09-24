// ChampTranscarte.h: interface for the CChampTranscarte class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_TRANSCARTE_H
#define __CSCMAPPING__CHAMP_TRANSCARTE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampTranscarte : public CChampSimple  
{
public:
	CChampTranscarte(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampTranscarte();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const ;

	virtual void	SetVal(long val);
	virtual bool	ToText(LPTSTR szTextVal, size_t textLen) const;

protected:
	virtual long GetVal() const;

	long	m_numSerie;		// le numéro de série de la carte
							// on ne stocke que les 39 derniers bits dans la carte
							// mais on affiche le numéro en entier !
};

#endif // __CSCMAPPING__CHAMP_TRANSCARTE_H
