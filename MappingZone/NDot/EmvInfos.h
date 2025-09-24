#pragma once

#include "../../ChampTexte.h"
#include "../MappingZone.h"

class CEmvInfos : public CMappingZone
{
public:
	CEmvInfos(CChampEnsemble* pRoot);
	virtual ~CEmvInfos(void);

	CChampNombre*	GetProvider() const;
	CChampDate*		GetEffectiveDate() const;
	CChampDate*		GetExpiryDate() const;
	CChampTexte*	GetTruncatedPan() const;
	// Application name, Application type, ...

};
