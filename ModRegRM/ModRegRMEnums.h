#ifndef MOD_REG_RM_ENUMS_HEADER
#define MOD_REG_RM_ENUMS_HEADER

enum class Mod
{
/* 0x00 */ NoDisp, //Register indirect addressing mode, SIB with no displacement (RM = 100, 32-bit), or displacement only addressing mode (RM = 101, 32-bit or RM = 110, 16-bit)
/* 0x01 */ Disp,   //Displacement (8-bit, 16-bit, or 32-bit)
/* 0x02 */ Reg     //Register addressing mode
};

enum class Reg
{
/* 0x00 */ A,           //General A Register
/* 0x03 */ C = A + 3,   //General C Register
/* 0x06 */ D = C + 3,   //General D Register
/* 0x09 */ B = D + 3,   //General B Register
/* 0x0C */ SP = B + 3,  //General SP Register
/* 0x0F */ BP = SP + 3, //General BP Register
/* 0x12 */ SI = BP + 3, //General SI Register
/* 0x15 */ DI = SI + 3  //General DI Register
};

enum class RM
{
/* 0x00 */ $,             //Specified elsewhere (used only in optional rm16 field)

/* 0x01 */ A,             //[EAX] or [BX + SI] (16-bit)
/* 0x03 */ C = A + 3,     //[ECX] or [BX + DI] (16-bit)
/* 0x05 */ D = C + 3,     //[EDX] or [BP + SI] (16-bit)
/* 0x07 */ B = D + 3,     //[EBX] or [BP + DI] (16-bit)
/* 0x09 */ SP = B + 3,    //[ESP] or [SI] (16-bit)
/* 0x0B */ BP = SP + 3,   //[EBP] or [DI] (16-bit)
/* 0x0D */ SI = BP + 3,   //[ESI] or [BP] (16-bit)
/* 0x0F */ DI = SI + 3,   //[EDI] or [BX] (16-bit)

/* 0x11 */ Disp = DI + 3, //Displacement (16-bit or 32-bit)

/* 0x12 */ SIB            //The SIB byte is used
};

#ifndef SIZE_ENUM
#define SIZE_ENUM
enum class Size
{
/* 0x00 */ _,   //No Size
/* 0x01 */ $,   //Size Specified in Another Table

/* 0x02 */ a,   //Two one-word or two double-word operands in memory, depending on operand-size
/* 0x03 */ b,   //Byte, regardless of operand-size
/* 0x04 */ d,   //Dword, regardless of operand-size
/* 0x05 */ p,   //32-bit pointer
/* 0x06 */ u,   //Byte, word, dword, quadword, or double-quadword, depending on operand-size
/* 0x07 */ v,   //Word or doubleword, depending on operand-size
/* 0x08 */ w,   //Word, regardless on operand-size
/* 0x09 */ x,   //Double-quadword or quad-quadword, depending on operand-size
/* 0x0A */ z,   //Word of doubleword, depending on operand-size
};
#endif

#endif