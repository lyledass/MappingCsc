// MapListeBestSpecialEvent.h: interface for the CMapListeBestSpecialEvent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_BEST_SPECIAL_EVENT_H
#define __CSCMAPPING__MAP_LISTE_BEST_SPECIAL_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapResumeSpecialEvent.h"

class CMapListeBestSpecialEvent  
{
public:
	virtual ~CMapListeBestSpecialEvent();

	void					Add(int bestSpecialEventPos, CMapResumeSpecialEvent* bestSpecialEvent);
	int						GetCount() const;
	CMapResumeSpecialEvent*	Get(int i) const;
	void					SwapBestSpecialEventValues(int bestSpecialEventPos1, int bestSpecialEventPos2);

protected:

	CMapListeBestSpecialEvent();

	CListExt<CMapResumeSpecialEvent*>	m_liste;

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_LISTE_BEST_SPECIAL_EVENT_H
