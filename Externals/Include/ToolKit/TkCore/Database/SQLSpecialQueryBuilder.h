#ifndef __SQLSPECIALQUERYBUILER_INCLUDE_H__
#define __SQLSPECIALQUERYBUILER_INCLUDE_H__

#include <windows.h>
#include <tchar.h>
#include <list>

//GetQueryCompareHexToInt retourne une clause where pour chercher dans des champs en d�cimal une valeur partiel en h�xad�cimal

//szDecQuery: Clause where originale de recherche sur les d�cimales (peut-�tre NULL).
//szSearchField: Nom du champs sur laquelle s'effectue la recherche
//szValToCompare: valeur recherch�e en h�xad�cimale
//szFilterField: Nom du champs sur laquelle s'effectue le filtre sur la liste
//listIdHex: Liste de filtre pour le test en h�xad�cimal. Si szFilterField appartient � la liste, on cherche en h�xa, sinon on cherche en d�cimal avec szDecQuery

LPSTR GetQueryCompareHexToIntForOracleA(LPCSTR szDecQuery, LPCSTR szSearchField, LPCSTR szValToCompare, LPCSTR szFilterField, const std::list<int>& listIdHex);
LPWSTR GetQueryCompareHexToIntForOracleW(LPCWSTR szDecQuery, LPCWSTR szSearchField, LPCWSTR szValToCompare, LPCWSTR szFilterField, const std::list<int>& listIdHex);

LPSTR GetQueryCompareHexToIntForODBCA(LPCSTR szDecQuery, LPCSTR szSearchField, LPCSTR szValToCompare, LPCSTR szFilterField, const std::list<int>& listIdHex);
LPWSTR GetQueryCompareHexToIntForODBCW(LPCWSTR szDecQuery, LPCWSTR szSearchField, LPCWSTR szValToCompare, LPCWSTR szFilterField, const std::list<int>& listIdHex);

LPSTR GetQueryCompareHexToIntA(LPCSTR szDecQuery, LPCSTR szSearchField, LPCSTR szValToCompare, LPCSTR szFilterField, const std::list<int>& listIdHex, LPCSTR szFormatMod, LPCSTR szFormatDiv);
LPWSTR GetQueryCompareHexToIntW(LPCWSTR szDecQuery, LPCWSTR szSearchField, LPCWSTR szValToCompare, LPCWSTR szFilterField, const std::list<int>& listIdHex, LPCWSTR szFormatMod, LPCWSTR szFormatDiv);

#endif