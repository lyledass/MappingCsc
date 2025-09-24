#ifndef _OPERATOR_ID_H
#define _OPERATOR_ID_H

#include "../../ChampTexte.h"
#include "../../ChampNombre.h"
#include "../MappingZone.h"

class COperatorId : public CMappingZone {
public:
	COperatorId(CChampEnsemble* pRoot);
	virtual ~COperatorId();

	CChampTexte*	GetCountry() const;
	CChampTexte*	GetProvince() const;
	CChampTexte*	GetMunicipalityType() const;
	CChampNombre*	GetMunicipality() const;
	CChampTexte*	GetOperator() const;


private:
};

#endif //_OPERATOR_ID_H
