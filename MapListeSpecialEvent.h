// MapListeSpecialEvent.h: interface for the CMapListeSpecialEvent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_SPECIAL_EVENT_H
#define __CSCMAPPING__MAP_LISTE_SPECIAL_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSpecialEvent.h"

class CMapListeSpecialEvent
{
public:
	virtual ~CMapListeSpecialEvent();

	void				Add(int i, CMapSpecialEvent* event);
	int					GetCount() const;
	CMapSpecialEvent*	Get(int i) const;

protected:
	CMapListeSpecialEvent();

	CListExt<CMapSpecialEvent*>	m_liste;

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_LISTE_SPECIAL_EVENT_H
