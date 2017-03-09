#ifndef MOD_REG_RM_STRINGS_HEADER
#define MOD_REG_RM_STRINGS_HEADER

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

const char * RMString[21] =
{
  /* 0x00 */ "_",       /* 0x01 */ "_" 

  /* 0x02 */ "EAX",     /* 0x03 */ "BX + SI",
  /* 0x04 */ "ECX",     /* 0x05 */ "BX + DI",
  /* 0x06 */ "EDX",     /* 0x07 */ "BP + SI",
  /* 0x08 */ "EBX",     /* 0x09 */ "BP + DI",
  /* 0x0A */ "ESP",     /* 0x0B */ "SI",
  /* 0x0C */ "EBP",     /* 0x0D */ "DI",
  /* 0x0E */ "ESI",     /* 0x0F */ "BP",
  /* 0x10 */ "EDI",     /* 0x11 */ "BX",

  /* 0x12 */ "_",       /* 0x13 */ "_",
  /* 0x14 */ "_",       /* 0x15 */ "_"
};

#endif 