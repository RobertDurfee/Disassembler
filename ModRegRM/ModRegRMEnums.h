#ifndef MOD_REG_RM_ENUMS_HEADER
#define MOD_REG_RM_ENUMS_HEADER

enum class Mod
{
/* 0x00 */ _,      //No Mod (Default)

/* 0x01 */ NoDisp, //Register indirect addressing mode, SIB with no displacement (RM = 100, 32-bit), or displacement only addressing mode (RM = 101, 32-bit or RM = 110, 16-bit)
/* 0x02 */ Disp,   //Displacement (8-bit, 16-bit, or 32-bit)
/* 0x03 */ Reg     //Register addressing mode
};

enum class Reg
{
/* 0x00 */ _,           //No Reg (Default)

/* 0x01 */ A,           //General A Register
/* 0x04 */ C = A + 3,   //General C Register
/* 0x07 */ D = C + 3,   //General D Register
/* 0x0A */ B = D + 3,   //General B Register
/* 0x0D */ SP = B + 3,  //General SP Register
/* 0x10 */ BP = SP + 3, //General BP Register
/* 0x13 */ SI = BP + 3, //General SI Register
/* 0x16 */ DI = SI + 3  //General DI Register
};

enum class RM
{
/* 0x00 */ _,             //No RM (Default)
/* 0x01 */ $,             //Specified elsewhere (used only in optional rm16 field)

/* 0x02 */ A,             //[EAX] or [BX + SI] (16-bit)
/* 0x05 */ C = A + 3,     //[ECX] or [BX + DI] (16-bit)
/* 0x08 */ D = C + 3,     //[EDX] or [BP + SI] (16-bit)
/* 0x0B */ B = D + 3,     //[EBX] or [BP + DI] (16-bit)
/* 0x0E */ SP = B + 3,    //[ESP] or [SI] (16-bit)
/* 0x11 */ BP = SP + 3,   //[EBP] or [DI] (16-bit)
/* 0x14 */ SI = BP + 3,   //[ESI] or [BP] (16-bit)
/* 0x17 */ DI = SI + 3,   //[EDI] or [BX] (16-bit)

/* 0x1A */ Disp = DI + 3, //Displacement (16-bit or 32-bit)

/* 0x1B */ SIB            //The SIB byte is used
};

#ifndef SIZE_ENUM
#define SIZE_ENUM
enum class Size
{ 
/* 0x00 */ _,   //No Size
/* 0x01 */ $,   //Size Specified in Another Table

/* 0x02 */ b,   //Byte, regardless of operand-size
/* 0x03 */ w,   //Word, regardless on operand-size
/* 0x04 */ d,   //Dword, regardless of operand-size

/* 0x05 */ v,   //Word or doubleword, depending on operand-size
/* 0x06 */ u,   //Byte, word, or doubleword depending on operand-size

/* 0x07 */ a,   //Two word or two doubleword operands in memory, depending on operand-size

/* 0x08 */ p,   //32-bit pointer
};
#endif

#endif