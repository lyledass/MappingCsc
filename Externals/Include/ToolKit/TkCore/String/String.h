#ifndef __TOOLKIT__STRING_H
#define __TOOLKIT__STRING_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <OleAuto.h>

#define sizeInTChar(szBuf)			(sizeof(szBuf) / sizeof(szBuf[0]))

#if (_MSC_VER < 1400)

// Version inférieure au Visual Studio 2005
#define _TRUNCATE				-1

#define _stscanf_s								_stscanf
#define _tcscpy_s(sz1, len, sz2)				_tcsncpy(sz1, sz2, len)
#define strcpy_s(sz1, len, sz2)					strncpy(sz1, sz2, len)
#define _tcsncpy_s(sz1, len, sz2, ignore)		_tcsncpy(sz1, sz2, len)
#define strtok_s(szText, szDelimiter, context)	strtok(szText, szDelimiter)
#define _vsntprintf_s(buffer, sizeOfBuffer, count, format, argptr)		_vsntprintf(buffer, sizeOfBuffer, format, argptr)

inline int __cdecl _sntprintf_s(LPTSTR szDest, size_t destSize, size_t ignore, LPCTSTR szFormat, ...) { 
	va_list args;
	va_start(args, szFormat);
	
	return _vsntprintf(szDest, destSize, szFormat, args);
};


#endif	// _MSC_VER < 1400


void	strTrimLeft(LPSTR lpszChaine, LPCSTR szComp);
void	strTrimRight(LPSTR lpszChaine, LPCSTR szComp);
long	strReplace (LPSTR lpszChaine, size_t sizeMaxChaine, LPCSTR szAncien, LPCSTR szNouveau);

LPWSTR	strdupwcs(LPCSTR szSrc);
int		vsprintf_alloc(LPSTR* pszDest, LPCSTR szFormat, va_list argptr);
int		sprintf_alloc(LPSTR* pszDest, LPCSTR szFormat, ...);

void	wcsTrimLeft(LPWSTR lpszChaine, LPCWSTR szComp);
void	wcsTrimRight(LPWSTR lpszChaine, LPCWSTR szComp);
long	wcsReplace (LPWSTR lpszChaine, size_t sizeMaxChaine, LPCWSTR szAncien, LPCWSTR szNouveau);

int		wcsFind(PWSTR lpszChaine, LPCWSTR szComp);

LPWSTR  wcsRemove(LPCWSTR lpszChain, LPCWSTR szComp);

LPSTR	wcsdupmbs(LPCWSTR szwSrc);
int		vswprintf_alloc(LPWSTR* pszDest, LPCWSTR szFormat, va_list argptr);
int		swprintf_alloc(LPWSTR* pszDest, LPCWSTR szFormat, ...);

void	strFree(LPSTR* lpszChaine) ;
void	wcsFree(LPWSTR* lpszChaine) ;

#ifdef _UNICODE
	#define _tcsTrimLeft		wcsTrimLeft
	#define _tcsTrimRight		wcsTrimRight
	#define _tcsReplace			wcsReplace

	#define mbstotcs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	mbstowcs_s(NULL, szDest, iTailleMaxDest, szSource, iTailleSource)
	#define tcstombs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	wcstombs_s(NULL, szDest, iTailleMaxDest, szSource, iTailleSource)
	#define wcstotcs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	wcsncpy_s(szDest, iTailleMaxDest, szSource, iTailleSource)
	#define tcstowcs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	wcsncpy_s(szDest, iTailleMaxDest, szSource, iTailleSource)

	#define vstprintf_alloc		vswprintf_alloc
	#define stprintf_alloc		swprintf_alloc
	#define _tcsFree			wcsFree

	#define tcsdupwcs			_wcsdup
	#define wcsduptcs			_wcsdup
	#define tcsdupmbs			wcsdupmbs
	#define mbsduptcs			strdupwcs
#else
	#define _tcsTrimLeft		strTrimLeft
	#define _tcsTrimRight		strTrimRight
	#define _tcsReplace			strReplace

	#define mbstotcs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	strncpy_s(szDest, iTailleMaxDest, szSource, iTailleSource)
	#define tcstombs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	strncpy_s(szDest, iTailleMaxDest, szSource, iTailleSource)
	#define wcstotcs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	wcstombs_s(NULL, szDest, iTailleMaxDest, szSource, iTailleSource)
	#define tcstowcs_s(szDest, iTailleMaxDest, szSource, iTailleSource)	mbstowcs_s(NULL, szDest, iTailleMaxDest, szSource, iTailleSource)

	#define vstprintf_alloc		vsprintf_alloc
	#define stprintf_alloc		sprintf_alloc
	#define _tcsFree			strFree

	#define tcsdupwcs			strdupwcs
	#define wcsduptcs			wcsdupmbs
	#define tcsdupmbs			_strdup
	#define mbsduptcs			_strdup
#endif

int		_tcsFormatPositional(LPTSTR szDest, size_t destChLen, LPCTSTR szFormat, ...);
long	_tcsToSignedLong(LPCTSTR szLong);

//////////////////////////////////////////////////////////////////////////////
///\brief Concatène 2 chaînes de caractère dans une seule chaîne.
///
///\author E. BEUQUE (07/04/2010)
///
///\param[in] szString1 Première chaîne...
///\param[in] ... Liste de chaînes dont le dernier element doit être NULL
///
///\return Renvoie une nouvelle chaîne alloué contenant la concatenation des chaînes.
/// Doit être désalloué lorsque qu'elle n'est plus utile avec free().
///
LPTSTR
tkc_strconcat(LPCTSTR szString1, ...);

//////////////////////////////////////////////////////////////////////////////
///\brief Copie la chaîne en paramètre.
///
///\author E. BEUQUE (07/04/2010)
///
///\param[in] szSrc Chaîne à copier.
///
///\return Renvoie une nouvelle chaîne alloué contenant la copie de la chaîne initiale.
/// Doit être désalloué lorsque qu'elle n'est plus utile avec free().
///
LPTSTR
tkc_strdup(LPCTSTR szSrc);


//////////////////////////////////////////////////////////////////////////////
///\brief Ecrit la chaîne formatée dans un buffer.
///
///\author E. BEUQUE (07/04/2010)
///
///\param[in] szFormat Format de la chaîne de caractère.
///\param[in] ... Liste des paramètres de la chaînes.
///
///\return Renvoie une nouvelle chaîne alloué contenant la chaîne formatée.
/// Doit être désalloué lorsque qu'elle n'est plus utile avec free().
///
LPTSTR
tkc_strdup_printf(LPCTSTR szFormat, ...);

//////////////////////////////////////////////////////////////////////////////
///\brief Ecrit la chaîne formatée dans un buffer.
///
///\author E. BEUQUE (07/04/2010)
///
///\param[in] szFormat Format de la chaîne de caractère.
///\param[in] args Liste des paramètres de la chaînes.
///
///\return Renvoie une nouvelle chaîne alloué contenant la chaîne formatée.
/// Doit être désalloué lorsque qu'elle n'est plus utile avec free().
///
LPTSTR
tkc_strdup_vprintf(LPCTSTR szFormat, va_list args);

//////////////////////////////////////////////////////////////////////////////
///\brief Dump un buffer d'octect en une chaîne de caractère de representation en hexadécimal séparé par szSep.
///
///\author E. BEUQUE (07/04/2010)
///
///\param[in] buffer Buffer a afficher.
///\param[in] len Taille du buffer.
///\param[in] szSep Chaîne de séparation entre chaque donnée (NULL accepté = "").
///
///\return Renvoie une nouvelle chaîne alloué contenant la chaîne formatée.
/// Doit être désalloué lorsque qu'elle n'est plus utile avec free().
///

LPTSTR tkc_get_hexdump(const byte* buffer, size_t len, LPCTSTR szSep = _T(" "));

#endif // __TOOLKIT__STRING_H
