// MapListeProfils.h: interface for the CMapListeProfils class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_PROFILS_H
#define __CSCMAPPING__MAP_LISTE_PROFILS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapProfil.h"

class CMapListeProfil
{
public:
	virtual ~CMapListeProfil();

	void		Add(int i, CMapProfil* profil);
	int			GetCount() const;
	CMapProfil* Get(int i) const;

	void		SwapProfilValues(int profilPos1, int profilPos2);

protected:
	// virtual CMapListeProfils*	MakeListeProfilsCopie(CMapListeProfils*	copie) const;

	CMapListeProfil();

	CListExt<CMapProfil*>	m_liste;

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_LISTE_PROFILS_H
