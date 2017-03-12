#ifndef SIB_STRINGS_HEADER
#define SIB_STRINGS_HEADER

const char * ScaleString[5] = 
{
/* 0x00 */ "_", //Placeholder

/* 0x01 */ "1", //Scale::ONE
/* 0x02 */ "2", //Scale::TWO
/* 0x03 */ "4", //Scale::FOUR
/* 0x04 */ "8"  //Scale::EIGHT
};

const char * IndexString[9] = 
{
/* 0x00 */ "_",   //Placeholder

/* 0x01 */ "EAX", //General EAX Register
/* 0x02 */ "ECX", //General ECX Register
/* 0x03 */ "EDX", //General EDX Register
/* 0x04 */ "EBX", //General EBX Register
/* 0x05 */ "ESP", //General ESP Register
/* 0x06 */ "EBP", //General EBP Register
/* 0x07 */ "ESI", //General ESI Register
/* 0x08 */ "EDI"  //General EDI Register
};

const char * BaseString[9] = 
{
/* 0x00 */ "_",   //Placeholder

/* 0x01 */ "EAX", //General EAX Register
/* 0x02 */ "ECX", //General ECX Register
/* 0x03 */ "EDX", //General EDX Register
/* 0x04 */ "EBX", //General EBX Register
/* 0x05 */ "ESP", //General ESP Register
/* 0x06 */ "EBP", //General EBP Register (if MOD = 01 or MOD = 10) or 32-bit Displacement (if MOD = 00)
/* 0x07 */ "ESI", //General ESI Register
/* 0x08 */ "EDI"  //General EDI Register
};

#endif