// MapSegment.h: interface for the CMapSegment class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_SEGMENT_H
#define __CSCMAPPING__MAP_SEGMENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampEnsemble.h"
#include "ChampNombre.h"
#include "ChampBooleen.h"
#include "ChampPlanningHebdo.h"

class CMapSegment : public CMapSet  
{
public:
	virtual ~CMapSegment();
	virtual CMapSegment*	MakeCopie(CChampEnsemble*	lpMapRootCopie) const;

	virtual CChampNombre*			GetOrigine() const;
	virtual CChampNombre*			GetLigneOrigine() const;
	virtual CChampNombre*			GetVia() const;

	virtual CChampNombre*			GetLigneVia() const;
	virtual CChampNombre*			GetDestination() const;
	virtual CChampNombre*			GetSoldeVoyage() const;
	virtual CChampBooleen*			GetSensForce() const;
	virtual CChampNombre*			GetSensMulti() const;
	virtual CChampPlanningHebdo*	GetPlanningHebdo() const;

	bool	SetOVD(long origine, long destination, long via);

protected:
	CMapSegment();
	CMapSegment(CChampEnsemble*	lpMapRoot, int numInstance);

	friend class CMappingIntercode;
	friend class CMapTitre;
};

#endif // __CSCMAPPING__MAP_SEGMENT_H
