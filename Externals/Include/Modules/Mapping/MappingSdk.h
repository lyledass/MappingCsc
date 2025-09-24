#ifndef __MAPPING_SDK_H
#define __MAPPING_SDK_H

#if defined(MAPPING_SDK_V1)
	#include "v1.0.0/MapFieldDef.h"

	#define MAPPING_VERSION		0x100

	#pragma message ("-------------------- Mapping SDK v1.0.0 --------------------\n")

#elif defined(MAPPING_SDK_V2_0)
	#include "v2.0.0/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x200

	#pragma message ("-------------------- Mapping SDK v2.0.0 --------------------\n")

#elif defined(MAPPING_SDK_V2_1)
	#include "v2.0.1/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x201

	#pragma message ("-------------------- Mapping SDK v2.0.1 --------------------\n")

#elif defined(MAPPING_SDK_V2_2)
	#include "v2.0.2/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x202

	#pragma message ("-------------------- Mapping SDK v2.0.2 --------------------\n")

#elif defined(MAPPING_SDK_V2_3)
	#include "v2.0.3/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x203

	#pragma message ("-------------------- Mapping SDK v2.0.3 --------------------\n")

#elif defined(MAPPING_SDK_V2_4)
	#include "v2.0.4/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x204

	#pragma message ("-------------------- Mapping SDK v2.0.4 --------------------\n")

#elif defined(MAPPING_SDK_V3_0)
	#include "v3.0.0/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x300

	#pragma message ("-------------------- Mapping SDK v3.0.0 --------------------\n")

#elif defined(MAPPING_SDK_V3_1)
	#include "v3.0.1/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x301

	#pragma message ("-------------------- Mapping SDK v3.0.1 --------------------\n")

#elif defined(MAPPING_SDK_V3_2)
	#include "v3.0.2/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x302

	#pragma message ("-------------------- Mapping SDK v3.0.2 --------------------\n")

#elif defined(MAPPING_SDK_V3_3)
	#include "v3.0.3/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x303

	#pragma message ("-------------------- Mapping SDK v3.0.3 --------------------\n")

#elif defined(MAPPING_SDK_V3_4)
	#include "v3.0.4/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x304

	#pragma message ("-------------------- Mapping SDK v3.0.4 --------------------\n")

#elif defined(MAPPING_SDK_V3_5)
	#include "v3.0.5/MapFieldDefExt.h"

	#define MAPPING_VERSION		0x305

	#pragma message ("-------------------- Mapping SDK v3.0.5 --------------------\n")


#else
	#define MAPPING_VERSION		0x000
	#pragma message ("-------------------- Mapping version not specified ! --------------------\n")
#endif

#endif /* __MAPPING_SDK_H */