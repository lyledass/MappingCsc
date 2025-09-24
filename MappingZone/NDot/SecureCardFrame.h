#ifndef _ZONE_SECURE_CARD_FRAME_H
#define _ZONE_SECURE_CARD_FRAME_H

#include "../MappingZone.h"
#include "../../ChampTexte.h"
#include "OperatorId.h"
#include <map>
#include <memory>

class CSecureCardFrame : public CMappingZone {
public:
	CSecureCardFrame(CChampEnsemble* pRoot);
	virtual ~CSecureCardFrame();

	////////////////////////////////////
	// Secure Card Frame
	///////////////////////////////////

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetFrameRevision() const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetValueFrameMap() const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetCommuterClassMap() const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampTexte*	GetCommuterCitizenship() const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetCommuterId() const;

	// @function : 
	// @field : "[NDot] "
	virtual COperatorId*	GetValueFrameOperatorId(int iIndex) const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetSecureFixedFrameLocation(int iIndex) const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetUnsecureVariableFrameLocation(int iIndex) const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetUnsecureGenericVariableFrameLocation() const;

	// @function : 
	// @field : "[NDot] "
	virtual CChampNombre*	GetSFIUsageMap() const;

protected:
	CMappingZone*	AddZone(MAP_FIELDS_ID fieldId, CChampEnsemble* pRoot, int iInstance);

private:
	std::map<int, std::unique_ptr<COperatorId>>	m_OperatorId;

	friend class CMappingNDot;
};

#endif //_ZONE_SECURE_CARD_FRAME_H
