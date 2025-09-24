#ifndef __TKCORE_MONTANT_ENV_H
#define __TKCORE_MONTANT_ENV_H

#include <windows.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define DEVISE_PRIMAIRE			1
#define DEVISE_SECONDAIRE		2


enum TPOSITIONSYMBOLE {
	POSITIONSYMBOLE_FIN_AVEC_ESPACE		= 0,
	POSITIONSYMBOLE_DEBUT_AVEC_ESPACE	= 1,
	POSITIONSYMBOLE_FIN_SANS_ESPACE		= 2,
	POSITIONSYMBOLE_DEBUT_SANS_ESPACE	= 3,
};

class IMontantEnv {
public :
	//IMontantEnv();
	//~IMontantEnv();

	virtual bool	IsDoubleAffichage() const = 0;
	virtual long	GetDeviseCount() const = 0;

	virtual long	GetDeviseCode(long devOrder = DEVISE_PRIMAIRE) const = 0;
	virtual void	GetDeviseLibelle(LPTSTR szBuffer, size_t bufferSize, long devOrder = DEVISE_PRIMAIRE) const = 0;

	virtual INT64	GetValByOrder(double prix, long devOrder = DEVISE_PRIMAIRE) const = 0;
	virtual INT64	GetValByCode(double prix, long devCode) const = 0;
	virtual bool	GetValByTrigrame(double prix, LPCTSTR szDevise, INT64* pVal) const = 0;
	virtual bool	GetValBySymbole(double prix, LPCTSTR szDevise, INT64* pVal) const = 0;

	virtual double	GetPrixByOrder(INT64 val, long devise = DEVISE_PRIMAIRE) const = 0;

	virtual INT64	TransformeInDevisePrimaire(INT64 val, long devCode) const = 0;
	virtual INT64	TransformeInDevisePrimaire(INT64 val, LPCTSTR szDevise) const = 0;
	virtual INT64	TransformeValCarteInDevisePrimaire(INT64 val, long devise = DEVISE_PRIMAIRE) const = 0;

	virtual long	GetDevisePrecision(long devCode) const = 0;
	virtual void	GetDeviseSymbole(LPTSTR szBuffer, size_t bufferSize, long devCode) const = 0;
	virtual TPOSITIONSYMBOLE	GetDevisePositionSymbole(long devCode) const = 0;

	virtual void	GetSeparateurMilliers(LPTSTR szBuffer, size_t bufferSize, long devCode) const = 0;
	virtual void	GetSeparateurDecimal(LPTSTR szBuffer, size_t bufferSize, long devCode) const = 0;
};

void	SetMontantEnv(IMontantEnv* pMontantEnv);


#endif // __TKCORE_MONTANT_ENV_H