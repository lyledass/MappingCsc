#ifndef __TOOLKIT__FILEINFO_H
#define __TOOLKIT__FILEINFO_H

#include "Dependency.h"

void TraceDllInfos(
				   LPCTSTR 			szDeviceType,		// string indicating the device type (for logging)
				   LPCTSTR 			szFileName,			// DLL file name to trace informations
				   TVersionStruct	&fileVersion,		// file version (format = x.x.x.x)
				   bool				&bFileExists		// return false if the file does not exist
				   );

#endif	// __TOOLKIT__FILEINFO_H