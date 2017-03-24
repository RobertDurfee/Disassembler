#ifndef OPERAND_SCHEMAS_HEADER
#define OPERAND_SCHEMAS_HEADER

#include "OperandEnums.h" //AddressingMethod, GeneralRegister, SegmentRegister, Constant, Size

struct OperandSchema
{
	OperandSchema() : addressingMethod(AddressingMethod::_), operandSize(Size::_), generalRegister(GeneralRegister::_), segmentRegister(SegmentRegister::_), constant(Constant::_) {};

	OperandSchema(AddressingMethod addressingMethod, Size operandSize) : addressingMethod(addressingMethod), operandSize(operandSize) {};
	OperandSchema(GeneralRegister generalRegister, Size operandSize) : generalRegister(generalRegister), operandSize(operandSize) {};
	OperandSchema(SegmentRegister segmentRegister, Size operandSize) : segmentRegister(segmentRegister), operandSize(operandSize) {};
	OperandSchema(Constant constant, Size operandSize) : constant(constant), operandSize(operandSize) {};

	struct
	{
		AddressingMethod addressingMethod;
		Size operandSize;
	};
	GeneralRegister generalRegister;
	SegmentRegister segmentRegister;
	Constant constant;
};

const OperandSchema EmptyOperandSchema = { AddressingMethod::_, Size::_ };

#endif