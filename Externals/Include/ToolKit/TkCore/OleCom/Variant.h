#ifndef __TKCORE__OLECOM__VARIANT_H
#define __TKCORE__OLECOM__VARIANT_H

#pragma once

#include <Windows.h>
#include <OleAuto.h>

void VariantInitStringA(VARIANTARG* pvarg, LPCSTR szVal);

void VariantInitStringW(VARIANTARG* pvarg, LPCWSTR szVal);

void VariantInitBool(VARIANTARG* pvarg, BOOL bVal);

void VariantInitLong(VARIANTARG* pvarg, long lVal);

void VariantInitShort(VARIANTARG* pvarg, short sVal);

void VariantInitByte(VARIANTARG* pvarg, BYTE val);

void VariantInitOptional(VARIANTARG* pvarg);


#ifdef _UNICODE
	#define VariantInitString	VariantInitStringW
#else
	#define VariantInitString	VariantInitStringA
#endif

#endif // #__TKCORE__OLECOM__VARIANT_H