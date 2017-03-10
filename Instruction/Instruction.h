#ifndef INSTRUCTION_HEADER
#define INSTRUCTION_HEADER

#include "../DisassemblerTypes.h" //byte, word, dword

#include "InstructionSchemas.h"   //InstructionSchema, InstructionSchemas

#include "../ModRegRM/ModRegRM.h" //ModRegRM

#include <vector>                 //std::vector

class Instruction
{
public:
	Instruction(byte * opcode, int * index)
	{
		SetInstructionSchema(opcode, index);

		if (!HasGroup() && HasModRegRM)
			SetModRegRM(opcode, index);

		if (HasImmediate())
			SetImmediate(opcode, index);

		if (HasDisplacement())
			SetDisplacement(opcode, index);
	}

	bool HasPrefix()
	{
		return (Prefix::ES <= schema.operator_.prefix) && (schema.operator_.prefix <= Prefix::REPE);
	}
	bool HasGroup()
	{
		return ((Group::Immediate <= schema.operator_.group) && (schema.operator_.group <= Group::TwoByte)) || hasGroup;
	}
	bool HasModRegRM()
	{
		for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
			if ((schema.operands[i].addressingMethod == AddressingMethod::D) || (schema.operands[i].addressingMethod == AddressingMethod::E) || (schema.operands[i].addressingMethod == AddressingMethod::G) || (schema.operands[i].addressingMethod == AddressingMethod::M) || (schema.operands[i].addressingMethod == AddressingMethod::S))
				return true;
		return (false || hasGroup);
	}
	bool HasImmediate()
	{
		for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
			if (schema.operands[i].addressingMethod == AddressingMethod::I)
				return true;
		return false;
	}
	bool HasDisplacement()
	{
		for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
			if ((schema.operands[i].addressingMethod == AddressingMethod::J) || (schema.operands[i].addressingMethod == AddressingMethod::O) || (schema.operands[i].addressingMethod == AddressingMethod::A))
				return true;
		return false;
	}
	bool HasOperandPrefix()
	{
		return (prefixes & (int)Prefix::OPERAND) != 0;
	}
	bool HasAddressPrefix()
	{
		return (prefixes & (int)Prefix::ADDRESS) != 0;
	}

private:
	InstructionSchema schema;
	ModRegRM modregrm;
	int prefixes;
	std::vector<byte> value;
	bool hasGroup;
	union
	{
		struct
		{
			byte imm8;
			word imm16;
		};
		dword imm32;
	};
	union
	{
		byte disp8;
		word disp16;
		dword disp32;
	};
	word selector16;

	void SetInstructionSchema(byte * opcode, int * index)
	{
		value.push_back(Peek<byte>(opcode, index));
		schema = InstructionSchemas[Select<byte>(opcode, index)];

		if (HasPrefix())
		{
			SetPrefix();
			SetInstructionSchema(opcode, index);
		}
		else if (HasGroup())
		{
			SetModRegRM(opcode, index);
			SetGroupSchema();
		}
	} 
	void SetGroupSchema()
	{
		hasGroup = true;
		schema |= GroupSchemas[(int)schema.operator_.group - (int)Group::Immediate][modregrm.GetOpcodeExtensionValue()];
	}
	void SetPrefix()
	{
		prefixes |= (int)schema.operator_.prefix;
	}
	void SetModRegRM(byte * opcode, int * index)
	{
		modregrm = ModRegRM(opcode, index, (Prefix)prefixes);
	}

	void SetImmediate(byte * opcode, int * index)
	{
		for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
			if (schema.operands[i].addressingMethod == AddressingMethod::I)
				switch (schema.operands[i].operandSize)
				{
					case Size::b:
						imm8 = Select<byte>(opcode, index);
						break;
					case Size::w:
						imm16 = Select<word>(opcode, index);
						break;
					case Size::v:
					case Size::z:
						if (HasOperandPrefix())
							imm16 = Select<word>(opcode, index);
						else if (!HasOperandPrefix())
							imm32 = Select<dword>(opcode, index);
						break;
				}
	}
	void SetDisplacement(byte * opcode, int * index)
	{

	}
};

#endif