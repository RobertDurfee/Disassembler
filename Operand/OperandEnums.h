#ifndef OPERAND_ENUMS_HEADER
#define OPERAND_ENUMS_HEADER

enum class AddressingMethod
{
/* 0x00 */ _,   //No Operand
/* 0x01 */ $,   //Operand Specified in Another Table

/* Direct Address */

/* 0x02 */ A,   //Direct Address: [Segment]:[Offset]

/* Relative Address Displacement Operand */

/* 0x03 */ J,   //Relative offset
/* 0x04 */ O,   //Memory offset relative to the segment base

/* ModRM Operand */

/* 0x05 */ E,   //ModRegRM specifies a general purpose register or memory address
/* 0x06 */ M,   //ModRegRM only specifies memory address

/* General Register Operand */

/* 0x07 */ G,   //Reg field of ModRegRM specifies a general register

/* Segment Register Operand */

/* 0x08 */ S,   //Reg field of ModRegRM specifies a segment register

/* Immediate Operand */

/* 0x09 */ I,   //Immediate data

/* Fixed Address Operand */

/* 0x0A */ X,   //Memory addressed by the DS:rSI regsiter pair
/* 0x0B */ Y,   //Memory addressed by the ES:rDI register pair

/* 0x0C */ LAST //Placeholder
};

enum class GeneralRegister
{
/* 0x00 */ _,    //No Operand
/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x0C */ A = (GeneralRegister)AddressingMethod::LAST,       //General A Register
/* 0x0F */ C = A + 3,     //General C Register
/* 0x12 */ D = C + 3,     //General D Register
/* 0x15 */ B = D + 3,     //General B Register
/* 0x18 */ SP = B + 3,    //General SP Register
/* 0x1B */ BP = SP + 3,   //General BP Register
/* 0x1E */ SI = BP + 3,   //General SI Register
/* 0x21 */ DI = SI + 3,   //General DI Register

/* 0x24 */ LAST = DI + 3  //Placeholder
};

enum class SegmentRegister
{
/* 0x00 */ _,    //No Operand
/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x24 */ ES = (SegmentRegister)GeneralRegister::LAST,          //E Segment Register
/* 0x27 */ CS = ES + 3,    //C Segment Register
/* 0x2A */ SS = CS + 3,    //S Segment Register
/* 0x2D */ DS = CS + 3,    //D Segment Register
/* 0x30 */ FS = DS + 3,    //F Segment Register
/* 0x33 */ GS = FS + 3,    //G Segment Register

/* 0x36 */ LAST = GS + 3   //Placeholder
};

enum class Constant
{
/* 0x00 */ _,      //No Operand
/* 0x01 */ $,      //Operand Specified in Another Table

/* 0x36 */ ONE = (Constant)SegmentRegister::LAST, //The number one (Used only by the shift instruction group)

/* 0x37 */ LAST    //Placeholder
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