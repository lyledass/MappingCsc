#pragma once

#include <windows.h>
#include <string>
#include <time.h>

#include <cctype>
#include <algorithm>
#include <sstream>
#include <wtypes.h>

#include <vector>

//#include <boost/serialization/level.hpp>

//using namespace std;

#define CHAINE(caractere) std::basic_string<caractere, std::char_traits<caractere>, std::allocator<caractere> >
#define tstring std::basic_string<TCHAR>

errno_t ShortToString( short valeur, char* message, size_t taille, int radix = 10);
errno_t ShortToString( short valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t UShortToString( unsigned short valeur, char* message, size_t taille, int radix = 10);
errno_t UShortToString( unsigned short valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t Int32ToString( __int32 valeur, char* message, size_t taille, int radix = 10);
errno_t Int32ToString( __int32 valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t UInt32ToString( unsigned __int32 valeur, char* message, size_t taille, int radix = 10);
errno_t UInt32ToString( unsigned __int32 valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t Int64ToString( __int64 valeur, char* message, size_t taille, int radix = 10);
errno_t Int64ToString( __int64 valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t UInt64ToString( unsigned __int64 valeur, char* message, size_t taille, int radix = 10);
errno_t UInt64ToString( unsigned __int64 valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t LongToString( long valeur, char* message, size_t taille, int radix = 10);
errno_t LongToString( long valeur, wchar_t* message, size_t taille, int radix = 10);

errno_t ULongToString( unsigned long valeur, char* message, size_t taille, int radix = 10);
errno_t ULongToString( unsigned long valeur, wchar_t* message, size_t taille, int radix = 10);

int		StringToInteger( const char* szValue );
int		StringToInteger( const wchar_t* szValue );

double	StringToDouble( const char* szValue );
double	StringToDouble( const wchar_t* szValue );

long	StringToLong( const char* szValue );
long	StringToLong( const wchar_t* szValue );

unsigned long	StringToULong( const char* szValue, int iBase = 10 );
unsigned long	StringToULong( const wchar_t* szValue, int iBase = 10 );

void	Affecter( std::string& szDestination, const std::string& szOrigine );
void	Affecter( std::string& szDestination, const std::wstring& szOrigine );
void	Affecter( std::wstring& szDestination, const std::string& szOrigine );
void	Affecter( std::wstring& szDestination, const std::wstring& szOrigine );

void	Concatener( std::string& szDestination, const std::string& szOrigine );
void	Concatener( std::string& szDestination, const std::wstring& szOrigine );
void	Concatener( std::wstring& szDestination, const std::string& szOrigine );
void	Concatener( std::wstring& szDestination, const std::wstring& szOrigine );


size_t longueur(	const char		* str );
size_t longueur(	const wchar_t	* str );

int PrintfArg(char *buffer, size_t sizeOfBuffer, size_t count, const char *format, va_list argptr );
//{ return _vsnprintf_s(buffer,sizeOfBuffer, count, format, argptr); }

int PrintfArg(wchar_t *buffer, size_t sizeOfBuffer, size_t count, const wchar_t *format, va_list argptr );
//{ return _vsnwprintf_s(buffer,sizeOfBuffer, count, format, argptr); }

enum TYPE_CARACTERE
{
	CARACTERE_ASCII,
	CARACTERE_UNICODE
};

int TypeCaractere( char );		
int TypeCaractere( wchar_t );	


template<class caractere>
class CTemplateErgString : public CHAINE(caractere)
{
	int m_iTypeCaractere;

public:
	CTemplateErgString(void)
	{
		caractere c=0;
		m_iTypeCaractere = TypeCaractere( c );

		if( m_iTypeCaractere == CARACTERE_ASCII )
			*this = "";
		else
			*this = L"";
	}

	CTemplateErgString(const caractere* chaine)
		: CHAINE(caractere)(chaine)
	{
		caractere c=0;
		m_iTypeCaractere = TypeCaractere( c );
	}

	CTemplateErgString(const CHAINE(caractere)& chaine)
		: CHAINE(caractere)(chaine)
	{
		caractere c=0;
		m_iTypeCaractere = TypeCaractere( c );
	}

	~CTemplateErgString(void)
	{}

	CTemplateErgString& operator=(const char* chaine)
	{
		Affecter( *this, chaine );
		return *this;
	}

	CTemplateErgString& operator=(const wchar_t* chaine)
	{
		Affecter( *this, chaine );
		return *this;
	}

	CTemplateErgString& operator=(const CHAINE(char)& chaine)
	{
		Affecter( *this, chaine );
		return *this;
	}

	CTemplateErgString& operator=(const CHAINE(wchar_t)& chaine)
	{
		Affecter( *this, chaine );
		return *this;
	}

	CTemplateErgString<caractere>& operator=( short valeur )
	{
		caractere message[20];
		ShortToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( unsigned short valeur )
	{
		caractere message[20];
		UShortToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( __int32 valeur )
	{
		caractere message[20];
		Int32ToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( unsigned __int32 valeur )
	{
		caractere message[20];
		UInt32ToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( __int64 valeur )
	{
		caractere message[20];
		Int32ToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( unsigned __int64 valeur )
	{
		caractere message[20];
		UInt32ToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( long valeur )
	{
		caractere message[20];
		LongToString( valeur, message, 20 );
		return operator=( message );
	}

	CTemplateErgString<caractere>& operator=( unsigned long valeur )
	{
		caractere message[20];
		ULongToString( valeur, message, 20 );
		return operator=( message );
	}

	caractere& operator[](int index )
	{
		return CHAINE(caractere)::operator[](index);
	}

	caractere operator[](int index) const
	{
		return CHAINE(caractere)::operator[](index);
	}

	caractere& operator[](size_t index)
	{
		return CHAINE(caractere)::operator[](index);
	}

	caractere operator[](size_t index) const
	{
		return CHAINE(caractere)::operator[](index);
	}

	operator const caractere*() const
	{
		return c_str();
	}

	CTemplateErgString operator+( short valeur )
	{
		caractere message[20];
		ShortToString( valeur, message, 20 );
		return *this + message;
	}

	CTemplateErgString operator+( unsigned short valeur )
	{
		caractere message[20];
		UShortToString( valeur, message, 20 );
		return *this + message;
	}

	CTemplateErgString operator+( __int32 valeur )
	{
		caractere message[20];
		Int32ToString( valeur, message, 20 );
		return *this + message;
	}

	CTemplateErgString operator+( unsigned __int32 valeur )
	{
		caractere message[20];
		UInt32ToString( valeur, message, 20 );
		return *this + message;
	}

	CTemplateErgString operator+( __int64 valeur )
	{
		caractere message[20];
		Int64ToString( valeur, message, 20, 10 );
		return *this + message;
	}

	CTemplateErgString operator+( unsigned __int64 valeur )
	{
		caractere message[20];
		UInt64ToString( valeur, message, 20, 10 );
		return *this + message;
	}

	CTemplateErgString operator+( long valeur )
	{
		caractere message[20];
		LongToString( valeur, message, 20 );
		return *this + message;
	}

	CTemplateErgString operator+( unsigned long valeur )
	{
		caractere message[20];
		ULongToString( valeur, message, 20, 10 );
		return *this + message;
	}

	//CTemplateErgString operator+( char* chaine )
	//{
	//	CTemplateErgString szResultat;
	//	szResultat = *this;
	//	Concatener( szResultat, chaine );
	//	return szResultat;
	//}

	//CTemplateErgString operator+( wchar_t* chaine )
	//{
	//	CTemplateErgString szResultat;
	//	szResultat = *this;
	//	Concatener( szResultat, chaine );
	//	return szResultat;
	//}
	//CTemplateErgString operator+( CHAINE(char) chaine )
	//{
	//	CTemplateErgString szResultat;
	//	szResultat = *this;
	//	Concatener( szResultat, chaine );
	//	return szResultat;
	//}

	//CTemplateErgString operator+( CHAINE(wchar_t) chaine )
	//{
	//	CTemplateErgString szResultat;
	//	szResultat = *this;
	//	Concatener( szResultat, chaine );
	//	return szResultat;
	//}

	CTemplateErgString& operator+=( const char* chaine )
	{
		Concatener( *this, chaine );

		return *this;
	}

	CTemplateErgString& operator+=( const wchar_t* chaine )
	{
		Concatener( *this, chaine );

		return *this;
	}

	CTemplateErgString& operator+=( const CHAINE(char)& chaine )
	{
		Concatener( *this, chaine );

		return *this;
	}

	CTemplateErgString& operator+=( const CHAINE(wchar_t)& chaine )
	{
		Concatener( *this, chaine );

		return *this;
	}

	CTemplateErgString& operator+=( const CTemplateErgString<char>& chaine )
	{
		Concatener( *this, chaine );

		return *this;
	}

	CTemplateErgString& operator+=( const CTemplateErgString<wchar_t>& chaine )
	{
		Concatener( *this, chaine );

		return *this;
	}

	CTemplateErgString& operator+=( short valeur )
	{
		caractere message[20];
		ShortToString( valeur, message, 20 );
		return *this += message;
	}

	CTemplateErgString& operator+=( unsigned short valeur )
	{
		caractere message[20];
		UShortToString( valeur, message, 20 );
		return *this += message;
	}

	CTemplateErgString& operator+=( __int32 valeur )
	{
		caractere message[20];
		Int32ToString( valeur, message, 20, 10 );
		return *this += message;
	}

	CTemplateErgString& operator+=( unsigned __int32 valeur )
	{
		caractere message[20];
		UInt32ToString( valeur, message, 20, 10 );
		return *this += message;
	}

	CTemplateErgString& operator+=( __int64 valeur )
	{
		caractere message[20];
		Int64ToString( valeur, message, 20, 10 );
		return *this += message;
	}

	CTemplateErgString& operator+=( unsigned __int64 valeur )
	{
		caractere message[20];
		UInt64ToString( valeur, message, 20, 10 );
		return *this += message;
	}

	CTemplateErgString& operator+=( long valeur )
	{
		caractere message[20];
		LongToString( valeur, message, 20, 10 );
		return *this += message;
	}

	CTemplateErgString& operator+=( unsigned long valeur )
	{
		caractere message[20];
		ULongToString( valeur, message, 20, 10 );
		return *this += message;
	}


	void Replace(const CHAINE(caractere) &oldStr, 
				 const CHAINE(caractere) &newStr);
	void Replace( caractere oldStr, caractere newStr);

	// remplace une chaine de caractere par un entier.
	void Replace(caractere* szSousChaine, caractere* szFormat, int iValeur);

	void Format(const caractere* pszFormat, ...);

	//template<class caractere>
	//struct my_tolower
	//{ 
	//	caractere operator()(caractere c) const 
	//	{
	//		return std::tolower(static_cast<unsigned caractere>(c));
	//	} 
	//};

	//template<class caractere>
	//struct my_toupper
	//{ 
	//	caractere operator()(caractere c) const 
	//	{
	//		return std::toupper(static_cast<unsigned caractere>(c));
	//	} 
	//};

	CTemplateErgString<caractere>& ToLower()
	{
		transform(begin(), end(), begin(), std::tolower);

		switch( m_iTypeCaractere )
		{
		case CARACTERE_ASCII:
			Replace( 'À', 'à' );
			Replace( 'Â', 'â' );
			Replace( 'Ä', 'ä' );
			Replace( 'Ã', 'ã' );
			Replace( 'É', 'é' );
			Replace( 'È', 'è' );
			Replace( 'Ê', 'ê' );
			Replace( 'Ë', 'ë' );
			Replace( 'Ì', 'ì' );
			Replace( 'Î', 'î' );
			Replace( 'Ï', 'ï' );
			Replace( 'Ò', 'ò' );
			Replace( 'Ô', 'ô' );
			Replace( 'Ö', 'ö' );
			Replace( 'Õ', 'õ' );
			Replace( 'Ù', 'ù' );
			Replace( 'Û', 'û' );
			Replace( 'Ü', 'ü' );
			Replace( 'Ñ', 'ñ' );
			break;

		case CARACTERE_UNICODE:
			Replace( L'À', L'à' );
			Replace( L'Â', L'â' );
			Replace( L'Ä', L'ä' );
			Replace( L'Ã', L'ã' );
			Replace( L'É', L'é' );
			Replace( L'È', L'è' );
			Replace( L'Ê', L'ê' );
			Replace( L'Ë', L'ë' );
			Replace( L'Ì', L'ì' );
			Replace( L'Î', L'î' );
			Replace( L'Ï', L'ï' );
			Replace( L'Ò', L'ò' );
			Replace( L'Ô', L'ô' );
			Replace( L'Ö', L'ö' );
			Replace( L'Õ', L'õ' );
			Replace( L'Ù', L'ù' );
			Replace( L'Û', L'û' );
			Replace( L'Ü', L'ü' );
			Replace( L'Ñ', L'ñ' );
			break;
		}

		return *this;
	}

	CTemplateErgString<caractere>& ToUpper()
	{
		transform(begin(), end(), begin(), std::toupper);
		return *this;
	}

	// complete a gauche avec cCaractere pour que la chaine est la taille iTaille.
	void CompleteLeft( caractere cCaractere, int iTaille );

	bool getLPSTR(LPSTR lpstr, __int32 iTaille) const;
	bool getBSTR(BSTR bstr, __int32 iTaille) const;

	int CTemplateErgString::ToInteger() const
	{
		return StringToInteger( c_str() );
	}

	float CTemplateErgString::ToFloat() const
	{
		return (float)StringToDouble( c_str() );
	}

	double CTemplateErgString::ToDouble() const
	{
		return StringToDouble( c_str() );
	}

	long CTemplateErgString::ToLong() const
	{
		return StringToLong( c_str() );
	}

	unsigned long CTemplateErgString::ToULong( int iBase = 10 ) const
	{
		return StringToULong( c_str(), iBase ); 
	}

	short CTemplateErgString::ToShort() const
	{
		return (short)StringToInteger( c_str() );
	}
	// TODO fonctions de conversion vers d'autre type (ulong par exemple)

	std::vector<CTemplateErgString<caractere>> Split(caractere separateur) const
	{
		std::vector<CTemplateErgString<caractere>> result;
		size_t debut = 0;
		size_t fin;
		while( (fin = find(separateur, debut)) != -1 )
		{
			result.insert(result.end(), substr( debut, fin - debut ));
			debut = fin + 1;
		}
		result.insert(result.end(), substr( debut ));

		return result;
	}

	std::vector<CTemplateErgString<caractere>> SplitStringNoCaseSensitive( caractere* separateur ) const
	{
		CTemplateErgString<caractere> rechercheChaine, rechercheSeparateur;
		std::vector<CTemplateErgString<caractere>> result;

		rechercheSeparateur = separateur;

		rechercheChaine = *this;
		rechercheChaine.ToLower();
		rechercheSeparateur = rechercheSeparateur.ToLower();
	
		size_t debut = 0;
		size_t fin;
		while( (fin = rechercheChaine.find( rechercheSeparateur, debut)) != -1 )
		{
			result.insert(result.end(), substr( debut, fin - debut ));
			debut = fin + longueur( separateur );
		}
		result.insert(result.end(), substr( debut ));

		return result;
	}

	CTemplateErgString<caractere> TrimLeft(caractere C = ' ' ) const
	{
		size_t index = find_first_not_of( C );

		if( index != npos )
			return substr( index );
		else
			return CTemplateErgString();
	}

	CTemplateErgString<caractere> TrimRight(caractere C = ' ' ) const
	{
		size_t index = find_last_not_of( C );

		if( index != npos )
			return substr( 0, index + 1 );
		else
			return CTemplateErgString();
	}	

	CTemplateErgString<caractere> Trim(caractere C = ' ' ) const
	{
		return TrimLeft( C ).TrimRight( C );
	}

	/// <summary>Retourne les nbCaracteres derniers caracteres de la chaine.</summary>
	/// <remarks>si le nombre de caracteres demandes est superieur a la taille de la chaine, alors on retourne la chaine en entier.</remarks>
	CTemplateErgString<caractere> Right( int nbCaracteres )
	{
		if( nbCaracteres < (int)length() )
			return substr( length() - nbCaracteres, nbCaracteres );
		else
			return *this;
	}

	/// <summary>Retourne les nbCaracteres premiers caracteres de la chaine.</summary>
	/// <remarks>si le nombre de caracteres demandes est superieur a la taille de la chaine, alors on retourne la chaine en entier.</remarks>
	CTemplateErgString<caractere> Left( int nbCaracteres )
	{
		if( nbCaracteres < (int)length() )
			return substr( 0, nbCaracteres );
		else
			return *this;
	}

	static caractere MajusculeSansAccent(caractere cIn)
	{
		caractere cOut = NULL;
		
		if( TypeCaractere( cIn ) == CARACTERE_ASCII )
		{
			if (cIn == 'À' || cIn == 'Á' || cIn == 'Â' || cIn == 'Ä' || cIn == 'Å' ||
				cIn == 'à' || cIn == 'á' || cIn == 'â' || cIn == 'ä' || cIn == 'å')
			{
				cOut = 'A';
			}
			else 
			{
				if (cIn == 'Ò' || cIn == 'Ó' || cIn == 'Ô' || cIn == 'Ö' ||
					cIn == 'ò' || cIn == 'ó' || cIn == 'ô' || cIn == 'ö') 
				{
					cOut = 'O';
				}
				else
				{
					if (cIn == 'È' || cIn == 'É' || cIn == 'Ê' || cIn == 'Ë' || 
						cIn == 'è' || cIn == 'é' || cIn == 'ê' || cIn == 'ë')
					{
						cOut = 'E';
					}
					else
					{
						if (cIn == 'Ì' || cIn == 'Í' || cIn == 'Î' || cIn == 'Ï' ||
							cIn == 'ì' || cIn == 'í' || cIn == 'î' || cIn == 'ï')
						{
							cOut = 'I';
						}
						else
						{
							if (cIn == 'Ù' || cIn == 'Ú' || cIn == 'Û' || cIn == 'Ü' ||
								cIn == 'ù' || cIn == 'ú' || cIn == 'û' || cIn == 'ü')
							{
								cOut = 'U';
							}
							else 
							{
								if (cIn == 'Ç' || cIn == 'ç')
								{
									cOut = 'C';
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (cIn == L'À' || cIn == L'Á' || cIn == L'Â' || cIn == L'Ä' || cIn == L'Å' ||
				cIn == L'à' || cIn == L'á' || cIn == L'â' || cIn == L'ä' || cIn == L'å')
			{
				cOut = L'A';
			}
			else 
			{
				if (cIn == L'Ò' || cIn == L'Ó' || cIn == L'Ô' || cIn == L'Ö' ||
					cIn == L'ò' || cIn == L'ó' || cIn == L'ô' || cIn == L'ö') 
				{
					cOut = L'O';
				}
				else
				{
					if (cIn == L'È' || cIn == L'É' || cIn == L'Ê' || cIn == L'Ë' || 
						cIn == L'è' || cIn == L'é' || cIn == L'ê' || cIn == L'ë')
					{
						cOut = L'E';
					}
					else
					{
						if (cIn == L'Ì' || cIn == L'Í' || cIn == L'Î' || cIn == L'Ï' ||
							cIn == L'ì' || cIn == L'í' || cIn == L'î' || cIn == L'ï')
						{
							cOut = L'I';
						}
						else
						{
							if (cIn == L'Ù' || cIn == L'Ú' || cIn == L'Û' || cIn == L'Ü' ||
								cIn == L'ù' || cIn == L'ú' || cIn == L'û' || cIn == L'ü')
							{
								cOut = L'U';
							}
							else 
							{
								if (cIn == L'Ç' || cIn == L'ç')
								{
									cOut = L'C';
								}
							}
						}
					}
				}
			}
		}

		return cOut;
	}

	CTemplateErgString<caractere> ToUpperSansAccent() const
	{
		CTemplateErgString<caractere> szOut = *this;
		caractere cTemp = NULL;

		unsigned int i;

		szOut.ToUpper();

		for(i = 0; i < (int)longueur(szOut); i++)
		{
			cTemp = MajusculeSansAccent(szOut[i]);
			
			if (cTemp != NULL)
			{
				szOut[i] = cTemp;
			}
		}

		return szOut;
	}
};



	template<class caractere>
	CTemplateErgString<caractere> operator+(	const CTemplateErgString<caractere>&	szString1,
												const CTemplateErgString<char>&			szString2 )
	{
		CTemplateErgString<caractere> szResultat = szString1;
		Concatener( szResultat, szString2 );
		return szResultat;
		//return (CHAINE(caractere)) szString1 + (CHAINE(caractere)) szString2;
	}

	template<class caractere>
	CTemplateErgString<caractere> operator+(	const CTemplateErgString<caractere>&	szString1,
												const CTemplateErgString<wchar_t>&		szString2 )
	{
		CTemplateErgString<caractere> szResultat = szString1;
		Concatener( szResultat, szString2 );
		return szResultat;
		//return (CHAINE(caractere)) szString1 + (CHAINE(caractere)) szString2;
	}

	template<class caractere>
	CTemplateErgString<caractere> operator+(	const CTemplateErgString<caractere>&	szString1,
												const CHAINE(char)&			szString2 )
	{
		CTemplateErgString<caractere> szResultat = szString1;
		Concatener( szResultat, szString2 );
		return szResultat;
		//return (CHAINE(caractere)) szString1 + (CHAINE(caractere)) szString2;
	}

	template<class caractere>
	CTemplateErgString<caractere> operator+(	const CTemplateErgString<caractere>&	szString1,
												const CHAINE(wchar_t)&		szString2 )
	{
		CTemplateErgString<caractere> szResultat = szString1;
		Concatener( szResultat, szString2 );
		return szResultat;
		//return (CHAINE(caractere)) szString1 + (CHAINE(caractere)) szString2;
	}

	template<class caractere>
	CTemplateErgString<caractere> operator+(	const CTemplateErgString<caractere>&	szString1,	
												const char*								szString2 )
	{
		CTemplateErgString<caractere> szResultat = szString1;
		Concatener( szResultat, szString2 );
		return szResultat;
		//return (CHAINE(caractere))szString1 + szString2;
	}

	template<class caractere>
	CTemplateErgString<caractere> operator+(	const CTemplateErgString<caractere>&	szString1,	
												const wchar_t*							szString2 )
	{
		CTemplateErgString<caractere> szResultat = szString1;
		Concatener( szResultat, szString2 );
		return szResultat;
		//return (CHAINE(caractere))szString1 + szString2;
	}

	template<class caractere>
	CTemplateErgString<caractere> operator+(	const caractere*						szString1,	
												const CTemplateErgString<caractere>&	szString2 )
	{
		return szString1 + (CHAINE(caractere)) szString2;
	}


	template<class caractere>
	void CTemplateErgString<caractere>::Replace(const CHAINE(caractere) &oldStr, 
												const CHAINE(caractere) &newStr)
	{
		size_t position( 0 );
		CTemplateErgString message;

		position = find(oldStr, position);

		while( position != CHAINE(caractere)::npos)
		{
			replace(position, oldStr.length(), newStr);//, position, newStr.length() );
			position += newStr.length();

			position = find(oldStr, position);
		}
	}

	template<class caractere>
	void CTemplateErgString<caractere>::Replace( caractere oldStr, caractere newStr )
	{
		size_t position( 0 );
		CTemplateErgString message;

		position = find(oldStr, position);

		while( position != CHAINE(caractere)::npos)
		{
			replace(position, 1, 1, newStr);//, position, newStr.length() );
			position += 1;

			position = find(oldStr, position);
		}
	}

	template<class caractere>
	void CTemplateErgString<caractere>::Replace(caractere* szSousChaine, caractere* szFormat, int iValeur)
	{
		CTemplateErgString sValeur;
		sValeur.Format( szFormat, iValeur );
		Replace( szSousChaine, sValeur );
	}

	template<class caractere>
	CHAINE(caractere) format_arg_list(const caractere *fmt, va_list args) 
	{ 
		if (!fmt) return CHAINE(caractere)(); 
		int   result = -1, length = 256; 
		caractere *buffer = 0; 
		while (result == -1) 
		{ 
			if (buffer) delete [] buffer; 
			buffer = new caractere [length + 1]; 
			memset(buffer, 0, length + 1); 
			
			result = PrintfArg(buffer, length, _TRUNCATE, fmt, args); 
			
			length *= 2; 
		}
		CHAINE(caractere) s(buffer); 
		delete [] buffer; 
		return s; 
	} 

	template<class caractere>
	void CTemplateErgString<caractere>::Format(const caractere* pszFormat, ...)
	{ 
		va_list args; 
		va_start(args, pszFormat); 
		CHAINE(caractere)::operator=( format_arg_list(pszFormat, args) ); 
		va_end(args); 
	} 


	template<class caractere>
	void CTemplateErgString<caractere>::CompleteLeft( caractere cCaractere, int iTaille )
	{
		insert( 0, CHAINE(caractere)( iTaille - length(), ' ') );
	}

	template<class caractere>
	bool CTemplateErgString<caractere>::getLPSTR(LPSTR lpstr, __int32 iTaille) const
	{
		bool result = true;
		__int32 l = (__int32)length();
		if( l > iTaille )
		{
			result = false;
			l = iTaille;
		}

		for(__int32 i = 0; i < l; ++i )
			lpstr[ i ] = operator[]( i );
		lpstr[ l ] = 0;

		return result;
	}

	template<class caractere>
	bool CTemplateErgString<caractere>::getBSTR(BSTR bstr, __int32 iTaille) const
	{
		bool result = true;
		__int32 l = (__int32)length();
		if( l > iTaille )
		{
			result = false;
			l = iTaille;
		}

		for(__int32 i = 0; i < l; ++i )
			bstr[ i ] = operator[]( i );
		bstr[ l ] = 0;

		return result;
	}

	typedef CTemplateErgString<char> CErgString;
	typedef CTemplateErgString<wchar_t> CErgWString;
	typedef CTemplateErgString<TCHAR> CErgTString;
	typedef CTemplateErgString<CHAR> CErgAString;


	CErgString iToString( __int32 i);
	CErgString iToString (__int64 i);
	CErgString iToString (long i);
	CErgString iToString (unsigned long i);

	CErgString fToString (float f);
	
	CErgString DateDuJourToString(CErgString format);

	CErgString ToAnsi(const CErgWString& );
	CErgWString ToUnicode(const CErgString& );

	//BOOST_CLASS_IMPLEMENTATION(CErgString, boost::serialization::primitive_type)
	//BOOST_CLASS_IMPLEMENTATION(CErgWString, boost::serialization::primitive_type)
