#ifndef INSTRUCTION_SCHEMAS_HEADER
#define INSTRUCTION_SCHEMAS_HEADER

typedef unsigned long  Operator;
typedef unsigned long  Operand;

enum class Mnemonic : Operator
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

enum class Group : Operator 
{ 
/* 0x00000 */ _,             //No Operator

/* 0x0009A */ Immediate = (Operator)Mnemonic::LAST,  //Arithmetic Operations
/* 0x0009B */ Shift,         //Shift/Rotate Operations
/* 0x0009C */ Unary,         //Multiplication, Division, Test, Negate Operations
/* 0x0009D */ Four,          //Increment, Decrement
/* 0x0009E */ Five,          //Increment, Decrement, Call, Jump, Push Operations
/* 0x0009F */ TwoByte,       //Two Byte Operations

/* 0x000A0 */ LAST           //Placeholder
};

enum class Prefix : Operator 
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

enum class AddressingMethod : Operand 
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

enum class Register : Operand 
{ 
/* 0x00 */ _,    //No Operand

/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x0E */ A = (Operand)AddressingMethod::LAST, //General A Register
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

enum class SegmentRegister : Operand
{
/* 0x00 */ _,    //No Operand

/* 0x01 */ $,    //Operand Specified in Another Table

/* 0x16 */ ES = (Operand)Register::LAST, //E Segment Register
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

enum class Constant : Operand 
{ 
/* 0x00 */ _,      //No Operand

/* 0x01 */ $,      //Operand Specified in Another Table

/* 0x1C */ ONE = (Operand)SegmentRegister::LAST, //The number one (Used only by the shift instruction group)

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

struct InstructionSchema
{
	union
	{
		Operator mnemonic;
		Operator prefix;
		Operator group;
	} operator_;

	union
	{
		struct
		{
			Operand addressingMethod;
			OperandType operandType;
		};
		Operand register_;
		Operand segmentRegister;
		Operand constant;
	} operands[NUMBER_OF_OPERANDS];
};

const InstructionSchema operator|(const InstructionSchema& left, const InstructionSchema& right)
{
	InstructionSchema output;

	output.operator_.mnemonic = left.operator_.mnemonic;

	for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
	{
		if (left.operands[i].addressingMethod == (Operand)AddressingMethod::$)
			output.operands[i].addressingMethod = right.operands[i].addressingMethod;
		else
			output.operands[i].addressingMethod = left.operands[i].addressingMethod;

		if (left.operands[i].operandType == OperandType::$)
			output.operands[i].operandType == right.operands[i].operandType;
		else
			output.operands[i].operandType == left.operands[i].operandType;
	}

	return output;
}

const InstructionSchema InstructionSchemas[0x100 /*0000 0000 - 1111 1111*/] = 
{ 
/*******************************************************************************************************************************************************************************************************/
/* 0x00 */ { (Operator)Mnemonic::ADD,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x01 */ { (Operator)Mnemonic::ADD,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x02 */ { (Operator)Mnemonic::ADD,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x03 */ { (Operator)Mnemonic::ADD,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x04 */ { (Operator)Mnemonic::ADD,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x05 */ { (Operator)Mnemonic::ADD,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x06 */ { (Operator)Mnemonic::PUSH,   { { (Operand)SegmentRegister::ES, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x07 */ { (Operator)Mnemonic::POP,    { { (Operand)SegmentRegister::ES, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x08 */ { (Operator)Mnemonic::OR,     { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x09 */ { (Operator)Mnemonic::OR,     { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x0A */ { (Operator)Mnemonic::OR,     { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x0B */ { (Operator)Mnemonic::OR,     { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x0C */ { (Operator)Mnemonic::OR,     { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x0D */ { (Operator)Mnemonic::OR,     { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x0E */ { (Operator)Mnemonic::PUSH,   { { (Operand)SegmentRegister::CS, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x0F */ { (Operator)Group::TwoByte,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x10 */ { (Operator)Mnemonic::ADC,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x11 */ { (Operator)Mnemonic::ADC,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x12 */ { (Operator)Mnemonic::ADC,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x13 */ { (Operator)Mnemonic::ADC,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x14 */ { (Operator)Mnemonic::ADC,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x15 */ { (Operator)Mnemonic::ADC,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x16 */ { (Operator)Mnemonic::PUSH,   { { (Operand)SegmentRegister::SS, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x17 */ { (Operator)Mnemonic::POP,    { { (Operand)SegmentRegister::SS, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x18 */ { (Operator)Mnemonic::SBB,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x19 */ { (Operator)Mnemonic::SBB,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x1A */ { (Operator)Mnemonic::SBB,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x1B */ { (Operator)Mnemonic::SBB,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x1C */ { (Operator)Mnemonic::SBB,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x1D */ { (Operator)Mnemonic::SBB,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x1E */ { (Operator)Mnemonic::PUSH,   { { (Operand)SegmentRegister::DS, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x1F */ { (Operator)Mnemonic::POP,    { { (Operand)SegmentRegister::DS, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x20 */ { (Operator)Mnemonic::AND,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x21 */ { (Operator)Mnemonic::AND,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x22 */ { (Operator)Mnemonic::AND,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x23 */ { (Operator)Mnemonic::AND,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x24 */ { (Operator)Mnemonic::AND,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x25 */ { (Operator)Mnemonic::AND,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x26 */ { (Operator)Prefix::ES,       { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x27 */ { (Operator)Mnemonic::DAA,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x28 */ { (Operator)Mnemonic::SUB,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x29 */ { (Operator)Mnemonic::SUB,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x2A */ { (Operator)Mnemonic::SUB,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x2B */ { (Operator)Mnemonic::SUB,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x2C */ { (Operator)Mnemonic::SUB,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x2D */ { (Operator)Mnemonic::SUB,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x2E */ { (Operator)Prefix::CS,       { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x2F */ { (Operator)Mnemonic::DAS,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x30 */ { (Operator)Mnemonic::XOR,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x31 */ { (Operator)Mnemonic::XOR,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x32 */ { (Operator)Mnemonic::XOR,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x33 */ { (Operator)Mnemonic::XOR,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x34 */ { (Operator)Mnemonic::XOR,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x35 */ { (Operator)Mnemonic::XOR,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x36 */ { (Operator)Prefix::SS,       { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x37 */ { (Operator)Mnemonic::AAA,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x38 */ { (Operator)Mnemonic::CMP,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x39 */ { (Operator)Mnemonic::CMP,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x3A */ { (Operator)Mnemonic::CMP,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x3B */ { (Operator)Mnemonic::CMP,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x3C */ { (Operator)Mnemonic::CMP,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x3E */ { (Operator)Mnemonic::CMP,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x3D */ { (Operator)Prefix::DS,       { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x3F */ { (Operator)Mnemonic::AAS,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x40 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::A,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x41 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::C,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x42 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::D,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x43 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::B,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x44 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::SP,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x45 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::BP,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x46 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::SI,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x47 */ { (Operator)Mnemonic::INC,    { { (Operand)Register::DI,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x48 */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::A,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x49 */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::C,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x4A */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::D,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x4B */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::B,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x4C */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::SP,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x4D */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::BP,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x4E */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::SI,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x4F */ { (Operator)Mnemonic::DEC,    { { (Operand)Register::DI,        OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x50 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x51 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::C,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x52 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::D,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x53 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::B,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x54 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::SP,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x55 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::BP,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x56 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::SI,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x57 */ { (Operator)Mnemonic::PUSH,   { { (Operand)Register::DI,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x58 */ { (Operator)Mnemonic::POP,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x59 */ { (Operator)Mnemonic::POP,    { { (Operand)Register::C,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x5A */ { (Operator)Mnemonic::POP,    { { (Operand)Register::D,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x5B */ { (Operator)Mnemonic::POP,    { { (Operand)Register::B,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x5C */ { (Operator)Mnemonic::POP,    { { (Operand)Register::SP,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x5D */ { (Operator)Mnemonic::POP,    { { (Operand)Register::BP,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x5E */ { (Operator)Mnemonic::POP,    { { (Operand)Register::SI,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x5F */ { (Operator)Mnemonic::POP,    { { (Operand)Register::DI,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x60 */ { (Operator)Mnemonic::PUSHA,  { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x61 */ { (Operator)Mnemonic::POPA,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x62 */ { (Operator)Mnemonic::BOUND,  { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::M, OperandType::a }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x63 */ { (Operator)Mnemonic::ARPL,   { { (Operand)AddressingMethod::E, OperandType::w }, { (Operand)AddressingMethod::G, OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x64 */ { (Operator)Prefix::FS,       { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x65 */ { (Operator)Prefix::GS,       { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x66 */ { (Operator)Prefix::OPERAND,  { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x67 */ { (Operator)Prefix::ADDRESS,  { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x68 */ { (Operator)Mnemonic::PUSH,   { { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x69 */ { (Operator)Mnemonic::IMUL,   { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z } } },
/* 0x6A */ { (Operator)Mnemonic::PUSH,   { { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x6B */ { (Operator)Mnemonic::IMUL,   { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::I, OperandType::b } } },
/* 0x6C */ { (Operator)Mnemonic::INS,    { { (Operand)AddressingMethod::Y, OperandType::b }, { (Operand)AddressingMethod::D, OperandType::x }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x6D */ { (Operator)Mnemonic::INS,    { { (Operand)AddressingMethod::Y, OperandType::z }, { (Operand)AddressingMethod::D, OperandType::x }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x6E */ { (Operator)Mnemonic::OUTS,   { { (Operand)AddressingMethod::D, OperandType::x }, { (Operand)AddressingMethod::X, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x6F */ { (Operator)Mnemonic::OUTS,   { { (Operand)AddressingMethod::D, OperandType::x }, { (Operand)AddressingMethod::X, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x70 */ { (Operator)Mnemonic::JO,     { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x71 */ { (Operator)Mnemonic::JNO,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x72 */ { (Operator)Mnemonic::JB,     { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x73 */ { (Operator)Mnemonic::JNB,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x74 */ { (Operator)Mnemonic::JZ,     { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x75 */ { (Operator)Mnemonic::JNZ,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x76 */ { (Operator)Mnemonic::JBE,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x77 */ { (Operator)Mnemonic::JNBE,   { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x78 */ { (Operator)Mnemonic::JS,     { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x79 */ { (Operator)Mnemonic::JNS,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x7A */ { (Operator)Mnemonic::JP,     { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x7B */ { (Operator)Mnemonic::JNP,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x7C */ { (Operator)Mnemonic::JL,     { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x7D */ { (Operator)Mnemonic::JNL,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x7E */ { (Operator)Mnemonic::JLE,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x7F */ { (Operator)Mnemonic::JNLE,   { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x80 */ { (Operator)Group::Immediate, { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x81 */ { (Operator)Group::Immediate, { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x82 */ { (Operator)Group::Immediate, { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x83 */ { (Operator)Group::Immediate, { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x84 */ { (Operator)Mnemonic::TEST,   { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x85 */ { (Operator)Mnemonic::TEST,   { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x86 */ { (Operator)Mnemonic::XCHG,   { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x87 */ { (Operator)Mnemonic::XCHG,   { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x88 */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x89 */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x8A */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::G, OperandType::b }, { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x8B */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x8C */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::S, OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x8D */ { (Operator)Mnemonic::LEA,    { { (Operand)AddressingMethod::G, OperandType::v }, { (Operand)AddressingMethod::M, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x8E */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::S, OperandType::w }, { (Operand)AddressingMethod::E, OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x8F */ { (Operator)Mnemonic::POP,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0x90 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x91 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::C,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x92 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::D,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x93 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::B,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x94 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::SP,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x95 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::BP,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x96 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::SI,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x97 */ { (Operator)Mnemonic::XCHG,   { { (Operand)Register::A,         OperandType::v }, { (Operand)Register::DI,        OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0x98 */ { (Operator)Mnemonic::CBW,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x99 */ { (Operator)Mnemonic::CWD,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x9A */ { (Operator)Mnemonic::CALL,   { { (Operand)AddressingMethod::A, OperandType::p }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x9B */ { (Operator)Mnemonic::WAIT,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x9C */ { (Operator)Mnemonic::PUSHF,  { { (Operand)AddressingMethod::F, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x9D */ { (Operator)Mnemonic::POPF,   { { (Operand)AddressingMethod::F, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x9E */ { (Operator)Mnemonic::SAHF,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0x9F */ { (Operator)Mnemonic::LAHF,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0xA0 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::O, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA1 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::O, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA2 */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::O, OperandType::b }, { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA3 */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::O, OperandType::v }, { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA4 */ { (Operator)Mnemonic::MOVS,   { { (Operand)AddressingMethod::Y, OperandType::b }, { (Operand)AddressingMethod::X, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA5 */ { (Operator)Mnemonic::MOVS,   { { (Operand)AddressingMethod::Y, OperandType::v }, { (Operand)AddressingMethod::X, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA6 */ { (Operator)Mnemonic::CMPS,   { { (Operand)AddressingMethod::X, OperandType::b }, { (Operand)AddressingMethod::Y, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA7 */ { (Operator)Mnemonic::CMPS,   { { (Operand)AddressingMethod::X, OperandType::v }, { (Operand)AddressingMethod::Y, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0xA8 */ { (Operator)Mnemonic::TEST,   { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xA9 */ { (Operator)Mnemonic::TEST,   { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xAA */ { (Operator)Mnemonic::STOS,   { { (Operand)AddressingMethod::Y, OperandType::b }, { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xAB */ { (Operator)Mnemonic::STOS,   { { (Operand)AddressingMethod::Y, OperandType::v }, { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xAC */ { (Operator)Mnemonic::LODS,   { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::X, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xAD */ { (Operator)Mnemonic::LODS,   { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::X, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xAE */ { (Operator)Mnemonic::SCAS,   { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::Y, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xAF */ { (Operator)Mnemonic::SCAS,   { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::Y, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0xB0 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB1 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::C,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB2 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::D,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB3 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::B,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB4 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::SP,        OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB5 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::BP,        OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB6 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::SI,        OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB7 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::DI,        OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
 
/* 0xB8 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::A,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xB9 */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::C,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xBA */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::D,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xBB */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::B,         OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xBC */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::SP,        OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xBD */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::BP,        OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xBE */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::SI,        OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xBF */ { (Operator)Mnemonic::MOV,    { { (Operand)Register::DI,        OperandType::v }, { (Operand)AddressingMethod::I, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0xC0 */ { (Operator)Group::Shift,     { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC1 */ { (Operator)Group::Shift,     { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC2 */ { (Operator)Mnemonic::RET,    { { (Operand)AddressingMethod::I, OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC3 */ { (Operator)Mnemonic::RET,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC4 */ { (Operator)Mnemonic::LES,    { { (Operand)AddressingMethod::G, OperandType::z }, { (Operand)AddressingMethod::M, OperandType::p }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC5 */ { (Operator)Mnemonic::LDS,    { { (Operand)AddressingMethod::G, OperandType::z }, { (Operand)AddressingMethod::M, OperandType::p }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC6 */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC7 */ { (Operator)Mnemonic::MOV,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::I, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0xC8 */ { (Operator)Mnemonic::ENTER,  { { (Operand)AddressingMethod::I, OperandType::w }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xC9 */ { (Operator)Mnemonic::LEAVE,  { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xCA */ { (Operator)Mnemonic::RET,    { { (Operand)AddressingMethod::I, OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xCB */ { (Operator)Mnemonic::RET,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xCC */ { (Operator)Mnemonic::INT,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xCD */ { (Operator)Mnemonic::INT,    { { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xCE */ { (Operator)Mnemonic::INTO,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xCF */ { (Operator)Mnemonic::IRET,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0xD0 */ { (Operator)Group::Shift,     { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)Constant::ONE,       OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD1 */ { (Operator)Group::Shift,     { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)Constant::ONE,       OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD2 */ { (Operator)Group::Shift,     { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)Register::C,         OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD3 */ { (Operator)Group::Shift,     { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)Register::C,         OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD4 */ { (Operator)Mnemonic::AAM,    { { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD5 */ { (Operator)Mnemonic::AAD,    { { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD6 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD7 */ { (Operator)Mnemonic::XLAT,   { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } }, 

/* 0xD8 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xD9 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xDA */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xDB */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xDC */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xDD */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xDE */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xDF */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0xE0 */ { (Operator)Mnemonic::LOOPNE, { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE1 */ { (Operator)Mnemonic::LOOPE,  { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE2 */ { (Operator)Mnemonic::LOOP,   { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE3 */ { (Operator)Mnemonic::JECXZ,  { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE4 */ { (Operator)Mnemonic::IN,     { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE5 */ { (Operator)Mnemonic::IN,     { { (Operand)Register::A,         OperandType::z }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE6 */ { (Operator)Mnemonic::OUT,    { { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE7 */ { (Operator)Mnemonic::OUT,    { { (Operand)Register::A,         OperandType::z }, { (Operand)AddressingMethod::I, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0xE8 */ { (Operator)Mnemonic::CALL,   { { (Operand)AddressingMethod::J, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xE9 */ { (Operator)Mnemonic::JMP,    { { (Operand)AddressingMethod::J, OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xEA */ { (Operator)Mnemonic::JMP,    { { (Operand)AddressingMethod::A, OperandType::p }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xEB */ { (Operator)Mnemonic::JMP,    { { (Operand)AddressingMethod::J, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xEC */ { (Operator)Mnemonic::IN,     { { (Operand)Register::A,         OperandType::b }, { (Operand)Register::D,         OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xED */ { (Operator)Mnemonic::IN,     { { (Operand)Register::A,         OperandType::z }, { (Operand)Register::D,         OperandType::w }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xEE */ { (Operator)Mnemonic::OUT,    { { (Operand)Register::D,         OperandType::w }, { (Operand)Register::A,         OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xEF */ { (Operator)Mnemonic::OUT,    { { (Operand)Register::D,         OperandType::w }, { (Operand)Register::A,         OperandType::z }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/*******************************************************************************************************************************************************************************************************/

/*******************************************************************************************************************************************************************************************************/
/* 0xF0 */ { (Operator)Prefix::LOCK,     { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF1 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF2 */ { (Operator)Prefix::REPNE,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF3 */ { (Operator)Prefix::REPE,     { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF4 */ { (Operator)Mnemonic::HLT,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF5 */ { (Operator)Mnemonic::CMC,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF6 */ { (Operator)Group::Unary,     { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::$, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF7 */ { (Operator)Group::Unary,     { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::$, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ } } },

/* 0xF8 */ { (Operator)Mnemonic::CLC,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xF9 */ { (Operator)Mnemonic::STC,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xFA */ { (Operator)Mnemonic::CLI,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xFB */ { (Operator)Mnemonic::STI,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xFC */ { (Operator)Mnemonic::CLD,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xFD */ { (Operator)Mnemonic::STD,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xFE */ { (Operator)Group::Four,      { { (Operand)AddressingMethod::E, OperandType::b }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
/* 0xFF */ { (Operator)Group::Five,      { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } }
/*******************************************************************************************************************************************************************************************************/
};

const InstructionSchema GroupSchemas[5][0x8 /* 000 - 111 */] =
{
	{/*Immediate Group********************************************************************************************************************************************************************************/
	/* 000 */ { (Operator)Mnemonic::ADD,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { (Operator)Mnemonic::OR,     { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { (Operator)Mnemonic::ADC,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { (Operator)Mnemonic::SBB,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { (Operator)Mnemonic::AND,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { (Operator)Mnemonic::SUB,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { (Operator)Mnemonic::XOR,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { (Operator)Mnemonic::CMP,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } }
	},/***********************************************************************************************************************************************************************************************/

	{/*Shift Group************************************************************************************************************************************************************************************/
	/* 000 */ { (Operator)Mnemonic::ROL,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { (Operator)Mnemonic::ROR,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { (Operator)Mnemonic::RCL,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { (Operator)Mnemonic::RCR,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { (Operator)Mnemonic::SHL,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { (Operator)Mnemonic::SHR,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { (Operator)Mnemonic::SAR,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } }
	},/***********************************************************************************************************************************************************************************************/

	{/*Unary Group************************************************************************************************************************************************************************************/
	/* 000 */ { (Operator)Mnemonic::TEST,   { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::I, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { (Operator)Mnemonic::NOT,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { (Operator)Mnemonic::NEG,    { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { (Operator)Mnemonic::MUL,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)Register::A,         OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { (Operator)Mnemonic::IMUL,   { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)Register::A,         OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { (Operator)Mnemonic::DIV,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)Register::A,         OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { (Operator)Mnemonic::IDIV,   { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)Register::A,         OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ } } }
	},/***********************************************************************************************************************************************************************************************/

	{/*Group Four*************************************************************************************************************************************************************************************/
	/* 000 */ { (Operator)Mnemonic::INC,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { (Operator)Mnemonic::DEC,    { { (Operand)AddressingMethod::$, OperandType::$ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } }
	},/***********************************************************************************************************************************************************************************************/

	{/*Group Five*************************************************************************************************************************************************************************************/
	/* 000 */ { (Operator)Mnemonic::INC,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 001 */ { (Operator)Mnemonic::DEC,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 010 */ { (Operator)Mnemonic::CALL,   { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 011 */ { (Operator)Mnemonic::CALL,   { { (Operand)AddressingMethod::E, OperandType::p }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 100 */ { (Operator)Mnemonic::JMP,    { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 101 */ { (Operator)Mnemonic::JMP,    { { (Operand)AddressingMethod::M, OperandType::p }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 110 */ { (Operator)Mnemonic::PUSH,   { { (Operand)AddressingMethod::E, OperandType::v }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } },
	/* 111 */ { (Operator)Mnemonic::_,      { { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ }, { (Operand)AddressingMethod::_, OperandType::_ } } }
	}/************************************************************************************************************************************************************************************************/
};

#endif