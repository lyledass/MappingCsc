#ifndef __TOOLKIT__TOKENIZER_H
#define __TOOLKIT__TOKENIZER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "../ListExt.h"

class CTokenizer
{
public :
	// Constructeurs/destructeur
	CTokenizer();
	CTokenizer(const CTokenizer&);
	virtual ~CTokenizer();

	// Surcharge d'opérateurs
	const CTokenizer& operator = (const CTokenizer&);

	// Découpage de la chaine
	bool	TokenizeStringA(
			/* in */	LPCSTR		szSource,
			/* in */	const CHAR	cSeparator);
	bool	TokenizeStringW(
			/* in */	LPCWSTR		szSource,
			/* in */	const WCHAR	cSeparator);
	bool	TokenizeString(
			/* in */	LPCTSTR		szSource,
			/* in */	const TCHAR	cSeparator);

	// Récupération des éléments découpés
	int		GetTokenCount() const;
	bool	GetTokenA(
			/* in */	int				index,
			/* int */	size_t			lSizeMaxToken,	
			/* out */	LPSTR			szToken);
	bool	GetTokenW(
			/* in */	int				index,
			/* int */	size_t			lSizeMaxToken,	
			/* out */	LPWSTR			szToken);
	bool	GetToken(
			/* in */	int				index,
			/* int */	size_t			lSizeMaxToken,
			/* out */	LPTSTR			szToken);

	bool	 CTokenizer::GetAllTokenFlag() const;
	void	SetAllTokenFlag(bool bAllTokenFlag);
	
	bool	CTokenizer::AddToken(
			/* in */	LPTSTR			szToken,
			/* in */	long			lIndex);

	bool	CTokenizer::AddToken(
			/* in */	LPTSTR			szToken);

	bool	CTokenizer::SetToken(
			/* in */	LPTSTR			szToken,
			/* in */	long			lIndex);

private:
	bool	TokenLineA(
			/* in */	LPCSTR			szSource,
			/* in */	size_t			lSize,
			/* in */	const CHAR		cSeparator,
			/* out */	LPSTR&			szResult);
	bool	TokenLineW(
			/* in */	LPCWSTR			szSource,
			/* in */	size_t			lSize,
			/* in */	const WCHAR		cSeparator,
			/* out */	LPWSTR&			szResult);
	void	ReleaseList();

	// Variables membres
//	CListExt<LPSTR>		m_listeTokensA;
	CListExt<LPWSTR>	m_listeTokensW;
	bool				m_bAllTokenFlag; //FLASE : nbToken=3, TRUE : nbToken=4 si token = "1;2;3;"
};

#endif /* __TOOLKIT__TOKENIZER_H */