#ifndef __MAP_FIELD_DEF_H
#define __MAP_FIELD_DEF_H

#include <Bit.h>

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
	BOOL				bNeeded;			///< Indique si le champ est obligatoire
	BOOL				bNegLogic;			///< Indique que la valeur du champ est g�r�e en logique invers�e
	BOOL				bResetToMax;		///< Indique que l'on met le champ � sa valeur maximale lors d'un reset (et le bit du bimap associ� n'est pas mont�)
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

	WORD				posCount;	///< Nombre de positions pour le champs
	LPFIELD_POSITION	posList;	///< Tableau de positions du champ dans la carte
} FIELD_DESCR;

typedef FIELD_DESCR			*LPFIELD_DESCR;
typedef CONST FIELD_DESCR	*LPCFIELD_DESCR;

#define FIELD_DESCR_SIZEOFHEADER	(sizeof(FIELD_DESCR) - sizeof(LPFIELD_POSITION))

// DEFINITION MAPPING VERSION 2
typedef struct _FIELD_DESCR_HEADER {
	DWORD				unidFieldId;		///< Identifiant unique d'un champ du mapping

	FIELD_PROPERTY		prop;				///< Propri�t� du champs
	FIELD_LOGICALINFO	logicalInfo;		///< Informations logiques (pour l'applicatif)

	WORD				posCount;			///< Nombre de positions pour le champ
	WORD				condCount;			///< Nombre de conditions associ�es au champ
} FIELD_DESCR_HEADER;

typedef struct _FIELD_DESCR_EX {
	FIELD_DESCR_HEADER		header;			///< Partie commune � tous les descripteur de champs

	LPFIELD_POSITION		posList;		///< Liste de positions du champ dans la carte
	LPFIELD_CONDITIONVAL	condDefValList;	///< Liste des conditions / valeur par d�faut associ�es
} FIELD_DESCR_EX;

typedef FIELD_DESCR_EX			*LPFIELD_DESCR_EX;
typedef CONST FIELD_DESCR_EX	*LPCFIELD_DESCR_EX;

#define FIELD_DESCR_EX_SIZEOFHEADER		(sizeof(FIELD_DESCR_HEADER))


// ENTETE DE FICHIER MAPPING
#define MAPFILE_MAGICWORD		"MAPFILE"
#define MAPFILE_MAGICWORDLEN	7

enum {
	MAPFILE_DEFVERSION_1 = 0x0100,
	MAPFILE_DEFVERSION_2 = 0x0200,					///< Version 2.00 de d�finition de mapping
	MAPFILE_DEFVERSION_201 = 0x0201,				///< Version 2.01 de d�finition de mapping : ajout de la propri�t� bNeeded
	MAPFILE_DEFVERSION_202	=	0x0202,				///< Version 2.02 de d�finition de mapping : ajout de la propri�t� bNullIsFull

	MAPFILE_DEFVERSION_LAST = MAPFILE_DEFVERSION_202,
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
**	- si type == TYPE_SWITCH, data indentifie le champs test�
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

	TYPE_COUNT,				///< Nombre total de types
};

// les diff�rentes sous types de dates
enum FIELD_TYPE_DATE {
	DATE_ISO = 0,			///< Date au format ISO
	DATE_545,				///< Jour sur 5 bits, mois sur 4 bits et nombre d'ann�e depuis 2000 sur 4 bits
	DATE_HEURE,				///< Date ou Heure selon la valeur
	DATE_ROULANTE,			///< Date roulante
	DATE_C,					///< Nombre de jours depuis le 01/01/1997 (1545)
	DATE_F,					///< Date au format BCD (1545)
	HEURE_1,				///< (1545)
	HEURE_2,				///< (1545)
	DATE_MINUTE,			///< Date - nombre de minutes depuis le 1er janvier de l'ann�e en cours
	HEURE_2HALF,			///< Heure2 1545 divis� par 2

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
	MAP_CONTRACT_SOLDPERIODE,								///< Solde de voyage dans la p�riode
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
	// MAP_CONTRACT_ZONES,										
	// MAP_CONTRACT_SOLDZONES,
	// MAP_CONTRACT_COEF,

	MAP_CONTRACT_CONTRACTKEY,								///< Clef du contrat
	MAP_CONTRACT_FLAGINVALIDATION,							///< Flag d'invalidation
	// MAP_CONTRACT_GROUPCORESSPONDANCE						///< Nombre de passagers en correspondance
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
	MAP_CONTRACT_SUBPERIODID,								///< Identifie la sous-p�riode pour laquelle le d�compte de voyages par sous-p�riode s'applique (Date)
	MAP_CONTRACT_AUTHENTICATOR,								///< Code de contr�le de l'authenticit� des donn�es
	MAP_CONTRACT_NULL,										///< Identifiant non significatif d'un contrat

	MAP_CONTRACT_MAX,										///< Borne sup�rieure des champs 'Contrat'

	// champs des segments
	MAP_CONTRACTSEG_MIN = 0x0700,							///< Borne inf�rieure des champs 'Segment'
	MAP_CONTRACTSEG_ORIGINE = MAP_CONTRACTSEG_MIN,			///< Arret d'origine du segment
	MAP_CONTRACTSEG_DESTINATION,							///< Arret destination du segment
	MAP_CONTRACTSEG_VIA,									///< Arr�t via du segment
	MAP_CONTRACTSEG_LIGNEORIGINE,							///< Ligne d'origine du segment
	MAP_CONTRACTSEG_LIGNEDESTINATION,						///< Ligne de destination du segment
	MAP_CONTRACTSEG_PLANNINGHEBDO,							///< Planning hebdomadaire associ� au segment
	MAP_CONTRACTSEG_MAX,									///< Borne sup�rieure des champs 'Segment'

	// champs de la liste des �v�nements sp�ciaux
	MAP_SPECIALEVENTLIST_MIN = 0x0800,							///< Borne inf�rieure des champs 'Liste d'�v�nements sp�ciaux'
	MAP_SPECIALEVENTLIST_EXPLOITANT = MAP_SPECIALEVENTLIST_MIN,	///< Identit� de l'exploitant
	MAP_SPECIALEVENTLIST_SERIOUSNESS,							///< Niveau de s�v�rit�
	MAP_SPECIALEVENTLIST_EVENTPOINTER,							///< Pointeur d'�v�nement sp�cial
	MAP_SPECIALEVENTLIST_NETWORKID,								///< R�seau
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
	MAP_EVENT_MAX,											///< Borne sup�rieure des champs 'Ev�nement'
};

#endif /* __MAP_FIELD_DEF_H */