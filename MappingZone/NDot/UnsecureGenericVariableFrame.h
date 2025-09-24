#ifndef _ZONE_UNSECURE_GENERIC_VARIABLE_FRAME_H
#define _ZONE_UNSECURE_GENERIC_VARIABLE_FRAME_H

#include "../MappingZone.h"
#include "LocationId.h"

class CUnsecureGenericVariableFrame : public CMappingZone {
public:
	CUnsecureGenericVariableFrame(CChampEnsemble* pRoot);
	virtual ~CUnsecureGenericVariableFrame();


	CChampDate*		GetBoardingDateTime() const;
	CChampNombre*	GetBoardingLocationType() const;
	CLocationId*	GetBoardingRouteIdFacilityId() const;

	CChampNombre*	GetBoardingValueFrame() const;
	CChampNombre*	GetBoardingValidationStatus() const;

	CChampNombre*	GetFarePaidSoFarThisJourney() const;

	CChampDate*		GetAlightingDateTime() const;
	CChampNombre*	GetAlightingLocationType() const;
	CLocationId*	GetAlightingRouteIdFacilityId() const;
	CChampNombre*	GetAlightingValueFrame() const;
	CChampNombre*	GetAlightingValidationStatus() const;

	CChampNombre*	GetLegNumber() const;
	CChampNombre*	GetJourneyAdditionalChildCount() const;
	CChampNombre*	GetTransferAdditionalChildCount() const;

	CChampNombre*	GetMACError() const;

protected:

private:
	CLocationId*	m_pBoardingFacilityId;
	CLocationId*	m_pAlightingFacilityId;
};

#endif //_ZONE_UNSECURE_GENERIC_VARIABLE_FRAME_H
