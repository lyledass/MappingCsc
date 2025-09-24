#ifndef __PHONETIQUE_H
#define __PHONETIQUE_H

#include "String/ErgString.h"

namespace ErgString
{
	CErgWString		EnPhonetiqueStringW( const CErgWString& szChaine );
	double			EnPhonetiqueDoubleW( const CErgWString& szChaine );
	double			PhonetiqueStringToDoubleW( const CErgWString& szChaine );

	CErgString		EnPhonetiqueStringA( const CErgString& szChaine );
	double			EnPhonetiqueDoubleA( const CErgString& szChaine );
	double			PhonetiqueStringToDoubleA( const CErgString& szChaine );

#if UNICODE 

#define EnPhonetiqueString				EnPhonetiqueStringW
#define	EnPhonetiqueDouble				EnPhonetiqueDoubleW		
#define	EnPhonetiqueStringToDouble		EnPhonetiqueStringToDoubleW

#else

#define EnPhonetiqueString				EnPhonetiqueStringA
#define	EnPhonetiqueDouble				EnPhonetiqueDoubleA
#define	EnPhonetiqueStringToDouble		EnPhonetiqueStringToDoubleA

#endif
};

#endif