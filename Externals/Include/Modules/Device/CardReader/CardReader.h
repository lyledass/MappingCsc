///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2007
//
// Fichier		: CardReader.h
//
// Description	: Interface d'accès au lecteur de cartes
//
// Remarque(s)	: /
//
// Auteur       : A. PRUDENT (19/03/2007)
//
// Modif(s)     : /
//
///////////////////////////////////////////////////////////////

#ifndef __TKCORE__DEVICE_CARDREADER__CARDREADER_H
#define __TKCORE__DEVICE_CARDREADER__CARDREADER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <TkCore/SmartCard/Atr.h>
#include "DataCeiling.h"

#ifndef PACKED
	#if _MSC_VER >= 1300
		// on est en VC++ 7 au moins
#define PACKED	__declspec(align(1))
	#else
		// on est en VC++ 6 donc "align(#)" n'existe pas
		// on utilise #prama 
		#define PACKED __declspec()
		#pragma pack(1)
	#endif
#endif

#define RDR_INTERFACEVERSION_MAJOR			0x0001
#define RDR_INTERFACEVERSION_MINOR			0x0001		// JFL : 0x0001 : modification du retour de la fonction SamReplafonnement. Ca aurai du etre une modif majeure mais on l'a mis en mineur car seulement utilisé à Rouen
#define RDR_INTERFACEVERSION				MAKELONG(RDR_INTERFACEVERSION_MINOR, RDR_INTERFACEVERSION_MAJOR)

#define RDRNAME__ReaderCheckInterfaceVer			"ReaderCheckInterfaceVer"
typedef BOOL (__stdcall *RDRPROC__ReaderCheckInterfaceVer)(DWORD expectedIVersion);

// erreurs du lecteur de cartes
typedef enum _TRDR_RESULT {
	RDR_OK				= 0,
	RDR_ERROR,
	RDR_ERROR_OPENCOM,
	RDR_ERROR_READERNOTFOUND,
	RDR_ERROR_TIMEOUT,
	RDR_ERROR_NOANSWER,
	RDR_ERROR_CHECKSUM,
	RDR_ERROR_FAIL,
	RDR_ERROR_CARDNOTFOUND,
	RDR_ERROR_ANTENNAFAILS,
	RDR_ERROR_DATAWRONG,
	RDR_ERROR_OVERFLOW,
	RDR_ERROR_ERRORSAM,
	RDR_ERROR_BADATR,
	RDR_ERROR_TXERROR,
	RDR_ERROR_WARNINGVERSION,
	RDR_ERROR_SELECTSAMERROR,
	RDR_ERROR_UNKNOWNCLASSCOMMAND,
	RDR_ERROR_INPUTDATAWRONG,
} TRDR_RESULT;

typedef enum _TRDR_PROTOCOL {
	RDR_PROTOCOL_UNKNOWN			= 0,	///< Unknow card protocol
	RDR_PROTOCOL_ISOA,						///< ISO A
	RDR_PROTOCOL_ISOB,						///< ISO B
	RDR_PROTOCOL_INNOVATRON,				///< Innovatron
	RDR_PROTOCOL_MIFARE,					///< Mode Mifare
	RDR_PROTOCOL_TICKET,					///< Mode B'
} TRDR_PROTOCOL;

typedef void*	TRDR_CARDCONTEXT;			///< Reader context for a card

#define RDR_CARDSEARCH_MASK_NONE			0x0000
#define RDR_CARDSEARCH_MASK_ISOA			0x0001
#define RDR_CARDSEARCH_MASK_ISOB			0x0002
#define RDR_CARDSEARCH_MASK_INNOVATRON		0x0004
#define RDR_CARDSEARCH_MASK_MIFARE			0x0008
#define RDR_CARDSEARCH_MASK_TICKET			0x0010
#define RDR_CARDSEARCH_MASK_ALL				0xFFFF

#define RDR_LED_RED			0x0001		///< Led rouge
#define RDR_LED_YELLOW		0x0002		///< Led jaune
#define RDR_LED_GREEN		0x0004		///< Led verte

#define	RDR_ANTENNA_1		0x0001		///< Antenne 1
#define	RDR_ANTENNA_2		0x0002		///< Antenne 2

#define RDRNAME__ReaderComOpenA									"ReaderComOpenA"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderComOpenA)		(LPCSTR szComPort);

#define RDRNAME__ReaderComOpenW									"ReaderComOpenW"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderComOpenW)		(LPCWSTR szComPort);

#define RDRNAME__ReaderComClose									"ReaderComClose"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderComClose)		();

#define RDRNAME__ReaderCscReset									"ReaderCscReset"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderCscReset)		();

#define RDRNAME__ReaderCardSearch								"ReaderCardSearch"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderCardSearch)		(WORD				searchMask,	
																 BOOL				bContactCard,
																 DWORD				dwTimeOut,
																 PATR_BULK			pCardAtr,	
																 TRDR_PROTOCOL*		pCardProtocol,
																 TRDR_CARDCONTEXT*	pCardContext);

#define RDRNAME__ReaderCardEnd								"ReaderCardEnd"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderCardEnd)		(TRDR_CARDCONTEXT	cardContext);

#define RDRNAME__ReaderLedSwitchOnOff								"ReaderLedSwitchOnOff"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderLedSwitchOnOff)		(WORD rdrLedsOnMask);

#define RDRNAME__ReaderAntennaSwitchOnOff							"ReaderAntennaSwitchOnOff"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderAntennaSwitchOnOff)	(WORD rdrAntennasOnMask);

#define RDRNAME__ReaderAntennaGetStatus								"ReaderAntennaGetStatus"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderAntennaGetStatus)	(WORD* pRdrAntennasOnMask);

#define RDRNAME__ReaderMifEepromGetKeyMax							"ReaderMifEepromGetKeyMax"
typedef WORD		(__stdcall *RDRPROC__ReaderMifEepromGetKeyMax)	();

#define RDRNAME__ReaderMifEepromLoadKey								"ReaderMifEepromLoadKey"
typedef TRDR_RESULT (__stdcall *RDRPROC__ReaderMifEepromLoadKey)	(WORD keyIndex, const LPBYTE pMifKey);

#define RDRNAME__ReaderGetSamSlotCount								"ReaderGetSamSlotCount"
typedef WORD		(__stdcall *RDRPROC__ReaderGetSamSlotCount)		();

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
//  SAM communication
//

typedef enum _TRDR_SAM_PROTOCOL {
	RDR_SAM_PROTOCOL_UNKNOWN			= 0,
	RDR_SAM_PROTOCOL_HSP_INNOVATRON,
	RDR_SAM_PROTOCOL_ISO_7816,
} TRDR_SAM_PROTOCOL;

#define RDRNAME__SamSelect										"SamSelect"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamSelect)	(WORD samSlot, TRDR_SAM_PROTOCOL protocol);

#define RDRNAME__SamReset										"SamReset"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamReset)	(PATR_BULK pSamAtr);

/* JFL : 16/01/08 : correction ALEA
#define RDRNAME__SamSelectDiversifier							"SamSelectDiversifier"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamSelectDiversifier)(	const		LPBYTE pData, 
																WORD		dataLen, 
																BOOL*		pbRes);
*/

#define RDRNAME__SamAuthenticate								"SamAuthenticate"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamAuthenticate)	(	WORD				keyLen,
																const LPBYTE		pCypherKey,
																BOOL*				pbRes);

#define RDRNAME__SamCertificatCompute							"SamCertificatCompute"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamCertificatCompute)(	BYTE			nKey,
																BYTE			nKvc,
																WORD			dataLen,
																const LPBYTE	pData,
																WORD			certifLen,
																LPBYTE			pCertif);

#define RDRNAME__SamCertificatCheck								"SamCertificatCheck"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamCertificatCheck)(	BYTE			nKey,
																BYTE			nKvc,
																WORD			dataLen,
																const LPBYTE	pData,
																WORD			certifLen,
																const LPBYTE	pCertif,
																BOOL*			pbOk);

#define RDRNAME__SamCypherDes									"SamCypherDes"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamCypherDes)(	BYTE			nKif,
														BYTE			nKvc,
														WORD			dataLen,
														LPBYTE			pData,
														BOOL			bUncypherMode);

#define RDRNAME__SamMacCompute									"SamMacCompute"
typedef BOOL		 (__stdcall *RDRPROC__SamMacCompute)(void * data,
														int len,
														void * rep );

#define RDRNAME__SamGetReCeilingAnswer							"SamGetReCeilingAnswer"
typedef TRDR_RESULT (__stdcall *RDRPROC__SamGetReCeilingAnswer)(DWORD lSamSerial, 
																long lCompteurVal, 
																BYTE bKvcPlafond, 
																BYTE* pbSamAlea,
																int iSamAleaLen,
																BYTE* pbSamDataFile, 
																int iSamDataFileLen, 
																BYTE* pbSamDataCrypted, 
																int iSamDataCryptedLen);

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
// Calypso card communication (GTML, CD97, CT2000)
//

typedef enum _TRDR_CALYPSO_ACESSMODE {
	RDR_CALYPSO_MODE_DEFAULT				= 0,
	RDR_CALYPSO_MODE_PROTECTED,
	RDR_CALYPSO_MODE_STAMPED,
	RDR_CALYPSO_MODE_PIN,
} TRDR_CALYPSO_ACESSMODE;

typedef enum _TRDR_CALYPSO_SESSIONLEVEL {
	RDR_CALYPSO_SESSIONLEVEL_UNKNOWN		= 0,

	RDR_CALYPSO_SESSIONLEVEL_PERSO,
	RDR_CALYPSO_SESSIONLEVEL_RELOAD,
	RDR_CALYPSO_SESSIONLEVEL_VALID,

	RDR_CALYPSO_SESSIONLEVEL_COUNT,
} TRDR_CALYPSO_SESSIONLEVEL;

typedef PACKED struct _TRDR_CALYPSO_SECURPARAM
{
	DWORD						size;		///< Structure size in bytes
	TRDR_CALYPSO_ACESSMODE		AccMode;	///< Acces Mode
	BYTE						SID;		///< Short ID
	WORD						LID;		///< Long ID
	BYTE						nKey;		///< Index of Key (if nKvc = 0) or Kif
	BYTE						nKvc;		///< KVC
} TRDR_CALYPSO_SECURPARAM;
typedef TRDR_CALYPSO_SECURPARAM far		*LPRDR_CALYPSO_SECURPARAM;

#define RDR_CALYPSO_SECUR_USECARDKVC		0xFF

typedef PACKED struct _TRDR_CALYPSO_STATUS
{
	BYTE		Code;		// Status Code
	BYTE		Byte1;		// First detail byte
	BYTE		Byte2;		// Last detail byte
} TRDR_CALYPSO_STATUS;
typedef TRDR_CALYPSO_STATUS far			*LPRDR_CALYPSO_STATUS;

typedef PACKED struct _TRDR_CALYPSO_PINCODE
{
	DWORD		size;		///< Structure size in bytes
	BYTE		pin [4];	///< Pin Code
} TRDR_CALYPSO_PINCODE;
typedef TRDR_CALYPSO_PINCODE far	*LPRDR_CALYPSO_PINCODE;

typedef PACKED struct  _TRDR_CALYPSO_FILEDESCR
{
	BYTE		tag;			///< $85
	BYTE		length;			///< $17

	BYTE		sid;			///< SID
	BYTE		type;			///< Type ($01=MF, $02=DF, $04=EF)
	BYTE		efType;			///< EF Type ($02=Linear, $04=Circular, $08=Counter, $10=Application Specific)
	BYTE		recSize;		///< Record bytes size ($00 for DF and MF)
	BYTE		dataSize;		///< Records count ($00 for DF and MF)
	BYTE		AC [4];			///< Acces modes ($00=Never, $01=Pin, $02=Protected, $0F=Applicative, $12=Protected & Session, $1F=Always)
	BYTE		nKey [4];		///< Key index number to use
	BYTE		status;			///< Status ($x0=File valid readable, $x1=File invalidated readable, $x2=File valid unreadable, $x3=File invalid unreadable, 
								///< $0x=No Pin errors, $1x=One Pin error, $3x=Two Pin errors, $7x=Three pin errors)
	BYTE		kvc [3];		///< KVC ($00 for EF)

	BYTE		floor [3];
	BYTE		ceiling [3];	

} TRDR_CALYPSO_FILEDESCR;


#define RDRNAME__CalypsoReadRecord								"CalypsoReadRecord"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoReadRecord)	(	TRDR_CARDCONTEXT				cardContext,
																const LPRDR_CALYPSO_SECURPARAM	pSecurParam,	BYTE	recordNum, 
																WORD							bufLen,			LPBYTE	pBuffer, 
																LPRDR_CALYPSO_STATUS			pStatus);

#define RDRNAME__CalypsoUpdateRecord							"CalypsoUpdateRecord"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoUpdateRecord)	(TRDR_CARDCONTEXT				cardContext,
																 const LPRDR_CALYPSO_SECURPARAM	pSecurParam,	BYTE			recordNum,
																 WORD							bufLen,			const LPBYTE	pBuffer,
																 LPRDR_CALYPSO_STATUS			pStatus);

#define RDRNAME__CalypsoAppendRecord							"CalypsoAppendRecord"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoAppendRecord)	(TRDR_CARDCONTEXT					cardContext,
																 const LPRDR_CALYPSO_SECURPARAM		pSecurParam,
																 WORD								bufLen,			const LPBYTE	pBuffer, 
																 LPRDR_CALYPSO_STATUS				pStatus);

#define RDRNAME__CalypsoOpenSession								"CalypsoOpenSession"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoOpenSession)	(TRDR_CARDCONTEXT					cardContext,
																 TRDR_CALYPSO_SESSIONLEVEL			sessionLevel,
																 const LPRDR_CALYPSO_SECURPARAM		pSecurParam,	BYTE	recordNum, 
																 LPRDR_CALYPSO_STATUS				pStatus);

#define RDRNAME__CalypsoCloseSession							"CalypsoCloseSession"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoCloseSession)	(TRDR_CARDCONTEXT		cardContext,
																 LPRDR_CALYPSO_STATUS	pStatus);

#define RDRNAME__CalypsoSelectFile								"CalypsoSelectFile"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoSelectFile)	(	TRDR_CARDCONTEXT				cardContext,
																WORD							LID,			
																TRDR_CALYPSO_FILEDESCR*			pFileDescr,
																LPRDR_CALYPSO_STATUS			pStatus);

#define RDRNAME__CalypsoInvalidate								"CalypsoInvalidate"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoInvalidate)	(	TRDR_CARDCONTEXT					cardContext,
																const LPRDR_CALYPSO_SECURPARAM		pSecurParam,			
																 LPRDR_CALYPSO_STATUS				pStatus);

#define RDRNAME__CalypsoRehabilitate							"CalypsoRehabilitate"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoRehabilitate)	(TRDR_CARDCONTEXT					cardContext,
																 const LPRDR_CALYPSO_SECURPARAM		pSecurParam,			
																 LPRDR_CALYPSO_STATUS				pStatus);

#define RDRNAME__CalypsoChangePIN								"CalypsoChangePIN"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoChangePIN)	(	TRDR_CARDCONTEXT					cardContext,
																const LPRDR_CALYPSO_SECURPARAM		pSecurParam,
																const LPRDR_CALYPSO_PINCODE			pOldPinCode,
																const LPRDR_CALYPSO_PINCODE			pMewPinCode,
																LPRDR_CALYPSO_STATUS				pStatus);

#define RDRNAME__CalypsoVerifyPIN								"CalypsoVerifyPIN"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoVerifyPIN)	(	TRDR_CARDCONTEXT				cardContext,
																const LPRDR_CALYPSO_SECURPARAM	pSecurParam,
																const LPRDR_CALYPSO_PINCODE		pPinCode,
																LPRDR_CALYPSO_STATUS			pStatus);

#define	RDRNAME__CalypsoSelectApplication						"CalypsoSelectApplication"
typedef TRDR_RESULT (__stdcall *RDRPROC__CalypsoSelectApplication)	(ATR_BULK* pAtrBulk);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
// Mifare card communication
//

typedef WORD						TRDR_MIFARE_STATUS;
typedef TRDR_MIFARE_STATUS far		*LPRDR_MIFARE_STATUS;

typedef enum _TRDR_MIFARE_KEYTYPE {
	RDR_MIFARE_KEYTYPE_A		= 0x0A,
	RDR_MIFARE_KEYTYPE_B		= 0x0B,
} TRDR_MIFARE_KEYTYPE;

#define RDRNAME__MifareSelect									"MifareSelect"
typedef TRDR_RESULT (__stdcall *RDRPROC__MifareSelect)(		TRDR_CARDCONTEXT		cardContext,
															DWORD					serial,
															LPRDR_MIFARE_STATUS		pStatus);

#define RDRNAME__MifareAuthSector								"MifareAuthSector"
typedef TRDR_RESULT (__stdcall *RDRPROC__MifareAuthSector)(		TRDR_CARDCONTEXT		cardContext,
																BYTE					sector,
																TRDR_MIFARE_KEYTYPE		keyType,
																WORD					keyIndex,
																LPRDR_MIFARE_STATUS		pStatus);

#define RDRNAME__MifareReadBlock								"MifareReadBlock"
typedef TRDR_RESULT (__stdcall *RDRPROC__MifareReadBlock)	(	TRDR_CARDCONTEXT		cardContext,
																BYTE					block,
																WORD					bufLen,		LPBYTE	pBuffer,
																LPRDR_MIFARE_STATUS		pStatus);

#define RDRNAME__MifareWriteBlock								"MifareWriteBlock"
typedef TRDR_RESULT (__stdcall *RDRPROC__MifareWriteBlock)(		TRDR_CARDCONTEXT		cardContext,
																BYTE					block,
																WORD					bufLen,		const LPBYTE	pBuffer,
																LPRDR_MIFARE_STATUS		pStatus);

#define RDRNAME__MifareChangeKey								"MifareChangeKey"
typedef TRDR_RESULT (__stdcall *RDRPROC__MifareChangeKey)(		TRDR_CARDCONTEXT		cardContext,
																BYTE					sector,
																TRDR_MIFARE_KEYTYPE		initialKeyType,
																WORD					initialKeyIndex,

																TRDR_MIFARE_KEYTYPE		finalKeyType,
																const LPBYTE			pFinalKeyA,
																const LPBYTE			pAccessBytes,
																const LPBYTE			pFinalKeyB,

																LPRDR_MIFARE_STATUS		pStatus);


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
// Receilling
//

typedef enum _TRDR_RESULT_RECEILING
{
	RECEILING_OK	=	0,
	RECEILING_ERROR,
	RECEILING_ERROR_SAM_LOCKED,
	RECEILING_ERROR_COUNTER,
}TRDR_RESULT_RECEILING;

#define RDRNAME__SamVerifyCounters								"SamVerifyCounters"
typedef HDATACEILING (__stdcall *RDRPROC__SamVerifyCounters)(	BYTE				bmKifPlafond,
																BOOL				bModeDynamique,
																int					iSamIndex);

#define RDRNAME__SamReadSerial									"SamReadSerial"
typedef long (__stdcall *RDRPROC__SamReadSerial)();

#define RDRNAME__SamReplafonnement								"SamReplafonnement"
typedef TRDR_RESULT_RECEILING	(__stdcall *RDRPROC__SamReplafonnement)(		BYTE*	reponse,
																				BOOL	bModeDynamique);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
// Ticket communication
//

typedef WORD						TRDR_TICKET_STATUS;
typedef TRDR_TICKET_STATUS far		*LPRDR_TICKET_STATUS;

#define RDRNAME__Ticket256Read								"Ticket256Read"
typedef TRDR_RESULT (__stdcall *RDRPROC__Ticket256Read)	(	TRDR_CARDCONTEXT		cardContext,
															BYTE					bytePos,
															WORD					bufLen,		LPBYTE	pBuffer,
															LPRDR_TICKET_STATUS		pStatus);

#define RDRNAME__Ticket256Update							"Ticket256Update"
typedef TRDR_RESULT (__stdcall *RDRPROC__Ticket256Update)(	TRDR_CARDCONTEXT		cardContext,
															BYTE					bytePos,
															WORD					bufLen,		const LPBYTE	pBuffer,
															LPRDR_TICKET_STATUS		pStatus);

#define RDRNAME__Ticket512Read								"Ticket512Read"
typedef TRDR_RESULT (__stdcall *RDRPROC__Ticket512Read)	(	TRDR_CARDCONTEXT		cardContext,
															BYTE					bytePos,
															WORD					bufLen,		LPBYTE	pBuffer,
															LPRDR_TICKET_STATUS		pStatus);

#define RDRNAME__Ticket512Update							"Ticket512Update"
typedef TRDR_RESULT (__stdcall *RDRPROC__Ticket512Update)(	TRDR_CARDCONTEXT		cardContext,
															BYTE					bytePos,
															WORD					bufLen,		const LPBYTE	pBuffer,
															LPRDR_TICKET_STATUS		pStatus);

#endif // __TKCORE__DEVICE_CARDREADER__CARDREADER_H