#ifndef DISASSEMBLER_HEADER
#define DISASSEMBLER_HEADER

#include "DisassemblerTypes.h"       //byte
#include "DisassemblerFunctions.h"   //Append()

#include "Instruction\Instruction.h" //Instruction

#include <stdlib.h>                  //free()
#include <string.h>                  //strlen()
#include <stdio.h>                   //fwrite()

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
			char * inst = nullptr;

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