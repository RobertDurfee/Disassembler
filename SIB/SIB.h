#ifndef SIB_HEADER
#define SIB_HEADER

#include "./SIBSchemas.h"
#include "../ModRegRM/ModRegRM.h"

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

#endif
