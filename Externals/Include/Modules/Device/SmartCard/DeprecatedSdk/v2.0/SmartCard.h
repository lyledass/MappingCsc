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

#ifndef __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_20_H
#define __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_20_H

#include <windows.h>

class ISmartCard20 {

public :

  // ------------------------------------------------------------
  // Constructeur		: SmartCard(DWORD sn)
  //
  // Description	: cr�� une nouvelle carte
  //
  // Argument(s)	: - sn (entr�e), num�ro de s�rie de la carte
  // ------------------------------------------------------------
  ISmartCard20(DWORD sn) {
	m_serialNumber = sn;
	m_buffer = NULL;
	m_bufferLen = 0;
  }

  // ------------------------------------------------------------
  // Destructeur		: SmartCard()
  //
  // Description	: d�truit une carte
  //
  // Argument(s)	: /
  // ------------------------------------------------------------
  virtual ~ISmartCard20() {
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
  // Fonction		: BYTE GetCardType() CONST;
  //
  // Description	: donne le type de la carte 
  //					(ex : )
  //
  // Argument(s)	: /
  //
  // Retour		: le type de la carte
  // ------------------------------------------------------------
  virtual BYTE GetCardType() CONST {
	return 1;	//	SC_TYPE_PUCE;
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
  virtual VOID Commit() = 0;

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

protected :
	DWORD	m_serialNumber;
	BYTE*	m_buffer;
	int		m_bufferLen;
};

#endif /* __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_20_H */