#ifndef __READER_ASK__DATACEILING_H
#define __READER_ASK__DATACEILING_H

DECLARE_HANDLE(HDATACEILING);
DECLARE_HANDLE(HDATACEILINGLIST);

#define KIF_PERSO			0x21
#define KIF_RECHARGEMENT	0x27

#define	TEST_KIF_NONE			0x0000
#define TEST_KIF_PERSO			0x0001
#define TEST_KIF_RECHARGEMENT	0x0002

#define TEST_KIF_ALL			TEST_KIF_PERSO | TEST_KIF_RECHARGEMENT

#define	PDATACEILING(hCeiling)				((sDataCeiling*) (hCeiling))
#define	PDATACEILING_LIST(hCeilingList)		((CListExt<sDataCeiling>*) (hCeilingList))

#define RDRNAME__DataCeilingList_GetCount							"DataCeilingList_GetCount"
typedef long (__stdcall *RDRPROC__DataCeilingList_GetCount)	(HDATACEILINGLIST hCeilingList);

#define RDRNAME__DataCeilingList_GetAt								"DataCeilingList_GetAt"
typedef CONST HDATACEILING (__stdcall *RDRPROC__DataCeilingList_GetAt)	(HDATACEILINGLIST hCeilingList, long i);

#define RDRNAME__DataCeilingList_CloseHandle						"DataCeilingList_CloseHandle"
typedef void (__stdcall *RDRPROC__DataCeilingList_CloseHandle)	(HDATACEILINGLIST hCeilingList);


#define RDRNAME__DataCeiling_GetAlea								"DataCeiling_GetAlea"
typedef BYTE* (__stdcall *RDRPROC__DataCeiling_GetAlea)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_GetCompteur							"DataCeiling_GetCompteur"
typedef unsigned long (__stdcall *RDRPROC__DataCeiling_GetCompteur)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_GetNumeroPlafond						"DataCeiling_GetNumeroPlafond"
typedef unsigned long (__stdcall *RDRPROC__DataCeiling_GetNumeroPlafond)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_GetNumeroSam							"DataCeiling_GetNumeroSam"
typedef unsigned long (__stdcall *RDRPROC__DataCeiling_GetNumeroSam)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_GetFichierPlafond						"DataCeiling_GetFichierPlafond"
typedef BYTE* (__stdcall *RDRPROC__DataCeiling_GetFichierPlafond)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_GetKif						"DataCeiling_GetKif"
typedef BYTE (__stdcall *RDRPROC__DataCeiling_GetKif)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_GetKvc						"DataCeiling_GetKvc"
typedef BYTE (__stdcall *RDRPROC__DataCeiling_GetKvc)	(HDATACEILING hCeiling);

#define RDRNAME__DataCeiling_CloseHandle				"DataCeiling_CloseHandle"
typedef void (__stdcall *RDRPROC__DataCeiling_CloseHandle)	(HDATACEILING hCeiling);

#endif // __READER_ASK__DATACEILING_H