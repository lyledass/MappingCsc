#ifndef __TKCORE__SMARTCARD__ATR_H
#define __TKCORE__SMARTCARD__ATR_H

#include <windows.h>

// Generique structure
typedef struct _AT_BULK {
	LPBYTE		pAtr;		///< Donnée de l'ATR
	DWORD		atrLen;		///< Longueur en octet de l'ATR
} AT_BULK;

#define		SERIALNUMBER_MAXLEN		10
typedef struct _AT_SCARDINFO {
	BYTE			histoType;		///< Format des octets d'historique (permet de savoir quelles données ne sont pas dans l'ATR et doivent être récupérées après)
	BYTE			type;			///< Type de la carte
	BYTE			subType;		///< Sous type de la carte
	BYTE			version;		///< Version de la carte
	BYTE			serialNumber[SERIALNUMBER_MAXLEN];	///< Card serial number
	UINT			serialNumberSize;	///< Serial number size
} AT_SCARDINFO;

// ATR definition
typedef AT_BULK				ATR_BULK;
typedef ATR_BULK*			PATR_BULK;
typedef CONST ATR_BULK*		PCATR_BULK;

BOOL ATRBulk_Init(DWORD len, PATR_BULK pAtrBulk);
VOID ATRBulk_Copy(PCATR_BULK pAtr, PATR_BULK pAtrCopy);
VOID ATRBulk_Dispose(PATR_BULK pAtrBulk);

#define AT_CARDINFO_HISTOTYPE_7816_4		0x00
#define AT_CARDINFO_HISTOTYPE_14443			0x01
#define AT_CARDINFO_HISTOTYPE_NXPSAM		0x02
#define AT_CARDINFO_HISTOTYPE_VIX			0x03
#define AT_CARDINFO_HISTOTYPE_UNKNOWN		0xFF

#define AT_CARDINFO_VERSION_MIFARESAM		0x01
#define AT_CARDINFO_VERSION_MIFARESAMAV1	0x02
#define AT_CARDINFO_VERSION_MIFARESAMAV2	0x03

BOOL GetISO7816_3_ATRInfo(PCATR_BULK pAtrBulk, AT_SCARDINFO* lpAtrInfo);
BOOL GetISO14443_ATRInfo(PCATR_BULK pAtrBulk, AT_SCARDINFO*	lpAtrInfo);

// ATS Definition
typedef AT_BULK				ATS_BULK;
typedef ATS_BULK*			PATS_BULK;
typedef CONST ATS_BULK*		PCATS_BULK;

BOOL ATSBulk_Init(DWORD len, PATS_BULK pAtsBulk);
VOID ATSBulk_Copy(PCATS_BULK pAtr, PATS_BULK pAtsCopy);
VOID ATSBulk_Dispose(PATS_BULK pAtsBulk);

BOOL GetISO7816_3_ATSInfo(PCATS_BULK pAtsBulk, AT_SCARDINFO* lpAtsInfo);
BOOL GetISO14443_ATSInfo(PCATS_BULK pAtsBulk, AT_SCARDINFO* lpAtsInfo);

// Old definition for Compatiblity
#define GetISO7816_4_ATSInfo GetISO7816_3_ATSInfo // Deprecated : le format d'un ATR est défini au niveau de 7816-3, 7816-4 défini les historical bytes
#define GetISO7816_4_ATRInfo GetISO7816_3_ATRInfo // Deprecated : le format d'un ATR est défini au niveau de 7816-3, 7816-4 défini les historical bytes

typedef AT_SCARDINFO ATR_CARDINFO;
typedef AT_SCARDINFO CARD_STARTUP_INFO;

#define ATR_CARDINFO_HISTOTYPE_7816_4		AT_CARDINFO_HISTOTYPE_7816_4
#define ATR_CARDINFO_HISTOTYPE_14443		AT_CARDINFO_HISTOTYPE_14443
#define ATR_CARDINFO_HISTOTYPE_NXPSAM		AT_CARDINFO_HISTOTYPE_NXPSAM
#define ATR_CARDINFO_HISTOTYPE_VIX			AT_CARDINFO_HISTOTYPE_VIX
#define ATR_CARDINFO_HISTOTYPE_UNKNOWN		AT_CARDINFO_HISTOTYPE_UNKNOWN

#define ATR_CARDINFO_VERSION_MIFARESAM		AT_CARDINFO_VERSION_MIFARESAM
#define ATR_CARDINFO_VERSION_MIFARESAMAV1	AT_CARDINFO_VERSION_MIFARESAMAV1
#define ATR_CARDINFO_VERSION_MIFARESAMAV2	AT_CARDINFO_VERSION_MIFARESAMAV2

#endif // __TKCORE__SMARTCARD__ATR_H