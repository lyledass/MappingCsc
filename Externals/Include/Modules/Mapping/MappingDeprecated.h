#ifndef __MAPPING_DEPRECATED_SDK_H
#define __MAPPING_DEPRECATED_SDK_H

/////////////////////////////////////////////////////////////////////
// Interface permettant d'afficher des warning sur les token déprécié
/////////////////////////////////////////////////////////////////////

// Déclaration des versions des mappings 
#define	BRANCHE_MAPPING_INITIALE		0x0000	// Token pour les mapping des branches TPV anciennes
#define	BRANCHE_MAPPING_V010			0x0100	// Token pour les mapping des branches TPV anciennes
#define	BRANCHE_MAPPING_V020			0x0200	// Token pour les mapping des branches TPV 2.0.0 - 2.0.1
#define	BRANCHE_MAPPING_V030			0x0300	// Token pour les mapping des branches TPV 2.0.2

#if defined USE_BRANCHE_MAPPING_V010
#define USE_BRANCHE_MAPPING BRANCHE_MAPPING_V010
#elif defined USE_BRANCHE_MAPPING_V020
#define USE_BRANCHE_MAPPING BRANCHE_MAPPING_V020
#elif defined USE_BRANCHE_MAPPING_V030
#define USE_BRANCHE_MAPPING BRANCHE_MAPPING_V030
#else
#define USE_BRANCHE_MAPPING BRANCHE_MAPPING_INITIALE
#endif

// Déclaration des macros pour la dépréciation :

#define MAPPING_DECLSPEC_DEPRECATED_VAL __declspec(deprecated)
#define MAPPING_DECLSPEC_DEPRECATED_VAL_MSG(msg) __declspec(deprecated(msg))

// Déclaration des macro pour chaque token
#if USE_BRANCHE_MAPPING >= BRANCHE_MAPPING_V010
#define MAPPING_DECLSPEC_DEPRECATED_MAPPING_V010 MAPPING_DECLSPEC_DEPRECATED_VAL
#define MAPPING_DECLSPEC_DEPRECATED_MSG_MAPPING_V010(msg) MAPPING_DECLSPEC_DEPRECATED_VAL_MSG(msg)
#else
#define MAPPING_DECLSPEC_DEPRECATED_MAPPING_V010
#define MAPPING_DECLSPEC_DEPRECATED_MSG_MAPPING_V010(msg)
#endif

#if USE_BRANCHE_MAPPING >= BRANCHE_MAPPING_V020
#define MAPPING_DECLSPEC_DEPRECATED_MAPPING_V020 MAPPING_DECLSPEC_DEPRECATED_VAL
#define MAPPING_DECLSPEC_DEPRECATED_MSG_MAPPING_V020(msg) MAPPING_DECLSPEC_DEPRECATED_VAL_MSG(msg)
#else
#define MAPPING_DECLSPEC_DEPRECATED_MAPPING_V020
#define MAPPING_DECLSPEC_DEPRECATED_MSG_MAPPING_V020(msg)
#endif

#if USE_BRANCHE_MAPPING >= BRANCHE_MAPPING_V030
#define MAPPING_DECLSPEC_DEPRECATED_MAPPING_V030 MAPPING_DECLSPEC_DEPRECATED_VAL
#define MAPPING_DECLSPEC_DEPRECATED_MSG_MAPPING_V030(msg) MAPPING_DECLSPEC_DEPRECATED_VAL_MSG(msg)
#else
#define MAPPING_DECLSPEC_DEPRECATED_MAPPING_V030
#define MAPPING_DECLSPEC_DEPRECATED_MSG_MAPPING_V030(msg)
#endif

// Fonction d'accès
#define MAPPING_DECLSPEC_DEPRECATED(since)				MAPPING_DECLSPEC_DEPRECATED_ ## since
#define MAPPING_DECLSPEC_DEPRECATED_MSG(since, msg)		MAPPING_DECLSPEC_DEPRECATED_MSG_ ## since ## (msg)


#endif /* __MAPPING_DEPRECATED_SDK_H */