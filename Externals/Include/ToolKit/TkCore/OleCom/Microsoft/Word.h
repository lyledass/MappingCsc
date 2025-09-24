#ifndef __TKCORE__OLECOM__MICROSOFT__WORD_H
#define __TKCORE__OLECOM__MICROSOFT__WORD_H

#pragma once

#include <windows.h>

DECLARE_HANDLE(HMSWORD_APPLICATION);
DECLARE_HANDLE(HMSWORD_DOCUMENT);

typedef struct _TWordMergeField {
	LPCTSTR		szDocFieldName;		///< Field name to merge in the Word document
	LPCTSTR		szValue;			///< Text value of the field
} TWordMergeField;

// Ms Word Application handlers
BOOL MsWord_Open(HMSWORD_APPLICATION*	phWordAppli, 
				 BOOL					bShow);

BOOL MsWord_ShowWindow(HMSWORD_APPLICATION	hWordAppli,
					   BOOL					bShow);

BOOL MsWord_Quit(	HMSWORD_APPLICATION hWordAppli,
					BOOL				bQuitWord);

// Document handlers
BOOL MsWordDocument_Open(	HMSWORD_APPLICATION		hWordAppli, 
							LPCTSTR					szFilename, 
							BOOL					bShow,
							HMSWORD_DOCUMENT*		phDocument);

BOOL MsWordDocument_Create(	HMSWORD_APPLICATION		hWordAppli,
							LPCTSTR					szTemplateFilename,
							BOOL					bShow,
							HMSWORD_DOCUMENT*		phDocument);

BOOL MsWordDocument_Close(	HMSWORD_DOCUMENT		hDocument, 
							BOOL					bSave,
							BOOL					bCloseWindow);


BOOL MsWordDocument_SaveAs(	HMSWORD_DOCUMENT		hDocument,
							LPCTSTR					szFilename);

//Modif VPO 10/03/2009 Ajout fonction pour sauvegarde dans un autre format que le .DOC
BOOL MsWordDocument_SaveFormatAs(	HMSWORD_DOCUMENT		hDocument,
									LPCTSTR					szFilename,
									long					iFileFormat);
//End Modif

BOOL MsWordDocument_Print(	HMSWORD_DOCUMENT		hDocument, 
							long					copyCount);

BOOL MsWordDocument_MergeFields(	HMSWORD_DOCUMENT		hDocument,
									const TWordMergeField*	pMergeFields,
									long					mergeFieldCount);

//Modif VPO 12/03/2009 Ajout fonction pour sauvegarde dans un autre format que le .DOC
BOOL GetDocProperties(char *filename, char* prop);

BOOL GetBuiltInProperties(IPropertySetStorage *pPropSetStg, char* valeur);
//End Modif

#endif // __TKCORE__OLECOM__MICROSOFT__WORD_H