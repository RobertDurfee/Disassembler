#ifndef INSTRUCTION_HEADER
#define INSTRUCTION_HEADER

#include "../DisassemblerTypes.h" //byte, word, dword

#include "InstructionSchemas.h"   //InstructionSchema, InstructionSchemas

#include "../ModRegRM/ModRegRM.h" //ModRegRM

#include <vector>                 //std::vector

class Instruction
{
public:
	Instruction() {};
	Instruction(byte * opcode, int * index)
	{
		int startingIndex = *index;

		SetInstructionSchema(opcode, index);

		for (int operand = 0; operand < NUMBER_OF_OPERANDS; operand++)
		{
			if (IsModRegRM(operand) && !HasModRegRM())
				SetModRegRM(opcode, index);

			else if (IsImmediate(operand))
				SetImmediate(operand, opcode, index);

			else if (IsRelativeDisplacement(operand))
				SetRelativeDisplacement(operand, opcode, index);

			else if (IsMemoryDisplacement(operand))
				SetMemoryDisplacement(operand, opcode, index);

			else if (IsDirectAddress(operand))
				SetDirectAddress(operand, opcode, index);
		}

		SetValue(opcode, &startingIndex, index);
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
		return hasModregrm;
	}
	bool HasOperandPrefix()
	{
		return ((int)prefixes & (int)Prefix::OPERAND) != 0;
	}
	bool HasAddressPrefix()
	{
		return ((int)prefixes & (int)Prefix::ADDRESS) != 0;
	}
	bool HasSegmentPrefix()
	{
		if ((int)prefixes & (int)Prefix::ES)
			return true;
		if ((int)prefixes & (int)Prefix::CS)
			return true;
		if ((int)prefixes & (int)Prefix::SS)
			return true;
		if ((int)prefixes & (int)Prefix::DS)
			return true;
		if ((int)prefixes & (int)Prefix::FS)
			return true;
		if ((int)prefixes & (int)Prefix::GS)
			return true;

		return false;
	}

	bool IsModRegRM(int operand)
	{
		return IsModRM(operand) || IsGeneralRegister(operand) || IsSegmentRegister(operand);
	}
	bool IsModRM(int operand)
	{
		return (schema.operands[operand].addressingMethod == AddressingMethod::E) || (schema.operands[operand].addressingMethod == AddressingMethod::M);
	}
	bool IsGeneralRegister(int operand)
	{
		return schema.operands[operand].addressingMethod == AddressingMethod::G;
	}
	bool IsSegmentRegister(int operand)
	{
		return schema.operands[operand].addressingMethod == AddressingMethod::S;
	}
	bool IsImmediate(int operand)
	{
		return (schema.operands[operand].addressingMethod == AddressingMethod::I);
	}
	bool IsRelativeDisplacement(int operand)
	{
		return (schema.operands[operand].addressingMethod == AddressingMethod::J);
	}
	bool IsMemoryDisplacement(int operand)
	{
		return (schema.operands[operand].addressingMethod == AddressingMethod::O);
	}
	bool IsDirectAddress(int operand)
	{
		return (schema.operands[operand].addressingMethod == AddressingMethod::A);
	}
	bool IsFixedAddress(int operand)
	{
		return (schema.operands[operand].addressingMethod == AddressingMethod::X) || (schema.operands[operand].addressingMethod == AddressingMethod::Y);
	}
	bool IsFixedGeneralRegister(int operand)
	{
		return (Register::A <= schema.operands[operand].register_) && (schema.operands[operand].register_ <= Register::DI);
	}
	bool IsFixedSegmentRegister(int operand)
	{
		return (SegmentRegister::ES <= schema.operands[operand].segmentRegister) && (schema.operands[operand].segmentRegister <= SegmentRegister::GS);
	}
	bool IsFixedConstant(int operand)
	{
		return (Constant::ONE <= schema.operands[operand].constant) && (schema.operands[operand].constant <= Constant::ONE);
	}
	
	std::string GetModRMString(int operand)
	{
		return modregrm.GetModRMString(schema.operands[operand].operandSize);
	}
	std::string GetGeneralRegisterString(int operand)
	{
		return modregrm.GetRegString(schema.operands[operand].operandSize);
	}
	std::string GetSegmentRegisterString(int operand)
	{
		return modregrm.GetRegString(schema.operands[operand].operandSize, true);
	}
	std::string GetImmediateString(int operand)
	{
		std::stringstream output;

		switch (schema.operands[operand].operandSize)
		{
			case Size::b:
				output << std::setfill('0') << std::setw(2) << std::uppercase << std::hex << (int)imm8;
				break;
			case Size::w:
				output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << imm16;
				break;
			case Size::d:
				output << std::setfill('0') << std::setw(8) << std::uppercase << std::hex << imm32;
				break;
			case Size::v:
				if (HasOperandPrefix())
					output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << imm16;
				else if (!HasAddressPrefix())
					output << std::setfill('0') << std::setw(8) << std::uppercase << std::hex << imm32;
				break;
		}

		output << "h";

		return output.str();
	}
	std::string GetRelativeDisplacementString(int operand)
	{
		std::stringstream output;

		switch (schema.operands[operand].operandSize)
		{
			case Size::b:
				output << std::setfill('0') << std::setw(2) << std::uppercase << std::hex << (int)disp8;
				break;
			case Size::w:
				output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << disp16;
				break;
			case Size::d:
				output << std::setfill('0') << std::setw(8) << std::uppercase << std::hex << disp32;
				break;
			case Size::v:
				if (HasOperandPrefix())
					output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << disp16;
				else if (!HasOperandPrefix())
					output << std::setfill('0') << std::setw(8) << std::uppercase << std::hex << disp32;
				break;
		}

		output << "h";

		return output.str();
	}
	std::string GetMemoryDisplacementString(int operand)
	{
		std::stringstream output;

		if (HasSegmentPrefix())
			output << GetSegmentPrefixString();
		else if (!HasSegmentPrefix())
			output << "DS:";

		if (HasAddressPrefix())
			output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << disp16;
		else if (!HasAddressPrefix())
			output << std::setfill('0') << std::setw(8) << std::uppercase << std::hex << disp32;

		output << "h";

		return output.str();
	}
	std::string GetDirectAddressString(int operand)
	{
		std::stringstream output;

		output << GetSizeString(schema.operands[operand].operandSize);
		
		output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << sel16 << "h:";

		if (HasOperandPrefix())
			output << std::setfill('0') << std::setw(4) << std::uppercase << std::hex << addr16;
		else if (!HasOperandPrefix())
			output << std::setfill('0') << std::setw(8) << std::uppercase << std::hex << addr32;

		output << "h";

		return output.str();
	}
	std::string GetFixedAddressString(int operand)
	{
		std::stringstream output;

		output << GetSizeString(schema.operands[operand].operandSize);

		switch (schema.operands[operand].addressingMethod)
		{
			case AddressingMethod::X:
				if (HasSegmentPrefix())
				{
					output << GetSegmentPrefixString();
					if (HasOperandPrefix())
						output << "[SI]";
					else if (!HasOperandPrefix())
						output << "[ESI]";
				}
				else if (!HasSegmentPrefix())
				{
					if (HasOperandPrefix())
						output << "DS:[SI]";
					else if (!HasOperandPrefix())
						output << "DS:[ESI]";
				}
				break;
			case AddressingMethod::Y:
				if (HasOperandPrefix())
					output << "ES:[DI]";
				else if (!HasOperandPrefix())
					output << "ES:[EDI]";
				break;
		}

		return output.str();
	}
	std::string GetFixedGeneralRegisterString(int operand)
	{
		switch (schema.operands[operand].operandSize)
		{
			case Size::b:
				return RegisterString[EIGHT_BIT ((int)schema.operands[operand].register_ - (int)Register::A)];
				break;
			case Size::w:
				return RegisterString[SIXTEEN_BIT ((int)schema.operands[operand].register_ - (int)Register::A)];
				break;
			case Size::d:
				return RegisterString[THIRTYTWO_BIT ((int)schema.operands[operand].register_ - (int)Register::A)];
				break;
			case Size::v:
				if (HasOperandPrefix())
					return RegisterString[SIXTEEN_BIT ((int)schema.operands[operand].register_ - (int)Register::A)];
				else if (!HasOperandPrefix())
					return RegisterString[THIRTYTWO_BIT ((int)schema.operands[operand].register_ - (int)Register::A)];
				break;
		}
	}
	std::string GetFixedSegmentRegisterString(int operand)
	{
		return SegmentRegisterString[(int)schema.operands[operand].segmentRegister - (int)SegmentRegister::ES];
	}
	std::string GetFixedConstantString(int operand)
	{
		return ConstantString[(int)schema.operands[operand].constant - (int)Constant::ONE];
	}
	std::string GetSegmentPrefixString()
	{
		std::stringstream output;

		if ((int)prefixes & (int)Prefix::ES)
			output << SegmentRegisterString[(int)SegmentRegister::ES - (int)SegmentRegister::ES] << ":";
		else if ((int)prefixes & (int)Prefix::CS)
			output << SegmentRegisterString[(int)SegmentRegister::CS - (int)SegmentRegister::ES] << ":";
		else if ((int)prefixes & (int)Prefix::SS)
			output << SegmentRegisterString[(int)SegmentRegister::SS - (int)SegmentRegister::ES] << ":";
		else if ((int)prefixes & (int)Prefix::DS)
			output << SegmentRegisterString[(int)SegmentRegister::DS - (int)SegmentRegister::ES] << ":";
		else if ((int)prefixes & (int)Prefix::FS)
			output << SegmentRegisterString[(int)SegmentRegister::FS - (int)SegmentRegister::ES] << ":";
		else if ((int)prefixes & (int)Prefix::GS)
			output << SegmentRegisterString[(int)SegmentRegister::GS - (int)SegmentRegister::ES] << ":";

		return output.str();
	}

	std::string GetOperatorString()
	{
		std::stringstream output;

		output << MnemonicString[(int)schema.operator_.mnemonic];

		return output.str();
	}
	std::string GetOperandString(int operand)
	{
		if (IsModRM(operand))
			return GetModRMString(operand);

		else if (IsGeneralRegister(operand))
			return GetGeneralRegisterString(operand);

		else if (IsSegmentRegister(operand))
			return GetSegmentRegisterString(operand);

		else if (IsImmediate(operand))
			return GetImmediateString(operand);

		else if (IsRelativeDisplacement(operand))
			return GetRelativeDisplacementString(operand);

		else if (IsMemoryDisplacement(operand))
			return GetMemoryDisplacementString(operand);

		else if (IsDirectAddress(operand))
			return GetDirectAddressString(operand);

		else if (IsFixedAddress(operand))
			return GetFixedAddressString(operand);

		else if (IsFixedGeneralRegister(operand))
			return GetFixedGeneralRegisterString(operand);

		else if (IsFixedSegmentRegister(operand))
			return GetFixedSegmentRegisterString(operand);

		else if (IsFixedConstant(operand))
			return GetFixedConstantString(operand);
	}
	std::string GetOperandsString()
	{
		std::stringstream output;

		int operand = 0;

		while (schema.operands[operand].addressingMethod != AddressingMethod::_ && operand < NUMBER_OF_OPERANDS)
			output << GetOperandString(operand++) << ", ";

		return output.str().substr(0, output.str().length() - 2);
	}
	std::string GetValueString()
	{
		std::stringstream output;

		for (int i = 0; i < (int)value.size() && i < 8; i++)
			if (i < 7)
				output << std::setfill('0') << std::setw(2) << std::uppercase << std::hex << (int)value[i] << " ";
			else
				output << "+ ";

		return output.str().substr(0, output.str().length() - 1);
	}

	std::string GetSizeString(Size size)
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
				else if (!HasOperandPrefix())
					return "DWORD PTR ";
			case Size::a:
				if (HasOperandPrefix())
					return "DWORD PTR ";
				else if (!HasOperandPrefix())
					return "QWORD PTR ";
			default:
				return "";
		}
	}

	std::string GetString()
	{
		std::stringstream output;

		output << std::setw(23) << std::left << GetValueString() << " ";

		output << std::setw(6) << std::left << GetOperatorString() << " ";

		output << GetOperandsString();

		return output.str();
	}

private:
	InstructionSchema schema = EmptyInstructionSchema; //Contains the Instruction configuration for the opcode
	ModRegRM modregrm;                                 //Optional ModRegRM byte
	bool hasModregrm = false;                          //Flag that remembers if the ModRegRM byte has been set
	Prefix prefixes = Prefix::_;                       //Optional instruction prefixes
	std::vector<byte> value;                           //Contains the Instruction opcodes
	bool hasGroup = false;                             //Flag that remembers if instruction belongs to a group
	union                                              //Optional immediate(s)
	{
		struct                                         //8-bit and 16-bit immediates can be accessed at same time
		{
			byte imm8;                                 //8-bit immediate
			word imm16;                                //16-bit immediate
		};
		dword imm32 = 0;                               //32-bit immediate (can't be accessed with 8-bit and 16-bit immediates)
	};
	union                                              //Optional displacement
	{
		byte disp8;                                    //8-bit displacement
		word disp16;                                   //16-bit displacement
		dword disp32 = 0;                              //32-bit displacement
	};
	struct                                             //Optional direct address
	{
		word sel16 = 0;                                //16-bit direct address segement selector
		union
		{
			byte addr8;                                //8-bit direct address (Not used)
			word addr16;                               //16-bit direct address
			dword addr32 = 0;                          //32-bit direct address
		};
	};

	void SetInstructionSchema(byte * opcode, int * index)
	{
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
		prefixes = (Prefix)((int)prefixes | (int)schema.operator_.prefix);
	}
	void SetModRegRM(byte * opcode, int * index)
	{
		hasModregrm = true;
		modregrm = ModRegRM(opcode, index, (Prefix)prefixes);
	}

	void SetImmediate(int operand, byte * opcode, int * index)
	{
		switch (schema.operands[operand].operandSize)
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
			else if (!HasOperandPrefix())
				imm32 = Select<dword>(opcode, index);
			break;
		}
	}
	void SetRelativeDisplacement(int operand, byte * opcode, int * index)
	{
		switch (schema.operands[operand].operandSize)
		{
		case Size::b:
			disp8 = Select<byte>(opcode, index);
			break;
		case Size::v:
			if (HasOperandPrefix())
				disp16 = Select<word>(opcode, index);
			else if (!HasOperandPrefix())
				disp32 = Select<dword>(opcode, index);
			break;
		}

		disp32 += *index;
	}
	void SetMemoryDisplacement(int operand, byte * opcode, int * index)
	{
		if (HasAddressPrefix())
			disp16 = Select<word>(opcode, index);
		else if (!HasAddressPrefix())
			disp32 = Select<dword>(opcode, index);
	}
	void SetDirectAddress(int operand, byte * opcode, int * index)
	{
		if (HasOperandPrefix())
			addr16 = Select<word>(opcode, index);
		else if (!HasOperandPrefix())
			addr32 = Select<dword>(opcode, index);

		sel16 = Select<word>(opcode, index);
	}

	void SetValue(byte * opcode, int * startingIndex, int * endingIndex)
	{
		while (*startingIndex != *endingIndex)
			value.push_back(Select<byte>(opcode, startingIndex));
	}
};

#endif