#ifndef _LOCATION_ID_H
#define _LOCATION_ID_H

#include "../../ChampTexte.h"
#include "../../ChampNombre.h"
#include "../MappingZone.h"

class CLocationId : public CMappingZone {
public:
	CLocationId(CChampEnsemble* pRoot);
	virtual ~CLocationId();

	CChampTexte*	GetCountry() const;
	CChampTexte*	GetProvince() const;
	CChampTexte*	GetMunicipalityType() const;
	CChampNombre*	GetMunicipality() const;
	CChampTexte*	GetStopType() const;
	CChampNombre*	GetStop() const;


private:
};

#endif //_LOCATION_ID_H
