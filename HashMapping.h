// HashMapping.h: interface for the CHashMapping class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__HASH_MAPPING_H
#define __CSCMAPPING__HASH_MAPPING_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ListMapping.h"

// FICHIER DE MAPPING
#define MAP_FILE_PATH		_T(".\\mapping\\")
// #define MAP_FILE_SEARCH	"*.map"				// fichier texte mapping
#define MAP_FILE_SEARCH		_T("*.bmf")			// fichier binaire mapping


class CHashMapping
{
public:
	CHashMapping();
	virtual ~CHashMapping();

	void SetAt(LPCTSTR key, unsigned long ulVersion, CMapping* newValue);
	CListMapping* GetAt(LPCTSTR key) const;

private:
	CListExt<LPTSTR>		m_listKey;
	CListExt<CListMapping*>	m_listMapping;
};

#endif // __CSCMAPPING__HASH_MAPPING_H
