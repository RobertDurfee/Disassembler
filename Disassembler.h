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
	Disassembler(byte * opcodes, int length);

	Instruction ** Instructions(int * numberOfInstructions);

	char ** Strings(int * numberOfLines);

	void Print();

private:
	byte * opcodes;
	int length;
};

Disassembler::Disassembler(byte * opcodes, int length)
{
	this->opcodes = opcodes;
	this->length = length;
}

Instruction ** Disassembler::Instructions(int * numberOfInstructions)
{
	Instruction ** output = nullptr;

	int index = 0;
	int maxNumberOfInstructions;

	if (*numberOfInstructions == 0)
		maxNumberOfInstructions = length; //The number of instructions will never exceed the length of the buffer
	else
		maxNumberOfInstructions = *numberOfInstructions;

	*numberOfInstructions = 0;

	while (*numberOfInstructions < maxNumberOfInstructions && index < length)
	{
		(*numberOfInstructions)++;

		output = (Instruction **)realloc(output, *numberOfInstructions * sizeof(Instruction *));

		output[*numberOfInstructions - 1] = new Instruction(opcodes, &index);
	}

	return output;
}

char ** Disassembler::Strings(int * numberOfLines)
{
	char ** output = nullptr;

	int index = 0;
	int maxNumberOfLines;

	if (*numberOfLines == 0)
		maxNumberOfLines = length; //The number of lines will never exceed the length of the buffer
	else
		maxNumberOfLines = *numberOfLines;

	*numberOfLines = 0;

	while (*numberOfLines < maxNumberOfLines && index < length)
	{
		(*numberOfLines)++;

		output = (char **)realloc(output, *numberOfLines * sizeof(char *));

		output[*numberOfLines - 1] = nullptr;

		Append(&output[*numberOfLines - 1], "0x%08X: ", index);

		Append(&output[*numberOfLines - 1], Instruction(opcodes, &index).GetString());

		Append(&output[*numberOfLines - 1], "\n");
	}

	return output;
}

void Disassembler::Print()
{
	int index = 0;

	while (index < length)
	{
		char * inst = nullptr;

		Append(&inst, "0x%08X: ", index);

		Append(&inst, Instruction(opcodes, &index).GetString());

		Append(&inst, "\n");

		fwrite(inst, sizeof(char), strlen(inst), stdout); //Used instead of printf() for performance

		free(inst);
	}
}

#endif