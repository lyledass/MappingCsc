#ifndef __TOOLKIT__BSDIFF_H
#define __TOOLKIT__BSDIFF_H

#include <windows.h>

///////////////////////////////////////////////
//		These BSDiff functions calls directly the "BSDiff.exe" and/or "BSPatch.exe" files (needed)
///////////////////////////////////////////////

///////////////////////////////////////////////
// BSDiff patchs works like this :
// - create a patch (DeltaV1_V2) from original file (FileV1) + target file (FileV2)
// - apply a patch (DeltaV1_V2) to the original file (FileV1) to create the final file (FileV2Bis == FileV2)
///////////////////////////////////////////////

// Ascii version
bool CreateBSDiffPatchA					(	LPCSTR szOriginalFilePath,		LPCSTR szLastVersionFilePath,	LPCSTR szDeltaFilePath		);
bool PatchAFileWithBSDiffDeltaA			(	LPCSTR szOriginalFilePath,		LPCSTR szDeltaFilePath,			LPCSTR szResultFilePath		);

// Unicode version
bool CreateBSDiffPatchW					(	LPCWSTR	szOriginalFilePath,		LPCWSTR szLastVersionFilePath,	LPCWSTR szDeltaFilePath		);
bool PatchAFileWithBSDiffDeltaW			(	LPCWSTR	szOriginalFilePath,		LPCWSTR szDeltaFilePath,		LPCWSTR szResultFilePath	);


#ifdef _UNICODE
	#define CreateBSDiffPatch					CreateBSDiffPatchW
	#define PatchAFileWithBSDiffDelta			PatchAFileWithBSDiffDeltaW
#else
	#define CreateBSDiffPatch					CreateBSDiffPatchA
	#define PatchAFileWithBSDiffDelta			PatchAFileWithBSDiffDeltaA
#endif

#endif // __TOOLKIT__BSDIFF_H