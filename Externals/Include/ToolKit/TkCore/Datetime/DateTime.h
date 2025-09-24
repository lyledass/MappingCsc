#ifndef __INCLUDE_TKCORE_DATETIME_H
#define __INCLUDE_TKCORE_DATETIME_H

//#pragma once

#include <time.h>
#include <windows.h>

enum DATETIME_TYPEVALUE {
	DATETIME_YEAR,
	DATETIME_MONTH,
	DATETIME_DAY,
	DATETIME_HOUR,
	DATETIME_MINUTE,
	DATETIME_SECOND
};

// Date en calendrier hégirien / islamique
typedef struct
{
	unsigned short day;
	unsigned short month;
	unsigned short year;  //sur 4 chiffres
} THEGIRE_DATE;

// Heure
typedef struct
{
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
} THEGIRE_TIME;


/// <summary>Return TRUE if stDateTime is in a leap year</summary>
BOOL DateTime_IsLeapYear (WORD wYear);

/// <summary>Return the last days of the wMonth in the wYear</summary>
unsigned int DateTime_GetDaysInMonth (WORD wYear, WORD wMonth);

/// <summary>Add to the systime the value for the selected unit</summary>
BOOL DateTime_DateAdd (SYSTEMTIME *stDateTime, DATETIME_TYPEVALUE typeAdd, int value);

/// <summary>Set the current day of the month. If the day is greater than the max day in month, the last valid day is set.</summary>
BOOL DateTime_SetDayMonth (SYSTEMTIME *stDateTime, unsigned int iDayMonth);


DWORD64 DateTime_GetSystemTimeDiffMs(const SYSTEMTIME* pVal, const SYSTEMTIME* pRef);

// Convertit une heure format 24 (0-23) en heure au format 12 (1-12)
USHORT	Time_GetHourFormat12(USHORT uHour);

// Indique si l'heure est AM ou PM
bool	Time_IsHourPm(USHORT uHour);



///////////////////////////////////////////////////////
// Fonctions pour la gestion du calendrier islamique //
///////////////////////////////////////////////////////

// Nombre de mois
#define		HEGIRE_NB_MONTH_IN_YEAR		12

// Compare 2 date. Renvoie 0 si les 2 dates sont égales, >0 si date > dateRef, <0 si date < dateRef
int		Hegire_CompareDate(const THEGIRE_DATE* pHegireDate, const THEGIRE_DATE* pHegireDateRef);

// Années bisextiles dans le calendrier hégirien prévisionnel
bool	Hegire_IsLeapYear(USHORT uiYear);

// Nombre de jours d'un mois islamique
int		Hegire_GetNbDaysInMonth( int mon, bool bLeapYear );

// Nombre de jours d'une année islamique
int		Hegire_GetNbDaysInYear( bool bLeapYear );

// Nombre de jours entre 2 dates du calendrier islamique
long	Hegire_GetDayDiff(const THEGIRE_DATE* pHegireDate, const THEGIRE_DATE* pHegireDateRef);

// Jour de la semaine (de 1 à 7 avec Dimanche = 1, Lundi = 2 ...)
int		Hegire_GetDayOfWeek(const THEGIRE_DATE* pHegireDate);

#endif // __INCLUDE_TKCORE_DATETIME_H