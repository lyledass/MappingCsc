#ifndef __TKCORE__DATABASE__ODBC_DATABASE_H
#define __TKCORE__DATABASE__ODBC_DATABASE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <SqlTypes.h>

#define		NB_MAX_RETRY			3
#define		CONNECTION_STRING_SIZE	1024
#define		SQL_STATE_SIZE			6

// #define REQ_FORMAT_DB_DATE		_T("{d '%Y-%m-%d'}")
// #define REQ_FORMAT_DB_DATETIME	_T("{ts '%Y-%m-%d %H:%M:%S'}")

enum TODBCVERS {
	ODBCVERS_ODBC2	= 2,
	ODBCVERS_ODBC3,
};

typedef struct _TODBCDATABASE {
	SQLHENV		hEnv;
	SQLHDBC		hDbc;
	TCHAR		lpszConnectString[CONNECTION_STRING_SIZE];
	TODBCVERS	odbcVersion;
} TODBCDATABASE;

typedef TODBCDATABASE	*PODBCDATABASE;

BOOL	OdbcDatabase_Open(LPCTSTR lpszConnectString, PODBCDATABASE pDatabase, TODBCVERS odbcVersion = ODBCVERS_ODBC3);
VOID	OdbcDatabase_Close(PODBCDATABASE pDatabase);

BOOL	OdbcDatabase_ExecSQL(SQLHDBC hDbc, LPCTSTR lpszSQL, SQLTCHAR* sqlState = NULL);

BOOL	OdbcDatabase_TableExists(SQLHDBC hDbc, LPCTSTR	lpszTableName, SQLTCHAR* sqlState = NULL);
BOOL	OdbcDatabase_TableFieldExists(SQLHDBC hDbc, LPCTSTR lpszTableName, LPCTSTR lpszFieldName, SQLTCHAR* sqlState = NULL);

BOOL	OdbcDatabase_ExecSQL(PODBCDATABASE pDatabase, LPCTSTR lpszSQL);

BOOL	OdbcDatabase_TableExists(PODBCDATABASE pDatabase, LPCTSTR	lpszTableName);
BOOL	OdbcDatabase_TableFieldExists(PODBCDATABASE pDatabase, LPCTSTR lpszTableName, LPCTSTR lpszFieldName);

#endif // __TKCORE__DATABASE__ODBC_DATABASE_H
