// MapListeShiftEvent.h: interface for the CMapListeShiftEvent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_LISTE_SHIFT_EVENT_H
#define __CSCMAPPING__MAP_LISTE_SHIFT_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapShiftEvent.h"

class CMapListeShiftEvent  
{
public:
	virtual ~CMapListeShiftEvent();

	void			Add(int pos, CMapShiftEvent* eventShift);
	int				GetCount() const;
	CMapShiftEvent*	Get(int i) const;

protected:

	CMapListeShiftEvent();

	CListExt<CMapShiftEvent*>	m_liste;

	friend class CMapping;
};

#endif // __CSCMAPPING__MAP_LISTE_SHIFT_EVENT_H
