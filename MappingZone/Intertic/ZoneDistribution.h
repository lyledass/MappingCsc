#ifndef _ZONE_DISTRIBUTION_H
#define _ZONE_DISTRIBUTION_H

#include "../MappingZone.h"
#include "../../MapTitre.h"

class CZoneDistribution : public CMappingZone {
public:
	CZoneDistribution(CChampEnsemble *pZoneRoot);
	virtual ~CZoneDistribution();

	////////////////////////////////////
	// Structure Usage
	///////////////////////////////////

	// @function : GetContractNetworkId
	// @resume : 
	CChampNombre* GetContractNetworkId() const;

	// @function : GetContractAppliVersionNumber
	// @resume : 
	CChampNombre* GetContractAppliVersionNumber() const;

	// @function : GetContractProvider
	// @resume : 
	CChampNombre* GetContractProvider() const;

	// @function : GetContractTariff
	// @resume : 
	CChampNombre* GetContractTariff() const;

	// @function : GetContractMediumEndDate
	// @resume : 
	CChampDate* GetContractMediumEndDate() const;


	////////////// ContractGeoBitmap ///////////////
	// @function : GetContractGeoZoneList1
	// @resume : 
	CChampNombre* GetContractGeoZoneList1() const;

	// @function : GetContractGeoZoneList2
	// @resume : 
	CChampNombre* GetContractGeoZoneList2() const;


	// @function : GetContractGeoZoneSetOrigin
	// @resume : 
	CChampNombre* GetContractGeoZoneSetOrigin() const;

	// @function : GetContractGeoZoneSetDestination
	// @resume : 
	CChampNombre* GetContractGeoZoneSetDestination() const;

	// @function : GetContractGeoZoneSetVia
	// @resume : 
	CChampNombre* GetContractGeoZoneSetVia() const;


	// @function : GetContractGeoOVDOrigin
	// @resume : 
	CChampNombre* GetContractGeoOVDOrigin(int iIndex) const;

	// @function : GetContractGeoOVDDestination
	// @resume : 
	CChampNombre* GetContractGeoOVDDestination(int iIndex) const;

	// @function : GetContractGeoOVDVia
	// @resume : 
	CChampNombre* GetContractGeoOVDVia(int iIndex) const;


	// @function : GetContractGeoLine1
	// @resume : 
	CChampNombre* GetContractGeoLine1() const;

	// @function : GetContractGeoLine2
	// @resume : 
	CChampNombre* GetContractGeoLine2() const;


	////////////// ContractValidityBitmap ///////////////
	// @function : GetContractValidityStartDate
	// @resume : 
	CChampDate* GetContractValidityStartDate() const;

	// @function : GetContractValidityStartTime
	// @resume : 
	CChampHeure* GetContractValidityStartTime() const;

	// @function : GetContractValidityEndDate
	// @resume : 
	CChampDate* GetContractValidityEndDate() const;

	// @function : GetContractValidityEndTime
	// @resume : 
	CChampHeure* GetContractValidityEndTime() const;

	// @function : GetContractValidityDuration
	// @resume : 
	CChampNombre* GetContractValidityDuration() const;


	////////////// ContractPassengerBitmap ///////////////
	// @function : GetContractPassengerClass
	// @resume : 
	CChampNombre* GetContractPassengerClass() const;

	// @function : GetContractPassengerTotal
	// @resume : 
	CChampNombre* GetContractPassengerTotal() const;


	////////////// ContractSaleBitmap ///////////////
	// @function : GetContractSaleAgent
	// @resume : 
	CChampNombre* GetContractSaleAgent() const;

	// @function : GetContractSaleDevice
	// @resume : 
	CChampNombre* GetContractSaleDevice() const;


	////////////// ContractMaxBitmap ///////////////
	// @function : GetContractMaxOTP
	// @resume : 
	CChampNombre* GetContractMaxOTP() const;

	// @function : GetAppliVersionNumber
	// @resume : 
	CChampNombre* GetContractMaxCounter() const;


private:
	friend class CMappingIntertic;
};

#endif //_ZONE_DISTRIBUTION_H
