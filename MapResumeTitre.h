// MapResumeTitre.h: interface for the CMapResumeTitre class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_RESUME_TITRE_H
#define __CSCMAPPING__MAP_RESUME_TITRE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"

class CMapResumeTitre : public CMapSet  
{
public:
	CMapResumeTitre(CChampEnsemble*	lpMapRoot, int numInstance);
	virtual ~CMapResumeTitre();

	virtual CMapResumeTitre*	MakeCopie() const;

	virtual CChampNombre*	GetCode();
	virtual CChampNombre*	GetExploitant();
	virtual CChampNombre*	GetReseau();
	virtual CChampNombre*	GetInstancePointer();
	virtual CChampNombre*	GetPriorite();
	virtual CChampNombre*	GetTypeContrat();

	virtual void UpdateValues(const CMapResumeTitre* lpRefBestContract);

protected:
	CMapResumeTitre();
};

#endif // __CSCMAPPING__MAP_RESUME_TITRE_H
