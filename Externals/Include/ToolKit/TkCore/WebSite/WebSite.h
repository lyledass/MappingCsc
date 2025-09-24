#ifndef __INCLUDE_TKCORE_WEBSITE_H
#define __INCLUDE_TKCORE_WEBSITE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

// Vérifie qu'un site web est atteignable depuis la machine
bool CheckWebSiteReachable(LPCTSTR szWebSiteUrl);


#endif // __INCLUDE_TKCORE_WEBSITE_H