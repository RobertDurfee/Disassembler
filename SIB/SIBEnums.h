#ifndef SIB_ENUMS_HEADER
#define SIB_ENUMS_HEADER

enum class Scale
{
/* 0x00 */ ONE,  // * 1
/* 0x01 */ TWO,  // * 2
/* 0x02 */ FOUR, // * 4
/* 0x03 */ EIGHT // * 8
};

enum class Index
{
/* 0x00 */ _,   //No Index

/* 0x01 */ EAX, //General EAX Register
/* 0x02 */ ECX, //General ECX Register
/* 0x03 */ EDX, //General EDX Register
/* 0x04 */ EBX, //General EBX Register
/* 0x05 */ ESP, //General ESP Register
/* 0x06 */ EBP, //General EBP Register
/* 0x07 */ ESI, //General ESI Register
/* 0x08 */ EDI  //General EDI Register
};

enum class Base
{
/* 0x00 */ EAX, //General EAX Register
/* 0x01 */ ECX, //General ECX Register
/* 0x02 */ EDX, //General EDX Register
/* 0x03 */ EBX, //General EBX Register
/* 0x04 */ ESP, //General ESP Register
/* 0x05 */ EBP, //General EBP Register (if MOD = 01 or MOD = 10) or 32-bit Displacement (if MOD = 00)
/* 0x06 */ ESI, //General ESI Register
/* 0x07 */ EDI  //General EDI Register
};

#endif