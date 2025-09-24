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

#ifndef __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_20_H
#define __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_20_H

#include <windows.h>

class ISmartCard20 {

public :

  // ------------------------------------------------------------
  // Constructeur		: SmartCard(DWORD sn)
  //
  // Description	: créé une nouvelle carte
  //
  // Argument(s)	: - sn (entrée), numéro de série de la carte
  // ------------------------------------------------------------
  ISmartCard20(DWORD sn) {
	m_serialNumber = sn;
	m_buffer = NULL;
	m_bufferLen = 0;
  }

  // ------------------------------------------------------------
  // Destructeur		: SmartCard()
  //
  // Description	: détruit une carte
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
  virtual VOID Commit() = 0;

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

protected :
	DWORD	m_serialNumber;
	BYTE*	m_buffer;
	int		m_bufferLen;
};

#endif /* __TKCORE__SMARTCARD__DEPRECATED_SDK__SMARTCARD_20_H */