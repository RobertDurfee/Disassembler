#ifndef INSTRUCTION_OPERAND_STRINGS_HEADER
#define INSTRUCTION_OPERAND_STRINGS_HEADER

#ifndef STRING_SIZE_OFFSETS
#define STRING_SIZE_OFFSETS

	#define EIGHT_BIT     0 +
	#define SIXTEEN_BIT   1 +
	#define THIRTYTWO_BIT 2 +

#endif

const char * RegisterString[24] = 
{ 
/* 8-bit Registers */ /* 16-bit Registers */ /* 32-bit Registers */

  /* 0x00 */ "AL",      /* 0x01 */ "AX",       /* 0x02 */ "EAX",
  /* 0x03 */ "CL",      /* 0x04 */ "CX",       /* 0x05 */ "ECX",
  /* 0x06 */ "DL",      /* 0x07 */ "DX",       /* 0x08 */ "EDX",
  /* 0x09 */ "BL",      /* 0x0A */ "BX",       /* 0x0B */ "EBX",
  /* 0x0C */ "AH",      /* 0x0D */ "SP",       /* 0x0E */ "ESP",
  /* 0x0F */ "CH",      /* 0x10 */ "BP",       /* 0x11 */ "EBP",
  /* 0x12 */ "DH",      /* 0x13 */ "SI",       /* 0x14 */ "ESI",
  /* 0x15 */ "BH",      /* 0x16 */ "DI",       /* 0x17 */ "EDI",
};

const char * SegmentRegisterString[24] =
{
/* Segment Registers */
	
  /* 0x00 */ "ES",      /* 0x01 */ "ES",       /* 0x02 */ "ES",
  /* 0x03 */ "CS",      /* 0x04 */ "CS",       /* 0x05 */ "CS",
  /* 0x06 */ "SS",      /* 0x07 */ "SS",       /* 0x08 */ "SS",
  /* 0x09 */ "DS",      /* 0x0A */ "DS",       /* 0x0B */ "DS",
  /* 0x0C */ "FS",      /* 0x0D */ "FS",       /* 0x0E */ "FS",
  /* 0x0F */ "GS",      /* 0x10 */ "GS",       /* 0x11 */ "GS",
  /* 0x12 */ "??",      /* 0x13 */ "??",       /* 0x14 */ "??",
  /* 0x15 */ "??",      /* 0x16 */ "??",       /* 0x17 */ "??"
};

const char * ConstantString[1] = 
{
/* 0x00 */ "1",  //The number one (Used only by the shift instruction group)
};

#endif