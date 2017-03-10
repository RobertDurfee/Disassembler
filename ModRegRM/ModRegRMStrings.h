#ifndef MOD_REG_RM_STRINGS_HEADER
#define MOD_REG_RM_STRINGS_HEADER

#ifndef STRING_SIZE_OFFSETS
#define STRING_SIZE_OFFSETS

	#define EIGHT_BIT     0 +
	#define SIXTEEN_BIT   1 +
	#define THIRTYTWO_BIT 2 +

#endif

const char * RegString[24] =
{
/* 8-bit Registers */ /* 16-bit Registers */ /* 32-Bit Registers */

  /* 0x00 */ "AL",      /* 0x01 */ "AX",       /* 0x02 */ "EAX",
  /* 0x03 */ "CL",      /* 0x04 */ "CX",       /* 0x05 */ "ECX",
  /* 0x06 */ "DL",      /* 0x07 */ "DX",       /* 0x08 */ "EDX",
  /* 0x09 */ "BL",      /* 0x0A */ "BX",       /* 0x0B */ "EBX",
  /* 0x0C */ "AH",      /* 0x0D */ "SP",       /* 0x0E */ "ESP",
  /* 0x0F */ "CH",      /* 0x10 */ "BP",       /* 0x11 */ "EBP",
  /* 0x12 */ "DH",      /* 0x13 */ "SI",       /* 0x14 */ "ESI",
  /* 0x15 */ "BH",      /* 0x16 */ "DI",       /* 0x17 */ "EDI", 
};

const char * RMString[24] =
{
/* 8-bit Addressing */ /* 16-bit Addressing */ /* 32-bit Addressing */

  /* 0x00 */ "_",       /* 0x01 */ "BX + SI",  /* 0x02 */ "EAX",
  /* 0x03 */ "_",       /* 0x04 */ "BX + DI",  /* 0x05 */ "ECX",
  /* 0x06 */ "_",       /* 0x07 */ "BP + SI",  /* 0x08 */ "EDX",
  /* 0x09 */ "_",       /* 0x0A */ "BP + DI",  /* 0x0B */ "EBX",
  /* 0x0C */ "_",       /* 0x0D */ "SI",       /* 0x0E */ "ESP",
  /* 0x0F */ "_",       /* 0x10 */ "DI",       /* 0x11 */ "EBP",
  /* 0x12 */ "_",       /* 0x13 */ "BP",       /* 0x14 */ "ESI",
  /* 0x15 */ "_",       /* 0x16 */ "BX",       /* 0x17 */ "EDI"
};

#endif 