#ifndef __TKCORE__OLECOM__ERG__GUA__GUA_H
#define __TKCORE__OLECOM__ERG__GUA__GUA_H

#if _MSC_VER > 1000
#pragma once
#endif

#include "ga.h"

typedef struct _GUA {
	_clsGA*		pGa;		
} TGUA;

BOOL GUA_Init(TGUA* pGua);
VOID GUA_Dispose(TGUA* pGua);

BOOL GUA_GetOdbcConnectString(TGUA* pGua, LPCTSTR szModule, LPTSTR szConnectString, size_t connectChLen);

#endif // __TKCORE__OLECOM__ERG__GUA__GUA_H