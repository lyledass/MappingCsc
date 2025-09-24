// MapSet.h: interface for the CMapSet class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_SET_H
#define __CSCMAPPING__MAP_SET_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChampEnsemble.h"

class CMapSet
{
public:
	virtual ~CMapSet();

	virtual int		GetNumInstance() const;
	virtual void	Reset();
	virtual void	SetModified(bool bmodified = true);
	virtual bool	IsModified();

	virtual	bool	GetImage(CListExt<long>* pCodeImgList) const;

	virtual void	Update(const CMapSet* lpRefMapSet);
	virtual bool	IsNull();

	virtual void	SetToDefautBitmapVal();

	virtual void	SetMapRoot(CChampEnsemble* lpMapRoot);
	virtual CChampEnsemble*	GetMapRoot() const;

protected :
	CMapSet(CChampEnsemble*	lpMapRoot, int numInstance, int idFieldMin, int idFieldMax);

	virtual CChamp*		GetChampById(int fieldId) const;
	virtual CMapSet*	MakeCopie(CMapSet*	lpMapSetCopie) const;

	CChampEnsemble*		m_lpMapRoot;	// le mapping de la carte surlequel
										// se basent ces infos
	int					m_numInstance;	// indique le numéro de cet ensemble (si il est dupliqué)
										// (on peut avoir plusieurs profils dans la carte)
	int					m_setIdMin;		// identifiant min de l'ensemble (inclus)
	int					m_setIdMax;		// identifiant max de l'ensemble (non inclus)

	bool				m_deleteMapRoot;	// indique si l'on doit détruire le pointeur
											// sur la racine du mapping ou non à la destruction
											// de l'objet
};

#endif // __CSCMAPPING__MAP_SET_H
