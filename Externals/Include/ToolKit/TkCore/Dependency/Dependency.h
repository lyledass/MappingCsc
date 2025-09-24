#ifndef _DEPENDENCY_H
#define _DEPENDENCY_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../String/String.h"
#include "../String/ErgString.h"
#include "../ListExt.h"

struct TVersionStruct {
	int				m_iMajor;			// a version is eather composed by a major;
	int				m_iProject;			// a project,
	int				m_iMinor;			// a minor and
	int				m_iBuild;			// a build number
	CErgTString		m_szVersion;		// or a string
	bool			m_bStringVersion;	// and a bool indicating it

	TVersionStruct::TVersionStruct(int iMajor, int iProject, int iMinor, int iBuild) {		// constructor for version with numbers
		m_iMajor			= iMajor;
		m_iProject			= iProject;
		m_iMinor			= iMinor;
		m_iBuild			= iBuild;
		m_szVersion			= _T("");
		m_bStringVersion	= false;
	}

	TVersionStruct::TVersionStruct(LPCTSTR szVersion) {		// constructor for version with a string
		m_iMajor			= 0;
		m_iProject			= 0;
		m_iMinor			= 0;
		m_iBuild			= 0;
		m_szVersion			= szVersion;
		m_bStringVersion	= true;
	}

	TVersionStruct::TVersionStruct() {
		m_iMajor			= 0;
		m_iProject			= 0;
		m_iMinor 			= 0;
		m_iBuild 			= 0;
		m_szVersion			= _T("");
		m_bStringVersion	= false;
	}

	TVersionStruct::TVersionStruct(const TVersionStruct &refVersionStruct) {
		m_iMajor			= refVersionStruct.m_iMajor;
		m_iProject			= refVersionStruct.m_iProject;
		m_iMinor			= refVersionStruct.m_iMinor;
		m_iBuild			= refVersionStruct.m_iBuild;
		m_szVersion			= refVersionStruct.m_szVersion;
		m_bStringVersion	= refVersionStruct.m_bStringVersion;
	}

	TVersionStruct::~TVersionStruct() {
	}

	bool IsAccepted(const TVersionStruct &refVersionStruct, 
		bool bMax = false) const			// if bMax is precised (and true), build test must be inversed
	{
		bool	bRes ;

		if (! m_bStringVersion) {
			if (!bMax) {
				bRes = ((m_iMajor		== refVersionStruct.m_iMajor)
					&&	(m_iProject		== refVersionStruct.m_iProject)
					&&	(m_iMinor		== refVersionStruct.m_iMinor)
					&&	(m_iBuild		>= refVersionStruct.m_iBuild));	// current min version is accepted only if same major/project/minor and higher or same build
			} else {
				bRes = ((m_iMajor		== refVersionStruct.m_iMajor)
					&&	(m_iProject		== refVersionStruct.m_iProject)
					&&	(m_iMinor		== refVersionStruct.m_iMinor)
					&&	(m_iBuild		<= refVersionStruct.m_iBuild));	// current max version is accepted only if same major/project/minor and loower or same build
			}
		} else {
			bRes = (m_szVersion == refVersionStruct.m_szVersion);
		}

		return bRes;
	}

	const TVersionStruct& operator =(const TVersionStruct &refVersionStruct) {
		// Pour éviter l'auto-affectation
		if (this != &refVersionStruct) {
			m_bStringVersion	= refVersionStruct.m_bStringVersion;
			m_iMajor			= refVersionStruct.m_iMajor;
			m_iProject			= refVersionStruct.m_iProject;
			m_iMinor			= refVersionStruct.m_iMinor;
			m_iBuild			= refVersionStruct.m_iBuild;
			m_szVersion			= refVersionStruct.m_szVersion;
		}

		return (*this);
	}

	bool operator ==(const TVersionStruct &refVersionStruct) const {
		bool	bRes ;

		if (m_bStringVersion != refVersionStruct.m_bStringVersion) {
			bRes = false;		// not the same kind of version struct => struct are different
		} else if (! m_bStringVersion) {
			bRes = ((m_iMajor		== refVersionStruct.m_iMajor)
				&&	(m_iProject		== refVersionStruct.m_iProject)
				&&	(m_iMinor		== refVersionStruct.m_iMinor)
				&&	(m_iBuild		== refVersionStruct.m_iBuild));
		} else {
			bRes = (m_szVersion == refVersionStruct.m_szVersion);
		}

		return bRes;
	}
} ;

class CDependencyCheck {
public:
	CDependencyCheck();

	CDependencyCheck(LPCTSTR					szDeviceType, 
					LPCTSTR						szDllName, 
					const TVersionStruct&		fileVersion, 
					const TVersionStruct&		firmwareVersionMin, 
					const TVersionStruct&		firmwareVersionMax);

	~CDependencyCheck();

	CDependencyCheck::CDependencyCheck(const CDependencyCheck &refDependencyCheck) {
		m_szDeviceType			= refDependencyCheck.m_szDeviceType;
		m_szDllName				= refDependencyCheck.m_szDllName;
		m_fileVersion			= refDependencyCheck.m_fileVersion;
		m_firmwareVersionMin	= refDependencyCheck.m_firmwareVersionMin;
		m_firmwareVersionMax	= refDependencyCheck.m_firmwareVersionMax;
	}

	const CDependencyCheck& operator =(const CDependencyCheck &refDependencyCheck) {
		if (this != &refDependencyCheck) {
			m_szDeviceType			= refDependencyCheck.m_szDeviceType;
			m_szDllName				= refDependencyCheck.m_szDllName;
			m_fileVersion			= refDependencyCheck.m_fileVersion;
			m_firmwareVersionMin	= refDependencyCheck.m_firmwareVersionMin;
			m_firmwareVersionMax	= refDependencyCheck.m_firmwareVersionMax;
		}

		return (*this);
	}

	CErgTString			m_szDeviceType;
	CErgTString			m_szDllName;
	TVersionStruct		m_fileVersion;
	TVersionStruct		m_firmwareVersionMin;
	TVersionStruct		m_firmwareVersionMax;

	bool	VerifyDependencyFile(const TVersionStruct& currentFirmwareVersion = TVersionStruct(0,0,0,0));
} ;

class CDependencyCheckList : public CListExt<CDependencyCheck> {
public :
	CDependencyCheckList (bool bOr = false);
	~CDependencyCheckList ();

	void AddDependency(		LPCTSTR						szDeviceType, 
							LPCTSTR						szDllName, 
							const TVersionStruct&		fileVersion, 
							const TVersionStruct&		firmwareVersionMin,	
							const TVersionStruct&		firmwareVersionMax = TVersionStruct(0,0,0,0));

	void AddCurrentFirmware(
							const TVersionStruct&		firmwareCurrentVersion							// must be given by each dll
							);

	TVersionStruct		m_firmwareCurrentVersion;
	bool				m_bOr;								// indicates weither or not the depencies of the list are tested with an "or" (if true) or an "and" (false)

	bool				VerifyDependencyFileList();
};

#endif	// _DEPENDENCY_H