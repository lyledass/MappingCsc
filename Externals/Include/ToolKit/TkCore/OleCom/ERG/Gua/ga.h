
#include <windows.h>
#include <Oleauto.h>

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Thu Mar 29 10:42:40 2007
 */
/* Compiler settings for .\GA.IDL:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __ga_h__
#define __ga_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___clsGA_FWD_DEFINED__
#define ___clsGA_FWD_DEFINED__
typedef interface _clsGA _clsGA;
#endif 	/* ___clsGA_FWD_DEFINED__ */


#ifndef ___clsSystemInfo_FWD_DEFINED__
#define ___clsSystemInfo_FWD_DEFINED__
typedef interface _clsSystemInfo _clsSystemInfo;
#endif 	/* ___clsSystemInfo_FWD_DEFINED__ */


#ifndef ___clsLocaleSettings_FWD_DEFINED__
#define ___clsLocaleSettings_FWD_DEFINED__
typedef interface _clsLocaleSettings _clsLocaleSettings;
#endif 	/* ___clsLocaleSettings_FWD_DEFINED__ */


#ifndef ___clsDroitSoft_FWD_DEFINED__
#define ___clsDroitSoft_FWD_DEFINED__
typedef interface _clsDroitSoft _clsDroitSoft;
#endif 	/* ___clsDroitSoft_FWD_DEFINED__ */


#ifndef ___clsArchive_FWD_DEFINED__
#define ___clsArchive_FWD_DEFINED__
typedef interface _clsArchive _clsArchive;
#endif 	/* ___clsArchive_FWD_DEFINED__ */


#ifndef __clsGA_FWD_DEFINED__
#define __clsGA_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsGA clsGA;
#else
typedef struct clsGA clsGA;
#endif /* __cplusplus */

#endif 	/* __clsGA_FWD_DEFINED__ */


#ifndef __clsSystemInfo_FWD_DEFINED__
#define __clsSystemInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsSystemInfo clsSystemInfo;
#else
typedef struct clsSystemInfo clsSystemInfo;
#endif /* __cplusplus */

#endif 	/* __clsSystemInfo_FWD_DEFINED__ */


#ifndef __clsLocaleSettings_FWD_DEFINED__
#define __clsLocaleSettings_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsLocaleSettings clsLocaleSettings;
#else
typedef struct clsLocaleSettings clsLocaleSettings;
#endif /* __cplusplus */

#endif 	/* __clsLocaleSettings_FWD_DEFINED__ */


#ifndef __clsDroitSoft_FWD_DEFINED__
#define __clsDroitSoft_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsDroitSoft clsDroitSoft;
#else
typedef struct clsDroitSoft clsDroitSoft;
#endif /* __cplusplus */

#endif 	/* __clsDroitSoft_FWD_DEFINED__ */


#ifndef __clsArchive_FWD_DEFINED__
#define __clsArchive_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsArchive clsArchive;
#else
typedef struct clsArchive clsArchive;
#endif /* __cplusplus */

#endif 	/* __clsArchive_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __GA_LIBRARY_DEFINED__
#define __GA_LIBRARY_DEFINED__

/* library GA */
/* [custom][version][uuid] */ 






//typedef /* [public][public][version][uuid] */  DECLSPEC_UUID("7769E807-F2E3-4C81-96E3-B44B355C6847") 
enum ModeAffichage
    {	byModal	= 1,
	byModalLess	= 0
    };

//typedef /* [public][public][version][uuid] */  DECLSPEC_UUID("A3F2CC98-D19D-49C4-9FD6-D4767A27A974") 
enum OS_VERSION
    {	OS_WINDOWS_UNKNOWN	= 0,
	OS_WINDOWS_3X	= 1,
	OS_WINDOWS_95	= 2,
	OS_WINDOWS_98	= 3,
	OS_WINDOWS_NT3X	= 4,
	OS_WINDOWS_NT40	= 5,
	OS_WINDOWS_2000	= 6,
	OS_WINDOWS_XP	= 7,
	OS_WINDOWS_2003	= 8
    };

//typedef /* [public][version][uuid] */  DECLSPEC_UUID("2E024ECF-F70D-48B8-81DD-D851D07830CD") 
enum Flag
    {	flgOFF	= 0,
	flgON	= 1
    };


//typedef /* [public][public][version][uuid] */  DECLSPEC_UUID("A00B0499-348A-423F-848C-405776BEAE2B") 
enum DRIVE_TYPE
    {	
		DRIVE_DOESNT_EXIST	= 1,
/*		DRIVE_REMOVABLE	= 2,
		DRIVE_FIXED	= 3,
		DRIVE_REMOTE	= 4,
		DRIVE_CDROM	= 5,
		DRIVE_RAMDISK	= 6*/
    };

EXTERN_C const IID LIBID_GA;

#ifndef ___clsGA_INTERFACE_DEFINED__
#define ___clsGA_INTERFACE_DEFINED__

/* interface _clsGA */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsGA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB3CD7F0-8FE6-49A8-84FD-92F2A39CD3F5")
    _clsGA : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsTypeSqlServer( 
            /* [retval][out] */ long *__MIDL_0010) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsTypeOracle( 
            /* [retval][out] */ long *__MIDL_0011) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetColArchive( 
            /* [out][in] _Collection */ IUnknown **Col) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ServerName2( 
            /* [out][in] */ BSTR *__MIDL_0012) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ServerName2( 
            /* [retval][out] */ BSTR *__MIDL_0013) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsMaitre( 
            /* [retval][out] */ long *__MIDL_0014) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsEsclave( 
            /* [retval][out] */ BSTR *__MIDL_0015) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LoginSuperviseur( 
            /* [retval][out] */ BSTR *__MIDL_0016) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PasswordSuperviseur( 
            /* [retval][out] */ BSTR *__MIDL_0017) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsTraceBDD( 
            /* [retval][out] */ long *__MIDL_0018) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsTraceLog( 
            /* [retval][out] */ long *__MIDL_0019) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ServerName( 
            /* [out][in] */ BSTR *__MIDL_0020) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ServerName( 
            /* [retval][out] */ BSTR *__MIDL_0021) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Nom_Base( 
            /* [out][in] */ BSTR *__MIDL_0022) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Nom_Base( 
            /* [retval][out] */ BSTR *__MIDL_0023) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DriverName( 
            /* [out][in] */ BSTR *__MIDL_0024) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DriverName( 
            /* [retval][out] */ BSTR *__MIDL_0025) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Nombre_Max_Essai( 
            /* [out][in] */ short *__MIDL_0026) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Nombre_Max_Essai( 
            /* [retval][out] */ short *__MIDL_0027) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getIDUtilisateur( 
            /* [retval][out] */ long *__MIDL_0028) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getNom( 
            /* [retval][out] */ BSTR *__MIDL_0029) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getPrenom( 
            /* [retval][out] */ BSTR *__MIDL_0030) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getLogin( 
            /* [retval][out] */ BSTR *__MIDL_0031) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getMaster( 
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0032) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getMatricule( 
            /* [retval][out] */ BSTR *__MIDL_0033) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getDateCreation( 
            /* [retval][out] */ BSTR *__MIDL_0034) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getDateMAJ( 
            /* [retval][out] */ BSTR *__MIDL_0035) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getPassword( 
            /* [retval][out] */ BSTR *__MIDL_0036) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getPinCode( 
            /* [retval][out] */ long *__MIDL_0037) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getNbEssaiCode( 
            /* [retval][out] */ unsigned char *__MIDL_0038) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getConnecte( 
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0039) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getActif( 
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0040) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getNbConnexionAutoriser( 
            /* [retval][out] */ short *__MIDL_0041) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getNbConnexionActives( 
            /* [retval][out] */ short *__MIDL_0042) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getLibelleSociete( 
            /* [retval][out] */ BSTR *__MIDL_0043) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getCodeSociete( 
            /* [retval][out] */ BSTR *__MIDL_0044) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getLibelleLangue( 
            /* [retval][out] */ BSTR *__MIDL_0045) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getLibelleCivilite( 
            /* [retval][out] */ BSTR *__MIDL_0046) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExistLog( 
            /* [out][in] */ BSTR *sLogin,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0047) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_getConnexion( 
            /* [retval][out] */ IDispatch **__MIDL_0048) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ChangerLangue( 
            /* [out][in] */ unsigned char *byIdLangue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddInfoLog( 
            /* [out][in] */ BSTR *sModule,
            /* [out][in] */ BSTR *sInfo1,
            /* [out][in] */ BSTR *sInfo2,
            /* [out][in] */ BSTR *sCodeErreur,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0049) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SilentConnect( 
            /* [out][in] */ BSTR *sModule,
            /* [out][in] */ BSTR *sUser,
            /* [out][in] */ BSTR *sPasswd,
            /* [optional][out][in] */ BSTR *sErreur,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0050) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [out][in] */ BSTR *sModule) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisconnectUser( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AProposDe( 
            /* [out][in] */ BSTR *sTitre,
            /* [out][in] */ BSTR *sNomSoft,
            /* [out][in] */ BSTR *sVersion,
            /* [out][in] */ BSTR *sDateVersion,
            /* [out][in] */ BSTR *sDescription,
            /* [retval][out] */ VARIANT *__MIDL_0051) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ChangerPWD( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getDroitGroupe( 
            /* [out][in] */ long *lIDGroupe,
            /* [optional][out][in] */ BSTR *sSoft,
            /* [retval][out] */ /* _Collection */  IUnknown **colection) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getDroitUser( 
            /* [out][in] */ long *lIdUser,
            /* [optional][out][in] */ BSTR *sSoft,
            /* [retval][out] */ /* _Collection */  IUnknown **colection) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AjoutDroit( 
            /* [out][in] */ BSTR *sSoft,
            /* [out][in] */ BSTR *sDroit,
            /* [out][in] */ short *nCode,
            /* [out][in] */ long *lValDroit,
            /* [retval][out] */ BSTR *__MIDL_0054) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ModifierDroit( 
            /* [out][in] */ BSTR *sSoft,
            /* [out][in] */ BSTR *sAncien,
            /* [out][in] */ BSTR *sNouveau,
            /* [out][in] */ short *nCode,
            /* [retval][out] */ BSTR *__MIDL_0055) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SupprimerDroit( 
            /* [out][in] */ BSTR *sSoft,
            /* [out][in] */ BSTR *sDroit,
            /* [out][in] */ short *nCode,
            /* [out][in] */ long *lValDroit,
            /* [retval][out] */ BSTR *__MIDL_0056) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AffParam( 
            /* [out][in] */ ModeAffichage *sMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsGAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _clsGA * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _clsGA * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _clsGA * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _clsGA * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _clsGA * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _clsGA * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _clsGA * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsTypeSqlServer )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0010);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsTypeOracle )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0011);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetColArchive )( 
            _clsGA * This,
            /* [out][in] */ /* external definition not present */ _Collection **Col);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ServerName2 )( 
            _clsGA * This,
            /* [out][in] */ BSTR *__MIDL_0012);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ServerName2 )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0013);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsMaitre )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0014);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsEsclave )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0015);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LoginSuperviseur )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0016);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PasswordSuperviseur )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0017);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsTraceBDD )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0018);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsTraceLog )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0019);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ServerName )( 
            _clsGA * This,
            /* [out][in] */ BSTR *__MIDL_0020);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ServerName )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0021);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Nom_Base )( 
            _clsGA * This,
            /* [out][in] */ BSTR *__MIDL_0022);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Nom_Base )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0023);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DriverName )( 
            _clsGA * This,
            /* [out][in] */ BSTR *__MIDL_0024);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DriverName )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0025);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Nombre_Max_Essai )( 
            _clsGA * This,
            /* [out][in] */ short *__MIDL_0026);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Nombre_Max_Essai )( 
            _clsGA * This,
            /* [retval][out] */ short *__MIDL_0027);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getIDUtilisateur )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0028);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getNom )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0029);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getPrenom )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0030);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getLogin )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0031);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getMaster )( 
            _clsGA * This,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0032);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getMatricule )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0033);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getDateCreation )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0034);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getDateMAJ )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0035);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getPassword )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0036);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getPinCode )( 
            _clsGA * This,
            /* [retval][out] */ long *__MIDL_0037);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getNbEssaiCode )( 
            _clsGA * This,
            /* [retval][out] */ unsigned char *__MIDL_0038);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getConnecte )( 
            _clsGA * This,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0039);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getActif )( 
            _clsGA * This,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0040);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getNbConnexionAutoriser )( 
            _clsGA * This,
            /* [retval][out] */ short *__MIDL_0041);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getNbConnexionActives )( 
            _clsGA * This,
            /* [retval][out] */ short *__MIDL_0042);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getLibelleSociete )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0043);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getCodeSociete )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0044);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getLibelleLangue )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0045);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getLibelleCivilite )( 
            _clsGA * This,
            /* [retval][out] */ BSTR *__MIDL_0046);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExistLog )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sLogin,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0047);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_getConnexion )( 
            _clsGA * This,
            /* [retval][out] */ IDispatch **__MIDL_0048);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ChangerLangue )( 
            _clsGA * This,
            /* [out][in] */ unsigned char *byIdLangue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddInfoLog )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sModule,
            /* [out][in] */ BSTR *sInfo1,
            /* [out][in] */ BSTR *sInfo2,
            /* [out][in] */ BSTR *sCodeErreur,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0049);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SilentConnect )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sModule,
            /* [out][in] */ BSTR *sUser,
            /* [out][in] */ BSTR *sPasswd,
            /* [optional][out][in] */ BSTR *sErreur,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0050);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sModule);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectUser )( 
            _clsGA * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AProposDe )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sTitre,
            /* [out][in] */ BSTR *sNomSoft,
            /* [out][in] */ BSTR *sVersion,
            /* [out][in] */ BSTR *sDateVersion,
            /* [out][in] */ BSTR *sDescription,
            /* [retval][out] */ VARIANT *__MIDL_0051);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ChangerPWD )( 
            _clsGA * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getDroitGroupe )( 
            _clsGA * This,
            /* [out][in] */ long *lIDGroupe,
            /* [optional][out][in] */ BSTR *sSoft,
            /* [retval][out] */ /* external definition not present */ _Collection **__MIDL_0052);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getDroitUser )( 
            _clsGA * This,
            /* [out][in] */ long *lIdUser,
            /* [optional][out][in] */ BSTR *sSoft,
            /* [retval][out] */ /* external definition not present */ _Collection **__MIDL_0053);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AjoutDroit )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sSoft,
            /* [out][in] */ BSTR *sDroit,
            /* [out][in] */ short *nCode,
            /* [out][in] */ long *lValDroit,
            /* [retval][out] */ BSTR *__MIDL_0054);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ModifierDroit )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sSoft,
            /* [out][in] */ BSTR *sAncien,
            /* [out][in] */ BSTR *sNouveau,
            /* [out][in] */ short *nCode,
            /* [retval][out] */ BSTR *__MIDL_0055);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SupprimerDroit )( 
            _clsGA * This,
            /* [out][in] */ BSTR *sSoft,
            /* [out][in] */ BSTR *sDroit,
            /* [out][in] */ short *nCode,
            /* [out][in] */ long *lValDroit,
            /* [retval][out] */ BSTR *__MIDL_0056);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AffParam )( 
            _clsGA * This,
            /* [out][in] */ ModeAffichage *sMode);
        
        END_INTERFACE
    } _clsGAVtbl;

    interface _clsGA
    {
        CONST_VTBL struct _clsGAVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsGA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsGA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsGA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsGA_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsGA_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsGA_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsGA_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsGA_IsTypeSqlServer(This,__MIDL_0010)	\
    (This)->lpVtbl -> IsTypeSqlServer(This,__MIDL_0010)

#define _clsGA_IsTypeOracle(This,__MIDL_0011)	\
    (This)->lpVtbl -> IsTypeOracle(This,__MIDL_0011)

#define _clsGA_GetColArchive(This,Col)	\
    (This)->lpVtbl -> GetColArchive(This,Col)

#define _clsGA_put_ServerName2(This,__MIDL_0012)	\
    (This)->lpVtbl -> put_ServerName2(This,__MIDL_0012)

#define _clsGA_get_ServerName2(This,__MIDL_0013)	\
    (This)->lpVtbl -> get_ServerName2(This,__MIDL_0013)

#define _clsGA_get_IsMaitre(This,__MIDL_0014)	\
    (This)->lpVtbl -> get_IsMaitre(This,__MIDL_0014)

#define _clsGA_get_IsEsclave(This,__MIDL_0015)	\
    (This)->lpVtbl -> get_IsEsclave(This,__MIDL_0015)

#define _clsGA_get_LoginSuperviseur(This,__MIDL_0016)	\
    (This)->lpVtbl -> get_LoginSuperviseur(This,__MIDL_0016)

#define _clsGA_get_PasswordSuperviseur(This,__MIDL_0017)	\
    (This)->lpVtbl -> get_PasswordSuperviseur(This,__MIDL_0017)

#define _clsGA_get_IsTraceBDD(This,__MIDL_0018)	\
    (This)->lpVtbl -> get_IsTraceBDD(This,__MIDL_0018)

#define _clsGA_get_IsTraceLog(This,__MIDL_0019)	\
    (This)->lpVtbl -> get_IsTraceLog(This,__MIDL_0019)

#define _clsGA_put_ServerName(This,__MIDL_0020)	\
    (This)->lpVtbl -> put_ServerName(This,__MIDL_0020)

#define _clsGA_get_ServerName(This,__MIDL_0021)	\
    (This)->lpVtbl -> get_ServerName(This,__MIDL_0021)

#define _clsGA_put_Nom_Base(This,__MIDL_0022)	\
    (This)->lpVtbl -> put_Nom_Base(This,__MIDL_0022)

#define _clsGA_get_Nom_Base(This,__MIDL_0023)	\
    (This)->lpVtbl -> get_Nom_Base(This,__MIDL_0023)

#define _clsGA_put_DriverName(This,__MIDL_0024)	\
    (This)->lpVtbl -> put_DriverName(This,__MIDL_0024)

#define _clsGA_get_DriverName(This,__MIDL_0025)	\
    (This)->lpVtbl -> get_DriverName(This,__MIDL_0025)

#define _clsGA_put_Nombre_Max_Essai(This,__MIDL_0026)	\
    (This)->lpVtbl -> put_Nombre_Max_Essai(This,__MIDL_0026)

#define _clsGA_get_Nombre_Max_Essai(This,__MIDL_0027)	\
    (This)->lpVtbl -> get_Nombre_Max_Essai(This,__MIDL_0027)

#define _clsGA_get_getIDUtilisateur(This,__MIDL_0028)	\
    (This)->lpVtbl -> get_getIDUtilisateur(This,__MIDL_0028)

#define _clsGA_get_getNom(This,__MIDL_0029)	\
    (This)->lpVtbl -> get_getNom(This,__MIDL_0029)

#define _clsGA_get_getPrenom(This,__MIDL_0030)	\
    (This)->lpVtbl -> get_getPrenom(This,__MIDL_0030)

#define _clsGA_get_getLogin(This,__MIDL_0031)	\
    (This)->lpVtbl -> get_getLogin(This,__MIDL_0031)

#define _clsGA_get_getMaster(This,__MIDL_0032)	\
    (This)->lpVtbl -> get_getMaster(This,__MIDL_0032)

#define _clsGA_get_getMatricule(This,__MIDL_0033)	\
    (This)->lpVtbl -> get_getMatricule(This,__MIDL_0033)

#define _clsGA_get_getDateCreation(This,__MIDL_0034)	\
    (This)->lpVtbl -> get_getDateCreation(This,__MIDL_0034)

#define _clsGA_get_getDateMAJ(This,__MIDL_0035)	\
    (This)->lpVtbl -> get_getDateMAJ(This,__MIDL_0035)

#define _clsGA_get_getPassword(This,__MIDL_0036)	\
    (This)->lpVtbl -> get_getPassword(This,__MIDL_0036)

#define _clsGA_get_getPinCode(This,__MIDL_0037)	\
    (This)->lpVtbl -> get_getPinCode(This,__MIDL_0037)

#define _clsGA_get_getNbEssaiCode(This,__MIDL_0038)	\
    (This)->lpVtbl -> get_getNbEssaiCode(This,__MIDL_0038)

#define _clsGA_get_getConnecte(This,__MIDL_0039)	\
    (This)->lpVtbl -> get_getConnecte(This,__MIDL_0039)

#define _clsGA_get_getActif(This,__MIDL_0040)	\
    (This)->lpVtbl -> get_getActif(This,__MIDL_0040)

#define _clsGA_get_getNbConnexionAutoriser(This,__MIDL_0041)	\
    (This)->lpVtbl -> get_getNbConnexionAutoriser(This,__MIDL_0041)

#define _clsGA_get_getNbConnexionActives(This,__MIDL_0042)	\
    (This)->lpVtbl -> get_getNbConnexionActives(This,__MIDL_0042)

#define _clsGA_get_getLibelleSociete(This,__MIDL_0043)	\
    (This)->lpVtbl -> get_getLibelleSociete(This,__MIDL_0043)

#define _clsGA_get_getCodeSociete(This,__MIDL_0044)	\
    (This)->lpVtbl -> get_getCodeSociete(This,__MIDL_0044)

#define _clsGA_get_getLibelleLangue(This,__MIDL_0045)	\
    (This)->lpVtbl -> get_getLibelleLangue(This,__MIDL_0045)

#define _clsGA_get_getLibelleCivilite(This,__MIDL_0046)	\
    (This)->lpVtbl -> get_getLibelleCivilite(This,__MIDL_0046)

#define _clsGA_ExistLog(This,sLogin,__MIDL_0047)	\
    (This)->lpVtbl -> ExistLog(This,sLogin,__MIDL_0047)

#define _clsGA_get_getConnexion(This,__MIDL_0048)	\
    (This)->lpVtbl -> get_getConnexion(This,__MIDL_0048)

#define _clsGA_ChangerLangue(This,byIdLangue)	\
    (This)->lpVtbl -> ChangerLangue(This,byIdLangue)

#define _clsGA_AddInfoLog(This,sModule,sInfo1,sInfo2,sCodeErreur,__MIDL_0049)	\
    (This)->lpVtbl -> AddInfoLog(This,sModule,sInfo1,sInfo2,sCodeErreur,__MIDL_0049)

#define _clsGA_SilentConnect(This,sModule,sUser,sPasswd,sErreur,__MIDL_0050)	\
    (This)->lpVtbl -> SilentConnect(This,sModule,sUser,sPasswd,sErreur,__MIDL_0050)

#define _clsGA_Connect(This,sModule)	\
    (This)->lpVtbl -> Connect(This,sModule)

#define _clsGA_DisconnectUser(This)	\
    (This)->lpVtbl -> DisconnectUser(This)

#define _clsGA_AProposDe(This,sTitre,sNomSoft,sVersion,sDateVersion,sDescription,__MIDL_0051)	\
    (This)->lpVtbl -> AProposDe(This,sTitre,sNomSoft,sVersion,sDateVersion,sDescription,__MIDL_0051)

#define _clsGA_ChangerPWD(This)	\
    (This)->lpVtbl -> ChangerPWD(This)

#define _clsGA_getDroitGroupe(This,lIDGroupe,sSoft,__MIDL_0052)	\
    (This)->lpVtbl -> getDroitGroupe(This,lIDGroupe,sSoft,__MIDL_0052)

#define _clsGA_getDroitUser(This,lIdUser,sSoft,__MIDL_0053)	\
    (This)->lpVtbl -> getDroitUser(This,lIdUser,sSoft,__MIDL_0053)

#define _clsGA_AjoutDroit(This,sSoft,sDroit,nCode,lValDroit,__MIDL_0054)	\
    (This)->lpVtbl -> AjoutDroit(This,sSoft,sDroit,nCode,lValDroit,__MIDL_0054)

#define _clsGA_ModifierDroit(This,sSoft,sAncien,sNouveau,nCode,__MIDL_0055)	\
    (This)->lpVtbl -> ModifierDroit(This,sSoft,sAncien,sNouveau,nCode,__MIDL_0055)

#define _clsGA_SupprimerDroit(This,sSoft,sDroit,nCode,lValDroit,__MIDL_0056)	\
    (This)->lpVtbl -> SupprimerDroit(This,sSoft,sDroit,nCode,lValDroit,__MIDL_0056)

#define _clsGA_AffParam(This,sMode)	\
    (This)->lpVtbl -> AffParam(This,sMode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_IsTypeSqlServer_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0010);


void __RPC_STUB _clsGA_IsTypeSqlServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_IsTypeOracle_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0011);


void __RPC_STUB _clsGA_IsTypeOracle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_GetColArchive_Proxy( 
    _clsGA * This,
    /* [out][in] */ /* _Collection */ IUnknown **Col);


void __RPC_STUB _clsGA_GetColArchive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsGA_put_ServerName2_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *__MIDL_0012);


void __RPC_STUB _clsGA_put_ServerName2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_ServerName2_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0013);


void __RPC_STUB _clsGA_get_ServerName2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_IsMaitre_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0014);


void __RPC_STUB _clsGA_get_IsMaitre_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_IsEsclave_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0015);


void __RPC_STUB _clsGA_get_IsEsclave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_LoginSuperviseur_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0016);


void __RPC_STUB _clsGA_get_LoginSuperviseur_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_PasswordSuperviseur_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0017);


void __RPC_STUB _clsGA_get_PasswordSuperviseur_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_IsTraceBDD_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0018);


void __RPC_STUB _clsGA_get_IsTraceBDD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_IsTraceLog_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0019);


void __RPC_STUB _clsGA_get_IsTraceLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsGA_put_ServerName_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *__MIDL_0020);


void __RPC_STUB _clsGA_put_ServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_ServerName_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0021);


void __RPC_STUB _clsGA_get_ServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsGA_put_Nom_Base_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *__MIDL_0022);


void __RPC_STUB _clsGA_put_Nom_Base_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_Nom_Base_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0023);


void __RPC_STUB _clsGA_get_Nom_Base_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsGA_put_DriverName_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *__MIDL_0024);


void __RPC_STUB _clsGA_put_DriverName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_DriverName_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0025);


void __RPC_STUB _clsGA_get_DriverName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsGA_put_Nombre_Max_Essai_Proxy( 
    _clsGA * This,
    /* [out][in] */ short *__MIDL_0026);


void __RPC_STUB _clsGA_put_Nombre_Max_Essai_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_Nombre_Max_Essai_Proxy( 
    _clsGA * This,
    /* [retval][out] */ short *__MIDL_0027);


void __RPC_STUB _clsGA_get_Nombre_Max_Essai_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getIDUtilisateur_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0028);


void __RPC_STUB _clsGA_get_getIDUtilisateur_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getNom_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0029);


void __RPC_STUB _clsGA_get_getNom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getPrenom_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0030);


void __RPC_STUB _clsGA_get_getPrenom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getLogin_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0031);


void __RPC_STUB _clsGA_get_getLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getMaster_Proxy( 
    _clsGA * This,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0032);


void __RPC_STUB _clsGA_get_getMaster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getMatricule_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0033);


void __RPC_STUB _clsGA_get_getMatricule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getDateCreation_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0034);


void __RPC_STUB _clsGA_get_getDateCreation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getDateMAJ_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0035);


void __RPC_STUB _clsGA_get_getDateMAJ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getPassword_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0036);


void __RPC_STUB _clsGA_get_getPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getPinCode_Proxy( 
    _clsGA * This,
    /* [retval][out] */ long *__MIDL_0037);


void __RPC_STUB _clsGA_get_getPinCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getNbEssaiCode_Proxy( 
    _clsGA * This,
    /* [retval][out] */ unsigned char *__MIDL_0038);


void __RPC_STUB _clsGA_get_getNbEssaiCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getConnecte_Proxy( 
    _clsGA * This,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0039);


void __RPC_STUB _clsGA_get_getConnecte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getActif_Proxy( 
    _clsGA * This,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0040);


void __RPC_STUB _clsGA_get_getActif_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getNbConnexionAutoriser_Proxy( 
    _clsGA * This,
    /* [retval][out] */ short *__MIDL_0041);


void __RPC_STUB _clsGA_get_getNbConnexionAutoriser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getNbConnexionActives_Proxy( 
    _clsGA * This,
    /* [retval][out] */ short *__MIDL_0042);


void __RPC_STUB _clsGA_get_getNbConnexionActives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getLibelleSociete_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0043);


void __RPC_STUB _clsGA_get_getLibelleSociete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getCodeSociete_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0044);


void __RPC_STUB _clsGA_get_getCodeSociete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getLibelleLangue_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0045);


void __RPC_STUB _clsGA_get_getLibelleLangue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getLibelleCivilite_Proxy( 
    _clsGA * This,
    /* [retval][out] */ BSTR *__MIDL_0046);


void __RPC_STUB _clsGA_get_getLibelleCivilite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_ExistLog_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sLogin,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0047);


void __RPC_STUB _clsGA_ExistLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsGA_get_getConnexion_Proxy( 
    _clsGA * This,
    /* [retval][out] */ IDispatch **__MIDL_0048);


void __RPC_STUB _clsGA_get_getConnexion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_ChangerLangue_Proxy( 
    _clsGA * This,
    /* [out][in] */ unsigned char *byIdLangue);


void __RPC_STUB _clsGA_ChangerLangue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_AddInfoLog_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sModule,
    /* [out][in] */ BSTR *sInfo1,
    /* [out][in] */ BSTR *sInfo2,
    /* [out][in] */ BSTR *sCodeErreur,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0049);


void __RPC_STUB _clsGA_AddInfoLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_SilentConnect_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sModule,
    /* [out][in] */ BSTR *sUser,
    /* [out][in] */ BSTR *sPasswd,
    /* [optional][out][in] */ BSTR *sErreur,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0050);


void __RPC_STUB _clsGA_SilentConnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_Connect_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sModule);


void __RPC_STUB _clsGA_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_DisconnectUser_Proxy( 
    _clsGA * This);


void __RPC_STUB _clsGA_DisconnectUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_AProposDe_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sTitre,
    /* [out][in] */ BSTR *sNomSoft,
    /* [out][in] */ BSTR *sVersion,
    /* [out][in] */ BSTR *sDateVersion,
    /* [out][in] */ BSTR *sDescription,
    /* [retval][out] */ VARIANT *__MIDL_0051);


void __RPC_STUB _clsGA_AProposDe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_ChangerPWD_Proxy( 
    _clsGA * This);


void __RPC_STUB _clsGA_ChangerPWD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_getDroitGroupe_Proxy( 
    _clsGA * This,
    /* [out][in] */ long *lIDGroupe,
    /* [optional][out][in] */ BSTR *sSoft,
    /* [retval][out] */ /* _Collection */ IUnknown ** colection);


void __RPC_STUB _clsGA_getDroitGroupe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_getDroitUser_Proxy( 
    _clsGA * This,
    /* [out][in] */ long *lIdUser,
    /* [optional][out][in] */ BSTR *sSoft,
    /* [retval][out] */ /* _Collection */ IUnknown ** colection);


void __RPC_STUB _clsGA_getDroitUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_AjoutDroit_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sSoft,
    /* [out][in] */ BSTR *sDroit,
    /* [out][in] */ short *nCode,
    /* [out][in] */ long *lValDroit,
    /* [retval][out] */ BSTR *__MIDL_0054);


void __RPC_STUB _clsGA_AjoutDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_ModifierDroit_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sSoft,
    /* [out][in] */ BSTR *sAncien,
    /* [out][in] */ BSTR *sNouveau,
    /* [out][in] */ short *nCode,
    /* [retval][out] */ BSTR *__MIDL_0055);


void __RPC_STUB _clsGA_ModifierDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_SupprimerDroit_Proxy( 
    _clsGA * This,
    /* [out][in] */ BSTR *sSoft,
    /* [out][in] */ BSTR *sDroit,
    /* [out][in] */ short *nCode,
    /* [out][in] */ long *lValDroit,
    /* [retval][out] */ BSTR *__MIDL_0056);


void __RPC_STUB _clsGA_SupprimerDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsGA_AffParam_Proxy( 
    _clsGA * This,
    /* [out][in] */ ModeAffichage *sMode);


void __RPC_STUB _clsGA_AffParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsGA_INTERFACE_DEFINED__ */


#ifndef ___clsSystemInfo_INTERFACE_DEFINED__
#define ___clsSystemInfo_INTERFACE_DEFINED__

/* interface _clsSystemInfo */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsSystemInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("130886BE-89F8-45BB-A250-969558B118BB")
    _clsSystemInfo : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WindowsDir( 
            /* [retval][out] */ BSTR *__MIDL_0057) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SystemDir( 
            /* [retval][out] */ BSTR *__MIDL_0058) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FreeMegaBytesOnDisk( 
            /* [defaultvalue][optional][out][in] */ BSTR *Drive,
            /* [retval][out] */ double *__MIDL_0059) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TotalMegaBytesOnDisk( 
            /* [defaultvalue][optional][out][in] */ BSTR *Drive,
            /* [retval][out] */ double *__MIDL_0060) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HasSoundCard( 
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0061) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ComputerName( 
            /* [retval][out] */ BSTR *__MIDL_0062) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CurrentUser( 
            /* [retval][out] */ BSTR *__MIDL_0063) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE VolumeName( 
            /* [defaultvalue][optional][out][in] */ BSTR *Drive,
            /* [retval][out] */ VARIANT *__MIDL_0064) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OSVersion( 
            /* [retval][out] */ OS_VERSION *__MIDL_0065) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DriveType( 
            /* [out][in] */ BSTR *Drive,
            /* [retval][out] */ DRIVE_TYPE *__MIDL_0066) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AvailablePhysicalMemory( 
            /* [retval][out] */ double *__MIDL_0067) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TotalPhysicalMemory( 
            /* [retval][out] */ double *__MIDL_0068) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PercentMemoryFree( 
            /* [retval][out] */ double *__MIDL_0069) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AvailablePageFile( 
            /* [retval][out] */ double *__MIDL_0070) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PageFileSize( 
            /* [retval][out] */ double *__MIDL_0071) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AvailableMemory( 
            /* [retval][out] */ double *__MIDL_0072) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TotalMemory( 
            /* [retval][out] */ double *__MIDL_0073) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxScreenColors( 
            /* [retval][out] */ double *__MIDL_0074) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ScreenPixelWidth( 
            /* [retval][out] */ short *__MIDL_0075) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ScreenPixelHeight( 
            /* [retval][out] */ short *__MIDL_0076) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ScreenResolution( 
            /* [retval][out] */ BSTR *__MIDL_0077) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SystemErrorCode( 
            /* [retval][out] */ long *__MIDL_0078) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsSystemInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _clsSystemInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _clsSystemInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _clsSystemInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _clsSystemInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _clsSystemInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _clsSystemInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _clsSystemInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WindowsDir )( 
            _clsSystemInfo * This,
            /* [retval][out] */ BSTR *__MIDL_0057);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SystemDir )( 
            _clsSystemInfo * This,
            /* [retval][out] */ BSTR *__MIDL_0058);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FreeMegaBytesOnDisk )( 
            _clsSystemInfo * This,
            /* [defaultvalue][optional][out][in] */ BSTR *Drive,
            /* [retval][out] */ double *__MIDL_0059);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TotalMegaBytesOnDisk )( 
            _clsSystemInfo * This,
            /* [defaultvalue][optional][out][in] */ BSTR *Drive,
            /* [retval][out] */ double *__MIDL_0060);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasSoundCard )( 
            _clsSystemInfo * This,
            /* [retval][out] */ VARIANT_BOOL *__MIDL_0061);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ComputerName )( 
            _clsSystemInfo * This,
            /* [retval][out] */ BSTR *__MIDL_0062);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentUser )( 
            _clsSystemInfo * This,
            /* [retval][out] */ BSTR *__MIDL_0063);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *VolumeName )( 
            _clsSystemInfo * This,
            /* [defaultvalue][optional][out][in] */ BSTR *Drive,
            /* [retval][out] */ VARIANT *__MIDL_0064);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OSVersion )( 
            _clsSystemInfo * This,
            /* [retval][out] */ OS_VERSION *__MIDL_0065);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DriveType )( 
            _clsSystemInfo * This,
            /* [out][in] */ BSTR *Drive,
            /* [retval][out] */ DRIVE_TYPE *__MIDL_0066);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AvailablePhysicalMemory )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0067);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TotalPhysicalMemory )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0068);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PercentMemoryFree )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0069);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AvailablePageFile )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0070);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PageFileSize )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0071);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AvailableMemory )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0072);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TotalMemory )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0073);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxScreenColors )( 
            _clsSystemInfo * This,
            /* [retval][out] */ double *__MIDL_0074);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ScreenPixelWidth )( 
            _clsSystemInfo * This,
            /* [retval][out] */ short *__MIDL_0075);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ScreenPixelHeight )( 
            _clsSystemInfo * This,
            /* [retval][out] */ short *__MIDL_0076);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ScreenResolution )( 
            _clsSystemInfo * This,
            /* [retval][out] */ BSTR *__MIDL_0077);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SystemErrorCode )( 
            _clsSystemInfo * This,
            /* [retval][out] */ long *__MIDL_0078);
        
        END_INTERFACE
    } _clsSystemInfoVtbl;

    interface _clsSystemInfo
    {
        CONST_VTBL struct _clsSystemInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsSystemInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsSystemInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsSystemInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsSystemInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsSystemInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsSystemInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsSystemInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsSystemInfo_WindowsDir(This,__MIDL_0057)	\
    (This)->lpVtbl -> WindowsDir(This,__MIDL_0057)

#define _clsSystemInfo_SystemDir(This,__MIDL_0058)	\
    (This)->lpVtbl -> SystemDir(This,__MIDL_0058)

#define _clsSystemInfo_FreeMegaBytesOnDisk(This,Drive,__MIDL_0059)	\
    (This)->lpVtbl -> FreeMegaBytesOnDisk(This,Drive,__MIDL_0059)

#define _clsSystemInfo_TotalMegaBytesOnDisk(This,Drive,__MIDL_0060)	\
    (This)->lpVtbl -> TotalMegaBytesOnDisk(This,Drive,__MIDL_0060)

#define _clsSystemInfo_get_HasSoundCard(This,__MIDL_0061)	\
    (This)->lpVtbl -> get_HasSoundCard(This,__MIDL_0061)

#define _clsSystemInfo_get_ComputerName(This,__MIDL_0062)	\
    (This)->lpVtbl -> get_ComputerName(This,__MIDL_0062)

#define _clsSystemInfo_get_CurrentUser(This,__MIDL_0063)	\
    (This)->lpVtbl -> get_CurrentUser(This,__MIDL_0063)

#define _clsSystemInfo_VolumeName(This,Drive,__MIDL_0064)	\
    (This)->lpVtbl -> VolumeName(This,Drive,__MIDL_0064)

#define _clsSystemInfo_get_OSVersion(This,__MIDL_0065)	\
    (This)->lpVtbl -> get_OSVersion(This,__MIDL_0065)

#define _clsSystemInfo_DriveType(This,Drive,__MIDL_0066)	\
    (This)->lpVtbl -> DriveType(This,Drive,__MIDL_0066)

#define _clsSystemInfo_AvailablePhysicalMemory(This,__MIDL_0067)	\
    (This)->lpVtbl -> AvailablePhysicalMemory(This,__MIDL_0067)

#define _clsSystemInfo_TotalPhysicalMemory(This,__MIDL_0068)	\
    (This)->lpVtbl -> TotalPhysicalMemory(This,__MIDL_0068)

#define _clsSystemInfo_PercentMemoryFree(This,__MIDL_0069)	\
    (This)->lpVtbl -> PercentMemoryFree(This,__MIDL_0069)

#define _clsSystemInfo_AvailablePageFile(This,__MIDL_0070)	\
    (This)->lpVtbl -> AvailablePageFile(This,__MIDL_0070)

#define _clsSystemInfo_PageFileSize(This,__MIDL_0071)	\
    (This)->lpVtbl -> PageFileSize(This,__MIDL_0071)

#define _clsSystemInfo_AvailableMemory(This,__MIDL_0072)	\
    (This)->lpVtbl -> AvailableMemory(This,__MIDL_0072)

#define _clsSystemInfo_TotalMemory(This,__MIDL_0073)	\
    (This)->lpVtbl -> TotalMemory(This,__MIDL_0073)

#define _clsSystemInfo_get_MaxScreenColors(This,__MIDL_0074)	\
    (This)->lpVtbl -> get_MaxScreenColors(This,__MIDL_0074)

#define _clsSystemInfo_get_ScreenPixelWidth(This,__MIDL_0075)	\
    (This)->lpVtbl -> get_ScreenPixelWidth(This,__MIDL_0075)

#define _clsSystemInfo_get_ScreenPixelHeight(This,__MIDL_0076)	\
    (This)->lpVtbl -> get_ScreenPixelHeight(This,__MIDL_0076)

#define _clsSystemInfo_get_ScreenResolution(This,__MIDL_0077)	\
    (This)->lpVtbl -> get_ScreenResolution(This,__MIDL_0077)

#define _clsSystemInfo_get_SystemErrorCode(This,__MIDL_0078)	\
    (This)->lpVtbl -> get_SystemErrorCode(This,__MIDL_0078)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_WindowsDir_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ BSTR *__MIDL_0057);


void __RPC_STUB _clsSystemInfo_WindowsDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_SystemDir_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ BSTR *__MIDL_0058);


void __RPC_STUB _clsSystemInfo_SystemDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_FreeMegaBytesOnDisk_Proxy( 
    _clsSystemInfo * This,
    /* [defaultvalue][optional][out][in] */ BSTR *Drive,
    /* [retval][out] */ double *__MIDL_0059);


void __RPC_STUB _clsSystemInfo_FreeMegaBytesOnDisk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_TotalMegaBytesOnDisk_Proxy( 
    _clsSystemInfo * This,
    /* [defaultvalue][optional][out][in] */ BSTR *Drive,
    /* [retval][out] */ double *__MIDL_0060);


void __RPC_STUB _clsSystemInfo_TotalMegaBytesOnDisk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_HasSoundCard_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ VARIANT_BOOL *__MIDL_0061);


void __RPC_STUB _clsSystemInfo_get_HasSoundCard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_ComputerName_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ BSTR *__MIDL_0062);


void __RPC_STUB _clsSystemInfo_get_ComputerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_CurrentUser_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ BSTR *__MIDL_0063);


void __RPC_STUB _clsSystemInfo_get_CurrentUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_VolumeName_Proxy( 
    _clsSystemInfo * This,
    /* [defaultvalue][optional][out][in] */ BSTR *Drive,
    /* [retval][out] */ VARIANT *__MIDL_0064);


void __RPC_STUB _clsSystemInfo_VolumeName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_OSVersion_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ OS_VERSION *__MIDL_0065);


void __RPC_STUB _clsSystemInfo_get_OSVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_DriveType_Proxy( 
    _clsSystemInfo * This,
    /* [out][in] */ BSTR *Drive,
    /* [retval][out] */ DRIVE_TYPE *__MIDL_0066);


void __RPC_STUB _clsSystemInfo_DriveType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_AvailablePhysicalMemory_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0067);


void __RPC_STUB _clsSystemInfo_AvailablePhysicalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_TotalPhysicalMemory_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0068);


void __RPC_STUB _clsSystemInfo_TotalPhysicalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_PercentMemoryFree_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0069);


void __RPC_STUB _clsSystemInfo_PercentMemoryFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_AvailablePageFile_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0070);


void __RPC_STUB _clsSystemInfo_AvailablePageFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_PageFileSize_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0071);


void __RPC_STUB _clsSystemInfo_PageFileSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_AvailableMemory_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0072);


void __RPC_STUB _clsSystemInfo_AvailableMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_TotalMemory_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0073);


void __RPC_STUB _clsSystemInfo_TotalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_MaxScreenColors_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ double *__MIDL_0074);


void __RPC_STUB _clsSystemInfo_get_MaxScreenColors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_ScreenPixelWidth_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ short *__MIDL_0075);


void __RPC_STUB _clsSystemInfo_get_ScreenPixelWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_ScreenPixelHeight_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ short *__MIDL_0076);


void __RPC_STUB _clsSystemInfo_get_ScreenPixelHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_ScreenResolution_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ BSTR *__MIDL_0077);


void __RPC_STUB _clsSystemInfo_get_ScreenResolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsSystemInfo_get_SystemErrorCode_Proxy( 
    _clsSystemInfo * This,
    /* [retval][out] */ long *__MIDL_0078);


void __RPC_STUB _clsSystemInfo_get_SystemErrorCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsSystemInfo_INTERFACE_DEFINED__ */


#ifndef ___clsLocaleSettings_INTERFACE_DEFINED__
#define ___clsLocaleSettings_INTERFACE_DEFINED__

/* interface _clsLocaleSettings */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsLocaleSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84F73397-2D65-498A-A26F-696832E2B751")
    _clsLocaleSettings : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DateFormat( 
            /* [retval][out] */ BSTR *__MIDL_0079) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TimeFormat( 
            /* [retval][out] */ BSTR *__MIDL_0080) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberFormat( 
            /* [retval][out] */ BSTR *__MIDL_0081) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ThousandSpecifier( 
            /* [retval][out] */ BSTR *__MIDL_0082) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DecimalSpecifier( 
            /* [retval][out] */ BSTR *__MIDL_0083) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CurrencySpecifier( 
            /* [retval][out] */ BSTR *__MIDL_0084) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SysLanguageID( 
            /* [retval][out] */ long *__MIDL_0085) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SysLanguageName( 
            /* [retval][out] */ BSTR *__MIDL_0086) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ShortMonthName( 
            /* [in] */ short iMonthNum,
            /* [retval][out] */ BSTR *__MIDL_0087) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MonthName( 
            /* [in] */ short iMonthNum,
            /* [retval][out] */ BSTR *__MIDL_0088) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ShortDayName( 
            /* [in] */ short iDayNum,
            /* [retval][out] */ BSTR *__MIDL_0089) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DayName( 
            /* [in] */ short iDayNum,
            /* [retval][out] */ BSTR *__MIDL_0090) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Country( 
            /* [retval][out] */ BSTR *__MIDL_0091) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LanguageName( 
            /* [retval][out] */ BSTR *__MIDL_0092) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NativeCountryName( 
            /* [retval][out] */ BSTR *__MIDL_0093) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PositiveSign( 
            /* [retval][out] */ BSTR *__MIDL_0094) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NegativeSign( 
            /* [retval][out] */ BSTR *__MIDL_0095) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsLocaleSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _clsLocaleSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _clsLocaleSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _clsLocaleSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _clsLocaleSettings * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _clsLocaleSettings * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _clsLocaleSettings * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _clsLocaleSettings * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DateFormat )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0079);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TimeFormat )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0080);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumberFormat )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0081);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ThousandSpecifier )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0082);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DecimalSpecifier )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0083);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CurrencySpecifier )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0084);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SysLanguageID )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ long *__MIDL_0085);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SysLanguageName )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0086);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShortMonthName )( 
            _clsLocaleSettings * This,
            /* [in] */ short iMonthNum,
            /* [retval][out] */ BSTR *__MIDL_0087);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MonthName )( 
            _clsLocaleSettings * This,
            /* [in] */ short iMonthNum,
            /* [retval][out] */ BSTR *__MIDL_0088);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShortDayName )( 
            _clsLocaleSettings * This,
            /* [in] */ short iDayNum,
            /* [retval][out] */ BSTR *__MIDL_0089);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DayName )( 
            _clsLocaleSettings * This,
            /* [in] */ short iDayNum,
            /* [retval][out] */ BSTR *__MIDL_0090);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Country )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0091);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageName )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0092);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NativeCountryName )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0093);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PositiveSign )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0094);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NegativeSign )( 
            _clsLocaleSettings * This,
            /* [retval][out] */ BSTR *__MIDL_0095);
        
        END_INTERFACE
    } _clsLocaleSettingsVtbl;

    interface _clsLocaleSettings
    {
        CONST_VTBL struct _clsLocaleSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsLocaleSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsLocaleSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsLocaleSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsLocaleSettings_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsLocaleSettings_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsLocaleSettings_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsLocaleSettings_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsLocaleSettings_get_DateFormat(This,__MIDL_0079)	\
    (This)->lpVtbl -> get_DateFormat(This,__MIDL_0079)

#define _clsLocaleSettings_get_TimeFormat(This,__MIDL_0080)	\
    (This)->lpVtbl -> get_TimeFormat(This,__MIDL_0080)

#define _clsLocaleSettings_get_NumberFormat(This,__MIDL_0081)	\
    (This)->lpVtbl -> get_NumberFormat(This,__MIDL_0081)

#define _clsLocaleSettings_get_ThousandSpecifier(This,__MIDL_0082)	\
    (This)->lpVtbl -> get_ThousandSpecifier(This,__MIDL_0082)

#define _clsLocaleSettings_get_DecimalSpecifier(This,__MIDL_0083)	\
    (This)->lpVtbl -> get_DecimalSpecifier(This,__MIDL_0083)

#define _clsLocaleSettings_get_CurrencySpecifier(This,__MIDL_0084)	\
    (This)->lpVtbl -> get_CurrencySpecifier(This,__MIDL_0084)

#define _clsLocaleSettings_get_SysLanguageID(This,__MIDL_0085)	\
    (This)->lpVtbl -> get_SysLanguageID(This,__MIDL_0085)

#define _clsLocaleSettings_get_SysLanguageName(This,__MIDL_0086)	\
    (This)->lpVtbl -> get_SysLanguageName(This,__MIDL_0086)

#define _clsLocaleSettings_get_ShortMonthName(This,iMonthNum,__MIDL_0087)	\
    (This)->lpVtbl -> get_ShortMonthName(This,iMonthNum,__MIDL_0087)

#define _clsLocaleSettings_get_MonthName(This,iMonthNum,__MIDL_0088)	\
    (This)->lpVtbl -> get_MonthName(This,iMonthNum,__MIDL_0088)

#define _clsLocaleSettings_get_ShortDayName(This,iDayNum,__MIDL_0089)	\
    (This)->lpVtbl -> get_ShortDayName(This,iDayNum,__MIDL_0089)

#define _clsLocaleSettings_get_DayName(This,iDayNum,__MIDL_0090)	\
    (This)->lpVtbl -> get_DayName(This,iDayNum,__MIDL_0090)

#define _clsLocaleSettings_get_Country(This,__MIDL_0091)	\
    (This)->lpVtbl -> get_Country(This,__MIDL_0091)

#define _clsLocaleSettings_get_LanguageName(This,__MIDL_0092)	\
    (This)->lpVtbl -> get_LanguageName(This,__MIDL_0092)

#define _clsLocaleSettings_get_NativeCountryName(This,__MIDL_0093)	\
    (This)->lpVtbl -> get_NativeCountryName(This,__MIDL_0093)

#define _clsLocaleSettings_get_PositiveSign(This,__MIDL_0094)	\
    (This)->lpVtbl -> get_PositiveSign(This,__MIDL_0094)

#define _clsLocaleSettings_get_NegativeSign(This,__MIDL_0095)	\
    (This)->lpVtbl -> get_NegativeSign(This,__MIDL_0095)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_DateFormat_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0079);


void __RPC_STUB _clsLocaleSettings_get_DateFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_TimeFormat_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0080);


void __RPC_STUB _clsLocaleSettings_get_TimeFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_NumberFormat_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0081);


void __RPC_STUB _clsLocaleSettings_get_NumberFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_ThousandSpecifier_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0082);


void __RPC_STUB _clsLocaleSettings_get_ThousandSpecifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_DecimalSpecifier_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0083);


void __RPC_STUB _clsLocaleSettings_get_DecimalSpecifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_CurrencySpecifier_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0084);


void __RPC_STUB _clsLocaleSettings_get_CurrencySpecifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_SysLanguageID_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ long *__MIDL_0085);


void __RPC_STUB _clsLocaleSettings_get_SysLanguageID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_SysLanguageName_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0086);


void __RPC_STUB _clsLocaleSettings_get_SysLanguageName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_ShortMonthName_Proxy( 
    _clsLocaleSettings * This,
    /* [in] */ short iMonthNum,
    /* [retval][out] */ BSTR *__MIDL_0087);


void __RPC_STUB _clsLocaleSettings_get_ShortMonthName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_MonthName_Proxy( 
    _clsLocaleSettings * This,
    /* [in] */ short iMonthNum,
    /* [retval][out] */ BSTR *__MIDL_0088);


void __RPC_STUB _clsLocaleSettings_get_MonthName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_ShortDayName_Proxy( 
    _clsLocaleSettings * This,
    /* [in] */ short iDayNum,
    /* [retval][out] */ BSTR *__MIDL_0089);


void __RPC_STUB _clsLocaleSettings_get_ShortDayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_DayName_Proxy( 
    _clsLocaleSettings * This,
    /* [in] */ short iDayNum,
    /* [retval][out] */ BSTR *__MIDL_0090);


void __RPC_STUB _clsLocaleSettings_get_DayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_Country_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0091);


void __RPC_STUB _clsLocaleSettings_get_Country_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_LanguageName_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0092);


void __RPC_STUB _clsLocaleSettings_get_LanguageName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_NativeCountryName_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0093);


void __RPC_STUB _clsLocaleSettings_get_NativeCountryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_PositiveSign_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0094);


void __RPC_STUB _clsLocaleSettings_get_PositiveSign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsLocaleSettings_get_NegativeSign_Proxy( 
    _clsLocaleSettings * This,
    /* [retval][out] */ BSTR *__MIDL_0095);


void __RPC_STUB _clsLocaleSettings_get_NegativeSign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsLocaleSettings_INTERFACE_DEFINED__ */


#ifndef ___clsDroitSoft_INTERFACE_DEFINED__
#define ___clsDroitSoft_INTERFACE_DEFINED__

/* interface _clsDroitSoft */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsDroitSoft;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76421557-FAB0-4B92-9D7D-3880D1BB0898")
    _clsDroitSoft : public IDispatch
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LibelleDroit( 
            /* [in] */ BSTR __MIDL_0096) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LibelleDroit( 
            /* [retval][out] */ BSTR *__MIDL_0097) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_NomSoft( 
            /* [in] */ BSTR __MIDL_0098) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NomSoft( 
            /* [retval][out] */ BSTR *__MIDL_0099) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Code( 
            /* [in] */ short __MIDL_0100) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Code( 
            /* [retval][out] */ short *__MIDL_0101) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ValDroit( 
            /* [in] */ long __MIDL_0102) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ValDroit( 
            /* [retval][out] */ long *__MIDL_0103) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsDroitSoftVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _clsDroitSoft * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _clsDroitSoft * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _clsDroitSoft * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _clsDroitSoft * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _clsDroitSoft * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _clsDroitSoft * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _clsDroitSoft * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LibelleDroit )( 
            _clsDroitSoft * This,
            /* [in] */ BSTR __MIDL_0096);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LibelleDroit )( 
            _clsDroitSoft * This,
            /* [retval][out] */ BSTR *__MIDL_0097);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_NomSoft )( 
            _clsDroitSoft * This,
            /* [in] */ BSTR __MIDL_0098);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NomSoft )( 
            _clsDroitSoft * This,
            /* [retval][out] */ BSTR *__MIDL_0099);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Code )( 
            _clsDroitSoft * This,
            /* [in] */ short __MIDL_0100);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Code )( 
            _clsDroitSoft * This,
            /* [retval][out] */ short *__MIDL_0101);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ValDroit )( 
            _clsDroitSoft * This,
            /* [in] */ long __MIDL_0102);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ValDroit )( 
            _clsDroitSoft * This,
            /* [retval][out] */ long *__MIDL_0103);
        
        END_INTERFACE
    } _clsDroitSoftVtbl;

    interface _clsDroitSoft
    {
        CONST_VTBL struct _clsDroitSoftVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsDroitSoft_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsDroitSoft_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsDroitSoft_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsDroitSoft_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsDroitSoft_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsDroitSoft_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsDroitSoft_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsDroitSoft_put_LibelleDroit(This,__MIDL_0096)	\
    (This)->lpVtbl -> put_LibelleDroit(This,__MIDL_0096)

#define _clsDroitSoft_get_LibelleDroit(This,__MIDL_0097)	\
    (This)->lpVtbl -> get_LibelleDroit(This,__MIDL_0097)

#define _clsDroitSoft_put_NomSoft(This,__MIDL_0098)	\
    (This)->lpVtbl -> put_NomSoft(This,__MIDL_0098)

#define _clsDroitSoft_get_NomSoft(This,__MIDL_0099)	\
    (This)->lpVtbl -> get_NomSoft(This,__MIDL_0099)

#define _clsDroitSoft_put_Code(This,__MIDL_0100)	\
    (This)->lpVtbl -> put_Code(This,__MIDL_0100)

#define _clsDroitSoft_get_Code(This,__MIDL_0101)	\
    (This)->lpVtbl -> get_Code(This,__MIDL_0101)

#define _clsDroitSoft_put_ValDroit(This,__MIDL_0102)	\
    (This)->lpVtbl -> put_ValDroit(This,__MIDL_0102)

#define _clsDroitSoft_get_ValDroit(This,__MIDL_0103)	\
    (This)->lpVtbl -> get_ValDroit(This,__MIDL_0103)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_put_LibelleDroit_Proxy( 
    _clsDroitSoft * This,
    /* [in] */ BSTR __MIDL_0096);


void __RPC_STUB _clsDroitSoft_put_LibelleDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_get_LibelleDroit_Proxy( 
    _clsDroitSoft * This,
    /* [retval][out] */ BSTR *__MIDL_0097);


void __RPC_STUB _clsDroitSoft_get_LibelleDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_put_NomSoft_Proxy( 
    _clsDroitSoft * This,
    /* [in] */ BSTR __MIDL_0098);


void __RPC_STUB _clsDroitSoft_put_NomSoft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_get_NomSoft_Proxy( 
    _clsDroitSoft * This,
    /* [retval][out] */ BSTR *__MIDL_0099);


void __RPC_STUB _clsDroitSoft_get_NomSoft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_put_Code_Proxy( 
    _clsDroitSoft * This,
    /* [in] */ short __MIDL_0100);


void __RPC_STUB _clsDroitSoft_put_Code_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_get_Code_Proxy( 
    _clsDroitSoft * This,
    /* [retval][out] */ short *__MIDL_0101);


void __RPC_STUB _clsDroitSoft_get_Code_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_put_ValDroit_Proxy( 
    _clsDroitSoft * This,
    /* [in] */ long __MIDL_0102);


void __RPC_STUB _clsDroitSoft_put_ValDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsDroitSoft_get_ValDroit_Proxy( 
    _clsDroitSoft * This,
    /* [retval][out] */ long *__MIDL_0103);


void __RPC_STUB _clsDroitSoft_get_ValDroit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsDroitSoft_INTERFACE_DEFINED__ */


#ifndef ___clsArchive_INTERFACE_DEFINED__
#define ___clsArchive_INTERFACE_DEFINED__

/* interface _clsArchive */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsArchive;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B66A168-D5D2-43AA-8F50-C73215BA45EF")
    _clsArchive : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Identifiant( 
            /* [retval][out] */ long *Identifiant) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Identifiant( 
            /* [in] */ long Identifiant) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DateDeb( 
            /* [retval][out] */ DATE *DateDeb) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DateDeb( 
            /* [in] */ DATE DateDeb) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DateFin( 
            /* [retval][out] */ DATE *DateFin) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DateFin( 
            /* [in] */ DATE DateFin) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DateArchive( 
            /* [retval][out] */ DATE *DateArchive) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DateArchive( 
            /* [in] */ DATE DateArchive) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ServerSrc( 
            /* [retval][out] */ BSTR *ServerSrc) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ServerSrc( 
            /* [in] */ BSTR ServerSrc) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ServerRes( 
            /* [retval][out] */ BSTR *ServerRes) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ServerRes( 
            /* [in] */ BSTR ServerRes) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *Description) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR Description) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CreateurNom( 
            /* [retval][out] */ BSTR *CreateurNom) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CreateurNom( 
            /* [in] */ BSTR CreateurNom) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CreateurPrenom( 
            /* [retval][out] */ BSTR *CreateurPrenom) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CreateurPrenom( 
            /* [in] */ BSTR CreateurPrenom) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NomFichier( 
            /* [retval][out] */ BSTR *NomFichier) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_NomFichier( 
            /* [in] */ BSTR NomFichier) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TypeSession( 
            /* [retval][out] */ long *TypeSession) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_TypeSession( 
            /* [in] */ long TypeSession) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Id_domaine( 
            /* [retval][out] */ long *Id_domaine) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Id_domaine( 
            /* [in] */ long Id_domaine) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RemplitInfo( 
            /* [out][in] */ /* _Recordset */ IUnknown **rs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsArchiveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _clsArchive * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _clsArchive * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _clsArchive * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _clsArchive * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _clsArchive * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _clsArchive * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _clsArchive * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Identifiant )( 
            _clsArchive * This,
            /* [retval][out] */ long *Identifiant);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Identifiant )( 
            _clsArchive * This,
            /* [in] */ long Identifiant);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DateDeb )( 
            _clsArchive * This,
            /* [retval][out] */ DATE *DateDeb);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DateDeb )( 
            _clsArchive * This,
            /* [in] */ DATE DateDeb);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DateFin )( 
            _clsArchive * This,
            /* [retval][out] */ DATE *DateFin);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DateFin )( 
            _clsArchive * This,
            /* [in] */ DATE DateFin);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DateArchive )( 
            _clsArchive * This,
            /* [retval][out] */ DATE *DateArchive);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DateArchive )( 
            _clsArchive * This,
            /* [in] */ DATE DateArchive);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ServerSrc )( 
            _clsArchive * This,
            /* [retval][out] */ BSTR *ServerSrc);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ServerSrc )( 
            _clsArchive * This,
            /* [in] */ BSTR ServerSrc);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ServerRes )( 
            _clsArchive * This,
            /* [retval][out] */ BSTR *ServerRes);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ServerRes )( 
            _clsArchive * This,
            /* [in] */ BSTR ServerRes);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            _clsArchive * This,
            /* [retval][out] */ BSTR *Description);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            _clsArchive * This,
            /* [in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CreateurNom )( 
            _clsArchive * This,
            /* [retval][out] */ BSTR *CreateurNom);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CreateurNom )( 
            _clsArchive * This,
            /* [in] */ BSTR CreateurNom);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CreateurPrenom )( 
            _clsArchive * This,
            /* [retval][out] */ BSTR *CreateurPrenom);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CreateurPrenom )( 
            _clsArchive * This,
            /* [in] */ BSTR CreateurPrenom);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NomFichier )( 
            _clsArchive * This,
            /* [retval][out] */ BSTR *NomFichier);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_NomFichier )( 
            _clsArchive * This,
            /* [in] */ BSTR NomFichier);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TypeSession )( 
            _clsArchive * This,
            /* [retval][out] */ long *TypeSession);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TypeSession )( 
            _clsArchive * This,
            /* [in] */ long TypeSession);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Id_domaine )( 
            _clsArchive * This,
            /* [retval][out] */ long *Id_domaine);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Id_domaine )( 
            _clsArchive * This,
            /* [in] */ long Id_domaine);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemplitInfo )( 
            _clsArchive * This,
            /* [out][in] */ /* external definition not present */ _Recordset **rs);
        
        END_INTERFACE
    } _clsArchiveVtbl;

    interface _clsArchive
    {
        CONST_VTBL struct _clsArchiveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsArchive_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsArchive_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsArchive_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsArchive_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsArchive_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsArchive_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsArchive_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsArchive_get_Identifiant(This,Identifiant)	\
    (This)->lpVtbl -> get_Identifiant(This,Identifiant)

#define _clsArchive_put_Identifiant(This,Identifiant)	\
    (This)->lpVtbl -> put_Identifiant(This,Identifiant)

#define _clsArchive_get_DateDeb(This,DateDeb)	\
    (This)->lpVtbl -> get_DateDeb(This,DateDeb)

#define _clsArchive_put_DateDeb(This,DateDeb)	\
    (This)->lpVtbl -> put_DateDeb(This,DateDeb)

#define _clsArchive_get_DateFin(This,DateFin)	\
    (This)->lpVtbl -> get_DateFin(This,DateFin)

#define _clsArchive_put_DateFin(This,DateFin)	\
    (This)->lpVtbl -> put_DateFin(This,DateFin)

#define _clsArchive_get_DateArchive(This,DateArchive)	\
    (This)->lpVtbl -> get_DateArchive(This,DateArchive)

#define _clsArchive_put_DateArchive(This,DateArchive)	\
    (This)->lpVtbl -> put_DateArchive(This,DateArchive)

#define _clsArchive_get_ServerSrc(This,ServerSrc)	\
    (This)->lpVtbl -> get_ServerSrc(This,ServerSrc)

#define _clsArchive_put_ServerSrc(This,ServerSrc)	\
    (This)->lpVtbl -> put_ServerSrc(This,ServerSrc)

#define _clsArchive_get_ServerRes(This,ServerRes)	\
    (This)->lpVtbl -> get_ServerRes(This,ServerRes)

#define _clsArchive_put_ServerRes(This,ServerRes)	\
    (This)->lpVtbl -> put_ServerRes(This,ServerRes)

#define _clsArchive_get_Description(This,Description)	\
    (This)->lpVtbl -> get_Description(This,Description)

#define _clsArchive_put_Description(This,Description)	\
    (This)->lpVtbl -> put_Description(This,Description)

#define _clsArchive_get_CreateurNom(This,CreateurNom)	\
    (This)->lpVtbl -> get_CreateurNom(This,CreateurNom)

#define _clsArchive_put_CreateurNom(This,CreateurNom)	\
    (This)->lpVtbl -> put_CreateurNom(This,CreateurNom)

#define _clsArchive_get_CreateurPrenom(This,CreateurPrenom)	\
    (This)->lpVtbl -> get_CreateurPrenom(This,CreateurPrenom)

#define _clsArchive_put_CreateurPrenom(This,CreateurPrenom)	\
    (This)->lpVtbl -> put_CreateurPrenom(This,CreateurPrenom)

#define _clsArchive_get_NomFichier(This,NomFichier)	\
    (This)->lpVtbl -> get_NomFichier(This,NomFichier)

#define _clsArchive_put_NomFichier(This,NomFichier)	\
    (This)->lpVtbl -> put_NomFichier(This,NomFichier)

#define _clsArchive_get_TypeSession(This,TypeSession)	\
    (This)->lpVtbl -> get_TypeSession(This,TypeSession)

#define _clsArchive_put_TypeSession(This,TypeSession)	\
    (This)->lpVtbl -> put_TypeSession(This,TypeSession)

#define _clsArchive_get_Id_domaine(This,Id_domaine)	\
    (This)->lpVtbl -> get_Id_domaine(This,Id_domaine)

#define _clsArchive_put_Id_domaine(This,Id_domaine)	\
    (This)->lpVtbl -> put_Id_domaine(This,Id_domaine)

#define _clsArchive_RemplitInfo(This,rs)	\
    (This)->lpVtbl -> RemplitInfo(This,rs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_Identifiant_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ long *Identifiant);


void __RPC_STUB _clsArchive_get_Identifiant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_Identifiant_Proxy( 
    _clsArchive * This,
    /* [in] */ long Identifiant);


void __RPC_STUB _clsArchive_put_Identifiant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_DateDeb_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ DATE *DateDeb);


void __RPC_STUB _clsArchive_get_DateDeb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_DateDeb_Proxy( 
    _clsArchive * This,
    /* [in] */ DATE DateDeb);


void __RPC_STUB _clsArchive_put_DateDeb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_DateFin_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ DATE *DateFin);


void __RPC_STUB _clsArchive_get_DateFin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_DateFin_Proxy( 
    _clsArchive * This,
    /* [in] */ DATE DateFin);


void __RPC_STUB _clsArchive_put_DateFin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_DateArchive_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ DATE *DateArchive);


void __RPC_STUB _clsArchive_get_DateArchive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_DateArchive_Proxy( 
    _clsArchive * This,
    /* [in] */ DATE DateArchive);


void __RPC_STUB _clsArchive_put_DateArchive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_ServerSrc_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ BSTR *ServerSrc);


void __RPC_STUB _clsArchive_get_ServerSrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_ServerSrc_Proxy( 
    _clsArchive * This,
    /* [in] */ BSTR ServerSrc);


void __RPC_STUB _clsArchive_put_ServerSrc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_ServerRes_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ BSTR *ServerRes);


void __RPC_STUB _clsArchive_get_ServerRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_ServerRes_Proxy( 
    _clsArchive * This,
    /* [in] */ BSTR ServerRes);


void __RPC_STUB _clsArchive_put_ServerRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_Description_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ BSTR *Description);


void __RPC_STUB _clsArchive_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_Description_Proxy( 
    _clsArchive * This,
    /* [in] */ BSTR Description);


void __RPC_STUB _clsArchive_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_CreateurNom_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ BSTR *CreateurNom);


void __RPC_STUB _clsArchive_get_CreateurNom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_CreateurNom_Proxy( 
    _clsArchive * This,
    /* [in] */ BSTR CreateurNom);


void __RPC_STUB _clsArchive_put_CreateurNom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_CreateurPrenom_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ BSTR *CreateurPrenom);


void __RPC_STUB _clsArchive_get_CreateurPrenom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_CreateurPrenom_Proxy( 
    _clsArchive * This,
    /* [in] */ BSTR CreateurPrenom);


void __RPC_STUB _clsArchive_put_CreateurPrenom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_NomFichier_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ BSTR *NomFichier);


void __RPC_STUB _clsArchive_get_NomFichier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_NomFichier_Proxy( 
    _clsArchive * This,
    /* [in] */ BSTR NomFichier);


void __RPC_STUB _clsArchive_put_NomFichier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_TypeSession_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ long *TypeSession);


void __RPC_STUB _clsArchive_get_TypeSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_TypeSession_Proxy( 
    _clsArchive * This,
    /* [in] */ long TypeSession);


void __RPC_STUB _clsArchive_put_TypeSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_get_Id_domaine_Proxy( 
    _clsArchive * This,
    /* [retval][out] */ long *Id_domaine);


void __RPC_STUB _clsArchive_get_Id_domaine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsArchive_put_Id_domaine_Proxy( 
    _clsArchive * This,
    /* [in] */ long Id_domaine);


void __RPC_STUB _clsArchive_put_Id_domaine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsArchive_RemplitInfo_Proxy( 
    _clsArchive * This,
    /* [out][in] */ /* _Recordset */ IUnknown **rs);


void __RPC_STUB _clsArchive_RemplitInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsArchive_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_clsGA;

#ifdef __cplusplus

class DECLSPEC_UUID("A77211D8-8250-4826-8A81-0D06BB45ED6C")
clsGA;
#endif

EXTERN_C const CLSID CLSID_clsSystemInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("E67FAD72-436A-4E1E-BB46-E857B5E63670")
clsSystemInfo;
#endif

EXTERN_C const CLSID CLSID_clsLocaleSettings;

#ifdef __cplusplus

class DECLSPEC_UUID("12D3244D-953E-4C1C-B477-E375E8285295")
clsLocaleSettings;
#endif

EXTERN_C const CLSID CLSID_clsDroitSoft;

#ifdef __cplusplus

class DECLSPEC_UUID("5675377E-59B8-4BA3-8539-C87531E77ACC")
clsDroitSoft;
#endif

EXTERN_C const CLSID CLSID_clsArchive;

#ifdef __cplusplus

class DECLSPEC_UUID("1772002E-9CCA-4F3F-8C45-828EFCDE1F9F")
clsArchive;
#endif
#endif /* __GA_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


