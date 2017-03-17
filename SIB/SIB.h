#ifndef SIB_HEADER
#define SIB_HEADER

#include "../DisassemblerTypes.h"      //byte, dword
#include "../DisassemblerFunctions.h"  //Append(), Select<>()

#include "SIBEnums.h"                  //Scale, Index, Base
#include "SIBStrings.h"                //ScaleString, IndexString, BaseString
#include "SIBSchemas.h"                //SIBSchema, EmptySIBSchema, SIBSchemas

#include "../ModRegRM/ModRegRMEnums.h" //Mod
//#include "../ModRegRM/ModRegRM.h"    //ModRegRM (Due do circular include dependency, this must be commented out.)

#include <stdlib.h>                    //malloc(), free()
#include <string.h>                    //memcpy()

class SIB
{
public:
	SIB() {};
	SIB(ModRegRM * modRegRM);

	~SIB();

	char * GetString();

private:
	//Opcode buffer
	byte * opcode = nullptr;
	int * index = nullptr;

	//Caller
	ModRegRM * modRegRM = nullptr;

	//Schema
	SIBSchema schema = EmptySIBSchema;

	//Optional fields
	dword disp32 = 0;

	//Hexadecimal opcode values
	byte * value = nullptr;
	int valueSize = 0;

	//Testers
	bool HasScale();
	bool HasIndex();
	bool HasBase();
	bool HasDisplacement();

	//Setters
	void SetSchema();
	void SetDisplacement();
	void SetValue(int startingIndex);

	//Getters
	const char * GetScaleString();
	const char * GetIndexString();
	const char * GetBaseString();
	char * GetDisplacementString();
};

SIB::SIB(ModRegRM * modRegRM) : modRegRM(modRegRM), opcode(modRegRM->opcode), index(modRegRM->index)
{
	int startingIndex = *index;

	SetSchema();

	if (HasDisplacement())
		SetDisplacement();

	SetValue(startingIndex);
}

SIB::~SIB()
{
	free(value);
}

char * SIB::GetString()
{
	char * output = nullptr;

	if (HasDisplacement())
		Append(&output, GetDisplacementString());
	else
		Append(&output, GetBaseString());

	if (HasIndex())
	{
		Append(&output, " + ");
		Append(&output, GetIndexString());
	}

	if (HasScale())
	{
		Append(&output, " * ");
		Append(&output, GetScaleString());
	}

	return output;
}

bool SIB::HasScale()
{
	return schema.scale != Scale::ONE;
}
bool SIB::HasIndex()
{
	return schema.index != Index::_;
}
bool SIB::HasBase()
{
	return !HasDisplacement();
}
bool SIB::HasDisplacement()
{
	return (modRegRM->schema.mod == Mod::NoDisp) && (schema.base == Base::EBP);
}

void SIB::SetSchema()
{
	schema = SIBSchemas[Select<byte>(opcode, index)];
}
void SIB::SetDisplacement()
{
	disp32 = Select<dword>(opcode, index);
}
void SIB::SetValue(int startingIndex)
{
	valueSize = *index - startingIndex;

	value = (byte *)malloc(valueSize);

	memcpy(value, &opcode[startingIndex], valueSize);
}

const char * SIB::GetScaleString()
{
	return ScaleString[(int)schema.scale];
}
const char * SIB::GetIndexString()
{
	return IndexString[(int)schema.index];
}
const char * SIB::GetBaseString()
{
	return BaseString[(int)schema.base];
}
char * SIB::GetDisplacementString()
{
	char * output = nullptr;

	Append(&output, "%08Xh", disp32);

	return output;
}

#endif