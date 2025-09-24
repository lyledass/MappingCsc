#ifndef _LNG_MSG_ROOT_H_
#define _LNG_MSG_ROOT_H_

#include "LngFile.h"
#include "LngMsgFile.h"

//Root object for language files management
class CLngMsgRoot
{
public:
	//Simple constructor
	CLngMsgRoot()
		: m_iCurrentLngId(-1), m_pLastFile(NULL), m_pHookProc(NULL)
	{}

	//Will call Clear
	~CLngMsgRoot() {
		Clear();
	}

	//Will clear all internal structures
	void Clear();

	//Sets current language id
	void SetCurrentLanguage(int iLngId) {
		m_iCurrentLngId = iLngId;
	}

	//Returns current language id
	int GetCurrentLanguage() const {
		return m_iCurrentLngId;
	}

	//Sets hook procedure called on every GetMsg call
	void SetHookProc(LNGHOOKPROC pHookProc) {
		m_pHookProc = pHookProc;
	}

	//Adds language file to map
	void AddFile(int iLngId, LPCTSTR szLngDigram, LPCTSTR szFileName);

	//Fills global message for current language
	int GetMsg(int iMsgId, LPTSTR szMsg, size_t iMsgCharLen, LPCTSTR szDefMsg);

	//Fills dialog text for current language
	bool GetDlgText(int iDlgId, int iCtrlId, LPTSTR szMsg, size_t iMsgCharLen);

private:
	//Returns message for specified language and dialog or NULL if not exists
	LPTSTR GetMsg(int iLngId, int iDlgId, int iMsgId);

	//Will copy string and replace all '|' with '\n'
	static void CopyMsg(LPTSTR szDest, size_t iDestLen, LPCTSTR szSrc);

	//Will get file with specified id or NULL if not exists
	CLngMsgFile* GetFile(int iLngId);

	//Current language id
	int m_iCurrentLngId;

	//File map type
	typedef std::map<int, CLngMsgFile*> TFileMap;

	//File map
	TFileMap m_fileMap;

	//Last used file for GetFile
	CLngMsgFile* m_pLastFile;

	//Hook procedure called on every GetMsg call
	LNGHOOKPROC m_pHookProc;

};

#endif