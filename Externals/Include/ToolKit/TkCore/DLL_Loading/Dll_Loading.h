#ifndef __DLL_LOADING_H
#define __DLL_LOADING_H

#include <windows.h>

HMODULE WINAPI TkLoadLibrary(__in  LPCTSTR lpFileName, bool bSearchDebug = false);

#ifdef _DEBUG
	#define LOAD_LIBRARY(filename) TkLoadLibrary(filename,true)
#else
	#define LOAD_LIBRARY(filename) TkLoadLibrary(filename)
#endif

#endif /* __DIBMP_H */