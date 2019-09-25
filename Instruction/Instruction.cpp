#include <cstdlib>
#include <cstring>
#include "./Instruction.h"
#include "../ModRegRM/ModRegRM.h"
#include "../DisassemblerFunctions.h"
#include "../Operator/Operator.h"
#include "../Operand/Operand.h"

Instruction::Instruction(byte * opcode, int * index) : opcode(opcode), index(index)
{
	int startingIndex = *index;

	SetSchema();

	SetOperator();

	while ((schema.operandSchema[numberOfOperands].addressingMethod != AddressingMethod::_ || schema.operandSchema[numberOfOperands].generalRegister != GeneralRegister::_ || schema.operandSchema[numberOfOperands].segmentRegister != SegmentRegister::_ || schema.operandSchema[numberOfOperands].constant != Constant::_) && numberOfOperands < NUMBER_OF_OPERANDS)
	{
		numberOfOperands++;
		SetOperand();
	}

	SetValue(startingIndex);
}

Instruction::~Instruction()
{
	delete modRegRM;

	delete operator_;

	for (int i = 0; i < numberOfOperands; i++)
		delete operands[i];

	free(operands);
	free(value);
}

char * Instruction::GetString()
{
	char * output = nullptr;

	Append(&output, "%- 23s ", GetValueString());

	Append(&output, "%- 6s ", GetOperatorString());

	Append(&output, GetOperandsString());

	return output;
}

bool Instruction::HasPrefix()
{
	return (Prefix::ES <= schema.operatorSchema.prefix) && (schema.operatorSchema.prefix <= Prefix::REPE);
}

bool Instruction::HasSegmentPrefix()
{
	return (int)prefixes & 0x003F00; //All the segment prefixes OR'd together
}

bool Instruction::HasAddressPrefix()
{
	return (int)prefixes & (int)Prefix::ADDRESS;
}

bool Instruction::HasOperandPrefix()
{
	return (int)prefixes & (int)Prefix::OPERAND;
}

bool Instruction::HasGroup()
{
	return (Group::Immediate <= schema.operatorSchema.group) && (schema.operatorSchema.group <= Group::TwoByte);
}

void Instruction::SetSchema()
{
	schema = InstructionSchemas[Select<byte>(opcode, index)];

	if (HasPrefix())
	{
		SetPrefix();
		SetSchema();
	}
	else if (HasGroup())
	{
		SetModRegRM();
		SetGroupSchema();
	}
}

void Instruction::SetPrefix()
{
	prefixes = (Prefix)((int)prefixes | (int)schema.operatorSchema.prefix);
}

void Instruction::SetModRegRM()
{
	modRegRM = new ModRegRM(this);
}

void Instruction::SetGroupSchema()
{
	schema |= GroupSchemas[(int)schema.operatorSchema.group - (int)Group::Immediate][modRegRM->GetOpcodeExtensionValue()];
}

void Instruction::SetOperator()
{
	operator_ = new Operator(this);
}

void Instruction::SetOperand()
{
	operands = (Operand **)realloc(operands, numberOfOperands * sizeof(Operand *));

	operands[numberOfOperands - 1] = new Operand(this);
}

void Instruction::SetValue(int startingIndex)
{
	valueSize = *index - startingIndex;

	value = (byte *)malloc(valueSize);

	memcpy(value, &opcode[startingIndex], valueSize);
}

const char * Instruction::GetSegmentPrefixString()
{
	if ((int)prefixes & (int)Prefix::ES)
		return "ES:";
	else if ((int)prefixes & (int)Prefix::CS)
		return "CS:";
	else if ((int)prefixes & (int)Prefix::SS)
		return "SS:";
	else if ((int)prefixes & (int)Prefix::DS)
		return "DS:";
	else if ((int)prefixes & (int)Prefix::FS)
		return "FS:";
	else if ((int)prefixes & (int)Prefix::GS)
		return "GS:";
	else
		return "";
}

char * Instruction::GetOperandString(int operand)
{
	return operands[operand]->GetString();
}

const char * Instruction::GetOperatorString()
{
	return operator_->GetString();
}

char * Instruction::GetOperandsString()
{
	char * output = nullptr;

	for (int operand = 0; operand < numberOfOperands; operand++)
	{
		Append(&output, GetOperandString(operand));
		Append(&output, ", ");
	}

	RemoveLast(&output, 2);

	return output;
}

char * Instruction::GetValueString()
{
	char * output = nullptr;

	for (int i = 0; i < valueSize && i < 8; i++)
		if (i < 7)
			Append(&output, "%02X ", value[i]);
		else
			Append(&output, "+ ");

	RemoveLast(&output, 1);

	return output;
}
