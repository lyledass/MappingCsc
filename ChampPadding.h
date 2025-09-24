// ChampPadding.h: interface for the CChampPadding class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_PADDING_H
#define __CSCMAPPING__CHAMP_PADDING_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampPadding : public CChampSimple
{
public:
	CChampPadding(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx);
	virtual ~CChampPadding();

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam);
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange);

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const ;
	virtual	bool	ToText(LPTSTR szTextVal, size_t textLen) const;

	virtual bool	BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos);

};

#endif // __CSCMAPPING__CHAMP_PADDING_H
