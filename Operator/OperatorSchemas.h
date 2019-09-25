#ifndef OPERATOR_SCHEMAS_HEADER
#define OPERATOR_SCHEMAS_HEADER

#include "./OperatorEnums.h"

struct OperatorSchema
{
	OperatorSchema() : mnemonic(Mnemonic::_), prefix(Prefix::_), group(Group::_) {};

	OperatorSchema(Mnemonic mnemonic) : mnemonic(mnemonic) {};
	OperatorSchema(Prefix prefix) : prefix(prefix) {};
	OperatorSchema(Group group) : group(group) {};

	Mnemonic mnemonic;
	Prefix prefix;
	Group group;
};

extern const OperatorSchema EmptyOperatorSchema;

#endif
