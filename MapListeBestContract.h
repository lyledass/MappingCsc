// MapListeBestContract.h: interface for the CMapListeBestContract class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_BEST_CONTRACT_H
#define __CSCMAPPING__MAP_LISTE_BEST_CONTRACT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapResumeTitre.h"

class CMapListeBestContract  
{
public:
	virtual ~CMapListeBestContract();

	void				Add(int bestContractPos, CMapResumeTitre* bestContract);
	int					GetCount() const;
	CMapResumeTitre*	Get(int bestContractPos) const;
	void				SwapBestContractValues(int bestContractPos1, int bestContractPos2);

protected:

	CMapListeBestContract();

	CListExt<CMapResumeTitre*>	m_liste;

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_LISTE_BEST_CONTRACT_H
