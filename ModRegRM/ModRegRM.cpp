#include <cstdlib>
#include "./ModRegRM.h"
#include "../SIB/SIB.h"
#include "../Operand/Operand.h"
#include "../DisassemblerFunctions.h"
#include "./ModRegRMStrings.h"

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
	switch (size)
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
		case Size::p:
			if (HasOperandPrefix())
				return "FWORD PTR ";
			else
				return "DWORD PTR ";
		default:
			return "";
	}
}
