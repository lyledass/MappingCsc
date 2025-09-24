#ifndef __TKCORE__SMARTCARD__BIT_H
#define __TKCORE__SMARTCARD__BIT_H

#include <windows.h>

typedef BYTE		BIT;
typedef BIT near	*PBIT;
typedef BYTE far	*LPBIT;
typedef CONST BIT	*PCBIT;
typedef CONST BIT far	*LPCBIT;
typedef CONST BYTE	*PCBYTE;
typedef CONST BYTE far	*LPCBYTE;

typedef enum {
	BIG_ENDIAN = 0,
	LITTLE_ENDIAN,
} TEndianNess;

/*
 *  1 est codé en bits comme suit : 0001b
 *  F2 est codé en bits F2 comme suit : 11110010b
 *  F2 A2 est codé en Big Endian F2 A2 => 11110010 10100010b
 *  srclen is in bytes
 */
// Copy the bits in Little Endian or Big Endian from the given bitpos (bitpos 0 = MSB (left bit in BE)). In Big Endian, if bitpos=0, the right bits are truncated.
bool bitGetEx(LPBIT bits, WORD bitslen, LPCBYTE src, WORD srclen, WORD bitpos, TEndianNess endianNess);

// Copy the bits in Little Endian or Big Endian (if bitslen < srclen*8, truncate MSbits (left bits in BE))
bool bitGetEx(LPBIT bits, WORD bitslen, LPCBYTE src, WORD srclen, TEndianNess endianNess);

// Copy the simple types in Big Endian, truncate MSbits if bitslen < simple type size
bool bitGet(LPBIT bits, WORD bitslen, bool b);
bool bitGet(LPBIT bits, WORD bitslen, char c);
bool bitGet(LPBIT bits, WORD bitslen, unsigned char c);
bool bitGet(LPBIT bits, WORD bitslen, short s);
bool bitGet(LPBIT bits, WORD bitslen, unsigned short s);
bool bitGet(LPBIT bits, WORD bitslen, int i);
bool bitGet(LPBIT bits, WORD bitslen, unsigned int i);
bool bitGet(LPBIT bits, WORD bitslen, long l);
bool bitGet(LPBIT bits, WORD bitslen, unsigned long l);
bool bitGet(LPBIT bits, WORD bitslen, float f);
bool bitGet(LPBIT bits, WORD bitslen, __int64 i64);
bool bitGet(LPBIT bits, WORD bitslen, unsigned __int64 i64);


/*
 *  1 est codé en bits comme suit : 0001b
 */
// Copy the bits in LE or BE from the given bitpos (bitpos 0 = MSB)
bool bitSetEx(LPCBIT bits, WORD bitslen, LPBYTE dest, WORD srclen, WORD bitpos, TEndianNess endianNess);
bool bitSetEx(LPCBIT bits, WORD bitslen, LPBYTE dest, WORD srclen, TEndianNess endianNess);

bool bitSet(LPCBIT bits, WORD bitslen, bool& b);
bool bitSet(LPCBIT bits, WORD bitslen, char& c);
bool bitSet(LPCBIT bits, WORD bitslen, unsigned char& c);
bool bitSet(LPCBIT bits, WORD bitslen, short& s);
bool bitSet(LPCBIT bits, WORD bitslen, unsigned short& s);
bool bitSet(LPCBIT bits, WORD bitslen, int& i);
bool bitSet(LPCBIT bits, WORD bitslen, unsigned int& i);
bool bitSet(LPCBIT bits, WORD bitslen, long& l);
bool bitSet(LPCBIT bits, WORD bitslen, unsigned long& l);
bool bitSet(LPCBIT bits, WORD bitslen, float& f);
bool bitSet(LPCBIT bits, WORD bitslen, __int64& i64);
bool bitSet(LPCBIT bits, WORD bitslen, unsigned __int64& i64);

BYTE* bitInsert(LPCBIT srcbits, WORD srcbitslen, LPBYTE dest, WORD destlen, WORD bitpos, WORD nbbit = 0);

WORD bitGetMsbPos(LPCBIT bits, WORD bitslen);
bool bitSetMsbPos(LPBIT bits, WORD bitslen, long l);

/*
 *  1 est codé en bits comme suit : 1000b
 *  F2 est codé en bits 4F comme suit : 01001111b
 *  F2 A2 (11110010 10100010b) est codé en Big Endian (01000101 01001111b => 45 4F)
 */
bool bitRGet(LPBIT bits, WORD bitslen, LPCBYTE src, WORD srclen, TEndianNess endianNess);
bool bitRGet(LPBIT bits, WORD bitslen, long l);
bool bitRGet(LPBIT bits, WORD bitslen, DWORD64 i64);
bool bitRGet(LPBIT bits, WORD bitslen, bool b);

bool bitRSet(LPCBIT bits, WORD bitslen, LPBYTE src, WORD srclen, TEndianNess endianNess);
bool bitRSet(LPCBIT bits, WORD bitslen, long& l);
bool bitRSet(LPCBIT bits, WORD bitslen, INT64& i64);
bool bitRSet(LPCBIT bits, WORD bitslen, DWORD64& i64);
bool bitRSet(LPCBIT bits, WORD bitslen, bool& b);

WORD bitRGetMsbPos(LPCBIT bits, WORD bitslen);
bool bitRSetMsbPos(LPBIT bits, WORD bitslen, long l);

void bitReverseOrder(LPBIT bits, WORD bitsLen);

#endif // __TKCORE__SMARTCARD__BIT_H