#ifndef _ZONE_OTP_H
#define _ZONE_OTP_H

#include "../MappingZone.h"

class CZoneOtp : public CMappingZone {
public:
	CZoneOtp(CChampEnsemble *pZoneRoot);
	virtual ~CZoneOtp();

	////////////////////////////////////
	// Structure OTP
	///////////////////////////////////

	// @function : GetOTPCount
	// @field : "[Intertic] OTPCount"
	// @resume : Nombre de voyages ou de déplacements ou de rechargements déjà consommés.
	virtual CChampNombre*	GetOTPCount() const;

	// @function : GetOTPCountZone
	// @field : "[Intertic] OTPCountZone"
	// @resume : Nombre de zones traversées dans un voyage ou un déplacement, ou sur la durée de vie du billet.
	virtual CChampNombre*	GetOTPCountZone() const;

	// @function : GetOTPValidityEndDate
	// @field : "[Intertic] OTPValidityEndDate"
	// @resume : Date de fin de validité du titre, codée en nombre de jours restants jusqu’à ContractMediumEndDate
	// (exemple : 0 signifie une fin de validité du titre identique à la fin de validité du billet sans contact).
	virtual CChampDate*		GetOTPValidityEndDate() const;

	friend class CMappingIntertic;
};

#endif //_ZONE_OTP_H
