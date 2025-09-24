#ifndef __DIBMP_H
#define __DIBMP_H

#include <windows.h>

#define NB_INCH_PAR_MM		0.03937

HBITMAP		dib2Bitmap(HWND hWnd, HANDLE hDib);
BOOL		SaveBmpAsJpg(LPCTSTR szFilename, HBITMAP hbitmap, LPBITMAPINFOHEADER lpBmpInfoHeader);
HBITMAP		LoadJpgAsBmp(LPCTSTR szFilename, HDC hDeviceDC = NULL, LPBITMAPINFOHEADER lpBmpInfoHeader = NULL);

HBITMAP		StretchBitmap(HBITMAP bmp, int width, int height);
HBITMAP		CutBitmap(HBITMAP bmp, int x, int y, int width, int height, int shrinkPercent = 100);
HBITMAP		RotateBitmap(HDC hDC, HBITMAP hBmp, BOOL bSensAntiHoraire = TRUE);

HBITMAP		TkCreateDIBSection(HDC hDC, INT iWidth, INT iHeight);



//////////////////////////////////////////////////
//												//
//  Gestion des couleurs et de la transparence	//
//												//
//////////////////////////////////////////////////

// Indique si le HBITMAP a un canal alpha (canal alpha si 32 bits par pixel et au moins 1 pixel a une valeur alpha <> 0)
BOOL BitmapHasAlphaChannel(HBITMAP hBitmap);

// Supprime le canal alpha d'un bitmap
void BitmapRemoveAlphaChannel(HBITMAP hBitmap);

// Modifie la valeur alpha de tous les pixel du bitmap
BOOL BitmapChangeAlpha(HBITMAP hBitmap, BYTE alphaValue);

// Rend le bitmap opaque (utile si on souhaite utiliser AlphaBlend et que l'image n'a pas été chargé avec une composante alpha)
BOOL BitmapMakeOpaque(HBITMAP hBitmap);

// Copie un HBITMAP ARGB (en conservant la composante alpha)
HBITMAP BitmapCopy_ARGB(HBITMAP hBitmap, bool bMirrorH = false);

// Copie un HBITMAP RGB (sans converser la composante alpha), un peu plus rapide que la précédente
HBITMAP BitmapCopy_RGB(HBITMAP hBitmap, bool bMirrorH = false);

// Inverse un bitmap suivant l'axe X (symétrie) en ARGB
HBITMAP BitmapMirrorH_ARGB(HBITMAP hBitmap);

// Inverse un bitmap suivant l'axe X (symétrie) en RGB
HBITMAP BitmapMirrorH_RGB(HBITMAP hBitmap);


// Couleurs ARGB (compatible COLORREF(RGB))
typedef DWORD	COLORARGB;
#define COLORREF_TO_ARGB(clr, alpha)	((COLORARGB)((clr) & 0x00FFFFFF) | ((DWORD)((BYTE)(alpha))<<24))
#define	ARGB(a, r, g, b)	((COLORARGB)((RGB(r, g, b) & 0x00FFFFFF) | (((DWORD)(BYTE)(a))<<24)))
#define GetAValue(argb)		(LOBYTE((argb)>>24))
#define GetRGBValue(argb)	((COLORREF)((argb) & 0x00FFFFFF))

// Remplace une couleur RGB par une autre couleur RGB => pas d'utilisation de la composante alpha
BOOL BitmapReplaceColor1(HBITMAP hBitmap, COLORREF oldColor, COLORREF newColor);

// Remplace une couleur RGB (sans tenir compte de la valeur alpha) par une couleur ARGB => utilisation de la composante alpha
BOOL BitmapReplaceColor2(HBITMAP hBitmap, COLORREF oldColor, COLORARGB newColor);

// Remplace une couleur ARGB par une couleur ARGB => utilisation de la composante alpha
BOOL BitmapReplaceColor3(HBITMAP hBitmap, COLORARGB oldColor, COLORARGB newColor);


#endif /* __DIBMP_H */