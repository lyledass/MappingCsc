#ifndef _MODULELOG_H_
#define _MODULELOG_H_

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LOG_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LOG_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef LOG_EXPORTS
#define LOG_API __declspec(dllexport)
#else
#define LOG_API __declspec(dllimport)
#endif

// Définition des informations de durée d'une alarme
enum LOG_ALARME_STATUT {
	LOG_ALARME_DUREE_PONCTUEL	= 0x0,	///< Alarme ponctuelle
	LOG_ALARME_DUREE_DEBUT		= 0x1,	///< Début d'alarme (alarme persistante)
	LOG_ALARME_DUREE_FIN		= 0x2,	///< Fin d'alarme (alarme persistante)
};

// Définition du statut général de l'équipement en fonction de l'alarme envoyée
// Le statut n'a d'intérêt que sur une alarme persistante (permet de définir un état d'équipement)
enum LOG_ALARME_ETAT {
	LOG_ALARME_STATUT_OK		= 0x0,	///< Équipement OK (alarme informative)
	LOG_ALARME_STATUT_DEGRADE	= 0x1,	///< Équipement en état dégradé
	LOG_ALARME_STATUT_KO		= 0x2,	///< Équipement HS
};

// Définition des niveaux de traces
enum LOG_NIVEAUX {
	LOG_NIVEAU_INACTIF = 0,		///< Inactif
	LOG_NIVEAU_URGENCE,			///< Urgence
	LOG_NIVEAU_ALERTE,			///< Alerte
	LOG_NIVEAU_CRITIQUE,		///< Critique
	LOG_NIVEAU_ERREUR,			///< Erreurs
	LOG_NIVEAU_AVERTISSEMENT,	///< Warning
	LOG_NIVEAU_REMARQUE,		///< Remarque
	LOG_NIVEAU_INFORMATION,		///< Information
	LOG_NIVEAU_DUMP,			///< Trace de performances (temps d'exécution du fragment de code)
	LOG_NIVEAU_DEBUG,			///< Debug (Tout)
	///< Niveaux supplémentaires définis par l'utilisateur
};

// Définition des catégories de traces
enum LOG_CATEGORIES {
	LOG_CATEGORIE_DEFAUT		= 0,	///< Catégories par défaut
	///< Catégories définies par l'utilisateur
	LOG_CATEGORIE_PERFORMANCES	= 1,	///< Traces de performances
	LOG_CATEGORIE_HYPERVISION	= 2,	///< Traces HPV : trame de vie + sortie socket pour envoi des alarmes
	LOG_CATEGORIE_IMPORTSCOL	= 3,	///< Traces import scolaire
	LOG_CATEGORIE_MASSENCODING	= 4,	///< Traces encodage de masse
	LOG_CATEGORIE_REQUEST		= 5,	///< Traces requête
	LOG_CATEGORIE_DB			= 6,	///< Traces db
};

// Code de trace par défaut
#define LOG_CODE_DEFAUT	0

// Définition des sorties de traces
#define LOG_SORTIE_FICHIER			0x00000001		///< Ecriture dans fichier
#define LOG_SORTIE_CONSOLE			0x00000002		///< Ecriture dans console
//BB
#define LOG_SORTIE_FICHIER_ACTIVITE	0x00000100		///< Ecriture dans fichier d'activité 
#define LOG_SORTIE_BASEDONNEES		0x00000004		///< Ecriture dans base de données
#define LOG_SORTIE_ROUTINEEXTERNE	0x00000008		///< Appel à des routines externes
#define LOG_SORTIE_FICHIERXML		0x00000010		///< Ecriture dans fichier XML
#define LOG_SORTIE_MESSAGEBOX		0x00000020		///< Ecriture dans une boite de dialog
#define LOG_SORTIE_SOCKET           0x00000040      ///< Ecriture dans socket
#define LOG_SORTIE_FICHIERXSL		0x00000080		///< Ecriture dans fichier XML (utilisant un fichier XSL pour hypervision)

#define LOG_SORTIE_TOUTES			0xFFFFFFFF		///< Toutes les sorties

// Type de création des fichiers de sortie
enum LOG_FICHIER_TYPECREATION {
	LOG_SORTIEFICHIER_TYPECREATION_UNIQUE = 0,
	LOG_SORTIEFICHIER_TYPECREATION_LANCEMENT,
	LOG_SORTIEFICHIER_TYPECREATION_PERIODIQUE,
};

// BB Type d'intervenant pour l'acquittement de la panne
enum LOG_INTERVENANT {
	LOG_INTERVENANT_M = 0,
	LOG_INTERVENANT_E,
	LOG_INTERVENANT_R,
	LOG_INTERVENANT_A,
};

// Information générée en sortie
#define LOG_SORTIEMASK_AUCUN					0x00000000			///< Aucun champs

#define LOG_SORTIEMASK_DATEHEURE				0x00000001			///< Date et heure courante
#define LOG_SORTIEMASK_NOMORDINATEUR			0x00000002			///< Nom de l'ordinateur
#define LOG_SORTIEMASK_NOMAPPLICATION			0x00000004			///< Nom de l'application (passé dans Init)
#define LOG_SORTIEMASK_NIVEAUMESSAGE			0x00000008			///< Niveau du message
#define LOG_SORTIEMASK_CATEGORIEMESSAGE			0x00000010			///< Catégorie du message
#define LOG_SORTIEMASK_CODEMESSAGE				0x00000020			///< Code du message
#define LOG_SORTIEMASK_LIBELLECOURTMESSAGE		0x00000040			///< Libellé court du message
#define LOG_SORTIEMASK_LIBELLELONGMESSAGE		0x00000080			///< Libellé long du message
#define LOG_SORTIEMASK_SOCIETE					0x00000100			///< Societe
#define LOG_SORTIEMASK_SYSTEMECODE				0x00000200			///< Systeme Code
#define LOG_SORTIEMASK_NUMEQUIPEMENT			0x00000400			///< Numéro de l'equipement
#define LOG_SORTIEMASK_NUMPROCESS				0x00000800			///< Numéro de process
#define LOG_SORTIEMASK_IDLOG					0x00001000			///< Identifiant du groupe de log
#define LOG_SORTIEMASK_NOMFICHIER				0x00002000			///< Nom du fichier de log
#define LOG_SORTIEMASK_THREAD					0x00004000			///< Log will contain thread id or [main] for thread which created log
#define LOG_SORTIEMASK_TIME						0x00008000			///< Log will contain only time, date will be written only once on separate line
//BB
#define LOG_SORTIEMASK_TIN						0x00010000			///< Type d'intervenant pour l'acquittement
#define LOG_SORTIEMASK_NMF						0x00020000			///< Nom du fichier paramètre chargé par ISGE

#define LOG_SORTIEMASK_ALARM_RESULT				0x00040000			///< Résultat de l'alarme :
																	///< partie haute = état (0x00=OK, 0x10=dégradé, 0x20=KO)
																	///< partie basse = durée (0x00=ponctuelle, 0x01=début, 0x02=fin)
#define LOG_SORTIEMASK_VERSION					0x00080000			///< Version de la trame (permet d'ajouter de nouveau champs)

//#define LOG_SORTIEMASK_NAMEFILE					0x00002000			///< Nom du fichier de log

#define LOG_SORTIEMASK_TOUS						0x7FFFFFFF			///< Tous les champs

// Définition des codes retour des fonctions
#define LOG_CODERETOUR_ERREUR_QUEUEEMPTY		-3
#define LOG_CODERETOUR_ERREUR_CHARGEMENTKLOG	-2
#define LOG_CODERETOUR_ERREUR					-1
#define LOG_CODERETOUR_OK						0
#define LOG_CODERETOUR_DEJAINITIALISE			1

// This classes are exported from the Log.dll
// Fonctions d'initialisation et de libération du module

#ifdef _UNICODE
	#define LogInit							LogInitW
	//BB
	#define LogInitActivite					LogInitActiviteW	
	#define LogStop							LogStopW
	#define LogInitSortieDefaut				LogInitSortieDefautW
	#define LogInitSortieFichier			LogInitSortieFichierW
	//BB	
	#define LogInitSortieFichierActivite	LogInitSortieFichierActiviteW
	#define LogInitSortieFichierXml			LogInitSortieFichierXmlW
	#define LogInitSortieFichierXsl			LogInitSortieFichierXslW
	#define LogInitSortieConsole			LogInitSortieConsoleW
	#define LogInitSortieMessageBox			LogInitSortieMessageBoxW
//	#define LogInitSortieBaseDonnees		LogInitSortieBaseDonneesW
//	#define LogInitSortieRoutineExterne		LogInitSortieRoutineExterneW
	#define LogActiveSortie					LogActiveSortieW
	#define LogInitSortieSocket				LogInitSortieSocketW
	#define LogEcrire						LogEcrireW
	#define LogEcrireActivite				LogEcrireActiviteW
	#define LogEcrire2						LogEcrire2W
	#define LogEcrireActivite2				LogEcrireActivite2W
	#define LogPurge						LogPurgeW
	#define LogArchive						LogArchiveW
	#define LogInitLife						LogInitLifeW
	#define LogInitCommand					LogInitCommandW
	#define LogUpdateParameters				LogUpdateParametersW
	#define LogGetParameters				LogGetParametersW
	#define LogZipRegisterFolder			LogZipRegisterFolderW
#else
	#define LogInit							LogInitA
	//BB
	#define LogInitActivite					LogInitActiviteA	
	#define LogStop							LogStopA
	#define LogInitSortieDefaut				LogInitSortieDefautA
	#define LogInitSortieFichier			LogInitSortieFichierA
	//BB	
	#define LogInitSortieFichierActivite	LogInitSortieFichierActiviteA
	#define LogInitSortieFichierXml			LogInitSortieFichierXmlA
	#define LogInitSortieFichierXsl			LogInitSortieFichierXslA
	#define LogInitSortieConsole			LogInitSortieConsoleA
	#define LogInitSortieMessageBox			LogInitSortieMessageBoxA
//	#define LogInitSortieBaseDonnees		LogInitSortieBaseDonneesA
//	#define LogInitSortieRoutineExterne		LogInitSortieRoutineExterneA
	#define LogInitSortieSocket				LogInitSortieSocketA
	#define LogActiveSortie					LogActiveSortieA
	#define LogEcrire						LogEcrireA
	#define LogEcrireActivite				LogEcrireActiviteA
	#define LogEcrire2						LogEcrire2A
	#define LogEcrireActivite2				LogEcrireActivite2A
	#define LogPurge						LogPurgeA
	#define LogArchive						LogArchiveA
	#define LogInitLife						LogInitLifeA
	#define LogInitCommand					LogInitCommandA
	#define LogUpdateParameters				LogUpdateParametersA
	#define LogGetParameters				LogGetParametersA
	#define LogZipRegisterFolder			LogZipRegisterFolderA
#endif

LOG_API INT32 __stdcall	LogInitW (LPCWSTR szNomAppli,
								  WORD wNumEquipement,
								  WORD wNumSociete,
								  DWORD dwSystemCode);

LOG_API INT32 __stdcall LogInitA (LPCSTR szNomAppli,
								  WORD wNumEquipement,
								  WORD wNumSociete,
								  DWORD dwSystemCode);

//BB
LOG_API INT32 __stdcall	LogInitActiviteW (LPCWSTR szNomAppli,
										WORD wNumEquipement,
										WORD wNumSociete,
										DWORD dwSystemCode,
										WORD wNumIdConcentrateur);

LOG_API INT32 __stdcall LogInitActiviteA (LPCSTR szNomAppli,
										WORD wNumEquipement,
										WORD wNumSociete,
										DWORD dwSystemCode,
										WORD wNumIdConcentrateur);
//fin BB

LOG_API VOID __stdcall  LogStopW (DWORD dwIdLog);

LOG_API VOID __stdcall  LogStopA (DWORD dwIdLog);

// Fonctions d'initialisation des sorties du module
//04/06/07: changement du type iTypeSortie; BYTE->DWORD
LOG_API INT32 __stdcall LogInitSortieDefautW(DWORD dwIdLog,
											 BYTE  iNiveau = LOG_NIVEAU_AVERTISSEMENT,
											 DWORD  iTypeSortie = LOG_SORTIE_FICHIER, 
											 BYTE  iCategorie = LOG_CATEGORIE_DEFAUT, 
											 BOOL  bActif = TRUE);
//04/06/07: changement du type iTypeSortie; BYTE->DWORD
LOG_API INT32 __stdcall LogInitSortieDefautA(DWORD dwIdLog,
											 BYTE  iNiveau = LOG_NIVEAU_AVERTISSEMENT,
											 DWORD  iTypeSortie = LOG_SORTIE_FICHIER, 
											 BYTE  iCategorie = LOG_CATEGORIE_DEFAUT, 
											 BOOL  bActif = TRUE);

LOG_API INT32 __stdcall LogInitSortieFichierW(DWORD		dwIdLog,
											  BYTE		iCategorie, 
											  BOOL		bActif, 
											  BYTE		iNiveau,
											  DWORD		iMaskChamps,
											  BOOL		bPrefixeChamps, 
											  BYTE		iTypeCreation,
											  DWORD		iPeriodeRenouvellement,
											  LPCWSTR	szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieFichierA(DWORD   dwIdLog,
											  BYTE    iCategorie, 
											  BOOL    bActif, 
											  BYTE    iNiveau,
											  DWORD   iMaskChamps,
											  BOOL    bPrefixeChamps, 
											  BYTE    iTypeCreation,
											  DWORD   iPeriodeRenouvellement,
											  LPCSTR szRepertoireFichier);
//BB
LOG_API INT32 __stdcall LogInitSortieFichierActiviteW(DWORD		dwIdLog,
													  BOOL		bActif, 
													  BYTE		iNiveau,
													  DWORD		iPeriodeRenouvellement,
													  LPCWSTR	szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieFichierActiviteA(DWORD   dwIdLog,
													  BOOL    bActif, 
													  BYTE    iNiveau,
													  DWORD   iMaskChamps,
													  LPCSTR szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieFichierXmlW(DWORD		dwIdLog,
												 BYTE		iCategorie, 
												 BOOL		bActif, 
												 BYTE		iNiveau,
												 DWORD		iMaskChamps,
												 BYTE		iTypeCreation,
												 DWORD		iPeriodeRenouvellement,
												 LPCWSTR	szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieFichierXmlA(DWORD		dwIdLog,
												 BYTE		iCategorie, 
												 BOOL		bActif, 
												 BYTE		iNiveau,
												 DWORD		iMaskChamps,
												 BYTE		iTypeCreation,
												 DWORD		iPeriodeRenouvellement,
												 LPCSTR		szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieFichierXslW(DWORD   dwIdLog,
												 BYTE    iCategorie, 
												 BOOL    bActif, 
												 BYTE    iNiveau,
												 DWORD   iMaskChamps,
												 BYTE    iTypeCreation,
												 DWORD   iPeriodeRenouvellement,
												 LPCWSTR szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieFichierXslA(DWORD   dwIdLog,
												 BYTE    iCategorie, 
												 BOOL    bActif, 
												 BYTE    iNiveau,
												 DWORD   iMaskChamps,
												 BYTE    iTypeCreation,
												 DWORD   iPeriodeRenouvellement,
												 LPCSTR	szRepertoireFichier);

LOG_API INT32 __stdcall LogInitSortieConsoleW(DWORD  dwIdLog,
											  BYTE   iCategorie, 
											  BOOL   bActif, 
											  BYTE   iNiveau,
											  DWORD  iMaskChamps,
											  BOOL   bPrefixeChamps);

LOG_API INT32 __stdcall LogInitSortieConsoleA  (DWORD  dwIdLog,
												BYTE   iCategorie, 
												BOOL   bActif, 
												BYTE   iNiveau,
												DWORD  iMaskChamps,
												BOOL   bPrefixeChamps);

LOG_API INT32 __stdcall LogInitSortieMessageBoxW    (DWORD dwIdLog,
													 BYTE  iCategorie, 
													 BOOL  bActif,
													 BYTE  iNiveau,
													 HWND  hParent);

LOG_API INT32 __stdcall LogInitSortieMessageBoxA	(DWORD dwIdLog,
													 BYTE  iCategorie, 
													 BOOL  bActif,
													 BYTE  iNiveau,
													 HWND  hParent);

LOG_API INT32 __stdcall LogInitSortieSocketW(DWORD   dwIdLog,
											 BYTE    iCategorie, 
											 BOOL    bActif,
											 BYTE    iNiveau,
											 LPCWSTR szHostName,
											 WORD    iPortId);

LOG_API INT32 __stdcall LogInitSortieSocketA(DWORD  dwIdLog,
											 BYTE   iCategorie, 
											 BOOL   bActif,
											 BYTE   iNiveau,
											 LPCSTR	szHostName,
											 WORD   iPortId);


// Activation/desactivation des sorties
LOG_API INT32 __stdcall LogActiveSortieW	(DWORD dwIdLog,
											 BOOL bActive, 
											 BYTE iTypeSortie, 
											 BYTE iCategorie);

LOG_API INT32 __stdcall LogActiveSortieA	(DWORD dwIdLog,
											 BOOL bActive, 
											 BYTE iTypeSortie, 
											 BYTE iCategorie);

// Fonctions d'écriture
LOG_API INT32 __stdcall LogEcrireW			(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCWSTR szLibelleCourt,
											 LPCWSTR szLibelleLong);

LOG_API INT32 __stdcall LogEcrireA			(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCSTR szLibelleCourt,
											 LPCSTR szLibelleLong);

//BB
LOG_API INT32 __stdcall LogEcrireActiviteW	(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCWSTR szLibelleLong,
											 char cTIN,
											 LPCWSTR szNomFichierParam);

LOG_API INT32 __stdcall LogEcrireActiviteA	(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCSTR szLibelleLong,
											 char cTIN,
											 LPCSTR szNomFichierParam);
//fin BB

LOG_API INT32 __stdcall LogEcrire2W			(DWORD		dwIdLog,
											 BYTE		iNiveau,
											 BYTE		iCategorie,
											 INT32		iCode,
											 BYTE		iStatutAlarme,
											 BYTE		iEtatAlarme,
											 LPCWSTR	szLibelleCourt,
											 LPCWSTR	szLibelleLong);

LOG_API INT32 __stdcall LogEcrire2A			(DWORD		dwIdLog,
											 BYTE		iNiveau,
											 BYTE		iCategorie,
											 INT32		iCode,
											 BYTE		iStatutAlarme,
											 BYTE		iEtatAlarme,
											 LPCSTR 	szLibelleCourt,
											 LPCSTR 	szLibelleLong);

LOG_API INT32 __stdcall LogEcrireActivite2W	(DWORD		dwIdLog,
											 BYTE		iNiveau,
											 BYTE		iCategorie,
											 INT32		iCode,
											 BYTE		iStatutAlarme,
											 BYTE		iEtatAlarme,
											 LPCWSTR	szLibelleLong,
											 char		cTIN,
											 LPCWSTR	szNomFichierParam);

LOG_API INT32 __stdcall LogEcrireActivite2A	(DWORD		dwIdLog,
											 BYTE		iNiveau,
											 BYTE		iCategorie,
											 INT32		iCode,
											 BYTE		iStatutAlarme,
											 BYTE		iEtatAlarme,
											 LPCSTR		szLibelleLong,
											 char		cTIN,
											 LPCSTR		szNomFichierParam);

// Fonctions de purge
LOG_API INT32 __stdcall LogPurgeW			(DWORD dwIdLog,
											 DWORD dwDureeConservationLog,
											 DWORD dwTypeSorties);

LOG_API INT32 __stdcall LogPurgeA			(DWORD dwIdLog,
											 DWORD dwDureeConservationLog,
											 DWORD dwTypeSorties);

// Fonctions de archive
LOG_API INT32 __stdcall LogArchiveW			(DWORD   dwIdLog,
											 DWORD   dwDureeArchivageLog,
											 DWORD   dwTypeSorties,
											 LPCWSTR szNomRepertoireArchive);

LOG_API INT32 __stdcall LogArchiveA			(DWORD  dwIdLog,
											 DWORD  dwDureeArchivageLog,
											 DWORD  dwTypeSorties,
											 LPCSTR	szNomRepertoireArchive);

// Fonctions d'initialisation de la dll de vie
LOG_API INT32 __stdcall LogInitLifeW		(DWORD	 dwIdLog, 
											 WORD    wPort,
											 LPCWSTR szHostname,
											 LONG	 lProtocole);

LOG_API INT32 __stdcall LogInitLifeA		(DWORD	 dwIdLog, 
											 WORD    wPort,
											 LPCSTR szHostname,
											 LONG	lProtocole);

// Fonctions d'initialisation de la dll de commande
LOG_API INT32 __stdcall LogInitCommandW		(DWORD		dwIdLog, 
											 WORD		wPort,
											 LPCWSTR	szHostname,
											 LONG		lProtocol,
											 LPCWSTR	szPathFile);

LOG_API INT32 __stdcall LogInitCommandA		(DWORD		dwIdLog, 
											 WORD		wPort,
											 LPCSTR		szHostname,
											 LONG		lProtocol,
											 LPCSTR		szPathFile);

LOG_API INT32 __stdcall LogReadCommandA		(DWORD		dwIdLog,
											 LPSTR		szCommand,
											 size_t		uiCommand);

LOG_API INT32 __stdcall LogUpdateParametersW(
												DWORD		dwIdLog,
												BYTE		iCategorie,
												DWORD		iTypeSortie,
												LPCWSTR		szParamName,
												LPCWSTR		szValue
												);

LOG_API INT32 __stdcall LogUpdateParametersA(
												DWORD		dwIdLog, 
												BYTE		iCategorie, 
												DWORD		iTypeSortie,
												LPCSTR		szParamName, 
												LPCSTR		szValue
												);

LOG_API INT32 __stdcall LogGetParametersA(
												DWORD		dwIdLog,
												BYTE		iCategorie,
												DWORD		iTypeSortie,
												LPCSTR		szParamName,
												LPSTR		szValue,
												int			iValueBufferSize
												);

LOG_API INT32 __stdcall LogGetParametersW(
												DWORD		dwIdLog,
												BYTE		iCategorie,
												DWORD		iTypeSortie,
												LPCWSTR		szParamName,
												LPWSTR		szValue,
												int			iValueBufferSize
												);

LOG_API void __stdcall LogZipStart(			
												DWORD		dwLogAgeInHours,
												DWORD		dwZipSizeThreshold
												);

LOG_API void __stdcall LogZipStop(
												);

LOG_API void __stdcall LogZipRegisterFolderW(	
												LPCWSTR		szFolder,
												LPCWSTR		wszZipName
												);

LOG_API void __stdcall LogZipRegisterFolderA(	
												LPCSTR		szFolder,
												LPCWSTR		wszZipName
												);

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//
// Prototype des fonctions exportées
//
#define LOGNAME__LogInitW					"LogInitW"
typedef INT32 (__stdcall *LOGPROC__LogInitW) (LPCWSTR szNomAppli,
								  WORD wNumEquipement,
								  WORD wNumSociete,
								  DWORD dwSystemCode);

#define LOGNAME__LogInitA					"LogInitA"
typedef INT32 (_stdcall *LOGPROC__LogInitA) (LPCSTR szNomAppli,
								  WORD wNumEquipement,
								  WORD wNumSociete,
								  DWORD dwSystemCode);

#define LOGNAME__LogInitActiviteW			"LogInitActiviteW"
typedef INT32 (_stdcall *LOGPROC__LogInitActiviteW) (LPCWSTR szNomAppli,
										WORD wNumEquipement,
										WORD wNumSociete,
										DWORD dwSystemCode,
										WORD wNumIdConcentrateur);

#define LOGNAME__LogInitActiviteA			"LogInitActiviteA"
typedef INT32 (_stdcall *LOGPROC__LogInitActiviteA) (LPCSTR szNomAppli,
										WORD wNumEquipement,
										WORD wNumSociete,
										DWORD dwSystemCode,
										WORD wNumIdConcentrateur);
#define LOGNAME__LogStopW					"LogStopW"
typedef VOID (_stdcall *LOGPROC__LogStopW) (DWORD dwIdLog);

#define LOGNAME__LogStopA					"LogStopA"
typedef VOID (_stdcall *LOGPROC__LogStopA) (DWORD dwIdLog);

#define LOGNAME__LogInitSortieDefautW		"LogInitSortieDefautW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieDefautW) (DWORD dwIdLog,
											 BYTE  iNiveau,
											 DWORD  iTypeSortie, 
											 BYTE  iCategorie, 
											 BOOL  bActif);

#define LOGNAME__LogInitSortieDefautA		"LogInitSortieDefautA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieDefautA) (DWORD dwIdLog,
											 BYTE  iNiveau,
											 DWORD  iTypeSortie, 
											 BYTE  iCategorie, 
											 BOOL  bActif);

#define LOGNAME__LogInitSortieFichierW		"LogInitSortieFichierW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierW) (DWORD		dwIdLog,
											  BYTE		iCategorie, 
											  BOOL		bActif, 
											  BYTE		iNiveau,
											  DWORD		iMaskChamps,
											  BOOL		bPrefixeChamps, 
											  BYTE		iTypeCreation,
											  DWORD		iPeriodeRenouvellement,
											  LPCWSTR	szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierA		"LogInitSortieFichierA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierA) (DWORD   dwIdLog,
											  BYTE    iCategorie, 
											  BOOL    bActif, 
											  BYTE    iNiveau,
											  DWORD   iMaskChamps,
											  BOOL    bPrefixeChamps, 
											  BYTE    iTypeCreation,
											  DWORD   iPeriodeRenouvellement,
											  LPCSTR szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierActiviteW		"LogInitSortieFichierActiviteW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierActiviteW) (DWORD		dwIdLog,
													  BOOL		bActif, 
													  BYTE		iNiveau,
													  DWORD		iPeriodeRenouvellement,
													  LPCWSTR	szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierActiviteA		"LogInitSortieFichierActiviteA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierActiviteA) (DWORD   dwIdLog,
													  BOOL    bActif, 
													  BYTE    iNiveau,
													  DWORD   iMaskChamps,
													  LPCSTR szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierXmlW	"LogInitSortieFichierXmlW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierXmlW) (DWORD		dwIdLog,
												 BYTE		iCategorie, 
												 BOOL		bActif, 
												 BYTE		iNiveau,
												 DWORD		iMaskChamps,
												 BYTE		iTypeCreation,
												 DWORD		iPeriodeRenouvellement,
												 LPCWSTR	szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierXmlA	"LogInitSortieFichierXmlA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierXmlA) (DWORD		dwIdLog,
												 BYTE		iCategorie, 
												 BOOL		bActif, 
												 BYTE		iNiveau,
												 DWORD		iMaskChamps,
												 BYTE		iTypeCreation,
												 DWORD		iPeriodeRenouvellement,
												 LPCSTR		szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierXslW	"LogInitSortieFichierXslW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierXslW) (DWORD   dwIdLog,
												 BYTE    iCategorie, 
												 BOOL    bActif, 
												 BYTE    iNiveau,
												 DWORD   iMaskChamps,
												 BYTE    iTypeCreation,
												 DWORD   iPeriodeRenouvellement,
												 LPCWSTR szRepertoireFichier);

#define LOGNAME__LogInitSortieFichierXslA	"LogInitSortieFichierXslA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieFichierXslA) (DWORD   dwIdLog,
												 BYTE    iCategorie, 
												 BOOL    bActif, 
												 BYTE    iNiveau,
												 DWORD   iMaskChamps,
												 BYTE    iTypeCreation,
												 DWORD   iPeriodeRenouvellement,
												 LPCSTR	szRepertoireFichier);

#define LOGNAME__LogInitSortieConsoleW		"LogInitSortieConsoleW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieConsoleW) (DWORD  dwIdLog,
											  BYTE   iCategorie, 
											  BOOL   bActif, 
											  BYTE   iNiveau,
											  DWORD  iMaskChamps,
											  BOOL   bPrefixeChamps);

#define LOGNAME__LogInitSortieConsoleA		"LogInitSortieConsoleA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieConsoleA)  (DWORD  dwIdLog,
												BYTE   iCategorie, 
												BOOL   bActif, 
												BYTE   iNiveau,
												DWORD  iMaskChamps,
												BOOL   bPrefixeChamps);

#define LOGNAME__LogInitSortieMessageBoxW	"LogInitSortieMessageBoxW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieMessageBoxW)    (DWORD dwIdLog,
													 BYTE  iCategorie, 
													 BOOL  bActif,
													 BYTE  iNiveau,
													 HWND  hParent);

#define LOGNAME__LogInitSortieMessageBoxA	"LogInitSortieMessageBoxA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieMessageBoxA)	(DWORD dwIdLog,
													 BYTE  iCategorie, 
													 BOOL  bActif,
													 BYTE  iNiveau,
													 HWND  hParent);

#define LOGNAME__LogInitSortieSocketW		"LogInitSortieSocketW"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieSocketW) (DWORD   dwIdLog,
											 BYTE    iCategorie, 
											 BOOL    bActif,
											 BYTE    iNiveau,
											 LPCWSTR szHostName,
											 WORD    iPortId);

#define LOGNAME__LogInitSortieSocketA		"LogInitSortieSocketA"
typedef INT32 (_stdcall *LOGPROC__LogInitSortieSocketA) (DWORD  dwIdLog,
											 BYTE   iCategorie, 
											 BOOL   bActif,
											 BYTE   iNiveau,
											 LPCSTR	szHostName,
											 WORD   iPortId);

// Activation/desactivation des sorties
#define LOGNAME__LogActiveSortieW			"LogActiveSortieW"
typedef INT32 (_stdcall *LOGPROC__LogActiveSortieW)	(DWORD dwIdLog,
											 BOOL bActive, 
											 BYTE iTypeSortie, 
											 BYTE iCategorie);

#define LOGNAME__LogActiveSortieA			"LogActiveSortieA"
typedef INT32 (_stdcall *LOGPROC__LogActiveSortieA)	(DWORD dwIdLog,
											 BOOL bActive, 
											 BYTE iTypeSortie, 
											 BYTE iCategorie);

// Fonctions d'écriture
#define LOGNAME__LogEcrireW					"LogEcrireW"
typedef INT32 (_stdcall *LOGPROC__LogEcrireW)			(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCWSTR szLibelleCourt,
											 LPCWSTR szLibelleLong);

#define LOGNAME__LogEcrireA					"LogEcrireA"
typedef INT32 (_stdcall *LOGPROC__LogEcrireA)			(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCSTR szLibelleCourt,
											 LPCSTR szLibelleLong);

#define LOGNAME__LogEcrireActiviteW			"LogEcrireActiviteW"
typedef INT32 (_stdcall *LOGPROC__LogEcrireActiviteW)	(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCWSTR szLibelleLong,
											 char cTIN,
											 LPCWSTR szNomFichierParam);

#define LOGNAME__LogEcrireActiviteA			"LogEcrireActiviteA"
typedef INT32 (_stdcall *LOGPROC__LogEcrireActiviteA)	(DWORD	dwIdLog,
											 BYTE	iNiveau,
											 BYTE	iCategorie,
											 INT32	iCode,
											 LPCSTR szLibelleLong,
											 char cTIN,
											 LPCSTR szNomFichierParam);

// CBO : Début ajout
// Fonctions d'écriture (avec "Result" intégré)
#define LOGNAME__LogEcrire2W				"LogEcrire2W"
typedef INT32 (_stdcall *LOGPROC__LogEcrire2W)
											(DWORD			dwIdLog,
											 BYTE			iNiveau,
											 BYTE			iCategorie,
											 INT32			iCode,
											 BYTE			iStatutAlarme,
											 BYTE			iEtatAlarme,
											 LPCWSTR		szLibelleCourt,
											 LPCWSTR		szLibelleLong);

#define LOGNAME__LogEcrire2A				"LogEcrire2A"
typedef INT32 (_stdcall *LOGPROC__LogEcrire2A)	
											(DWORD			dwIdLog,
											 BYTE			iNiveau,
											 BYTE			iCategorie,
											 INT32			iCode,
											 BYTE			iStatutAlarme,
											 BYTE			iEtatAlarme,
											 LPCSTR			szLibelleCourt,
											 LPCSTR			szLibelleLong);

#define LOGNAME__LogEcrireActivite2W		"LogEcrireActivite2W"
typedef INT32 (_stdcall *LOGPROC__LogEcrireActivite2W)
											(DWORD			dwIdLog,
											 BYTE			iNiveau,
											 BYTE			iCategorie,
											 INT32			iCode,
											 BYTE			iStatutAlarme,
											 BYTE			iEtatAlarme,
											 LPCWSTR		szLibelleLong,
											 char			cTIN,
											 LPCWSTR		szNomFichierParam);

#define LOGNAME__LogEcrireActivite2A		"LogEcrireActivite2A"
typedef INT32 (_stdcall *LOGPROC__LogEcrireActivite2A)
											(DWORD			dwIdLog,
											 BYTE			iNiveau,
											 BYTE			iCategorie,
											 INT32			iCode,
											 BYTE			iStatutAlarme,
											 BYTE			iEtatAlarme,
											 LPCSTR			szLibelleLong,
											 char			cTIN,
											 LPCSTR			szNomFichierParam);
// CBO : Fin ajout

// Fonctions de purge
#define LOGNAME__LogPurgeW					"LogPurgeW"
typedef INT32 (_stdcall *LOGPROC__LogPurgeW)			(DWORD dwIdLog,
											 DWORD dwDureeConservationLog,
											 DWORD dwTypeSorties);

#define LOGNAME__LogPurgeA					"LogPurgeA"
typedef INT32 (_stdcall *LOGPROC__LogPurgeA)			(DWORD dwIdLog,
											 DWORD dwDureeConservationLog,
											 DWORD dwTypeSorties);

// Fonctions de archive
#define LOGNAME__LogArchiveW				"LogArchiveW"
typedef INT32 (_stdcall *LOGPROC__LogArchiveW)			(DWORD   dwIdLog,
											 DWORD   dwDureeArchivageLog,
											 DWORD   dwTypeSorties,
											 LPCWSTR szNomRepertoireArchive);

#define LOGNAME__LogArchiveA				"LogArchiveA"
typedef INT32 (_stdcall *LOGPROC__LogArchiveA)			(DWORD  dwIdLog,
											 DWORD  dwDureeArchivageLog,
											 DWORD  dwTypeSorties,
											 LPCSTR	szNomRepertoireArchive);

// Fonctions d'initialisation de la dll de vie
#define LOGNAME__LogInitLifeW				"LogInitLifeW"
typedef INT32 (_stdcall *LOGPROC__LogInitLifeW)		(DWORD	 dwIdLog, 
											 WORD    wPort,
											 LPCWSTR szHostname,
											 LONG	 lProtocole);

#define LOGNAME__LogInitLifeA				"LogInitLifeA"
typedef INT32 (_stdcall *LOGPROC__LogInitLifeA)		(DWORD	 dwIdLog, 
											 WORD    wPort,
											 LPCSTR szHostname,
											 LONG	lProtocole);

#define LOGNAME__LogInitCommandW			"LogInitCommandW"
typedef INT32 (_stdcall *LOGPROC__LogInitCommandW)		(DWORD		dwIdLog, 
											 WORD		wPort,
											 LPCWSTR	szHostname,
											 LONG		lProtocol,
											 LPCWSTR	szPathFile);

#define LOGNAME__LogInitCommandA			"LogInitCommandA"
typedef INT32 (_stdcall *LOGPROC__LogInitCommandA)		(DWORD		dwIdLog, 
											 WORD		wPort,
											 LPCSTR		szHostname,
											 LONG		lProtocol,
											 LPCSTR		szPathFile);

#define LOGNAME__LogReadCommandA			"LogReadCommandA"
typedef INT32 (_stdcall *LOGPROC__LogReadCommandA)		(DWORD		dwIdLog,
											 LPSTR		szCommand,
											 size_t		uiCommand);

// Log Parameters that can be Get/Set
#define			LOG_PARAM_SOCKET_HOSTNAME_A			"SocketHostname"
#define			LOG_PARAM_SOCKET_PORT_A				"SocketPort"
#define			LOG_PARAM_SOCKET_HOSTNAME_W			L"SocketHostname"
#define			LOG_PARAM_SOCKET_PORT_W				L"SocketPort"

#ifdef _UNICODE
	#define		LOG_PARAM_SOCKET_HOSTNAME			LOG_PARAM_SOCKET_HOSTNAME_W
	#define		LOG_PARAM_SOCKET_PORT				LOG_PARAM_SOCKET_PORT_W
#else
	#define		LOG_PARAM_SOCKET_HOSTNAME			LOG_PARAM_SOCKET_HOSTNAME_A
	#define		LOG_PARAM_SOCKET_PORT				LOG_PARAM_SOCKET_PORT_A
#endif

// Log Parameters generic Get/Set functions
#define LOGNAME__LogUpdateParametersW		"LogUpdateParametersW"
typedef INT32 (__stdcall *LOGPROC__LogUpdateParametersW)(
												DWORD		dwIdLog,
												BYTE		iCategorie,
												DWORD		iTypeSortie,
												LPCWSTR		szParamName,
												LPCWSTR		szValue
												);

#define LOGNAME__LogUpdateParametersA		"LogUpdateParametersA"
typedef INT32 (__stdcall *LOGPROC__LogUpdateParametersA)(
												DWORD		dwIdLog, 
												BYTE		iCategorie, 
												DWORD		iTypeSortie,
												LPCSTR		szParamName, 
												LPCSTR		szValue
												);

#define LOGNAME__LogGetParametersA			"LogGetParametersA"
typedef INT32 (__stdcall *LOGPROC__LogGetParametersA)(
												DWORD		dwIdLog,
												BYTE		iCategorie,
												DWORD		iTypeSortie,
												LPCSTR		szParamName,
												LPSTR		szValue,
												int			iValueBufferSize
												);

#define LOGNAME__LogGetParametersW			"LogGetParametersW"
typedef INT32 (__stdcall *LOGPROC__LogGetParametersW)(
												DWORD		dwIdLog,
												BYTE		iCategorie,
												DWORD		iTypeSortie,
												LPCWSTR		szParamName,
												LPWSTR		szValue,
												int			iValueBufferSize
												);


#define LOGNAME__LogZipStart			"LogZipStart"
typedef void (__stdcall *LOGPROC__LogZipStart)(
												DWORD		dwLogAgeInHours,
												DWORD		dwZipSizeThreshold
												);

#define LOGNAME__LogZipStop				"LogZipStop"
typedef void (__stdcall *LOGPROC__LogZipStop)(
												);

#define LOGNAME__LogZipRegisterFolderW	"LogZipRegisterFolderW"
typedef void (__stdcall *LOGPROC__LogZipRegisterFolderW)(
												LPCWSTR		wszFolder,
												LPCWSTR		wszZipName
												);

#define LOGNAME__LogZipRegisterFolderA	"LogZipRegisterFolderA"
typedef void (__stdcall *LOGPROC__LogZipRegisterFolderA)(
												LPCSTR		szFolderName,
												LPCSTR		szZipName
												);

#endif	// _MODULELOG_H_
