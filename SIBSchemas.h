#ifndef SIB_SCHEMAS_HEADER
#define SIB_SCHEMAS_HEADER

// [Base + Index * Scale]

enum class Scale 
{ 
/* 0x00 */ ONE,  // * 1
/* 0x01 */ TWO,  // * 2
/* 0x02 */ FOUR, // * 4
/* 0x03 */ EIGHT // * 8
};

enum class Index 
{ 
/* 0x00 */ _,  //No Index

/* 0x01 */ A,  //General EAX Register
/* 0x02 */ C,  //General ECX Register
/* 0x03 */ D,  //General EDX Register
/* 0x04 */ B,  //General EBX Register
/* 0x05 */ SP, //General ESP Register
/* 0x06 */ BP, //General EBP Register
/* 0x07 */ SI, //General ESI Register
/* 0x08 */ DI  //General EDI Register
};

enum class Base  
{ 
/* 0x00 */ A,  //General EAX Register
/* 0x01 */ C,  //General ECX Register
/* 0x02 */ D,  //General EDX Register
/* 0x03 */ B,  //General EBX Register
/* 0x04 */ SP, //General ESP Register
/* 0x05 */ BP, //General EBP Register (if MOD = 01 or MOD = 10) or 32-bit Displacement (if MOD = 00)
/* 0x06 */ SI, //General ESI Register
/* 0x07 */ DI  //General EDI Register
};

struct SIBSchema
{
	Scale scale;
	Index index;
	Base  base;
};

const SIBSchema SIBSchemas[0x100 /* 00 000 000 - 11 111 111 */] = 
{
/*****************************************************/
/* 00 000 000 */ { Scale::ONE,   Index::A,  Base::A  },
/* 00 000 001 */ { Scale::ONE,   Index::A,  Base::C  },
/* 00 000 010 */ { Scale::ONE,   Index::A,  Base::D  },
/* 00 000 011 */ { Scale::ONE,   Index::A,  Base::B  },
/* 00 000 100 */ { Scale::ONE,   Index::A,  Base::SP },
/* 00 000 101 */ { Scale::ONE,   Index::A,  Base::BP },
/* 00 000 110 */ { Scale::ONE,   Index::A,  Base::SI },
/* 00 000 111 */ { Scale::ONE,   Index::A,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 001 000 */ { Scale::ONE,   Index::C,  Base::A  },
/* 00 001 001 */ { Scale::ONE,   Index::C,  Base::C  },
/* 00 001 010 */ { Scale::ONE,   Index::C,  Base::D  },
/* 00 001 011 */ { Scale::ONE,   Index::C,  Base::B  },
/* 00 001 100 */ { Scale::ONE,   Index::C,  Base::SP },
/* 00 001 101 */ { Scale::ONE,   Index::C,  Base::BP },
/* 00 001 110 */ { Scale::ONE,   Index::C,  Base::SI },
/* 00 001 111 */ { Scale::ONE,   Index::C,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 010 000 */ { Scale::ONE,   Index::D,  Base::A  },
/* 00 010 001 */ { Scale::ONE,   Index::D,  Base::C  },
/* 00 010 010 */ { Scale::ONE,   Index::D,  Base::D  },
/* 00 010 011 */ { Scale::ONE,   Index::D,  Base::B  },
/* 00 010 100 */ { Scale::ONE,   Index::D,  Base::SP },
/* 00 010 101 */ { Scale::ONE,   Index::D,  Base::BP },
/* 00 010 110 */ { Scale::ONE,   Index::D,  Base::SI },
/* 00 010 111 */ { Scale::ONE,   Index::D,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 011 000 */ { Scale::ONE,   Index::B,  Base::A  },
/* 00 011 001 */ { Scale::ONE,   Index::B,  Base::C  },
/* 00 011 010 */ { Scale::ONE,   Index::B,  Base::D  },
/* 00 011 011 */ { Scale::ONE,   Index::B,  Base::B  },
/* 00 011 100 */ { Scale::ONE,   Index::B,  Base::SP },
/* 00 011 101 */ { Scale::ONE,   Index::B,  Base::BP },
/* 00 011 110 */ { Scale::ONE,   Index::B,  Base::SI },
/* 00 011 111 */ { Scale::ONE,   Index::B,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 100 000 */ { Scale::ONE,   Index::_,  Base::A  },
/* 00 100 001 */ { Scale::ONE,   Index::_,  Base::C  },
/* 00 100 010 */ { Scale::ONE,   Index::_,  Base::D  },
/* 00 100 011 */ { Scale::ONE,   Index::_,  Base::B  },
/* 00 100 100 */ { Scale::ONE,   Index::_,  Base::SP },
/* 00 100 101 */ { Scale::ONE,   Index::_,  Base::BP },
/* 00 100 110 */ { Scale::ONE,   Index::_,  Base::SI },
/* 00 100 111 */ { Scale::ONE,   Index::_,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 101 000 */ { Scale::ONE,   Index::BP, Base::A  },
/* 00 101 001 */ { Scale::ONE,   Index::BP, Base::C  },
/* 00 101 010 */ { Scale::ONE,   Index::BP, Base::D  },
/* 00 101 011 */ { Scale::ONE,   Index::BP, Base::B  },
/* 00 101 100 */ { Scale::ONE,   Index::BP, Base::SP },
/* 00 101 101 */ { Scale::ONE,   Index::BP, Base::BP },
/* 00 101 110 */ { Scale::ONE,   Index::BP, Base::SI },
/* 00 101 111 */ { Scale::ONE,   Index::BP, Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 110 000 */ { Scale::ONE,   Index::SI, Base::A  },
/* 00 110 001 */ { Scale::ONE,   Index::SI, Base::C  },
/* 00 110 010 */ { Scale::ONE,   Index::SI, Base::D  },
/* 00 110 011 */ { Scale::ONE,   Index::SI, Base::B  },
/* 00 110 100 */ { Scale::ONE,   Index::SI, Base::SP },
/* 00 110 101 */ { Scale::ONE,   Index::SI, Base::BP },
/* 00 110 110 */ { Scale::ONE,   Index::SI, Base::SI },
/* 00 110 111 */ { Scale::ONE,   Index::SI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 00 111 000 */ { Scale::ONE,   Index::DI, Base::A  },
/* 00 111 001 */ { Scale::ONE,   Index::DI, Base::C  },
/* 00 111 010 */ { Scale::ONE,   Index::DI, Base::D  },
/* 00 111 011 */ { Scale::ONE,   Index::DI, Base::B  },
/* 00 111 100 */ { Scale::ONE,   Index::DI, Base::SP },
/* 00 111 101 */ { Scale::ONE,   Index::DI, Base::BP },
/* 00 111 110 */ { Scale::ONE,   Index::DI, Base::SI },
/* 00 111 111 */ { Scale::ONE,   Index::DI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 000 000 */ { Scale::TWO,   Index::A,  Base::A  },
/* 01 000 001 */ { Scale::TWO,   Index::A,  Base::C  },
/* 01 000 010 */ { Scale::TWO,   Index::A,  Base::D  },
/* 01 000 011 */ { Scale::TWO,   Index::A,  Base::B  },
/* 01 000 100 */ { Scale::TWO,   Index::A,  Base::SP },
/* 01 000 101 */ { Scale::TWO,   Index::A,  Base::BP },
/* 01 000 110 */ { Scale::TWO,   Index::A,  Base::SI },
/* 01 000 111 */ { Scale::TWO,   Index::A,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 001 000 */ { Scale::TWO,   Index::C,  Base::A  },
/* 01 001 001 */ { Scale::TWO,   Index::C,  Base::C  },
/* 01 001 010 */ { Scale::TWO,   Index::C,  Base::D  },
/* 01 001 011 */ { Scale::TWO,   Index::C,  Base::B  },
/* 01 001 100 */ { Scale::TWO,   Index::C,  Base::SP },
/* 01 001 101 */ { Scale::TWO,   Index::C,  Base::BP },
/* 01 001 110 */ { Scale::TWO,   Index::C,  Base::SI },
/* 01 001 111 */ { Scale::TWO,   Index::C,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 010 000 */ { Scale::TWO,   Index::D,  Base::A  },
/* 01 010 001 */ { Scale::TWO,   Index::D,  Base::C  },
/* 01 010 010 */ { Scale::TWO,   Index::D,  Base::D  },
/* 01 010 011 */ { Scale::TWO,   Index::D,  Base::B  },
/* 01 010 100 */ { Scale::TWO,   Index::D,  Base::SP },
/* 01 010 101 */ { Scale::TWO,   Index::D,  Base::BP },
/* 01 010 110 */ { Scale::TWO,   Index::D,  Base::SI },
/* 01 010 111 */ { Scale::TWO,   Index::D,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 011 000 */ { Scale::TWO,   Index::B,  Base::A  },
/* 01 011 001 */ { Scale::TWO,   Index::B,  Base::C  },
/* 01 011 010 */ { Scale::TWO,   Index::B,  Base::D  },
/* 01 011 011 */ { Scale::TWO,   Index::B,  Base::B  },
/* 01 011 100 */ { Scale::TWO,   Index::B,  Base::SP },
/* 01 011 101 */ { Scale::TWO,   Index::B,  Base::BP },
/* 01 011 110 */ { Scale::TWO,   Index::B,  Base::SI },
/* 01 011 111 */ { Scale::TWO,   Index::B,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 100 000 */ { Scale::TWO,   Index::_,  Base::A  },
/* 01 100 001 */ { Scale::TWO,   Index::_,  Base::C  },
/* 01 100 010 */ { Scale::TWO,   Index::_,  Base::D  },
/* 01 100 011 */ { Scale::TWO,   Index::_,  Base::B  },
/* 01 100 100 */ { Scale::TWO,   Index::_,  Base::SP },
/* 01 100 101 */ { Scale::TWO,   Index::_,  Base::BP },
/* 01 100 110 */ { Scale::TWO,   Index::_,  Base::SI },
/* 01 100 111 */ { Scale::TWO,   Index::_,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 101 000 */ { Scale::TWO,   Index::BP, Base::A  },
/* 01 101 001 */ { Scale::TWO,   Index::BP, Base::C  },
/* 01 101 010 */ { Scale::TWO,   Index::BP, Base::D  },
/* 01 101 011 */ { Scale::TWO,   Index::BP, Base::B  },
/* 01 101 100 */ { Scale::TWO,   Index::BP, Base::SP },
/* 01 101 101 */ { Scale::TWO,   Index::BP, Base::BP },
/* 01 101 110 */ { Scale::TWO,   Index::BP, Base::SI },
/* 01 101 111 */ { Scale::TWO,   Index::BP, Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 110 000 */ { Scale::TWO,   Index::SI, Base::A  },
/* 01 110 001 */ { Scale::TWO,   Index::SI, Base::C  },
/* 01 110 010 */ { Scale::TWO,   Index::SI, Base::D  },
/* 01 110 011 */ { Scale::TWO,   Index::SI, Base::B  },
/* 01 110 100 */ { Scale::TWO,   Index::SI, Base::SP },
/* 01 110 101 */ { Scale::TWO,   Index::SI, Base::BP },
/* 01 110 110 */ { Scale::TWO,   Index::SI, Base::SI },
/* 01 110 111 */ { Scale::TWO,   Index::SI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 01 111 000 */ { Scale::TWO,   Index::DI, Base::A  },
/* 01 111 001 */ { Scale::TWO,   Index::DI, Base::C  },
/* 01 111 010 */ { Scale::TWO,   Index::DI, Base::D  },
/* 01 111 011 */ { Scale::TWO,   Index::DI, Base::B  },
/* 01 111 100 */ { Scale::TWO,   Index::DI, Base::SP },
/* 01 111 101 */ { Scale::TWO,   Index::DI, Base::BP },
/* 01 111 110 */ { Scale::TWO,   Index::DI, Base::SI },
/* 01 111 111 */ { Scale::TWO,   Index::DI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 000 000 */ { Scale::FOUR,  Index::A,  Base::A  },
/* 10 000 001 */ { Scale::FOUR,  Index::A,  Base::C  },
/* 10 000 010 */ { Scale::FOUR,  Index::A,  Base::D  },
/* 10 000 011 */ { Scale::FOUR,  Index::A,  Base::B  },
/* 10 000 100 */ { Scale::FOUR,  Index::A,  Base::SP },
/* 10 000 101 */ { Scale::FOUR,  Index::A,  Base::BP },
/* 10 000 110 */ { Scale::FOUR,  Index::A,  Base::SI },
/* 10 000 111 */ { Scale::FOUR,  Index::A,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 001 000 */ { Scale::FOUR,  Index::C,  Base::A  },
/* 10 001 001 */ { Scale::FOUR,  Index::C,  Base::C  },
/* 10 001 010 */ { Scale::FOUR,  Index::C,  Base::D  },
/* 10 001 011 */ { Scale::FOUR,  Index::C,  Base::B  },
/* 10 001 100 */ { Scale::FOUR,  Index::C,  Base::SP },
/* 10 001 101 */ { Scale::FOUR,  Index::C,  Base::BP },
/* 10 001 110 */ { Scale::FOUR,  Index::C,  Base::SI },
/* 10 001 111 */ { Scale::FOUR,  Index::C,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 010 000 */ { Scale::FOUR,  Index::D,  Base::A  },
/* 10 010 001 */ { Scale::FOUR,  Index::D,  Base::C  },
/* 10 010 010 */ { Scale::FOUR,  Index::D,  Base::D  },
/* 10 010 011 */ { Scale::FOUR,  Index::D,  Base::B  },
/* 10 010 100 */ { Scale::FOUR,  Index::D,  Base::SP },
/* 10 010 101 */ { Scale::FOUR,  Index::D,  Base::BP },
/* 10 010 110 */ { Scale::FOUR,  Index::D,  Base::SI },
/* 10 010 111 */ { Scale::FOUR,  Index::D,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 011 000 */ { Scale::FOUR,  Index::B,  Base::A  },
/* 10 011 001 */ { Scale::FOUR,  Index::B,  Base::C  },
/* 10 011 010 */ { Scale::FOUR,  Index::B,  Base::D  },
/* 10 011 011 */ { Scale::FOUR,  Index::B,  Base::B  },
/* 10 011 100 */ { Scale::FOUR,  Index::B,  Base::SP },
/* 10 011 101 */ { Scale::FOUR,  Index::B,  Base::BP },
/* 10 011 110 */ { Scale::FOUR,  Index::B,  Base::SI },
/* 10 011 111 */ { Scale::FOUR,  Index::B,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 100 000 */ { Scale::FOUR,  Index::_,  Base::A  },
/* 10 100 001 */ { Scale::FOUR,  Index::_,  Base::C  },
/* 10 100 010 */ { Scale::FOUR,  Index::_,  Base::D  },
/* 10 100 011 */ { Scale::FOUR,  Index::_,  Base::B  },
/* 10 100 100 */ { Scale::FOUR,  Index::_,  Base::SP },
/* 10 100 101 */ { Scale::FOUR,  Index::_,  Base::BP },
/* 10 100 110 */ { Scale::FOUR,  Index::_,  Base::SI },
/* 10 100 111 */ { Scale::FOUR,  Index::_,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 101 000 */ { Scale::FOUR,  Index::BP, Base::A  },
/* 10 101 001 */ { Scale::FOUR,  Index::BP, Base::C  },
/* 10 101 010 */ { Scale::FOUR,  Index::BP, Base::D  },
/* 10 101 011 */ { Scale::FOUR,  Index::BP, Base::B  },
/* 10 101 100 */ { Scale::FOUR,  Index::BP, Base::SP },
/* 10 101 101 */ { Scale::FOUR,  Index::BP, Base::BP },
/* 10 101 110 */ { Scale::FOUR,  Index::BP, Base::SI },
/* 10 101 111 */ { Scale::FOUR,  Index::BP, Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 110 000 */ { Scale::FOUR,  Index::SI, Base::A  },
/* 10 110 001 */ { Scale::FOUR,  Index::SI, Base::C  },
/* 10 110 010 */ { Scale::FOUR,  Index::SI, Base::D  },
/* 10 110 011 */ { Scale::FOUR,  Index::SI, Base::B  },
/* 10 110 100 */ { Scale::FOUR,  Index::SI, Base::SP },
/* 10 110 101 */ { Scale::FOUR,  Index::SI, Base::BP },
/* 10 110 110 */ { Scale::FOUR,  Index::SI, Base::SI },
/* 10 110 111 */ { Scale::FOUR,  Index::SI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 10 111 000 */ { Scale::FOUR,  Index::DI, Base::A  },
/* 10 111 001 */ { Scale::FOUR,  Index::DI, Base::C  },
/* 10 111 010 */ { Scale::FOUR,  Index::DI, Base::D  },
/* 10 111 011 */ { Scale::FOUR,  Index::DI, Base::B  },
/* 10 111 100 */ { Scale::FOUR,  Index::DI, Base::SP },
/* 10 111 101 */ { Scale::FOUR,  Index::DI, Base::BP },
/* 10 111 110 */ { Scale::FOUR,  Index::DI, Base::SI },
/* 10 111 111 */ { Scale::FOUR,  Index::DI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 000 000 */ { Scale::EIGHT, Index::A,  Base::A  },
/* 11 000 001 */ { Scale::EIGHT, Index::A,  Base::C  },
/* 11 000 010 */ { Scale::EIGHT, Index::A,  Base::D  },
/* 11 000 011 */ { Scale::EIGHT, Index::A,  Base::B  },
/* 11 000 100 */ { Scale::EIGHT, Index::A,  Base::SP },
/* 11 000 101 */ { Scale::EIGHT, Index::A,  Base::BP },
/* 11 000 110 */ { Scale::EIGHT, Index::A,  Base::SI },
/* 11 000 111 */ { Scale::EIGHT, Index::A,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 001 000 */ { Scale::EIGHT, Index::C,  Base::A  },
/* 11 001 001 */ { Scale::EIGHT, Index::C,  Base::C  },
/* 11 001 010 */ { Scale::EIGHT, Index::C,  Base::D  },
/* 11 001 011 */ { Scale::EIGHT, Index::C,  Base::B  },
/* 11 001 100 */ { Scale::EIGHT, Index::C,  Base::SP },
/* 11 001 101 */ { Scale::EIGHT, Index::C,  Base::BP },
/* 11 001 110 */ { Scale::EIGHT, Index::C,  Base::SI },
/* 11 001 111 */ { Scale::EIGHT, Index::C,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 010 000 */ { Scale::EIGHT, Index::D,  Base::A  },
/* 11 010 001 */ { Scale::EIGHT, Index::D,  Base::C  },
/* 11 010 010 */ { Scale::EIGHT, Index::D,  Base::D  },
/* 11 010 011 */ { Scale::EIGHT, Index::D,  Base::B  },
/* 11 010 100 */ { Scale::EIGHT, Index::D,  Base::SP },
/* 11 010 101 */ { Scale::EIGHT, Index::D,  Base::BP },
/* 11 010 110 */ { Scale::EIGHT, Index::D,  Base::SI },
/* 11 010 111 */ { Scale::EIGHT, Index::D,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 011 000 */ { Scale::EIGHT, Index::B,  Base::A  },
/* 11 011 001 */ { Scale::EIGHT, Index::B,  Base::C  },
/* 11 011 010 */ { Scale::EIGHT, Index::B,  Base::D  },
/* 11 011 011 */ { Scale::EIGHT, Index::B,  Base::B  },
/* 11 011 100 */ { Scale::EIGHT, Index::B,  Base::SP },
/* 11 011 101 */ { Scale::EIGHT, Index::B,  Base::BP },
/* 11 011 110 */ { Scale::EIGHT, Index::B,  Base::SI },
/* 11 011 111 */ { Scale::EIGHT, Index::B,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 100 000 */ { Scale::EIGHT, Index::_,  Base::A  },
/* 11 100 001 */ { Scale::EIGHT, Index::_,  Base::C  },
/* 11 100 010 */ { Scale::EIGHT, Index::_,  Base::D  },
/* 11 100 011 */ { Scale::EIGHT, Index::_,  Base::B  },
/* 11 100 100 */ { Scale::EIGHT, Index::_,  Base::SP },
/* 11 100 101 */ { Scale::EIGHT, Index::_,  Base::BP },
/* 11 100 110 */ { Scale::EIGHT, Index::_,  Base::SI },
/* 11 100 111 */ { Scale::EIGHT, Index::_,  Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 101 000 */ { Scale::EIGHT, Index::BP, Base::A  },
/* 11 101 001 */ { Scale::EIGHT, Index::BP, Base::C  },
/* 11 101 010 */ { Scale::EIGHT, Index::BP, Base::D  },
/* 11 101 011 */ { Scale::EIGHT, Index::BP, Base::B  },
/* 11 101 100 */ { Scale::EIGHT, Index::BP, Base::SP },
/* 11 101 101 */ { Scale::EIGHT, Index::BP, Base::BP },
/* 11 101 110 */ { Scale::EIGHT, Index::BP, Base::SI },
/* 11 101 111 */ { Scale::EIGHT, Index::BP, Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 110 000 */ { Scale::EIGHT, Index::SI, Base::A  },
/* 11 110 001 */ { Scale::EIGHT, Index::SI, Base::C  },
/* 11 110 010 */ { Scale::EIGHT, Index::SI, Base::D  },
/* 11 110 011 */ { Scale::EIGHT, Index::SI, Base::B  },
/* 11 110 100 */ { Scale::EIGHT, Index::SI, Base::SP },
/* 11 110 101 */ { Scale::EIGHT, Index::SI, Base::BP },
/* 11 110 110 */ { Scale::EIGHT, Index::SI, Base::SI },
/* 11 110 111 */ { Scale::EIGHT, Index::SI, Base::DI },
/*****************************************************/

/*****************************************************/
/* 11 111 000 */ { Scale::EIGHT, Index::DI, Base::A  },
/* 11 111 001 */ { Scale::EIGHT, Index::DI, Base::C  },
/* 11 111 010 */ { Scale::EIGHT, Index::DI, Base::D  },
/* 11 111 011 */ { Scale::EIGHT, Index::DI, Base::B  },
/* 11 111 100 */ { Scale::EIGHT, Index::DI, Base::SP },
/* 11 111 101 */ { Scale::EIGHT, Index::DI, Base::BP },
/* 11 111 110 */ { Scale::EIGHT, Index::DI, Base::SI },
/* 11 111 111 */ { Scale::EIGHT, Index::DI, Base::DI }
/*****************************************************/
};

#endif