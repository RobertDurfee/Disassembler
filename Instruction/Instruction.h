#ifndef INSTRUCTION_HEADER
#define INSTRUCTION_HEADER

#include "../DisassemblerTypes.h" //byte, word, dword

#include "InstructionSchemas.h"   //InstructionSchema, InstructionSchemas

#include "../ModRegRM/ModRegRM.h" //ModRegRM

class Instruction
{
public:
	Instruction(byte * opcode, int * index)
	{

	}

private:
	InstructionSchema schema;
	ModRegRM modregrm;

};

#endif