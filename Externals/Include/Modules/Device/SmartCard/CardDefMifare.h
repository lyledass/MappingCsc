#ifndef __TKCORE__SMARTCARD__CARD_DEF_MIFARE_H
#define __TKCORE__SMARTCARD__CARD_DEF_MIFARE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CardStruct.h"

#define MIFARE_BLOCLEN			0x10

#define	MIFARE1K_SECTORCOUNT	0x10
#define MIFARE1K_BLOCPERSECT	0x04		///< Nombre de bloc par secteur. On consid�re aussi le bloc 4, 
											///< m�me s'il n'est pas utilisable directement puisqu'il contient
											///< les informations de s�curit�s du secteur.



#endif /* __TKCORE__SMARTCARD__CARD_DEF_MIFARE_H */