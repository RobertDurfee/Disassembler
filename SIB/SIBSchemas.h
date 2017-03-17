#ifndef SIB_SCHEMAS_HEADER
#define SIB_SCHEMAS_HEADER

#include "SIBEnums.h" //Scale, Index, Base

struct SIBSchema
{
	Scale scale;
	Index index;
	Base  base;
};

const SIBSchema EmptySIBSchema = { Scale::_, Index::_, Base::_ };

const SIBSchema SIBSchemas[0x100 /* 00 000 000 - 11 111 111 */] = 
{
/*******************************************************/
/* 00 000 000 */ { Scale::ONE,   Index::EAX, Base::EAX },
/* 00 000 001 */ { Scale::ONE,   Index::EAX, Base::ECX },
/* 00 000 010 */ { Scale::ONE,   Index::EAX, Base::EDX },
/* 00 000 011 */ { Scale::ONE,   Index::EAX, Base::EBX },
/* 00 000 100 */ { Scale::ONE,   Index::EAX, Base::ESP },
/* 00 000 101 */ { Scale::ONE,   Index::EAX, Base::EBP },
/* 00 000 110 */ { Scale::ONE,   Index::EAX, Base::ESI },
/* 00 000 111 */ { Scale::ONE,   Index::EAX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 001 000 */ { Scale::ONE,   Index::ECX, Base::EAX },
/* 00 001 001 */ { Scale::ONE,   Index::ECX, Base::ECX },
/* 00 001 010 */ { Scale::ONE,   Index::ECX, Base::EDX },
/* 00 001 011 */ { Scale::ONE,   Index::ECX, Base::EBX },
/* 00 001 100 */ { Scale::ONE,   Index::ECX, Base::ESP },
/* 00 001 101 */ { Scale::ONE,   Index::ECX, Base::EBP },
/* 00 001 110 */ { Scale::ONE,   Index::ECX, Base::ESI },
/* 00 001 111 */ { Scale::ONE,   Index::ECX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 010 000 */ { Scale::ONE,   Index::EDX, Base::EAX },
/* 00 010 001 */ { Scale::ONE,   Index::EDX, Base::ECX },
/* 00 010 010 */ { Scale::ONE,   Index::EDX, Base::EDX },
/* 00 010 011 */ { Scale::ONE,   Index::EDX, Base::EBX },
/* 00 010 100 */ { Scale::ONE,   Index::EDX, Base::ESP },
/* 00 010 101 */ { Scale::ONE,   Index::EDX, Base::EBP },
/* 00 010 110 */ { Scale::ONE,   Index::EDX, Base::ESI },
/* 00 010 111 */ { Scale::ONE,   Index::EDX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 011 000 */ { Scale::ONE,   Index::EBX, Base::EAX },
/* 00 011 001 */ { Scale::ONE,   Index::EBX, Base::ECX },
/* 00 011 010 */ { Scale::ONE,   Index::EBX, Base::EDX },
/* 00 011 011 */ { Scale::ONE,   Index::EBX, Base::EBX },
/* 00 011 100 */ { Scale::ONE,   Index::EBX, Base::ESP },
/* 00 011 101 */ { Scale::ONE,   Index::EBX, Base::EBP },
/* 00 011 110 */ { Scale::ONE,   Index::EBX, Base::ESI },
/* 00 011 111 */ { Scale::ONE,   Index::EBX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 100 000 */ { Scale::ONE,   Index::_,   Base::EAX },
/* 00 100 001 */ { Scale::ONE,   Index::_,   Base::ECX },
/* 00 100 010 */ { Scale::ONE,   Index::_,   Base::EDX },
/* 00 100 011 */ { Scale::ONE,   Index::_,   Base::EBX },
/* 00 100 100 */ { Scale::ONE,   Index::_,   Base::ESP },
/* 00 100 101 */ { Scale::ONE,   Index::_,   Base::EBP },
/* 00 100 110 */ { Scale::ONE,   Index::_,   Base::ESI },
/* 00 100 111 */ { Scale::ONE,   Index::_,   Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 101 000 */ { Scale::ONE,   Index::EBP, Base::EAX },
/* 00 101 001 */ { Scale::ONE,   Index::EBP, Base::ECX },
/* 00 101 010 */ { Scale::ONE,   Index::EBP, Base::EDX },
/* 00 101 011 */ { Scale::ONE,   Index::EBP, Base::EBX },
/* 00 101 100 */ { Scale::ONE,   Index::EBP, Base::ESP },
/* 00 101 101 */ { Scale::ONE,   Index::EBP, Base::EBP },
/* 00 101 110 */ { Scale::ONE,   Index::EBP, Base::ESI },
/* 00 101 111 */ { Scale::ONE,   Index::EBP, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 110 000 */ { Scale::ONE,   Index::ESI, Base::EAX },
/* 00 110 001 */ { Scale::ONE,   Index::ESI, Base::ECX },
/* 00 110 010 */ { Scale::ONE,   Index::ESI, Base::EDX },
/* 00 110 011 */ { Scale::ONE,   Index::ESI, Base::EBX },
/* 00 110 100 */ { Scale::ONE,   Index::ESI, Base::ESP },
/* 00 110 101 */ { Scale::ONE,   Index::ESI, Base::EBP },
/* 00 110 110 */ { Scale::ONE,   Index::ESI, Base::ESI },
/* 00 110 111 */ { Scale::ONE,   Index::ESI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 00 111 000 */ { Scale::ONE,   Index::EDI, Base::EAX },
/* 00 111 001 */ { Scale::ONE,   Index::EDI, Base::ECX },
/* 00 111 010 */ { Scale::ONE,   Index::EDI, Base::EDX },
/* 00 111 011 */ { Scale::ONE,   Index::EDI, Base::EBX },
/* 00 111 100 */ { Scale::ONE,   Index::EDI, Base::ESP },
/* 00 111 101 */ { Scale::ONE,   Index::EDI, Base::EBP },
/* 00 111 110 */ { Scale::ONE,   Index::EDI, Base::ESI },
/* 00 111 111 */ { Scale::ONE,   Index::EDI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 000 000 */ { Scale::TWO,   Index::EAX, Base::EAX },
/* 01 000 001 */ { Scale::TWO,   Index::EAX, Base::ECX },
/* 01 000 010 */ { Scale::TWO,   Index::EAX, Base::EDX },
/* 01 000 011 */ { Scale::TWO,   Index::EAX, Base::EBX },
/* 01 000 100 */ { Scale::TWO,   Index::EAX, Base::ESP },
/* 01 000 101 */ { Scale::TWO,   Index::EAX, Base::EBP },
/* 01 000 110 */ { Scale::TWO,   Index::EAX, Base::ESI },
/* 01 000 111 */ { Scale::TWO,   Index::EAX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 001 000 */ { Scale::TWO,   Index::ECX, Base::EAX },
/* 01 001 001 */ { Scale::TWO,   Index::ECX, Base::ECX },
/* 01 001 010 */ { Scale::TWO,   Index::ECX, Base::EDX },
/* 01 001 011 */ { Scale::TWO,   Index::ECX, Base::EBX },
/* 01 001 100 */ { Scale::TWO,   Index::ECX, Base::ESP },
/* 01 001 101 */ { Scale::TWO,   Index::ECX, Base::EBP },
/* 01 001 110 */ { Scale::TWO,   Index::ECX, Base::ESI },
/* 01 001 111 */ { Scale::TWO,   Index::ECX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 010 000 */ { Scale::TWO,   Index::EDX, Base::EAX },
/* 01 010 001 */ { Scale::TWO,   Index::EDX, Base::ECX },
/* 01 010 010 */ { Scale::TWO,   Index::EDX, Base::EDX },
/* 01 010 011 */ { Scale::TWO,   Index::EDX, Base::EBX },
/* 01 010 100 */ { Scale::TWO,   Index::EDX, Base::ESP },
/* 01 010 101 */ { Scale::TWO,   Index::EDX, Base::EBP },
/* 01 010 110 */ { Scale::TWO,   Index::EDX, Base::ESI },
/* 01 010 111 */ { Scale::TWO,   Index::EDX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 011 000 */ { Scale::TWO,   Index::EBX, Base::EAX },
/* 01 011 001 */ { Scale::TWO,   Index::EBX, Base::ECX },
/* 01 011 010 */ { Scale::TWO,   Index::EBX, Base::EDX },
/* 01 011 011 */ { Scale::TWO,   Index::EBX, Base::EBX },
/* 01 011 100 */ { Scale::TWO,   Index::EBX, Base::ESP },
/* 01 011 101 */ { Scale::TWO,   Index::EBX, Base::EBP },
/* 01 011 110 */ { Scale::TWO,   Index::EBX, Base::ESI },
/* 01 011 111 */ { Scale::TWO,   Index::EBX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 100 000 */ { Scale::TWO,   Index::_,   Base::EAX },
/* 01 100 001 */ { Scale::TWO,   Index::_,   Base::ECX },
/* 01 100 010 */ { Scale::TWO,   Index::_,   Base::EDX },
/* 01 100 011 */ { Scale::TWO,   Index::_,   Base::EBX },
/* 01 100 100 */ { Scale::TWO,   Index::_,   Base::ESP },
/* 01 100 101 */ { Scale::TWO,   Index::_,   Base::EBP },
/* 01 100 110 */ { Scale::TWO,   Index::_,   Base::ESI },
/* 01 100 111 */ { Scale::TWO,   Index::_,   Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 101 000 */ { Scale::TWO,   Index::EBP, Base::EAX },
/* 01 101 001 */ { Scale::TWO,   Index::EBP, Base::ECX },
/* 01 101 010 */ { Scale::TWO,   Index::EBP, Base::EDX },
/* 01 101 011 */ { Scale::TWO,   Index::EBP, Base::EBX },
/* 01 101 100 */ { Scale::TWO,   Index::EBP, Base::ESP },
/* 01 101 101 */ { Scale::TWO,   Index::EBP, Base::EBP },
/* 01 101 110 */ { Scale::TWO,   Index::EBP, Base::ESI },
/* 01 101 111 */ { Scale::TWO,   Index::EBP, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 110 000 */ { Scale::TWO,   Index::ESI, Base::EAX },
/* 01 110 001 */ { Scale::TWO,   Index::ESI, Base::ECX },
/* 01 110 010 */ { Scale::TWO,   Index::ESI, Base::EDX },
/* 01 110 011 */ { Scale::TWO,   Index::ESI, Base::EBX },
/* 01 110 100 */ { Scale::TWO,   Index::ESI, Base::ESP },
/* 01 110 101 */ { Scale::TWO,   Index::ESI, Base::EBP },
/* 01 110 110 */ { Scale::TWO,   Index::ESI, Base::ESI },
/* 01 110 111 */ { Scale::TWO,   Index::ESI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 01 111 000 */ { Scale::TWO,   Index::EDI, Base::EAX },
/* 01 111 001 */ { Scale::TWO,   Index::EDI, Base::ECX },
/* 01 111 010 */ { Scale::TWO,   Index::EDI, Base::EDX },
/* 01 111 011 */ { Scale::TWO,   Index::EDI, Base::EBX },
/* 01 111 100 */ { Scale::TWO,   Index::EDI, Base::ESP },
/* 01 111 101 */ { Scale::TWO,   Index::EDI, Base::EBP },
/* 01 111 110 */ { Scale::TWO,   Index::EDI, Base::ESI },
/* 01 111 111 */ { Scale::TWO,   Index::EDI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 000 000 */ { Scale::FOUR,  Index::EAX, Base::EAX },
/* 10 000 001 */ { Scale::FOUR,  Index::EAX, Base::ECX },
/* 10 000 010 */ { Scale::FOUR,  Index::EAX, Base::EDX },
/* 10 000 011 */ { Scale::FOUR,  Index::EAX, Base::EBX },
/* 10 000 100 */ { Scale::FOUR,  Index::EAX, Base::ESP },
/* 10 000 101 */ { Scale::FOUR,  Index::EAX, Base::EBP },
/* 10 000 110 */ { Scale::FOUR,  Index::EAX, Base::ESI },
/* 10 000 111 */ { Scale::FOUR,  Index::EAX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 001 000 */ { Scale::FOUR,  Index::ECX, Base::EAX },
/* 10 001 001 */ { Scale::FOUR,  Index::ECX, Base::ECX },
/* 10 001 010 */ { Scale::FOUR,  Index::ECX, Base::EDX },
/* 10 001 011 */ { Scale::FOUR,  Index::ECX, Base::EBX },
/* 10 001 100 */ { Scale::FOUR,  Index::ECX, Base::ESP },
/* 10 001 101 */ { Scale::FOUR,  Index::ECX, Base::EBP },
/* 10 001 110 */ { Scale::FOUR,  Index::ECX, Base::ESI },
/* 10 001 111 */ { Scale::FOUR,  Index::ECX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 010 000 */ { Scale::FOUR,  Index::EDX, Base::EAX },
/* 10 010 001 */ { Scale::FOUR,  Index::EDX, Base::ECX },
/* 10 010 010 */ { Scale::FOUR,  Index::EDX, Base::EDX },
/* 10 010 011 */ { Scale::FOUR,  Index::EDX, Base::EBX },
/* 10 010 100 */ { Scale::FOUR,  Index::EDX, Base::ESP },
/* 10 010 101 */ { Scale::FOUR,  Index::EDX, Base::EBP },
/* 10 010 110 */ { Scale::FOUR,  Index::EDX, Base::ESI },
/* 10 010 111 */ { Scale::FOUR,  Index::EDX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 011 000 */ { Scale::FOUR,  Index::EBX, Base::EAX },
/* 10 011 001 */ { Scale::FOUR,  Index::EBX, Base::ECX },
/* 10 011 010 */ { Scale::FOUR,  Index::EBX, Base::EDX },
/* 10 011 011 */ { Scale::FOUR,  Index::EBX, Base::EBX },
/* 10 011 100 */ { Scale::FOUR,  Index::EBX, Base::ESP },
/* 10 011 101 */ { Scale::FOUR,  Index::EBX, Base::EBP },
/* 10 011 110 */ { Scale::FOUR,  Index::EBX, Base::ESI },
/* 10 011 111 */ { Scale::FOUR,  Index::EBX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 100 000 */ { Scale::FOUR,  Index::_,   Base::EAX },
/* 10 100 001 */ { Scale::FOUR,  Index::_,   Base::ECX },
/* 10 100 010 */ { Scale::FOUR,  Index::_,   Base::EDX },
/* 10 100 011 */ { Scale::FOUR,  Index::_,   Base::EBX },
/* 10 100 100 */ { Scale::FOUR,  Index::_,   Base::ESP },
/* 10 100 101 */ { Scale::FOUR,  Index::_,   Base::EBP },
/* 10 100 110 */ { Scale::FOUR,  Index::_,   Base::ESI },
/* 10 100 111 */ { Scale::FOUR,  Index::_,   Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 101 000 */ { Scale::FOUR,  Index::EBP, Base::EAX },
/* 10 101 001 */ { Scale::FOUR,  Index::EBP, Base::ECX },
/* 10 101 010 */ { Scale::FOUR,  Index::EBP, Base::EDX },
/* 10 101 011 */ { Scale::FOUR,  Index::EBP, Base::EBX },
/* 10 101 100 */ { Scale::FOUR,  Index::EBP, Base::ESP },
/* 10 101 101 */ { Scale::FOUR,  Index::EBP, Base::EBP },
/* 10 101 110 */ { Scale::FOUR,  Index::EBP, Base::ESI },
/* 10 101 111 */ { Scale::FOUR,  Index::EBP, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 110 000 */ { Scale::FOUR,  Index::ESI, Base::EAX },
/* 10 110 001 */ { Scale::FOUR,  Index::ESI, Base::ECX },
/* 10 110 010 */ { Scale::FOUR,  Index::ESI, Base::EDX },
/* 10 110 011 */ { Scale::FOUR,  Index::ESI, Base::EBX },
/* 10 110 100 */ { Scale::FOUR,  Index::ESI, Base::ESP },
/* 10 110 101 */ { Scale::FOUR,  Index::ESI, Base::EBP },
/* 10 110 110 */ { Scale::FOUR,  Index::ESI, Base::ESI },
/* 10 110 111 */ { Scale::FOUR,  Index::ESI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 10 111 000 */ { Scale::FOUR,  Index::EDI, Base::EAX },
/* 10 111 001 */ { Scale::FOUR,  Index::EDI, Base::ECX },
/* 10 111 010 */ { Scale::FOUR,  Index::EDI, Base::EDX },
/* 10 111 011 */ { Scale::FOUR,  Index::EDI, Base::EBX },
/* 10 111 100 */ { Scale::FOUR,  Index::EDI, Base::ESP },
/* 10 111 101 */ { Scale::FOUR,  Index::EDI, Base::EBP },
/* 10 111 110 */ { Scale::FOUR,  Index::EDI, Base::ESI },
/* 10 111 111 */ { Scale::FOUR,  Index::EDI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 000 000 */ { Scale::EIGHT, Index::EAX, Base::EAX },
/* 11 000 001 */ { Scale::EIGHT, Index::EAX, Base::ECX },
/* 11 000 010 */ { Scale::EIGHT, Index::EAX, Base::EDX },
/* 11 000 011 */ { Scale::EIGHT, Index::EAX, Base::EBX },
/* 11 000 100 */ { Scale::EIGHT, Index::EAX, Base::ESP },
/* 11 000 101 */ { Scale::EIGHT, Index::EAX, Base::EBP },
/* 11 000 110 */ { Scale::EIGHT, Index::EAX, Base::ESI },
/* 11 000 111 */ { Scale::EIGHT, Index::EAX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 001 000 */ { Scale::EIGHT, Index::ECX, Base::EAX },
/* 11 001 001 */ { Scale::EIGHT, Index::ECX, Base::ECX },
/* 11 001 010 */ { Scale::EIGHT, Index::ECX, Base::EDX },
/* 11 001 011 */ { Scale::EIGHT, Index::ECX, Base::EBX },
/* 11 001 100 */ { Scale::EIGHT, Index::ECX, Base::ESP },
/* 11 001 101 */ { Scale::EIGHT, Index::ECX, Base::EBP },
/* 11 001 110 */ { Scale::EIGHT, Index::ECX, Base::ESI },
/* 11 001 111 */ { Scale::EIGHT, Index::ECX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 010 000 */ { Scale::EIGHT, Index::EDX, Base::EAX },
/* 11 010 001 */ { Scale::EIGHT, Index::EDX, Base::ECX },
/* 11 010 010 */ { Scale::EIGHT, Index::EDX, Base::EDX },
/* 11 010 011 */ { Scale::EIGHT, Index::EDX, Base::EBX },
/* 11 010 100 */ { Scale::EIGHT, Index::EDX, Base::ESP },
/* 11 010 101 */ { Scale::EIGHT, Index::EDX, Base::EBP },
/* 11 010 110 */ { Scale::EIGHT, Index::EDX, Base::ESI },
/* 11 010 111 */ { Scale::EIGHT, Index::EDX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 011 000 */ { Scale::EIGHT, Index::EBX, Base::EAX },
/* 11 011 001 */ { Scale::EIGHT, Index::EBX, Base::ECX },
/* 11 011 010 */ { Scale::EIGHT, Index::EBX, Base::EDX },
/* 11 011 011 */ { Scale::EIGHT, Index::EBX, Base::EBX },
/* 11 011 100 */ { Scale::EIGHT, Index::EBX, Base::ESP },
/* 11 011 101 */ { Scale::EIGHT, Index::EBX, Base::EBP },
/* 11 011 110 */ { Scale::EIGHT, Index::EBX, Base::ESI },
/* 11 011 111 */ { Scale::EIGHT, Index::EBX, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 100 000 */ { Scale::EIGHT, Index::_,   Base::EAX },
/* 11 100 001 */ { Scale::EIGHT, Index::_,   Base::ECX },
/* 11 100 010 */ { Scale::EIGHT, Index::_,   Base::EDX },
/* 11 100 011 */ { Scale::EIGHT, Index::_,   Base::EBX },
/* 11 100 100 */ { Scale::EIGHT, Index::_,   Base::ESP },
/* 11 100 101 */ { Scale::EIGHT, Index::_,   Base::EBP },
/* 11 100 110 */ { Scale::EIGHT, Index::_,   Base::ESI },
/* 11 100 111 */ { Scale::EIGHT, Index::_,   Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 101 000 */ { Scale::EIGHT, Index::EBP, Base::EAX },
/* 11 101 001 */ { Scale::EIGHT, Index::EBP, Base::ECX },
/* 11 101 010 */ { Scale::EIGHT, Index::EBP, Base::EDX },
/* 11 101 011 */ { Scale::EIGHT, Index::EBP, Base::EBX },
/* 11 101 100 */ { Scale::EIGHT, Index::EBP, Base::ESP },
/* 11 101 101 */ { Scale::EIGHT, Index::EBP, Base::EBP },
/* 11 101 110 */ { Scale::EIGHT, Index::EBP, Base::ESI },
/* 11 101 111 */ { Scale::EIGHT, Index::EBP, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 110 000 */ { Scale::EIGHT, Index::ESI, Base::EAX },
/* 11 110 001 */ { Scale::EIGHT, Index::ESI, Base::ECX },
/* 11 110 010 */ { Scale::EIGHT, Index::ESI, Base::EDX },
/* 11 110 011 */ { Scale::EIGHT, Index::ESI, Base::EBX },
/* 11 110 100 */ { Scale::EIGHT, Index::ESI, Base::ESP },
/* 11 110 101 */ { Scale::EIGHT, Index::ESI, Base::EBP },
/* 11 110 110 */ { Scale::EIGHT, Index::ESI, Base::ESI },
/* 11 110 111 */ { Scale::EIGHT, Index::ESI, Base::EDI },
/*******************************************************/

/*******************************************************/
/* 11 111 000 */ { Scale::EIGHT, Index::EDI, Base::EAX },
/* 11 111 001 */ { Scale::EIGHT, Index::EDI, Base::ECX },
/* 11 111 010 */ { Scale::EIGHT, Index::EDI, Base::EDX },
/* 11 111 011 */ { Scale::EIGHT, Index::EDI, Base::EBX },
/* 11 111 100 */ { Scale::EIGHT, Index::EDI, Base::ESP },
/* 11 111 101 */ { Scale::EIGHT, Index::EDI, Base::EBP },
/* 11 111 110 */ { Scale::EIGHT, Index::EDI, Base::ESI },
/* 11 111 111 */ { Scale::EIGHT, Index::EDI, Base::EDI }
/*******************************************************/
};

#endif