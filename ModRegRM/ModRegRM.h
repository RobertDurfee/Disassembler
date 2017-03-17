#ifndef MOD_REG_RM_HEADER
#define MOD_REG_RM_HEADER

#include "../DisassemblerTypes.h"         //byte, word, dword
#include "../DisassemblerFunctions.h"     //Append(), Select<>()

//#include "../Operand/Operand.h"         //Operand (Due to circular include dependency, this must be commented out.)
//#include "../Instruction/Instruction.h" //Instruction (Due to circular include dependency, this must be commented out.)

#include "ModRegRMEnums.h"                //Mod, Reg, RM, Size
#include "ModRegRMStrings.h"              //GeneralRegisterString, RMString, SegmentRegisterString, EIGHT_BIT, SIXTEEN_BIT, THIRTYTWO_BIT
#include "ModRegRMSchemas.h"              //ModRegRMSchema, EmptyModRegRMSchema, ModRegRMSchemas

#include <stdlib.h>                       //malloc(), free()
#include <string.h>                       //memcpy()

class ModRegRM
{
	friend class SIB; //Needs: opcode, index, schema.mod

public:
	ModRegRM() {};
	ModRegRM(Instruction * instruction);

	~ModRegRM();

	char * GetString(Operand * operand);

	byte GetOpcodeExtensionValue();

private:
	//Opcode buffer
	byte * opcode = nullptr;
	int * index = nullptr;

	//Caller
	Instruction * instruction = nullptr;
	Operand * operand = nullptr;
	Size size = Size::_;

	//Schema
	ModRegRMSchema schema = EmptyModRegRMSchema;

	//Optional fields
	SIB * sib = nullptr;
	byte disp8 = 0;
	word disp16 = 0;
	dword disp32 = 0;

	//Hexadecimal opcode values
	byte * value = nullptr;
	int valueSize = 0;

	//Testers
	bool HasAddressPrefix();
	bool HasOperandPrefix();
	bool HasSegmentPrefix();
	bool HasSIB();
	bool HasDisplacement();
	bool HasModDisplacement();
	bool HasRMDisplacement();
	bool HasModRM();
	bool HasGeneralRegister();
	bool HasSegmentRegister();

	//Setters
	void SetSchema();
	void SetSIB();
	void SetDisplacement();
	void SetModDisplacement();
	void SetRMDisplacement();
	void SetValue(int startingIndex);

	//Getters
	const char * GetSegmentPrefixString();
	char * GetSIBString();
	char * GetModDisplacementString();
	char * GetRMDisplacementString();
	char * GetModRMString();
	const char * GetRMAddressString();
	const char * GetRMRegisterString();
	const char * GetGeneralRegisterString();
	const char * GetSegmentRegisterString();
	const char * GetSizeString();
};

#include "../SIB/SIB.h" //SIB (Due to circular include dependency, this must be placed here.)

ModRegRM::ModRegRM(Instruction * instruction) : instruction(instruction), opcode(instruction->opcode), index(instruction->index)
{
	int startingIndex = *index;

	SetSchema();

	if (HasSIB())
		SetSIB();

	if (HasDisplacement())
		SetDisplacement();

	SetValue(startingIndex);
}

ModRegRM::~ModRegRM()
{
	delete sib;
	free(value);
}

char * ModRegRM::GetString(Operand * operand)
{
	this->operand = operand;
	size = operand->schema.operandSize;

	char * output = nullptr;

	if (HasModRM())
		Append(&output, GetModRMString());
	else if (HasGeneralRegister())
		Append(&output, GetGeneralRegisterString());
	else if (HasSegmentRegister())
		Append(&output, GetSegmentRegisterString());
	else
		Append(&output, "ERROR");

	return output;
}

byte ModRegRM::GetOpcodeExtensionValue()
{
	return (value[0] >> 3) & 0x7;
}

bool ModRegRM::HasAddressPrefix()
{
	return instruction->HasAddressPrefix();
}
bool ModRegRM::HasOperandPrefix()
{
	return instruction->HasOperandPrefix();
}
bool ModRegRM::HasSegmentPrefix()
{
	return instruction->HasSegmentPrefix();
}
bool ModRegRM::HasSIB()
{
	return (schema.rm == RM::SIB) && !HasAddressPrefix();		
}
bool ModRegRM::HasDisplacement()
{
	return HasModDisplacement() || HasRMDisplacement();
}
bool ModRegRM::HasModDisplacement()
{
	return schema.mod == Mod::Disp;
}
bool ModRegRM::HasRMDisplacement()
{
	return (schema.rm16 == RM::Disp && HasAddressPrefix()) || (schema.rm == RM::Disp && !HasAddressPrefix());
}
bool ModRegRM::HasModRM()
{
	return operand->HasModRM();
}
bool ModRegRM::HasGeneralRegister()
{
	return operand->HasGeneralRegister();
}
bool ModRegRM::HasSegmentRegister()
{
	return operand->HasSegmentRegister();
}

void ModRegRM::SetSchema()
{
	schema = ModRegRMSchemas[Select<byte>(opcode, index)];
}
void ModRegRM::SetSIB()
{
	sib = new SIB(this);
}
void ModRegRM::SetDisplacement()
{
	if (HasModDisplacement())
		SetModDisplacement();
	else if (HasRMDisplacement())
		SetRMDisplacement();
}
void ModRegRM::SetModDisplacement()
{
	switch (schema.modSize)
	{
		case Size::b:
			disp8 = Select<byte>(opcode, index);
			break;
		case Size::v:
			if (HasAddressPrefix())
				disp16 = Select<word>(opcode, index);
			else
				disp32 = Select<dword>(opcode, index);
			break;
	}
}
void ModRegRM::SetRMDisplacement()
{
	if (HasAddressPrefix())
		disp16 = Select<word>(opcode, index);
	else
		disp32 = Select<dword>(opcode, index);
}
void ModRegRM::SetValue(int startingIndex)
{
	valueSize = *index - startingIndex;

	value = (byte *)malloc(valueSize);

	memcpy(value, &opcode[startingIndex], valueSize);
}

const char * ModRegRM::GetSegmentPrefixString()
{
	return instruction->GetSegmentPrefixString();
}
char * ModRegRM::GetSIBString()
{
	return sib->GetString();
}
char * ModRegRM::GetModDisplacementString()
{
	char * output = nullptr;

	switch (schema.modSize)
	{
		case Size::b:
			Append(&output, "%02Xh", disp8);
			break;
		case Size::v:
			if (HasAddressPrefix())
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
char * ModRegRM::GetRMDisplacementString()
{
	char * output = nullptr;

	if (HasAddressPrefix())
		Append(&output, "%04Xh", disp16);
	else
		Append(&output, "%08Xh", disp32);

	return output;
}
char * ModRegRM::GetModRMString()
{
	char * output = nullptr;

	switch (schema.mod)
	{
		case Mod::NoDisp:
			Append(&output, GetSizeString());

			if (HasSegmentPrefix())
				Append(&output, GetSegmentPrefixString());

			Append(&output, "[");

			if (HasRMDisplacement())
				Append(&output, GetRMDisplacementString());
			else if (HasSIB())
				Append(&output, sib->GetString());
			else
				Append(&output, GetRMAddressString());

			Append(&output, "]");

			break;
		case Mod::Disp:
			Append(&output, GetSizeString());

			if (HasSegmentPrefix())
				Append(&output, GetSegmentPrefixString());

			Append(&output, "[");

			if (HasSIB())
				Append(&output, sib->GetString());
			else
				Append(&output, GetRMAddressString());

			Append(&output, " + ");

			Append(&output, GetModDisplacementString());

			Append(&output, "]");

			break;
		case Mod::Reg:
			Append(&output, GetRMRegisterString());
			break;
		default:
			Append(&output, "ERROR");
			break;
	}

	return output;
}
const char * ModRegRM::GetRMAddressString()
{
	if (HasAddressPrefix())
		return RMString[SIXTEEN_BIT((int)schema.rm16 - (int)RM::A)];
	else
		return RMString[THIRTYTWO_BIT((int)schema.rm - (int)RM::A)];
}
const char * ModRegRM::GetRMRegisterString()
{
	switch (size)
	{
		case Size::b:
			return GeneralRegisterString[EIGHT_BIT((int)schema.rm - (int)RM::A)];
		case Size::w:
			return GeneralRegisterString[SIXTEEN_BIT((int)schema.rm - (int)RM::A)];
		case Size::d:
			return GeneralRegisterString[THIRTYTWO_BIT((int)schema.rm - (int)RM::A)];
		case Size::v:
			if (HasOperandPrefix())
				return GeneralRegisterString[SIXTEEN_BIT((int)schema.rm - (int)RM::A)];
			else
				return GeneralRegisterString[THIRTYTWO_BIT((int)schema.rm - (int)RM::A)];
		default:
			return "ERROR";
	}
}
const char * ModRegRM::GetGeneralRegisterString()
{
	switch (size)
	{
		case Size::b:
			return GeneralRegisterString[EIGHT_BIT((int)schema.reg - (int)Reg::A)];
		case Size::w:
			return GeneralRegisterString[SIXTEEN_BIT((int)schema.reg - (int)Reg::A)];
		case Size::d:
			return GeneralRegisterString[THIRTYTWO_BIT((int)schema.reg - (int)Reg::A)];
		case Size::v:
			if (HasOperandPrefix())
				return GeneralRegisterString[SIXTEEN_BIT((int)schema.reg - (int)Reg::A)];
			else
				return GeneralRegisterString[THIRTYTWO_BIT((int)schema.reg - (int)Reg::A)];
		default:
			return "ERROR";
	}
}
const char * ModRegRM::GetSegmentRegisterString()
{
	return SegmentRegisterString[(int)schema.reg - (int)Reg::A];
}
const char * ModRegRM::GetSizeString()
{
	return operand->GetSizeString();
}

#endif
