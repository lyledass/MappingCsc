#ifndef __CSCMAPPING__MAPPINGTYPE_H
#define __CSCMAPPING__MAPPINGTYPE_H

// Application type (instanciations)
typedef enum {
	APPLICATION_TYPE_INTERCODE		= 1,	// transport Intercode
	APPLICATION_TYPE_DIOMAG			= 2,	// Agent (Dijon)
	APPLICATION_TYPE_STORE_VALUE	= 3,	// Store value
	APPLICATION_TYPE_INTERTIC		= 4,	// Intertic
	APPLICATION_TYPE_NDOT			= 5,	// NDot
} TTYPE_APPLICATION;


// Application type names
#define		APPLICATION_TYPE_INTERCODE_NAME		_T("Intercode")
#define		APPLICATION_TYPE_INTERTIC_NAME		_T("Intertic")
#define		APPLICATION_TYPE_DIOMAG_NAME		_T("DiOmag")
#define		APPLICATION_TYPE_STORE_VALUE_NAME	_T("StoreValue")
#define		APPLICATION_TYPE_NDOT_NAME			_T("NDot")


// Get AppType name from type
LPCTSTR		MappingGetAppTypeName(TTYPE_APPLICATION	eAppType);
// Get application type from name
bool		MappingGetAppType(LPCTSTR szAppTypeName, TTYPE_APPLICATION &eAppType);


// Get Card name from mapping filename : "CD97.165.bmf" => "CD97"
bool		MappingFileGetCardName(LPCTSTR szFilename, LPTSTR szCardName, size_t uiBufferLen);

// Get Card application type name from mapping filename : "CD97-Intercode.165.bmf" => "Intercode"
bool		MappingFileGetAppTypeName(LPCTSTR szFilename, LPTSTR szAppTypeName, size_t uiBufferLen);

// Get Card application type from mapping filename : "CD97-Intercode.165.bmf" => APPLICATION_TYPE_INTERCODE
bool		MappingFileGetAppType(LPCTSTR szFilename, TTYPE_APPLICATION& eAppType);

// Get mapping version from mapping filename : "CD97-Intercode.165.bmf" => 165
bool		MappingFileGetVersion(LPCTSTR szFilename, unsigned long& ulVersion);

#endif //__CSCMAPPING__MAPPINGTYPE_H
