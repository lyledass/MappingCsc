#ifndef __CONVERSION_ERGSTRING_H
#define __PHONETIQUE_ERGSTRING_H

#include "../String/ErgString.h"

namespace ErgString
{
	CErgString 	ConvertDecToHexaA( const CErgString& 	szValue );
	CErgString 	ConvertHexaToDecA( const CErgString& 	szValue );

	CErgWString ConvertDecToHexaW( const CErgWString& 	szValue );
	CErgWString ConvertHexaToDecW( const CErgWString& 	szValue );


#if UNICODE	

#define ConvertDecToHexa	ConvertDecToHexaW
#define ConvertHexoToDec	ConvertHexaToDecW

#else

#define ConvertDecToHexa	ConvertDecToHexaA
#define ConvertHexoToDec	ConvertHexaToDecA

#endif

};

#endif