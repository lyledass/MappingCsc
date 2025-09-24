// MapAgent.h: interface for the CMapAgent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_AGENT_H
#define __CSCMAPPING__MAP_AGENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"
#include "ChampDate.h"


class CMapAgent : public CMapSet  
{
public:
	CMapAgent::CMapAgent();
	virtual ~CMapAgent();

	virtual	CChampDate*		GetContratValidityEndDate() const;
	virtual	CChampNombre*	GetContractProvider() const;
	virtual	CChampNombre*	GetContractTariff() const;
	virtual	CChampNombre*	GetContratStatus() const;
	virtual	CChampNombre*	GetHashPinCode() const;
	virtual	CChampNombre*	GetAgentRights1() const;
	virtual	CChampNombre*	GetAgentRights2() const;
	virtual	CChampNombre*	GetAgentPDCShift() const;
	virtual	CChampNombre*	GetAgentNumber() const;

protected :
	CMapAgent(CChampEnsemble*	lpMapRoot);

	friend class CMappingAgent;
};

#endif // __CSCMAPPING__MAP_AGENT_H