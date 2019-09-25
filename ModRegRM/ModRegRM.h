#ifndef MOD_REG_RM_HEADER
#define MOD_REG_RM_HEADER

#include "../Instruction/Instruction.h"
#include "./ModRegRMSchemas.h"

class SIB;

class ModRegRM
{
	friend class SIB;

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

	//Callers
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

#endif
