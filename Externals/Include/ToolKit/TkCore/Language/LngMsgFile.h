#ifndef _LNG_MSG_FILE_H_
#define _LNG_MSG_FILE_H_

#include "LngMsgDlg.h"

//Id of dialog for global messages
#define NO_DLG_ID -1

//Represents one file and one language
class CLngMsgFile
{
public:
	//Simple constructor
	CLngMsgFile(int iLngId, LPCTSTR szLngDigram, LPCTSTR szFileName);

	//Delete all dialogs and internal strings
	~CLngMsgFile();

	//Language id
	int GetLngId() const {
		return m_iLngId;
	}
	
	//Returns message for specified dialog or NULL if not exists
	LPTSTR GetMsg(int iDlgId, int iMsgId);

private:
	//Locking of Load
	CRITICAL_SECTION m_csLock;

	//Language id
	int m_iLngId;

	//Language digram
	LPTSTR m_szLngDigram;

	//Language file name
	LPTSTR m_szFileName;

	//Map of dialogs type
	typedef std::map<int, CLngMsgDlg*> TDlgMap;

	//Map of dialogs
	TDlgMap m_dlgMap;

	//Indicate that messages were already loaded
	bool m_bLoaded;

	//Indicate that during loading we are processing section for language specified by digram
	bool m_bSectionLoaded;

	//Last used dialog (for GetDlg and AddDlg)
	CLngMsgDlg* m_pLastDlg;

	//Returns dialog with specified id or NULL if not exists
	CLngMsgDlg* GetDlg(int iDlgId);

	//Returns dialog with specified id or create new one if not exists
	CLngMsgDlg* AddDlg(int iDlgId);

	//Will add message for specified dialog
	void AddMsg(int iDlgId, int iMsgId, LPCTSTR szMsg);

	//Will check if content of language file was already loaded and if not, will load it (using DoLoad)
	void Load();

	//Internal method for loading content of language file
	void DoLoad();

	//Will parse line loaded from language file
	void ParseLine(LPWSTR szLine);

	//Will remove white spaces and comment from string and returns trimmed string
	static LPTSTR ParseEmpty(LPTSTR szLine);

	//Will return section name if line is section specification or NULL if not
	static LPTSTR ParseSection(LPTSTR szLine);

	//Will return value from key=value line or NULL if not successful
	static LPTSTR ParseValue(LPTSTR szLine);

	//Will parse dialog id and message id from key, returns true if successful
	static bool ParseKey(LPTSTR szKey, int& iDlgId, int& iMsgId);

};

#endif