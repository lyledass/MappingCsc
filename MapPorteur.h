// MapPorteur.h: interface for the CMapPorteur class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_PORTEUR_H
#define __CSCMAPPING__MAP_PORTEUR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"
#include "ChampDate.h"

class CMapPorteur : public CMapSet  
{
public:
	virtual ~CMapPorteur();

	virtual	CChampNombre*	GetNumClient() const;
	virtual CChampDate*		GetDateNaissance() const;
	virtual CChampNombre*	GetCardStatus() const;
	virtual CChampNombre*	GetCommercialId() const;
	virtual CChampNombre*	GetSaleDevice() const;
	virtual CChampNombre*	GetAuthenticator() const;
	virtual	CChampNombre*	GetAgentIdNumber() const;
	virtual	CChampNombre*	GetHolderCompany() const;

protected :
	CMapPorteur(CChampEnsemble*	lpMapRoot);

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_PORTEUR_H
