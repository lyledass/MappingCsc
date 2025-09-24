#ifndef _LNG_MSG_DLG_H_
#define _LNG_MSG_DLG_H_

#include <windows.h>
#include <tchar.h>
#include <map>

//Represents texts for specific dialog or global messages (with iId = NO_DLG_ID)
class CLngMsgDlg
{
public:
	//Simple constructor
	CLngMsgDlg(int iId)
		: m_iId(iId)
	{}

	//Free the messages
	~CLngMsgDlg();

	//Id of the dialog or NO_DLG_ID for global messages
	int GetId() const {
		return m_iId;
	}
	
	//Returns specified message or NULL if message do not exists
	LPTSTR GetMsg(int iMsgId) const;

	//Adds specified message to map
	void AddMsg(int iMsgId, LPCTSTR szMsg);

private:
	//Id of the dialog or NO_DLG_ID for global messages
	int m_iId;

	//Map of messages type
	typedef std::map<int, LPTSTR> TMsgMap;

	//Map of messages
	TMsgMap m_msgMap;

};

#endif