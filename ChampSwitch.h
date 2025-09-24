// ChampSwitch.h: interface for the CChampSwitch class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_SWITCH_H
#define __CSCMAPPING__CHAMP_SWITCH_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampEnsemble.h"
// #include "ChampCase.h"

// Permet de gérer dynamiquement la définition du mapping
// le data du descripteur contient l'identifiant du champ 
// sur lequel repose la condition

class CChampSwitch : public CChampEnsemble {
public:
	CChampSwitch(CChamp* lpParent, LPCFIELD_DESCR_EX_V3	lpcFieldDescr);
	virtual ~CChampSwitch();

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const;

	virtual TCRD_RESULT	ReadFromSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION		lpPos, 
											const CChampReadParam*	pParam);
	virtual TCRD_RESULT	WriteToSmartCard(	IMappingIO *pMappingIO,	TUserData userData, 
											LPFIELD_POSITION			lpPos,
											bool&						bPosRelativeChange);

	virtual CChamp*	GetChampById(WORD fieldId, int fieldInst = 0) const;

	virtual LPTSTR	ToXml() const;

	virtual bool	BrowseTreeGeneric(	MapBrowseTreeGenericFunction	pGenericFunction,
										void*							pArgsIn,
										void*							pArgsOut,
										LPFIELD_POSITION				pActualPos);

protected:

	bool					TestChildField(CChamp* pChildField, bool bAllowFieldCase, bool* pbFieldCase) const;

	void					InitConditionField();
	const CChampSimple*		GetConditionField() const;

	virtual size_t			GetFieldBitsLen(bool bOnlyPhysical) const;

	const CChampSimple*		m_pConditionField;		///< Pointeur d'instance du champ à tester
};

#endif // __CSCMAPPING__CHAMP_SWITCH_H
