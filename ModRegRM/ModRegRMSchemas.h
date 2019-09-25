#ifndef MOD_REG_RM_SCHEMAS_HEADER
#define MOD_REG_RM_SCHEMAS_HEADER

#include "./ModRegRMEnums.h"

struct ModRegRMSchema
{
	struct
	{
		Mod mod;
		Size modSize;
	};
	struct
	{
		Reg reg;
		Size regSize;
	};
	struct
	{
		RM rm;
		Size rmSize;
		RM rm16; //Used to accomodate inconsistencies between 16-bit and 32-bit addressing methods
	};
};

extern const ModRegRMSchema EmptyModRegRMSchema;

extern const ModRegRMSchema ModRegRMSchemas[0x100 /* 00 000 000 - 11 111 111 */];

#endif
