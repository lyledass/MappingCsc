#ifndef __INCLUDE_TKCORE_ERGNUMBER_H
#define __INCLUDE_TKCORE_ERGNUMBER_H

//#pragma once

#include <windows.h>


#ifdef _UNICODE
	#define GetStringT			GetStringW
	#define GetStringFromMask	GetStringFromMaskW
#else
	#define GetStringT			GetStringA
	#define GetStringFromMask	GetStringFromMaskA
#endif

class CErgNumber {
public:
	// Construsteur/Destructeur
	CErgNumber();
	CErgNumber(const CErgNumber&);
	virtual ~CErgNumber();

	CErgNumber(signed char cNumber);
	CErgNumber(unsigned char ucNumber);
	CErgNumber(short sNumber);
	CErgNumber(unsigned short usNumber);
	CErgNumber(int iNumber);
	CErgNumber(unsigned int uiNumber);
	CErgNumber(long lNumber);
	CErgNumber(unsigned long ulNumber);
	CErgNumber(__int64 i64Number);
	CErgNumber(unsigned __int64 ui64Number);
	CErgNumber(unsigned __int32 ui32PartieHaute, unsigned __int32 ui32PartieBasse);
	CErgNumber(const char* s, int base = 10);
	CErgNumber(const wchar_t* ws, int base = 10);
	CErgNumber(const BYTE* lpByteArray, const int& iBufSize, bool bLittleEndian);

	// Chaîne + base => Number
	BOOL	FromString(LPCSTR szNumber, int base);
	BOOL	FromString(LPCWSTR wszNumber, int base);

	// Opérateurs unaires
	CErgNumber			operator- () const;
	CErgNumber			operator+ () const;

	const CErgNumber&	operator =	(const CErgNumber& entier);

	const int				ToInt() const;
	const unsigned int		ToUInt() const;
	const long				ToLong() const;
	const unsigned long		ToULong() const;
	const short				ToShort() const;
	const unsigned short	ToUShort() const;
	const __int64			ToI64() const;
	const unsigned __int64	ToUI64() const;

	// Opérateur binaires
	CErgNumber			operator +	(const CErgNumber& otherNb) const;
	CErgNumber&			operator -=	(const CErgNumber& otherNb);
	CErgNumber			operator -	(const CErgNumber& otherNb) const;
	CErgNumber&			operator +=	(const CErgNumber& otherNb);
	bool				operator >	(const CErgNumber& otherNb)	const;
	bool				operator <	(const CErgNumber& otherNb)	const;
	bool				operator <=	(const CErgNumber& otherNb)	const;
	bool				operator >=	(const CErgNumber& otherNb)	const;
	bool				operator ==	(const CErgNumber& otherNb)	const;
	bool				operator !=	(const CErgNumber& otherNb)	const;

	bool				DivisionEntiere(const UINT8 ui8Diviseur, UINT8& ui8Reste);
	void				Multiply(UINT8 uiVal);
	bool				IsNull() const;
	bool				IsPositive() const;
	bool				IsNegative() const;
	int					CompareAbsoluteVal(const CErgNumber& nb) const; // -1 si this < other, 1 si this > other

	void				SetNegative();
	void				SetPositive();
	void				InvertSign();

	// Renvoie le nombre d'octets significatifs
	UINT				GetNbChiffresSignificatifs() const;

	unsigned int GetNbChiffresMax(unsigned int  base = 10) const;

	BOOL GetStringA(LPSTR szStr, UINT uiBufSize, UINT uiBase = 10) const;
	BOOL GetStringW(LPWSTR swzStr, UINT uiBufSize, UINT uiBase = 10) const;
	// GetStringFromMask retourne une chaine allouée formatée selon le masque en entrée
	LPSTR GetStringFromMaskA(LPCSTR szMaskStr) const;
	LPWSTR GetStringFromMaskW(LPCWSTR swzMaskStr) const;

	UINT GetByteSize() const;
	int GetByteArray(BYTE* b, UINT uiBufSize, bool bLittleEndian) const;

	// GetBaseFromMaskA retourne la base utilisée par le masque (dernière lettre du masque=d --> 10, dernière lettre du masque=h --> 16) 
	static int GetBaseFromMaskA(LPCSTR szMaskStr);
	static int GetBaseFromMaskW(LPCWSTR szMaskStr);

protected:
	void			AddOrSubtract(const CErgNumber& otherNb, bool bSubtract);

	LPSTR DeleteUnusedSpaceAndZero(LPSTR szFormatStr) const;
	LPWSTR DeleteUnusedSpaceAndZero(LPWSTR swzFormatStr) const;

private:
	// Variable membre
	BYTE*			m_pbyBuffer;
	UINT			m_uiBufferSize;

	void			Delete();
	void			CreateFrom(const CErgNumber& other);
	void			CopyFrom(const CErgNumber& other);
	void			SetToNull();

	void			EnsureSize(UINT uiNewSize);


	bool			m_bNegatif;

};

#endif // __INCLUDE_TKCORE_ERGNUMBER_H