// ChampBitmap.h: interface for the CChampBitmap class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_BITMAP_H
#define __CSCMAPPING__CHAMP_BITMAP_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampEnsemble.h"

class CChampBitmap : public CChampEnsemble  
{
public:
	CChampBitmap(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescrEx);
	virtual ~CChampBitmap();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;

	virtual void	Reset();
	virtual void	ResetFields(BYTE fieldIdType, int fieldInst);
	virtual bool	IsNull() const;
	virtual void	SetValNone();

	virtual void	SetModified(bool modified = true);
	virtual bool	IsModified();
	virtual void	SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance);
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

	virtual bool	UpdateFromModifiedCopy(const CChamp* lpCopie);

	virtual bool	GetImage(CListExt<long>* pCodeImgList) const;
	virtual bool	GetImage(CListExt<INT64>* pCodeImgList) const;
	virtual void	SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam);
	virtual void	SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam);

	virtual void	SetChamp(int index, CChamp* champ);

	virtual void	SetToDefautBitmapVal();

	virtual void	SetAuthorizeAutoCompute(bool bAuthorizeAutoCompute);

	virtual LPTSTR	ToXml() const;

protected:
	CChampBitmap(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcSetDescrEx, LPCFIELD_DESCR_EX_V3 lpcFieldBitmapDescrEx);

	virtual bool	ComputeBitmapVal();

	virtual CChamp*	GetChampByUNId(DWORD fieldUNId, BYTE lookFlag = LOOKFIELD_DOWN, const CChamp* excluded = NULL) const;

	virtual size_t	GetFieldBitsLen(bool bOnlyPhysical) const;

	bool			m_bAuthorizeAutoCompute;

	CChampNombre*	m_bitmap;
};

#endif // __CSCMAPPING__CHAMP_BITMAP_H
