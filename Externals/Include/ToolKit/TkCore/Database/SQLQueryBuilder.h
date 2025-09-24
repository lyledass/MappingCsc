#ifndef __SQLQUERYBUILER_INCLUDE_H__
#define __SQLQUERYBUILER_INCLUDE_H__

#pragma once

#include <windows.h>
#include <tchar.h>
#include "../ListExt.h"
#include "../ErgNumber/CErgNumber.h"

class CSQLQueryBuilder
{
public:
	CSQLQueryBuilder(void);
	~CSQLQueryBuilder(void);

	LPCTSTR						GetSQLQueryText();
	void						Clear();

protected:
	virtual LPTSTR				DoGetSQLQueryText() = 0;
	virtual void				DoClear() = 0;

private:
	LPTSTR						m_szQuery; // Sert à stocker la chaîne de la requete 

};

class CSQLQueryBuilderSelect : public CSQLQueryBuilder
{
public:
	CSQLQueryBuilderSelect(void);
	~CSQLQueryBuilderSelect(void);

	void						AddField(LPCTSTR szField);
	void						AddFieldWithTablename(LPCTSTR szTable, LPCTSTR szField, LPCTSTR szNewFieldName = NULL);
	void						AddTable(LPCTSTR szTable);

	void						AddWhereClause(LPCTSTR szWhereClause, bool bAddParentheses = false);

	void						AddWhereClauseEq(LPCTSTR szField, LPCTSTR szValue, bool bAddQuote = true);
	void						AddWhereClauseEq(LPCTSTR szField, long lValue);
	void						AddWhereClauseEq(LPCTSTR szField, unsigned long lValue);
	void						AddWhereClauseEq(LPCTSTR szField, int iValue);
	void						AddWhereClauseEq(LPCTSTR szField, unsigned int iValue);
	void						AddWhereClauseEq(LPCTSTR szField, float fValue);
	void						AddWhereClauseEq(LPCTSTR szField, double dValue);
	void						AddWhereClauseEq(LPCTSTR szField, const CErgNumber& nbValue);
	void						AddWhereClauseEq(LPCTSTR szTableName1, LPCTSTR szField1, LPCTSTR szTableName2, LPCTSTR szField2);

	void						AddOrderClause(LPCTSTR szOrderClause);
	void						AddOrderClause(LPCTSTR szTableName, LPCTSTR szField, bool bDesc = false);

protected:
	virtual LPTSTR				DoGetSQLQueryText();
	virtual void				DoClear();

private:
	CListExt<LPTSTR>			m_listField;
	CListExt<LPTSTR>			m_listTable;
	CListExt<LPTSTR>			m_listWhereClause;
	CListExt<LPTSTR>			m_listOrderClause;
};

class CSQLQueryBuilderInsert : public CSQLQueryBuilder
{
public:
	CSQLQueryBuilderInsert(LPCTSTR szTable);
	~CSQLQueryBuilderInsert(void);

	void						AddFieldValue(LPCTSTR szField, LPCTSTR szValue, bool bAddQuote = true);
	void						AddFieldValue(LPCTSTR szField, long lValue);
	void						AddFieldValue(LPCTSTR szField, unsigned long lValue);
	void						AddFieldValue(LPCTSTR szField, int iValue);
	void						AddFieldValue(LPCTSTR szField, unsigned int iValue);
	void						AddFieldValue(LPCTSTR szField, float fValue);
	void						AddFieldValue(LPCTSTR szField, double dValue);
	void						AddFieldValue(LPCTSTR szField, const CErgNumber& nbValue);

	CSQLQueryBuilderSelect*		GetSqlQueryBuilderSelectFromInsert(bool bAddFieldInSelectClause = false, bool bFieldWithTableName = false, bool bSetFieldName = false);

protected:
	LPTSTR						DoGetSQLQueryText();
	virtual void				DoClear();

private:
	LPTSTR						m_szTable;
	CListExt<LPTSTR>			m_listField;
	CListExt<LPTSTR>			m_listValue;
};

class CSQLQueryBuilderUpdate : public CSQLQueryBuilder
{
public:
	CSQLQueryBuilderUpdate(LPCTSTR szTable);
	~CSQLQueryBuilderUpdate(void);

	void						AddFieldValue(LPCTSTR szField, LPCTSTR szValue, bool bAddQuote = true);
	void						AddFieldValue(LPCTSTR szField, long lValue);
	void						AddFieldValue(LPCTSTR szField, unsigned long lValue);
	void						AddFieldValue(LPCTSTR szField, int iValue);
	void						AddFieldValue(LPCTSTR szField, unsigned int iValue);
	void						AddFieldValue(LPCTSTR szField, float fValue);
	void						AddFieldValue(LPCTSTR szField, double dValue);
	void						AddFieldValue(LPCTSTR szField, const CErgNumber& nbValue);

	void						AddWhereClause(LPCTSTR szWhereClause, bool bAddParentheses = false);

	void						AddWhereClauseEq(LPCTSTR szField, LPCTSTR szValue, bool bAddQuote = true);
	void						AddWhereClauseEq(LPCTSTR szField, long lValue);
	void						AddWhereClauseEq(LPCTSTR szField, unsigned long lValue);
	void						AddWhereClauseEq(LPCTSTR szField, int iValue);
	void						AddWhereClauseEq(LPCTSTR szField, unsigned int iValue);
	void						AddWhereClauseEq(LPCTSTR szField, float fValue);
	void						AddWhereClauseEq(LPCTSTR szField, double dValue);
	void						AddWhereClauseEq(LPCTSTR szField, const CErgNumber& nbValue);
	void						AddWhereClauseEq(LPCTSTR szTableName1, LPCTSTR szField1, LPCTSTR szTableName2, LPCTSTR szField2);

protected:
	LPTSTR						DoGetSQLQueryText();
	virtual void				DoClear();

private:
	LPTSTR						m_szTable;
	CListExt<LPTSTR>			m_listField;
	CListExt<LPTSTR>			m_listValue;
	CListExt<LPTSTR>			m_listWhereClause;
};


#endif __SQLQUERYBUILER_INCLUDE_H__