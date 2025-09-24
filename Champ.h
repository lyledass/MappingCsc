// Champ.h: interface for the CChamp class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_H
#define __CSCMAPPING__CHAMP_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Mapping\MappingSdk.h>
#include "IMappingIO.h"


typedef BOOL (*MAPVIRTUALFIELD_CALLBACK) (	PVOID	pParam,			///< Paramètre fourni en même temps que la définition de la fonction
											SC_TYPE	scType,
											WORD	fieldId,		///< Identifiant du champ	
											DWORD	instance,		///< Numéro d'instance du champ
											LONG*	pVal			///< Valeur que doit prendre le champ	
										  );


// Fonction générique permettant le parcours du mapping et l'exécution d'un processus 
// sur un ou plusieurs champs du mapping (champs simples)
typedef bool (*MapBrowseTreeGenericFunction) (	LPFIELD_DESCR_EX_V3	pDescriptor,	///< Descripteur du champ courant
												LPFIELD_INSTANCE	pInstance,		///< Instance du champs courant
												LPFIELD_POSITION*	pReadPosition,	///< Dernière information de position calculée pour un champ à position relative
												LPFIELD_POSITION	pActualPos,		///< Position courante du champ calculée
												void*				pArgsIn,		///< Arguments en entrée de la fonction
												void*				pArgsOut);		///< Arguments en sortie de la fonction

class  CChampReadParam {
public :
	MAPVIRTUALFIELD_CALLBACK	pVirtualCallback;		///< Fonction appelée pour l'initialisation des champs virtuels
	PVOID						pParam;					///< Paramètre passé à la fonction d'initialisation des champs virtuels
	SC_TYPE						cardType;				///< Le type de la carte
};

class CChamp
{
public:
	enum {
		LOOKFIELD_EXACT = 0,
		LOOKFIELD_DOWN,
		LOOKFIELD_UP,
	};
	
	CChamp(CChamp*	lpParent,	LPCFIELD_DESCR_EX_V3	lpcFieldDescrEx);
	virtual ~CChamp();

	virtual CChamp*	MakeCopie(CChamp*	lpParentCopie) const = 0;
	
	virtual void	Reset() = 0;
	virtual void	ResetFields(BYTE fieldIdType, int fieldInst) = 0;
	virtual bool	IsNull() const = 0;
	virtual bool	IsPositionFixe() const;

	virtual MAPFIELDS_IDNEEDED	GetNeededType();

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam) = 0;
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange) = 0;
	virtual void	WriteToSmartCardCommit() = 0;
	virtual bool	BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos) = 0;

	virtual CChamp*	GetChampById(WORD fieldId, int fieldInst = 0) const = 0;
	virtual void	SetModified(bool modified = true) = 0;
	virtual bool	IsModified() = 0;
	virtual void	SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance) = 0;
	virtual bool	IsModifiedGroup(WORD fieldIdMin, WORD fieldIdMax, WORD instance) = 0;

	virtual bool	UpdateFromModifiedCopy(const CChamp* lpCopie);

	virtual long	GetCodeImage() const;
	virtual bool	GetImage(CListExt<long>* pCodeImgList) const = 0;
	virtual bool	GetImage(CListExt<INT64>* pCodeImgList) const = 0;
	virtual void	SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam) = 0;
	virtual void	SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam) = 0;

	virtual void	SetToDefautBitmapVal();

	virtual LPTSTR	ToXml() const = 0;

	virtual const CChamp*	GetParent() const;

protected:
	virtual CChamp*	GetChampByUNId(DWORD fieldUNId, BYTE lookFlag = LOOKFIELD_DOWN, const CChamp* excluded = NULL) const = 0;
	virtual void	ParentNotifyModified() = 0;
	virtual size_t	GetFieldBitsLen(bool bOnlyPhysical) const = 0;

	FIELD_DESCR_EX_V3	m_descripteur;

	CChamp*				m_lpParent;

	LPTSTR GetFriendlyName(WORD fieldId) const;
	LPTSTR GetFriendlyType(WORD type, WORD subType) const;

private:

	friend class CChampSimple;
	friend class CChampEnsemble;
	friend class CChampBitmap;
	friend class CChampList;
	friend class CChampSwitch;
	friend class CChampNombre;
	friend class CChampDateCfvDelta;
};

#endif // __CSCMAPPING__CHAMP_H
