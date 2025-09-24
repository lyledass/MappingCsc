// MapListeEvent.h: interface for the CMapListeEvent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_EVENT_H
#define __CSCMAPPING__MAP_LISTE_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapEvent.h"

class CMapListeEvent  
{
public:
	virtual ~CMapListeEvent();

	void		Add(int i, CMapEvent* event);
	int			GetCount() const;
	CMapEvent*	Get(int i) const;

protected:

	CMapListeEvent();

	CListExt<CMapEvent*>	m_liste;

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_LISTE_EVENT_H
