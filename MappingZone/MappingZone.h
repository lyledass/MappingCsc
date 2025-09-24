#ifndef _MAPPING_ZONE_H
#define _MAPPING_ZONE_H

#include "Mapping.h"

// Mapping zone : similar to CMapSet but more simple (includes only one Data in the mapping)
class CMappingZone {
public:
	CMappingZone(CChampEnsemble *pZoneRoot);
	virtual ~CMappingZone();

	CChampEnsemble*		GetRoot() const;

	virtual void	Reset();
	virtual void	SetModified(bool modified = true);

protected:
	CChamp*				GetChampById(int fieldId, int iInstance = 0) const;

	CChampEnsemble	*m_pRoot;

	friend class CMapping;
};

#endif //_MAPPING_ZONE_H
