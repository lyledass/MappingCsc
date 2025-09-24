#ifndef __TOOLKIT__RDIFF_H
#define __TOOLKIT__RDIFF_H

#include <windows.h>

///////////////////////////////////////////////
//		These RDiff functions calls directly the "RDiff.exe" file (needed)
///////////////////////////////////////////////

///////////////////////////////////////////////
// RDiff patchs works like this :
// - create a signature file (SigFile) with original file (FileV1)
// - create a patch (DeltaV1_V2) from signature file (SigFile) + target file (FileV2)
// - apply a patch (DeltaV1_V2) to the original file (FileV1) to create the final file (FileV2Bis == FileV2) 
///////////////////////////////////////////////

///////////////////////////////////////////////
// The "CreateRDiffPatch" functions calls "CreateRDiffSignatureFile + CreateRDiffPatchFromSignatureFile" using a temporary file automatically deleted after operations
///////////////////////////////////////////////

// Ascii version
bool CreateRDiffSignatureFileA			(	LPCSTR szOriginalFilePath,		LPCSTR szSignatureFilePath		);
bool CreateRDiffPatchFromSignatureFileA	(	LPCSTR szSignatureFilePath,		LPCSTR szLastVersionFilePath,	LPCSTR szDeltaFilePath		);
bool CreateRDiffPatchA					(	LPCSTR szOriginalFilePath,		LPCSTR szLastVersionFilePath,	LPCSTR szDeltaFilePath		);
bool PatchAFileWithRDiffDeltaA			(	LPCSTR szOriginalFilePath,		LPCSTR szDeltaFilePath,			LPCSTR szResultFilePath		);

// Unicode version
bool CreateRDiffSignatureFileW			(	LPCWSTR	szOriginalFilePath,		LPCWSTR	szSignatureFilePath		);
bool CreateRDiffPatchFromSignatureFileW	(	LPCWSTR	szSignatureFilePath,	LPCWSTR szLastVersionFilePath,	LPCWSTR szDeltaFilePath		);
bool CreateRDiffPatchW					(	LPCWSTR	szOriginalFilePath,		LPCWSTR szLastVersionFilePath,	LPCWSTR szDeltaFilePath		);
bool PatchAFileWithRDiffDeltaW			(	LPCWSTR	szOriginalFilePath,		LPCWSTR szDeltaFilePath,		LPCWSTR szResultFilePath	);


#ifdef _UNICODE
	#define CreateRDiffSignatureFile			CreateRDiffSignatureFileW
	#define CreateRDiffPatchFromSignatureFile	CreateRDiffPatchFromSignatureFileW
	#define CreateRDiffPatch					CreateRDiffPatchW
	#define PatchAFileWithRDiffDelta			PatchAFileWithRDiffDeltaW
#else
	#define CreateRDiffSignatureFile			CreateRDiffSignatureFileA
	#define CreateRDiffPatchFromSignatureFile	CreateRDiffPatchFromSignatureFileA
	#define CreateRDiffPatch					CreateRDiffPatchA
	#define PatchAFileWithRDiffDelta			PatchAFileWithRDiffDeltaA
#endif

#endif // __TOOLKIT__RDIFF_H