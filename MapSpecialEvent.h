// MapSpecialEvent.h: interface for the CMapSpecialEvent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_SPECIAL_EVENT_H
#define __CSCMAPPING__MAP_SPECIAL_EVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampDate.h"
#include "ChampHeure.h"

class CMapSpecialEvent : public CMapSet  
{
public:
	virtual ~CMapSpecialEvent();

	virtual CMapSpecialEvent*	MakeCopie() const;

	virtual CChampDate*		GetDate() const;
	virtual CChampHeure*	GetHeure() const;
	virtual CChampNombre*	GetDonneesAffichage() const;
	virtual CChampNombre*	GetReseau() const;
	virtual CChampNombre*	GetCode() const;
	virtual CChampNombre*	GetResultat() const;
	virtual CChampNombre*	GetExploitant() const;
	virtual CChampNombre*	GetCompteursEvtAnormaux() const;
	virtual CChampNombre*	GetNumeroSerie() const;
	virtual CChampNombre*	GetDestination() const;
	virtual CChampNombre*	GetLocalisationId() const;
	virtual CChampNombre*	GetPassageId() const;
	virtual CChampNombre*	GetEquipementId() const;
	virtual CChampNombre*	GetLigneDerniereMontee() const;
	virtual CChampNombre*	GetLigneVariante() const;
	virtual CChampNombre*	GetMissionRef() const;
	virtual CChampNombre*	GetVehiculeId() const;
	virtual CChampNombre*	GetVehiculeType() const;
	virtual CChampNombre*	GetLocalisationType() const;
	virtual CChampNombre*	GetEmploye() const;
	virtual CChampNombre*	GetLocalisationRef() const;
	virtual CChampNombre*	GetCorrespondancesNombre() const;
	virtual CChampNombre*	GetVoyagesNombre() const;
	virtual CChampNombre*	GetVoyagesTotal() const;
	virtual CChampNombre*	GetDistance() const;
	virtual CChampNombre*	GetMontant() const;
	virtual CChampNombre*	GetMontantUnite() const;
	virtual CChampNombre*	GetPointeurContrat() const;
	virtual CChampNombre*	GetCodeSecurite() const;
	virtual CChampDate*		GetDatePremiereMontee() const;
	virtual CChampHeure*	GetHeurePremiereMontee() const;
	virtual CChampNombre*	GetValidationMode() const;
	virtual CChampNombre*	GetTroncon() const;
	virtual CChampNombre*	GetSens() const;

protected:
	CMapSpecialEvent(CChampEnsemble* lpMapRoot, int numInstance);

	friend class CMappingIntercode;

private :
	CMapSpecialEvent();
};

#endif // __CSCMAPPING__MAP_SPECIAL_EVENT_H
