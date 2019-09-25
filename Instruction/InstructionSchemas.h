#ifndef INSTRUCTION_SCHEMAS_HEADER
#define INSTRUCTION_SCHEMAS_HEADER

#include "../Operator/OperatorSchemas.h"
#include "../Operand/OperandSchemas.h"

#define NUMBER_OF_OPERANDS 3

struct InstructionSchema
{
	OperatorSchema operatorSchema;

	OperandSchema operandSchema[NUMBER_OF_OPERANDS];
};

InstructionSchema& operator|=(InstructionSchema& left, const InstructionSchema& right);

extern const InstructionSchema EmptyInstructionSchema;

extern const InstructionSchema InstructionSchemas[0x100 /* 0x00 - 0xFF */];

extern const InstructionSchema GroupSchemas[5][0x8 /* 000 - 111 */];

#endif
