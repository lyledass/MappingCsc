#ifndef _ZONE_UNSECURE_VARIABLE_VALUE_FRAME_H
#define _ZONE_UNSECURE_VARIABLE_VALUE_FRAME_H

#include "../MappingZone.h"

class CUnsecureVariableValueFrame : public CMappingZone {
public:
	CUnsecureVariableValueFrame(CChampEnsemble* pRoot);
	virtual ~CUnsecureVariableValueFrame();

	CChampNombre*	GetBlockingStatus() const;
	CChampNombre*	GetTransactionSequenceId() const;
	CChampDate*		GetLastDateUsage() const;

	// For Transit Stored Value
	CChampNombre*	GetSpare() const;
	CChampNombre*	GetRemainingValue() const;

	// For Limited and unlimited pass
	CChampNombre*	GetDailyInCounter() const;
	CChampNombre*	GetDailyOutCounter() const;

	// For Multirides products
	CChampNombre*	GetRemainingRides() const;

    // For Special container products
	CChampNombre*	GetLastJourneyCheckInStatus() const;
	CChampNombre*	GetLastJourneyAddPassengers() const;
	CChampNombre*	GetValueOnCredit() const;

protected:

private:
};

#endif //_ZONE_UNSECURE_VARIABLE_VALUE_FRAME_H
