///////////////////////////////////////////////////////////////
//
// Copyright	: (c) CIBEST 2000
//
// Fichier		: SmartCard.h
//
// Description	: Interface d'acc�s � une carte � puce
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
  // Description	: cr�� une nouvelle carte
  //
  // Argument(s)	: - sn (entr�e), num�ro de s�rie de la carte
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
  // Description	: d�truit une carte
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
  // Description	: donne le num�ro de s�rie de la carte
  //
  // Argument(s)	: /
  //
  // Retour		: le num�ro de s�rie de la carte
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
  //                  - atrBufMaxLen (entr�e) : taille maxi. de atrBuf
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
  // Description	: indique si la carte a �t� initialis�e
  //
  // Argument(s)	: /
  //
  // Retour		: TRUE si la carte est initialis�e, FALSE sinon
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
  //				  - spos (entr�e), secteur ou SID � lire
  //				  - rpos (entr�e), bloc ou enregistrement � lire
  //                  - bpos (entr�e), position du premier bit � lire
  //				  - len (entr�e), nombre de bits � lire
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Read(LPBIT data, WORD len, WORD spos, WORD bpos) = 0;

  // ------------------------------------------------------------
  // Fonction		: VOID write(LPBYTE data, BYTE len, BYTE pos, BYTE sid = 0)
  //
  // Description	: �crit des octets sur la carte
  //
  // Argument(s)	: - data (entr�e), buffer contenant les octets � �crire
  //				  - spos (entr�e), secteur ou SID � �crire
  //				  - rpos (entr�e), bloc ou enregistrement � lire
  //                  - bpos (entr�e), position du premier bit � �crire
  //				  - len (entr�e), nombre de bits � �crire
  //
  // Retour		: /
  // ------------------------------------------------------------
  virtual VOID Write(LPCBIT data, WORD len, WORD spos, WORD bpos) = 0; 

  // ------------------------------------------------------------
  // Fonction		: VOID commit()
  //
  // Description	: valide l'�criture des donn�es sur la carte
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
  //                l'�jection de carte)
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
  // Argument(s)	: - pos (entr�e), position de la ligne � �crire
  //                - msg (entr�e), message � �crire
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
	DWORD		m_serialNumber;		///< Num�ro de s�rie de la carte
	BYTE		m_cardType;			///< Type de la carte
	
	BYTE*		m_buffer;			///< Buffer des donn�es de la carte
	int			m_bufferLen;		///< Taille du buffer

	ATR_BULK	m_atrBulk;			///< ATR de la carte
};

#endif /* __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_40_H */