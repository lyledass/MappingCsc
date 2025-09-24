///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2000
//
// Fichier		: SmartCard.h
//
// Description	: Interface d'accès à une carte à puce
//
// Remarque(s)	: /
//
// Auteur       : A. PRUDENT (13/12/2000)
//
// Modif(s)     : /
//
///////////////////////////////////////////////////////////////

#ifndef __TKCORE__SMARTCARD__SMARTCARD_H
#define __TKCORE__SMARTCARD__SMARTCARD_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <TkCore/SmartCard/Atr.h>
#include <TkCore/SmartCard/Bit.h>
#include <Device/CardReader/CardReader.h>

#define SCRD_INTERFACEVERSION_MAJOR			0x0002
#define SCRD_INTERFACEVERSION_MINOR			0x0000
#define SCRD_INTERFACEVERSION				MAKELONG(SCRD_INTERFACEVERSION_MINOR, SCRD_INTERFACEVERSION_MAJOR)

#define SCRDNAME__SmartCardCheckInterfaceVer					"SmartCardCheckInterfaceVer"
typedef BOOL (__stdcall *SCRDPROC__SmartCardCheckInterfaceVer)	(DWORD expectedIVersion);

// type d'erreur
enum TCRD_STATUS {
	CRD_OK				= 0,
	CRD_ERROR_UNKNOWN,			///< Erreur inconnue

	CRD_ERROR_NOCARD,			///< Il n'y a pas ou plus de carte

	CRD_ERROR_DATAWRONG,		///< Erreur de paramètre dans la fonction
	CRD_ERROR_ACCESS,			///< Erreur d'accès au données
	CRD_ERROR_AUTH,				///< Erreur d'authentification
	CRD_ERROR_CRC,				///< Erreur de CRC
	CRD_ERROR_FAT,				///< Erreur de FAT
	CRD_ERROR_READONLY,			///< Erreur d'écriture d'une zone en lecture seule
	CRD_ERROR_WRITEREADCHECK,	///< Erreur le buffer relu ne correspond pas au buffer lu


/*
	SCC_ERROR_OPENCOM,		///< Erreur d'ouverture du port de comm.
	SCC_ERROR_TIMEOUT,		///< Time-out de la commande
	SCC_ERROR_FAIL,			///< Echec de la commande
	SCC_ERROR_DATAWRONG,	///< Mauvais argument passé à la commande
	SCC_ERROR_CRC,			///< Erreur de CRC
	SCC_ERROR_LEN,			///< Erreur de longueur de la commande
	SCC_ERROR_NOCARD,		///< Carte non présente
	SCC_ERROR_BADCARD,		///< La carte n'est pas celle attendue
	SCC_ERROR_ISOCMDFAIL,	///< Erreur de la commande ISO
	SCC_ERROR_READONLY,		///< Erreur, données en lecture seule
*/
};

typedef DWORD		TCRD_RESULT;

#define CRD_RESULT_MAKE(scrdStatus, crdrResult)		((TCRD_RESULT) MAKELONG((TCRD_STATUS)(scrdStatus), (TRDR_RESULT)(crdrResult)))
#define GET_CRD_STATUS(scrdResult)					((TCRD_STATUS) LOWORD((TCRD_RESULT) (scrdResult)))
#define GET_RDR_RESULT(scrdResult)					((TRDR_RESULT) HIWORD((TCRD_RESULT) (scrdResult)))

#define CRD_RESULT_OK								CRD_RESULT_MAKE(CRD_OK, RDR_OK)

#define ALL_READER_MODULES						0

#define SCRDNAME__ReaderAttach					"ReaderAttach"
typedef BOOL (__stdcall *SCRDPROC__ReaderAttach) (HMODULE hReaderModule);

#define SCRDNAME__ReaderDetach					"ReaderDetach"
typedef VOID (__stdcall *SCRDPROC__ReaderDetach) (HMODULE hReaderModule);	// = ALL_READER_MODULES 

#define SCRDNAME__ReaderSamGetCount				"ReaderSamGetCount"
typedef WORD (__stdcall *SCRDPROC__ReaderSamGetCount) (HMODULE hReaderModule);

#define SCRDNAME__ReaderSamIsOk					"ReaderSamIsOk"
typedef BOOL (__stdcall *SCRDPROC__ReaderSamIsOk) (HMODULE	hReaderModule,
												   WORD		samIndex);

#define	SCRDNAME__ReaderSamGetCurrent			"ReaderSamGetCurrent"
typedef DWORD (__stdcall *SCRDPROC__ReaderSamGetCurrent)(HMODULE	hReaderModule);

#define SCRDNAME__ReaderSamSelect				"ReaderSamSelect"
typedef VOID (__stdcall *SCRDPROC__ReaderSamSelect) (HMODULE	hReaderModule, 
													 WORD samIndex);

#define SCRDNAME__ReaderSamGetSerial			"ReaderSamGetSerial"
typedef DWORD (__stdcall *SCRDPROC__ReaderSamGetSerial)(HMODULE	hReaderModule, 
														WORD samIndex);

#define SCRDNAME__ReaderResetAllSam				"ReaderResetAllSam"
typedef BOOL (__stdcall *SCRDPROC__ReaderResetAllSam) (HMODULE hReaderModule);	// = ALL_READER_MODULES 

#define SCRDNAME__ReaderSamCypherDes			"ReaderSamCypherDes"
typedef BOOL (__stdcall *SCRDPROC__ReaderSamCypherDes) (HMODULE			hReaderModule,
														BOOL			bUncypherMode,
														BOOL			bChain,
														BYTE			nKif,
														BYTE			nKvc,
														WORD			dataInLen,
														const LPBYTE	pDataIn,
														WORD*			pDataOutLen,
														LPBYTE			pDataOut);

#define SCRDNAME__ReaderLoadMifareKey			"ReaderLoadMifareKey"
typedef BOOL (__stdcall *SCRDPROC__ReaderLoadMifareKey) (HMODULE hReaderModule);

#define SCRDNAME__ReaderSearchCard				"ReaderSearchCard"
typedef BOOL (__stdcall *SCRDPROC__ReaderSearchCard)(HMODULE*			phReaderModule,
													 PATR_BULK			pCardAtr,
													 TRDR_PROTOCOL*		pCardProtocol, 
													 TRDR_CARDCONTEXT*	pCardContext);
													 
//Modif VP 21/03/2008 reactivation cible apres perte
#define SCRDNAME__ReaderCloseCom				"ReaderCloseCom"
typedef TRDR_RESULT (__stdcall *SCRDPROC__ReaderCloseCom)(HMODULE		phReaderModule);


#define SCRDNAME__ReaderOpenComA				"ReaderOpenComA"
typedef TRDR_RESULT (__stdcall *SCRDPROC__ReaderOpenComA)(LPCSTR		szComPort,
														  HMODULE		phReaderModule);


#define SCRDNAME__ReaderOpenComW				"ReaderOpenComW"
typedef TRDR_RESULT (__stdcall *SCRDPROC__ReaderOpenComW)(LPCWSTR		szComPort,
														  HMODULE		phReaderModule);
//End Modif

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
//  Card handlers
//

#if !defined( SMARTCARD_VERSION )
// le type des cartes à puces
// en liaison avec les codes de type de support BRIO
// et du contenu de T_CARTE_TYPE
enum SC_TYPE {
	SC_TYPE_NONE = 0,
	SC_TYPE_MIFARE,			///< Carte Mifare
	SC_TYPE_GTML,			///< Carte GTML
	SC_TYPE_CT2000,			///< Carte CT2000
	SC_TYPE_MAGNETIQUE,		///< Ticket magnétique
	SC_TYPE_CD97,			///< Carte CD97
	SC_TYPE_GTML2,			///< Carte GTML2
	SC_TYPE_CTS_512,		///< Ticket CTS 512

	SC_TYPE_CTS_256 	= -1,		///< Ticket CTS
	SC_TYPE_ULMIFARE	= -2,		///< Ticket Ultra Light Mifare
};

typedef DWORD64		SC_SERIAL;		///< Numéro de série d'une carte

#endif

DECLARE_HANDLE(HSMARTCARD);

#define SCRDNAME__SmartcardCreate					"SmartcardCreate"
typedef HSMARTCARD (__stdcall *SCRDPROC__SmartcardCreate) (HMODULE hReaderModule, const PATR_BULK pAtr, TRDR_PROTOCOL protocol, TRDR_CARDCONTEXT cardContext);

#define SCRDNAME__SmartcardRelease					"SmartcardRelease"
typedef HSMARTCARD (__stdcall *SCRDPROC__SmartcardRelease) (HSMARTCARD hSmartCard);

// ------------------------------------------------------------
// Fonction		: DWORD serialNumber() CONST
//
// Description	: donne le numéro de série de la carte
//
// Argument(s)	: /
//
// Retour		: le numéro de série de la carte
// ------------------------------------------------------------
#define SCRDNAME__SmartcardGetSerialNumber			"SmartcardGetSerialNumber"
typedef SC_SERIAL (__stdcall *SCRDPROC__SmartcardGetSerialNumber) (HSMARTCARD hSmartCard);

// ------------------------------------------------------------
// Fonction		: LPCSTR GetCardName() CONST
//
// Description	: donne le nom de la carte (ex : GTML, Mifare...)
//
// Argument(s)	: /
//
// Retour		: le nom de la carte
// ------------------------------------------------------------
#define SCRDNAME__SmartcardGetNameA				"SmartcardGetNameA"
#define SCRDNAME__SmartcardGetNameW				"SmartcardGetNameW"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardGetNameA) (HSMARTCARD hSmartCard, LPSTR szName, size_t nameCharMax);
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardGetNameW) (HSMARTCARD hSmartCard, LPWSTR szName, size_t nameCharMax);

#ifdef _UNICODE
	#define SCRDNAME__SmartcardGetName				SCRDNAME__SmartcardGetNameW
	#define SCRDPROC__SmartcardGetName				SCRDPROC__SmartcardGetNameW
#else
	#define SCRDNAME__SmartcardGetName				SCRDNAME__SmartcardGetNameA
	#define SCRDPROC__SmartcardGetName				SCRDPROC__SmartcardGetNameA
#endif

// ------------------------------------------------------------
// Fonction		: BYTE GetCardType() CONST = 0;
//
// Description	: donne le type de la carte 
//					(ex : )
//
// Argument(s)	: /
//
// Retour		: le type de la carte
// ------------------------------------------------------------
#define SCRDNAME__SmartcardGetType			"SmartcardGetType"
typedef SC_TYPE (__stdcall *SCRDPROC__SmartcardGetType) (HSMARTCARD hSmartCard);


// Fonction		: DWORD GetATR(LPBYTE atrBuf, DWORD atrBufMaxLen) CONST
//
// Description	: donne l'ATR de la carte
//
// Argument(s)	: - atrBuf (sortie) : buffer contenant l'ATR lue
//                  - atrBufMaxLen (entrée) : taille maxi. de atrBuf
//
// Retour		: Nombre d'octets inscrits dans atrBuf 
// ------------------------------------------------------------
#define SCRDNAME__SmartcardGetATR			"SmartcardGetATR"
typedef DWORD (__stdcall *SCRDPROC__SmartcardGetATR) (HSMARTCARD hSmartCard, LPBYTE atrBuf, DWORD atrBufMaxLen);

  
#define SCRDNAME__SmartcardIsCardPresent			"SmartcardIsCardPresent"
typedef BOOL (__stdcall *SCRDPROC__SmartcardIsCardPresent) (HSMARTCARD hSmartCard);

// ------------------------------------------------------------
// Fonction		: VOID format()
//
// Description	: formate la carte
//
// Argument(s)	: /
//
// Retour		: /
// ------------------------------------------------------------
#define SCRDNAME__SmartcardFormat			"SmartcardFormat"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardFormat) (HSMARTCARD hSmartCard);

// ------------------------------------------------------------
// Fonction		: BOOL isInitialised() CONST
//
// Description	: indique si la carte a été initialisée
//
// Argument(s)	: /
//
// Retour		: TRUE si la carte est initialisée, FALSE sinon
// ------------------------------------------------------------
#define SCRDNAME__SmartcardIsInitialised			"SmartcardIsInitialised"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardIsInitialised) (HSMARTCARD hSmartCard, BOOL* pbInitialised);

// ------------------------------------------------------------
// Fonction		: VOID initialise()
//
// Description	: initialise la carte
//
// Argument(s)	: /
//
// Retour		: /
// ------------------------------------------------------------
#define SCRDNAME__SmartcardInitialise			"SmartcardInitialise"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardInitialise) (HSMARTCARD hSmartCard, DWORD dwPartitionType);

// ------------------------------------------------------------
// Fonction		: VOID read(LPBYTE data, BYTE len, BYTE pos, BYTE sid = 0) CONST
//
// Description	: lit des octets de la carte
//
// Argument(s)	: - data (sortie), buffer contenant les bits lus
//				  - spos (entrée), secteur ou SID à lire
//				  - rpos (entrée), bloc ou enregistrement à lire
//                  - bpos (entrée), position du premier bit à lire
//				  - len (entrée), nombre de bits à lire
//
// Retour		: /
// ------------------------------------------------------------
#define SCRDNAME__SmartcardRead			"SmartcardRead"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardRead) (HSMARTCARD hSmartCard, LPBIT data, WORD len, WORD spos, WORD bpos);

// ------------------------------------------------------------
// Fonction		: VOID write(LPBYTE data, BYTE len, BYTE pos, BYTE sid = 0)
//
// Description	: écrit des octets sur la carte
//
// Argument(s)	: - data (entrée), buffer contenant les octets à écrire
//				  - spos (entrée), secteur ou SID à écrire
//				  - rpos (entrée), bloc ou enregistrement à lire
//                  - bpos (entrée), position du premier bit à écrire
//				  - len (entrée), nombre de bits à écrire
//
// Retour		: /
// ------------------------------------------------------------
#define SCRDNAME__SmartcardWrite			"SmartcardWrite"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardWrite) (HSMARTCARD hSmartCard, LPCBIT data, WORD len, WORD spos, WORD bpos);

// ------------------------------------------------------------
// Fonction		: VOID commit()
//
// Description	: valide l'écriture des données sur la carte
//
// Argument(s)	: /
//
// Retour		: /
// ------------------------------------------------------------
#define SCRDNAME__SmartcardCommit			"SmartcardCommit"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardCommit) (HSMARTCARD hSmartCard, BOOL bDirectWrite);

// ------------------------------------------------------------
// Fonction		: VOID eject()
//
// Description	: ejecte la carte du lecteur (si le lecteur supporte
//                l'éjection de carte)
//
// Argument(s)	: /
//
// Retour		: /
// ------------------------------------------------------------
#define SCRDNAME__SmartcardEject			"SmartcardEject"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardEject) (HSMARTCARD hSmartCard, BOOL* pbEjected);

#define SCRDNAME__SmartcardInvalidate				"SmartcardInvalidate"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardInvalidate) (HSMARTCARD hSmartCard);

#define SCRDNAME__SmartcardRehabilitate				"SmartcardRehabilitate"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardRehabilitate) (HSMARTCARD hSmartCard);

#define SCRDNAME__SmartcardIsInvalidate				"SmartcardIsInvalidate"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardIsInvalidate) (HSMARTCARD hSmartCard, BOOL* bInvalidate);

#define SCRDNAME__SmartcardChangePin				"SmartcardChangePin"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardChangePin) (HSMARTCARD		hSmartCard, 
												   CONST LPBYTE		pOldPin,	WORD oldPinLen,
												   CONST LPBYTE		pNewPin,	WORD newPinLen,
												   BOOL*			pbSucess);

#define SCRDNAME__SmartcardVerifyPin				"SmartcardVerifyPin"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardVerifyPin) (	HSMARTCARD		hSmartCard,
																CONST LPBYTE	pPin,		WORD pinLen,
																BOOL*			pbSucess);


#define SCRDNAME__SmartcardCanSamWrite				"SmartcardCanSamWrite"
typedef TCRD_RESULT (__stdcall *SCRDPROC__SmartcardCanSamWrite) (HSMARTCARD		hSmartCard);

#endif // __TKCORE__SMARTCARD__SMARTCARD_H