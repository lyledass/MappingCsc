// MapFile.h: interface for the CMapFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __CSCMAPPING__MAP_FILE_H
#define __CSCMAPPING__MAP_FILE_H

//#if _MSC_VER > 1000
#pragma once
//#endif // _MSC_VER > 1000

#include "Champ.h"

class CMapFile {
public:
	CMapFile();
	virtual ~CMapFile();

	BOOL	Open(LPCTSTR lpszFileName);
	void	Close();

	BOOL	ReadFileHeader(LPMAPFILE_HEADER lpMapFileHeader);
	BOOL	ReadFieldDescr(LPFIELD_DESCR_EX_V3	lpFieldDescrEx);

protected :
	BOOL	ReadFieldDescrHeader(LPFIELD_DESCR_EX_V3 lpFieldDescrEx);

	WORD	m_mapVersion;		///< Version du fichier mapping

private :
	virtual UINT	Read(void* lpBuf, UINT nCount);
	virtual void	Write(const void* lpBuf, UINT nCount);
	void			SeekToBegin();
	
	HANDLE	m_hFile;

};


#endif // __CSCMAPPING__MAP_FILE_H
