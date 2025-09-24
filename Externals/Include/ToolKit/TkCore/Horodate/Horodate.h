// Horodate.h: interface for the CHorodate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HORODATE_H__0E63BA89_F08A_4422_AB18_1084F3FE97EC__INCLUDED_)
#define AFX_HORODATE_H__0E63BA89_F08A_4422_AB18_1084F3FE97EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <time.h>
#include <windows.h>

#include "HorodateDiff.h"

class CHorodateDiff;

#define OLEDATETIME2HORODATE(dtDateHeure, hdDateHeure) { hdDateHeure.FixeHorodate(dtDateHeure.GetYear(), dtDateHeure.GetMonth(), dtDateHeure.GetDay(), dtDateHeure.GetHour(), dtDateHeure.GetMinute(), dtDateHeure.GetSecond()); }
#define HORODATE2OLEDATETIME(hdDateHeure, dtDateHeure) { dtDateHeure.SetDateTime(hdDateHeure.DonneAnnee(), hdDateHeure.DonneMois(), hdDateHeure.DonneJour(), hdDateHeure.DonneHeure(), hdDateHeure.DonneMinute(), hdDateHeure.DonneSeconde()); }

// Liste des arguments possibles du format pour les méthodes FixeHorodate(LPCSTR...)
// et Format(LPCSTR...)
//
#define HORODATE_ARGLIB_ANNEE_COURTW	L'a'
#define HORODATE_ARGLIB_ANNEE_LONGW		L'A'
#define HORODATE_ARGLIB_MOISW			L'm'
#define HORODATE_ARGLIB_JOURW			L'j'
#define HORODATE_ARGLIB_HEUREW			L'H'
#define HORODATE_ARGLIB_MINUTEW			L'M'
#define HORODATE_ARGLIB_SECONDEW		L'S'

#define HORODATE_ARGLIB_ANNEE_COURTA	'a'
#define HORODATE_ARGLIB_ANNEE_LONGA		'A'
#define HORODATE_ARGLIB_MOISA			'm'
#define HORODATE_ARGLIB_JOURA			'j'
#define HORODATE_ARGLIB_HEUREA			'H'
#define HORODATE_ARGLIB_MINUTEA			'M'
#define HORODATE_ARGLIB_SECONDEA		'S'

// Format prédéfinis
#define HORODATE_ARGPREDEF_AMJ_W						L"%A%m%j"
#define HORODATE_ARGPREDEF_LONGUEUR_AMJ_W				7
#define HORODATE_ARGPREDEF_JMA_W						L"%j%m%A"
#define HORODATE_ARGPREDEF_LONGUEUR_JMA_W				7
#define HORODATE_ARGPREDEF_AMJHMS_W						L"%A%m%j%H%M%S"
#define HORODATE_ARGPREDEF_LONGUEUR_AMJHMS_W			13
#define HORODATE_ARGPREDEF_JMAHMS_W						L"%j%m%A%H%M%S"
#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMS_W			13
#define HORODATE_ARGPREDEF_AMJSEP_W						L"%A/%m/%j"
#define HORODATE_ARGPREDEF_LONGUEUR_AMJSEP_W			9
#define HORODATE_ARGPREDEF_JMASEP_W						L"%j/%m/%A"
#define HORODATE_ARGPREDEF_LONGUEUR_JMASEP_W			9
#define HORODATE_ARGPREDEF_HMSSEP_W						L"%H:%M:%S"
#define HORODATE_ARGPREDEF_LONGUEUR_HMSSEP_W			9
#define HORODATE_ARGPREDEF_JMAHMSSEP_W					L"%j/%m/%A %H:%M:%S"
#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMSSEP_W			18
#define HORODATE_ARGPREDEF_ODBCDATEHEURE_W				L"{ts '%A-%m-%j %H:%M:%S'}"
#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATEHEURE_W		25
#define HORODATE_ARGPREDEF_ODBCDATE_W					L"{d '%A-%m-%j'}"
#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATE_W			15
#define HORODATE_ARGPREDEF_MJAHMSSEP_W					L"%m/%j/%A %H:%M:%S"
#define HORODATE_ARGPREDEF_LONGUEUR_MJAHMSSEP_W			18

#define HORODATE_ARGPREDEF_AMJ_A						"%A%m%j"
#define HORODATE_ARGPREDEF_LONGUEUR_AMJ_A				7
#define HORODATE_ARGPREDEF_JMA_A						"%j%m%A"
#define HORODATE_ARGPREDEF_LONGUEUR_JMA_A				7
#define HORODATE_ARGPREDEF_AMJHMS_A						"%A%m%j%H%M%S"
#define HORODATE_ARGPREDEF_LONGUEUR_AMJHMS_A			13
#define HORODATE_ARGPREDEF_JMAHMS_A						"%j%m%A%H%M%S"
#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMS_A			13
#define HORODATE_ARGPREDEF_AMJSEP_A						"%A/%m/%j"
#define HORODATE_ARGPREDEF_LONGUEUR_AMJSEP_A			9
#define HORODATE_ARGPREDEF_JMASEP_A						"%j/%m/%A"
#define HORODATE_ARGPREDEF_LONGUEUR_JMASEP_A			9
#define HORODATE_ARGPREDEF_HMSSEP_A						"%H:%M:%S"
#define HORODATE_ARGPREDEF_LONGUEUR_HMSSEP_A			9
#define HORODATE_ARGPREDEF_JMAHMSSEP_A					"%j/%m/%A %H:%M:%S"
#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMSSEP_A			18
#define HORODATE_ARGPREDEF_ODBCDATEHEURE_A				"{ts '%A-%m-%j %H:%M:%S'}"
#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATEHEURE_A		25
#define HORODATE_ARGPREDEF_ODBCDATE_A					"{d '%A-%m-%j'}"
#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATE_A			15
#define HORODATE_ARGPREDEF_MJAHMSSEP_A					"%m/%j/%A %H:%M:%S"
#define HORODATE_ARGPREDEF_LONGUEUR_MJAHMSSEP_A			18

#ifdef _UNICODE
	#define HORODATE_ARGLIB_ANNEE_COURT					HORODATE_ARGLIB_ANNEE_COURTW
	#define HORODATE_ARGLIB_ANNEE_LONG					HORODATE_ARGLIB_ANNEE_LONGW
	#define HORODATE_ARGLIB_MOIS						HORODATE_ARGLIB_MOISW
	#define HORODATE_ARGLIB_JOUR						HORODATE_ARGLIB_JOURW
	#define HORODATE_ARGLIB_HEURE						HORODATE_ARGLIB_HEUREW
	#define HORODATE_ARGLIB_MINUTE						HORODATE_ARGLIB_MINUTEW
	#define HORODATE_ARGLIB_SECONDE						HORODATE_ARGLIB_SECONDEW

	#define HORODATE_ARGPREDEF_AMJ						HORODATE_ARGPREDEF_AMJ_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_AMJ				HORODATE_ARGPREDEF_LONGUEUR_AMJ_W			
	#define HORODATE_ARGPREDEF_JMA						HORODATE_ARGPREDEF_JMA_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMA				HORODATE_ARGPREDEF_LONGUEUR_JMA_W			
	#define HORODATE_ARGPREDEF_AMJHMS					HORODATE_ARGPREDEF_AMJHMS_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_AMJHMS			HORODATE_ARGPREDEF_LONGUEUR_AMJHMS_W		
	#define HORODATE_ARGPREDEF_JMAHMS					HORODATE_ARGPREDEF_JMAHMS_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMS			HORODATE_ARGPREDEF_LONGUEUR_JMAHMS_W		
	#define HORODATE_ARGPREDEF_AMJSEP					HORODATE_ARGPREDEF_AMJSEP_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_AMJSEP			HORODATE_ARGPREDEF_LONGUEUR_AMJSEP_W		
	#define HORODATE_ARGPREDEF_JMASEP					HORODATE_ARGPREDEF_JMASEP_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMASEP			HORODATE_ARGPREDEF_LONGUEUR_JMASEP_W		
	#define HORODATE_ARGPREDEF_HMSSEP					HORODATE_ARGPREDEF_HMSSEP_W					
	#define HORODATE_ARGPREDEF_LONGUEUR_HMSSEP			HORODATE_ARGPREDEF_LONGUEUR_HMSSEP_W
	#define HORODATE_ARGPREDEF_JMAHMSSEP				HORODATE_ARGPREDEF_JMAHMSSEP_W
	#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMSSEP		HORODATE_ARGPREDEF_LONGUEUR_JMAHMSSEP_W		
	#define HORODATE_ARGPREDEF_ODBCDATEHEURE			HORODATE_ARGPREDEF_ODBCDATEHEURE_W			
	#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATEHEURE	HORODATE_ARGPREDEF_LONGUEUR_ODBCDATEHEURE_W	
	#define HORODATE_ARGPREDEF_ODBCDATE					HORODATE_ARGPREDEF_ODBCDATE_W				
	#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATE		HORODATE_ARGPREDEF_LONGUEUR_ODBCDATE_W
	#define HORODATE_ARGPREDEF_MJAHMSSEP				HORODATE_ARGPREDEF_MJAHMSSEP_W
	#define HORODATE_ARGPREDEF_LONGUEUR_MJAHMSSEP		HORODATE_ARGPREDEF_LONGUEUR_MJAHMSSEP_W
#else
	#define HORODATE_ARGLIB_ANNEE_COURT					HORODATE_ARGLIB_ANNEE_COURTA
	#define HORODATE_ARGLIB_ANNEE_LONG					HORODATE_ARGLIB_ANNEE_LONGA
	#define HORODATE_ARGLIB_MOIS						HORODATE_ARGLIB_MOISA
	#define HORODATE_ARGLIB_JOUR						HORODATE_ARGLIB_JOURA
	#define HORODATE_ARGLIB_HEURE						HORODATE_ARGLIB_HEUREA
	#define HORODATE_ARGLIB_MINUTE						HORODATE_ARGLIB_MINUTEA
	#define HORODATE_ARGLIB_SECONDE						HORODATE_ARGLIB_SECONDEA

	#define HORODATE_ARGPREDEF_AMJ						HORODATE_ARGPREDEF_AMJ_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_AMJ				HORODATE_ARGPREDEF_LONGUEUR_AMJ_A			
	#define HORODATE_ARGPREDEF_JMA						HORODATE_ARGPREDEF_JMA_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMA				HORODATE_ARGPREDEF_LONGUEUR_JMA_A			
	#define HORODATE_ARGPREDEF_AMJHMS					HORODATE_ARGPREDEF_AMJHMS_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_AMJHMS			HORODATE_ARGPREDEF_LONGUEUR_AMJHMS_A		
	#define HORODATE_ARGPREDEF_JMAHMS					HORODATE_ARGPREDEF_JMAHMS_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMS			HORODATE_ARGPREDEF_LONGUEUR_JMAHMS_A		
	#define HORODATE_ARGPREDEF_AMJSEP					HORODATE_ARGPREDEF_AMJSEP_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_AMJSEP			HORODATE_ARGPREDEF_LONGUEUR_AMJSEP_A		
	#define HORODATE_ARGPREDEF_JMASEP					HORODATE_ARGPREDEF_JMASEP_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMASEP			HORODATE_ARGPREDEF_LONGUEUR_JMASEP_A		
	#define HORODATE_ARGPREDEF_HMSSEP					HORODATE_ARGPREDEF_HMSSEP_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_HMSSEP			HORODATE_ARGPREDEF_LONGUEUR_HMSSEP_A
	#define HORODATE_ARGPREDEF_JMAHMSSEP				HORODATE_ARGPREDEF_JMAHMSSEP_A					
	#define HORODATE_ARGPREDEF_LONGUEUR_JMAHMSSEP		HORODATE_ARGPREDEF_LONGUEUR_JMAHMSSEP_A		
	#define HORODATE_ARGPREDEF_ODBCDATEHEURE			HORODATE_ARGPREDEF_ODBCDATEHEURE_A			
	#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATEHEURE	HORODATE_ARGPREDEF_LONGUEUR_ODBCDATEHEURE_A	
	#define HORODATE_ARGPREDEF_ODBCDATE					HORODATE_ARGPREDEF_ODBCDATE_A				
	#define HORODATE_ARGPREDEF_LONGUEUR_ODBCDATE		HORODATE_ARGPREDEF_LONGUEUR_ODBCDATE_A
	#define HORODATE_ARGPREDEF_MJAHMSSEP				HORODATE_ARGPREDEF_MJAHMSSEP_A
	#define HORODATE_ARGPREDEF_LONGUEUR_MJAHMSSEP		HORODATE_ARGPREDEF_LONGUEUR_MJAHMSSEP_A
#endif

class CHorodate {
public:
	// Construsteur/Destructeur
	CHorodate();
	CHorodate(INT32 iAnnee, INT32 iMois,   INT32 iJour,
			  INT32 iHeure, INT32 iMinute, INT32 iSeconde);
	CHorodate(const CHorodate& dHorodate);
	CHorodate(const SYSTEMTIME& stHorodate);
	CHorodate(const time_t&  timer);

	virtual ~CHorodate();

	// Opérateurs
	const CHorodate&	operator =	(const CHorodate& dHorodate);
	const CHorodate&	operator =	(const SYSTEMTIME& stHorodate);
	const CHorodate&	operator =	(const time_t&  timer);
	bool				operator ==	(const CHorodate& dHorodate)	const;
	bool				operator ==	(const SYSTEMTIME& stHorodate)	const;
	bool				operator ==	(const time_t&  timer)	const;
	bool				operator !=	(const CHorodate& stHorodate)	const;
	bool				operator !=	(const SYSTEMTIME& dHorodate)	const;
	bool				operator !=	(const time_t&  timer)	const;
	bool				operator <	(const CHorodate& dHorodate)	const;
	bool				operator <	(const SYSTEMTIME& stHorodate)	const;
	bool				operator <	(const time_t&  timer)	const;
	bool				operator >	(const CHorodate& dHorodate)	const;
	bool				operator >	(const SYSTEMTIME& stHorodate)	const;
	bool				operator >	(const time_t&  timer)	const;
	bool				operator <=	(const CHorodate& dHorodate)	const;
	bool				operator <=	(const SYSTEMTIME& stHorodate)	const;
	bool				operator <=	(const time_t&  timer)	const;
	bool				operator >=	(const CHorodate& dHorodate)	const;
	bool				operator >=	(const SYSTEMTIME& stHorodate)	const;
	bool				operator >=	(const time_t&  timer)	const;

//	CHorodate			operator -	(INT32 dateOffset)						const;
	CHorodate			operator -	(const CHorodateDiff& hdHorodateDiff)	const;
//	INT32				operator -	(const CHorodate& dHorodate)	const;
	CHorodateDiff		operator -	(const CHorodate& dHorodate)			const;
//	CHorodate			operator +	(INT32 dateOffset)						const;
	CHorodate			operator +	(const CHorodateDiff& hdHorodateDiff)	const;
//	CHorodate&			operator +=	(INT32 dateOffset);
	CHorodate&			operator +=	(const CHorodateDiff& hdHorodateDiff);
//	CHorodate&			operator -=	(INT32 dateOffset);
	CHorodate&			operator -=	(const CHorodateDiff& hdHorodateDiff);

	// Pour les opérateurs de cast, pas de type de retour et pas de paramètre
						operator SYSTEMTIME	();

	// Méthodes membres publiques
	BOOL	FixeHorodateW(LPCWSTR lpszHorodate, UINT32 iHorodateMaxLen,
						 LPCWSTR lpszFormat, UINT32 iFormatMaxLen);
	BOOL	FixeHorodateA(LPCSTR lpszHorodate, UINT32 iHorodateMaxLen,
						 LPCSTR lpszFormat, UINT32 iFormatMaxLen);
	BOOL	FixeHorodate(LPCTSTR lpszHorodate, UINT32 iHorodateMaxLen,
						 LPCTSTR lpszFormat, UINT32 iFormatMaxLen);
	BOOL	FixeHorodate(INT32 iAnnee, INT32 iMois,   INT32 iJour,
						 INT32 iHeure, INT32 iMinute, INT32 iSeconde);
	BOOL	FixeHorodate(SYSTEMTIME stHorodate);
	BOOL	FixeHorodate(const time_t&  timer);
	BOOL	FixeDate	(INT32 iAnnee, INT32 iMois,   INT32 iJour);
	BOOL	FixeHeure	(INT32 iHeure, INT32 iMinute, INT32 iSeconde);


	INT32	DonneSeconde() const;
	INT32	DonneMinute() const;
	INT32	DonneHeure() const;
	INT32	DonneJour() const;
	INT32	DonneJourDeLaSemaine() const;
	INT32	DonneJourDeLAnnee() const;
	INT32	DonneMois() const;
	INT32	DonneAnnee() const;
	INT32	DonneStatut() const;
	INT32	DonneSemaineDeLAnnee() const;

	time_t	DonneUnixTimeStamp() const;

	INT32	DonneNombreJourDansMois	(INT32 iMois, bool bAnneeBissextile = false) const;
	bool	EstAnneeBissextile		(INT32 iAnnee) const;

	BOOL	AjouteHeure(INT32 iNbHeuresAjout, INT32 iNbMinutesAjout, INT32 iNbSecondesAjout);
	BOOL	AjouteJour(	INT32 iNbJoursAjout	);
	
	/// <summary>Ajoute un nombre de mois à la date</summary>
	/// <remarks>Si le jour qui en résulte n'existe pas, la date est fixée au jour suivant (si iNbMoisAjout >= 0) ou précédent (si iNbMoisAjout < 0). Exemple : 31/03/2008 +1 mois donnera 30/04/2008 et -1 mois donnera 29/02/2008</remarks>
	BOOL	AjouteMois(	INT32 iNbMoisAjout	);
	/// <summary>Ajoute un nombre d'année à la date</summary>
	/// <remarks>Si le jour qui en résulte n'existe pas, la date est fixée au jour suivant (si iNbMoisAjout >= 0) ou précédent (si iNbMoisAjout < 0). Exemple : 29/02/2008 +1 an donnera 01/03/2009 et -1 an donnera 28/02/2007</remarks>
	BOOL	AjouteAnnee(INT32 iNbAnneesAjout);

	LPCWSTR	FormatW() const;
	LPCWSTR	FormatW(LPCWSTR lpszFormat, UINT32 iFormatMaxLen) const;
	LPCSTR		FormatA() const;
	LPCSTR		FormatA(LPCSTR lpszFormat, UINT32 iFormatMaxLen) const;
	LPCTSTR	Format() const;
	LPCTSTR	Format(LPCTSTR lpszFormat, UINT32 iFormatMaxLen) const;

	// Méthodes de classe
	static CHorodate DonneDateSysteme();
	static time_t	 ConvertCHorodateToUnixTimeStamp(const CHorodate& objHorodate);
	static CHorodate ConvertUnixTimeStampToCHorodate(const time_t timer);

	// Les états possibles
	enum {
		invalide = 0,
		valide,
	};

private:
	// Structure de date privée
	struct THorodate {
		INT32	iAnnee;
		INT32	iMois;
		INT32	iJour;
		INT32	iHeure;
		INT32	iMinute;
		INT32	iSeconde;
	};

	// Méthodes membres privées
	void	MiseAJourStatut();
	void	MiseAJourStatut( THorodate tHorodate );

	INT32	DonneProchainArgumentW	(LPCWSTR lpszFormat, 
									UINT32 iFormatMaxLen, 
									INT32& iOffsetIdx) const;

	double	HorodateEnFlottant		(THorodate tHorodate) const;
	void	FlottantEnHorodate		(double fHorodate, THorodate& tHorodate) const;

	void	FixeAnneePivot			(INT32 iAnneePivot);
	INT32	DonneAnneePivot			() const;

	INT32	FormateAnneeAvecSiecle	(INT32 iAnnee) const;


	// Variables membres
	double				m_fHorodate;
	INT32				m_iStatut;
	mutable LPWSTR	    m_lpszFormatBufferW;
	mutable LPSTR	    m_lpszFormatBufferA;
};

#endif // !defined(AFX_HORODATE_H__0E63BA89_F08A_4422_AB18_1084F3FE97EC__INCLUDED_)
