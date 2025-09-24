#ifndef _MAPPING_NDOT_H
#define _MAPPING_NDOT_H

#include "Mapping.h"
#include "MappingZone/NDot/SecureCardFrame.h"
#include "MappingZone/NDot/SecureFixedValueFrame.h"
#include "MappingZone/NDot/UnsecureGenericVariableFrame.h"
#include "MappingZone/NDot/UnsecureVariableValueFrame.h"
#include "MappingZone/NDot/EmvInfos.h"
#include "MapNDotCardInfo.h"


class CMappingNDot : public CMapping {
public:
	CMappingNDot(LPCTSTR szFilename, WORD version);
	CMappingNDot(const CMappingNDot& otherMapping);
	virtual ~CMappingNDot();

	virtual CMappingNDot*	MakeCopie() const;

	///////////////////////////////////
	// Zones
	///////////////////////////////////
	CSecureCardFrame*				GetSecureCardFrame() const;
	CUnsecureGenericVariableFrame*	GetUnsecureGenericVariableFrame() const;
	// Value frames (typically 1-3, )
	unsigned int					GetValueFrameCount() const;
	CSecureFixedValueFrame*			GetSecureFixedValueFrame(int iIndex) const;
	CUnsecureVariableValueFrame*	GetUnsecureVariableValueFrame(int iIndex) const;

	// Virtual field MappingCode (1 per value frame/contract)
	CChampNombre*					GetMappingCode(int iIndex) const;

	CEmvInfos*						GetEmvInfos() const; // Only for EMV cards

	CMapNDotCardInfo*				GetVixCardInfo() const; // Optional (not present on EMV cards)

protected:
	virtual CMapping*	MakeCopieInternal() const;
	virtual void		FieldParseEnd(CChamp* pField, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);

private:
	CSecureCardFrame*				m_pSecureCardFrame;
	CUnsecureGenericVariableFrame*	m_pUnsecureGenericVariableFrame;
	std::map<int, std::unique_ptr<CSecureFixedValueFrame>>		m_secureFixedValueFrame;
	std::map<int, std::unique_ptr<CUnsecureVariableValueFrame>>	m_unsecureVariableValueFrame;
	CEmvInfos*						m_pEmvInfos;
	std::unique_ptr<CMapNDotCardInfo>	m_pVixCardInfo;
};


#endif //_MAPPING_NDOT_H
