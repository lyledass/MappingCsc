#ifndef __MAP_FIELD_DEF_H
#define __MAP_FIELD_DEF_H

#include <TkCore/SmartCard/Bit.h>

#define FIELD_POS_UNFIXED	0xFFFF	///< Valeur pour une position de lecture/�criture d'un champ non fix� � l'avance
#define FIELD_CODEIMG_NONE	0x0L	///< Valeur d'un code image non significatif

// Position d'un champs
typedef struct _FIELD_POSITION {
	WORD	fileId;			///< Sid de fichier ou num�ro de bloc de lecture/�criture (vaut FIELD_POS_UNFIXED si non fixe)
	WORD	filePos;		///< Position en bit de lecture/�cirture dans le fichier ou le bloc (vaut FIELD_POS_UNFIXED si non fixe)
} FIELD_POSITION;

typedef FIELD_POSITION			*LPFIELD_POSITION;
typedef CONST FIELD_POSITION	*LPCFIELD_POSITION;

typedef struct _FIELD_PROPERTY {
	WORD				type;				///< Type du champ
	WORD				subType;			///< Sous type du champ
	WORD				len;				///< Longueur du champ en bits
	BOOL				bVirtual;			///< Indique si le champ est r�ellement encod� ou non sur la carte
	BOOL				bReadOnly;			///< Indique si le champ est en lecture seule dans le mapping
	DWORD				defVal;				///< Valeur par d�faut
	BOOL				bNeeded;			///< Indique si le champ est obligatoire (si le parent est un bitmap, le bit sera mont� m�me si le champ est nul)
	BOOL				bNegLogic;			///< Indique que la valeur du champ est g�r�e en logique invers�e (1 est encod� 0xFE)
	BOOL				bResetToMax;		///< Indique que l'on met le champ � sa valeur maximale lors d'un reset (et le bit du bimap associ� n'est pas mont�)

	BOOL				bBitLeftToRight;	///< On stocke la valeur du champ en sens inverse (soit : 5 (00101b) est encod� 10100b dans la carte)
	BOOL				bNotInBitmap;		///< Pour un champs d'un bitmap, indique si sa pr�sence n'est pas conditionn� par un bit. 
											///< Le champs est toujours pr�sent si le parent est activ� et la longueur du bitmap parent en bit est donc r�duite de 1...)
	BOOL				bValIsMsbPos;		///< La valeur du champ est la position du bit de poids fort dans (ex : 1010b donne 4, 100000b donne 6)
//	DWORD				data;				///< Donn�e sp�cifique selon le type (valeurs ci-dessous)
} FIELD_PROPERTY;

// Informations logiques li�es au champ
typedef struct _FIELD_LOGICALINFO {
	WORD	fieldId;	///< Identifiant du champ : permet de faire le lien 'info TPV' <-> 'champ du mapping'
						///< vaut MAP_NOID si le champ est non significatif pour le TPV
	WORD	instance;	///< Num�ro d'instance du champ
	DWORD	codeImg;	///< Code image du champ ou FIELD_CODEIMG_NONE si non significatif
} FIELD_LOGICALINFO;

typedef FIELD_LOGICALINFO			*LPFIELD_LOGICALINFO;
typedef CONST FIELD_LOGICALINFO		*LPCFIELD_LOGICALINFO;

// Conditions / valeurs par d�faut
typedef struct _FIELD_CONDITIONVAL {
	BYTE	logicalOp;		///< Op�rateur logique (ou, et)
	DWORD	unidTestField;	///< Identifiant unique d'un champ du mapping
	BYTE	compareOp;		///< Op�rateur de comparaison (=, <>, <, >, <=, >=)
	DWORD	compareVal;		///< Valeur de comparaison
	DWORD	val;			///< Valeur si les conditions sont respect�es
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

	DWORD				data;		///< Donn�e sp�cifique selon le type (valeurs ci-dessous)

	WORD				posCount;	///< Nombre de positions pour le champ
	LPFIELD_POSITION	posList;	///< Tableau de positions du champ dans la carte
} FIELD_DESCR;

typedef FIELD_DESCR			*LPFIELD_DESCR;
typedef CONST FIELD_DESCR	*LPCFIELD_DESCR;

#define FIELD_DESCR_SIZEOFHEADER	(sizeof(FIELD_DESCR) - sizeof(LPFIELD_POSITION))

// DEFINITION MAPPING VERSION 2
typedef struct _FIELD_DESCR_HEADER {
	DWORD				unidFieldId;		///< Identifiant unique d'un champ du mapping

	FIELD_PROPERTY		prop;				///< Propri�t� du champ
	FIELD_LOGICALINFO	logicalInfo;		///< Informations logiques (pour l'applicatif)

	WORD				posCount;			///< Nombre de positions pour le champ
	WORD				condCount;			///< Nombre de conditions associ�es au champ
} FIELD_DESCR_HEADER;


typedef struct _FIELD_DESCR_EX {
	FIELD_DESCR_HEADER		header;			///< Partie commune � tous les descripteur de champs

	LPFIELD_POSITION		posList;		///< Liste de positions du champ dans la carte
	LPFIELD_CONDITIONVAL	condDefValList;	///< Liste des conditions / valeur par d�faut associ�es
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
	BOOL				bVirtual;			///< Indique si le champ est r�ellement encod� ou non sur la carte
	BOOL				bReadOnly;			///< Indique si le champ est en lecture seule dans le mapping
	DWORD				defVal;				///< Valeur par d�faut
	DWORD				dNeeded;			///< Gestion du champ obligatoire 
											///< 0 = Non obligatoire sans r�activation
											///< 1 = Non obligatoire avec r�activation
											///< 2 = Obligatoire sans r�activation
											///< 3 = Obligatoire avec r�activation

	BOOL				bNegLogic;			///< Indique que la valeur du champ est g�r�e en logique invers�e (1 est encod� 0xFE)
	BOOL				bResetToMax;		///< Indique que l'on met le champ � sa valeur maximale lors d'un reset (et le bit du bimap associ� n'est pas mont�)

	BOOL				bBitLeftToRight;	///< On stocke la valeur du champ en sens inverse (soit : 5 (00101b) est encod� 10100b dans la carte)
	BOOL				bNotInBitmap;		///< Pour un champs d'un bitmap, indique si sa pr�sence n'est pas conditionn� par un bit. 
											///< Le champs est toujours pr�sent si le parent est activ� et la longueur du bitmap parent en bit est donc r�duite de 1...)
	BOOL				bValIsMsbPos;		///< La valeur du champ est la position du bit de poids fort dans (ex : 1010b donne 4, 100000b donne 6)		
	DWORD				data;				///< Donn�e sp�cifique selon le type (valeurs ci-dessous)
	BOOL				bAutoValueDisabled;	///< La valeur n'est pas calcul�e automatiquement (permet de d�sactiver le calcul automatique du nombre d'�l�ments d'une liste)
} FIELD_PROPERTY_V3 ;

typedef struct _FIELD_LOGICALINFO_V3 {
	WORD	fieldId;	///< Identifiant du champ : permet de faire le lien 'info TPV' <-> 'champ du mapping'
						///< vaut MAP_NOID si le champ est non significatif pour le TPV
	DWORD	instance;	///< Num�ro d'instance du champ
	DWORD	codeImg;	///< Code image du champ ou FIELD_CODEIMG_NONE si non significatif
} FIELD_LOGICALINFO_V3;

typedef FIELD_LOGICALINFO_V3			*LPFIELD_LOGICALINFO_V3;
typedef CONST FIELD_LOGICALINFO_V3		*LPCFIELD_LOGICALINFO_V3;

typedef struct _FIELD_DESCR_HEADER_V3 {
	DWORD					unidFieldId;		///< Identifiant unique d'un champ du mapping

	FIELD_PROPERTY_V3		prop;				///< Propri�t� du champ
	FIELD_LOGICALINFO_V3	logicalInfo;		///< Informations logiques (pour l'applicatif)

	WORD					posCount;			///< Nombre de positions pour le champ
	WORD					condCount;			///< Nombre de conditions associ�es au champ
} FIELD_DESCR_HEADER_V3;

typedef struct _FIELD_DESCR_EX_V3 {
	FIELD_DESCR_HEADER_V3		header;			///< Partie commune � tous les descripteur de champs

	LPFIELD_POSITION			posList;		///< Liste de positions du champ dans la carte
	LPFIELD_CONDITIONVAL		condDefValList;	///< Liste des conditions / valeur par d�faut associ�es
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
	MAPFILE_DEFVERSION_2	=	0x0200,				///< Version 2.00 de d�finition de mapping
	MAPFILE_DEFVERSION_201	=	0x0201,				///< Version 2.01 de d�finition de mapping : ajout de la propri�t� bNeeded
	MAPFILE_DEFVERSION_202	=	0x0202,				///< Version 2.02 de d�finition de mapping : ajout de la propri�t� bNullIsFull
	MAPFILE_DEFVERSION_203	=	0x0203,				///< Version 2.03 de d�finition de mapping : ajout de la propri�t� bResetToMax
	MAPFILE_DEFVERSION_204	=	0x0204,				///< Version 2.04 de d�finition de mapping : ajout des propri�t�s bRevBitOrder, bNotInBitmapet et bValIsMsbPos
//	MAPFILE_DEFVERSION_205	=	0x0205,				///< Version 2.05 de d�finition de mapping : ajout du CChampList2 (et nbMaxElmts)
	MAPFILE_DEFVERSION_300	=	0x0300,				///< Version 3.00 de d�finition de mapping : ajout du CChampList2 (et nbMaxElmts) + n� instance sur 32 bits
	MAPFILE_DEFVERSION_301	=	0x0301,				///< Version 3.01 de d�finition de mapping : ajout d'une propri�t� bAutoValueDisabled
	MAPFILE_DEFVERSION_302	=	0x0302,				///< Version 3.02 de d�finition de mapping : Gestion des diff�rents type d'obligation avec la propri�t� bNeeded
	MAPFILE_DEFVERSION_303	=	0x0303,				///< Version 3.03 de d�finition de mapping : Gestion des deux champs event drniere monte et periode de fin validit�
	MAPFILE_DEFVERSION_304	=	0x0304,				///< Version 3.04 de d�finition de mapping : Ajout de la Dfv dans Event

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
**	FIELD_DESCR.data contient les donn�es suivantes selon :
**	- si fieldId <> MAP_NOID (le type est forc�ment non essembliste),
**		data identifie de mani�re unique le regroupement logique de champs auquel appartient un champ. 
**		Ainsi, si un champ est dupliqu� dans le mapping, ceci permet d'en g�rer plusieurs ind�pendemments.
**		On peut donc d�finir plusieurs fois des champs contrats, profils...
**
**			LOWORD(data) : 'num�ro du groupe 1' + (100 * 'num�ro du groupe 2') + (10000 * 'num�ro du groupe 3')
**
**		ex : pour un champ du contrat 2, data = 0x0000002
**			 pour un champ du segment 2 du contrat 1, data = 0x000000C9	(201) 
**	
**		remarques : 
**			- au vu de la d�finition du data, un champ ne peut appartenir que � 3 sous groupes simultan�ments
**			- un identifiant de groupe prend un valeur de 0 � 99 inclus (sauf pour le 3eme qui va de 0 � 5)
**			- les num�ros de groupes doivent commencer � 0
**			- les num�ros de groupes doivent �tre cons�cutifs
**
**	- si type == TYPE_SWITCH, data indentifie le champ test�
**
**			LOWORD(data) : identifiant du champ
**			HIWORD(data) : valeur de regroupement
**
*/

typedef struct _FIELD_INSTANCE { 
	LPBIT		value;		///< Valeur du champ (tableau de bits)
	BOOL		modified;	///< Valeur du champ modifi�e ?
} FIELD_INSTANCE;

typedef FIELD_INSTANCE			*LPFIELD_INSTANCE;
typedef CONST FIELD_INSTANCE	*LPCFIELD_INSTANCE;

// les types de base de champs
enum FIELD_TYPE {
// TYPES UNITAIRE
	TYPE_NOMBRE = 0,		///< Type entier positif ou nul
	TYPE_BOOLEEN,			///< Type bool�en (vrai / faux)
	TYPE_DATE,				///< Type date, il existe plusieurs formats de date (voir FIELD_TYPE_DATE)
	TYPE_PLANNING,			///< Type planning hebdomadaire (2 bits par jours)
	TYPE_TRANSCARTE,		///< Type transcarte pour g�rer un num�ro transcarte
// TYPES ENSEMBLISTE
	TYPE_DATA,				///< Ensemble de champs 
	TYPE_BITMAP,			///< Ensemble de champs
	TYPE_SWITCH,			///< Ensemble conditionel
	TYPE_CASE,				///< Cas d'un ensemble conditionel
// TYPES UNITAIRE (suite)
	TYPE_TEXTE,				///< Type chaine de caract�res (4 caract�res maxi.)
	TYPE_CONST,				///< Type constante
// TYPES ENSEMBLISTE (RE)
	TYPE_LIST,				///< Type liste d'�l�ments
	TYPE_LIST2,				///< [Israel] Type liste d'�l�ments avec caract�re de fin
	TYPE_PADDING,			///< [Israel] Type entier de longueur ind�finie avec une position de fin fixe

	TYPE_COUNT,				///< Nombre total de types
};

// les diff�rentes sous types de dates
enum FIELD_TYPE_DATE {
	DATE_ISO = 0,			///< Date au format ISO - Nombre de jours depuis une ann�e de r�f�rence
	DATE_545,				///< Format : JJJJJmmmmAAAAA b avec AAAAA=nombre d'ann�es depuis 2000
	DATE_HEURE,				///< Date ou Heure selon la valeur (si < 600000 nombre de minutes depuis le d�but de l'ann�e, sinon nombre de jours depuis la d�cennie) (nb : les ann�es r�volues font toutes 366 jours)
	DATE_ROULANTE,			///< Nombre de jours de la d�cennie (nb : les ann�es r�volues font toutes 366 jours)
	DATE_C,					///< Nombre de jours depuis le 01/01/1997 (1545)
	DATE_F,					///< Date au format BCD (AAAA-mm-JJ h) (1545)

	HEURE_1,				///< Format : hhhhh-MMMMMMM-sssss b (1545) 
	HEURE_2,				///< Nombre de minutes depuis minuit (1545)
	DATE_MINUTE,			///< Nombre de minutes depuis le 1er janvier de l'ann�e en cours
	HEURE_2HALF,			///< Nombre de double minutes depuis minuit (Heure2 divis� par 2)
	HEURE_4,				///< Nombre de quart d'heure depuis minuit (Heure2 divis� par 4)

	DATE_CVF_DELTA,			///< Delta par rapport � la DFV de la carte
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
	MAP_ROOT,					///< Identifiant de la racine du mapping (seul idenfifiant associ� � un ensemble !)

	// champs des informations carte
	MAP_CARDINFO_MIN = 0x0100,						///< Borne inf�rieure des champs 'Information carte'
	MAP_CARDINFO_VERSIONNUMBER = MAP_CARDINFO_MIN,	///< Num�ro de version de l'application bill�tique
	MAP_CARDINFO_NETWORKID,							///< Code application (code ville)
	MAP_CARDINFO_APPISSUERID,						///< Id du cr�ateur de carte
	MAP_CARDINFO_APPENDDATE,						///< Dfv de la carte
//	MAP_CARDINFO_PAYMETHOD,
// 	MAP_CARDINFO_AUTHENTICATOR,
//	MAP_CARDINFO_SELECTLIST,
	MAP_CARDINFO_CARDTYPE,							///< Type de la carte
	MAP_CARDINFO_MAPVERSION,						///< Num�ro de version du mapping
	MAP_CARDINFO_CAUTION,							///< Montant de la caution pour la carte
	MAP_CARDINFO_CAUTIONDEVISE,						///< Code devise de la caution
	MAP_CARDINFO_INVALIDATEFLAG,					///< Flag d'invalidation de la carte
	MAP_CARDINFO_TELEMODIFFLAG,						///< Flag de t�l�modif de la carte						
	MAP_CARDINFO_CONTRACTKEY,						///< Clef du prochain contrat ajout�
	MAP_CARDINFO_CARDNUMBER,						///< Num�ro de s�rie de la carte
	MAP_CARDINFO_TRANSCARDNUMBER,					///< Num�ro 'transcarte' de la carte
	MAP_CARDINFO_PROFILCOUNT,						///< Nombre de profils dans la carte
	MAP_CARDINFO_BESTCONTRACTCOUNT,					///< Nombre de contrats dans la carte
	MAP_CARDINFO_BESTSPECIALEVENTCOUNT,				///< Nombre d'�v�nements sp�ciaux
	MAP_CARDINFO_ICCDATE,							///< Date d'�mission de la carte
	MAP_CARDINFO_NULL,								///< Identifiant non significatif de la carte
	MAP_CARDINFO_CARDGRAPHNUMBER,					///< Num�ro graphique de carte
	MAP_CARDINFO_MAX,								///< Borne sup�rieure des champs 'Information carte'

	// champs des informations porteur
	MAP_HOLDERINFO_MIN = 0x0200,					///< Borne inf�rieure des champs 'Information porteur'
	MAP_HOLDERINFO_IDNUMBER = MAP_HOLDERINFO_MIN,	///< Num�ro TPV du client
	MAP_HOLDERINFO_BIRTHDATE,						///< Date de naissance du client
	MAP_HOLDERINFO_CARDSTATUS,						///< Type de carte
	MAP_HOLDERINFO_COMMERCIALID,					///< Identification de l'utilisation possible de la carte dans le domaine d'interop�rabilit�
	MAP_HOLDERINFO_SALEDEVICE,						///< Identifiant du p�riph�rique de vente
	MAP_HOLDERINFO_AUTHENTICATOR,					///< Code de contr�le de l'int�grit� des donn�es
	MAP_HOLDERINFO_NULL,							///< Identifiant non significatif du porteur
		// ajout Israel
	MAP_HOLDERINFO_PAY_METHOD,						///< Allowed contracts payments methods

#pragma message("TODO : d�placer MAP_HOLDERINFO_PAY_METHOD en MAP_CARDINFO_PAY_METHOD \n")
	
	MAP_HOLDERINFO_LANGUAGE,						///< Holder main language
	MAP_HOLDERINFO_COMPANY,							///< Short holder company identifier
	MAP_HOLDERINFO_COMPANY_ID,						///< Holder identifier, within company
		// fin ajout Israel
	
	MAP_HOLDERINFO_MAX,								///< Borne sup�rieure des champs 'Information porteur'

	// champs des informations profil
	MAP_PROFIL_MIN = 0x0300,						///< Borne inf�rieure des champs 'Profil'
	MAP_PROFIL_NUMBER = MAP_PROFIL_MIN,				///< Code 'BRIO' du profil
	MAP_PROFIL_ENDDATE,								///< Dfv du profil
	MAP_PROFIL_BEGINDATE,							///< Ddv du profil
	MAP_PROFIL_NULL,								///< Identifiant non significatif d'un profil
	MAP_PROFIL_MAX,									///< Borne sup�rieure des champs 'Profil'

	// champs du r�sum� des contrats
	MAP_BESTCONTRACT_MIN = 0x0500,							///< Borne inf�rieure des champs 'BestContract'
	MAP_BESTCONTRACT_EXPLOITANT = MAP_BESTCONTRACT_MIN,		///< Code de l'exploitant associ� au contract
	MAP_BESTCONTRACT_TYPE,									///< Type de contrat
	MAP_BESTCONTRACT_PRIORITY,								///< Priorit� du contrat
	MAP_BESTCONTRACT_INSTANCEPOINTER,						///< Pointeur vers l'instance du contrat
	MAP_BESTCONTRACT_CONTRACTCODE,							///< Code 'BRIO' du contrat
	MAP_BESTCONTRACT_ZONE,									///< Code 'BRIO' de la zone associ�e au contrat
	MAP_BESTCONTRACT_NULL,									///< Identifiant non significatif d'un best contract
	MAP_BESTCONTRACT_MAX,									///< Borne sup�rieure des champs 'BestContract'

	// champs des contrats
	MAP_CONTRACT_MIN = 0x0600,								///< Borne inf�rieure des champs 'Contrat'
	MAP_CONTRACT_PROVIDER = MAP_CONTRACT_MIN,				///< Code de l'exploitant assurant le service
	MAP_CONTRACT_TARIFF,									///< Code 'BRIO' du contrat
	MAP_CONTRACT_SALEAGENT,									///< Code de l'exploitant de vente
	MAP_CONTRACT_SALEDEVICE,								///< Code du p�riph�rique de vente
	MAP_CONTRACT_TYPEMAPPING,								///< Num�ro de version du mapping du contrat
	MAP_CONTRACT_VALIDITYENDDATE,							///< Date de fin de validit� du contrat
	MAP_CONTRACT_STATUS,									///< Etat du contrat
	MAP_CONTRACT_GREYLIST,									///< Date de traitement en liste grise
	MAP_CONTRACT_CHRONO,									///< Chronologie
	MAP_CONTRACT_FLAGTELEMODIF,								///< Flag de t�l�modif du contrat
	// GeoOVD
	MAP_CONTRACT_JOURNEYORIGINE,							///< Code de l'origine du trajet
	MAP_CONTRACT_JOURNEYDESTINATION,						///< Code de la destination du trajet
	MAP_CONTRACT_JOURNEYVIA,								///< Code du via du trajet
	// NamedToken
	MAP_CONTRACT_TOKENNUMBER1,								///< Code 'BRIO' du jeton nom� 1
	MAP_CONTRACT_TOKENNUMBER2,								///< Code 'BRIO' du jeton nom� 2
	MAP_CONTRACT_TOKENNUMBER3,								///< Code 'BRIO' du jeton nom� 3
	MAP_CONTRACT_AUTOLOAD_DATESTART,						///< Date de d�but/reprise de l'autoload
	MAP_CONTRACT_AUTOLOAD_DATESTOP,							///< Date de fin/suspension de l'autoload
	// SoldX
	MAP_CONTRACT_SOLDX,										///< Solde de voyages ou unit�s
	MAP_CONTRACT_DEBITSOLDX,								///< Valeur du d�bit lors d'une validation
	// TPurse
	MAP_CONTRACT_TPURSE,									///< Montant du porte monnaie
	MAP_CONTRACT_DEBITTPURSE,								///< Valeur du d�bit lors d'une validation
	// Passenger
	MAP_CONTRACT_GROUP,										///< Nombre de passagers
	// Z Periodicity
	MAP_CONTRACT_ENDPERIOD,									///< Date de fin de la p�riode
	MAP_CONTRACT_SOLDPERIOD,								///< Solde de voyage dans la p�riode
	// GeoZonales
	MAP_CONTRACT_GEOZONE1,									///< Zone origine authoris�e
	MAP_CONTRACT_GEOZONE2,									///< Zone destination authoris�e
	MAP_CONTRACT_GEOZONE3,									///< Zone 3 authoris�e
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
	MAP_CONTRACT_VALIDITYSTARTDATE,							///< Date de d�but de validit� du contrat
	MAP_CONTRACT_VALIDITYENDTIME,							///< Heure de fin de validit� du contrat
	MAP_CONTRACT_TOKEN,										///< Nombre de jeton (pour un coupon simple)
	MAP_CONTRACT_INTERMODAL,								///< Gestion de l'intermodalit�
	
	// MAP_CONTRACT_PASSENGER_CLASS,
	// MAP_CONTRACT_VALIDITY_INFO,
	// MAP_CONTRACT_COEF,

	MAP_CONTRACT_CONTRACTKEY,								///< Clef du contrat
	MAP_CONTRACT_FLAGINVALIDATION,							///< Flag d'invalidation
	// MAP_CONTRACT_GROUPCORRESPONDANCE						///< Nombre de passagers en correspondance
	MAP_CONTRACT_TOKENZINITIAL,								///< Solde initial pour Z Voyages
	MAP_CONTRACT_TOKENZPERIODTYPE,							///< Type de p�riode pour Z Voyages
	MAP_CONTRACT_HASHPINCODE,								///< Hash PinCode pour le contrat d'habilitation
	MAP_CONTRACT_RIGHTS1,									///< Droits 1 pour le contrat d'habilitation
	MAP_CONTRACT_RIGHTS2,									///< Droits 2 pour le contrat d'habilitation
	MAP_CONTRACT_PDCSHIFT,									///< Num�ro de la course pour le contrat d'habilitation
	MAP_CONTRACT_AGENTNUMBER,								///< Num�ro de l'agent
	MAP_CONTRACT_PASSENGERCLASS,							///< Classe de service des voyageurs
	MAP_CONTRACT_SERIALNUMBER,								///< Num�ro de s�rie du contrat

	// champs des contrats sp�cifiques SNCF
	MAP_CONTRACT_SNCF_VALIDITYJOURNEYS,						///< Nombre de voyages autoris�s
	MAP_CONTRACT_SNCF_JOURNEYDISTANCE,						///< Distance
	MAP_CONTRACT_SNCF_VALIDITYDURATION,						///< Dur�e de validit�
	MAP_CONTRACT_SNCF_VALIDITYZONEORIGIN,					///< Zone de validit� d�finis � partir de l'origine
	MAP_CONTRACT_SNCF_VALIDITYZONEDESTINATION,				///< Zone de validit� d�finis � partir de la destination
	MAP_CONTRACT_SNCF_PAYMETHOD,							///< Code mode de paiement
	MAP_CONTRACT_SNCF_PRICEAMOUNT,							///< Montant total
	MAP_CONTRACT_SNCF_SALEDATE,								///< Date de vente
	MAP_CONTRACT_SNCF_SALETIME,								///< Heure de vente
	MAP_CONTRACT_SNCF_LINKEDCONTRACT,						///< Pointeur sur le contrat li�
	MAP_CONTRACT_SNCF_RECEIPTDELIVERED,						///< Indicateur justificatif �mis
	MAP_CONTRACT_SNCF_SCREEN,								///< Ecran de l'�tui portatif passif
	MAP_CONTRACT_SNCF_EXCEPTION,							///< Indicateur d'intervention du vendeur sur le tarif du produit
	MAP_CONTRACT_SNCF_PROXY,								///< Code mandataire
	MAP_CONTRACT_SNCF_PECTYPE,								///< Type de prise en charge
	MAP_CONTRACT_SNCF_PECRATE,								///< Taux de prise en charge
	MAP_CONTRACT_SNCF_PECAMOUNT,							///< Montant de prise en charge
	MAP_CONTRACT_SNCF_PECNUMBER,							///< Num�ro de contrat de prise en charge
	MAP_CONTRACT_SNCF_PROXYREVERSION,						///< Indicateur de prise en charge de la prestation associ�e
	MAP_CONTRACT_SNCF_VEHICLEALLOWED,						///< Type de transport utilis�
	MAP_CONTRACT_SNCF_LIMITEDATE,							///< Date maximale de premi�re validation
	MAP_CONTRACT_SNCF_VALIDITYZONE,							///< Zone(s) autoris�e(s)
	MAP_CONTRACT_SNCF_VALIDITYJOURNEYSLEFT,					///< Nombre de voyages restants

	// champs des contrats pour compatibilit� avec les anciens projets
	// (mappings non 1545 ou assimil�)
	MAP_CONTRACT_EVT_LOCATIONID,							///< Arr�t tarifaire de derni�re mont�e
	MAP_CONTRACT_EVT_ROUTENUMBER,							///< Ligne de derni�re mont�e
	MAP_CONTRACT_EVT_VEHICULEID,							///< Num�ro du v�hicule de derni�re mont�e
	MAP_CONTRACT_EVT_SENS,									///< Sens de la derni�re validation
	MAP_CONTRACT_EVT_CORSPD_GROUP,							///< Nombre de passagers en correspondance
	MAP_CONTRACT_EVT_CORSPD_LEVEL,							///< Nombre de correspondances effectu�es
	MAP_CONTRACT_EVT_CORSPD_DELTAMIN,						///< Minutes �coul�es entre la premi�re validation et la derni�re correspondance
	
	MAP_CONTRACT_CODEFAMILLE,								///< Code de la famille BRIO du champ
	MAP_CONTRACT_CODEMAPPING,								///< Num�ro du mapping BRIO du contrat

	// champs Aoste
	MAP_CONTRACT_LINECTRL,									///< Contr�le de la ligne sur un sens autoris�
	MAP_CONTRACT_STATUSPMT,									///< Etat de la validation
	MAP_CONTRACT_CPT1VALUE1,								///< Nombre de voyages pour la p�riode (Fid�lit�)
	MAP_CONTRACT_CPT1DATESTART,								///< Date de d�but de la p�riode (Fid�lit�)

	// champs ajout�s pour le Bas Rhin
	MAP_CONTRACT_VALIDITYSTARTTIME,							///< Heure de d�but de validit� du contrat
	MAP_CONTRACT_PERIODEIDENTITY,							///< Identifie la p�riode pour laquelle le d�compte de voyages par sous-p�riode s'applique
	MAP_CONTRACT_AUTHENTICATOR,								///< Code de contr�le de l'authenticit� des donn�es
	MAP_CONTRACT_NULL,										///< Identifiant non significatif d'un contrat

	// champs ajout�s pour Intercode 2
	MAP_CONTRACT_SOLDX_INITIAL,
	MAP_CONTRACT_TPURSE_INITIAL,
//	MAP_CONTRACT_GEOSECTION_INITIAL,
	// GeoSections
	MAP_CONTRACT_ZONES,										///< Nombre de sections autoris�es				
	MAP_CONTRACT_SOLDZONES,									///< Nombre de sections restantes
	MAP_CONTRACT_SOLDZONESINITIAL,							///< Nombre de sections initiales

	MAP_CONTRACT_HASCOUNTER,								///< Si le champ est pr�sent, le contrat dispose d'un compteur. La valeur du champ n'a pas d'importance
	
	// champs ajout�s pour Intercode 2
	MAP_CONTRACT_SOLDX_CONSUMED,							///< Nombre de voyages consomm�s

	MAP_CONTRAT_MAXOTP,										///< Max OTP : nombre de rechargement maximum r�alisable sur un support de type CTS		
	MAP_CONTRAT_OTPVALUE,									///< Nombre de rechargements effectu�s ou restant (NFO : a voir...)

		// ajout Israel
	dep_MAP_CONTRACT_SPATIAL_TYPE,							///< d�finition des zones pour les ContractValidityLocation,
#pragma message("TODO : � supprimer")
	MAP_CONTRACT_VALIDITY_LOCATION_END_LIST,				///< d�finition du caract�re de fin d'une ContractValidityLocationX
	MAP_CONTRACT_VERSION_NUMBER,							///< Num�ro de version de structure de contrat
	MAP_CONTRACT_TARIFF_ACCESS,								///< Type de contrat ( pp)			: acc�s autoris�s
	MAP_CONTRACT_TARIFF_COUNTER,							///< Type de contrat (   ccc)		: compteurs
	MAP_CONTRACT_TARIFF_NAME,								///< Type de contrat (      nnnnnn)	: nom de contrat
	MAP_CONTRACT_SALE_NUMBER_DAILY,							///< Num�ro de vente dans la journ�e pour l'�quipement
	MAP_CONTRACT_RESTRICT_CODE,								///< Restrictions g�n�rales
	MAP_CONTRACT_RESTRICT_DURATION,							///< Dur�e de la restriction d'un voyage
	MAP_CONTRACT_LINKED_PROFILE_CODE,						///< Code du profil qui a autoris� la vente de ce contrat

	MAP_CONTRACT_PADDING,									///< champ de taille variable (avec position de fin fixe) qu'on remplit d'une valeur (0 par exemple)
	MAP_CONTRACT_TARIFF_ISRAEL,								///< Type de contrat ( ppcccnnnnn )
	MAP_CONTRACT_REF_PRIORITY,								///< Priorit� du contrat (r�f�rence sur BestContract)

	MAP_CONTRACT_VALIDITY_DURATION,							///< dur�e de validity du contrct (  ddnnnnnn )
	MAP_CONTRACT_VALIDITY_DURATION_UNIT,					///< Unit�  ( dd )			[ 0=months, 1=weeks, 2=days, 3=half-hours ]
	MAP_CONTRACT_VALIDITY_DURATION_VALUE,					///< Valeur (   nnnnnn )
	MAP_CONTRACT_PERIOD_JOURNEYS,							///< Nombre de voyages par p�riode ( ppnnnnnn )
	MAP_CONTRACT_PERIOD_JOURNEYS_UNIT,						///< P�riode    ( pp ) [0=month, 1=week, 2=day]
	MAP_CONTRACT_PERIOD_JOURNEYS_VALUE,						///< Valeur max (   nnnnnn )
	MAP_CONTRACT_SALE_DATE,									///< Date de vente
	MAP_CONTRACT_RESTRICT_TIME_CODE,						///< D�finition des restrictions de p�riode

		// fin ajout Israel

	MAP_CONTRACT_MAX,										///< Borne sup�rieure des champs 'Contrat'

	// champs des segments
	MAP_CONTRACTSEG_MIN = 0x0700,							///< Borne inf�rieure des champs 'Segment'
	MAP_CONTRACTSEG_ORIGINE = MAP_CONTRACTSEG_MIN,			///< Arret d'origine du segment
	MAP_CONTRACTSEG_DESTINATION,							///< Arret destination du segment
	MAP_CONTRACTSEG_VIA,									///< Arr�t via du segment
	MAP_CONTRACTSEG_LIGNEORIGINE,							///< Ligne d'origine du segment
	MAP_CONTRACTSEG_LIGNEDESTINATION,						///< Ligne de destination du segment
	MAP_CONTRACTSEG_PLANNINGHEBDO,							///< Planning hebdomadaire associ� au segment
	MAP_CONTRACTSEG_DESTINATION_OU_VIA,						///< Arr�t de destination ou arr�t de via si on a un via
	MAP_CONTRACTSEG_DESTINATION_SI_VIA,						///< Arr�t de destination si l'on a un via

		// ajout Israel
	MAP_CONTRACTSEG_LIGNE,									///< Ligne
		// fin ajout Israel

	MAP_CONTRACTSEG_MAX,									///< Borne sup�rieure des champs 'Segment'

	// champs de la liste des �v�nements sp�ciaux
	MAP_SPECIALEVENTLIST_MIN = 0x0800,							///< Borne inf�rieure des champs 'Liste d'�v�nements sp�ciaux'
	MAP_SPECIALEVENTLIST_EXPLOITANT = MAP_SPECIALEVENTLIST_MIN,	///< Identit� de l'exploitant
	MAP_SPECIALEVENTLIST_SERIOUSNESS,							///< Niveau de s�v�rit�
	MAP_SPECIALEVENTLIST_EVENTPOINTER,							///< Pointeur d'�v�nement sp�cial
	MAP_SPECIALEVENTLIST_NETWORKID,								///< R�seau
	MAP_SPECIALEVENTLIST_NULL,									///< Identifiant non significatif de liste d'�v�nement sp�ciaux
	MAP_SPECIALEVENTLIST_MAX,									///< Borne sup�rieure des champs 'Liste d'�v�nements sp�ciaux'

	// champs des �v�nements sp�ciaux
	MAP_SPECIALEVENT_MIN = 0x0900,							///< Borne inf�rieure des champs 'Ev�nements sp�ciaux'
	MAP_SPECIALEVENT_DATE = MAP_SPECIALEVENT_MIN,			///< Date de l'�v�nement sp�cial
	MAP_SPECIALEVENT_TIME,									///< Heure de l'�v�nement sp�cial
	MAP_SPECIALEVENT_RESULT,								///< R�sultat
	MAP_SPECIALEVENT_EXPLOITANT,							///< Identit� de l'exploitant
	MAP_SPECIALEVENT_VEHICULEID,							///< Identifiant du v�hicule
	MAP_SPECIALEVENT_CONTRATPOINTER,						///< R�f�rence vers le contrat concern�
	MAP_SPECIALEVENT_CODE,									///< Nature de l'�v�nement sp�cial
	MAP_SPECIALEVENT_LOCATIONID,							///< Arr�t tarifaire de l'�v�nement sp�cial: arr�t tarifaire de mont�e ou arr�t th�orique de descente
	MAP_SPECIALEVENT_ROUTENUMBER,							///< Ligne de l'�v�nement sp�cial (la derni�re mont�e)
	MAP_SPECIALEVENT_FIRSTJOURNEYDATE,						///< Date de la 1�re mont�e (correspondance)
	MAP_SPECIALEVENT_FIRSTJOURNEYTIME,						///< Heure de la 1�re mont�e (correspondance)
	MAP_SPECIALEVENT_TRONCONSENS,							///< Tron�on et sens du parcours
	MAP_SPECIALEVENT_SERIALNUMBER,							///< Num�ro de s�rie de l'�venement
	MAP_SPECIALEVENT_DEVICE,								///< Identificateur de l'equipement
	MAP_SPECIALEVENT_NULL,									///< Identifiant non significatif d'�v�nement sp�ciaux
	MAP_SPECIALEVENT_MAX,									///< Borne sup�rieure des champs 'Ev�nements sp�ciaux'

	// champs des �v�nements
	MAP_EVENT_MIN = 0x1000,									///< Borne inf�rieure des champs 'Ev�nements'
	MAP_EVENT_DATE = MAP_EVENT_MIN,							///< Date de l'�v�nement
	MAP_EVENT_TIME,											///< Heure de l'�v�nement
	MAP_EVENT_CODE,											///< Nature de l'�v�nement
	MAP_EVENT_RESULT,										///< R�sultat
	MAP_EVENT_EXPLOITANT,									///< Identit� de l'exploitant
	MAP_EVENT_LOCATIONID,									///< Arr�t tarifaire de l'�v�nement : arr�t tarifaire de mont�e ou arr�t th�orique de descente
	MAP_EVENT_ROUTENUMBER,									///< Ligne de l'�v�nement (la derni�re mont�e)
	MAP_EVENT_VEHICULEID,									///< Identifiant du v�hicule
	MAP_EVENT_CONTRATPOINTER,								///< R�f�rence vers le contrat concern�
	MAP_EVENT_FIRSTJOURNEYDATE,								///< Date de la 1�re mont�e (correspondance)
	MAP_EVENT_FIRSTJOURNEYTIME,								///< Heure de la 1�re mont�e (correspondance)
	MAP_EVENT_TRONCONSENS,									///< Tron�on et sens du parcours
	MAP_EVENT_MINUTEDELTA,									///< Nombre de minutes par rapport � la 1ere mont�e
	MAP_EVENT_SERIALNUMBER,									///< Num�ro de s�rie de l'�v�nement
	MAP_EVENT_NULL,											///< Identifiant non significatif d'un �v�nement
	MAP_EVENT_FIRSTJOURNEYLOCALISATION,						///< Arr�t de 1�re mont�e (correspondance)
	MAP_EVENT_SENS,											///< Sens du parcours
	MAP_EVENT_CORRESPONDANCECOUNT,							///< Nombre de correspondances
	MAP_EVENT_JOURNEYRUN,									///< R�f�rence de la mission (course en cours)
	MAP_EVENT_TOTALJOURNEYS,								///< Nombre total de voyages autoris�s
	MAP_EVENT_PRICEAMOUNT,									///< Montant en jeu lors de l'�v�nement
		// ajout Israel
	MAP_EVENT_VERSION_NUMBER,								///< Num�ro de version de la structure d'�v�nement
	MAP_EVENT_LINE,											///< Num�ro de ligne o� l'�v�nement a lieu
	MAP_EVENT_STATION,										///< Num�ro d'arr�t sur l'EventLine o� l'�v�nement a lieu
	MAP_EVENT_RUN_ID,										///< Num�ro de la course
	MAP_EVENT_VEHICULE_COACH,								///< Coach identifier (1 to 16383) pour un lieu d�fini par les champs pr�c�dents
	MAP_EVENT_DEVICE,										///< Num�ro d'�quipement pour un lieu d�fini par les champs pr�c�dents
	MAP_EVENT_JOURNEY_INTERCHANGE,							///< Indique s'il s'agit d'une correspondance
	MAP_EVENT_PADDING,										///< champ de taille variable (avec position de fin fixe) rempli de 0
		// fin ajout Israel
	MAP_EVENT_VALIDITYPERIODENDDATE,						///< Dae de fin validite de la periode
	MAP_EVENT_VALIDITYTIMEFIRSTSTAMP,						///< Heure de premiere validation 
	MAP_EVENT_VALIDITYENDDATE,								///< Date de fin validite du contrat
	MAP_EVENT_VALIDITYENDTIME,								///< Heure de fin validation


	MAP_EVENT_MAX,											///< Borne sup�rieure des champs 'Ev�nement'

	// [Israel] champs d�finissant les ValidityLocation
	MAP_VALIDITY_LOCATION_MIN = 0x1100,						///< Borne inf�rieure des champs 'SpatialType'
	MAP_VALIDITY_LOCATION_ROUTES_SYSTEM,					///< Num�ro de RoutesSystem o� le contrat est valide
	MAP_VALIDITY_LOCATION_ZONES,							///< Bitmap des zones autoris�es, pour un SpatialRoutesSystem donn�
	MAP_VALIDITY_LOCATION_FARE_CODE,						///< FareCode pour un contrat, pour un SpatialRoutesSystem donn�
	MAP_VALIDITY_LOCATION_LINES_NUMBER,						///< Nombre de lignes (ou groupe de lignes) dans la liste
	MAP_VALIDITY_LOCATION_RUN_TYPE,							///< Type de course autoris�e
	MAP_VALIDITY_LOCATION_RUN_ID,							///< Num�ro de course
	MAP_VALIDITY_LOCATION_VEHICLE_COACH,					///< 0 if irrelevant, else coach number(1 to 15)
	MAP_VALIDITY_LOCATION_SEAT,								///< Seat reference in the coach, 0 to 127. Coding according to the service provider
	MAP_VALIDITY_LOCATION_ROUTES_SYSTEM_FROM,				///< Num�ro de RoutesSystem d'o� la course part
	MAP_VALIDITY_LOCATION_ROUTES_SYSTEM_TO,					///< Num�ro de RoutesSystem o� la course arrive
	MAP_VALIDITY_LOCATION_ZONES_FROM,						///< Bitmap des zones autoris�es d'o� une course peut partir, pour un SpatialRoutesSystemFrom donn�
	MAP_VALIDITY_LOCATION_ZONES_TO,							///< Bitmap des zones autoris�es o� une course arrive, pour un SpatialRoutesSystemFrom donn�
	MAP_VALIDITY_LOCATION_PARKING_DATA_SIZE,				///< Taille en bits du ParkingData -12
	MAP_VALIDITY_LOCATION_PARKING_DATA,						///< A d�finir.. (12 � 75 bits)
	MAP_VALIDITY_LOCATION_CONTRACT_TYPE_ID,					///< Identifiant du type de contrat pr�d�fini (3 + 11 bits)
	MAP_VALIDITY_LOCATION_CONTRACT_TYPE_ID_ETT,				///< 3� digit de l'ETT (code d�fini dans le contrat) (3 bits)
	MAP_VALIDITY_LOCATION_CONTRACT_TYPE_ID_DEF,				///< d�finit l'interop�rabilit� (num�ro faisant le lien tentre 2 ou plusieurs exploitants) (11 bits)			
	MAP_VALIDITY_LOCATION_SPATIAL_TYPE,						///< d�finition des zones pour les ContractValidityLocation,
	MAP_VALIDITY_LOCATION_MAX,								///< Borne sup�rieure des champs 'SpatialType'
};

enum MAPFIELDS_IDNEEDED {
	MAPNEEDED_NONEEDED			= 0x00,
	MAPNEEDED_NEEDEDTOINIT		= 0x01,
	MAPNEEDED_NEEDEDTOACCESS	= 0x02,
	MAPNEEDED_ALLNEEDED			= 0x03,
};

#endif /* __MAP_FIELD_DEF_H */