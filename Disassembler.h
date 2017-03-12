#ifndef DISASSEMBLER_HEADER
#define DISASSEMBLER_HEADER

#include "Instruction\Instruction.h" //Instruction

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

	std::vector<Instruction> Instructions()
	{
		instructions.clear();

		int index = 0;

		while (index < length)
			instructions.push_back(Instruction(opcodes, &index));

		return instructions;
	}
	std::string String()
	{
		std::stringstream output;

		instructions.clear();

		int index = 0;
		
		while (index < length)
		{
			output << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase << index << ": ";
			instructions.push_back(Instruction(opcodes, &index));
			output << instructions.back().GetString() << std::endl;
		}

		return output.str();
	}
	void Print()
	{
		instructions.clear();

		int index = 0;

		while (index < length)
		{
			std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase << index << ": ";
			instructions.push_back(Instruction(opcodes, &index));
			std::cout << instructions.back().GetString() << std::endl;
		}
	}

private:
	std::vector<Instruction> instructions;
	byte * opcodes;
	int length;
};

#endif