// ChampUnion.h: interface for the CChampUnion class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_UNION_H
#define __CSCMAPPING__CHAMP_UNION_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampEnsemble.h"


class CChampUnion : public CChampEnsemble {
public:
	CChampUnion(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescr);
	virtual ~CChampUnion();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam);
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange);

	//virtual LPTSTR	ToXml() const;

protected:

};

#endif // __CSCMAPPING__CHAMP_UNION_H
