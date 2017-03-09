#ifndef SIB_HEADER
#define SIB_HEADER

#include "../DisassemblerTypes.h"      //byte, word, dword, Peek<>(), Select<>()

#include "SIBEnums.h"                  //Scale, Index, Base
#include "SIBSchemas.h"                //SIBSchema, SIBSchemas
#include "SIBStrings.h"                //ScaleString, IndexString, BaseString

#include "../ModRegRM/ModRegRMEnums.h" //Mod

#include <sstream>                     //stringstream, hex
#include <iomanip>                     //setfill(), setw()

class SIB
{
public:
	SIB() {};
	SIB(byte * opcode, int * index, Mod mod)
	{
		value = Peek<byte>(opcode, index);

		SetSIBSchema(opcode, index);

		hasDisp = (mod == Mod::NoDisp) && (schema.base == Base::EBP);

		if (HasDisp())
			SetDisp(opcode, index);
	}

	bool HasIndex()
	{
		return schema.index != Index::_;
	}
	bool HasScale()
	{
		return schema.scale != Scale::ONE;
	}
	bool HasBase()
	{
		return !hasDisp;
	}
	bool HasDisp()
	{
		return hasDisp;
	}

	byte GetScaleValue()
	{
		return (value >> 6) & 0x3;
	}
	byte GetIndexValue()
	{
		return (value >> 3) & 0x7;
	}
	byte GetBaseValue()
	{
		return value & 0x7;
	}
	dword GetDispValue()
	{
		return disp32;
	}

	std::string GetScaleString()
	{
		return ScaleString[(int)schema.scale];
	}
	std::string GetIndexString()
	{
		return IndexString[(int)schema.index];
	}
	std::string GetBaseString()
	{
		return BaseString[(int)schema.base];
	}
	std::string GetDispString()
	{
		std::stringstream output;
		output << std::setfill('0') << std::setw(8) << std::hex << disp32 << "h";
		return output.str();
	}

	std::string GetString()
	{
		std::stringstream output;

		if (HasDisp())
			output << GetDispString();
		else if (HasBase())
			output << GetBaseString();

		if (HasIndex())
			output << " + " << GetIndexString();

		if (HasScale())
			output << " * " << GetScaleString();

		return output.str();
	}

private:
	SIBSchema schema;  //Contains SIB configuration for the opcode
	byte value;        //Contains the SIB opcode
	dword disp32;      //Only used if there is a 32-bit displacement
	bool hasDisp;      //Seperate value used to prevent write-access outside of class

	void SetSIBSchema(byte * opcode, int * index)
	{
		schema = SIBSchemas[Select<byte>(opcode, index)];
	}
	void SetDisp(byte * opcode, int * index)
	{
		disp32 = Select<dword>(opcode, index);
	}
};

#endif