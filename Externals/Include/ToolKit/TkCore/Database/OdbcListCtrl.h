#ifndef __ODBC_LIST_CTRL_H
#define __ODBC_LIST_CTRL_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>
#include <SqlTypes.h>

// typedef int (CALLBACK* ODBCLISTCTRL_IMAGEPROC)(HWND hWnd, LPCSTR szText);

typedef int (CALLBACK* ODBCLISTCTRL_IMAGEPROC)(HWND hWnd, int count, LPCTSTR* pszText);

HWND OdbcListCtrl_CreateWindow(	HWND					hWndParent,
								DWORD					dwStyle,
								UINT					nId,
								int x,					int y,	int nWidth,	int nHeight);

HWND OdbcListCtrl_AttachListCtrl(HWND	hListCtrl); 

// A Suppimer des fonctions publiques :
BOOL OdbcListCtrl_DestroyWindow(HWND hOdbcListCtrl);

BOOL OdbcListCtrl_SetStatement(HWND hOdbcListCtrl, SQLHDBC hDbc, LPCTSTR szQuery, BOOL bResetHeader = TRUE);
VOID OdbcListCtrl_RefreshData(HWND hOdbcListCtrl);
VOID OdbcListCtrl_RefreshDisplay(HWND hOdbcListCtrl);

BOOL OdbcListCtrl_SetImageList(HWND						hOdbcListCtrl, 
							   WORD						resIdImgList,
							   ODBCLISTCTRL_IMAGEPROC	pImageCallBack,
							   int						indexTextCallBackCount,
							   const int*				cIndexTextCallBackArray);

BOOL OdbcListCtrl_SetColumnHeaderText(	HWND hOdbcListCtrl,	int cIndex, LPCTSTR szColName);
BOOL OdbcListCtrl_SetColumnHeaderSize(	HWND hOdbcListCtrl,	int cIndex, int size);
BOOL OdbcListCtrl_SetColumnVisible(		HWND hOdbcListCtrl,	int cIndex, BOOL bVisible);

INT		OdbcListCtrl_GetSelItemText(HWND hOdbcListCtrl, int cIndex, LPTSTR szText, int textMax);
VOID	OdbcListCtrl_SetSelItem(HWND hOdbcListCtrl, int cIndex, LPCTSTR szSearchText);

VOID	OdbcListCtrl_SetFirstItem(HWND hOdbcListCtrl, int cIndex);

#endif // __ODBC_LIST_CTRL_H