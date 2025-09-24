// ChampSimple.h: interface for the CChampSimple class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_SIMPLE_H
#define __CSCMAPPING__CHAMP_SIMPLE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Champ.h"

class CChampSimple : public CChamp {
public:
	virtual ~CChampSimple();

	virtual void	Reset();
	virtual void	ResetFields(BYTE fieldIdType, int fieldInst);
	virtual bool	IsNull() const;
	virtual bool	IsValNone() const;
	virtual void	SetValNone();
	virtual bool	IsValMax() const;
	virtual void	SetValMax();

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam);
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange);
	virtual void	WriteToSmartCardCommit();

	virtual BYTE	operator [] (int bpos) const;
	virtual void	SetBitVal(WORD bpos, BYTE val);

	virtual CChamp*	GetChampById(WORD fieldId, int fieldInst = 0) const;
	virtual void	SetModified(bool modified = true);
	virtual bool	IsModified();
	virtual void	SetModifiedGroup(bool modified, WORD fieldIdMin, WORD fieldIdMax, WORD instance);
	virtual bool	IsModifiedGroup(WORD fieldIdMin, WORD fieldIdMax, WORD instance);
	virtual bool	UpdateFromModifiedCopy(const CChamp*	lpCopie);
	virtual	void	SetVal(const CChampSimple* lpRefVal);


	virtual bool	GetImage(CListExt<long>* pCodeImgList) const;
	virtual bool	GetImage(CListExt<INT64>* pCodeImgList) const;
	virtual void	SetImage(const CListExt<long>* pCodeImgList, const CChampReadParam* pParam);
	virtual void	SetImage(const CListExt<INT64>* pCodeImgList, const CChampReadParam* pParam);
	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);

	virtual LPTSTR	ToXml() const;
	virtual	bool	ToXmlText(LPTSTR szTextVal, size_t textLen) const;
	virtual	bool	ToText(LPTSTR szTextVal, size_t textLen) const = 0;

	virtual bool	BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos);

protected:
	CChampSimple(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual CChamp*	MakeInstanceCopie(CChamp* lpParentCopie, CChampSimple* copie) const;

	virtual CChamp*	GetChampByUNId(DWORD fieldUNId, BYTE lookFlag = LOOKFIELD_DOWN, const CChamp* excluded = NULL) const;

	virtual void	ParentNotifyModified();

	long	GetInstLongValue() const;
	void	SetInstLongValue(DWORD64 val);
	long	GetInstMaxLongValue() const;

	DWORD64	GetInstLongValueEx() const;
	DWORD64	GetInstMaxLongValueEx() const;

	bool	SetToDefautVal();

	FIELD_INSTANCE		m_instance;			///< L'instance carte du champ
	LPFIELD_POSITION	m_lpReadPosition;	///< Position de lecture du champ (pour un champs à position non fixe)

	void SetInitialised(bool bInitialised);

	virtual size_t	GetFieldBitsLen(bool bOnlyPhysical) const;

private:

	friend class CChampEnsemble;
	friend class CChampBitmap;
	friend class CChampList;
	friend class CChampSwitch;

	bool	m_bInitialised; // Indique si le champ est initialisé (i.e. sa valeur est significative)
};

#endif // __CSCMAPPING__CHAMP_SIMPLE_H
