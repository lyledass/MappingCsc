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
	// @resume : Nombre de voyages ou de d�placements ou de rechargements d�j� consomm�s.
	virtual CChampNombre*	GetOTPCount() const;

	// @function : GetOTPCountZone
	// @field : "[Intertic] OTPCountZone"
	// @resume : Nombre de zones travers�es dans un voyage ou un d�placement, ou sur la dur�e de vie du billet.
	virtual CChampNombre*	GetOTPCountZone() const;

	// @function : GetOTPValidityEndDate
	// @field : "[Intertic] OTPValidityEndDate"
	// @resume : Date de fin de validit� du titre, cod�e en nombre de jours restants jusqu�� ContractMediumEndDate
	// (exemple�: 0 signifie une fin de validit� du titre identique � la fin de validit� du billet sans contact).
	virtual CChampDate*		GetOTPValidityEndDate() const;

	friend class CMappingIntertic;
};

#endif //_ZONE_OTP_H
