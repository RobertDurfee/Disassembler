#ifndef INSTRUCTION_OPERATOR_ENUMS_HEADER
#define INSTRUCTION_OPERATOR_ENUMS_HEADER

enum class Mnemonic
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

enum class Group
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

enum class Prefix
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

Prefix& operator|=(const Prefix& left, const Prefix& right)
{
	Prefix output = (Prefix)((int)left | (int)right); //Possible memory leak...
	return output;
}

#endif