#ifndef SIB_SCHEMAS_HEADER
#define SIB_SCHEMAS_HEADER

#include "./SIBEnums.h"

struct SIBSchema
{
	Scale scale;
	Index index;
	Base  base;
};

extern const SIBSchema EmptySIBSchema;

extern const SIBSchema SIBSchemas[0x100 /* 00 000 000 - 11 111 111 */];

#endif
