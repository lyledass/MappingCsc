#ifndef __SQLSPECIALQUERYBUILER_INCLUDE_H__
#define __SQLSPECIALQUERYBUILER_INCLUDE_H__

#include <windows.h>
#include <tchar.h>
#include <list>

//GetQueryCompareHexToInt retourne une clause where pour chercher dans des champs en décimal une valeur partiel en héxadécimal

//szDecQuery: Clause where originale de recherche sur les décimales (peut-être NULL).
//szSearchField: Nom du champs sur laquelle s'effectue la recherche
//szValToCompare: valeur recherchée en héxadécimale
//szFilterField: Nom du champs sur laquelle s'effectue le filtre sur la liste
//listIdHex: Liste de filtre pour le test en héxadécimal. Si szFilterField appartient à la liste, on cherche en héxa, sinon on cherche en décimal avec szDecQuery

LPSTR GetQueryCompareHexToIntForOracleA(LPCSTR szDecQuery, LPCSTR szSearchField, LPCSTR szValToCompare, LPCSTR szFilterField, const std::list<int>& listIdHex);
LPWSTR GetQueryCompareHexToIntForOracleW(LPCWSTR szDecQuery, LPCWSTR szSearchField, LPCWSTR szValToCompare, LPCWSTR szFilterField, const std::list<int>& listIdHex);

LPSTR GetQueryCompareHexToIntForODBCA(LPCSTR szDecQuery, LPCSTR szSearchField, LPCSTR szValToCompare, LPCSTR szFilterField, const std::list<int>& listIdHex);
LPWSTR GetQueryCompareHexToIntForODBCW(LPCWSTR szDecQuery, LPCWSTR szSearchField, LPCWSTR szValToCompare, LPCWSTR szFilterField, const std::list<int>& listIdHex);

LPSTR GetQueryCompareHexToIntA(LPCSTR szDecQuery, LPCSTR szSearchField, LPCSTR szValToCompare, LPCSTR szFilterField, const std::list<int>& listIdHex, LPCSTR szFormatMod, LPCSTR szFormatDiv);
LPWSTR GetQueryCompareHexToIntW(LPCWSTR szDecQuery, LPCWSTR szSearchField, LPCWSTR szValToCompare, LPCWSTR szFilterField, const std::list<int>& listIdHex, LPCWSTR szFormatMod, LPCWSTR szFormatDiv);

#endif