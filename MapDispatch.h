// MapDispatch.h: interface for the MapDispatch class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_DISPATCH_H
#define __CSCMAPPING__MAP_DISPATCH_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"

class CMapDispatch : public CMapSet  
{
public:
	virtual ~CMapDispatch();

	virtual CChampDate*		GetDispatchDate() const;
	virtual CChampDate*		GetDispatchTime() const;

protected :
	CMapDispatch(CChampEnsemble* lpMapRoot);

	friend class CMapping;
};

#endif // __CSCMAPPING__MAP_DISPATCH_H
