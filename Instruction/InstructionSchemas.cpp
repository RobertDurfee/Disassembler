#include "./InstructionSchemas.h"
#include "../Operator/OperatorEnums.h"
#include "../Operand/OperandEnums.h"

InstructionSchema& operator|=(InstructionSchema& left, const InstructionSchema& right)
{
	left.operatorSchema.mnemonic = right.operatorSchema.mnemonic;

	for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
	{
		if (left.operandSchema[i].addressingMethod == AddressingMethod::$)
			left.operandSchema[i].addressingMethod = right.operandSchema[i].addressingMethod;

		if (left.operandSchema[i].operandSize == Size::$)
			left.operandSchema[i].operandSize = right.operandSchema[i].operandSize;
	}

	return left;
}

const InstructionSchema EmptyInstructionSchema = { Mnemonic::_,{ { AddressingMethod::_, Size::_ },{ AddressingMethod::_, Size::_ },{ AddressingMethod::_, Size::_ } } };

const InstructionSchema InstructionSchemas[0x100 /* 0x00 - 0xFF */] =
{
/****************************************************************************************************************************************/
/* 0x00 */ { Mnemonic::ADD,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x01 */ { Mnemonic::ADD,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x02 */ { Mnemonic::ADD,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x03 */ { Mnemonic::ADD,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x04 */ { Mnemonic::ADD,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x05 */ { Mnemonic::ADD,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x06 */ { Mnemonic::PUSH,   { { SegmentRegister::ES, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x07 */ { Mnemonic::POP,    { { SegmentRegister::ES, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x08 */ { Mnemonic::OR,     { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x09 */ { Mnemonic::OR,     { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x0A */ { Mnemonic::OR,     { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x0B */ { Mnemonic::OR,     { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x0C */ { Mnemonic::OR,     { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x0D */ { Mnemonic::OR,     { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x0E */ { Mnemonic::PUSH,   { { SegmentRegister::CS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x0F */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x10 */ { Mnemonic::ADC,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x11 */ { Mnemonic::ADC,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x12 */ { Mnemonic::ADC,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x13 */ { Mnemonic::ADC,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x14 */ { Mnemonic::ADC,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x15 */ { Mnemonic::ADC,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x16 */ { Mnemonic::PUSH,   { { SegmentRegister::SS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x17 */ { Mnemonic::POP,    { { SegmentRegister::SS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x18 */ { Mnemonic::SBB,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x19 */ { Mnemonic::SBB,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x1A */ { Mnemonic::SBB,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x1B */ { Mnemonic::SBB,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x1C */ { Mnemonic::SBB,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x1D */ { Mnemonic::SBB,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x1E */ { Mnemonic::PUSH,   { { SegmentRegister::DS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x1F */ { Mnemonic::POP,    { { SegmentRegister::DS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x20 */ { Mnemonic::AND,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x21 */ { Mnemonic::AND,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x22 */ { Mnemonic::AND,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x23 */ { Mnemonic::AND,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x24 */ { Mnemonic::AND,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x25 */ { Mnemonic::AND,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x26 */ { Prefix::ES,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x27 */ { Mnemonic::DAA,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x28 */ { Mnemonic::SUB,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x29 */ { Mnemonic::SUB,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x2A */ { Mnemonic::SUB,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x2B */ { Mnemonic::SUB,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x2C */ { Mnemonic::SUB,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x2D */ { Mnemonic::SUB,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x2E */ { Prefix::CS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x2F */ { Mnemonic::DAS,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x30 */ { Mnemonic::XOR,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x31 */ { Mnemonic::XOR,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x32 */ { Mnemonic::XOR,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x33 */ { Mnemonic::XOR,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x34 */ { Mnemonic::XOR,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x35 */ { Mnemonic::XOR,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x36 */ { Prefix::SS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x37 */ { Mnemonic::AAA,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x38 */ { Mnemonic::CMP,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x39 */ { Mnemonic::CMP,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x3A */ { Mnemonic::CMP,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x3B */ { Mnemonic::CMP,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x3C */ { Mnemonic::CMP,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x3E */ { Mnemonic::CMP,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x3D */ { Prefix::DS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x3F */ { Mnemonic::AAS,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x40 */ { Mnemonic::INC,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x41 */ { Mnemonic::INC,    { { GeneralRegister::C,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x42 */ { Mnemonic::INC,    { { GeneralRegister::D,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x43 */ { Mnemonic::INC,    { { GeneralRegister::B,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x44 */ { Mnemonic::INC,    { { GeneralRegister::SP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x45 */ { Mnemonic::INC,    { { GeneralRegister::BP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x46 */ { Mnemonic::INC,    { { GeneralRegister::SI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x47 */ { Mnemonic::INC,    { { GeneralRegister::DI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x48 */ { Mnemonic::DEC,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x49 */ { Mnemonic::DEC,    { { GeneralRegister::C,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4A */ { Mnemonic::DEC,    { { GeneralRegister::D,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4B */ { Mnemonic::DEC,    { { GeneralRegister::B,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4C */ { Mnemonic::DEC,    { { GeneralRegister::SP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4D */ { Mnemonic::DEC,    { { GeneralRegister::BP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4E */ { Mnemonic::DEC,    { { GeneralRegister::SI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4F */ { Mnemonic::DEC,    { { GeneralRegister::DI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x50 */ { Mnemonic::PUSH,   { { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x51 */ { Mnemonic::PUSH,   { { GeneralRegister::C,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x52 */ { Mnemonic::PUSH,   { { GeneralRegister::D,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x53 */ { Mnemonic::PUSH,   { { GeneralRegister::B,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x54 */ { Mnemonic::PUSH,   { { GeneralRegister::SP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x55 */ { Mnemonic::PUSH,   { { GeneralRegister::BP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x56 */ { Mnemonic::PUSH,   { { GeneralRegister::SI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x57 */ { Mnemonic::PUSH,   { { GeneralRegister::DI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x58 */ { Mnemonic::POP,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x59 */ { Mnemonic::POP,    { { GeneralRegister::C,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5A */ { Mnemonic::POP,    { { GeneralRegister::D,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5B */ { Mnemonic::POP,    { { GeneralRegister::B,  Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5C */ { Mnemonic::POP,    { { GeneralRegister::SP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5D */ { Mnemonic::POP,    { { GeneralRegister::BP, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5E */ { Mnemonic::POP,    { { GeneralRegister::SI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5F */ { Mnemonic::POP,    { { GeneralRegister::DI, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x60 */ { Mnemonic::PUSHA,  { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x61 */ { Mnemonic::POPA,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x62 */ { Mnemonic::BOUND,  { { AddressingMethod::G, Size::v }, { AddressingMethod::M, Size::a }, { AddressingMethod::_, Size::_ } } },
/* 0x63 */ { Mnemonic::ARPL,   { { AddressingMethod::E, Size::w }, { AddressingMethod::G, Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0x64 */ { Prefix::FS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x65 */ { Prefix::GS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x66 */ { Prefix::OPERAND,  { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x67 */ { Prefix::ADDRESS,  { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x68 */ { Mnemonic::PUSH,   { { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x69 */ { Mnemonic::IMUL,   { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::v } } },
/* 0x6A */ { Mnemonic::PUSH,   { { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x6B */ { Mnemonic::IMUL,   { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::b } } },
/* 0x6C */ { Mnemonic::INS,    { { AddressingMethod::Y, Size::b }, { GeneralRegister::D,  Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0x6D */ { Mnemonic::INS,    { { AddressingMethod::Y, Size::v }, { GeneralRegister::D,  Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0x6E */ { Mnemonic::OUTS,   { { GeneralRegister::D,  Size::w }, { AddressingMethod::X, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x6F */ { Mnemonic::OUTS,   { { GeneralRegister::D,  Size::w }, { AddressingMethod::X, Size::v }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x70 */ { Mnemonic::JO,     { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x71 */ { Mnemonic::JNO,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x72 */ { Mnemonic::JB,     { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x73 */ { Mnemonic::JNB,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x74 */ { Mnemonic::JZ,     { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x75 */ { Mnemonic::JNZ,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x76 */ { Mnemonic::JBE,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x77 */ { Mnemonic::JNBE,   { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x78 */ { Mnemonic::JS,     { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x79 */ { Mnemonic::JNS,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x7A */ { Mnemonic::JP,     { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x7B */ { Mnemonic::JNP,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x7C */ { Mnemonic::JL,     { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x7D */ { Mnemonic::JNL,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x7E */ { Mnemonic::JLE,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x7F */ { Mnemonic::JNLE,   { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x80 */ { Group::Immediate, { { AddressingMethod::E, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x81 */ { Group::Immediate, { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x82 */ { Group::Immediate, { { AddressingMethod::E, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x83 */ { Group::Immediate, { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x84 */ { Mnemonic::TEST,   { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x85 */ { Mnemonic::TEST,   { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x86 */ { Mnemonic::XCHG,   { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x87 */ { Mnemonic::XCHG,   { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0x88 */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x89 */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x8A */ { Mnemonic::MOV,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x8B */ { Mnemonic::MOV,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x8C */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::v }, { AddressingMethod::S, Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0x8D */ { Mnemonic::LEA,    { { AddressingMethod::G, Size::v }, { AddressingMethod::M, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x8E */ { Mnemonic::MOV,    { { AddressingMethod::S, Size::w }, { AddressingMethod::E, Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0x8F */ { Mnemonic::POP,    { { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x90 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x91 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::C,  Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x92 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::D,  Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x93 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::B,  Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x94 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::SP, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x95 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::BP, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x96 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::SI, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x97 */ { Mnemonic::XCHG,   { { GeneralRegister::A,  Size::v }, { GeneralRegister::DI, Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0x98 */ { Mnemonic::CBW,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x99 */ { Mnemonic::CWD,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9A */ { Mnemonic::CALL,   { { AddressingMethod::A, Size::p }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9B */ { Mnemonic::WAIT,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9C */ { Mnemonic::PUSHF,  { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9D */ { Mnemonic::POPF,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9E */ { Mnemonic::SAHF,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9F */ { Mnemonic::LAHF,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xA0 */ { Mnemonic::MOV,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::O, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA1 */ { Mnemonic::MOV,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::O, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xA2 */ { Mnemonic::MOV,    { { AddressingMethod::O, Size::b }, { GeneralRegister::A,  Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA3 */ { Mnemonic::MOV,    { { AddressingMethod::O, Size::v }, { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xA4 */ { Mnemonic::MOVS,   { { AddressingMethod::Y, Size::b }, { AddressingMethod::X, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA5 */ { Mnemonic::MOVS,   { { AddressingMethod::Y, Size::v }, { AddressingMethod::X, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xA6 */ { Mnemonic::CMPS,   { { AddressingMethod::X, Size::b }, { AddressingMethod::Y, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA7 */ { Mnemonic::CMPS,   { { AddressingMethod::X, Size::v }, { AddressingMethod::Y, Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0xA8 */ { Mnemonic::TEST,   { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA9 */ { Mnemonic::TEST,   { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xAA */ { Mnemonic::STOS,   { { AddressingMethod::Y, Size::b }, { GeneralRegister::A,  Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xAB */ { Mnemonic::STOS,   { { AddressingMethod::Y, Size::v }, { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xAC */ { Mnemonic::LODS,   { { GeneralRegister::A,  Size::b }, { AddressingMethod::X, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xAD */ { Mnemonic::LODS,   { { GeneralRegister::A,  Size::v }, { AddressingMethod::X, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xAE */ { Mnemonic::SCAS,   { { GeneralRegister::A,  Size::b }, { AddressingMethod::Y, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xAF */ { Mnemonic::SCAS,   { { GeneralRegister::A,  Size::v }, { AddressingMethod::Y, Size::v }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xB0 */ { Mnemonic::MOV,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB1 */ { Mnemonic::MOV,    { { GeneralRegister::C,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB2 */ { Mnemonic::MOV,    { { GeneralRegister::D,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB3 */ { Mnemonic::MOV,    { { GeneralRegister::B,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB4 */ { Mnemonic::MOV,    { { GeneralRegister::SP, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB5 */ { Mnemonic::MOV,    { { GeneralRegister::BP, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB6 */ { Mnemonic::MOV,    { { GeneralRegister::SI, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB7 */ { Mnemonic::MOV,    { { GeneralRegister::DI, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },

/* 0xB8 */ { Mnemonic::MOV,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xB9 */ { Mnemonic::MOV,    { { GeneralRegister::C,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBA */ { Mnemonic::MOV,    { { GeneralRegister::D,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBB */ { Mnemonic::MOV,    { { GeneralRegister::B,  Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBC */ { Mnemonic::MOV,    { { GeneralRegister::SP, Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBD */ { Mnemonic::MOV,    { { GeneralRegister::BP, Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBE */ { Mnemonic::MOV,    { { GeneralRegister::SI, Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBF */ { Mnemonic::MOV,    { { GeneralRegister::DI, Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xC0 */ { Group::Shift,     { { AddressingMethod::E, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC1 */ { Group::Shift,     { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC2 */ { Mnemonic::RET,    { { AddressingMethod::I, Size::w }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xC3 */ { Mnemonic::RET,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xC4 */ { Mnemonic::LES,    { { AddressingMethod::G, Size::v }, { AddressingMethod::M, Size::p }, { AddressingMethod::_, Size::_ } } },
/* 0xC5 */ { Mnemonic::LDS,    { { AddressingMethod::G, Size::v }, { AddressingMethod::M, Size::p }, { AddressingMethod::_, Size::_ } } },
/* 0xC6 */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC7 */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0xC8 */ { Mnemonic::ENTER,  { { AddressingMethod::I, Size::w }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC9 */ { Mnemonic::LEAVE,  { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xCA */ { Mnemonic::RET,    { { AddressingMethod::I, Size::w }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xCB */ { Mnemonic::RET,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xCC */ { Mnemonic::INT,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xCD */ { Mnemonic::INT,    { { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xCE */ { Mnemonic::INTO,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xCF */ { Mnemonic::IRET,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xD0 */ { Group::Shift,     { { AddressingMethod::E, Size::b }, { Constant::ONE,       Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xD1 */ { Group::Shift,     { { AddressingMethod::E, Size::v }, { Constant::ONE,       Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xD2 */ { Group::Shift,     { { AddressingMethod::E, Size::b }, { GeneralRegister::C,  Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xD3 */ { Group::Shift,     { { AddressingMethod::E, Size::v }, { GeneralRegister::C,  Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xD4 */ { Mnemonic::AAM,    { { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xD5 */ { Mnemonic::AAD,    { { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xD6 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xD7 */ { Mnemonic::XLAT,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0xD8 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xD9 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xDA */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xDB */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xDC */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xDD */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xDE */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xDF */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xE0 */ { Mnemonic::LOOPNE, { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xE1 */ { Mnemonic::LOOPE,  { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xE2 */ { Mnemonic::LOOP,   { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xE3 */ { Mnemonic::JECXZ,  { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xE4 */ { Mnemonic::IN,     { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xE5 */ { Mnemonic::IN,     { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xE6 */ { Mnemonic::OUT,    { { GeneralRegister::A,  Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xE7 */ { Mnemonic::OUT,    { { GeneralRegister::A,  Size::v }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },

/* 0xE8 */ { Mnemonic::CALL,   { { AddressingMethod::J, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xE9 */ { Mnemonic::JMP,    { { AddressingMethod::J, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xEA */ { Mnemonic::JMP,    { { AddressingMethod::A, Size::p }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xEB */ { Mnemonic::JMP,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xEC */ { Mnemonic::IN,     { { GeneralRegister::A,  Size::b }, { GeneralRegister::D,  Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0xED */ { Mnemonic::IN,     { { GeneralRegister::A,  Size::v }, { GeneralRegister::D,  Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0xEE */ { Mnemonic::OUT,    { { GeneralRegister::D,  Size::w }, { GeneralRegister::A,  Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xEF */ { Mnemonic::OUT,    { { GeneralRegister::D,  Size::w }, { GeneralRegister::A,  Size::v }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xF0 */ { Prefix::LOCK,     { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF1 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF2 */ { Prefix::REPNE,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF3 */ { Prefix::REPE,     { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF4 */ { Mnemonic::HLT,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF5 */ { Mnemonic::CMC,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF6 */ { Group::Unary,     { { AddressingMethod::E, Size::b }, { AddressingMethod::$, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xF7 */ { Group::Unary,     { { AddressingMethod::E, Size::v }, { AddressingMethod::$, Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0xF8 */ { Mnemonic::CLC,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xF9 */ { Mnemonic::STC,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xFA */ { Mnemonic::CLI,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xFB */ { Mnemonic::STI,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xFC */ { Mnemonic::CLD,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xFD */ { Mnemonic::STD,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xFE */ { Group::Four,      { { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xFF */ { Group::Five,      { { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } }
/****************************************************************************************************************************************/
};

const InstructionSchema GroupSchemas[5][0x8 /* 000 - 111 */] =
{
	{/*Immediate Group**********************************************************************************************************************/
	/* 000 */ { Mnemonic::ADD,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 001 */ { Mnemonic::OR,     { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 010 */ { Mnemonic::ADC,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 011 */ { Mnemonic::SBB,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 100 */ { Mnemonic::AND,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 101 */ { Mnemonic::SUB,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 110 */ { Mnemonic::XOR,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 111 */ { Mnemonic::CMP,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } }
	},/*************************************************************************************************************************************/

	{/*Shift Group**************************************************************************************************************************/
	/* 000 */ { Mnemonic::ROL,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 001 */ { Mnemonic::ROR,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 010 */ { Mnemonic::RCL,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 011 */ { Mnemonic::RCR,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 100 */ { Mnemonic::SHL,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 101 */ { Mnemonic::SHR,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 110 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 111 */ { Mnemonic::SAR,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ } } }
	},/*************************************************************************************************************************************/

	{/*Unary Group**************************************************************************************************************************/
	/* 000 */ { Mnemonic::TEST,   { { AddressingMethod::$, Size::$ }, { AddressingMethod::I, Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 001 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 010 */ { Mnemonic::NOT,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 011 */ { Mnemonic::NEG,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 100 */ { Mnemonic::MUL,    { { AddressingMethod::$, Size::$ }, { GeneralRegister::A,  Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 101 */ { Mnemonic::IMUL,   { { AddressingMethod::$, Size::$ }, { GeneralRegister::A,  Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 110 */ { Mnemonic::DIV,    { { AddressingMethod::$, Size::$ }, { GeneralRegister::A,  Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 111 */ { Mnemonic::IDIV,   { { AddressingMethod::$, Size::$ }, { GeneralRegister::A,  Size::$ }, { AddressingMethod::_, Size::_ } } }
	},/*************************************************************************************************************************************/

	{/*Group Four***************************************************************************************************************************/
	/* 000 */ { Mnemonic::INC,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 001 */ { Mnemonic::DEC,    { { AddressingMethod::$, Size::$ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 010 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 011 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 100 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 101 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 110 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 111 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } }
	},/*************************************************************************************************************************************/

	{/*Group Five***************************************************************************************************************************/
	/* 000 */ { Mnemonic::INC,    { { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 001 */ { Mnemonic::DEC,    { { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 010 */ { Mnemonic::CALL,   { { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 011 */ { Mnemonic::CALL,   { { AddressingMethod::E, Size::p }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 100 */ { Mnemonic::JMP,    { { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 101 */ { Mnemonic::JMP,    { { AddressingMethod::M, Size::p }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 110 */ { Mnemonic::PUSH,   { { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
	/* 111 */ { Mnemonic::_,      { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } }
	}/**************************************************************************************************************************************/
};
