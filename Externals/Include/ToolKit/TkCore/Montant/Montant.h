// Montant.h: interface for the CMontant class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __TKCORE_MONTANT_H
#define __TKCORE_MONTANT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "../ListExt.h"

class CMontant {
public :
	CMontant();
	CMontant(int iVal);
	CMontant(long val);
	CMontant(ULONG val);
	CMontant(INT64 val);
	CMontant(INT64 val, long devise);
	CMontant(INT64 val, LPCTSTR szDevise);
	CMontant(const CMontant& montant);
	~CMontant();
	
	void Set(INT64 val);
	void Set(INT64 val, long devise);
	void Set(INT64 val, LPCTSTR szDevise);
	void SetPrix(double val);
	void SetPrixCentime(LONG val);
	void SetPrix(double val, long devise);
	void SetPrixCentime(LONG val, long devise);
	void SetPrix(double val, LPCTSTR szDevise);
	void SetPrixCentime(LONG val, LPCTSTR szDevise);
	void SetValeurCarte(INT64 val, long devise);
	void SetValeurCarte(INT64 val);
	INT64 Get()  const;
	INT64 Get(long devise) const;
	INT64 GetValeurCarte() const;

	double GetPrixDevisePrimaire() const;
	double GetPrixDeviseSecondaire() const;
	LONG GetPrixDevisePrimaireCentime() const;
	LONG GetPrixDeviseSecondaireCentime() const;

	// to get the same round as FormatDevisePrimaire method
	LONG GetPrixDevisePrimaireCentimeRound() const;

	void FormatDevisePrimaire(LPTSTR szBuffer, size_t bufferSize, bool bUseSymbole = true) const;
	LPCTSTR FormatDevisePrimaire(bool bUseSymbole = true) const;
	void FormatDeviseSecondaire(LPTSTR szBuffer, size_t bufferSize, bool bUseSymbole = true) const;
	LPCTSTR FormatDeviseSecondaire(bool bUseSymbole = true) const;

	// Arrondit le montant pour l'affichage (perte d'info possible)
	void ArrondirAffichage();

	CMontant	ConvertAllTaxToWithoutTax(LONG lVatRate);
	CMontant	ConvertWithoutTaxToAllTax(LONG lVatRate);

	CMontant	operator + () const;
	CMontant	operator - () const;

	CMontant	operator * (int quantite) const;
	CMontant	operator / (int quantite) const;
	CMontant&	operator = (const CMontant& montant);
	CMontant&	operator += (const CMontant& montant);
	CMontant&	operator -= (const CMontant& montant);
	CMontant	operator - (const CMontant& montant) const;
	CMontant	operator + (const CMontant& montant) const;
	CMontant	operator * (const CMontant& montant) const;
	CMontant	operator / (const CMontant& montant) const;
	CMontant	operator * (double multiplicateur) const;
	CMontant	operator / (double diviseur) const;
	
	bool		operator >= (const CMontant& montant) const;
	bool		operator > (const CMontant& montant) const;
	bool		operator <= (const CMontant& montant) const;
	bool		operator < (const CMontant& montant) const;
	bool		operator == (const CMontant& montant) const;
	bool		operator != (const CMontant& montant) const;

protected:
	static void	Format(LPTSTR	szBuffer,
					size_t	bufferSize,
					double	dVal,
					long	lOrder,
					bool	bUseSymbol = true);

private:
	INT64			m_val;			//< Valeur dans la devise primaire
};

class CMontantList : public CListExt<CMontant> {
public :

};


#endif // __TKCORE_MONTANT_H
