// MapPorteur.h: interface for the CMapPorteur class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_SHIFT_EVENT_H
#define __CSCMAPPING__MAP_SHIFT_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"

class CMapShiftEvent : public CMapSet  
{
public:
	virtual ~CMapShiftEvent();

	virtual	CChampNombre*	GetShiftStatus() const;

	virtual CChampDate*		GetShiftFirstOpenDate() const;
	virtual CChampDate*		GetShiftFirstOpenTime() const;

	virtual CChampNombre*	GetShiftLastVehiculeId() const;
	virtual CChampNombre*	GetShiftLastDeviceId() const;
	virtual CChampDate*		GetShiftLastOpenDate() const;
	virtual CChampDate*		GetShiftLastOpenTime() const;
	virtual CChampDate*		GetShiftLastCloseDate() const;
	virtual CChampDate*		GetShiftLastCloseTime() const;

	virtual CChampNombre*	GetShiftSalesCount() const;
	virtual CChampNombre*	GetShiftSalesAmount() const;

	virtual CChampNombre*	GetShiftCancellationsCount() const;
	virtual CChampNombre*	GetShiftCancellationsAmount() const;

protected :
	CMapShiftEvent(CChampEnsemble*	lpMapRoot, int numInstance);

	friend class CMapping;
};

#endif 
