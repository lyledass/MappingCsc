#ifndef _MAPPING_INTERTIC_H
#define _MAPPING_INTERTIC_H

#include "Mapping.h"
#include "MappingZone/Intertic/ZoneDistribution.h"
#include "MappingZone/Intertic/ZoneUsage.h"
#include "MappingZone/Intertic/ZoneCounter.h"
#include "MappingZone/Intertic/ZoneOtp.h"

class CMappingIntertic : public CMapping {
public:
	CMappingIntertic(LPCTSTR szFilename, WORD version);
	CMappingIntertic(const CMappingIntertic& otherMapping);
	virtual ~CMappingIntertic();

	CMappingIntertic*	MakeCopie() const;

	// Zone getters
	CZoneDistribution*	GetZoneDistribution() const;
	CZoneUsage*			GetZoneUsage() const;
	CZoneCounter*		GetZoneCounter() const;
	CZoneOtp*			GetZoneOtp() const;

	// Virtual field CodeMapping
	CChampNombre*		GetCodeMapping() const;

protected:
	virtual void	FieldParseEnd(CChamp* pField, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	CMapping*		MakeCopieInternal() const;

private:
	CZoneDistribution*	m_pZoneDistribution;
	CZoneUsage*			m_pZoneUsage;
	CZoneCounter*		m_pZoneCounter;
	CZoneOtp*			m_pZoneOtp;
};

#endif //_MAPPING_INTERTIC_H
