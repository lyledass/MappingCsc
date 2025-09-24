// ChampNombre.h: interface for the CChampNombre class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__CHAMP_NOMBRE_H
#define __CSCMAPPING__CHAMP_NOMBRE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampSimple.h"

class CChampNombre : public CChampSimple  
{
public:
	CChampNombre(CChamp* lpParent, LPCFIELD_DESCR_EX_V3 lpcFieldDescrEx, bool bSigned);
	virtual ~CChampNombre();

	DWORD	GetVal() const;
	INT64	GetValEx() const;
	INT64	GetMaxVal() const;
	INT64	GetMinVal() const;
	void	operator += (INT64 val);
	void	operator -= (INT64 val);

	virtual bool	IsListElementManualCount() const;

	virtual CChamp*	MakeCopie(CChamp* lpParentCopie) const ;
	virtual void	SetVal(INT64 val);
	// Surcharge de SetValMax pour mettre la valeur max positive si le champ est signé
	virtual void	SetValMax();
	// SetValMin pour mettre la valeur minimum (éventuellement négative)
	virtual void	SetValMin();

	virtual bool	ToXmlText(LPTSTR szTextVal, size_t textLen) const;
	virtual bool	ToText(LPTSTR szTextVal, size_t textLen) const;

	virtual INT64	GetImageValue() const;
	virtual void	SetImageValue(INT64 lVal);

private:
	bool	m_bSigned; // Indique que le champ est signé
};

#endif // __CSCMAPPING__CHAMP_NOMBRE_H
