///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2000
//
// Fichier		: SmartCard.h
//
// Description	: Interface d'accès à une carte à puce
//
// Remarque(s)	: /
//
// Auteur       : A. PRUDENT (13/12/2000)
//
// Modif(s)     : /
//
///////////////////////////////////////////////////////////////

#ifndef __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_40_H
#define __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_40_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

class ISmartCard40 {

public :

  // ------------------------------------------------------------
  // Constructeur		: SmartCard(DWORD sn)
  //
  // Description	: créé une nouvelle carte
  //
  // Argument(s)	: - sn (entrée), numéro de série de la carte
  // ------------------------------------------------------------
  ISmartCard40(DWORD sn, BYTE ct, PCATR_BULK pAtrBulk) {
	m_serialNumber = sn;
	m_cardType = ct;
	m_buffer = NULL;
	m_bufferLen = 0;

	ATRBulk_Copy(pAtrBulk, &m_atrBulk);
  }

  // ------------------------------------------------------------
  // Destructeur		: SmartCard(DWORD sn)
  //
  // Description	: détruit une carte
  //
  // Argument(s)	: /
  // ------------------------------------------------------------
  virtual ~ISmartCard40() {
	  ATRBulk_Dispose(&m_atrBulk);

	  if (m_buffer) {
		  free(m_buffer);
		  m_buffer = NULL;
	  }
	  m_bufferLen = 0;
  }

  // ------------------------------------------------------------
  // Fonction		: DWORD serialNumber() CONST
  //
  // Description	: donne le numéro de série de la carte
  //
  // Argument(s)	: /
  //
  // Retour		: le numéro de série de la carte
  // ------------------------------------------------------------
  virtual DWORD SerialNumber() CONST {
	return m_serialNumber;
  }

  // ------------------------------------------------------------
  // Fonction		: LPCSTR GetCardName() CONST
  //
  // Description	: donne le nom de la carte (ex : GTML, Mifare...)
  //
  // Argument(s)	: /
  //
  // Retour		: le nom de la carte
  // ------------------------------------------------------------
  virtual LPCSTR GetCardName() CONST = 0;

  // ------------------------------------------------------------
  // Fonction		: BYTE GetCardType() CONST = 0;
  //
  // Description	: donne le type de la carte 
  //					(ex : )
  //
  // Argument(s)	: /
  //
  // Retour		: le type de la carte
  // ------------------------------------------------------------
  virtual BYTE GetCardType() CONST {
	return m_cardType;
  }

  // Fonction		: DWORD GetATR(LPBYTE atrBuf, DWORD atrBufMaxLen) CONST
  //
  // Description	: donne l'ATR de la carte
  //
  // Argument(s)	: - atrBuf (sortie) : buffer contenant l'ATR lue
  //                  - atrBufMaxLen (entrée) : taille maxi. de atrBuf
  //
  // Retour		: Nombre d'octets inscrits dans atrBuf 
  // ------------------------------------------------------------
  virtual DWORD	GetATR(LPBYTE atrBuf, DWORD atrBufMaxLen) CONST {
	DWORD	res;

	res = 0;
	if (atrBuf && m_atrBulk.pAtr) {
		memcpy(atrBuf, m_atrBulk.pAtr, min(atrBufMaxLen, m_atrBulk.atrLen));
		
		res = min(atrBufMaxLen, m_atrBulk.atrLen);
	}

	return res;
  }
  
  // ------------------------------------------------------------
  // Fonction		: VOID format()
  //
  // Description	: formate la carte
  //
  // Argument(s)	: /
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Format() = 0;

  // ------------------------------------------------------------
  // Fonction		: BOOL isInitialised() CONST
  //
  // Description	: indique si la carte a été initialisée
  //
  // Argument(s)	: /
  //
  // Retour		: TRUE si la carte est initialisée, FALSE sinon
  // ------------------------------------------------------------
  virtual BOOL IsInitialised() = 0;

  // ------------------------------------------------------------
  // Fonction		: VOID initialise()
  //
  // Description	: initialise la carte
  //
  // Argument(s)	: /
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Initialise() = 0;

  // ------------------------------------------------------------
  // Fonction		: VOID read(LPBYTE data, BYTE len, BYTE pos, BYTE sid = 0) CONST
  //
  // Description	: lit des octets de la carte
  //
  // Argument(s)	: - data (sortie), buffer contenant les bits lus
  //				  - spos (entrée), secteur ou SID à lire
  //				  - rpos (entrée), bloc ou enregistrement à lire
  //                  - bpos (entrée), position du premier bit à lire
  //				  - len (entrée), nombre de bits à lire
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Read(LPBIT data, WORD len, WORD spos, WORD bpos) = 0;

  // ------------------------------------------------------------
  // Fonction		: VOID write(LPBYTE data, BYTE len, BYTE pos, BYTE sid = 0)
  //
  // Description	: écrit des octets sur la carte
  //
  // Argument(s)	: - data (entrée), buffer contenant les octets à écrire
  //				  - spos (entrée), secteur ou SID à écrire
  //				  - rpos (entrée), bloc ou enregistrement à lire
  //                  - bpos (entrée), position du premier bit à écrire
  //				  - len (entrée), nombre de bits à écrire
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Write(LPCBIT data, WORD len, WORD spos, WORD bpos) = 0; 

  // ------------------------------------------------------------
  // Fonction		: VOID commit()
  //
  // Description	: valide l'écriture des données sur la carte
  //
  // Argument(s)	: /
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Commit(BOOL bDirectWrite = FALSE) = 0;

  // ------------------------------------------------------------
  // Fonction		: VOID eject()
  //
  // Description	: ejecte la carte du lecteur (si le lecteur supporte
  //                l'éjection de carte)
  //
  // Argument(s)	: /
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Eject() = 0;

  // ------------------------------------------------------------
  // Fonction		: VOID print(WORD pos, LPCTSTR msg)
  //
  // Description	: imprime un message sur la carte
  //
  // Argument(s)	: - pos (entrée), position de la ligne à écrire
  //                - msg (entrée), message à écrire
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Print(WORD pos, LPCTSTR msg) = 0;


  virtual BOOL IsCardPresent() = 0;

  virtual VOID Invalidate() = 0;

  virtual VOID Rehabilitate() = 0;

  virtual BOOL IsInvalidate() = 0;

  virtual BOOL ChangePin(CONST LPBYTE oldPin, CONST LPBYTE newPin) = 0;

  virtual BOOL VerifyPin(CONST LPBYTE pin) = 0;

  virtual BOOL CanSamWrite() {
	return TRUE;
  }

protected :
	DWORD		m_serialNumber;		///< Numéro de série de la carte
	BYTE		m_cardType;			///< Type de la carte
	
	BYTE*		m_buffer;			///< Buffer des données de la carte
	int			m_bufferLen;		///< Taille du buffer

	ATR_BULK	m_atrBulk;			///< ATR de la carte
};

#endif /* __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_40_H */