#ifndef MOD_REG_RM_SCHEMAS_HEADER
#define MOD_REG_RM_SCHEMAS_HEADER

#include "ModRegRMEnums.h" //Mod, Reg, RM, Size

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

const ModRegRMSchema EmptyModRegRMSchema = { { Mod::_, Size::_ },{ Reg::_, Size::_ },{ RM::_, Size::_, RM::_ } };

const ModRegRMSchema ModRegRMSchemas[0x100 /* 00 000 000 - 11 111 111 */] = 
{
/***************************************************************************************************/
/* 00 000 000 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::A,    Size::v, RM::A    } }, 
/* 00 000 001 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::C,    Size::v, RM::C    } }, 
/* 00 000 010 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 000 011 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 000 100 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 000 101 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 000 110 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 000 111 */ { { Mod::NoDisp, Size::_ }, { Reg::A,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 001 000 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 001 001 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 001 010 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 001 011 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 001 100 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 001 101 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 001 110 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 001 111 */ { { Mod::NoDisp, Size::_ }, { Reg::C,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 010 000 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 010 001 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 010 010 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 010 011 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 010 100 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 010 101 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 010 110 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 010 111 */ { { Mod::NoDisp, Size::_ }, { Reg::D,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 011 000 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 011 001 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 011 010 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 011 011 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 011 100 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 011 101 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 011 110 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 011 111 */ { { Mod::NoDisp, Size::_ }, { Reg::B,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 100 000 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 100 001 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 100 010 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 100 011 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 100 100 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 100 101 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 100 110 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 100 111 */ { { Mod::NoDisp, Size::_ }, { Reg::SP, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 101 000 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 101 001 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 101 010 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 101 011 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 101 100 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 101 101 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 101 110 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 101 111 */ { { Mod::NoDisp, Size::_ }, { Reg::BP, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 110 000 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 110 001 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 110 010 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 110 011 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 110 100 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 110 101 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 110 110 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 110 111 */ { { Mod::NoDisp, Size::_ }, { Reg::SI, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 00 111 000 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 00 111 001 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 00 111 010 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 00 111 011 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 00 111 100 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 111 101 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 111 110 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 111 111 */ { { Mod::NoDisp, Size::_ }, { Reg::DI, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 000 000 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 000 001 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 000 010 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 000 011 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 000 100 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 000 101 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 000 110 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 000 111 */ { { Mod::Disp,   Size::b }, { Reg::A,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 001 000 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 001 001 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 001 010 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 001 011 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 001 100 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 001 101 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 001 110 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 001 111 */ { { Mod::Disp,   Size::b }, { Reg::C,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 010 000 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 010 001 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 010 010 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 010 011 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 010 100 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 010 101 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 010 110 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 010 111 */ { { Mod::Disp,   Size::b }, { Reg::D,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 011 000 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 011 001 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 011 010 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 011 011 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 011 100 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 011 101 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 011 110 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 011 111 */ { { Mod::Disp,   Size::b }, { Reg::B,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 100 000 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 100 001 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 100 010 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 100 011 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 100 100 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 100 101 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 100 110 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 100 111 */ { { Mod::Disp,   Size::b }, { Reg::SP, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 101 000 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 101 001 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 101 010 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 101 011 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 101 100 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 101 101 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 101 110 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 101 111 */ { { Mod::Disp,   Size::b }, { Reg::BP, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 110 000 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 110 001 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 110 010 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 110 011 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 110 100 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 110 101 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 110 110 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 110 111 */ { { Mod::Disp,   Size::b }, { Reg::SI, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 01 111 000 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 01 111 001 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 01 111 010 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 01 111 011 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 01 111 100 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 01 111 101 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 01 111 110 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 01 111 111 */ { { Mod::Disp,   Size::b }, { Reg::DI, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 000 000 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 000 001 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 000 010 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 000 011 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 000 100 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 000 101 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 000 110 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 000 111 */ { { Mod::Disp,   Size::v }, { Reg::A,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 001 000 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 001 001 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 001 010 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 001 011 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 001 100 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 001 101 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 001 110 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 001 111 */ { { Mod::Disp,   Size::v }, { Reg::C,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 010 000 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 010 001 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 010 010 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 010 011 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 010 100 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 010 101 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 010 110 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 010 111 */ { { Mod::Disp,   Size::v }, { Reg::D,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 011 000 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 011 001 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 011 010 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 011 011 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 011 100 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 011 101 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 011 110 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 011 111 */ { { Mod::Disp,   Size::v }, { Reg::B,  Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 100 000 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 100 001 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 100 010 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 100 011 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 100 100 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 100 101 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 100 110 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 100 111 */ { { Mod::Disp,   Size::v }, { Reg::SP, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 101 000 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 101 001 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 101 010 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 101 011 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 101 100 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 101 101 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 101 110 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 101 111 */ { { Mod::Disp,   Size::v }, { Reg::BP, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 110 000 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 110 001 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 110 010 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 110 011 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 110 100 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 110 101 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 110 110 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 110 111 */ { { Mod::Disp,   Size::v }, { Reg::SI, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 10 111 000 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::A,    Size::v, RM::A    } },
/* 10 111 001 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::C,    Size::v, RM::C    } },
/* 10 111 010 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::D,    Size::v, RM::D    } },
/* 10 111 011 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::B,    Size::v, RM::B    } },
/* 10 111 100 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 10 111 101 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::BP,   Size::v, RM::BP   } },
/* 10 111 110 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::SI,   Size::v, RM::SI   } },
/* 10 111 111 */ { { Mod::Disp,   Size::v }, { Reg::DI, Size::u }, { RM::DI,   Size::v, RM::DI   } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 000 000 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 000 001 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 000 010 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 000 011 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 000 100 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 000 101 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 000 110 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 000 111 */ { { Mod::Reg,    Size::$ }, { Reg::A,  Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 001 000 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 001 001 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 001 010 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 001 011 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 001 100 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 001 101 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 001 110 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 001 111 */ { { Mod::Reg,    Size::$ }, { Reg::C,  Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 010 000 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 010 001 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 010 010 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 010 011 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 010 100 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 010 101 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 010 110 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 010 111 */ { { Mod::Reg,    Size::$ }, { Reg::D,  Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 011 000 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 011 001 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 011 010 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 011 011 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 011 100 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 011 101 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 011 110 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 011 111 */ { { Mod::Reg,    Size::$ }, { Reg::B,  Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 100 000 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 100 001 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 100 010 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 100 011 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 100 100 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 100 101 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 100 110 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 100 111 */ { { Mod::Reg,    Size::$ }, { Reg::SP, Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 101 000 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 101 001 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 101 010 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 101 011 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 101 100 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 101 101 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 101 110 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 101 111 */ { { Mod::Reg,    Size::$ }, { Reg::BP, Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 110 000 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 110 001 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 110 010 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 110 011 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 110 100 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 110 101 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 110 110 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 110 111 */ { { Mod::Reg,    Size::$ }, { Reg::SI, Size::u }, { RM::DI,   Size::u, RM::$    } },
/***************************************************************************************************/

/***************************************************************************************************/
/* 11 111 000 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::A,    Size::u, RM::$    } },
/* 11 111 001 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::C,    Size::u, RM::$    } },
/* 11 111 010 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::D,    Size::u, RM::$    } },
/* 11 111 011 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::B,    Size::u, RM::$    } },
/* 11 111 100 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::SP,   Size::u, RM::$    } },
/* 11 111 101 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::BP,   Size::u, RM::$    } },
/* 11 111 110 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::SI,   Size::u, RM::$    } },
/* 11 111 111 */ { { Mod::Reg,    Size::$ }, { Reg::DI, Size::u }, { RM::DI,   Size::u, RM::$    } }
/***************************************************************************************************/
};

#endif