#include "./Operator.h"
#include "./OperatorStrings.h"

Operator::Operator(Instruction * instruction) : instruction(instruction)
{
  schema = instruction->schema.operatorSchema;
}

const char * Operator::GetString()
{
  if (schema.mnemonic != Mnemonic::_)
    return MnemonicString[(int)schema.mnemonic];
  else
    return "ERROR";
}

