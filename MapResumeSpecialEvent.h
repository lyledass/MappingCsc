// MapResumeSpecialEvent.h: interface for the CMapResumeSpecialEvent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_RESUME_SPECIAL_EVENT_H
#define __CSCMAPPING__MAP_RESUME_SPECIAL_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"

class CMapResumeSpecialEvent : public CMapSet  
{
public:
	CMapResumeSpecialEvent(CChampEnsemble*	lpMapRoot, int numInstance);
	virtual ~CMapResumeSpecialEvent();

	virtual CMapResumeSpecialEvent*	MakeCopie() const;

	virtual CChampNombre*	GetExploitant();
	virtual CChampNombre*	GetReseau();
	virtual CChampNombre*	GetInstancePointer();
	virtual CChampNombre*	GetGravite();


	virtual void UpdateValues(const CMapResumeSpecialEvent* lpRefSpecialEvent);

protected:
	CMapResumeSpecialEvent();
};

#endif // __CSCMAPPING__MAP_RESUME_SPECIAL_EVENT_H
