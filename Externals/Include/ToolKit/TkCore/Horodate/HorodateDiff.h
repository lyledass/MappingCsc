// HorodateDiff.h: interface for the CHorodateDiff class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_HORODATEDIFF_H__)
#define _HORODATEDIFF_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <time.h>
#include <windows.h>

//#include "Horodate.h"

//class CHorodate;

class CHorodateDiff {
public:
	// Construsteur/Destructeur
	CHorodateDiff();
	CHorodateDiff(INT32 iJour, INT32 iHeure, INT32 iMinute, INT32 iSeconde);
	CHorodateDiff(const CHorodateDiff& dHorodate);
	CHorodateDiff(double dblHorodate);

	virtual ~CHorodateDiff();

	// Opérateurs
	const CHorodateDiff&	operator =	(const CHorodateDiff& dHorodate);
	bool					operator ==	(const CHorodateDiff& dHorodate)	const;
	bool					operator !=	(const CHorodateDiff& stHorodate)	const;
	bool					operator <	(const CHorodateDiff& dHorodate)	const;
	bool					operator >	(const CHorodateDiff& dHorodate)	const;
	bool					operator <=	(const CHorodateDiff& dHorodate)	const;
	bool					operator >=	(const CHorodateDiff& dHorodate)	const;
//	CHorodate				operator +	(CHorodate hdDateOffset)			const;
//	CHorodateDiff			operator -	(INT32 dateOffset)					const;
//	INT32					operator -	(const CHorodateDiff& dHorodate)	const;
//	CHorodateDiff&			operator +=	(INT32 dateOffset);		
//	CHorodateDiff&			operator -=	(INT32 dateOffset);

	// Méthodes membres publiques
	INT32	DonneSecondes() const;
	INT32	DonneMinutes() const;
	INT32	DonneHeures() const;
	INT32	DonneJours() const;

	INT32	DonneTotalSecondes() const;
	INT32	DonneTotalMinutes() const;
	INT32	DonneTotalHeures() const;
	INT32	DonneTotalJours() const;

	BOOL	FixeHorodateDiff(INT32 iJour, INT32 iHeure, INT32 iMinute, INT32 iSeconde);
/*
operator +, -
 Add, subtract, and change sign for COleDateTimeSpan values.
 
operator +=, -=
 Add and subtract a COleDateTimeSpan value from this COleDateTimeSpan value.
 
operator =
 Copies a COleDateTimeSpan value.
 
operator ==, <, <=
 Compare two COleDateTimeSpan values.
 
operator double
 Converts this COleDateTimeSpan value to a double.
*/
private:
	// Structure de date privée
	struct THorodateDiff {
		INT32	iJour;
		INT32	iHeure;
		INT32	iMinute;
		INT32	iSeconde;
	};

	// Méthodes membres privées
	double	HorodateDiffEnFlottant	(THorodateDiff tHorodateDiff) const;
	void	FlottantEnHorodateDiff	(double fHorodate, THorodateDiff& tHorodateDiff) const;

	// Variables membres
	double				m_fHorodateDiff;
};

#endif // !defined(AFX_HORODATE_H__0E63BA89_F08A_4422_AB18_1084F3FE97EC__INCLUDED_)
