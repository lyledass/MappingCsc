// MapCarte.h: interface for the CMapCarte class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_CARTE_H
#define __CSCMAPPING__MAP_CARTE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampNombre.h"
#include "ChampDate.h"
#include "ChampBooleen.h"
#include "ChampTranscarte.h"
#include "ChampEnsemble.h"

class CMapCarte : public CMapSet {
public:
	virtual ~CMapCarte();

	virtual CChampNombre*		GetAppliVersion() const;
	virtual CChampNombre*		GetCodeAppli() const;
	virtual CChampNombre*		GetIssuerId() const;
	virtual CChampDate*			GetDfv() const;
	virtual CChampNombre*		GetCaution() const;
	virtual CChampNombre*		GetDevise() const;
	virtual CChampBooleen*		IsInvalide() const;
	virtual CChampNombre*		GetTelemodif() const;
	virtual CChampNombre*		GetClefTitre() const;
	virtual CChampNombre*		GetNumCarte() const;
	virtual CChampTranscarte*	GetNumTranscarte() const;
	virtual CChampNombre*		GetNumGraphique() const;
	virtual CChampNombre*		GetType() const;
	virtual CChampNombre*		GetNumMapping() const;

	virtual CChampNombre*		GetProfilCurrentCount() const;
	virtual CChampNombre*		GetBestContractCurrentCount() const;
	virtual CChampNombre*		GetBestSpecialEventCurrentCount() const;
	virtual CChampNombre*		GetData2Version() const;

    virtual CChampNombre*       GetReloading() const;

protected:
	CMapCarte(CChampEnsemble*	lpMapRoot);

	friend class CMappingIntercode;
};

#endif // __CSCMAPPING__MAP_CARTE_H
