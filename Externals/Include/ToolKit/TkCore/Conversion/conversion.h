#ifndef __CONVERSION_H
#define __CONVERSION_H

#include <Math.h>
#include <ctype.h>
#include <windows.h>
#include "../DateTime/DateTime.h"

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define _MAX_BUFFER				256

char*		_ito36_s (__int64 nDecValue, char *szResult, unsigned long tailleBuffer,unsigned int nSize);
int			_36toi_s (const char* sz36Value, unsigned int nSize);

int			ConvertCharToByte (CHAR* chaine, BYTE* tabByte, long tailleTableau);
int			ConvertCharToByte (LPCSTR chaine, BYTE* tabByte, long tailleTableau);
int			ConvertCharToByte (WCHAR* chaine, BYTE* tabByte, long tailleTableau);
int			ConvertCharToByte (LPCWSTR chaine, BYTE* tabByte, long tailleTableau);

LPSTR		ConvertByteArrayToHexStringA (const BYTE* tabByte, int tabSize);
LPWSTR		ConvertByteArrayToHexStringW (const BYTE* tabByte, int tabSize);

int			_16toi_s (const char* szHexValue,		unsigned int nSize);
int			_w16toi_s (const wchar_t* szHexValue,	unsigned int nSize);

char*		_ito16_s (const int& val, char* szResult,		unsigned long tailleBuffer,		unsigned int nSize);
wchar_t*	_itow16_s (const int& val, wchar_t* szResult,	unsigned long tailleBuffer,		unsigned int nSize);

long		_DateToDateC (const SYSTEMTIME* pVal);
bool		_DateCToDate(long lValDateC, SYSTEMTIME* pVal);

long		_HeureToLong(const SYSTEMTIME* pVal);
bool		_LongToHeure(long lValHeure, SYSTEMTIME* pVal);

bool		_LongToMinute(long lValHeure, SYSTEMTIME* pVal);

bool		_DateToHegire(const SYSTEMTIME* pDate, THEGIRE_DATE * pHegire, THEGIRE_TIME * pTime = NULL);
bool		_HegireToDate(const THEGIRE_DATE* pHegire, const THEGIRE_TIME* pTime, SYSTEMTIME* pDate);
bool		_HegireToDate(const THEGIRE_DATE* pHegire, SYSTEMTIME* pDate);

// Les fonctions suivantes retourne 0 si réussi, autre chose sinon
int 		ConvertDecToHexaA( char* szResultat, size_t iTailleBufferResultat, const char* szValeur );
int			ConvertHexaToDecA( char* szResultat, size_t iTailleBufferResultat, const char* szValeur );

int			ConvertDecToHexaW( wchar_t* szResultat, size_t iTailleBufferResultat, const wchar_t* szValeur );
int			ConvertHexaToDecW( wchar_t* szResultat, size_t iTailleBufferResultat, const wchar_t* szValeur );

#endif