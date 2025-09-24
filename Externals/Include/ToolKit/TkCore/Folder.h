#ifndef __TOOLKIT__FOLDER_H
#define __TOOLKIT__FOLDER_H

#include <windows.h>
#include <tchar.h>

// Pour Windows 98 et précedent, la limite d'un chemin est 0xFF,
// et sous windows 2000, XP... 0x7FFF
// On coupe la poire en deux :
#define _MAX_FULLPATH		0x07FF

BOOL	Path_ExistsA(LPCSTR		szPath);
BOOL	Path_ExistsW(LPCWSTR	szPath);

LPSTR	Path_ConcatA(LPCSTR szPath1, LPCSTR szPath2);
LPCSTR	Path_ConcatA(LPSTR szDest, size_t destChCount, LPCSTR szPath1, LPCSTR szPath2);
LPWSTR	Path_ConcatW(LPCWSTR szPath1, LPCWSTR szPath2);
LPCWSTR	Path_ConcatW(LPWSTR szDest, size_t destChCount, LPCWSTR szPath1, LPCWSTR szPath2);

LPSTR	Path_MakeAbsoluteA(LPCSTR szRelativePath, BOOL bShortPathName);
LPWSTR	Path_MakeAbsoluteW(LPCWSTR szRelativePath, BOOL bShortPathName);

// Extract directory name from a path by looking for the last '/' or '\'
// If no '/' or '\' found, returns "."
// If szPath is NULL, returns NULL
LPSTR	Path_ExtractDirNameA(LPCSTR szPath);
LPWSTR	Path_ExtractDirNameW(LPCWSTR szPath);

BOOL	CreateFolderA(LPCSTR szPath);
BOOL	CreateFolderW(LPCWSTR szPath);

BOOL	DlgSelectFolderA(HWND hWnd, LPCSTR szTitle, LPSTR szPath, size_t pathCharLen);
BOOL	DlgSelectFolderW(HWND hWnd, LPCWSTR szTitle, LPWSTR szPath, size_t pathCharLen);

BOOL	DlgSelectFileOpenA(	HWND	hWnd,		
							LPCSTR	szTitle, LPCSTR	szExtFilter, 
							BOOL	bKeepCurDiretory,
							LPSTR	szFilePath,	size_t	pathCharLen);
BOOL	DlgSelectFileOpenW(	HWND	hWnd,		
							LPCWSTR	szTitle, LPCWSTR	szExtFilter, 
							BOOL	bKeepCurDiretory,
							LPWSTR	szFilePath,	size_t	pathCharLen);

BOOL	DeleteFilesA		(LPCSTR szDirectory, LPCSTR  szMasque, BOOL bNoCopySubDirectories = TRUE);
BOOL	DeleteFilesW		(LPCWSTR szDirectory, LPCWSTR  szMasque, BOOL bNoCopySubDirectories = TRUE);
BOOL	CopyFilesA			(LPCSTR szDirectorySource, LPCSTR szDirectoryDestination, LPCSTR szMask, BOOL bFailIfExistsFile = TRUE, BOOL bNoCopySubDirectories = TRUE);
BOOL	CopyFilesW			(LPCWSTR szDirectorySource, LPCWSTR szDirectoryDestination, LPCWSTR szMask, BOOL bFailIfExistsFile = TRUE, BOOL bNoCopySubDirectories = TRUE);


#ifdef _UNICODE
	#define Path_Exists			Path_ExistsW
	#define Path_Concat			Path_ConcatW
	#define	Path_MakeAbsolute	Path_MakeAbsoluteW
	#define Path_ExtractDirName	Path_ExtractDirNameW
	#define	CreateFolder		CreateFolderW
	#define DlgSelectFolder		DlgSelectFolderW
	#define DlgSelectFileOpen	DlgSelectFileOpenW
	#define DeleteFiles			DeleteFilesW
	#define CopyFiles			CopyFilesW

#else
	#define Path_Exists			Path_ExistsA
	#define Path_Concat			Path_ConcatA
	#define	Path_MakeAbsolute	Path_MakeAbsoluteA	
	#define Path_ExtractDirName	Path_ExtractDirNameA
	#define	CreateFolder		CreateFolderA
	#define DlgSelectFolder		DlgSelectFolderA
	#define DlgSelectFileOpen	DlgSelectFileOpenA
	#define DeleteFiles			DeleteFilesA
	#define CopyFiles			CopyFilesA

#endif

#endif // __TOOLKIT__FOLDER_H