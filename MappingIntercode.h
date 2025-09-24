#ifndef _MAPPING_INTERCODE_H
#define _MAPPING_INTERCODE_H

#include "Mapping.h"

#include "MapCarte.h"
#include "MapAgent.h"
#include "MapPorteur.h"
#include "MapListeProfils.h"
#include "MapListeBestContract.h"
#include "MapListeContract.h"
#include "MapListeEvent.h"
#include "MapListeSpecialEvent.h"
#include "MapListeBestSpecialEvent.h"


class CMappingIntercode : public CMapping {
public:
	CMappingIntercode(LPCTSTR szFilename, WORD version);
	CMappingIntercode(const CMappingIntercode& otherMapping);
	virtual ~CMappingIntercode();


	virtual CMappingIntercode*	MakeCopie() const;
	virtual BOOL			UpdateFromModifiedCopy(const CMappingIntercode* pCopy);

	// Access to mapping areas
	CMapCarte*				GetCarte()					const;
	CMapPorteur*			GetPorteur()				const;
	int						GetProfilCount()			const;
	CMapProfil*				GetProfil(int i)			const;
	int						GetBestContractCount()		const;
	CMapResumeTitre*		GetBestContract(int i)		const;
	int						GetContractCount()			const;
	CMapTitre*				GetContract(int i)			const;
	int						GetEventCount()				const;
	CMapEvent*				GetEvent(int i)				const;
	int						GetBestSpecialEventCount()	const;
	CMapResumeSpecialEvent*	GetBestSpecialEvent(int i)	const;
	int						GetSpecialEventCount()		const;
	CMapSpecialEvent*		GetSpecialEvent(int i)		const;


	void	SwapBestContractValues		(int bestContractPos1, int bestContractPos2);
	void	SwapBestSpecialEventValues	(int bestSpecialEventPos1, int bestSpecialEventPos2);
	void	SwapProfilValues			(int profilPos1, int profilPos2);


protected:
	CMapCarte*					m_cardInfo;					// Les informations de la carte
	CMapPorteur*				m_holderInfo;				// Les informations du porteur
	CMapListeProfil				m_profilList;				// La liste des profils de la carte
	CMapListeBestContract		m_bestContractList;			// La liste des best contrats
	CMapListeContract			m_contractList;				// La liste des contrats
	CMapListeEvent				m_eventList;				// La liste des évènements de la carte
	CMapListeSpecialEvent		m_specialEventList;			// La liste des évènements spéciaux de la carte
	CMapListeBestSpecialEvent	m_bestSpecialEventList;		// La liste des résumés des évènements spéciaux de la carte


	virtual CChamp*		FieldDescrToChamp(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual CMapping*	MakeCopieInternal() const;

};

#endif //_MAPPING_INTERCODE_H
