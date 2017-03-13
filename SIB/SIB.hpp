#ifndef SIB_HEADER
#define SIB_HEADER

#include "../DisassemblerTypes.hpp"    //byte, word, dword, Peek<>(), Select<>()

#include "SIBEnums.h"                  //Scale, Index, Base
#include "SIBSchemas.h"                //SIBSchema, SIBSchemas
#include "SIBStrings.h"                //ScaleString, IndexString, BaseString

#include "../ModRegRM/ModRegRMEnums.h" //Mod

#include <sstream>                     //stringstream, hex
#include <iomanip>                     //setfill(), setw()

#include <vector>                      //std::vector

class SIB
{
public:
	SIB() {};
	SIB(byte * opcode, int * index, Mod mod)
	{
		int startingIndex = *index;
		
		SetSIBSchema(opcode, index);

		hasDisp = (mod == Mod::NoDisp) && (schema.base == Base::EBP);

		if (HasDisp())
			SetDisp(opcode, index);

		SetValue(opcode, &startingIndex, index);
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
		return (value[0] >> 6) & 0x3;
	}
	byte GetIndexValue()
	{
		return (value[0] >> 3) & 0x7;
	}
	byte GetBaseValue()
	{
		return value[0] & 0x7;
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
	SIBSchema schema = EmptySIBSchema; //Contains SIB configuration for the opcode
	std::vector<byte> value;           //Contains the SIB opcodes
	dword disp32 = 0;                  //Only used if there is a 32-bit displacement
	bool hasDisp = false;              //Seperate value used to prevent write-access outside of class

	void SetSIBSchema(byte * opcode, int * index)
	{
		schema = SIBSchemas[Select<byte>(opcode, index)];
	}
	void SetDisp(byte * opcode, int * index)
	{
		disp32 = Select<dword>(opcode, index);
	}

	void SetValue(byte * opcode, int * startingIndex, int * endingIndex)
	{
		while (*startingIndex != *endingIndex)
			value.push_back(Select<byte>(opcode, startingIndex));
	}
};

#endif