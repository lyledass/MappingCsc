// LngFile.cpp: implementation of a class which handle the messages's file.
//
//////////////////////////////////////////////////////////////////////

#ifndef __LNG__LNGFILE_H
#define __LNG__LNGFILE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <tchar.h>

// Fonction de Callback
typedef void (*LNGHOOKPROC) (int iMsg, LPTSTR szText, size_t msgCharLen);

// Initialisation des langues par lecture du fichier + enregistrement d'une fonction de Callback (optionnel)
// => pour compatibilité
void		LngInit(LPCTSTR szFilename, LNGHOOKPROC pHookProc = NULL);
// Initialisation des structures pour l'enregistrement ultérieures de langues (via la fonction "LngRegisterLanguage")
// + enregistrement d'une fonction de Callback (optionnel)
void		LngInit2(LNGHOOKPROC pHookProc = NULL);
// Enregistrement des langues (iLngCode >= 0)
// Surcharge d'une langue interdite (tous les iLngCode sont uniques)
bool		LngRegisterLanguage(const int& iLngCode, LPCTSTR szLngDigram, LPCTSTR szFileName);
// Désallocation des structures de stockage
void		LngFree();

// Choix du language affiché
int			LngGetCurrentLanguage();
void		LngSetCurrentLanguage(int lng);

// Fonctions permettant de lire les messages contenus dans le fichier LNG
int			LngGetMsg(const int& iMsg, LPTSTR szMsg, const size_t& msgCharLen, LPCTSTR szDefMsg = NULL);
bool		LngGetDlgText(const int& idDlg, const int& idCtrl, LPTSTR szMsg, const size_t& msgCharLen);

#endif /* __LNG__LNGFILE_H */