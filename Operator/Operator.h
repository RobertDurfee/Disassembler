#ifndef OPERATOR_HEADER
#define OPERATOR_HEADER

#include "../Instruction/Instruction.h"

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

#endif
