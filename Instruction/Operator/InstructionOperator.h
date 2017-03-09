#ifndef INSTRUCTION_OPERATOR_HEADER
#define INSTRUCTION_OPERATOR_HEADER

#include "InstructionOperatorEnums.h"
#include "InstructionOperatorStrings.h"

union Operator
{
	Operator() : mnemonic(Mnemonic::_) , prefix(Prefix::_) , group(Group::_) {};

	Operator(Mnemonic mnemonic) : mnemonic(mnemonic) {};
	Operator(Prefix prefix)     : prefix(prefix) {};
	Operator(Group group)       : group(group) {};

	Mnemonic mnemonic;
	Prefix prefix;
	Group group;
};

#endif