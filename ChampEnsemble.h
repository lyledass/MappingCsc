// ChampEnsemble.h: interface for the CChampEnsemble class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_ENSEMBLE_H
#define __CSCMAPPING__CHAMP_ENSEMBLE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Champ.h"
#include "ChampNombre.h"
#include "ChampBooleen.h"
#include "ChampDate.h"
#include "ChampPlanningHebdo.h"
#include "ChampTranscarte.h"


class CChampEnsemble : public CChamp  
{
public:
	CChampEnsemble(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx, bool bAtomic);
	virtual ~CChampEnsemble();


	virtual CChamp*	MakeCopie(CChamp*	lpParentCopie) const;

	virtual void	Reset();
	virtual void	ResetFields(BYTE fieldIdType, int fieldInst);
	virtual bool	IsNull() const;

	virtual void	SetModified(bool modified = true);
	virtual bool	IsModified();
	virtual void	SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance);
	virtual bool	IsModifiedGroup(WORD fieldIdMin, WORD fieldIdMax, WORD instance);
	virtual CChamp*	GetChampById(WORD fieldId, int fieldInst = 0) const;

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam);
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange);
	virtual void	WriteToSmartCardCommit();

	virtual bool	BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos);

	virtual bool	UpdateFromModifiedCopy(const CChamp*	lpCopie);

	virtual bool	GetImage(CListExt<long>* pCodeImgList) const;
	virtual bool	GetImage(CListExt<INT64>* pCodeImgList) const;
	virtual void	SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam);
	virtual void	SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam);

	virtual void	SetChamp(int index, CChamp* champ);

	virtual void	SetToDefautBitmapVal();

	virtual LPTSTR	ToXml() const;

protected:
	CChampEnsemble*	MakeSetCopie(CChampEnsemble* copie) const;

	virtual CChamp*	GetChampByUNId(DWORD fieldUNId, BYTE lookFlag = LOOKFIELD_DOWN, const CChamp* excluded = NULL) const;
	virtual void	ParentNotifyModified();

	TCRD_RESULT		ReadAtomicField(	IMappingIO *pMappingIO,
										TUserData	userData,
										const FIELD_POSITION*	lpPos, 
										const CChampReadParam*	pParam);
	TCRD_RESULT		WriteAtomicField(	IMappingIO *pMappingIO,
										TUserData	userData,
										const FIELD_POSITION*	lpPos);

	virtual CChamp*	GetChamp(int index) const;
	virtual size_t	GetFieldBitsLen(bool bOnlyPhysical) const;
	
	CChamp**	m_champs;		///< champs applicatifs formant l'ensemble
	BOOL		m_bModified;	///< indique si au moins 1 des champs de l'ensemble a été modifié
	bool		m_bAtomic;		///< Reading and Writing are atomic operations

private:
	friend class CChampBitmap;
};

#endif // __CSCMAPPING__CHAMP_ENSEMBLE_H
