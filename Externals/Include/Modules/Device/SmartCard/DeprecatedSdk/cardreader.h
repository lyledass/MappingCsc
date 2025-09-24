///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2000
//
// Fichier		: CardTerminal.h
//
// Description	: Interface d'accès au lecteur de cartes
//
// Remarque(s)	: /
//
// Auteur       : A. PRUDENT (13/12/2000)
//
// Modif(s)     : /
//
///////////////////////////////////////////////////////////////

#ifndef __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_CARDREADER_H
#define __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_CARDREADER_H

// card message sent to window
enum {
	WM_CARD_INSERTED	= WM_APP + 1,
	WM_CARD_REMOVED,
};

// erreurs du lecteur de cartes
enum {
	SCR_OK			= 0,
	SCR_ERROR,
	SCR_ERROR_OPENCOM,
	SCR_ERROR_READERCOM,
	SCR_ERROR_READERNOTFOUND,
	SCR_ERROR_SAMAUTH,
};

// état des SAM
enum TSCRS_STATUS {
	SCRS_OK			= 0,	///< SAM présent et en état de fonctionnement
	SCRS_NOTFOUND,			///< SAM non présent
	SCRS_LOCKED,			///< SAM non déverouillé
	SCRS_DISABLED,			///< SAM non autorisé applicativement
};

enum TSCRP_PROTOCOL {
	SCRP_PROTOCOL_UNKNOWN			= 0,	///< Unknow card protocol
	SCRP_PROTOCOL_ISOA,						///< ISO A
	SCRP_PROTOCOL_ISOB,						///< ISO B
	SCRP_PROTOCOL_INNOVATRON,				///< Innovatron
	SCRP_PROTOCOL_MIFARE,					///< Mode Mifare
	SCRP_PROTOCOL_TICKET,					///< Mode B'
};


// dll function's name
#define DLLCARDREADER_OPEN_NAME						"CardReaderOpen"
#define DLLCARDREADER_CLOSE_NAME					"CardReaderClose"
#define DLLCARDREADER_RESET_NAME					"CardReaderReset"
#define DLLCARDREADER_STATUS_NAME					"CardReaderStatus"
#define DLLCARDREADER_CONFIG_NAME					"CardReaderConfig"
#define DLLCARDREADER_ANTENNA_SWITCH_NAME			"CardReaderAntennaSwitch"

#define DLLCARDREADER_CARDGET_NAME					"CardReaderCardGet"
#define DLLCARDREADER_CARDCREATE_NAME				"CardReaderCardCreate"
#define DLLCARDREADER_CARDRELEASE_NAME				"CardReaderCardRelease"

#define DLLCARDREADER_SAMGETCURRENTSERIAL_NAME		"CardReaderSAMGetCurrentSerial"
#define DLLCARDREADER_SAMGETCOUNT_NAME				"CardReaderSAMGetCount"
#define DLLCARDREADER_SAMGETSERIAL_NAME				"CardReaderSAMGetSerial"
#define DLLCARDREADER_SAMSETDISABLED				"CardReaderSAMSetDisabled"
#define DLLCARDREADER_SAMCYPHER_NAME				"CardReaderSAMCypher"
#define DLLCARDREADER_SAMMACCOMPUTE_NAME			"CardReaderSAMMacCompute"

#define DLLCARDREADER_MIFARELOADKEYFROMCARD_NAME	"CardReaderMIFARELoadKeyFromCard"

#define DLLCARDREADER_SAMGETSTATUS_NAME				"CardReaderSAMGetStatus"

// prototype of card reader fonctions
typedef DWORD (*DLLCARDREADER_OPEN)				(WORD readerId, LPCSTR port, HWND hWndPollingMsg);
typedef DWORD (*DLLCARDREADER_CLOSE)			(WORD readerId);
typedef DWORD (*DLLCARDREADER_RESET)			(WORD readerId);
typedef DWORD (*DLLCARDREADER_STATUS)			(WORD readerId);
typedef DWORD (*DLLCARDREADER_CONFIG)			(WORD readerId, HWND hParentWnd);
typedef DWORD (*DLLCARDREADER_ANTENNA_SWITCH)	(WORD readerId, WORD Param);

typedef BOOL  (*DLLCARDREADER_CARDGET)			(WORD readerId, VOID** ppSmartCard);
typedef BOOL  (*DLLCARDREADER_CARDCREATE)		(WORD readerId, const BYTE* pAtr, WORD atrLen, TSCRP_PROTOCOL cardProtocol, void* rdrCardContext, VOID** ppSmartCard);
typedef BOOL  (*DLLCARDREADER_CARDRELEASE)		(WORD readerId, VOID** ppSmartCard);

typedef BOOL  (*DLLCARDREADER_SAMGETCURRENTSERIAL)	(WORD readerId, DWORD* pSerial);
typedef BYTE  (*DLLCARDREADER_SAMGETCOUNT)			(WORD readerId);
typedef BOOL  (*DLLCARDREADER_SAMGETSERIAL)			(WORD readerId, BYTE samId, DWORD* pSerial);
typedef VOID  (*DLLCARDREADER_SAMSETDISABLE)		(WORD readerId, BYTE samId);
typedef BOOL  (*DLLCARDREADER_SAMCYPHER)			(WORD readerId, BOOL bUncypher, BYTE kif, BYTE kvc, BYTE dataLen, BYTE* data);
typedef BOOL  (*DLLCARDREADER_SAMMACCOMPUTE)		(WORD readerId, BYTE * data, int len, BYTE * rep);

typedef VOID  (*DLLCARDREADER_MIFARELOADKEYFROMCARD) (WORD readerId, HWND hwndOwner, LPCTSTR port);

typedef TSCRS_STATUS (*DLLCARDREADER_SAMGETSTATUS)	(WORD readerId, BYTE samId);


#endif /* __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_CARDREADER_H */