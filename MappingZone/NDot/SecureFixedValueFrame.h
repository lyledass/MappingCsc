#ifndef _ZONE_SECURE_FIXED_VALUE_FRAME_H
#define _ZONE_SECURE_FIXED_VALUE_FRAME_H

#include "../MappingZone.h"
#include "../../ChampTexte.h"

class CSecureFixedValueFrame : public CMappingZone {
public:
	CSecureFixedValueFrame(CChampEnsemble* pRoot);
	virtual ~CSecureFixedValueFrame();

	CChampNombre*	GetProductContractCategory() const;
	CChampNombre*	GetProductContractId() const;

	CChampNombre*	GetSpecialEventUniqueInstanceId() const;

	CChampDate*		GetStartDateForFrame() const;
	CChampDate*		GetEndDateForFrame() const;

	CChampNombre*	GetSpare() const;
	CChampNombre*	GetDiscountPercent() const;

	CChampNombre*	GetFormatVersion() const;
	CChampNombre*	GetCommuterLanguage() const;
	CChampNombre*	GetCardPurchasePrice() const;

	CChampNombre*	GetMACError() const;

protected:

private:
};

#endif //_ZONE_SECURE_FIXED_VALUE_FRAME_H
