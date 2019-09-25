#ifndef DISASSEMBLER_HEADER
#define DISASSEMBLER_HEADER

#include "./DisassemblerTypes.h"
#include "./Instruction/Instruction.h"

class Disassembler
{
public:
	Disassembler(byte * opcodes, int length);

	Instruction ** Instructions(int * numberOfInstructions);

	char ** Strings(int * numberOfLines);

	void Print();

private:
	byte * opcodes;
	int length;
};

#endif
