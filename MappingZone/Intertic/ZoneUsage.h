#ifndef _ZONE_USAGE_H
#define _ZONE_USAGE_H

#include "../MappingZone.h"
#include "../../MapEvent.h"

class CZoneUsage : public CMappingZone {
public:
	CZoneUsage(CChampEnsemble *pZoneRoot);
	virtual ~CZoneUsage();


	CChampDate*		GetEventDateStamp() const;
	CChampDate*		GetEventTimeStamp() const;
	CChampNombre*	GetEventProvider() const;
	CChampNombre*	GetEventCode() const;

	CChampNombre*	GetEventResult() const;

	// EventGeoBitmap
	CChampNombre*	GetEventGeoRunId() const;
	CChampNombre*	GetEventGeoVehicleId() const;
	CChampNombre*	GetEventGeoRouteId() const;
	CChampNombre*	GetEventGeoRouteDirection() const;
	CChampNombre*	GetEventGeoLocationId() const;
	CChampNombre*	GetEventGeoDeviceId() const;

	// EventValidityBitmap
	CChampDate*		GetEventValidityEndDate() const;
	CChampHeure*	GetEventValidityEndTime() const;
	CChampDate*		GetEventValidityPeriodEndDate() const;
	CChampHeure*	GetEventValidityTimeFirstStamp() const;

	////////////////////////////////////
	// Structure Usage
	///////////////////////////////////

	friend class CMappingIntertic;
};

#endif //_ZONE_USAGE_H
