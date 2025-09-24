// MapTitre.h: interface for the CMapTitre class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_TITRE_H
#define __CSCMAPPING__MAP_TITRE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapSet.h"
#include "ChampDate.h"
#include "MapResumeTitre.h"
#include "MapSegment.h"
//#include "Intercode.h"
//#include "../Tarification.h"
#include <Mapping/MappingDeprecated.h>

#define CONTRACT_NAMEDTOKEN_MAX		3
#define ZONES_NBMAX					48

// ETAT DU CONTRAT
enum TCONTRAT_ETAT {
	CONTRAT_ETAT_UNKNOWN	= -1,		///< Etat du contrat indéterminé !
	TITRE_VALIDE			= 0,		///< Contrat valide
	TITRE_PERIME,						///< Contrat périmé
	TITRE_EPUISE,						///< Contrat épuisé
	TITRE_INVALIDE,						///< Contrat invaldidé
	TITRE_ANNULE,						
	TITRE_EFFACABLE,					///< Contrat effacable
	TITRE_JAMAISCONSOMME,				///< Contrat jamais consomé
	TITRE_SUSPENDU,
};

class CMapTitre : public CMapSet {
public:
	virtual ~CMapTitre();

	void					AddSegment(int segPos, CMapSegment* lpSegment);
	CMapSegment*			GetSegment(int segPos) const;
	int						GetSegmentCount() const;

	virtual CMapTitre*		MakeCopie() const;
	virtual void			MakeSegmentCopie(CMapTitre*	lpContrat) const;
	virtual void			Reset();
	virtual void			SetModified();
	virtual bool			IsModified();
	virtual void			Update(const CMapTitre* lpRefMapContract);

	virtual long			GetCodeImage() const;
	virtual	bool			GetImage(CListExt<long>* pCodeImgList) const;

//	virtual void			ComputeState(BOOL bValidOnCreation);
//	virtual void			SetState(TCONTRAT_ETAT	desiredState, BOOL bValidOnCreation);

	virtual TCONTRAT_ETAT	SetState(TCONTRAT_ETAT newState);
	virtual TCONTRAT_ETAT	GetState() const;

	virtual bool			HasCounter() const;

	virtual CChampNombre*	GetCode() const;
	virtual CChampNombre*	GetExploitant() const;
	virtual CChampNombre*	GetCodeFamille() const;
	virtual CChampNombre*	GetCodeMapping() const;
	virtual CChampNombre*	GetSerialNumber() const;

	virtual CChampNombre*	GetPassengerClass() const;
	virtual CChampNombre*	GetSaleAgent() const;
	virtual CChampNombre*	GetSaleDevice() const;
	virtual CChampNombre*	GetTypeMapping() const;
	virtual CChampDate*		GetDfv() const;
	
	// @function : GetStatus
	// @field : "[Intercode] GetIntercodeContratStatus ()"
	// @resume : Représente le statut du contrat
	// @deprecated : Remplacé par GetIntercodeContratStatus
	virtual MAPPING_DECLSPEC_DEPRECATED(MAPPING_V030)
	 CChampNombre*	GetStatus() const;

	virtual CChampDate*		GetSignature() const;
	virtual CChampNombre*	GetChronologie() const;
	virtual CChampNombre*	GetFlagTlm() const;

	// NamedToken
	virtual CChampNombre*	GetJeton1() const;
	virtual CChampNombre*	GetJeton2() const;
	virtual CChampNombre*	GetJeton3() const;
	virtual CChampNombre*	GetJeton(int idxToken) const;
	virtual CChampNombre*	GetJetonLibre();
	virtual void			CleanOldJeton();
	virtual CChampDate*		GetAutoloadDateDebut();
	virtual CChampDate*		GetAutoloadDateArret();

	// SoldX
	virtual CChampNombre*	GetSoldeVoyage() const;
	virtual CChampNombre*	GetSoldeVoyageDebit();
	virtual CChampNombre*	GetSoldeVoyageInitial() const;

	// @function : GetSoldeVoyageConsumed
	// @field : "[Intertic] OTPCount (Sold)"
	// @resume : Représente le nombre de voyages consommés.
	// @deprecated : Remplacé par GetOTPCount
	virtual MAPPING_DECLSPEC_DEPRECATED(MAPPING_V020)
			CChampNombre*	GetSoldeVoyageConsumed() const;

	// TPurse
	virtual CChampNombre*	GetSoldeValeur() const;
	virtual CChampNombre*	GetSoldeValeurDebit();
	virtual CChampNombre*	GetSoldeValeurInitial() const;
	
	// Passenger
	virtual CChampNombre*	GetNbPassagers() const;
	virtual CChampNombre*	GetNbPassagersCorrespondance() const;

	// Z Periodicity
	virtual CChampDate*		GetPeriodDfv() const;
	virtual CChampNombre*	GetPeriodSoldeVoyage() const;
	virtual CChampNombre*	GetPeriodInitialVoyage() const;
	virtual CChampNombre*	GetPeriodType() const;
	virtual	CChampNombre*	GetPeriodIdentity() const;

	////////////////////////////////////
	// Restrictions Geographiques
	///////////////////////////////////
	
	// GeoZonales
	virtual INT64			GetZonesBitmap() const;
	virtual bool			SetZonesFromBitmap(INT64 valeur);
	
	// Gestion des 3 Zones classiques
	virtual CChampNombre*	GetZone1() const;
	virtual CChampNombre*	GetZone2() const;
	virtual CChampNombre*	GetZone3() const;
	
	//Gestion des 48 zones (mapping 21h)
	virtual CChampNombre*	GetZone32_1() const;
	virtual CChampNombre*	GetZone32_2() const;
	virtual CChampNombre*	GetZone48_1() const;
	virtual CChampNombre*	GetZone48_2() const;
	virtual CChampNombre*	GetZone48_3() const;
	virtual long			GetNbMaxZones() const;

	// GeoSection
	virtual CChampNombre*	GetSectionNbZone() const;

	// GeoOD
	//virtual CChampNombre*	GetOrigine() const;
	//virtual CChampNombre*	GetDestination() const;

	// GeoLine
	//virtual CChampNombre*	GetLigne() const;
	virtual CChampDate*		GetHorodatage() const;
	virtual CChampDate*		GetHfv() const;
	virtual CChampNombre*	GetNbJeton() const;
	virtual CChampNombre*	GetIntermodal();
	virtual CChampNombre*	GetClef() const;
	virtual CChampBooleen*	GetInvalide();

	virtual CChampDate*		GetHdv() const;
	virtual CChampNombre*	GetAuthenticator() const;

	// Habilitation
	virtual CChampNombre*	GetHashPinCode() const;
	virtual CChampNombre*	GetRights1() const;
	virtual CChampNombre*	GetRights2() const;
	virtual CChampNombre*	GetPDCShift() const;
	virtual CChampNombre*	GetAgentNumber() const;

	virtual CChampNombre*	GetMinuteCorrespondance() const;
	virtual CChampNombre*	GetReseau() const;
	virtual CChampNombre*	GetValeur();

	// Champs SNCF
	//virtual CChampNombre*	GetLinkedCounter();
	virtual CChampNombre*	GetSncfValidityJourneys() const;
	//virtual CChampNombre*	GetSncfValidityJourneysLeft();
	virtual CChampNombre*	GetSncfJourneyDistance() const;
	virtual CChampNombre*	GetSncfJourneyDuration() const;
	virtual CChampNombre*	GetSncfValidityZoneOrigin() const;
	virtual CChampNombre*	GetSncfValidityZoneDestination() const;
	virtual CChampNombre*	GetSncfValidityZone() const;
	virtual CChampNombre*	GetSncfPayMethod() const;
	virtual CChampNombre*	GetSncfPriceAmount() const;
	virtual CChampDate*		GetSncfSaleDate() const;
	virtual CChampDate*		GetSncfSaleTime() const;
	virtual CChampNombre*	GetSncfLinkedContract() const;
	virtual CChampNombre*	GetSncfReceiptDelivered() const;
	virtual CChampNombre*	GetSncfScreen() const;
	virtual CChampNombre*	GetSncfException() const;
	virtual CChampNombre*	GetSncfProxy() const;
	virtual CChampNombre*	GetSncfTypePriseEnCharge() const;
	virtual CChampNombre*	GetSncfTauxPriseEnCharge() const;
	virtual CChampNombre*	GetSncfMontantPriseEnCharge() const;
	virtual CChampNombre*	GetSncfContratPriseEnCharge() const;
	virtual CChampNombre*	GetSncfProxyReversion() const;
	virtual CChampNombre*	GetSncfVehicleAllowed() const;
	virtual CChampDate*		GetSncfLimiteDate() const;

	////////////////////////////////////
	// Structure Distribution
	///////////////////////////////////

	// @function : GetContractMaxOTP
	// @field : "[Intertic] ContractMaxOTP"
	// @resume : Plafond des valeurs autorisées pour les données OTPCount ou OTPCountZone.
	virtual CChampNombre*	GetContractMaxOTP() const;

	// @function : GetContractMaxCounter
	// @field : "[Intertic] ContractMaxCounter"
	// @resume : Plafond des valeurs autorisées pour les données CounterCount ou CounterCountZone.
	virtual CChampNombre*	GetContractMaxCounter() const;

	////////////////////////////////////
	// Structure OTP
	///////////////////////////////////

	// @function : GetMaxOTP
	// @field : "[Intertic] ContractMaxOTP"
	// @resume : Limitation sur le nombre de rechargement possible sur support CTS.
	// @deprecated : Remplacé par GetContractMaxOTP
	virtual MAPPING_DECLSPEC_DEPRECATED(MAPPING_V020)
			CChampNombre*	GetMaxOTP() const;

	// @function : GetCurrentValueOTP
	// @field : "[Intertic] OTPCount (Reload)"
	// @resume : Valeur courante du nombre de rechargements effectués ou restants (NFO : a voir...)
	// @deprecated : Remplacé par GetOTPCount
	virtual MAPPING_DECLSPEC_DEPRECATED(MAPPING_V020)
			CChampNombre*	GetCurrentValueOTP() const;

	// @function : GetOTPCount
	// @field : "[Intertic] OTPCount"
	// @resume : Nombre de voyages ou de déplacements ou de rechargements déjà consommés.
	virtual CChampNombre*	GetOTPCount() const;

	// @function : GetOTPCountZone
	// @field : "[Intertic] OTPCountZone"
	// @resume : Nombre de zones traversées dans un voyage ou un déplacement, ou sur la durée de vie du billet.
	virtual CChampNombre*	GetOTPCountZone() const;

	// @function : GetOTPValidityEndDate
	// @field : "[Intertic] OTPValidityEndDate"
	// @resume : Date de fin de validité du titre, codée en nombre de jours restants jusqu’à ContractMediumEndDate
	// (exemple : 0 signifie une fin de validité du titre identique à la fin de validité du billet sans contact).
	virtual CChampDate*		GetOTPValidityEndDate() const;

	////////////////////////////////////
	// Structure Compteur
	///////////////////////////////////

	// @function : GetCounterContractCount
	// @field : "[Intertic] CounterContractCount"
	virtual CChampNombre*	GetCounterContractCount() const;

	// @function : GetCounterCount
	// @field : "[Intertic] CounterCount"
	// @resume : Nombre de voyages ou de déplacements ou de rechargements déjà consommés.
	// Lorsque cette donnée est utilisée simultanément à CounterValidityPeriodEndDate,
	// ce nombre est relatif à la période s’achevant à cette date CounterValidityPeriodEndDate.
	virtual CChampNombre*	GetCounterCount() const;

	// @function : GetCounterCountZone
	// @field : "[Intertic] CounterCountZone"
	// @resume : Nombre de zones traversées dans un voyage ou un déplacement, ou sur la durée de vie du billet.
	// Lorsque cette donnée est utilisée simultanément à CounterValidityPeriodEndDate,
	// ce nombre est relatif à la période s’achevant à cette date CounterValidityPeriodEndDate.
	virtual CChampNombre*	GetCounterCountZone() const;

	// @function : GetCounterValidityEndDate
	// @field : "[Intertic] CounterValidityEndDate"
	// @deprecated : remplace par GetInterticCounterValidityEndDate
	virtual MAPPING_DECLSPEC_DEPRECATED(MAPPING_V030)
		CChampDate*		GetCounterValidityEndDate() const;

	// @function : GetInterticCounterValidityEndDate
	// @field : "[Intertic] GetInterticCounterValidityEndDate"
	virtual CChampDate*		GetInterticCounterValidityEndDate() const;
	
	// @function : GetCounterValidityPeriodEndDate
	// @field : "[Intertic] CounterValidityPeriodEndDate"
	// @resume : Date de fin de période, codée en nombre de jours restants jusqu’à ContractValidityMediumEndDate.
	virtual CChampDate*		GetCounterValidityPeriodEndDate() const;


	// @function : GetIntercodeCounterValidityEndDate
	// @field : "[Intercode] GetIntercodeCounterValidityEndDate"
	virtual CChampDate*		GetIntercodeCounterValidityEndDate() const;

	// @function : GetContractDataEndInhibitionDate
	// @field : "[Intertic] GetContractDataEndInhibitionDate"
	virtual CChampDate*		GetContractDataEndInhibitionDate() const;

	// @function : GetIntercodeCounterHfv
	// @field : "[Intertic] GetIntercodeCounterHfv"
	virtual CChampDate*		GetIntercodeCounterHfv() const;

	// @function : GetInterCodeCounterStatus
	// @field : "[Intertic] GetInterCodeCounterStatus"
	virtual CChampNombre*	GetIntercodeCounterStatus() const;

	// @function : GetInterCodeContratStatus
	// @field : "[Intertic] GetInterCodeContratStatus"
	virtual CChampNombre*	GetIntercodeContratStatus() const;
	


	// Hérault (contrat intermodal)
	virtual CChampNombre*	GetHeraultIntermodalMasque() const;
	virtual CChampNombre*	GetHeraultIntermodalCardSerial() const;
	
protected :
	CMapTitre(CChampEnsemble* lpMapRoot, int numInstance);


	CListExt<CMapSegment*>	m_segment;		///< Segments définis pour ce contrat
	long					m_codeImage;	///< Le code image de base des champs du contrat

	TCONTRAT_ETAT			m_state;		///< Etat logique actuel du contrat
											///< doit être initialisé par l'application

	friend class CMappingIntercode;

private :
	CMapTitre();
};

#endif // __CSCMAPPING__MAP_TITRE_H
