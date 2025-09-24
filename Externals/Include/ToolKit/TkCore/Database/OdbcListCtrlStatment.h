#ifndef __ODBC_LISTCTRL_STATMENT_H
#define __ODBC_LISTCTRL_STATMENT_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>
#include <SqlTypes.h>
/*
enum ODBCLISTCTRL_FETCH_MODE {
	ODBCLISTCTRL_FETCH_NEXT		= 1,
	ODBCLISTCTRL_FETCH_FIRST	= 2,
	ODBCLISTCTRL_FETCH_LAST		= 3,
	ODBCLISTCTRL_FETCH_PRIOR	= 4,
	ODBCLISTCTRL_FETCH_ABSOLUTE	= 5,
	ODBCLISTCTRL_FETCH_RELATIVE	= 6,
	ODBCLISTCTRL_FETCH_BOOKMARK = 8,
};
*/
#define ODBCLISTCTRL_COLUMN_NAMELEN		100

enum TODBCDRIVERTYPE {
	ODBCDRIVERTYPE__UNKNOWN	= 0,	///< Type de driver inconnu
	ODBCDRIVERTYPE__MSACCESS,		///< Base de donnée Access
	ODBCDRIVERTYPE__MSSQLSERVER,	///< Base de donnée SQL Server
	ODBCDRIVERTYPE__ORACLE,			///< Base de donnée Oracle
};

enum {
	ODBCLISTCTRL_BOOKMARK_NONE			= -2,
	ODBCLISTCTRL_BOOKMARK_NOTVISIBLE	= -1,
};

typedef DWORD64					TODBC_BOOKMARK;			///< Type de stockage des bookmark (convient au moins pour une base Access, voir pour d'autre...?)

typedef struct _TODBCLISTCTRL_STATMENT_COL {
	SQLTCHAR				szName[ODBCLISTCTRL_COLUMN_NAMELEN];	///< Nom de la colonne résultat
	SQLINTEGER				textMaxLen;								///< Taille max des textes contenus dans la colonne (en caractères)
	TCHAR					*pFetchedRowSet;						///< Donnée retournée par le dernier Fetch (nb lignes x taille de colonne)
	SQLINTEGER				*pFetchedLength;						///< Donnée retournée par le dernier Fetch (nb ligne)
} TODBCLISTCTRL_STATMENT_COL;

typedef struct _TODBCLISTCTRL_STATMENT {
	HWND						hRefListCtrl;			///< Référence vers le controle d'affichage

	SQLHDBC						hSqlDBC;				///< Handle vers la connexion ODBC
	TODBCDRIVERTYPE				dbType;					///< Type de la source de donnée

	SQLHSTMT					hSqlStmt;				///< Handle vers le statement ODBC
	
	SQLUINTEGER					rowCount;				///< Nombre total de lignes du statement
	SQLSMALLINT					columnCount;			///< Nombre de colonnes du statement

	SQLUINTEGER					fetchedRowCount;		///< Nombre de lignes retournée par le dernier Fetch
	TODBC_BOOKMARK				*pFetchedBookmark;		///< Bookmark de chaque ligne retournée par le dernier Fetch
	SQLUINTEGER					fetchedRowMax;			///< Nombre max actuel de ligne retournable par un fetch

	TODBCLISTCTRL_STATMENT_COL	*pColumns;				///< Colonnes de résultat (nb colonnes)

	TODBC_BOOKMARK				curBookmark;			///< Bookmark courant

	// Champs spécifiques pour la gestion d'une base accès
	SQLUINTEGER					curFetchedRow;			///< Numéro de la 1ère ligne retournée par le dernier Fetch

	LPTSTR						szQuery;	

} TODBCLISTCTRL_STATMENT;
typedef TODBCLISTCTRL_STATMENT			*PODBCLISTCTRL_STATMENT;
typedef const TODBCLISTCTRL_STATMENT	*PCODBCLISTCTRL_STATMENT;


PODBCLISTCTRL_STATMENT	OdbcListCtrlStatement_Create(HWND hRefListCtrl, SQLHDBC hDBC, LPCTSTR szQuery);
BOOL					OdbcListCtrlStatement_Destroy(PODBCLISTCTRL_STATMENT pStatement);
BOOL					OdbcListCtrlStatement_Requery(PODBCLISTCTRL_STATMENT pStatement);

long					OdbcListCtrlStatement_GetColCount(PODBCLISTCTRL_STATMENT pStatement);
long					OdbcListCtrlStatement_GetRowCount(PODBCLISTCTRL_STATMENT pStatement);

LPCTSTR					OdbcListCtrlStatement_GetColName(PODBCLISTCTRL_STATMENT pStatement, long column);
int						OdbcListCtrlStatement_GetColTextMaxLen(PODBCLISTCTRL_STATMENT pStatement, long column);

BOOL					OdbcListCtrlStatement_SetFetchedRowMaxCount(PODBCLISTCTRL_STATMENT pStatement, long count);
long					OdbcListCtrlStatement_GetFetchedRowCurrentCount(PODBCLISTCTRL_STATMENT pStatement);

BOOL					OdbcListCtrlStatement_FetchRow(PODBCLISTCTRL_STATMENT pStatement, long row);
BOOL					OdbcListCtrlStatement_FetchBookmark(PODBCLISTCTRL_STATMENT pStatement);
long					OdbcListCtrlStatement_GetFetchedRow(PODBCLISTCTRL_STATMENT pStatement);

LPCTSTR					OdbcListCtrlStatement_GetFetchedText(PODBCLISTCTRL_STATMENT pStatement, long row, long column);

long					OdbcListCtrlStatement_GetBookmarkFetchedRow(PODBCLISTCTRL_STATMENT pStatement);
BOOL					OdbcListCtrlStatement_SetBookmarkFetchedRow(PODBCLISTCTRL_STATMENT pStatement, long row);
BOOL					OdbcListCtrlStatement_SetBookmarkSearch(PODBCLISTCTRL_STATMENT pStatement, long column1, LPCSTR szText1);

long					OdbcListCtrlStatement_SearchRow(PODBCLISTCTRL_STATMENT pStatement, long column, LPCTSTR szSearchText);

#endif // __ODBC_LISTCTRL_STATMENT_H