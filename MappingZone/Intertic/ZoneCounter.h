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
	// @resume : Nombre de voyages ou de d�placements ou de rechargements d�j� consomm�s.
	// Lorsque cette donn�e est utilis�e simultan�ment � CounterValidityPeriodEndDate,
	// ce nombre est relatif � la p�riode s�achevant � cette date CounterValidityPeriodEndDate.
	virtual CChampNombre*	GetCounterCount() const;

	// @function : GetCounterCountZone
	// @field : "[Intertic] CounterCountZone"
	// @resume : Nombre de zones travers�es dans un voyage ou un d�placement, ou sur la dur�e de vie du billet.
	// Lorsque cette donn�e est utilis�e simultan�ment � CounterValidityPeriodEndDate,
	// ce nombre est relatif � la p�riode s�achevant � cette date CounterValidityPeriodEndDate.
	virtual CChampNombre*	GetCounterCountZone() const;

	// @function : GetInterticCounterValidityEndDate
	// @field : "[Intertic] GetInterticCounterValidityEndDate"
	virtual CChampDate*		GetInterticCounterValidityEndDate() const;
	
	// @function : GetCounterValidityPeriodEndDate
	// @field : "[Intertic] CounterValidityPeriodEndDate"
	// @resume : Date de fin de p�riode, cod�e en nombre de jours restants jusqu�� ContractValidityMediumEndDate.
	virtual CChampDate*		GetCounterValidityPeriodEndDate() const;


	// @function : GetReloading
	// @field : "[Intertic] Reloading"
	// @resume : Compteur "nombre de rechargements" sur BSC.
	CChampNombre* GetReloading() const;

	friend class CMappingIntertic;
};

#endif //_ZONE_COUNTER_H
