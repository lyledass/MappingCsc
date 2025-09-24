// MapPorteur.h: interface for the CMapPorteur class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_MK3_H
#define __CSCMAPPING__MAP_MK3_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"

class CMapMk3 : public CMapSet  
{
public:
	virtual ~CMapMk3();

	virtual	CChampNombre*	GetMk3Provider() const;
	virtual CChampNombre*	GetMk3Tariff() const;
	virtual CChampDate*		GetMk3StartDate() const;
	virtual CChampDate*		GetMk3EndDate() const;
	virtual CChampNombre*	GetMk3CardZone() const;
	virtual CChampNombre*	GetMk3CardZoneH() const;
	virtual CChampNombre*	GetMk3JourneyRemmain() const;
	virtual CChampNombre*	GetMk3JourneyRemmain1() const;
	virtual CChampNombre*	GetMk3JourneyRemmain2() const;
	virtual CChampNombre*	GetMk3JourneyRemmain3() const;
	virtual CChampNombre*	GetMk3StoreValue() const;
	virtual CChampNombre*	GetMk3StoreValue1() const;
	virtual CChampNombre*	GetMk3StoreValue2() const;
	virtual CChampNombre*	GetMk3StoreValue3() const;

protected :
	CMapMk3(CChampEnsemble*	lpMapRoot);

	friend class CMapping;
};

#endif 
