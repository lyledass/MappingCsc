#ifndef __TKCORE__CYPHER__CYPHER_H
#define __TKCORE__CYPHER__CYPHER_H

#if _MSC_VER > 1000
#pragma once
#endif

#include <windows.h>

/*
typedef int			CRYPT_CTX;			// Handle sur structure general de cryptage
typedef CRYPT_CTX	CRYPT_ALGO_CTX;		// Handle sur donn�es de travailpour chaque algorithme
*/
DECLARE_HANDLE(CRYPT_CTX);				// Handle sur structure general de cryptage
DECLARE_HANDLE(CRYPT_ALGO_CTX);			// Handle sur donn�es de travailpour chaque algorithme

// -----------------------------------------------------------------------------------------
// Algorithme de cryptage � utiliser
// -----------------------------------------------------------------------------------------
enum CRYPT_ALGO {
   ALGO_NONE		= 0,
   ALGO_DES,
   ALGO_DESX,
   ALGO_MD5,
}; 

// --------------------- Mode de fonctionnement ---------------------------------------------
//	Pour passer en mode cryptage ou decryptage ( Utiliser pour le DES qui n'est pas 
//  compl�tement sym�trique )
// -----------------------------------------------------------------------------------------
enum CRYPT_DIR {
   CRYPT_DIR_ENCRYPT	= 0,
   CRYPT_DIR_DECRYPT,
};

// -------------------- Acces aux donn�es d'un algorithme ----------------------------------
// Les donn�es pouvant �tre demande � un contexte. Attention, tous ces champs ne sont pas 
// toujours accessible (depend de l'algorithme utilis�). Ces constantes sont utilis�es par 
// cryptInfoGet et cryptInfoSet
// -----------------------------------------------------------------------------------------
enum CRYPT_INFO_FIELD {
	CRYPT_INFO_BLOCKSIZE,			// Taille d'un bloc de donn�es
	CRYPT_INFO_DIGESTSIZE,			// Taille d'une empreinte (algorithme de hachage)
	CRYPT_INFO_ALGONAME,				// Nom de l'algorithme
	CRYPT_INFO_ALGONAME_LEN,			// Taille de la chaine de nom de l'algorithme
	CRYPT_INFO_KEY,					// Cle utilis�e
	CRYPT_INFO_KEYSIZE,				// Taille de la cl�
	CRYPT_INFO_IV,					// Vecteur d'intialisation utilis�e
	CRYPT_INFO_IVSIZE,				// Taille du vecteur d'initialisation
	CRYPT_INFO_ALGO,					// Algo tutilisee pour HMAC
	CRYPT_INFO_DIR,					// Encryption ouy decryption
};

// -----------------------------------------------------------------------------------------
// Les status retourn�s par les fonctions de cryptage. En particulier les code d'erreurs
// -----------------------------------------------------------------------------------------
enum CRYPT_STATUS {
	CRYPT_OK				= 0,
	CRYPT_ERR_MEMORY,					// Erreur d'allocation memoire
	CRYPT_ERR_HANDLE,					// Contexte non allou�
	CRYPT_ERR_BADUSE,					// Mauvaise utilisation
	CRYPT_ERR_UNKNOWN,					// Mauvais argument
	CRYPT_ERR_PARAM1,					// 1er Param�tre incorrect
	CRYPT_ERR_PARAM2,					// 2i�me Param�tre incorrect
	CRYPT_ERR_PARAM3,					// 3i�me Param�tre incorrect
	CRYPT_ERR_PARAM4,					// 4i�me Param�tre incorrect
	CRYPT_ERR_SELFTEST,                 // Self test algo en erreur
	CRYPT_ERR_NOT_SUPPORTED,
	CRYPT_ERR_COM,
	CRYPT_ERR_DATATOREAD,				// CRYPTAGE : Read a faire (un bloc traite)
	CRYPT_ERR_SIGNFILE,
	CRYPT_ERR_SIGNREAD,
	CRYPT_ERR_SIGNTEST,
};

// -----------------------------------------------------------------------------------------
// Fonctions g�n�riques d'acces � la librairie cryptographique
// -----------------------------------------------------------------------------------------
CRYPT_STATUS	cryptInit( CRYPT_ALGO algo, CRYPT_CTX * pCtx );
CRYPT_STATUS	cryptUpdate(CRYPT_CTX Ctx, BYTE * buffer, int len );
CRYPT_STATUS	cryptEnd(CRYPT_CTX Ctx, BYTE * buffer);
CRYPT_STATUS	cryptInfoGet( CRYPT_CTX Ctx, CRYPT_INFO_FIELD info, void * pData, int len );
CRYPT_STATUS	cryptInfoSet( CRYPT_CTX Ctx, CRYPT_INFO_FIELD info, void * pData, int len );

/* Wrapper courant pour l'obtention d'information */
#define  cryptSetKey(Ctx, key, key_len )	cryptInfoSet( Ctx, CRYPT_INFO_KEY, (void*) (key),				(key_len) )
#define  cryptSetDir(Ctx, dir )				cryptInfoSet( Ctx, CRYPT_INFO_DIR, (void*)(CRYPT_DIR) (dir),	sizeof(CRYPT_DIR) )
#define  cryptBlockSize( Ctx, BlSz )		cryptInfoGet( Ctx, CRYPT_INFO_BLOCKSIZE, &(BlSz), sizeof( BlSz ) )
#define  cryptDigestSize( Ctx, DgSz )		cryptInfoGet( Ctx, CRYPT_INFO_DIGESTSIZE, &(DgSz), sizeof( DgSz ) )


#endif  // __TKCORE__CYPHER__CYPHER_H
