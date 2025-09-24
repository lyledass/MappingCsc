// Mapping.h: interface for the CMapping class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __CSCMAPPING__MAPPING_H
#define __CSCMAPPING__MAPPING_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapFile.h"
#include "ChampEnsemble.h"

#include "MapCarte.h"
#include "MapAgent.h"
#include "MapPorteur.h"
#include "MapVixAgentData.h"
#include "MapListeProfils.h"
#include "MapListeBestContract.h"
#include "MapListeContract.h"
#include "MapListeEvent.h"
#include "MapListeSpecialEvent.h"
#include "MapListeBestSpecialEvent.h"
#include "IMappingIO.h"
#include "MapMk3.h"
#include "MapListeShiftEvent.h"
#include "MapDispatch.h"

class CMapping
{
public:
	CMapping(LPCTSTR szFilename, WORD version);
	CMapping(const CMapping& otherMapping);
	virtual ~CMapping();

	BOOL					ReadMapFile();
	CChampEnsemble *		GetMapRoot() 				const;
	WORD					GetVersion()				const;
	DWORD					GetDfvCardUNID				() const;
	TCHAR*					GetFileName					() const;
	CMapVixAgentData*		GetVixAgentData()			const;
	CMapMk3*				GetMk3()					const;

	// Atamelang operator card
	CMapDispatch*			GetDispatch() const;
	int						GetShiftEventCount() const;
	CMapShiftEvent*			GetShiftEvent(int i) const;

	virtual CMapping *		MakeCopie					() const;
	virtual BOOL			UpdateFromModifiedCopy		(const CMapping* copy);
	void					SetFieldsModified			(BOOL	modified = TRUE);
	void					InitConstValues				(bool bForceModified);
	BOOL					ResetConstValuesFromCopies	(const CMapping* lpInitialCopie, const CMapping* lpModifiedCopie);

	TCRD_RESULT				ReadFromSmartCard	(IMappingIO *pMappingIO, TUserData userData, const CChampReadParam * pParam); 
	TCRD_RESULT				WriteToSmartCard	(IMappingIO *pMappingIO, TUserData userData); 
	void	                WriteCommit();

	void	BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
								void*							pArgsIn,
								void*							pArgsOut);

	bool					GetImage					(CListExt<long> * pListeField);
	bool					GetImage					(CListExt<INT64> * pListeField);
	void					SetFieldValueByCodeImg		(const CListExt<long>& listeField, const CChampReadParam* pParam);
	void					SetFieldValueByCodeImg		(const CListExt<INT64>& listeField, const CChampReadParam* pParam);
	CChampSimple *			GetField					(WORD fieldId, int fieldInst) const;

    LPTSTR					ToXml(BOOL bWithHeader = TRUE) const;

protected:
	CChampEnsemble *	m_lpMapRoot;			//!< {en}The root of the mapping{/en} {fr}La racine du mapping{/fr}
	DWORD				m_dfvCardUNID;			//!< {en}Unique ID of the Validity-End-Date card's field (required for initializing fields CfvDelta){/en}
												//! {fr}Unid du champ DFV carte (nécessaire pour l'initialisation des champs CfvDelta){/fr}
	WORD				m_version;				//!< {en}Version number of the mapping{/en} {fr}Numéro de version du mapping{/fr}
	TCHAR *				m_szFilename;			//!< {en}Mapping's file name{/en} {fr}Nom du fichier mapping{/fr}

	CMapVixAgentData*			m_pVixAgentDataInfo;		// Les informations de l'agent Smith
	CMapMk3*					m_pMk3;						// Les informations carte Mk3
	CMapListeShiftEvent			m_eventShiftList;
	CMapDispatch*				m_pDispatch;
	virtual CChamp *	FieldDescrToChamp		(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual CChamp *	ParseBinaryMapFileDescr	(CMapFile& file, CChamp* lpParent, LPFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	BOOL				ReadBinaryMapFile		(CMapFile& file); // Parse the mapping's binary files
	virtual void		MakeCopie				(CMapping* pMapping) const;
	virtual CMapping *	MakeCopieInternal		() const = 0; // Method to subclass to have a generic MakeCopie method
	virtual	void		ParseEnd				() {};
	virtual void		FieldParseEnd			(CChamp* pField, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx) {};

private:
};

#endif // __CSCMAPPING__MAPPING_H
