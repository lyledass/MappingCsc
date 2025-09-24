#ifndef _MAPPING_AGENT_H
#define _MAPPING_AGENT_H

#include "Mapping.h"

class CMappingAgent: public CMapping {
public:
	CMappingAgent(LPCTSTR szFilename, WORD version);
	CMappingAgent(const CMappingAgent& otherMapping);
	virtual ~CMappingAgent();

	CMappingAgent*		MakeCopie() const;


	CMapAgent&			GetAgent();
	const CMapAgent&	GetAgent() const;

protected:
	virtual CMapping*	MakeCopieInternal() const;
	virtual void		ParseEnd();


private:
	CMapAgent		m_agentInfo;				// Les info de l'application Agent
};

#endif //_MAPPING_AGENT_H
