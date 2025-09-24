// MapListeContract.h: interface for the CMapListeContract class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_CONTRACT_H
#define __CSCMAPPING__MAP_LISTE_CONTRACT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapTitre.h"

class CMapListeContract  
{
public:
	virtual ~CMapListeContract();

	void		Add(int i, CMapTitre* contract);
	int			GetCount() const;
	CMapTitre*	Get(int i) const;

protected:

	CMapListeContract();

	CListExt<CMapTitre*>	m_liste;

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_LISTE_CONTRACT_H
