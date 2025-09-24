#ifndef __PHONETIQUE_CHAR_H
#define __PHONETIQUE_CHAR_H

//#include <Strsafe.h>

int		EnPhonetiqueStringW(		wchar_t* szResultat, size_t iTailleBufferResultat, const wchar_t* chaine);
double	EnPhonetiqueDoubleW(		const wchar_t* szChaine );
double	PhonetiqueStringToDoubleW(	const wchar_t* szChaine );

int		EnPhonetiqueStringA(		char* szResultat, size_t iTailleBufferResultat, const char* chaine);
double	EnPhonetiqueDoubleA(		const char* szChaine );
double	PhonetiqueStringToDoubleA(	const char* szChaine );

#if UNICODE 

#define EnPhonetiqueString				EnPhonetiqueStringW
#define	EnPhonetiqueDouble				EnPhonetiqueDoubleW		
#define	PhonetiqueStringToDouble		PhonetiqueStringToDoubleW

#else

#define EnPhonetiqueString				EnPhonetiqueStringA
#define	EnPhonetiqueDouble				EnPhonetiqueDoubleA
#define	PhonetiqueStringToDouble		PhonetiqueStringToDoubleA

#endif

#endif