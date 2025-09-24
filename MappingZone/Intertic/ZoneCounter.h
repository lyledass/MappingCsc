#ifndef _ZONE_COUNTER_H
#define _ZONE_COUNTER_H

#include "../MappingZone.h"

class CZoneCounter : public CMappingZone {
public:
	CZoneCounter(CChampEnsemble *pZoneRoot);
	virtual ~CZoneCounter();

	////////////////////////////////////
	// Structure Compteur
	///////////////////////////////////

	// @function : GetCounterContractCount
	// @field : "[Intertic] CounterContractCount"
	virtual CChampNombre*	GetCounterContractCount() const;

	// @function : GetCounterCount
	// @field : "[Intertic] CounterCount"
	// @resume : Nombre de voyages ou de déplacements ou de rechargements déjà consommés.
	// Lorsque cette donnée est utilisée simultanément à CounterValidityPeriodEndDate,
	// ce nombre est relatif à la période s’achevant à cette date CounterValidityPeriodEndDate.
	virtual CChampNombre*	GetCounterCount() const;

	// @function : GetCounterCountZone
	// @field : "[Intertic] CounterCountZone"
	// @resume : Nombre de zones traversées dans un voyage ou un déplacement, ou sur la durée de vie du billet.
	// Lorsque cette donnée est utilisée simultanément à CounterValidityPeriodEndDate,
	// ce nombre est relatif à la période s’achevant à cette date CounterValidityPeriodEndDate.
	virtual CChampNombre*	GetCounterCountZone() const;

	// @function : GetInterticCounterValidityEndDate
	// @field : "[Intertic] GetInterticCounterValidityEndDate"
	virtual CChampDate*		GetInterticCounterValidityEndDate() const;
	
	// @function : GetCounterValidityPeriodEndDate
	// @field : "[Intertic] CounterValidityPeriodEndDate"
	// @resume : Date de fin de période, codée en nombre de jours restants jusqu’à ContractValidityMediumEndDate.
	virtual CChampDate*		GetCounterValidityPeriodEndDate() const;


	// @function : GetReloading
	// @field : "[Intertic] Reloading"
	// @resume : Compteur "nombre de rechargements" sur BSC.
	CChampNombre* GetReloading() const;

	friend class CMappingIntertic;
};

#endif //_ZONE_COUNTER_H
