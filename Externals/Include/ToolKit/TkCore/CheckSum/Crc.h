#ifndef __CRC_H
#define __CRC_H

#include <windows.h>

// définition du type CRC sur 2 octets
typedef WORD CRC;
typedef LONG CRC32;


CRC	CrcCalcul(CONST BYTE *pData, DWORD len);
CRC	CrcAppend(CRC curCrc, CONST BYTE *pData, WORD len);


CRC32	Crc32Calcul(CONST BYTE *pData, WORD len);

CRC32	Crc32Begin();
CRC32	Crc32Append(CRC32 curCrc, CONST BYTE *pData, WORD len);
CRC32	Crc32End(CRC32 curCrc);


#endif /* __CRC_H */