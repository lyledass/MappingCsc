// MapPorteur.h: interface for the CMapPorteur class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_VIXAGENTDATA_H
#define __CSCMAPPING__MAP_VIXAGENTDATA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"

class CMapVixAgentData : public CMapSet  
{
public:
	virtual ~CMapVixAgentData();

	virtual	CChampNombre*	GetVixAgentRights1() const;
	virtual CChampNombre*	GetVixAgentRights2() const;

protected :
	CMapVixAgentData(CChampEnsemble*	lpMapRoot);

	friend class CMapping;
};

#endif // __CSCMAPPING__MAP_PORTEUR_H
