#ifndef __MAP_FIELD_DEF_H
#define __MAP_FIELD_DEF_H

#include <TkCore/SmartCard/Bit.h>

#define FIELD_POS_UNFIXED	0xFFFF	///< Valeur pour une position de lecture/écriture d'un champ non fixé à l'avance
#define FIELD_CODEIMG_NONE	0x0L	///< Valeur d'un code image non significatif

// Position d'un champs
typedef struct _FIELD_POSITION {
	WORD	fileId;			///< Sid de fichier ou numéro de bloc de lecture/écriture (vaut FIELD_POS_UNFIXED si non fixe)
	WORD	filePos;		///< Position en bit de lecture/écirture dans le fichier ou le bloc (vaut FIELD_POS_UNFIXED si non fixe)
} FIELD_POSITION;

typedef FIELD_POSITION			*LPFIELD_POSITION;
typedef CONST FIELD_POSITION	*LPCFIELD_POSITION;

typedef struct _FIELD_PROPERTY {
	WORD				type;				///< Type du champ
	WORD				subType;			///< Sous type du champ
	WORD				len;				///< Longueur du champ en bits
	BOOL				bVirtual;			///< Indique si le champ est réellement encodé ou non sur la carte
	BOOL				bReadOnly;			///< Indique si le champ est en lecture seule dans le mapping
	DWORD				defVal;				///< Valeur par défaut
	BOOL				bNeeded;			///< Indique si le champ est obligatoire (si le parent est un bitmap, le bit sera monté même si le champ est nul)
	BOOL				bNegLogic;			///< Indique que la valeur du champ est gérée en logique inversée (1 est encodé 0xFE)
	BOOL				bResetToMax;		///< Indique que l'on met le champ à sa valeur maximale lors d'un reset (et le bit du bimap associé n'est pas monté)

	BOOL				bBitLeftToRight;	///< On stocke la valeur du champ en sens inverse (soit : 5 (00101b) est encodé 10100b dans la carte)
	BOOL				bNotInBitmap;		///< Pour un champs d'un bitmap, indique si sa présence n'est pas conditionné par un bit. 
											///< Le champs est toujours présent si le parent est activé et la longueur du bitmap parent en bit est donc réduite de 1...)
	BOOL				bValIsMsbPos;		///< La valeur du champ est la position du bit de poids fort dans (ex : 1010b donne 4, 100000b donne 6)
//	DWORD				data;				///< Donnée spécifique selon le type (valeurs ci-dessous)
} FIELD_PROPERTY;

// Informations logiques liées au champ
typedef struct _FIELD_LOGICALINFO {
	WORD	fieldId;	///< Identifiant du champ : permet de faire le lien 'info TPV' <-> 'champ du mapping'
						///< vaut MAP_NOID si le champ est non significatif pour le TPV
	WORD	instance;	///< Numéro d'instance du champ
	DWORD	codeImg;	///< Code image du champ ou FIELD_CODEIMG_NONE si non significatif
} FIELD_LOGICALINFO;

typedef FIELD_LOGICALINFO			*LPFIELD_LOGICALINFO;
typedef CONST FIELD_LOGICALINFO		*LPCFIELD_LOGICALINFO;

// Conditions / valeurs par défaut
typedef struct _FIELD_CONDITIONVAL {
	BYTE	logicalOp;		///< Opérateur logique (ou, et)
	DWORD	unidTestField;	///< Identifiant unique d'un champ du mapping
	BYTE	compareOp;		///< Opérateur de comparaison (=, <>, <, >, <=, >=)
	DWORD	compareVal;		///< Valeur de comparaison
	DWORD	val;			///< Valeur si les conditions sont respectées
} FIELD_CONDITIONVAL;

typedef FIELD_CONDITIONVAL			*LPFIELD_CONDITIONVAL;
typedef CONST FIELD_CONDITIONVAL	*LPCFIELD_CONDITIONVAL;

// DEFINITION MAPPING VERSION 1
typedef struct _FIELD_DESCR {
	WORD				fieldId;	///< Identifiant du champ : permet de faire le lien 'info TPV' <-> 'champ du mapping'
									///< vaut MAP_NOID si le champ est non significatif pour le TPV
	WORD				type;		///< Type du champ
	WORD				subType;	///< Sous type du champ (si type vaut TYPE_DATE et TYPE_CASE)
	BOOL				readOnly;	///< Indique si le champ est en lecture seule dans le mapping
	WORD				len;		///< Longueur du champ en bit
									///< ou nombre de champs si le type est ensembliste (TYPE_DATA, TYPE_BITMAP, TYPE_SWITCH ou TYPE_CASE)
	DWORD				codeImg;	///< Code image du champ ou FIELD_CODEIMG_NONE si non significatif

	DWORD				data;		///< Donnée spécifique selon le type (valeurs ci-dessous)

	WORD				posCount;	///< Nombre de positions pour le champ
	LPFIELD_POSITION	posList;	///< Tableau de positions du champ dans la carte
} FIELD_DESCR;

typedef FIELD_DESCR			*LPFIELD_DESCR;
typedef CONST FIELD_DESCR	*LPCFIELD_DESCR;

#define FIELD_DESCR_SIZEOFHEADER	(sizeof(FIELD_DESCR) - sizeof(LPFIELD_POSITION))

// DEFINITION MAPPING VERSION 2
typedef struct _FIELD_DESCR_HEADER {
	DWORD				unidFieldId;		///< Identifiant unique d'un champ du mapping

	FIELD_PROPERTY		prop;				///< Propriété du champ
	FIELD_LOGICALINFO	logicalInfo;		///< Informations logiques (pour l'applicatif)

	WORD				posCount;			///< Nombre de positions pour le champ
	WORD				condCount;			///< Nombre de conditions associées au champ
} FIELD_DESCR_HEADER;


typedef struct _FIELD_DESCR_EX {
	FIELD_DESCR_HEADER		header;			///< Partie commune à tous les descripteur de champs

	LPFIELD_POSITION		posList;		///< Liste de positions du champ dans la carte
	LPFIELD_CONDITIONVAL	condDefValList;	///< Liste des conditions / valeur par défaut associées
//	BOOL					bFixedEndPos;	///< [Israel] Vrai indique que la position indique une position de fin fixe
} FIELD_DESCR_EX;

typedef FIELD_DESCR_EX			*LPFIELD_DESCR_EX;
typedef CONST FIELD_DESCR_EX	*LPCFIELD_DESCR_EX;

#define FIELD_DESCR_EX_SIZEOFHEADER		(sizeof(FIELD_DESCR_HEADER))






// DEFINITION MAPPING VERSION 3


typedef struct _FIELD_PROPERTY_V3 {
	WORD				type;				///< Type du champ
	WORD				subType;			///< Sous type du champ
	WORD				len;				///< Longueur du champ en bits
	BOOL				bVirtual;			///< Indique si le champ est réellement encodé ou non sur la carte
	BOOL				bReadOnly;			///< Indique si le champ est en lecture seule dans le mapping
	DWORD				defVal;				///< Valeur par défaut
	DWORD				dNeeded;			///< Gestion du champ obligatoire 
											///< 0 = Non obligatoire sans réactivation
											///< 1 = Non obligatoire avec réactivation
											///< 2 = Obligatoire sans réactivation
											///< 3 = Obligatoire avec réactivation

	BOOL				bNegLogic;			///< Indique que la valeur du champ est gérée en logique inversée (1 est encodé 0xFE)
	BOOL				bResetToMax;		///< Indique que l'on met le champ à sa valeur maximale lors d'un reset (et le bit du bimap associé n'est pas monté)

	BOOL				bBitLeftToRight;	///< On stocke la valeur du champ en sens inverse (soit : 5 (00101b) est encodé 10100b dans la carte)
	BOOL				bNotInBitmap;		///< Pour un champs d'un bitmap, indique si sa présence n'est pas conditionné par un bit. 
											///< Le champs est toujours présent si le parent est activé et la longueur du bitmap parent en bit est donc réduite de 1...)
	BOOL				bValIsMsbPos;		///< La valeur du champ est la position du bit de poids fort dans (ex : 1010b donne 4, 100000b donne 6)		
	DWORD				data;				///< Donnée spécifique selon le type (valeurs ci-dessous)
	BOOL				bAutoValueDisabled;	///< La valeur n'est pas calculée automatiquement (permet de désactiver le calcul automatique du nombre d'éléments d'une liste)
} FIELD_PROPERTY_V3 ;

typedef struct _FIELD_LOGICALINFO_V3 {
	WORD	fieldId;	///< Identifiant du champ : permet de faire le lien 'info TPV' <-> 'champ du mapping'
						///< vaut MAP_NOID si le champ est non significatif pour le TPV
	DWORD	instance;	///< Numéro d'instance du champ
	DWORD	codeImg;	///< Code image du champ ou FIELD_CODEIMG_NONE si non significatif
} FIELD_LOGICALINFO_V3;

typedef FIELD_LOGICALINFO_V3			*LPFIELD_LOGICALINFO_V3;
typedef CONST FIELD_LOGICALINFO_V3		*LPCFIELD_LOGICALINFO_V3;

typedef struct _FIELD_DESCR_HEADER_V3 {
	DWORD					unidFieldId;		///< Identifiant unique d'un champ du mapping

	FIELD_PROPERTY_V3		prop;				///< Propriété du champ
	FIELD_LOGICALINFO_V3	logicalInfo;		///< Informations logiques (pour l'applicatif)

	WORD					posCount;			///< Nombre de positions pour le champ
	WORD					condCount;			///< Nombre de conditions associées au champ
} FIELD_DESCR_HEADER_V3;

typedef struct _FIELD_DESCR_EX_V3 {
	FIELD_DESCR_HEADER_V3		header;			///< Partie commune à tous les descripteur de champs

	LPFIELD_POSITION			posList;		///< Liste de positions du champ dans la carte
	LPFIELD_CONDITIONVAL		condDefValList;	///< Liste des conditions / valeur par défaut associées
	BOOL						bFixedEndPos;	///< [Israel] Vrai indique que la position indique une position de fin fixe
} FIELD_DESCR_EX_V3;

typedef FIELD_DESCR_EX_V3			*LPFIELD_DESCR_EX_V3;
typedef CONST FIELD_DESCR_EX_V3		*LPCFIELD_DESCR_EX_V3;

#define FIELD_DESCR_EX_SIZEOFHEADER_V3		(sizeof(FIELD_DESCR_HEADER_V3))











// ENTETE DE FICHIER MAPPING
#define MAPFILE_MAGICWORD		"MAPFILE"
#define MAPFILE_MAGICWORDLEN	7

enum {
	MAPFILE_DEFVERSION_1	=	0x0100,
	MAPFILE_DEFVERSION_2	=	0x0200,				///< Version 2.00 de définition de mapping
	MAPFILE_DEFVERSION_201	=	0x0201,				///< Version 2.01 de définition de mapping : ajout de la propriété bNeeded
	MAPFILE_DEFVERSION_202	=	0x0202,				///< Version 2.02 de définition de mapping : ajout de la propriété bNullIsFull
	MAPFILE_DEFVERSION_203	=	0x0203,				///< Version 2.03 de définition de mapping : ajout de la propriété bResetToMax
	MAPFILE_DEFVERSION_204	=	0x0204,				///< Version 2.04 de définition de mapping : ajout des propriétés bRevBitOrder, bNotInBitmapet et bValIsMsbPos
//	MAPFILE_DEFVERSION_205	=	0x0205,				///< Version 2.05 de définition de mapping : ajout du CChampList2 (et nbMaxElmts)
	MAPFILE_DEFVERSION_300	=	0x0300,				///< Version 3.00 de définition de mapping : ajout du CChampList2 (et nbMaxElmts) + n° instance sur 32 bits
	MAPFILE_DEFVERSION_301	=	0x0301,				///< Version 3.01 de définition de mapping : ajout d'une propriété bAutoValueDisabled
	MAPFILE_DEFVERSION_302	=	0x0302,				///< Version 3.02 de définition de mapping : Gestion des différents type d'obligation avec la propriété bNeeded
	MAPFILE_DEFVERSION_303	=	0x0303,				///< Version 3.03 de définition de mapping : Gestion des deux champs event drniere monte et periode de fin validité
	MAPFILE_DEFVERSION_304	=	0x0304,				///< Version 3.04 de définition de mapping : Ajout de la Dfv dans Event

	MAPFILE_DEFVERSION_LAST = MAPFILE_DEFVERSION_304,
};

typedef struct {
	char	magicWord[MAPFILE_MAGICWORDLEN];	///< Vaut 'MAPFILE' pour un fichier mapping
	WORD	mapDefVersion;						///< Version des structures du fichier mapping (ex : 0x0200)
	BYTE	padding[23];						///< RFU
} MAPFILE_HEADER;

typedef MAPFILE_HEADER			*LPMAPFILE_HEADER;
typedef CONST MAPFILE_HEADER	*LPCMAPFILE_HEADER;


/*
**	FIELD_DESCR.data contient les données suivantes selon :
**	- si fieldId <> MAP_NOID (le type est forcément non essembliste),
**		data identifie de manière unique le regroupement logique de champs auquel appartient un champ. 
**		Ainsi, si un champ est dupliqué dans le mapping, ceci permet d'en gérer plusieurs indépendemments.
**		On peut donc définir plusieurs fois des champs contrats, profils...
**
**			LOWORD(data) : 'numéro du groupe 1' + (100 * 'numéro du groupe 2') + (10000 * 'numéro du groupe 3')
**
**		ex : pour un champ du contrat 2, data = 0x0000002
**			 pour un champ du segment 2 du contrat 1, data = 0x000000C9	(201) 
**	
**		remarques : 
**			- au vu de la définition du data, un champ ne peut appartenir que à 3 sous groupes simultanéments
**			- un identifiant de groupe prend un valeur de 0 à 99 inclus (sauf pour le 3eme qui va de 0 à 5)
**			- les numéros de groupes doivent commencer à 0
**			- les numéros de groupes doivent être consécutifs
**
**	- si type == TYPE_SWITCH, data indentifie le champ testé
**
**			LOWORD(data) : identifiant du champ
**			HIWORD(data) : valeur de regroupement
**
*/

typedef struct _FIELD_INSTANCE { 
	LPBIT		value;		///< Valeur du champ (tableau de bits)
	BOOL		modified;	///< Valeur du champ modifiée ?
} FIELD_INSTANCE;

typedef FIELD_INSTANCE			*LPFIELD_INSTANCE;
typedef CONST FIELD_INSTANCE	*LPCFIELD_INSTANCE;

// les types de base de champs
enum FIELD_TYPE {
// TYPES UNITAIRE
	TYPE_NOMBRE = 0,		///< Type entier positif ou nul
	TYPE_BOOLEEN,			///< Type booléen (vrai / faux)
	TYPE_DATE,				///< Type date, il existe plusieurs formats de date (voir FIELD_TYPE_DATE)
	TYPE_PLANNING,			///< Type planning hebdomadaire (2 bits par jours)
	TYPE_TRANSCARTE,		///< Type transcarte pour gérer un numéro transcarte
// TYPES ENSEMBLISTE
	TYPE_DATA,				///< Ensemble de champs 
	TYPE_BITMAP,			///< Ensemble de champs
	TYPE_SWITCH,			///< Ensemble conditionel
	TYPE_CASE,				///< Cas d'un ensemble conditionel
// TYPES UNITAIRE (suite)
	TYPE_TEXTE,				///< Type chaine de caractères (4 caractères maxi.)
	TYPE_CONST,				///< Type constante
// TYPES ENSEMBLISTE (RE)
	TYPE_LIST,				///< Type liste d'éléments
	TYPE_LIST2,				///< [Israel] Type liste d'éléments avec caractère de fin
	TYPE_PADDING,			///< [Israel] Type entier de longueur indéfinie avec une position de fin fixe

	TYPE_COUNT,				///< Nombre total de types
};

// les différentes sous types de dates
enum FIELD_TYPE_DATE {
	DATE_ISO = 0,			///< Date au format ISO - Nombre de jours depuis une année de référence
	DATE_545,				///< Format : JJJJJmmmmAAAAA b avec AAAAA=nombre d'années depuis 2000
	DATE_HEURE,				///< Date ou Heure selon la valeur (si < 600000 nombre de minutes depuis le début de l'année, sinon nombre de jours depuis la décennie) (nb : les années révolues font toutes 366 jours)
	DATE_ROULANTE,			///< Nombre de jours de la décennie (nb : les années révolues font toutes 366 jours)
	DATE_C,					///< Nombre de jours depuis le 01/01/1997 (1545)
	DATE_F,					///< Date au format BCD (AAAA-mm-JJ h) (1545)

	HEURE_1,				///< Format : hhhhh-MMMMMMM-sssss b (1545) 
	HEURE_2,				///< Nombre de minutes depuis minuit (1545)
	DATE_MINUTE,			///< Nombre de minutes depuis le 1er janvier de l'année en cours
	HEURE_2HALF,			///< Nombre de double minutes depuis minuit (Heure2 divisé par 2)
	HEURE_4,				///< Nombre de quart d'heure depuis minuit (Heure2 divisé par 4)

	DATE_CVF_DELTA,			///< Delta par rapport à la DFV de la carte
	DATE_TIME_REAL,			///< Nombre de secondes depuis le 01/01/1997 00:00:00 (GMT)
	
	TYPEDATE_COUNT,			///< Nombre total de types 'Date'
};

// 
enum FIELD_CONDITION_OPLOGICAL {
	CONDITION_OPLOGICAL_OR = 0,
	CONDITION_OPLOGICAL_AND,
	CONDITION_OPLOGICAL_NOR,
	CONDITION_OPLOGICAL_NAND,

	CONDITION_OPLOGICAL_COUNT,
};

enum FIELD_CONDITION_OPCOMPARE {
	CONDITION_OPCOMPARE_EQ = 0,	///< Equal
	CONDITION_OPCOMPARE_LTE,	///< Lesser Than or Equal
	CONDITION_OPCOMPARE_GTE,	///< Greater Than or Equal
	CONDITION_OPCOMPARE_LT,		///< Lesser Than
	CONDITION_OPCOMPARE_GT,		///< Greater Than
	CONDITION_OPCOMPARE_NEQ,	///< Not Equal

	CONDITION_OPCOMPARE_COUNT,
};

enum MAP_FIELDS_IDTYPE {
	MAP_FIT_NONE				= 0x00,
	MAP_FIT_CARDINFO			= 0x01,
	MAP_FIT_HOLDERINFO			= 0x02,
	MAP_FIT_PROFIL				= 0x03,
	MAP_FIT_BESTCONTRACT		= 0x05,
	MAP_FIT_CONTRACT			= 0x06,
	MAP_FIT_CONTRACTSEG			= 0x07,
	MAP_FIT_SPECIALEVENTLIST	= 0x08,
	MAP_FIT_SPECIALEVENT		= 0x09,
	MAP_FIT_EVENT				= 0x10,
	MAP_FIT_VALIDITY_LOCATION	= 0x11,
};

// les identifiants uniques des champs du mapping
enum MAP_FIELDS_ID {
	MAP_NOID = 0x0000,			///< Identifiant non significatif
	MAP_ROOT,					///< Identifiant de la racine du mapping (seul idenfifiant associé à un ensemble !)

	// champs des informations carte
	MAP_CARDINFO_MIN = 0x0100,						///< Borne inférieure des champs 'Information carte'
	MAP_CARDINFO_VERSIONNUMBER = MAP_CARDINFO_MIN,	///< Numéro de version de l'application billétique
	MAP_CARDINFO_NETWORKID,							///< Code application (code ville)
	MAP_CARDINFO_APPISSUERID,						///< Id du créateur de carte
	MAP_CARDINFO_APPENDDATE,						///< Dfv de la carte
//	MAP_CARDINFO_PAYMETHOD,
// 	MAP_CARDINFO_AUTHENTICATOR,
//	MAP_CARDINFO_SELECTLIST,
	MAP_CARDINFO_CARDTYPE,							///< Type de la carte
	MAP_CARDINFO_MAPVERSION,						///< Numéro de version du mapping
	MAP_CARDINFO_CAUTION,							///< Montant de la caution pour la carte
	MAP_CARDINFO_CAUTIONDEVISE,						///< Code devise de la caution
	MAP_CARDINFO_INVALIDATEFLAG,					///< Flag d'invalidation de la carte
	MAP_CARDINFO_TELEMODIFFLAG,						///< Flag de télémodif de la carte						
	MAP_CARDINFO_CONTRACTKEY,						///< Clef du prochain contrat ajouté
	MAP_CARDINFO_CARDNUMBER,						///< Numéro de série de la carte
	MAP_CARDINFO_TRANSCARDNUMBER,					///< Numéro 'transcarte' de la carte
	MAP_CARDINFO_PROFILCOUNT,						///< Nombre de profils dans la carte
	MAP_CARDINFO_BESTCONTRACTCOUNT,					///< Nombre de contrats dans la carte
	MAP_CARDINFO_BESTSPECIALEVENTCOUNT,				///< Nombre d'événements spéciaux
	MAP_CARDINFO_ICCDATE,							///< Date d'émission de la carte
	MAP_CARDINFO_NULL,								///< Identifiant non significatif de la carte
	MAP_CARDINFO_CARDGRAPHNUMBER,					///< Numéro graphique de carte
	MAP_CARDINFO_MAX,								///< Borne supérieure des champs 'Information carte'

	// champs des informations porteur
	MAP_HOLDERINFO_MIN = 0x0200,					///< Borne inférieure des champs 'Information porteur'
	MAP_HOLDERINFO_IDNUMBER = MAP_HOLDERINFO_MIN,	///< Numéro TPV du client
	MAP_HOLDERINFO_BIRTHDATE,						///< Date de naissance du client
	MAP_HOLDERINFO_CARDSTATUS,						///< Type de carte
	MAP_HOLDERINFO_COMMERCIALID,					///< Identification de l'utilisation possible de la carte dans le domaine d'interopérabilité
	MAP_HOLDERINFO_SALEDEVICE,						///< Identifiant du périphérique de vente
	MAP_HOLDERINFO_AUTHENTICATOR,					///< Code de contrôle de l'intégrité des données
	MAP_HOLDERINFO_NULL,							///< Identifiant non significatif du porteur
		// ajout Israel
	MAP_HOLDERINFO_PAY_METHOD,						///< Allowed contracts payments methods

#pragma message("TODO : déplacer MAP_HOLDERINFO_PAY_METHOD en MAP_CARDINFO_PAY_METHOD \n")
	
	MAP_HOLDERINFO_LANGUAGE,						///< Holder main language
	MAP_HOLDERINFO_COMPANY,							///< Short holder company identifier
	MAP_HOLDERINFO_COMPANY_ID,						///< Holder identifier, within company
		// fin ajout Israel
	
	MAP_HOLDERINFO_MAX,								///< Borne supérieure des champs 'Information porteur'

	// champs des informations profil
	MAP_PROFIL_MIN = 0x0300,						///< Borne inférieure des champs 'Profil'
	MAP_PROFIL_NUMBER = MAP_PROFIL_MIN,				///< Code 'BRIO' du profil
	MAP_PROFIL_ENDDATE,								///< Dfv du profil
	MAP_PROFIL_BEGINDATE,							///< Ddv du profil
	MAP_PROFIL_NULL,								///< Identifiant non significatif d'un profil
	MAP_PROFIL_MAX,									///< Borne supérieure des champs 'Profil'

	// champs du résumé des contrats
	MAP_BESTCONTRACT_MIN = 0x0500,							///< Borne inférieure des champs 'BestContract'
	MAP_BESTCONTRACT_EXPLOITANT = MAP_BESTCONTRACT_MIN,		///< Code de l'exploitant associé au contract
	MAP_BESTCONTRACT_TYPE,									///< Type de contrat
	MAP_BESTCONTRACT_PRIORITY,								///< Priorité du contrat
	MAP_BESTCONTRACT_INSTANCEPOINTER,						///< Pointeur vers l'instance du contrat
	MAP_BESTCONTRACT_CONTRACTCODE,							///< Code 'BRIO' du contrat
	MAP_BESTCONTRACT_ZONE,									///< Code 'BRIO' de la zone associée au contrat
	MAP_BESTCONTRACT_NULL,									///< Identifiant non significatif d'un best contract
	MAP_BESTCONTRACT_MAX,									///< Borne supérieure des champs 'BestContract'

	// champs des contrats
	MAP_CONTRACT_MIN = 0x0600,								///< Borne inférieure des champs 'Contrat'
	MAP_CONTRACT_PROVIDER = MAP_CONTRACT_MIN,				///< Code de l'exploitant assurant le service
	MAP_CONTRACT_TARIFF,									///< Code 'BRIO' du contrat
	MAP_CONTRACT_SALEAGENT,									///< Code de l'exploitant de vente
	MAP_CONTRACT_SALEDEVICE,								///< Code du périphérique de vente
	MAP_CONTRACT_TYPEMAPPING,								///< Numéro de version du mapping du contrat
	MAP_CONTRACT_VALIDITYENDDATE,							///< Date de fin de validité du contrat
	MAP_CONTRACT_STATUS,									///< Etat du contrat
	MAP_CONTRACT_GREYLIST,									///< Date de traitement en liste grise
	MAP_CONTRACT_CHRONO,									///< Chronologie
	MAP_CONTRACT_FLAGTELEMODIF,								///< Flag de télémodif du contrat
	// GeoOVD
	MAP_CONTRACT_JOURNEYORIGINE,							///< Code de l'origine du trajet
	MAP_CONTRACT_JOURNEYDESTINATION,						///< Code de la destination du trajet
	MAP_CONTRACT_JOURNEYVIA,								///< Code du via du trajet
	// NamedToken
	MAP_CONTRACT_TOKENNUMBER1,								///< Code 'BRIO' du jeton nomé 1
	MAP_CONTRACT_TOKENNUMBER2,								///< Code 'BRIO' du jeton nomé 2
	MAP_CONTRACT_TOKENNUMBER3,								///< Code 'BRIO' du jeton nomé 3
	MAP_CONTRACT_AUTOLOAD_DATESTART,						///< Date de début/reprise de l'autoload
	MAP_CONTRACT_AUTOLOAD_DATESTOP,							///< Date de fin/suspension de l'autoload
	// SoldX
	MAP_CONTRACT_SOLDX,										///< Solde de voyages ou unités
	MAP_CONTRACT_DEBITSOLDX,								///< Valeur du débit lors d'une validation
	// TPurse
	MAP_CONTRACT_TPURSE,									///< Montant du porte monnaie
	MAP_CONTRACT_DEBITTPURSE,								///< Valeur du débit lors d'une validation
	// Passenger
	MAP_CONTRACT_GROUP,										///< Nombre de passagers
	// Z Periodicity
	MAP_CONTRACT_ENDPERIOD,									///< Date de fin de la période
	MAP_CONTRACT_SOLDPERIOD,								///< Solde de voyage dans la période
	// GeoZonales
	MAP_CONTRACT_GEOZONE1,									///< Zone origine authorisée
	MAP_CONTRACT_GEOZONE2,									///< Zone destination authorisée
	MAP_CONTRACT_GEOZONE3,									///< Zone 3 authorisée
	// GeoOD
	MAP_CONTRACT_JOURNEYORIGINE1,							///< Code origine 1
	MAP_CONTRACT_JOURNEYDESTINATION1,						///< Code destination 1
	MAP_CONTRACT_JOURNEYORIGINE2,							///< Code origine 2
	MAP_CONTRACT_JOURNEYDESTINATION2,						///< Code destination 2
	// GeoLine
	MAP_CONTRACT_JOURNEYLINE1,								///< Code ligne 1
	MAP_CONTRACT_JOURNEYLINE2,								///< Code ligne 2
	// Restriction Hebdo
	MAP_CONTRACT_RESTRICTHEBDO,								///< Restriction hebdomadaire
	MAP_CONTRACT_VALIDITYSTARTDATE,							///< Date de début de validité du contrat
	MAP_CONTRACT_VALIDITYENDTIME,							///< Heure de fin de validité du contrat
	MAP_CONTRACT_TOKEN,										///< Nombre de jeton (pour un coupon simple)
	MAP_CONTRACT_INTERMODAL,								///< Gestion de l'intermodalité
	
	// MAP_CONTRACT_PASSENGER_CLASS,
	// MAP_CONTRACT_VALIDITY_INFO,
	// MAP_CONTRACT_COEF,

	MAP_CONTRACT_CONTRACTKEY,								///< Clef du contrat
	MAP_CONTRACT_FLAGINVALIDATION,							///< Flag d'invalidation
	// MAP_CONTRACT_GROUPCORRESPONDANCE						///< Nombre de passagers en correspondance
	MAP_CONTRACT_TOKENZINITIAL,								///< Solde initial pour Z Voyages
	MAP_CONTRACT_TOKENZPERIODTYPE,							///< Type de période pour Z Voyages
	MAP_CONTRACT_HASHPINCODE,								///< Hash PinCode pour le contrat d'habilitation
	MAP_CONTRACT_RIGHTS1,									///< Droits 1 pour le contrat d'habilitation
	MAP_CONTRACT_RIGHTS2,									///< Droits 2 pour le contrat d'habilitation
	MAP_CONTRACT_PDCSHIFT,									///< Numéro de la course pour le contrat d'habilitation
	MAP_CONTRACT_AGENTNUMBER,								///< Numéro de l'agent
	MAP_CONTRACT_PASSENGERCLASS,							///< Classe de service des voyageurs
	MAP_CONTRACT_SERIALNUMBER,								///< Numéro de série du contrat

	// champs des contrats spécifiques SNCF
	MAP_CONTRACT_SNCF_VALIDITYJOURNEYS,						///< Nombre de voyages autorisés
	MAP_CONTRACT_SNCF_JOURNEYDISTANCE,						///< Distance
	MAP_CONTRACT_SNCF_VALIDITYDURATION,						///< Durée de validité
	MAP_CONTRACT_SNCF_VALIDITYZONEORIGIN,					///< Zone de validité définis à partir de l'origine
	MAP_CONTRACT_SNCF_VALIDITYZONEDESTINATION,				///< Zone de validité définis à partir de la destination
	MAP_CONTRACT_SNCF_PAYMETHOD,							///< Code mode de paiement
	MAP_CONTRACT_SNCF_PRICEAMOUNT,							///< Montant total
	MAP_CONTRACT_SNCF_SALEDATE,								///< Date de vente
	MAP_CONTRACT_SNCF_SALETIME,								///< Heure de vente
	MAP_CONTRACT_SNCF_LINKEDCONTRACT,						///< Pointeur sur le contrat lié
	MAP_CONTRACT_SNCF_RECEIPTDELIVERED,						///< Indicateur justificatif émis
	MAP_CONTRACT_SNCF_SCREEN,								///< Ecran de l'étui portatif passif
	MAP_CONTRACT_SNCF_EXCEPTION,							///< Indicateur d'intervention du vendeur sur le tarif du produit
	MAP_CONTRACT_SNCF_PROXY,								///< Code mandataire
	MAP_CONTRACT_SNCF_PECTYPE,								///< Type de prise en charge
	MAP_CONTRACT_SNCF_PECRATE,								///< Taux de prise en charge
	MAP_CONTRACT_SNCF_PECAMOUNT,							///< Montant de prise en charge
	MAP_CONTRACT_SNCF_PECNUMBER,							///< Numéro de contrat de prise en charge
	MAP_CONTRACT_SNCF_PROXYREVERSION,						///< Indicateur de prise en charge de la prestation associée
	MAP_CONTRACT_SNCF_VEHICLEALLOWED,						///< Type de transport utilisé
	MAP_CONTRACT_SNCF_LIMITEDATE,							///< Date maximale de première validation
	MAP_CONTRACT_SNCF_VALIDITYZONE,							///< Zone(s) autorisée(s)
	MAP_CONTRACT_SNCF_VALIDITYJOURNEYSLEFT,					///< Nombre de voyages restants

	// champs des contrats pour compatibilité avec les anciens projets
	// (mappings non 1545 ou assimilé)
	MAP_CONTRACT_EVT_LOCATIONID,							///< Arrêt tarifaire de dernière montée
	MAP_CONTRACT_EVT_ROUTENUMBER,							///< Ligne de dernière montée
	MAP_CONTRACT_EVT_VEHICULEID,							///< Numéro du véhicule de dernière montée
	MAP_CONTRACT_EVT_SENS,									///< Sens de la dernière validation
	MAP_CONTRACT_EVT_CORSPD_GROUP,							///< Nombre de passagers en correspondance
	MAP_CONTRACT_EVT_CORSPD_LEVEL,							///< Nombre de correspondances effectuées
	MAP_CONTRACT_EVT_CORSPD_DELTAMIN,						///< Minutes écoulées entre la première validation et la dernière correspondance
	
	MAP_CONTRACT_CODEFAMILLE,								///< Code de la famille BRIO du champ
	MAP_CONTRACT_CODEMAPPING,								///< Numéro du mapping BRIO du contrat

	// champs Aoste
	MAP_CONTRACT_LINECTRL,									///< Contrôle de la ligne sur un sens autorisé
	MAP_CONTRACT_STATUSPMT,									///< Etat de la validation
	MAP_CONTRACT_CPT1VALUE1,								///< Nombre de voyages pour la période (Fidélité)
	MAP_CONTRACT_CPT1DATESTART,								///< Date de début de la période (Fidélité)

	// champs ajoutés pour le Bas Rhin
	MAP_CONTRACT_VALIDITYSTARTTIME,							///< Heure de début de validité du contrat
	MAP_CONTRACT_PERIODEIDENTITY,							///< Identifie la période pour laquelle le décompte de voyages par sous-période s'applique
	MAP_CONTRACT_AUTHENTICATOR,								///< Code de contrôle de l'authenticité des données
	MAP_CONTRACT_NULL,										///< Identifiant non significatif d'un contrat

	// champs ajoutés pour Intercode 2
	MAP_CONTRACT_SOLDX_INITIAL,
	MAP_CONTRACT_TPURSE_INITIAL,
//	MAP_CONTRACT_GEOSECTION_INITIAL,
	// GeoSections
	MAP_CONTRACT_ZONES,										///< Nombre de sections autorisées				
	MAP_CONTRACT_SOLDZONES,									///< Nombre de sections restantes
	MAP_CONTRACT_SOLDZONESINITIAL,							///< Nombre de sections initiales

	MAP_CONTRACT_HASCOUNTER,								///< Si le champ est présent, le contrat dispose d'un compteur. La valeur du champ n'a pas d'importance
	
	// champs ajoutés pour Intercode 2
	MAP_CONTRACT_SOLDX_CONSUMED,							///< Nombre de voyages consommés

	MAP_CONTRAT_MAXOTP,										///< Max OTP : nombre de rechargement maximum réalisable sur un support de type CTS		
	MAP_CONTRAT_OTPVALUE,									///< Nombre de rechargements effectués ou restant (NFO : a voir...)

		// ajout Israel
	dep_MAP_CONTRACT_SPATIAL_TYPE,							///< définition des zones pour les ContractValidityLocation,
#pragma message("TODO : à supprimer")
	MAP_CONTRACT_VALIDITY_LOCATION_END_LIST,				///< définition du caractère de fin d'une ContractValidityLocationX
	MAP_CONTRACT_VERSION_NUMBER,							///< Numéro de version de structure de contrat
	MAP_CONTRACT_TARIFF_ACCESS,								///< Type de contrat ( pp)			: accès autorisés
	MAP_CONTRACT_TARIFF_COUNTER,							///< Type de contrat (   ccc)		: compteurs
	MAP_CONTRACT_TARIFF_NAME,								///< Type de contrat (      nnnnnn)	: nom de contrat
	MAP_CONTRACT_SALE_NUMBER_DAILY,							///< Numéro de vente dans la journée pour l'équipement
	MAP_CONTRACT_RESTRICT_CODE,								///< Restrictions générales
	MAP_CONTRACT_RESTRICT_DURATION,							///< Durée de la restriction d'un voyage
	MAP_CONTRACT_LINKED_PROFILE_CODE,						///< Code du profil qui a autorisé la vente de ce contrat

	MAP_CONTRACT_PADDING,									///< champ de taille variable (avec position de fin fixe) qu'on remplit d'une valeur (0 par exemple)
	MAP_CONTRACT_TARIFF_ISRAEL,								///< Type de contrat ( ppcccnnnnn )
	MAP_CONTRACT_REF_PRIORITY,								///< Priorité du contrat (référence sur BestContract)

	MAP_CONTRACT_VALIDITY_DURATION,							///< durée de validity du contrct (  ddnnnnnn )
	MAP_CONTRACT_VALIDITY_DURATION_UNIT,					///< Unité  ( dd )			[ 0=months, 1=weeks, 2=days, 3=half-hours ]
	MAP_CONTRACT_VALIDITY_DURATION_VALUE,					///< Valeur (   nnnnnn )
	MAP_CONTRACT_PERIOD_JOURNEYS,							///< Nombre de voyages par période ( ppnnnnnn )
	MAP_CONTRACT_PERIOD_JOURNEYS_UNIT,						///< Période    ( pp ) [0=month, 1=week, 2=day]
	MAP_CONTRACT_PERIOD_JOURNEYS_VALUE,						///< Valeur max (   nnnnnn )
	MAP_CONTRACT_SALE_DATE,									///< Date de vente
	MAP_CONTRACT_RESTRICT_TIME_CODE,						///< Définition des restrictions de période

		// fin ajout Israel

	MAP_CONTRACT_MAX,										///< Borne supérieure des champs 'Contrat'

	// champs des segments
	MAP_CONTRACTSEG_MIN = 0x0700,							///< Borne inférieure des champs 'Segment'
	MAP_CONTRACTSEG_ORIGINE = MAP_CONTRACTSEG_MIN,			///< Arret d'origine du segment
	MAP_CONTRACTSEG_DESTINATION,							///< Arret destination du segment
	MAP_CONTRACTSEG_VIA,									///< Arrêt via du segment
	MAP_CONTRACTSEG_LIGNEORIGINE,							///< Ligne d'origine du segment
	MAP_CONTRACTSEG_LIGNEDESTINATION,						///< Ligne de destination du segment
	MAP_CONTRACTSEG_PLANNINGHEBDO,							///< Planning hebdomadaire associé au segment
	MAP_CONTRACTSEG_DESTINATION_OU_VIA,						///< Arrêt de destination ou arrêt de via si on a un via
	MAP_CONTRACTSEG_DESTINATION_SI_VIA,						///< Arrêt de destination si l'on a un via

		// ajout Israel
	MAP_CONTRACTSEG_LIGNE,									///< Ligne
		// fin ajout Israel

	MAP_CONTRACTSEG_MAX,									///< Borne supérieure des champs 'Segment'

	// champs de la liste des événements spéciaux
	MAP_SPECIALEVENTLIST_MIN = 0x0800,							///< Borne inférieure des champs 'Liste d'évènements spéciaux'
	MAP_SPECIALEVENTLIST_EXPLOITANT = MAP_SPECIALEVENTLIST_MIN,	///< Identité de l'exploitant
	MAP_SPECIALEVENTLIST_SERIOUSNESS,							///< Niveau de sévérité
	MAP_SPECIALEVENTLIST_EVENTPOINTER,							///< Pointeur d'évènement spécial
	MAP_SPECIALEVENTLIST_NETWORKID,								///< Réseau
	MAP_SPECIALEVENTLIST_NULL,									///< Identifiant non significatif de liste d'événement spéciaux
	MAP_SPECIALEVENTLIST_MAX,									///< Borne supérieure des champs 'Liste d'évènements spéciaux'

	// champs des événements spéciaux
	MAP_SPECIALEVENT_MIN = 0x0900,							///< Borne inférieure des champs 'Evènements spéciaux'
	MAP_SPECIALEVENT_DATE = MAP_SPECIALEVENT_MIN,			///< Date de l'évènement spécial
	MAP_SPECIALEVENT_TIME,									///< Heure de l'évènement spécial
	MAP_SPECIALEVENT_RESULT,								///< Résultat
	MAP_SPECIALEVENT_EXPLOITANT,							///< Identité de l'exploitant
	MAP_SPECIALEVENT_VEHICULEID,							///< Identifiant du véhicule
	MAP_SPECIALEVENT_CONTRATPOINTER,						///< Référence vers le contrat concerné
	MAP_SPECIALEVENT_CODE,									///< Nature de l'évènement spécial
	MAP_SPECIALEVENT_LOCATIONID,							///< Arrêt tarifaire de l'évènement spécial: arrêt tarifaire de montée ou arrêt théorique de descente
	MAP_SPECIALEVENT_ROUTENUMBER,							///< Ligne de l'évènement spécial (la dernière montée)
	MAP_SPECIALEVENT_FIRSTJOURNEYDATE,						///< Date de la 1ère montée (correspondance)
	MAP_SPECIALEVENT_FIRSTJOURNEYTIME,						///< Heure de la 1ère montée (correspondance)
	MAP_SPECIALEVENT_TRONCONSENS,							///< Tronçon et sens du parcours
	MAP_SPECIALEVENT_SERIALNUMBER,							///< Numéro de série de l'évenement
	MAP_SPECIALEVENT_DEVICE,								///< Identificateur de l'equipement
	MAP_SPECIALEVENT_NULL,									///< Identifiant non significatif d'événement spéciaux
	MAP_SPECIALEVENT_MAX,									///< Borne supérieure des champs 'Evènements spéciaux'

	// champs des événements
	MAP_EVENT_MIN = 0x1000,									///< Borne inférieure des champs 'Evènements'
	MAP_EVENT_DATE = MAP_EVENT_MIN,							///< Date de l'évènement
	MAP_EVENT_TIME,											///< Heure de l'évènement
	MAP_EVENT_CODE,											///< Nature de l'évènement
	MAP_EVENT_RESULT,										///< Résultat
	MAP_EVENT_EXPLOITANT,									///< Identité de l'exploitant
	MAP_EVENT_LOCATIONID,									///< Arrêt tarifaire de l'évènement : arrêt tarifaire de montée ou arrêt théorique de descente
	MAP_EVENT_ROUTENUMBER,									///< Ligne de l'évènement (la dernière montée)
	MAP_EVENT_VEHICULEID,									///< Identifiant du véhicule
	MAP_EVENT_CONTRATPOINTER,								///< Référence vers le contrat concerné
	MAP_EVENT_FIRSTJOURNEYDATE,								///< Date de la 1ère montée (correspondance)
	MAP_EVENT_FIRSTJOURNEYTIME,								///< Heure de la 1ère montée (correspondance)
	MAP_EVENT_TRONCONSENS,									///< Tronçon et sens du parcours
	MAP_EVENT_MINUTEDELTA,									///< Nombre de minutes par rapport à la 1ere montée
	MAP_EVENT_SERIALNUMBER,									///< Numéro de série de l'événement
	MAP_EVENT_NULL,											///< Identifiant non significatif d'un événement
	MAP_EVENT_FIRSTJOURNEYLOCALISATION,						///< Arrêt de 1ère montée (correspondance)
	MAP_EVENT_SENS,											///< Sens du parcours
	MAP_EVENT_CORRESPONDANCECOUNT,							///< Nombre de correspondances
	MAP_EVENT_JOURNEYRUN,									///< Référence de la mission (course en cours)
	MAP_EVENT_TOTALJOURNEYS,								///< Nombre total de voyages autorisés
	MAP_EVENT_PRICEAMOUNT,									///< Montant en jeu lors de l'événement
		// ajout Israel
	MAP_EVENT_VERSION_NUMBER,								///< Numéro de version de la structure d'évènement
	MAP_EVENT_LINE,											///< Numéro de ligne où l'évènement a lieu
	MAP_EVENT_STATION,										///< Numéro d'arrêt sur l'EventLine où l'évènement a lieu
	MAP_EVENT_RUN_ID,										///< Numéro de la course
	MAP_EVENT_VEHICULE_COACH,								///< Coach identifier (1 to 16383) pour un lieu défini par les champs précédents
	MAP_EVENT_DEVICE,										///< Numéro d'équipement pour un lieu défini par les champs précédents
	MAP_EVENT_JOURNEY_INTERCHANGE,							///< Indique s'il s'agit d'une correspondance
	MAP_EVENT_PADDING,										///< champ de taille variable (avec position de fin fixe) rempli de 0
		// fin ajout Israel
	MAP_EVENT_VALIDITYPERIODENDDATE,						///< Dae de fin validite de la periode
	MAP_EVENT_VALIDITYTIMEFIRSTSTAMP,						///< Heure de premiere validation 
	MAP_EVENT_VALIDITYENDDATE,								///< Date de fin validite du contrat
	MAP_EVENT_VALIDITYENDTIME,								///< Heure de fin validation


	MAP_EVENT_MAX,											///< Borne supérieure des champs 'Evènement'

	// [Israel] champs définissant les ValidityLocation
	MAP_VALIDITY_LOCATION_MIN = 0x1100,						///< Borne inférieure des champs 'SpatialType'
	MAP_VALIDITY_LOCATION_ROUTES_SYSTEM,					///< Numéro de RoutesSystem où le contrat est valide
	MAP_VALIDITY_LOCATION_ZONES,							///< Bitmap des zones autorisées, pour un SpatialRoutesSystem donné
	MAP_VALIDITY_LOCATION_FARE_CODE,						///< FareCode pour un contrat, pour un SpatialRoutesSystem donné
	MAP_VALIDITY_LOCATION_LINES_NUMBER,						///< Nombre de lignes (ou groupe de lignes) dans la liste
	MAP_VALIDITY_LOCATION_RUN_TYPE,							///< Type de course autorisée
	MAP_VALIDITY_LOCATION_RUN_ID,							///< Numéro de course
	MAP_VALIDITY_LOCATION_VEHICLE_COACH,					///< 0 if irrelevant, else coach number(1 to 15)
	MAP_VALIDITY_LOCATION_SEAT,								///< Seat reference in the coach, 0 to 127. Coding according to the service provider
	MAP_VALIDITY_LOCATION_ROUTES_SYSTEM_FROM,				///< Numéro de RoutesSystem d'où la course part
	MAP_VALIDITY_LOCATION_ROUTES_SYSTEM_TO,					///< Numéro de RoutesSystem où la course arrive
	MAP_VALIDITY_LOCATION_ZONES_FROM,						///< Bitmap des zones autorisées d'où une course peut partir, pour un SpatialRoutesSystemFrom donné
	MAP_VALIDITY_LOCATION_ZONES_TO,							///< Bitmap des zones autorisées où une course arrive, pour un SpatialRoutesSystemFrom donné
	MAP_VALIDITY_LOCATION_PARKING_DATA_SIZE,				///< Taille en bits du ParkingData -12
	MAP_VALIDITY_LOCATION_PARKING_DATA,						///< A définir.. (12 à 75 bits)
	MAP_VALIDITY_LOCATION_CONTRACT_TYPE_ID,					///< Identifiant du type de contrat prédéfini (3 + 11 bits)
	MAP_VALIDITY_LOCATION_CONTRACT_TYPE_ID_ETT,				///< 3è digit de l'ETT (code défini dans le contrat) (3 bits)
	MAP_VALIDITY_LOCATION_CONTRACT_TYPE_ID_DEF,				///< définit l'interopérabilité (numéro faisant le lien tentre 2 ou plusieurs exploitants) (11 bits)			
	MAP_VALIDITY_LOCATION_SPATIAL_TYPE,						///< définition des zones pour les ContractValidityLocation,
	MAP_VALIDITY_LOCATION_MAX,								///< Borne supérieure des champs 'SpatialType'
};

enum MAPFIELDS_IDNEEDED {
	MAPNEEDED_NONEEDED			= 0x00,
	MAPNEEDED_NEEDEDTOINIT		= 0x01,
	MAPNEEDED_NEEDEDTOACCESS	= 0x02,
	MAPNEEDED_ALLNEEDED			= 0x03,
};

#endif /* __MAP_FIELD_DEF_H */