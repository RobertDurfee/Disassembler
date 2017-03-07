#ifndef MOD_REG_RM_SCHEMAS_HEADER
#define MOD_REG_RM_SCHEMAS_HEADER

enum class Mod
{ 
/* 0x00 */ _,   //No Mod

/* 0x01 */ Disp //Displacement (8-bit, 16-bit, or 32-bit)
};

enum class Reg  
{ 
/* 0x00 */ A,  //General A  Register or AL Register (8-bit)
/* 0x01 */ C,  //General C  Register or CL Register (8-bit)
/* 0x02 */ D,  //General D  Register or DL Register (8-bit)
/* 0x03 */ B,  //General B  Register or BL Register (8-bit)
/* 0x04 */ SP, //General SP Register or AH Register (8-bit)
/* 0x05 */ BP, //General BP Register or CH Register (8-bit)
/* 0x06 */ SI, //General SI Register or DH Register (8-bit)
/* 0x07 */ DI  //General DI Register or BH Register (8-bit)
};

enum class RM   
{ 
/* 0x00 */ _,    //No RM (used only in optional rm16 field)

/* 0x01 */ A,    //[EAX] or [BX + SI] (16-bit)
/* 0x02 */ C,    //[ECX] or [BX + DI] (16-bit)
/* 0x03 */ D,    //[EDX] or [BP + SI] (16-bit)
/* 0x04 */ B,    //[EBX] or [BP + DI] (16-bit)
/* 0x05 */ SP,   //[ESP] or [SI] (16-bit)
/* 0x06 */ BP,   //[EBP] or [DI] (16-bit)
/* 0x07 */ SI,   //[ESI] or [BP] (16-bit)
/* 0x08 */ DI,   //[EDI] or [BX] (16-bit)

/* 0x09 */ Disp, //Displacement (16-bit or 32-bit)

/* 0x0A */ SIB   //The SIB byte is used
};

enum class Size
{
/* 0x00 */ _, //Unspecified

/* 0x01 */ b, //Byte
/* 0x02 */ u, //Byte, Word, Dword, Qword, or DQword
/* 0x03 */ v  //Word or Dword
};

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
		RM rm16; //Used to accomodate inconsistancies in 16-bit vs 32-bit addressing forms without making an entire new table.
	};
};

const ModRegRMSchema ModRegRMSchemas[0x100 /* 00 000 000 - 11 111 111 */] = 
{
/*************************************************************************************************/
/* 00 000 000 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::A,    Size::v, RM::_    } }, 
/* 00 000 001 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::C,    Size::v, RM::_    } }, 
/* 00 000 010 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 000 011 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 000 100 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 000 101 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 000 110 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 000 111 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 001 000 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 001 001 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 001 010 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 001 011 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 001 100 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 001 101 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 001 110 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 001 111 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 010 000 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 010 001 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 010 010 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 010 011 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 010 100 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 010 101 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 010 110 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 010 111 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 011 000 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 011 001 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 011 010 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 011 011 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 011 100 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 011 101 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 011 110 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 011 111 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 100 000 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 100 001 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 100 010 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 100 011 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 100 100 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 100 101 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 100 110 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 100 111 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 101 000 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 101 001 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 101 010 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 101 011 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 101 100 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 101 101 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 101 110 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 101 111 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 110 000 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 110 001 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 110 010 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 110 011 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 110 100 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 110 101 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 110 110 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 110 111 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 00 111 000 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 00 111 001 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 00 111 010 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 00 111 011 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 00 111 100 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::SIB,  Size::v, RM::SP   } },
/* 00 111 101 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::Disp, Size::v, RM::BP   } },
/* 00 111 110 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::SI,   Size::v, RM::Disp } },
/* 00 111 111 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 000 000 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 000 001 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 000 010 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 000 011 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 000 100 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 000 101 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 000 110 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 000 111 */ { { Mod::Disp, Size::b }, { Reg::A,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 001 000 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 001 001 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 001 010 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 001 011 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 001 100 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 001 101 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 001 110 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 001 111 */ { { Mod::Disp, Size::b }, { Reg::C,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 010 000 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 010 001 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 010 010 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 010 011 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 010 100 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 010 101 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 010 110 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 010 111 */ { { Mod::Disp, Size::b }, { Reg::D,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 011 000 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 011 001 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 011 010 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 011 011 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 011 100 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 011 101 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 011 110 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 011 111 */ { { Mod::Disp, Size::b }, { Reg::B,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 100 000 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 100 001 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 100 010 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 100 011 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 100 100 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 100 101 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 100 110 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 100 111 */ { { Mod::Disp, Size::b }, { Reg::SP, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 101 000 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 101 001 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 101 010 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 101 011 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 101 100 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 101 101 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 101 110 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 101 111 */ { { Mod::Disp, Size::b }, { Reg::BP, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 110 000 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 110 001 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 110 010 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 110 011 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 110 100 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 110 101 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 110 110 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 110 111 */ { { Mod::Disp, Size::b }, { Reg::SI, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 01 111 000 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 01 111 001 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 01 111 010 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 01 111 011 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 01 111 100 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 01 111 101 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 01 111 110 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 01 111 111 */ { { Mod::Disp, Size::b }, { Reg::DI, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 000 000 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 000 001 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 000 010 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 000 011 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 000 100 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 000 101 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 000 110 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 000 111 */ { { Mod::Disp, Size::v }, { Reg::A,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 001 000 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 001 001 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 001 010 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 001 011 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 001 100 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 001 101 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 001 110 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 001 111 */ { { Mod::Disp, Size::v }, { Reg::C,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 010 000 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 010 001 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 010 010 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 010 011 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 010 100 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 010 101 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 010 110 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 010 111 */ { { Mod::Disp, Size::v }, { Reg::D,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 011 000 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 011 001 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 011 010 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 011 011 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 011 100 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 011 101 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 011 110 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 011 111 */ { { Mod::Disp, Size::v }, { Reg::B,  Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 100 000 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 100 001 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 100 010 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 100 011 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 100 100 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 100 101 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 100 110 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 100 111 */ { { Mod::Disp, Size::v }, { Reg::SP, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 101 000 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 101 001 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 101 010 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 101 011 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 101 100 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 101 101 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 101 110 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 101 111 */ { { Mod::Disp, Size::v }, { Reg::BP, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 110 000 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 110 001 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 110 010 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 110 011 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 110 100 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 110 101 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 110 110 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 110 111 */ { { Mod::Disp, Size::v }, { Reg::SI, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 10 111 000 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::A,    Size::v, RM::_    } },
/* 10 111 001 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::C,    Size::v, RM::_    } },
/* 10 111 010 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::D,    Size::v, RM::_    } },
/* 10 111 011 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::B,    Size::v, RM::_    } },
/* 10 111 100 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::SIB,  Size::v, RM::_    } },
/* 10 111 101 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::BP,   Size::v, RM::_    } },
/* 10 111 110 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::SI,   Size::v, RM::_    } },
/* 10 111 111 */ { { Mod::Disp, Size::v }, { Reg::DI, Size::u }, { RM::DI,   Size::v, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 000 000 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 000 001 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 000 010 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 000 011 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 000 100 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 000 101 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 000 110 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 000 111 */ { { Mod::_,    Size::_ }, { Reg::A,  Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 001 000 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 001 001 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 001 010 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 001 011 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 001 100 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 001 101 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 001 110 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 001 111 */ { { Mod::_,    Size::_ }, { Reg::C,  Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 010 000 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 010 001 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 010 010 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 010 011 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 010 100 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 010 101 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 010 110 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 010 111 */ { { Mod::_,    Size::_ }, { Reg::D,  Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 011 000 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 011 001 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 011 010 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 011 011 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 011 100 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 011 101 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 011 110 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 011 111 */ { { Mod::_,    Size::_ }, { Reg::B,  Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 100 000 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 100 001 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 100 010 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 100 011 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 100 100 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 100 101 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 100 110 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 100 111 */ { { Mod::_,    Size::_ }, { Reg::SP, Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 101 000 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 101 001 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 101 010 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 101 011 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 101 100 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 101 101 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 101 110 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 101 111 */ { { Mod::_,    Size::_ }, { Reg::BP, Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 110 000 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 110 001 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 110 010 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 110 011 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 110 100 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 110 101 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 110 110 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 110 111 */ { { Mod::_,    Size::_ }, { Reg::SI, Size::u }, { RM::DI,   Size::u, RM::_    } },
/*************************************************************************************************/

/*************************************************************************************************/
/* 11 111 000 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::A,    Size::u, RM::_    } },
/* 11 111 001 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::C,    Size::u, RM::_    } },
/* 11 111 010 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::D,    Size::u, RM::_    } },
/* 11 111 011 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::B,    Size::u, RM::_    } },
/* 11 111 100 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::SP,   Size::u, RM::_    } },
/* 11 111 101 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::BP,   Size::u, RM::_    } },
/* 11 111 110 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::SI,   Size::u, RM::_    } },
/* 11 111 111 */ { { Mod::_,    Size::_ }, { Reg::DI, Size::u }, { RM::DI,   Size::u, RM::_    } }
/*************************************************************************************************/
};

#endif