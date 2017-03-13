#ifndef DISASSEMBLER_HEADER
#define DISASSEMBLER_HEADER

#include "Instruction\Instruction.hpp" //Instruction

#include <vector>                    //std::vector
#include <string>                    //std::string
#include <sstream>                   //std::stringstream
#include <iostream>                  //std::cout

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
			std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase << index << ": ";
			std::cout << Instruction(opcodes, &index).GetString() << std::endl;
		}
	}

private:
	byte * opcodes;
	int length;
};

#endif