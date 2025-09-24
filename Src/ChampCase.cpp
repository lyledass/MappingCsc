// ChampCase.cpp: implementation of the CChampCase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ChampCase.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChampCase::CChampCase(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescr)
	: CChampEnsemble(lpParent, lpcFieldDescr, false)
{

}

CChampCase::~CChampCase() {
}

CChamp*	CChampCase::MakeCopie(CChamp* pParentCopie) const {
	CChampCase* copie;
	
	copie = new CChampCase(pParentCopie, &m_descripteur);

	return CChampEnsemble::MakeSetCopie(copie);
}
