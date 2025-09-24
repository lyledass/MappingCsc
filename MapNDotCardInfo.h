#pragma once

#include "MapSet.h"

class CMapNDotCardInfo : public CMapSet {
public:
	virtual ~CMapNDotCardInfo();

	virtual CChampDate*			GetValidityEndDate() const;

protected:
	CMapNDotCardInfo(CChampEnsemble*	lpMapRoot);

	friend class CMappingNDot;
};
