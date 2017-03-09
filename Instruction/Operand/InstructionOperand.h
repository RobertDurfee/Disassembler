#ifndef INSTRUCTION_OPERAND_HEADER
#define INSTRUCTION_OPERAND_HEADER

#include "InstructionOperandEnums.h"
#include "InstructionOperandStrings.h"

union Operand
{
	Operand() : addressingMethod(AddressingMethod::_) , operandSize(Size::_) , register_(Register::_) , segmentRegister(SegmentRegister::_) , constant(Constant::_) {};

	Operand(AddressingMethod addressingMethod, Size operandSize) : addressingMethod(addressingMethod), operandSize(operandSize) {};
	Operand(Register register_, Size operandSize)                : register_(register_),               operandSize(operandSize) {};
	Operand(SegmentRegister segmentRegister, Size operandSize)   : segmentRegister(segmentRegister),   operandSize(operandSize) {};
	Operand(Constant constant, Size operandSize)                 : constant(constant),                 operandSize(operandSize) {};

	struct
	{
		AddressingMethod addressingMethod;
		Size operandSize;
	};
	Register register_;
	SegmentRegister segmentRegister;
	Constant constant;
};

#endif