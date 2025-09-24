// ChampList.h: interface for the CChampList class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_LIST_H
#define __CSCMAPPING__CHAMP_LIST_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampEnsemble.h"

class CChampList : public CChampEnsemble  
{
public:
	CChampList(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescrEx);
	virtual ~CChampList();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;
	virtual bool	IsNull() const;

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam);
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange);
	virtual void	WriteToSmartCardCommit();

	virtual CChamp*	GetChampById(WORD fieldId, int fieldInst = 0) const;

	virtual void	SetModified(bool modified = true);
	virtual bool	IsModified();
	virtual void	SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance);
	virtual bool	IsModifiedGroup(WORD fieldIdMin, WORD fieldIdMax, WORD instance);
	virtual bool	UpdateFromModifiedCopy(const CChamp* lpCopie);

	virtual bool	GetImage(CListExt<long>* pCodeImgList) const;
	virtual bool	GetImage(CListExt<INT64>* pCodeImgList) const;
	virtual void	SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam);
	virtual void	SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam);

	virtual LPTSTR	ToXml() const;

protected:
	CChampList(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcSetDescrEx, LPCFIELD_DESCR_EX_V3 lpcFieldElmtCountDescrEx);

	virtual void	ComputeElementCount();

	virtual CChamp*	GetChampByUNId(DWORD fieldUNId, BYTE lookFlag = LOOKFIELD_DOWN, const CChamp* excluded = NULL) const;

	CChampNombre*	m_lpFieldElmtCount;
};

#endif // __CSCMAPPING__CHAMP_LIST_H
