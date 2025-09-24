#ifndef __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_H
#define __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <TkCore/SmartCard/Atr.h>
#include <TkCore/SmartCard/Bit.h>

// type d'erreur
enum {
	SC_ERROR_UNKNOWN = 1,	///< Erreur inconnue
	SC_ERROR_OPENCOM,		///< Erreur d'ouverture du port de comm.
	SC_ERROR_TIMEOUT,		///< Time-out de la commande
	SC_ERROR_FAIL,			///< Echec de la commande
	SC_ERROR_DATAWRONG,		///< Mauvais argument passé à la commande
	SC_ERROR_CRC,			///< Erreur de CRC
	SC_ERROR_LEN,			///< Erreur de longueur de la commande
	SC_ERROR_ACCESS,		///< Erreur d'accès au données
	SC_ERROR_AUTH,			///< Erreur d'authentification 
	SC_ERROR_NOCARD,		///< Carte non présente
	SC_ERROR_BADCARD,		///< La carte n'est pas celle attendue
	SC_ERROR_ISOCMDFAIL,	///< Erreur de la commande ISO
	SC_ERROR_READONLY,		///< Erreur, données en lecture seule
};


// type d'opération
enum {
	SC_OPENSESSION = 1,		///< Ouverture de session
	SC_CLOSESESSION,			///< Fermeture de session
	SC_READ,					///< Lecture de données sur carte
	SC_WRITE,				///< Ecriture de données de carte
	SC_WRITEKEY_CARD,		///< Ecriture de clef sur carte
	SC_LOADKEY_READER,		///< Chargement de clef dans lecteur de carte
	SC_INVALIDATE,			///< Invalidation de carte
	SC_REHABILITATE,			///< Revalidation de carte
	SC_TESTINVALIDATE,		///< Test d'invalidation de carte
	SC_CHANGEPIN,			///< Changement de code PIN de carte
	SC_VERIFYPIN,			///< Vérification du code PIN de carte
};

class SmartCardException {
public:
	SmartCardException(BYTE op, BYTE type) {
		m_operation = op;
		m_type = type;
	}

	~SmartCardException() {}

	BYTE GetOperation() { return m_operation; }
	BYTE GetType() { return m_type; }

private:
	BYTE	m_operation;
	BYTE	m_type;
};


#include "CardReader.h"

#pragma message ("------------- Using SmartCard Deprecated SDK ! -------------\n")

#if defined(SMARTCARD_SDK_V1)

	#define SMARTCARD_VERSION	0x100
	#define SmartCard			ISmartCard10

	// les type de cartes
	enum {
		SC_TYPE_PUCE = 1,
		SC_TYPE_MAGNETIQUE,
	};

	#pragma message ("-------------------- SmartCard SDK v1.0 --------------------\n")

#elif defined(SMARTCARD_SDK_V2)

	#define SMARTCARD_VERSION	0x200
	#define SmartCard			ISmartCard20

	// les type de cartes
	enum {
		SC_TYPE_PUCE = 1,
		SC_TYPE_MAGNETIQUE,
	};

	#pragma message ("-------------------- SmartCard SDK v2.0 --------------------\n")

#elif defined(SMARTCARD_SDK_V3)

	#define SMARTCARD_VERSION	0x300

	#define SmartCard			ISmartCard30

	typedef BYTE		SC_TYPE;
	enum {
		SC_TYPE_NONE = 0,
		SC_TYPE_MIFARE,			///< Carte Mifare
		SC_TYPE_GTML,			///< Carte GTML
		SC_TYPE_CT2000,			///< Carte CT2000
		SC_TYPE_MAGNETIQUE,		///< Ticket magnétique
		SC_TYPE_CD97,			///< Carte CD97
		SC_TYPE_GTML2,			///< Carte GTML2
		SC_TYPE_CTS_256,		///< Ticket CTS
		SC_TYPE_ULMIFARE,		///< Ticket Ultra Light Mifare
		SC_TYPE_CTS_512,		///< ADU
	};

	#pragma message ("-------------------- SmartCard SDK v3.0 --------------------\n")

#elif defined(SMARTCARD_SDK_V3_1)

	#define SMARTCARD_VERSION	0x301
	#define SmartCard			ISmartCard31

	typedef DWORD		SC_SERIAL;		///< Numéro de série d'une carte

	typedef BYTE		SC_TYPE;
	enum {
		SC_TYPE_NONE = 0,
		SC_TYPE_MIFARE,			///< Carte Mifare
		SC_TYPE_GTML,			///< Carte GTML
		SC_TYPE_CT2000,			///< Carte CT2000
		SC_TYPE_MAGNETIQUE,		///< Ticket magnétique
		SC_TYPE_CD97,			///< Carte CD97
		SC_TYPE_GTML2,			///< Carte GTML2
		SC_TYPE_CTS_256,		///< Ticket CTS
		SC_TYPE_ULMIFARE,		///< Ticket Ultra Light Mifare
		SC_TYPE_CTS_512,		///< ADU
	};

	#pragma message ("-------------------- SmartCard SDK v3.1 --------------------\n")

#elif defined(SMARTCARD_SDK_V3_1I)

	#define SMARTCARD_VERSION	0x311
	#define SmartCard			ISmartCard31i

	typedef DWORD		SC_SERIAL;		///< Numéro de série d'une carte

	// le type des cartes à puces
	// en liaison avec les codes de type de support BRIO
	// et du contenu de T_CARTE_TYPE
	typedef BYTE		SC_TYPE;
	enum {
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

	#pragma message ("------------- SmartCard SDK v3.1  Intertic -----------------\n")

#elif defined(SMARTCARD_SDK_V4)

	#define SMARTCARD_VERSION	0x400
	#define SmartCard			ISmartCard40

	typedef DWORD		SC_SERIAL;		///< Numéro de série d'une carte

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
		SC_TYPE_CTS_256,		///< Ticket CTS
		SC_TYPE_ULMIFARE,		///< Ticket Ultra Light Mifare
		SC_TYPE_CTS_512,		///< ADU
	};

	#pragma message ("-------------------- SmartCard SDK v4.0 --------------------\n")

#elif defined(SMARTCARD_SDK_V4_1)

	#define SMARTCARD_VERSION	0x401
	#define SmartCard			ISmartCard41

	typedef DWORD64		SC_SERIAL;		///< Numéro de série d'une carte

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
		SC_TYPE_CTS_256,		///< Ticket CTS
		SC_TYPE_ULMIFARE,		///< Ticket Ultra Light Mifare
		SC_TYPE_CTS_512,		///< ADU
	};

	#pragma message ("-------------------- SmartCard SDK v4.1 --------------------\n")

#elif defined(SMARTCARD_SDK_V4_1I)

	#define SMARTCARD_VERSION	0x411
	#define SmartCard			ISmartCard41i

	typedef DWORD64		SC_SERIAL;		///< Numéro de série d'une carte

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

		SC_TYPE_CTS_256		= -1,		///< Ticket CTS
		SC_TYPE_ULMIFARE	= -2,		///< Ticket Ultra Light Mifare
	};

	#pragma message ("----------- SmartCard SDK v4.1 Intertic --------------------\n")

#else
	#define SMARTCARD_VERSION	0x00
	#pragma message ("------------ SmartCard Version Not Specified ! -------------\n")
#endif

#include "v1.0/SmartCard.h"
#include "v2.0/SmartCard.h"
#include "v3.0/SmartCard.h"
#include "v3.1/SmartCard.h"
#include "v3.1i/SmartCard.h"
#include "v4.0/SmartCard.h"
#include "v4.1/SmartCard.h"
#include "v4.1i/SmartCard.h"

#endif	/* __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_H */
