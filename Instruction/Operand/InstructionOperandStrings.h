#ifndef INSTRUCTION_OPERAND_STRINGS_HEADER
#define INSTRUCTION_OPERAND_STRINGS_HEADER

const char * RegisterString[33] = 
{ 
/* 8-bit Registers */ /* 16-bit Registers */ /* 32-bit Registers */
	
  /* 0x00 */ "_",       /* 0x01 */ "_",        /* 0x02 */ "_",
  /* 0x03 */ "_",       /* 0x04 */ "_",        /* 0x05 */ "_",

  /* 0x06 */ "AL",      /* 0x07 */ "AX",       /* 0x08 */ "EAX",
  /* 0x09 */ "CL",      /* 0x0A */ "CX",       /* 0x0B */ "ECX",
  /* 0x0C */ "DL",      /* 0x0D */ "DX",       /* 0x0E */ "EDX",
  /* 0x0F */ "BL",      /* 0x10 */ "BX",       /* 0x11 */ "EBX",
  /* 0x12 */ "AH",      /* 0x13 */ "SP",       /* 0x14 */ "ESP",
  /* 0x15 */ "CH",      /* 0x16 */ "BP",       /* 0x17 */ "EBP",
  /* 0x18 */ "DH",      /* 0x19 */ "SI",       /* 0x1A */ "ESI",
  /* 0x1B */ "BH",      /* 0x1C */ "DI",       /* 0x1D */ "EDI",

  /* 0x1E */ "_",       /* 0x1F */ "_",        /* 0x20 */ "_"
};

const char * SegmentRegisterString[9] =
{
/* Segment Registers */

/* 0x00 */ "_",  //Placeholder
/* 0x01 */ "_",  //Placeholder

/* 0x02 */ "ES", //E Segment Register
/* 0x03 */ "CS", //C Segment Register
/* 0x04 */ "SS", //S Segment Register
/* 0x05 */ "DS", //D Segment Register
/* 0x06 */ "FS", //F Segment Register
/* 0x07 */ "GS", //G Segment Register

/* 0x08 */ "_"  //Placeholder
};

const char * ConstantString[4] = 
{
/* 0x00 */ "_",  //Placeholder
/* 0x01 */ "_",  //Placeholder

/* 0x02 */ "1",  //The number one (Used only by the shift instruction group)

/* 0x03 */ "_"   //Placeholder
};

#endif