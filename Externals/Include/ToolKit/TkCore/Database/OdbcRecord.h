///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2001
//
// Fichier		: RECORD.H
//
// Description	: Définition de la classe CRecord
//                Enregistrement générique de base de données
//
// Contenu		: /
//
// Remarque(s)	: /
//
// Auteur       : D. MIODON (06/03/2001)
//
// Modif(s)     : /
//
///////////////////////////////////////////////////////////////


#ifndef	__TKCORE__DATABASE__RECORD_H
#define __TKCORE__DATABASE__RECORD_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <SqlTypes.h>
#include "OdbcDatabase.h"

enum TODBCRECORD_MOVE {
	ODBCRECORD_MOVE_FIRST		= 0,
	ODBCRECORD_MOVE_NEXT,
	ODBCRECORD_MOVE_PREVIOUS,
	ODBCRECORD_MOVE_LAST,
};

typedef BOOL				TSQL_BIT;
typedef BYTE				TSQL_TINYINT;	// !!! ce type n'est pas ANSI !!!
typedef short				TSQL_SMALLINT;
typedef long				TSQL_INTEGER;
typedef float				TSQL_REAL;
typedef double				TSQL_FLOAT;
typedef TCHAR				TSQL_CHAR;
typedef DATE_STRUCT			TSQL_DATE;
typedef TIME_STRUCT			TSQL_TIME;
typedef TIMESTAMP_STRUCT	TSQL_DATETIME;

typedef struct _TODBCRECORD {
	SQLHSTMT	hStmt;
			
	LPVOID		lpReserved;
} TODBCRECORD;

BOOL		OdbcRecord_Open(SQLHDBC hDbc, LPCTSTR lpszQuery, TODBCRECORD* pRecord, SQLTCHAR* sqlState = NULL);
BOOL		OdbcRecord_Open(PODBCDATABASE pDatabase, LPCTSTR lpszQuery, TODBCRECORD* pRecord);
VOID		OdbcRecord_Close(TODBCRECORD* pRecord);

BOOL		OdbcRecord_Move(TODBCRECORD* pRecord, TODBCRECORD_MOVE moveType = ODBCRECORD_MOVE_NEXT);

BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_BIT*		pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_TINYINT*	pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_SMALLINT*	pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_INTEGER*	pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_REAL*		pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_FLOAT*		pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_DATE*		pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_TIME*		pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_DATETIME*	pValue,		BOOL* pbIsNull = NULL);
BOOL		OdbcRecord_GetValue(TODBCRECORD* pRecord, LPCTSTR szFieldName, TSQL_CHAR*		szValue,	int valueTCharLen,	BOOL* pbIsNull = NULL);

BOOL		OdbcRecord_FormatDateTime(	const TSQL_DATETIME*	pSqlDateTime,	LPTSTR szText, size_t textChLen, BOOL* pbDateNull = NULL);
BOOL		OdbcRecord_FormatDate(		const TSQL_DATE*		pSqlDate,		LPTSTR szText, size_t textChLen, BOOL* pbDateNull = NULL);
BOOL		OdbcRecord_FormatTime(		const TSQL_TIME*		pSqlTime,		LPTSTR szText, size_t textChLen);
BOOL		OdbcRecord_FormatString(	LPCTSTR					szValue,		LPTSTR szText, size_t textChLen);

/*
///////////////////////////////////////////////////////////////
// Classe CRecord
///////////////////////////////////////////////////////////////

class CRecord : public CRecordset {
	DECLARE_DYNAMIC(CRecord)

	protected:

	// Fonctions virtuelles surchargées (générées par ClassWizard)
	// -----------------------------------------------------------
	//{{AFX_VIRTUAL(CRecord)
	public:
		virtual void DoFieldExchange (CFieldExchange*) {};
		virtual void AddNew ();
		virtual void Edit ();
		virtual BOOL Update ();
		virtual void Close();
		virtual short GetFieldIndexByName(LPCTSTR lpszFieldName);
		virtual void GetFieldValue(LPCTSTR lpszName, CDBVariant& varValue, short nFieldType = DEFAULT_FIELD_TYPE);
		virtual void GetFieldValue(short nIndex, CDBVariant& varValue, short nFieldType = DEFAULT_FIELD_TYPE);
		virtual void GetFieldValue(LPCTSTR lpszName, CString& strValue);
		virtual void GetFieldValue(short nIndex, CString& strValue);
		virtual BOOL Open (UINT = AFX_DB_USE_DEFAULT_TYPE, LPCTSTR = NULL, DWORD = CRecordset::none, int numIteration = 0);
	//}}AFX_VIRTUAL

	// Implémentation
	// --------------
	public:

		CRecord (CDatabase* pdb = NULL);
		virtual ~CRecord ();

	#ifdef _DEBUG
		virtual void AssertValid () const;
		virtual void Dump (CDumpContext&) const;
	#endif
	
public :
		void GetValue (short	nIndex, TSQL_INTEGER*	pValue);
		void GetValue (LPCTSTR	szName, TSQL_INTEGER*	pValue);
		void GetValue (short	nIndex, TSQL_SMALLINT*	pValue);
		void GetValue (LPCTSTR	szName, TSQL_SMALLINT*	pValue);
		void GetValue (short	nIndex, TSQL_REAL*		pValue);
		void GetValue (LPCTSTR	szName, TSQL_REAL*		pValue);
		void GetValue (short	nIndex, TSQL_FLOAT*		pValue);
		void GetValue (LPCTSTR	szName, TSQL_FLOAT*		pValue);
		void GetValue (short	nIndex, TSQL_TIMESTAMP*	pValue, TSQL_TIMESTAMP* pOnNullValue = NULL);
		void GetValue (LPCTSTR	szName, TSQL_TIMESTAMP*	pValue, TSQL_TIMESTAMP* pOnNullValue = NULL);
		void GetValue (short	nIndex, TSQL_TINYINT*	pValue);
		void GetValue (LPCTSTR	szName, TSQL_TINYINT*	pValue);
		void GetValue (short	nIndex, TSQL_CHAR*		pValue);
		void GetValue (LPCTSTR	szName, TSQL_CHAR*		pValue);
		void GetValue (short	nIndex, TSQL_BIT*		pValue);
		void GetValue (LPCTSTR	szName, TSQL_BIT*		pValue);

		void GetFormat (short	nIndex, LPTSTR		szValue, size_t count);
		void GetFormat (short	nIndex, CString*	pValue);
		void GetFormat (LPCTSTR	szName, LPTSTR		szValue, size_t count);
		void GetFormat (LPCTSTR	szName, CString*	pValue);

	protected:
		void ColumnNames ();

		void GetValue (short	nIndex, CDBVariant*		pValue);
		void GetValue (LPCTSTR	szName, CDBVariant*		pValue);

		BOOL GetValue (short	nIndex, void*			pValue, short nFieldType = DEFAULT_FIELD_TYPE);
		BOOL GetValue (LPCTSTR	szName, void*			pValue, short nFieldType = DEFAULT_FIELD_TYPE);

		int PASCAL GetTextLenEx (short nSQLType, UDWORD nPrecision);
		void GetFieldValueEx (LPCTSTR szName, CString& szValue);
		void GetFieldValueEx (short nIndex, CString& szValue);
		BOOL GetFieldVariant (short nIndex, CDBVariant* pValue, short nFieldType = DEFAULT_FIELD_TYPE);
		BOOL GetFieldVariant (LPCTSTR szName, CDBVariant* pValue, short nFieldType = DEFAULT_FIELD_TYPE);
		BOOL GetValueEx (CDBVariant* pFieldValue, void* pValue);
		void GetFormatEx (CDBVariant* pFieldValue, LPTSTR szValue, size_t count);
};

*/
#endif	// __TKCORE__DATABASE__RECORD_H
