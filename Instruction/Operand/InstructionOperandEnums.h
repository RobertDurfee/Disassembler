#ifndef INSTRUCTION_OPERAND_ENUMS_HEADER
#define INSTRUCTION_OPERAND_ENUMS_HEADER

enum class AddressingMethod
{
/* 0x00 */ _,   //No Operand
/* 0x01 */ $,   //Operand Specified in Another Table

/* 0x02 */ A,   //Direct Address: [Segment]:[Offset]
/* 0x03 */ D,   //Reg field of ModRegRM specifies a debug register
/* 0x04 */ E,   //ModRegRM specifies a general purpose register or memory address
/* 0x05 */ F,   //EFLAGS Register
/* 0x06 */ G,   //Reg field of ModRegRM specifies a general register
/* 0x07 */ I,   //Immediate data
/* 0x08 */ J,   //Relative offset
/* 0x09 */ M,   //ModRegRM only specifies memory address
/* 0x0A */ O,   //Memory offset relative to the segment base
/* 0x0B */ S,   //Reg field of ModRegRM specifies a segment register
/* 0x0C */ X,   //Memory addressed by the DS:rSI regsiter pair
/* 0x0D */ Y,   //Memory addressed by the ES:rDI register pair

/* 0x0E */ LAST //Placeholder
};

enum class Register
{
/* 0x00 */ _,    //No Operand
/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x0E */ A = (Register)AddressingMethod::LAST,       //General A Register
/* 0x11 */ C = A + 3,     //General C Register
/* 0x14 */ D = C + 3,     //General D Register
/* 0x17 */ B = D + 3,     //General B Register
/* 0x1A */ SP = B + 3,    //General SP Register
/* 0x1D */ BP = SP + 3,   //General BP Register
/* 0x20 */ SI = BP + 3,   //General SI Register
/* 0x23 */ DI = SI + 3,   //General DI Register

/* 0x26 */ LAST = DI + 3  //Placeholder
};

enum class SegmentRegister
{
/* 0x00 */ _,    //No Operand
/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x16 */ ES = (SegmentRegister)Register::LAST, //E Segment Register
/* 0x17 */ CS,    //C Segment Register
/* 0x18 */ SS,    //S Segment Register
/* 0x19 */ DS,    //D Segment Register
/* 0x1A */ FS,    //F Segment Register
/* 0x1B */ GS,    //G Segment Register

/* 0x1C */ LAST   //Placeholder
};

enum class Constant
{
/* 0x00 */ _,      //No Operand
/* 0x01 */ $,      //Operand Specified in Another Table

/* 0x1C */ ONE = (Constant)SegmentRegister::LAST, //The number one (Used only by the shift instruction group)

/* 0x1D */ LAST    //Placeholder
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