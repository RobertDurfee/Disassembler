#ifndef MOD_REG_RM_HEADER
#define MOD_REG_RM_HEADER

#include "../DisassemblerTypes.h"                             //byte, word, dword, Peek<>(), Select<>()

#include "ModRegRMEnums.h"                                    //Mod, Reg, RM, Size
#include "ModRegRMSchemas.h"                                  //ModRegRMSchema, ModRegRMSchemas
#include "ModRegRMStrings.h"                                  //RegString, RMString

#include "../SIB/SIB.h"                                       //SIB

#include "../Instruction/Operator/InstructionOperatorEnums.h" //Prefix

class ModRegRM
{
public:
	ModRegRM() {};
	ModRegRM(byte * opcode, int * index, Prefix prefixes)
	{
		value = Peek<byte>(opcode, index);

		SetModRegRMSchema(opcode, index);

		hasAddressPrefix = ((int)prefixes & (int)Prefix::ADDRESS);
		hasOperandPrefix = ((int)prefixes & (int)Prefix::OPERAND);

		if (HasSIB())
			SetSIB(opcode, index);

		if (HasDisp())
			SetDisp(opcode, index);
	}

	bool HasAddressPrefix()
	{
		return hasAddressPrefix;
	}
	bool HasOperandPrefix()
	{
		return hasOperandPrefix;
	}
	bool HasSIB()
	{
		return (schema.rm == RM::SIB) && !HasAddressPrefix();
	}
	bool HasDisp()
	{
		return (schema.rm16 == RM::Disp && HasAddressPrefix()) || (schema.rm == RM::Disp && !HasAddressPrefix()) || (schema.mod == Mod::Disp);
	}

	byte GetModValue()
	{
		return (value >> 6) & 0x3;
	}
	byte GetRegValue()
	{
		return (value >> 3) & 0x7;
	}
	byte GetRMValue()
	{
		return value & 0x7;
	}
	byte GetModRMValue()
	{
		return ((value >> 3) & 0x18) | (value & 0x7);
	}
	byte GetOpcodeExtensionValue()
	{
		return (value >> 3) & 0x7;
	}
	Size GetDispSize()
	{
		return dispSize;
	}
	template<typename T>
	T GetDispValue()
	{
		switch (dispSize)
		{
			case Size::b:
				return disp8;
			case Size::w:
				return disp16;
			case Size::d:
				return disp32;
		}
	}
	SIB GetSIBValue()
	{
		return sib;
	}

	std::string GetModRMString(Size size)
	{
		switch (size)
		{
			case Size::b:
				break;
			case Size::v:
				break;
			case Size::w:
				break;
		}
	}
	std::string GetRegString(Size size)
	{
		switch (size)
		{
			case Size::b:
				return RegString[(int)schema.reg];
				break;
			case Size::v:
				if (HasOperandPrefix())
					return RegString[(int)schema.reg + (8 * 1)];
				else if (!HasOperandPrefix())
					return RegString[(int)schema.reg + (8 * 2)];
				break;
			case Size::w:
				return RegString[(int)schema.reg + (8 * 1)];
				break;
		}
	}

private:
	ModRegRMSchema schema; //Contains the ModRegRM configuration for the opcode
	byte value;            //Contains the ModRegRM opcode
	SIB sib;               //Optional scale index base byte
	union                  //Optional displacement
	{
		byte disp8;        //8-bit version
		word disp16;       //16-bit version
		dword disp32;      //32-bit version
	};
	Size dispSize;         //Represents the size of the displacement stored in the union above
	bool hasOperandPrefix; //Seperate value used to prevent write-access outside of class
	bool hasAddressPrefix; //Seperate value used to prevent write-access outside of class

	void SetModRegRMSchema(byte * opcode, int * index)
	{
		schema = ModRegRMSchemas[Select<byte>(opcode, index)];
	}
	void SetSIB(byte * opcode, int * index)
	{
		sib = SIB(opcode, index, schema.mod);
	}
	void SetDisp(byte * opcode, int * index)
	{
		if (HasRMDisp())
			SetModDisp(opcode, index);
		else if (HasModDisp())
			SetRMDisp(opcode, index);
	}

	bool HasModDisp()
	{
		return schema.mod == Mod::Disp;
	}
	bool HasRMDisp()
	{
		return (schema.rm16 == RM::Disp && HasAddressPrefix()) || (schema.rm == RM::Disp && !HasAddressPrefix());
	}
	void SetModDisp(byte * opcode, int * index)
	{
		switch (schema.modSize)
		{
			case Size::b:
				disp8 = Select<byte>(opcode, index);
				dispSize = Size::b;
				break;
			case Size::v:
				if (HasAddressPrefix())
				{
					disp16 = Select<word>(opcode, index);
					dispSize = Size::w;
				}

				else if (!HasAddressPrefix())
				{
					disp32 = Select<dword>(opcode, index);
					dispSize = Size::d;
				}
				break;
		}
	}
	void SetRMDisp(byte * opcode, int * index)
	{
		if (HasAddressPrefix())
		{
			disp16 = Select<word>(opcode, index);
			dispSize = Size::w;
		}
		else if (!HasAddressPrefix())
		{
			disp32 = Select<dword>(opcode, index);
			dispSize = Size::d;
		}
	}
};

#endif