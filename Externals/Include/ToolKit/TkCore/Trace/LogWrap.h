///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2005
//
// Fichier	: LOGWRAP.H
//
// Description	: Définition des fonctions de lien avec la dll de log
//
// Contenu	: /
//
// Remarque(s)	: /
//
// Auteur       : T. COTTIGNIES (08/11/2005)
//
// Modif(s)     : - 12/10/2006 (TCO) : Lecture des paramètres dans un fichier ini.
//
///////////////////////////////////////////////////////////////


// Options de compilation
// ----------------------
#if !defined(_LOG_WRAP_H_)
#define _LOG_WRAP_H_

#if _MSC_VER > 1000
	#pragma once
#endif

#include <windows.h>
#include <tchar.h>
#include "Log.h"

void LogWrapInit								(LPCTSTR szNomApplication, LPCTSTR szFichierIni, WORD wIdApplication, WORD wIdExploitantApplication, DWORD dwCodeSysteme);
void LogWrapDispose								();
void LogWrapPurge								();
void LogWrapEcrire								(BYTE byNiveau, BYTE iCategorie, INT32 iCode, LPCTSTR lpszFormat, va_list argptr);
void LogWrapEcrireError							(LPCTSTR lpszFormat, ...);
void LogWrapEcrireWarn							(LPCTSTR lpszFormat, ...);
void LogWrapEcrireInfo							(LPCTSTR lpszFormat, ...);
void LogWrapEcrireDebug							(LPCTSTR lpszFormat, ...);
void LogWrapEcrireHexDump						(LPCTSTR lpszMsg, const void* lpBuf, size_t bufLen);
bool LogWrapUpdateParameters					(BYTE iCategorie, DWORD  iTypeSortie, LPCTSTR szParamName, LPCTSTR szValue); // LOG_PARAM_SOCKET_HOSTNAME, LOG_PARAM_SOCKET_PORT, ...
bool LogWrapGetParameters						(BYTE iCategorie, DWORD  iTypeSortie, LPCTSTR szParamName, LPTSTR szValue, int iValueBufferLen); // LOG_PARAM_SOCKET_HOSTNAME, LOG_PARAM_SOCKET_PORT, ...
void LogWrapZipStart							(DWORD dwLogAgeInHours, DWORD dwZipSizeThreshold); 
void LogWrapZipStop								(); 
void LogWrapZipRegisterFolder					(LPCTSTR szFolder, LPCTSTR szZipName); 

/*
#define TRACE_ERROR							LogWrapEcrireError
#define TRACE_WARN							LogWrapEcrireWarn
#define TRACE_INFO							LogWrapEcrireInfo
#define TRACE_DEBUG							LogWrapEcrireDebug
#define TRACE_HEXDUMP						LogWrapEcrireHexDump
*/

void LogWrapEcrireEx					(BYTE byNiveau, BYTE iCategorie, INT32 iCode, LOG_ALARME_STATUT iStatutAlarme, LOG_ALARME_ETAT iEtatAlarme, LPCSTR szFile, long line, LPCSTR szFunction, LPCTSTR lpszFormat, ...);

// __FUNCSIG__ ou __FUNCTION__ ?
#define TRACE_ERROR(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_ERREUR,			0, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_WARN(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_AVERTISSEMENT,	0, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_INFO(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_INFORMATION,		0, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_DEBUG(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_DEBUG,			0, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
// #define TRACE_HEXDUMP(szFormat, ...)	LogWrapEcrireEx(LOG_NIVEAU_DEBUG,			0, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_HEXDUMP					LogWrapEcrireHexDump

#define TRACE_EX(iCategorie, byNiveau, szFormat, ...)					LogWrapEcrireEx(byNiveau, iCategorie, 0, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)

#define TRACE_ALARM(iCategorie, iCode, iStatutAlarme, iEtatAlarme)	LogWrapEcrireEx(LOG_NIVEAU_INFORMATION, iCategorie, iCode, iStatutAlarme, iEtatAlarme, __FILE__, __LINE__, __FUNCTION__, _T(""))

#define TRACE_REQ(szFormat, ...)								TRACE_EX(LOG_CATEGORIE_REQUEST, LOG_NIVEAU_INFORMATION, szFormat, __VA_ARGS__)

#define TRACE_TIME(x)						{ \
												DWORD	t2,	t1; \
												t1 = GetTickCount();	\
												x; \
												t2 = GetTickCount();	\
												TRACE_INFO(_T("TIME {") _T(#x) _T("} = %i ms"), t2 - t1); \
											}

#define TRACE_ERROR_DB(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_ERREUR,			LOG_CATEGORIE_DB, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_WARN_DB(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_AVERTISSEMENT,	LOG_CATEGORIE_DB, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_INFO_DB(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_INFORMATION,		LOG_CATEGORIE_DB, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)
#define TRACE_DEBUG_DB(szFormat, ...)		LogWrapEcrireEx(LOG_NIVEAU_DEBUG,			LOG_CATEGORIE_DB, LOG_CODE_DEFAUT, LOG_ALARME_DUREE_PONCTUEL, LOG_ALARME_STATUT_OK, __FILE__, __LINE__, __FUNCTION__, szFormat, __VA_ARGS__)


#endif // !defined(_LOG_WRAP_H_)
