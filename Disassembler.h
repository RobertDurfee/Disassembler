#ifndef DISASSEMBLER_HEADER
#define DISASSEMBLER_HEADER

#include "Instruction\Instruction.h" //Instruction

class Disassembler
{
public:
	Disassembler(byte * opcodes, int length)
	{
		this->opcodes = opcodes;
		this->length = length;
	}

	void Print()
	{
		int index = 0;

		while (index < length)
		{
			char * inst = NULL;

			Append(&inst, "0x%08X: ", index);
			
			Append(&inst, Instruction(opcodes, &index).GetString());

			Append(&inst, "\n");

			fwrite(inst, sizeof(char), strlen(inst), stdout);

			free(inst);
		}
	}

private:
	byte * opcodes;
	int length;
};

#endif