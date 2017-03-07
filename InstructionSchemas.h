#ifndef INSTRUCTION_SCHEMAS_HEADER
#define INSTRUCTION_SCHEMAS_HEADER

enum class Mnemonic// : Operator
{
/* 0x00000 */ _,      //No Operator

/* Arithmetic Instructions */
	
/* 0x00001 */ ADD,    //Add 
/* 0x00002 */ SUB,    //Subtract
/* 0x00003 */ MUL,    //Unsigned multiply
/* 0x00004 */ DIV,    //Unsigned divide
/* 0x00005 */ ADC,    //Add with carry
/* 0x00006 */ SBB,    //Integer subtraction with borrow
/* 0x00007 */ IMUL,   //Signed multiply
/* 0x00008 */ IDIV,   //Signed divide
/* 0x00009 */ INC,    //Increment by 1
/* 0x0000A */ DEC,    //Decrement by 1

/* Logical Instructions */

/* 0x0000B */ NOT,    //One's complement negation
/* 0x0000C */ NEG,    //Two's complement negation
/* 0x0000D */ AND,    //Logical AND
/* 0x0000E */ OR,     //Logical OR
/* 0x0000F */ XOR,    //Logical exclusive OR
	
/* Shift Instructions */

/* 0x00010 */ ROL,    //Rotate left
/* 0x00011 */ ROR,    //Rotate right
/* 0x00012 */ RCL,    //Rotate left with carry
/* 0x00013 */ RCR,    //Rotate right with carry
/* 0x00014 */ SHL,    //Shift logical left
/* 0x00015 */ SHR,    //Shift logical right
/* 0x00016 */ SAL,    //Shift arithmetic left
/* 0x00017 */ SAR,    //Shift arithmetic right

/* Push Instructions */

/* 0x00018 */ PUSH,   //Push word, doubleword, or quadword onto the stack
/* 0x00019 */ PUSHA,  //Push all general-purpose registers
/* 0x0001A */ PUSHAD, //Push all general-purpose registers
/* 0x0001B */ PUSHF,  //Push FLAGS register onto the stack
/* 0x0001C */ PUSHD,  //Push EFLAGS register onto the stack
/* 0x0001D */ PUSHQ,  //Push RFLAGS reigster onto the stack

/* Pop Instructions */

/* 0x0001E */ POP,    //Pop a value from the stack
/* 0x0001F */ POPA,   //Pop all general-purpose registers
/* 0x00020 */ POPAD,  //Pop all general-purpose registers
/* 0x00021 */ POPF,   //Pop stack into FLAGS register
/* 0x00022 */ POPD,   //Pop stack into EFLAGS register
/* 0x00023 */ POPQ,   //Pop stack into RFLAGS register
	
/* Move Instructions */

/* 0x00024 */ XCHG,   //Exchange register/memory with register
/* 0x00025 */ MOV,    //Move
/* 0x00026 */ MOVS,   //Move data from string to string
/* 0x00027 */ MOVSB,  //Move data from string to string
/* 0x00028 */ MOVSW,  //Move data from string to string
/* 0x00029 */ MOVSD,  //Move data from string to string
/* 0x0002A */ MOVSQ,  //Move data from string to string
		
/* Jump Instructions */

/* 0x0002B */ JMP,    //Jump
/* 0x0002C */ JA,     //Jump if above (CF = 0 and ZF = 0)
/* 0x0002D */ JAE,    //Jump if above or equal (CF = 0)
/* 0x0002E */ JB,     //Jump if below (CF = 1)
/* 0x0002F */ JBE,    //Jump if below or equal (CF = 1 or ZF = 1)
/* 0x00030 */ JC,     //Jump if carry (CF = 1)
/* 0x00031 */ JE,     //Jump if equal (ZF = 1)
/* 0x00032 */ JG,     //Jump if greater (ZF = 0 and SF = OF)
/* 0x00033 */ JGE,    //Jump if greater or equal (SF = OF)
/* 0x00034 */ JL,     //Jump if less (SF != OF)
/* 0x00035 */ JLE,    //Jump if less or equal (ZF = 1 or SF != OF)
/* 0x00036 */ JNA,    //Jump if not above (CF = 1 or ZF = 1)
/* 0x00037 */ JNAE,   //Jump if not above or equal (CF = 1)
/* 0x00038 */ JNB,    //Jump if not below (CF = 0)
/* 0x00039 */ JNBE,   //Jump if not below or equal (CF = 0 and ZF = 0)
/* 0x0003A */ JNC,    //Jump if if not carry (CF = 0)
/* 0x0003B */ JNE,    //Jump if not equal (ZF = 0)
/* 0x0003C */ JNG,    //Jump if not greater (ZF = 1 or SF != OF)
/* 0x0003D */ JNGE,   //Jump if not greater or equal (SF != OF)
/* 0x0003E */ JNL,    //Jump if not less (SF = OF)
/* 0x0003F */ JNLE,   //Jump if not less or equal (ZF = 0 and SF = OF)
/* 0x00040 */ JNO,    //Jump if not overflow (OF = 0)
/* 0x00041 */ JNP,    //Jump if not parity (PF = 0)
/* 0x00042 */ JNS,    //Jump if not sign (SF = 0)
/* 0x00043 */ JNZ,    //Jump if not zero (ZF = 0)
/* 0x00044 */ JO,     //Jump if overflow (OF = 1)
/* 0x00045 */ JP,     //Jump if parity (PF = 1)
/* 0x00046 */ JPE,    //Jump if parity even (PF = 1)
/* 0x00047 */ JPO,    //Jump if parity odd (PF = 0)
/* 0x00048 */ JS,     //Jump if sign (SF = 1)
/* 0x00049 */ JZ,     //Jump if zero (ZF = 1)
/* 0x0004A */ JCXZ,   //Jump if CX register is 0
/* 0x0004B */ JECXZ,  //Jump if ECX register is 0

/* Procedure Instructions */

/* 0x0004C */ CALL,   //Call procedure
/* 0x0004D */ RET,    //Return from procedure
/* 0x0004E */ ENTER,  //Make stack frame for procedure parameters
/* 0x0004F */ LEAVE,  //High level prodecure exit

/* Interrupt Instructions */

/* 0x00050 */ INT,    //Call to interrupt prodedure
/* 0x00051 */ INTO,   //Call to interrupt procedure
/* 0x00052 */ IRET,   //Interrupt return
/* 0x00053 */ IRETD,  //Interrupt return
/* 0x00054 */ IRETQ,  //Interrupt return

/* Input Instructions */
		
/* 0x00055 */ IN,     //Input from port
/* 0x00056 */ INS,    //Input from port to string
/* 0x00057 */ INSB,   //Input from port to string
/* 0x00058 */ INSW,   //Input from port to string
/* 0x00059 */ INSD,   //Input from port to string

/* Output Instructions */
		
/* 0x0005A */ OUT,    //Output to port
/* 0x0005B */ OUTS,   //Output string to port
/* 0x0005C */ OUTSB,  //Output string to port
/* 0x0005D */ OUTSW,  //Output string to port
/* 0x0005E */ OUTSD,  //Output string to port

/* Conversion Instructions */
		
/* 0x0005F */ CBW,    //Convert byte to word
/* 0x00060 */ CWDE,   //Convert word to doubleword
/* 0x00061 */ CDQE,   //Convert doubleword to quadword
/* 0x00062 */ CWD,    //Convert word to doubleword
/* 0x00063 */ CDQ,    //Convert doubleword to quadword
/* 0x00064 */ CQO,    //Convert quadword to double-quadword

/* Loop Instructions */
		
/* 0x00065 */ LOOPNE, //Decrement count, jump if count != 0 and ZF = 0
/* 0x00066 */ LOOPNZ, //Decrement count, jump if count != 0 and ZF = 0
/* 0x00067 */ LOOPE,  //Decrement count, jump if count != 0 and ZF = 1
/* 0x00068 */ LOOPZ,  //Decrement count, jump if count != 0 and ZF = 1
/* 0x00069 */ LOOP,   //Decrement count, jump if count != 0

/* ASCII Adjust Instructions */
		
/* 0x0006A */ AAM,    //ASCII adjust AX after multiply
/* 0x0006B */ AAD,    //ASCII adjust AX before division
/* 0x0006C */ AAA,    //ASCII adjust after addition
/* 0x0006D */ AAS,    //ASCII adjust AL after subtraction

/* Decimal Adjust Instructions */
		
/* 0x0006E */ DAA,    //Decimal adjust AL after addition
/* 0x0006F */ DAS,    //Decimal adjust AL after subtraction

/* Compare Instructions */
		
/* 0x00070 */ TEST,   //Logical compare
/* 0x00071 */ CMP,    //Compare two operands
/* 0x00072 */ CMPS,   //Compare string operands
/* 0x00073 */ CMPSB,  //Compare string operands
/* 0x00074 */ CMPSW,  //Compare string operands
/* 0x00075 */ CMPSD,  //Compare string operands

/* Flag Instructions */
		
/* 0x00076 */ CMC,    //Complement carry flag
/* 0x00077 */ CLC,    //Clear carry flag
/* 0x00078 */ STC,    //Set carry flag
/* 0x00079 */ CLI,    //Clear interrupt flag
/* 0x0007A */ STI,    //Set interrupt flag
/* 0x0007B */ CLD,    //Clear direction flag
/* 0x0007C */ STD,    //Set direction flag

/* Load String Instructions */
		
/* 0x0007D */ LODS,   //Load string
/* 0x0007E */ LODSB,  //Load string
/* 0x0007F */ LODSW,  //Load string
/* 0x00080 */ LODSD,  //Load string
/* 0x00081 */ LODSQ,  //Load string

/* Scan String Instructions */
		
/* 0x00082 */ SCAS,   //Scan string
/* 0x00083 */ SCASB,  //Scan string
/* 0x00084 */ SCASW,  //Scan string
/* 0x00085 */ SCASD,  //Scan string
/* 0x00086 */ SCASQ,  //Scan string

/* Store String Instructions */
		
/* 0x00087 */ STOS,   //Store string
/* 0x00088 */ STOSB,  //Store string
/* 0x00089 */ STOSW,  //Store string
/* 0x0008A */ STOSD,  //Store string
/* 0x0008B */ STOSQ,  //Store string

/* Obstruction Instructions */
		
/* 0x0008C */ HLT,    //Halt
/* 0x0008D */ WAIT,   //Wait
/* 0x0008E */ FWAIT,  //Wait
/* 0x0008F */ NOP,    //No operation
/* 0x00090 */ PAUSE,  //Spin loop hint
		
/* Pointer Instructions */

/* 0x00091 */ LES,    //Load far pointer
/* 0x00092 */ LDS,    //Load far pointer

/* Table Instructions */

/* 0x00093 */ XLAT,   //Table look-up translation
/* 0x00094 */ XLATB,  //Table look-up translation

/* FLAGS Instructions */
		
/* 0x00095 */ SAHF,   //Store AH register into FLAGS
/* 0x00096 */ LAHF,   //Load FLAGS into AH		

/* Effective Address Instruction*/

/* 0x00097 */ LEA,    //Load effective address

/* Array Instruction */
		
/* 0x00098 */ BOUND,  //Check array index against bounds

/* Segment Instruction */

/* 0x00099 */ ARPL,   //Adjust RPL field of segment selector

/* 0x0009A */ LAST    //Placeholder
};

const char * MnemonicString[154] =
{
/* 0x00 */ "_",      //No Operator

/* Arithmetic Instructions */
	
/* 0x01 */ "ADD",    //Add 
/* 0x02 */ "SUB",    //Subtract
/* 0x03 */ "MUL",    //Unsigned multiply
/* 0x04 */ "DIV",    //Unsigned divide
/* 0x05 */ "ADC",    //Add with carry
/* 0x06 */ "SBB",    //Integer subtraction with borrow
/* 0x07 */ "IMUL",   //Signed multiply
/* 0x08 */ "IDIV",   //Signed divide
/* 0x09 */ "INC",    //Increment by 1
/* 0x0A */ "DEC",    //Decrement by 1

/* Logical Instructions */

/* 0x0B */ "NOT",    //One's complement negation
/* 0x0C */ "NEG",    //Two's complement negation
/* 0x0D */ "AND",    //Logical AND
/* 0x0E */ "OR",     //Logical OR
/* 0x0F */ "XOR",    //Logical exclusive OR
	
/* Shift Instructions */

/* 0x10 */ "ROL",    //Rotate left
/* 0x11 */ "ROR",    //Rotate right
/* 0x12 */ "RCL",    //Rotate left with carry
/* 0x13 */ "RCR",    //Rotate right with carry
/* 0x14 */ "SHL",    //Shift logical left
/* 0x15 */ "SHR",    //Shift logical right
/* 0x16 */ "SAL",    //Shift arithmetic left
/* 0x17 */ "SAR",    //Shift arithmetic right

/* Push Instructions */

/* 0x18 */ "PUSH",   //Push word", doubleword", or quadword onto the stack
/* 0x19 */ "PUSHA",  //Push all general-purpose registers
/* 0x1A */ "PUSHAD", //Push all general-purpose registers
/* 0x1B */ "PUSHF",  //Push FLAGS register onto the stack
/* 0x1C */ "PUSHD",  //Push EFLAGS register onto the stack
/* 0x1D */ "PUSHQ",  //Push RFLAGS reigster onto the stack

/* Pop Instructions */

/* 0x1E */ "POP",    //Pop a value from the stack
/* 0x1F */ "POPA",   //Pop all general-purpose registers
/* 0x20 */ "POPAD",  //Pop all general-purpose registers
/* 0x21 */ "POPF",   //Pop stack into FLAGS register
/* 0x22 */ "POPD",   //Pop stack into EFLAGS register
/* 0x23 */ "POPQ",   //Pop stack into RFLAGS register
	
/* Move Instructions */

/* 0x24 */ "XCHG",   //Exchange register/memory with register
/* 0x25 */ "MOV",    //Move
/* 0x26 */ "MOVS",   //Move data from string to string
/* 0x27 */ "MOVSB",  //Move data from string to string
/* 0x28 */ "MOVSW",  //Move data from string to string
/* 0x29 */ "MOVSD",  //Move data from string to string
/* 0x2A */ "MOVSQ",  //Move data from string to string
		
/* Jump Instructions */

/* 0x2B */ "JMP",    //Jump
/* 0x2C */ "JA",     //Jump if above (CF = 0 and ZF = 0)
/* 0x2D */ "JAE",    //Jump if above or equal (CF = 0)
/* 0x2E */ "JB",     //Jump if below (CF = 1)
/* 0x2F */ "JBE",    //Jump if below or equal (CF = 1 or ZF = 1)
/* 0x30 */ "JC",     //Jump if carry (CF = 1)
/* 0x31 */ "JE",     //Jump if equal (ZF = 1)
/* 0x32 */ "JG",     //Jump if greater (ZF = 0 and SF = OF)
/* 0x33 */ "JGE",    //Jump if greater or equal (SF = OF)
/* 0x34 */ "JL",     //Jump if less (SF != OF)
/* 0x35 */ "JLE",    //Jump if less or equal (ZF = 1 or SF != OF)
/* 0x36 */ "JNA",    //Jump if not above (CF = 1 or ZF = 1)
/* 0x37 */ "JNAE",   //Jump if not above or equal (CF = 1)
/* 0x38 */ "JNB",    //Jump if not below (CF = 0)
/* 0x39 */ "JNBE",   //Jump if not below or equal (CF = 0 and ZF = 0)
/* 0x3A */ "JNC",    //Jump if if not carry (CF = 0)
/* 0x3B */ "JNE",    //Jump if not equal (ZF = 0)
/* 0x3C */ "JNG",    //Jump if not greater (ZF = 1 or SF != OF)
/* 0x3D */ "JNGE",   //Jump if not greater or equal (SF != OF)
/* 0x3E */ "JNL",    //Jump if not less (SF = OF)
/* 0x3F */ "JNLE",   //Jump if not less or equal (ZF = 0 and SF = OF)
/* 0x40 */ "JNO",    //Jump if not overflow (OF = 0)
/* 0x41 */ "JNP",    //Jump if not parity (PF = 0)
/* 0x42 */ "JNS",    //Jump if not sign (SF = 0)
/* 0x43 */ "JNZ",    //Jump if not zero (ZF = 0)
/* 0x44 */ "JO",     //Jump if overflow (OF = 1)
/* 0x45 */ "JP",     //Jump if parity (PF = 1)
/* 0x46 */ "JPE",    //Jump if parity even (PF = 1)
/* 0x47 */ "JPO",    //Jump if parity odd (PF = 0)
/* 0x48 */ "JS",     //Jump if sign (SF = 1)
/* 0x49 */ "JZ",     //Jump if zero (ZF = 1)
/* 0x4A */ "JCXZ",   //Jump if CX register is 0
/* 0x4B */ "JECXZ",  //Jump if ECX register is 0

/* Procedure Instructions */

/* 0x4C */ "CALL",   //Call procedure
/* 0x4D */ "RET",    //Return from procedure
/* 0x4E */ "ENTER",  //Make stack frame for procedure parameters
/* 0x4F */ "LEAVE",  //High level prodecure exit

/* Interrupt Instructions */

/* 0x50 */ "INT",    //Call to interrupt prodedure
/* 0x51 */ "INTO",   //Call to interrupt procedure
/* 0x52 */ "IRET",   //Interrupt return
/* 0x53 */ "IRETD",  //Interrupt return
/* 0x54 */ "IRETQ",  //Interrupt return

/* Input Instructions */
		
/* 0x55 */ "IN",     //Input from port
/* 0x56 */ "INS",    //Input from port to string
/* 0x57 */ "INSB",   //Input from port to string
/* 0x58 */ "INSW",   //Input from port to string
/* 0x59 */ "INSD",   //Input from port to string

/* Output Instructions */
		
/* 0x5A */ "OUT",    //Output to port
/* 0x5B */ "OUTS",   //Output string to port
/* 0x5C */ "OUTSB",  //Output string to port
/* 0x5D */ "OUTSW",  //Output string to port
/* 0x5E */ "OUTSD",  //Output string to port

/* Conversion Instructions */
		
/* 0x5F */ "CBW",    //Convert byte to word
/* 0x60 */ "CWDE",   //Convert word to doubleword
/* 0x61 */ "CDQE",   //Convert doubleword to quadword
/* 0x62 */ "CWD",    //Convert word to doubleword
/* 0x63 */ "CDQ",    //Convert doubleword to quadword
/* 0x64 */ "CQO",    //Convert quadword to double-quadword

/* Loop Instructions */
		
/* 0x65 */ "LOOPNE", //Decrement count", jump if count != 0 and ZF = 0
/* 0x66 */ "LOOPNZ", //Decrement count", jump if count != 0 and ZF = 0
/* 0x67 */ "LOOPE",  //Decrement count", jump if count != 0 and ZF = 1
/* 0x68 */ "LOOPZ",  //Decrement count", jump if count != 0 and ZF = 1
/* 0x69 */ "LOOP",   //Decrement count", jump if count != 0

/* ASCII Adjust Instructions */
		
/* 0x6A */ "AAM",    //ASCII adjust AX after multiply
/* 0x6B */ "AAD",    //ASCII adjust AX before division
/* 0x6C */ "AAA",    //ASCII adjust after addition
/* 0x6D */ "AAS",    //ASCII adjust AL after subtraction

/* Decimal Adjust Instructions */
		
/* 0x6E */ "DAA",    //Decimal adjust AL after addition
/* 0x6F */ "DAS",    //Decimal adjust AL after subtraction

/* Compare Instructions */
		
/* 0x70 */ "TEST",   //Logical compare
/* 0x71 */ "CMP",    //Compare two operands
/* 0x72 */ "CMPS",   //Compare string operands
/* 0x73 */ "CMPSB",  //Compare string operands
/* 0x74 */ "CMPSW",  //Compare string operands
/* 0x75 */ "CMPSD",  //Compare string operands

/* Flag Instructions */
		
/* 0x76 */ "CMC",    //Complement carry flag
/* 0x77 */ "CLC",    //Clear carry flag
/* 0x78 */ "STC",    //Set carry flag
/* 0x79 */ "CLI",    //Clear interrupt flag
/* 0x7A */ "STI",    //Set interrupt flag
/* 0x7B */ "CLD",    //Clear direction flag
/* 0x7C */ "STD",    //Set direction flag

/* Load String Instructions */
		
/* 0x7D */ "LODS",   //Load string
/* 0x7E */ "LODSB",  //Load string
/* 0x7F */ "LODSW",  //Load string
/* 0x80 */ "LODSD",  //Load string
/* 0x81 */ "LODSQ",  //Load string

/* Scan String Instructions */
		
/* 0x82 */ "SCAS",   //Scan string
/* 0x83 */ "SCASB",  //Scan string
/* 0x84 */ "SCASW",  //Scan string
/* 0x85 */ "SCASD",  //Scan string
/* 0x86 */ "SCASQ",  //Scan string

/* Store String Instructions */
		
/* 0x87 */ "STOS",   //Store string
/* 0x88 */ "STOSB",  //Store string
/* 0x89 */ "STOSW",  //Store string
/* 0x8A */ "STOSD",  //Store string
/* 0x8B */ "STOSQ",  //Store string

/* Obstruction Instructions */
		
/* 0x8C */ "HLT",    //Halt
/* 0x8D */ "WAIT",   //Wait
/* 0x8E */ "FWAIT",  //Wait
/* 0x8F */ "NOP",    //No operation
/* 0x90 */ "PAUSE",  //Spin loop hint
		
/* Pointer Instructions */

/* 0x91 */ "LES",    //Load far pointer
/* 0x92 */ "LDS",    //Load far pointer

/* Table Instructions */

/* 0x93 */ "XLAT",   //Table look-up translation
/* 0x94 */ "XLATB",  //Table look-up translation

/* FLAGS Instructions */
		
/* 0x95 */ "SAHF",   //Store AH register into FLAGS
/* 0x96 */ "LAHF",   //Load FLAGS into AH		

/* Effective Address Instruction*/

/* 0x97 */ "LEA",    //Load effective address

/* Array Instruction */
		
/* 0x98 */ "BOUND",  //Check array index against bounds

/* Segment Instruction */

/* 0x99 */ "ARPL",   //Adjust RPL field of segment selector
};

enum class Group// : Operator 
{ 
/* 0x00000 */ _,             //No Operator

/* 0x0009A */ Immediate = (Group)Mnemonic::LAST,  //Arithmetic Operations
/* 0x0009B */ Shift,         //Shift/Rotate Operations
/* 0x0009C */ Unary,         //Multiplication, Division, Test, Negate Operations
/* 0x0009D */ Four,          //Increment, Decrement
/* 0x0009E */ Five,          //Increment, Decrement, Call, Jump, Push Operations
/* 0x0009F */ TwoByte,       //Two Byte Operations

/* 0x000A0 */ LAST           //Placeholder
};

enum class Prefix// : Operator 
{ 
/* 0x00000 */ _,                 //No Operator

/* 0x00100 */ ES = 0x00100,      //E Segment Register Prefix
/* 0x00200 */ CS = 0x00200,      //C Segment Register Prefix
/* 0x00400 */ SS = 0x00400,      //S Segment Register Prefix
/* 0x00800 */ DS = 0x00800,      //D Segment Register Prefix
/* 0x01000 */ FS = 0x01000,      //F Segment Register Prefix
/* 0x02000 */ GS = 0x02000,      //G Segment Register Prefix

/* 0x04000 */ OPERAND = 0x04000, //Operand Size Prefix
/* 0x08000 */ ADDRESS = 0x08000, //Address Size Prefix

/* 0x10000 */ LOCK = 0x10000,    //Lock Prefix

/* 0x20000 */ REPNE = 0x20000,   //Repeat Not Equal Prefix
/* 0x40000 */ REPE  = 0x40000,   //Repeat Equal Prefix

/* 0x40001 */ LAST               //Placeholder
};

enum class AddressingMethod// : Operand 
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

enum class Register// : Operand 
{ 
/* 0x00 */ _,    //No Operand

/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x0E */ A = (Register)AddressingMethod::LAST, //General A Register
/* 0x0F */ C,    //General C Register
/* 0x10 */ D,    //General D Register
/* 0x11 */ B,    //General B Register
/* 0x12 */ SP,   //General SP Register
/* 0x13 */ BP,   //General BP Register
/* 0x14 */ SI,   //General SI Register
/* 0x15 */ DI,   //General DI Register

/* 0x16 */ LAST  //Placeholder
};

const char * RegisterString[38] = 
{ 
/* General 8-bit Registers */ 

/* 0x00 */ "AL", 
/* 0x01 */ "CL",
/* 0x02 */ "DL",
/* 0x03 */ "BL",
/* 0x04 */ "AH",
/* 0x05 */ "CH",
/* 0x06 */ "DH",
/* 0x07 */ "BH",

/* General 16-bit Registers */

/* 0x08 */ "AX", 
/* 0x09 */ "CX",
/* 0x0A */ "DX",
/* 0x0B */ "BX",
/* 0x0C */ "SP",
/* 0x0D */ "BP",
/* 0x0E */ "SI",
/* 0x0F */ "DI",
	
/* General 32-Bit Registers */

/* 0x10 */ "EAX", 
/* 0x11 */ "ECX",
/* 0x12 */ "EDX",
/* 0x13 */ "EBX",
/* 0x14 */ "ESP",
/* 0x15 */ "EBP",
/* 0x16 */ "ESI",
/* 0x17 */ "EDI",

/* Special ModRM Register Combos */ 

/* 0x18 */ "BX + SI", 
/* 0x19 */ "BX + DI", 
/* 0x1A */ "BP + SI",
/* 0x1B */ "BP + DI",
/* 0x1C */ "SI",
/* 0x1D */ "DI",
/* 0x1E */ "BP",
/* 0x1F */ "BX"
};

enum class SegmentRegister// : Operand
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

const char * SegmentRegisterString[6] =
{
/* Segment Registers */

/* 0x00 */ "ES", //E Segment Register
/* 0x01 */ "CS", //C Segment Register
/* 0x02 */ "SS", //S Segment Register
/* 0x03 */ "DS", //D Segment Register
/* 0x04 */ "FS", //F Segment Register
/* 0x05 */ "GS"  //G Segment Register
};

enum class Constant// : Operand 
{ 
/* 0x00 */ _,      //No Operand

/* 0x01 */ $,      //Operand Specified in Another Table

/* 0x1C */ ONE = (Constant)SegmentRegister::LAST, //The number one (Used only by the shift instruction group)

/* 0x1D */ LAST    //Placeholder
};

const char * ConstantString[1] = 
{
/* 0x00 */ "1" //The number one (Used only by the shift instruction group)
};

enum class OperandType
{ 
/* 0x00 */ _,   //No Operand Type

/* 0x01 */ $,   //Operand Type Specified in Another Table

/* 0x02 */ a,   //Two one-word or two double-word operands in memory, depending on operand-size
/* 0x03 */ b,   //Byte, regardless of operand-size
/* 0x04 */ p,   //32-bit pointer
/* 0x05 */ v,   //Word or doubleword, depending on operand-size
/* 0x06 */ w,   //Word, regardless on operand-size
/* 0x07 */ x,   //Double-quadword or quad-quadword, depending on operand-size
/* 0x08 */ z,   //Word of doubleword, depending on operand-size

/* 0x09 */ LAST //Placeholder
};

#define NUMBER_OF_OPERANDS 3

union Operator
{
	Operator() : mnemonic(Mnemonic::_) , prefix(Prefix::_) , group(Group::_) {};
	Operator(Mnemonic mnemonic) : mnemonic(mnemonic) {};
	Operator(Prefix prefix) : prefix(prefix) {};
	Operator(Group group) : group(group) {};

	Mnemonic mnemonic;
	Prefix prefix;
	Group group;
};

union Operand
{
	Operand() : addressingMethod(AddressingMethod::_) , operandType(OperandType::_) , register_(Register::_) , segmentRegister(SegmentRegister::_) , constant(Constant::_) {};
	Operand(AddressingMethod addressingMethod, OperandType operandType) : addressingMethod(addressingMethod), operandType(operandType) {};
	Operand(Register register_, OperandType operandType) : register_(register_) , operandType(operandType) {};
	Operand(SegmentRegister segmentRegister, OperandType operandType) : segmentRegister(segmentRegister), operandType(operandType) {};
	Operand(Constant constant, OperandType operandType) : constant(constant) , operandType(operandType) {};

	struct
	{
		AddressingMethod addressingMethod;
		OperandType operandType;
	};
	Register register_;
	SegmentRegister segmentRegister;
	Constant constant;
};

struct InstructionSchema
{
	Operator operator_;

	Operand operands[NUMBER_OF_OPERANDS];
};

const InstructionSchema operator|(const InstructionSchema& left, const InstructionSchema& right)
{
	InstructionSchema output;

	output.operator_.mnemonic = right.operator_.mnemonic;

	for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
	{
		if (left.operands[i].addressingMethod == AddressingMethod::$)
			output.operands[i].addressingMethod = right.operands[i].addressingMethod;
		else
			output.operands[i].addressingMethod = left.operands[i].addressingMethod;

		if (left.operands[i].operandType == OperandType::$)
			output.operands[i].operandType = right.operands[i].operandType;
		else
			output.operands[i].operandType = left.operands[i].operandType;
	}

	return output;
}

const InstructionSchema InstructionSchemas[0x100 /*0000 0000 - 1111 1111*/] =
{
	/*************************************************************************************************************************************************************/
	/* 0x00 */ { Mnemonic::ADD,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x01 */ { Mnemonic::ADD,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x02 */ { Mnemonic::ADD,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x03 */ { Mnemonic::ADD,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x04 */ { Mnemonic::ADD,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x05 */ { Mnemonic::ADD,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x06 */ { Mnemonic::PUSH,   { { SegmentRegister::ES, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x07 */ { Mnemonic::POP,    { { SegmentRegister::ES, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x08 */ { Mnemonic::OR,     { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x09 */ { Mnemonic::OR,     { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x0A */ { Mnemonic::OR,     { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x0B */ { Mnemonic::OR,     { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x0C */ { Mnemonic::OR,     { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x0D */ { Mnemonic::OR,     { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x0E */ { Mnemonic::PUSH,   { { SegmentRegister::CS, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x0F */ { Group::TwoByte,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x10 */ { Mnemonic::ADC,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x11 */ { Mnemonic::ADC,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x12 */ { Mnemonic::ADC,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x13 */ { Mnemonic::ADC,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x14 */ { Mnemonic::ADC,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x15 */ { Mnemonic::ADC,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x16 */ { Mnemonic::PUSH,   { { SegmentRegister::SS, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x17 */ { Mnemonic::POP,    { { SegmentRegister::SS, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x18 */ { Mnemonic::SBB,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x19 */ { Mnemonic::SBB,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x1A */ { Mnemonic::SBB,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x1B */ { Mnemonic::SBB,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x1C */ { Mnemonic::SBB,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x1D */ { Mnemonic::SBB,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x1E */ { Mnemonic::PUSH,   { { SegmentRegister::DS, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x1F */ { Mnemonic::POP,    { { SegmentRegister::DS, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x20 */ { Mnemonic::AND,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x21 */ { Mnemonic::AND,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x22 */ { Mnemonic::AND,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x23 */ { Mnemonic::AND,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x24 */ { Mnemonic::AND,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x25 */ { Mnemonic::AND,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x26 */ { Prefix::ES,       { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x27 */ { Mnemonic::DAA,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x28 */ { Mnemonic::SUB,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x29 */ { Mnemonic::SUB,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x2A */ { Mnemonic::SUB,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x2B */ { Mnemonic::SUB,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x2C */ { Mnemonic::SUB,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x2D */ { Mnemonic::SUB,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x2E */ { Prefix::CS,       { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x2F */ { Mnemonic::DAS,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x30 */ { Mnemonic::XOR,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x31 */ { Mnemonic::XOR,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x32 */ { Mnemonic::XOR,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x33 */ { Mnemonic::XOR,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x34 */ { Mnemonic::XOR,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x35 */ { Mnemonic::XOR,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x36 */ { Prefix::SS,       { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x37 */ { Mnemonic::AAA,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x38 */ { Mnemonic::CMP,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x39 */ { Mnemonic::CMP,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x3A */ { Mnemonic::CMP,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x3B */ { Mnemonic::CMP,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x3C */ { Mnemonic::CMP,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x3E */ { Mnemonic::CMP,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x3D */ { Prefix::DS,       { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x3F */ { Mnemonic::AAS,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x40 */ { Mnemonic::INC,    { { Register::A,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x41 */ { Mnemonic::INC,    { { Register::C,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x42 */ { Mnemonic::INC,    { { Register::D,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x43 */ { Mnemonic::INC,    { { Register::B,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x44 */ { Mnemonic::INC,    { { Register::SP,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x45 */ { Mnemonic::INC,    { { Register::BP,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x46 */ { Mnemonic::INC,    { { Register::SI,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x47 */ { Mnemonic::INC,    { { Register::DI,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x48 */ { Mnemonic::DEC,    { { Register::A,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x49 */ { Mnemonic::DEC,    { { Register::C,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x4A */ { Mnemonic::DEC,    { { Register::D,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x4B */ { Mnemonic::DEC,    { { Register::B,         OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x4C */ { Mnemonic::DEC,    { { Register::SP,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x4D */ { Mnemonic::DEC,    { { Register::BP,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x4E */ { Mnemonic::DEC,    { { Register::SI,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x4F */ { Mnemonic::DEC,    { { Register::DI,        OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x50 */ { Mnemonic::PUSH,   { { Register::A,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x51 */ { Mnemonic::PUSH,   { { Register::C,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x52 */ { Mnemonic::PUSH,   { { Register::D,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x53 */ { Mnemonic::PUSH,   { { Register::B,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x54 */ { Mnemonic::PUSH,   { { Register::SP,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x55 */ { Mnemonic::PUSH,   { { Register::BP,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x56 */ { Mnemonic::PUSH,   { { Register::SI,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x57 */ { Mnemonic::PUSH,   { { Register::DI,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x58 */ { Mnemonic::POP,    { { Register::A,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x59 */ { Mnemonic::POP,    { { Register::C,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x5A */ { Mnemonic::POP,    { { Register::D,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x5B */ { Mnemonic::POP,    { { Register::B,         OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x5C */ { Mnemonic::POP,    { { Register::SP,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x5D */ { Mnemonic::POP,    { { Register::BP,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x5E */ { Mnemonic::POP,    { { Register::SI,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x5F */ { Mnemonic::POP,    { { Register::DI,        OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x60 */ { Mnemonic::PUSHA,  { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x61 */ { Mnemonic::POPA,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x62 */ { Mnemonic::BOUND,  { { AddressingMethod::G, OperandType::v }, { AddressingMethod::M, OperandType::a }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x63 */ { Mnemonic::ARPL,   { { AddressingMethod::E, OperandType::w }, { AddressingMethod::G, OperandType::w }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x64 */ { Prefix::FS,       { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x65 */ { Prefix::GS,       { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x66 */ { Prefix::OPERAND,  { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x67 */ { Prefix::ADDRESS,  { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x68 */ { Mnemonic::PUSH,   { { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x69 */ { Mnemonic::IMUL,   { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::I, OperandType::z } } },
	/* 0x6A */ { Mnemonic::PUSH,   { { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x6B */ { Mnemonic::IMUL,   { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::I, OperandType::b } } },
	/* 0x6C */ { Mnemonic::INS,    { { AddressingMethod::Y, OperandType::b }, { AddressingMethod::D, OperandType::x }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x6D */ { Mnemonic::INS,    { { AddressingMethod::Y, OperandType::z }, { AddressingMethod::D, OperandType::x }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x6E */ { Mnemonic::OUTS,   { { AddressingMethod::D, OperandType::x }, { AddressingMethod::X, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x6F */ { Mnemonic::OUTS,   { { AddressingMethod::D, OperandType::x }, { AddressingMethod::X, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x70 */ { Mnemonic::JO,     { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x71 */ { Mnemonic::JNO,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x72 */ { Mnemonic::JB,     { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x73 */ { Mnemonic::JNB,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x74 */ { Mnemonic::JZ,     { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x75 */ { Mnemonic::JNZ,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x76 */ { Mnemonic::JBE,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x77 */ { Mnemonic::JNBE,   { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x78 */ { Mnemonic::JS,     { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x79 */ { Mnemonic::JNS,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x7A */ { Mnemonic::JP,     { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x7B */ { Mnemonic::JNP,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x7C */ { Mnemonic::JL,     { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x7D */ { Mnemonic::JNL,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x7E */ { Mnemonic::JLE,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x7F */ { Mnemonic::JNLE,   { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x80 */ { Group::Immediate, { { AddressingMethod::E, OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x81 */ { Group::Immediate, { { AddressingMethod::E, OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x82 */ { Group::Immediate, { { AddressingMethod::E, OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x83 */ { Group::Immediate, { { AddressingMethod::E, OperandType::v }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x84 */ { Mnemonic::TEST,   { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x85 */ { Mnemonic::TEST,   { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x86 */ { Mnemonic::XCHG,   { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x87 */ { Mnemonic::XCHG,   { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x88 */ { Mnemonic::MOV,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::G, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x89 */ { Mnemonic::MOV,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::G, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x8A */ { Mnemonic::MOV,    { { AddressingMethod::G, OperandType::b }, { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x8B */ { Mnemonic::MOV,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x8C */ { Mnemonic::MOV,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::S, OperandType::w }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x8D */ { Mnemonic::LEA,    { { AddressingMethod::G, OperandType::v }, { AddressingMethod::M, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x8E */ { Mnemonic::MOV,    { { AddressingMethod::S, OperandType::w }, { AddressingMethod::E, OperandType::w }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x8F */ { Mnemonic::POP,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0x90 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::A,         OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x91 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::C,         OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x92 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::D,         OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x93 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::B,         OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x94 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::SP,        OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x95 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::BP,        OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x96 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::SI,        OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x97 */ { Mnemonic::XCHG,   { { Register::A,         OperandType::v }, { Register::DI,        OperandType::v }, { AddressingMethod::_, OperandType::_ } } },

	/* 0x98 */ { Mnemonic::CBW,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x99 */ { Mnemonic::CWD,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x9A */ { Mnemonic::CALL,   { { AddressingMethod::A, OperandType::p }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x9B */ { Mnemonic::WAIT,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x9C */ { Mnemonic::PUSHF,  { { AddressingMethod::F, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x9D */ { Mnemonic::POPF,   { { AddressingMethod::F, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x9E */ { Mnemonic::SAHF,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0x9F */ { Mnemonic::LAHF,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0xA0 */ { Mnemonic::MOV,    { { Register::A,         OperandType::b }, { AddressingMethod::O, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA1 */ { Mnemonic::MOV,    { { Register::A,         OperandType::v }, { AddressingMethod::O, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA2 */ { Mnemonic::MOV,    { { AddressingMethod::O, OperandType::b }, { Register::A,         OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA3 */ { Mnemonic::MOV,    { { AddressingMethod::O, OperandType::v }, { Register::A,         OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA4 */ { Mnemonic::MOVS,   { { AddressingMethod::Y, OperandType::b }, { AddressingMethod::X, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA5 */ { Mnemonic::MOVS,   { { AddressingMethod::Y, OperandType::v }, { AddressingMethod::X, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA6 */ { Mnemonic::CMPS,   { { AddressingMethod::X, OperandType::b }, { AddressingMethod::Y, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA7 */ { Mnemonic::CMPS,   { { AddressingMethod::X, OperandType::v }, { AddressingMethod::Y, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },

	/* 0xA8 */ { Mnemonic::TEST,   { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xA9 */ { Mnemonic::TEST,   { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xAA */ { Mnemonic::STOS,   { { AddressingMethod::Y, OperandType::b }, { Register::A,         OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xAB */ { Mnemonic::STOS,   { { AddressingMethod::Y, OperandType::v }, { Register::A,         OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xAC */ { Mnemonic::LODS,   { { Register::A,         OperandType::b }, { AddressingMethod::X, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xAD */ { Mnemonic::LODS,   { { Register::A,         OperandType::v }, { AddressingMethod::X, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xAE */ { Mnemonic::SCAS,   { { Register::A,         OperandType::b }, { AddressingMethod::Y, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xAF */ { Mnemonic::SCAS,   { { Register::A,         OperandType::v }, { AddressingMethod::Y, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0xB0 */ { Mnemonic::MOV,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB1 */ { Mnemonic::MOV,    { { Register::C,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB2 */ { Mnemonic::MOV,    { { Register::D,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB3 */ { Mnemonic::MOV,    { { Register::B,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB4 */ { Mnemonic::MOV,    { { Register::SP,        OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB5 */ { Mnemonic::MOV,    { { Register::BP,        OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB6 */ { Mnemonic::MOV,    { { Register::SI,        OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB7 */ { Mnemonic::MOV,    { { Register::DI,        OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },

	/* 0xB8 */ { Mnemonic::MOV,    { { Register::A,         OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xB9 */ { Mnemonic::MOV,    { { Register::C,         OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xBA */ { Mnemonic::MOV,    { { Register::D,         OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xBB */ { Mnemonic::MOV,    { { Register::B,         OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xBC */ { Mnemonic::MOV,    { { Register::SP,        OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xBD */ { Mnemonic::MOV,    { { Register::BP,        OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xBE */ { Mnemonic::MOV,    { { Register::SI,        OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xBF */ { Mnemonic::MOV,    { { Register::DI,        OperandType::v }, { AddressingMethod::I, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0xC0 */ { Group::Shift,     { { AddressingMethod::E, OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC1 */ { Group::Shift,     { { AddressingMethod::E, OperandType::v }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC2 */ { Mnemonic::RET,    { { AddressingMethod::I, OperandType::w }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC3 */ { Mnemonic::RET,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC4 */ { Mnemonic::LES,    { { AddressingMethod::G, OperandType::z }, { AddressingMethod::M, OperandType::p }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC5 */ { Mnemonic::LDS,    { { AddressingMethod::G, OperandType::z }, { AddressingMethod::M, OperandType::p }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC6 */ { Mnemonic::MOV,    { { AddressingMethod::E, OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC7 */ { Mnemonic::MOV,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::I, OperandType::z }, { AddressingMethod::_, OperandType::_ } } },

	/* 0xC8 */ { Mnemonic::ENTER,  { { AddressingMethod::I, OperandType::w }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xC9 */ { Mnemonic::LEAVE,  { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xCA */ { Mnemonic::RET,    { { AddressingMethod::I, OperandType::w }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xCB */ { Mnemonic::RET,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xCC */ { Mnemonic::INT,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xCD */ { Mnemonic::INT,    { { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xCE */ { Mnemonic::INTO,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xCF */ { Mnemonic::IRET,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0xD0 */ { Group::Shift,     { { AddressingMethod::E, OperandType::b }, { Constant::ONE,       OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD1 */ { Group::Shift,     { { AddressingMethod::E, OperandType::v }, { Constant::ONE,       OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD2 */ { Group::Shift,     { { AddressingMethod::E, OperandType::b }, { Register::C,         OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD3 */ { Group::Shift,     { { AddressingMethod::E, OperandType::v }, { Register::C,         OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD4 */ { Mnemonic::AAM,    { { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD5 */ { Mnemonic::AAD,    { { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD6 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD7 */ { Mnemonic::XLAT,   { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },

	/* 0xD8 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xD9 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xDA */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xDB */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xDC */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xDD */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xDE */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xDF */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0xE0 */ { Mnemonic::LOOPNE, { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE1 */ { Mnemonic::LOOPE,  { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE2 */ { Mnemonic::LOOP,   { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE3 */ { Mnemonic::JECXZ,  { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE4 */ { Mnemonic::IN,     { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE5 */ { Mnemonic::IN,     { { Register::A,         OperandType::z }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE6 */ { Mnemonic::OUT,    { { Register::A,         OperandType::b }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE7 */ { Mnemonic::OUT,    { { Register::A,         OperandType::z }, { AddressingMethod::I, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },

	/* 0xE8 */ { Mnemonic::CALL,   { { AddressingMethod::J, OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xE9 */ { Mnemonic::JMP,    { { AddressingMethod::J, OperandType::z }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xEA */ { Mnemonic::JMP,    { { AddressingMethod::A, OperandType::p }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xEB */ { Mnemonic::JMP,    { { AddressingMethod::J, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xEC */ { Mnemonic::IN,     { { Register::A,         OperandType::b }, { Register::D,         OperandType::w }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xED */ { Mnemonic::IN,     { { Register::A,         OperandType::z }, { Register::D,         OperandType::w }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xEE */ { Mnemonic::OUT,    { { Register::D,         OperandType::w }, { Register::A,         OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xEF */ { Mnemonic::OUT,    { { Register::D,         OperandType::w }, { Register::A,         OperandType::z }, { AddressingMethod::_, OperandType::_ } } },
	/*************************************************************************************************************************************************************/

	/*************************************************************************************************************************************************************/
	/* 0xF0 */ { Prefix::LOCK,     { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF1 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF2 */ { Prefix::REPNE,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF3 */ { Prefix::REPE,     { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF4 */ { Mnemonic::HLT,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF5 */ { Mnemonic::CMC,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF6 */ { Group::Unary,     { { AddressingMethod::E, OperandType::b }, { AddressingMethod::$, OperandType::b }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF7 */ { Group::Unary,     { { AddressingMethod::E, OperandType::v }, { AddressingMethod::$, OperandType::v }, { AddressingMethod::_, OperandType::_ } } },

	/* 0xF8 */ { Mnemonic::CLC,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xF9 */ { Mnemonic::STC,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xFA */ { Mnemonic::CLI,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xFB */ { Mnemonic::STI,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xFC */ { Mnemonic::CLD,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xFD */ { Mnemonic::STD,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xFE */ { Group::Four,      { { AddressingMethod::E, OperandType::b }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 0xFF */ { Group::Five,      { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } }
	/*************************************************************************************************************************************************************/
};

const InstructionSchema GroupSchemas[5][0x8 /* 000 - 111 */] =
{
	{/*Immediate Group*******************************************************************************************************************************************/
	/* 000 */ { Mnemonic::ADD,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { Mnemonic::OR,     { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { Mnemonic::ADC,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { Mnemonic::SBB,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { Mnemonic::AND,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { Mnemonic::SUB,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { Mnemonic::XOR,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { Mnemonic::CMP,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } }
	},/**********************************************************************************************************************************************************/

	{/*Shift Group***********************************************************************************************************************************************/
	/* 000 */ { Mnemonic::ROL,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { Mnemonic::ROR,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { Mnemonic::RCL,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { Mnemonic::RCR,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { Mnemonic::SHL,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { Mnemonic::SHR,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { Mnemonic::SAR,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } }
	},/**********************************************************************************************************************************************************/

	{/*Unary Group***********************************************************************************************************************************************/
	/* 000 */ { Mnemonic::TEST,   { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::I, OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { Mnemonic::NOT,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { Mnemonic::NEG,    { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { Mnemonic::MUL,    { { AddressingMethod::$, OperandType::$ }, { Register::A,         OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { Mnemonic::IMUL,   { { AddressingMethod::$, OperandType::$ }, { Register::A,         OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { Mnemonic::DIV,    { { AddressingMethod::$, OperandType::$ }, { Register::A,         OperandType::$ }, { AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { Mnemonic::IDIV,   { { AddressingMethod::$, OperandType::$ }, { Register::A,         OperandType::$ }, { AddressingMethod::_, OperandType::_ } } }
	},/**********************************************************************************************************************************************************/

	{/*Group Four************************************************************************************************************************************************/
	/* 000 */ { Mnemonic::INC,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { Mnemonic::DEC,    { { AddressingMethod::$, OperandType::$ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } }
	},/**********************************************************************************************************************************************************/

	{/*Group Five************************************************************************************************************************************************/
	/* 000 */ { Mnemonic::INC,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { Mnemonic::DEC,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { Mnemonic::CALL,   { { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { Mnemonic::CALL,   { { AddressingMethod::E, OperandType::p }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { Mnemonic::JMP,    { { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { Mnemonic::JMP,    { { AddressingMethod::M, OperandType::p }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { Mnemonic::PUSH,   { { AddressingMethod::E, OperandType::v }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { Mnemonic::_,      { { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ }, { AddressingMethod::_, OperandType::_ } } }
	}/***********************************************************************************************************************************************************/
};

#endif