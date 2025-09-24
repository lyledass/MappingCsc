// MapProfil.h: interface for the CMapProfil class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_PROFIL_H
#define __CSCMAPPING__MAP_PROFIL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"
#include "ChampDate.h"

// ETAT DU PROFIL
enum TPROFIL_ETAT {
	PROFIL_ETAT_UNKNOWN		= -1,	///< Etat du profil indéterminé !
	PROFIL_ETAT_VALIDE		= 0,	///< Profil valide
	PROFIL_ETAT_FUTUR,				///< Profil pas encore valide
	PROFIL_ETAT_PERIME_SOON,		///< Profil est bientot périmé
	PROFIL_ETAT_PERIME,				///< Profil périmé
};

class CMapProfil : public CMapSet {
public:
	virtual ~CMapProfil();

	virtual CMapProfil*		MakeCopie() const;

	virtual CChampNombre*	GetCode();
	virtual CChampDate*		GetDfv();
	virtual CChampDate*		GetDdv();

	virtual void			UpdateValues(const CMapProfil* lpRefProfil);

protected :
	CMapProfil();
	CMapProfil(CChampEnsemble*	lpMapRoot, int numInstance);

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_PROFIL_H
