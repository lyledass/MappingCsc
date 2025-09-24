#ifndef __TKCORE__OLECOM__STRING_H
#define __TKCORE__OLECOM__STRING_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <OleAuto.h>

BSTR	SysAllocStringW(LPCWSTR	szText);
BSTR	SysAllocStringA(LPCSTR	szText);

int		SysCmpStringW(BSTR bszString1, LPCWSTR	wszString2);
int		SysCmpStringA(BSTR bszString1, LPCSTR	szString2);

#ifdef _UNICODE
	#define SysAllocStringT		SysAllocStringW
	#define SysCmpString		SysCmpStringW
#else
	#define SysAllocStringT		SysAllocStringA
	#define SysCmpString		SysCmpStringA
#endif

#endif // __TKCORE__OLECOM__STRING_H
