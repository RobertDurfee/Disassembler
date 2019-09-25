#ifndef OPERAND_HEADER
#define OPERAND_HEADER

#include "../Instruction/Instruction.h"

class Operand
{
	friend class ModRegRM;

public:
	Operand() {};
	Operand(Instruction * instruction);

	char * GetString();

private:
	//Opcode buffer
	int * index = nullptr;
	byte * opcode = nullptr;

	//Caller
	Instruction * instruction = nullptr;
	int operandIndex = 0;

	//Schema
	OperandSchema schema = EmptyOperandSchema;

	//Optional fields
	ModRegRM * modRegRM = nullptr;
	byte imm8 = 0;
	word imm16 = 0;
	dword imm32 = 0;
	byte disp8 = 0;
	word disp16 = 0;
	dword disp32 = 0;
	word sel16 = 0;
	byte addr8 = 0;
	word addr16 = 0;
	dword addr32 = 0;

	//Testers
	bool HasAddressPrefix();
	bool HasOperandPrefix();
	bool HasSegmentPrefix();
	bool HasModRegRM();
	bool HasImmediate();
	bool HasRelativeDisplacement();
	bool HasMemoryDisplacement();
	bool HasDirectAddress();
	bool HasModRM();
	bool HasGeneralRegister();
	bool HasSegmentRegister();
	bool HasFixedAddress();
	bool HasFixedGeneralRegister();
	bool HasFixedSegmentRegsiter();
	bool HasFixedConstant();

	//Setters
	void SetSchema();
	void SetModRegRM();
	void SetImmediate();
	void SetRelativeDisplacement();
	void SetMemoryDisplacement();
	void SetDirectAddress();

	//Getters
	const char * GetSegmentPrefixString();
	char * GetImmediateString();
	char * GetRelativeDisplacementString();
	char * GetMemoryDisplacementString();
	char * GetDirectAddressString();
	char * GetModRMString();
	char * GetGeneralRegisterString();
	char * GetSegmentRegsiterString();
	char * GetFixedAddressString();
	const char * GetFixedGeneralRegisterString();
	const char * GetFixedSegmentRegisterString();
	const char * GetFixedConstantString();
	const char * GetSizeString();
};

#endif
