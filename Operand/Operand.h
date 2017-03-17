#ifndef OPERAND_HEADER
#define OPERAND_HEADER

#include "../DisassemblerTypes.h"         //byte, word, dword
#include "../DisassemblerFunctions.h"     //Append(), Select<>()

//#include "../Instruction/Instruction.h" //Instruction (Due to circular include dependency, this must be commented out.)

#include "OperandEnums.h"                 //AddressingMethod, GeneralRegister, SegmentRegister
#include "OperandStrings.h"               //GeneralRegisterString, SegmentRegisterString, ConstantString, EIGHT_BIT, SIXTEEN_BIT, THIRTYTWO_BIT
#include "OperandSchemas.h"               //OperandSchema, EmptyOperandSchema

#include <stdlib.h>                       //malloc(), free()
#include <string.h>                       //memcpy()

class Operand
{
	friend class ModRegRM; //Needs: opcode, index, schema.operandSize

public:
	Operand() {};
	Operand(Instruction * instruction);

	char * GetString();

private:
	//Opcode buffer
	int * index = nullptr;
	byte * opcode = nullptr;

	//Caller
	Instruction * instruction = nullptr;
	int operandIndex = 0;

	//Schema
	OperandSchema schema = EmptyOperandSchema;

	//Optional fields
	ModRegRM * modRegRM = nullptr;
	byte imm8 = 0;
	word imm16 = 0;
	dword imm32 = 0;
	byte disp8 = 0;
	word disp16 = 0;
	dword disp32 = 0;
	word sel16 = 0;
	byte addr8 = 0;
	word addr16 = 0;
	dword addr32 = 0;

	//Testers
	bool HasAddressPrefix();
	bool HasOperandPrefix();
	bool HasSegmentPrefix();
	bool HasModRegRM();
	bool HasImmediate();
	bool HasRelativeDisplacement();
	bool HasMemoryDisplacement();
	bool HasDirectAddress();
	bool HasModRM();
	bool HasGeneralRegister();
	bool HasSegmentRegister();
	bool HasFixedAddress();
	bool HasFixedGeneralRegister();
	bool HasFixedSegmentRegsiter();
	bool HasFixedConstant();

	//Setters
	void SetSchema();
	void SetModRegRM();
	void SetImmediate();
	void SetRelativeDisplacement();
	void SetMemoryDisplacement();
	void SetDirectAddress();

	//Getters
	const char * GetSegmentPrefixString();
	char * GetImmediateString();
	char * GetRelativeDisplacementString();
	char * GetMemoryDisplacementString();
	char * GetDirectAddressString();
	char * GetModRMString();
	char * GetGeneralRegisterString();
	char * GetSegmentRegsiterString();
	char * GetFixedAddressString();
	const char * GetFixedGeneralRegisterString();
	const char * GetFixedSegmentRegisterString();
	const char * GetFixedConstantString();
	const char * GetSizeString();
};

#include "../ModRegRM/ModRegRM.h" //ModRegRM (Due to circular include dependency, this must be placed here.)

Operand::Operand(Instruction * instruction) : instruction(instruction), opcode(instruction->opcode), index(instruction->index), modRegRM(instruction->modRegRM), operandIndex(instruction->numberOfOperands - 1)
{
	SetSchema();

	if (HasModRegRM() && modRegRM == nullptr)
		SetModRegRM();
	else if (HasImmediate())
		SetImmediate();
	else if (HasRelativeDisplacement())
		SetRelativeDisplacement();
	else if (HasMemoryDisplacement())
		SetMemoryDisplacement();
	else if (HasDirectAddress())
		SetDirectAddress();
}

char * Operand::GetString()
{
	char * output = nullptr;

	if (HasModRM())
		Append(&output, GetModRMString());
	else if (HasGeneralRegister())
		Append(&output, GetGeneralRegisterString());
	else if (HasSegmentRegister())
		Append(&output, GetSegmentRegsiterString());
	else if (HasImmediate())
		Append(&output, GetImmediateString());
	else if (HasRelativeDisplacement())
		Append(&output, GetRelativeDisplacementString());
	else if (HasMemoryDisplacement())
		Append(&output, GetMemoryDisplacementString());
	else if (HasDirectAddress())
		Append(&output, GetDirectAddressString());
	else if (HasFixedAddress())
		Append(&output, GetFixedAddressString());
	else if (HasFixedGeneralRegister())
		Append(&output, GetFixedGeneralRegisterString());
	else if (HasFixedSegmentRegsiter())
		Append(&output, GetFixedSegmentRegisterString());
	else if (HasFixedConstant())
		Append(&output, GetFixedConstantString());
	else
		Append(&output, "ERROR");

	return output;
}

bool Operand::HasAddressPrefix()
{
	return instruction->HasAddressPrefix();
}
bool Operand::HasOperandPrefix()
{
	return instruction->HasOperandPrefix();
}
bool Operand::HasSegmentPrefix()
{
	return instruction->HasSegmentPrefix();
}
bool Operand::HasModRegRM()
{
	return HasModRM() || HasGeneralRegister() || HasSegmentRegister();
}
bool Operand::HasImmediate()
{
	return schema.addressingMethod == AddressingMethod::I;
}
bool Operand::HasRelativeDisplacement()
{
	return schema.addressingMethod == AddressingMethod::J;
}
bool Operand::HasMemoryDisplacement()
{
	return schema.addressingMethod == AddressingMethod::O;
}
bool Operand::HasDirectAddress()
{
	return schema.addressingMethod == AddressingMethod::A;
}
bool Operand::HasModRM()
{
	return (schema.addressingMethod == AddressingMethod::E) || (schema.addressingMethod == AddressingMethod::M);
}
bool Operand::HasGeneralRegister()
{
	return schema.addressingMethod == AddressingMethod::G;
}
bool Operand::HasSegmentRegister()
{
	return schema.addressingMethod == AddressingMethod::S;
}
bool Operand::HasFixedAddress()
{
	return (schema.addressingMethod == AddressingMethod::X) || (schema.addressingMethod == AddressingMethod::Y);
}
bool Operand::HasFixedGeneralRegister()
{
	return (GeneralRegister::A <= schema.generalRegister) && (schema.generalRegister <= GeneralRegister::DI);
}
bool Operand::HasFixedSegmentRegsiter()
{
	return (SegmentRegister::ES <= schema.segmentRegister) && (schema.segmentRegister <= SegmentRegister::GS);
}
bool Operand::HasFixedConstant()
{
	return (Constant::ONE <= schema.constant) && (schema.constant <= Constant::ONE);
}

void Operand::SetSchema()
{
	schema = instruction->schema.operandSchema[operandIndex];
}
void Operand::SetModRegRM()
{
	instruction->SetModRegRM();
	modRegRM = instruction->modRegRM;
}
void Operand::SetImmediate()
{
	switch (schema.operandSize)
	{
		case Size::b:
			imm8 = Select<byte>(opcode, index);
			break;
		case Size::w:
			imm16 = Select<word>(opcode, index);
			break;
		case Size::v:
			if (HasOperandPrefix())
				imm16 = Select<word>(opcode, index);
			else
				imm32 = Select<dword>(opcode, index);
			break;
	}
}
void Operand::SetRelativeDisplacement()
{
	switch (schema.operandSize)
	{
		case Size::b:
			disp8 = Select<byte>(opcode, index) + *index;
			break;
		case Size::v:
			if (HasOperandPrefix())
				disp16 = Select<word>(opcode, index) + *index;
			else
				disp32 = Select<dword>(opcode, index) + *index;
			break;
	}
}
void Operand::SetMemoryDisplacement()
{
	if (HasAddressPrefix())
		disp16 = Select<word>(opcode, index);
	else
		disp32 = Select<dword>(opcode, index);
}
void Operand::SetDirectAddress()
{
	if (HasOperandPrefix())
		addr16 = Select<word>(opcode, index);
	else
		addr32 = Select<dword>(opcode, index);

	sel16 = Select<word>(opcode, index);
}

const char * Operand::GetSegmentPrefixString()
{
	return instruction->GetSegmentPrefixString();
}
char * Operand::GetImmediateString()
{
	char * output = nullptr;

	switch (schema.operandSize)
	{
		case Size::b:
			Append(&output, "%02Xh", imm8);
			break;
		case Size::w:
			Append(&output, "%04Xh", imm16);
			break;
		case Size::d:
			Append(&output, "%08Xh", imm32);
			break;
		case Size::v:
			if (HasOperandPrefix())
				Append(&output, "%04Xh", imm16);
			else
				Append(&output, "%08Xh", imm32);
			break;
		default:
			Append(&output, "ERROR");
			break;
	}

	return output;
}
char * Operand::GetRelativeDisplacementString()
{
	char * output = nullptr;

	switch (schema.operandSize)
	{
		case Size::b:
			Append(&output, "%02Xh", disp8);
			break;
		case Size::w:
			Append(&output, "%04Xh", disp16);
			break;
		case Size::d:
			Append(&output, "%08Xh", disp32);
			break;
		case Size::v:
			if (HasOperandPrefix())
				Append(&output, "%04Xh", disp16);
			else
				Append(&output, "%08Xh", disp32);
			break;
		default:
			Append(&output, "ERROR");
			break;
	}

	return output;
}
char * Operand::GetMemoryDisplacementString()
{
	char * output = nullptr;

	if (HasSegmentPrefix())
		Append(&output, GetSegmentPrefixString());
	else
		Append(&output, "DS:");

	if (HasAddressPrefix())
		Append(&output, "%04Xh", disp16);
	else
		Append(&output, "%08Xh", disp32);

	return output;
}
char * Operand::GetDirectAddressString()
{
	char * output = nullptr;

	Append(&output, GetSizeString());

	Append(&output, "%04Xh:", sel16);

	if (HasOperandPrefix())
		Append(&output, "%04Xh", addr16);
	else
		Append(&output, "%08Xh", addr32);

	return output;
}
char * Operand::GetModRMString()
{
	return modRegRM->GetString(this);
}
char * Operand::GetGeneralRegisterString()
{
	return modRegRM->GetString(this);
}
char * Operand::GetSegmentRegsiterString()
{
	return modRegRM->GetString(this);
}
char * Operand::GetFixedAddressString()
{
	char * output = nullptr;

	switch (schema.addressingMethod)
	{
		case AddressingMethod::X:
			if (HasSegmentPrefix())
				Append(&output, GetSegmentPrefixString());
			else
				Append(&output, "DS:");

			if (HasOperandPrefix())
				Append(&output, "[SI]");
			else
				Append(&output, "[ESI]");
			break;
		case AddressingMethod::Y:
			if (HasOperandPrefix())
				Append(&output, "ES:[DI]");
			else
				Append(&output, "ES:[EDI]");
			break;
		default:
			Append(&output, "ERROR");
			break;
	}

	return output;
}
const char * Operand::GetFixedGeneralRegisterString()
{
	switch (schema.operandSize)
	{
		case Size::b:
			return GeneralRegisterString[EIGHT_BIT((int)schema.generalRegister - (int)GeneralRegister::A)];
		case Size::w:
			return GeneralRegisterString[SIXTEEN_BIT((int)schema.generalRegister - (int)GeneralRegister::A)];
		case Size::d:
			return GeneralRegisterString[THIRTYTWO_BIT((int)schema.generalRegister - (int)GeneralRegister::A)];
		case Size::v:
			if (HasOperandPrefix())
				return GeneralRegisterString[SIXTEEN_BIT((int)schema.generalRegister - (int)GeneralRegister::A)];
			else
				return GeneralRegisterString[THIRTYTWO_BIT((int)schema.generalRegister - (int)GeneralRegister::A)];
		default:
			return "ERROR";
	}
}
const char * Operand::GetFixedSegmentRegisterString()
{
	return SegmentRegisterString[(int)schema.segmentRegister - (int)SegmentRegister::ES];
}
const char * Operand::GetFixedConstantString()
{
	return ConstantString[(int)schema.constant - (int)Constant::ONE];
}
const char * Operand::GetSizeString()
{
	switch (schema.operandSize)
	{
		case Size::b:
			return "BYTE PTR ";
		case Size::w:
			return "WORD PTR ";
		case Size::d:
			return "DWORD PTR ";
		case Size::v:
			if (HasOperandPrefix())
				return "WORD PTR ";
			else
				return "DWORD PTR ";
		case Size::a:
			if (HasOperandPrefix())
				return "DWORD PTR ";
			else
				return "QWORD PTR ";
		default:
			return "";
	}
}

#endif