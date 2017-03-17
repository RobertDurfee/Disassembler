#ifndef OPERATOR_HEADER
#define OPERATOR_HEADER

//#include "../Instruction/Instruction.h" //Instruction (Due to circular include dependency, this must be commented out.)

#include "OperatorStrings.h"              //MnemonicString
#include "OperatorSchemas.h"              //OperatorSchema, EmptyOperatorSchema

class Operator
{
public:
	Operator() {};
	Operator(Instruction * instruction);

	const char * GetString();

private:
	//Caller
	Instruction * instruction = nullptr;

	//Schema
	OperatorSchema schema = EmptyOperatorSchema;
};

Operator::Operator(Instruction * instruction) : instruction(instruction)
{
	schema = instruction->schema.operatorSchema;
}

const char * Operator::GetString()
{
	return MnemonicString[(int)schema.mnemonic];
}

#endif