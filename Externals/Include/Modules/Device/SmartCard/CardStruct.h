#ifndef __TKCORE__SMARTCARD__CARDSTRUCT__H
#define __TKCORE__SMARTCARD__CARDSTRUCT__H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Device/CardReader/CardReader.h>

/////////////////////////////////////////////////////////////////////////////////////////
//
// Structure en système de fichier (type Calypso)
//
//

#define SID_NONE				0x00		///< Pas de valeur définie pour le SID
#define LID_NONE				0x0000		///< Pas de valeur définie pour le LID

// Définition des status
#define STATUS_DEFAULT		0x00
#define STATUS_PINTOREAD	0x01

// Définitions des types de fichier
#define		TYPE_MF		0x01		///< Master File
#define		TYPE_DF		0x02		///< Directory File
#define		TYPE_EF		0x04		///< Elementary File

// Définitions des EFType
#define EFT_NA				0x00	///< Non applicable (pour les MF et les DF)
#define EFT_LINEARFIXED		0x02	///< Structure linéaire fixe
#define EFT_CIRCULAR		0x04	///< Structure circulaire
#define EFT_COUNTER			0x08	///< Structure de compteur
#define EFT_KEYS			0x22	///< Structure de clefs
#define EFT_SIMCOUNTER		0xF8	///< Structure de compteur simulé

// Définition d'un élément de structure d'une carte (EF ou DF)
typedef struct _TCARD_FILESTRUCT {
	WORD						lid;			///< Lid du fichier
	BYTE						sid;			///< Sid du fichier
	BYTE						type;			///< Type du fichier (MF, DF, EF...)
	BYTE						status;			///< Etat du fichier (RUF)
	TRDR_CALYPSO_SESSIONLEVEL	keyLevel;		///< Niveau de clef d'accès à utiliser pour l'écriture

	// champs significatifs uniquement pour un EF :
	BYTE						efType;			///< Type du EF (linéaire, circulaire, compteur...)
	BYTE						recSize;		///< Taille en octet d'un enregistrement
	BOOL						writable;		///< Les enregistrements peuvent ils être écrits ou non ?
	BYTE						recCount;		///< Nombre d'enregistrements du EF

	// champs pour les données simulée
	BYTE						refSid;			///< Sid du fichier de référence
	BYTE						refOffset;		///< Octet d'offset dans le fichier de référence
	BYTE						refSize;		///< Taille en octet dans le fichier de référence

} TCARD_FILESTRUCT;

typedef TCARD_FILESTRUCT			*LPCARD_FILESTRUCT;
typedef CONST TCARD_FILESTRUCT		*LPCCARD_FILESTRUCT;

#define CARD_FILESTRUCT_DECLARE( cardStructName, fileCount )								static const TCARD_FILESTRUCT cardStructName [ fileCount ] = {
#define CARD_FILESTRUCT_MF( lid )																	{ lid,	SID_NONE,	TYPE_MF,	STATUS_DEFAULT,		RDR_CALYPSO_SESSIONLEVEL_UNKNOWN,	EFT_NA,				0x00,		FALSE,		0,			0,				0,			0		},
#define CARD_FILESTRUCT_DF( lid )																	{ lid,	SID_NONE,	TYPE_DF,	STATUS_DEFAULT,		RDR_CALYPSO_SESSIONLEVEL_UNKNOWN,	EFT_NA,				0x00,		FALSE,		0,			0,				0,			0		},
#define CARD_FILESTRUCT_EF( lid, sid, nKey, efType, recCount, recSize, bWritable )					{ lid,	sid,		TYPE_EF,	STATUS_DEFAULT,		nKey,								efType,				recSize,	bWritable,	recCount,	0,				0,			0		},
#define CARD_FILESTRUCT_EF_PIN( lid, sid, nKey, efType, recCount, recSize, bWritable )				{ lid,	sid,		TYPE_EF,	STATUS_PINTOREAD,	nKey,								efType,				recSize,	bWritable,	recCount,	0,				0,			0		},
#define CARD_FILESTRUCT_EF_PIN( lid, sid, nKey, efType, recCount, recSize, bWritable )				{ lid,	sid,		TYPE_EF,	STATUS_PINTOREAD,	nKey,								efType,				recSize,	bWritable,	recCount,	0,				0,			0		},
#define CARD_FILESTRUCT_EF_SIMCOUNTER(	lid, sid, recSize, refCounterSid, refOffset, refSize )		{ lid,	sid,		TYPE_EF,	STATUS_DEFAULT,		RDR_CALYPSO_SESSIONLEVEL_UNKNOWN,	EFT_SIMCOUNTER,		recSize,	TRUE,		1,			refCounterSid,	refOffset,	refSize	},
#define CARD_FILESTRUCT_END()																};

#define CARD_FILESTRUCT_EF_LINEAR(			lid, sid, nKey, recCount, recSize, bWritable )	CARD_FILESTRUCT_EF(			lid,	sid,	nKey,	EFT_LINEARFIXED,	recCount,	recSize, bWritable)
#define CARD_FILESTRUCT_EF_CIRCULAR(		lid, sid, nKey, recCount, recSize, bWritable )	CARD_FILESTRUCT_EF(			lid,	sid,	nKey,	EFT_CIRCULAR,		recCount,	recSize, bWritable)
#define CARD_FILESTRUCT_EF_LINEAR_PIN(		lid, sid, nKey, recCount, recSize, bWritable )	CARD_FILESTRUCT_EF_PIN(		lid,	sid,	nKey,	EFT_LINEARFIXED,	recCount,	recSize, bWritable)
#define CARD_FILESTRUCT_EF_COUNTER(			lid, sid, nKey, recCount, recSize, bWritable )	CARD_FILESTRUCT_EF(			lid,	sid,	nKey,	EFT_COUNTER,		recCount,	recSize, bWritable)


#endif /* __TKCORE__SMARTCARD__CARDSTRUCT__H */