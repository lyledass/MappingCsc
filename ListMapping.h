// ListMapping.h: interface for the CListMapping class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__LIST_MAPPING_H
#define __CSCMAPPING__LIST_MAPPING_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Mapping.h"

class CListMapping
{
public:
	CListMapping();
	virtual ~CListMapping();

	void				SetAt(unsigned long ulKey, CMapping* newValue);
	CMapping*			GetAt(unsigned long ulKey) const;

	bool				IsEmpty() const;

	virtual CMapping*	GetLastVersion() const;

protected :
	CListExt<CMapping*>		m_liste;
};

#endif // __CSCMAPPING__LIST_MAPPING_H
