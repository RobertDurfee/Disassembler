#ifndef INSTRUCTION_SCHEMAS_HEADER
#define INSTRUCTION_SCHEMAS_HEADER

#include "Operator/InstructionOperator.h" //Operator, Mnemonic, Group, Prefix
#include "Operand/InstructionOperand.h"   //Operand, AddressingMethod, Register, SegmentRegister, Constant, Size

#define NUMBER_OF_OPERANDS 3

struct InstructionSchema
{
	Operator operator_;

	Operand operands[NUMBER_OF_OPERANDS];
};

InstructionSchema& operator|=(InstructionSchema& left, const InstructionSchema& right)
{
	left.operator_.mnemonic = right.operator_.mnemonic;

	for (int i = 0; i < NUMBER_OF_OPERANDS; i++)
	{
		if (left.operands[i].addressingMethod == AddressingMethod::$)
			left.operands[i].addressingMethod = right.operands[i].addressingMethod;

		if (left.operands[i].operandSize == Size::$)
			left.operands[i].operandSize = right.operands[i].operandSize;
	}

	return left;
}

const InstructionSchema InstructionSchemas[0x100 /* 0x00 - 0xFF */] =
{
/****************************************************************************************************************************************/
/* 0x00 */ { Mnemonic::ADD,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x01 */ { Mnemonic::ADD,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x02 */ { Mnemonic::ADD,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x03 */ { Mnemonic::ADD,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x04 */ { Mnemonic::ADD,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x05 */ { Mnemonic::ADD,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x06 */ { Mnemonic::PUSH,   { { SegmentRegister::ES, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x07 */ { Mnemonic::POP,    { { SegmentRegister::ES, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x08 */ { Mnemonic::OR,     { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x09 */ { Mnemonic::OR,     { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x0A */ { Mnemonic::OR,     { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x0B */ { Mnemonic::OR,     { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x0C */ { Mnemonic::OR,     { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x0D */ { Mnemonic::OR,     { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x0E */ { Mnemonic::PUSH,   { { SegmentRegister::CS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x0F */ { Group::TwoByte,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x10 */ { Mnemonic::ADC,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x11 */ { Mnemonic::ADC,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x12 */ { Mnemonic::ADC,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x13 */ { Mnemonic::ADC,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x14 */ { Mnemonic::ADC,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x15 */ { Mnemonic::ADC,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x16 */ { Mnemonic::PUSH,   { { SegmentRegister::SS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x17 */ { Mnemonic::POP,    { { SegmentRegister::SS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x18 */ { Mnemonic::SBB,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x19 */ { Mnemonic::SBB,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x1A */ { Mnemonic::SBB,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x1B */ { Mnemonic::SBB,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x1C */ { Mnemonic::SBB,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x1D */ { Mnemonic::SBB,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x1E */ { Mnemonic::PUSH,   { { SegmentRegister::DS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x1F */ { Mnemonic::POP,    { { SegmentRegister::DS, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x20 */ { Mnemonic::AND,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x21 */ { Mnemonic::AND,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x22 */ { Mnemonic::AND,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x23 */ { Mnemonic::AND,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x24 */ { Mnemonic::AND,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x25 */ { Mnemonic::AND,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x26 */ { Prefix::ES,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x27 */ { Mnemonic::DAA,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x28 */ { Mnemonic::SUB,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x29 */ { Mnemonic::SUB,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x2A */ { Mnemonic::SUB,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x2B */ { Mnemonic::SUB,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x2C */ { Mnemonic::SUB,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x2D */ { Mnemonic::SUB,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x2E */ { Prefix::CS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x2F */ { Mnemonic::DAS,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x30 */ { Mnemonic::XOR,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x31 */ { Mnemonic::XOR,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x32 */ { Mnemonic::XOR,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x33 */ { Mnemonic::XOR,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x34 */ { Mnemonic::XOR,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x35 */ { Mnemonic::XOR,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x36 */ { Prefix::SS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x37 */ { Mnemonic::AAA,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x38 */ { Mnemonic::CMP,    { { AddressingMethod::E, Size::b }, { AddressingMethod::G, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x39 */ { Mnemonic::CMP,    { { AddressingMethod::E, Size::v }, { AddressingMethod::G, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x3A */ { Mnemonic::CMP,    { { AddressingMethod::G, Size::b }, { AddressingMethod::E, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x3B */ { Mnemonic::CMP,    { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x3C */ { Mnemonic::CMP,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x3E */ { Mnemonic::CMP,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0x3D */ { Prefix::DS,       { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x3F */ { Mnemonic::AAS,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x40 */ { Mnemonic::INC,    { { Register::A,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x41 */ { Mnemonic::INC,    { { Register::C,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x42 */ { Mnemonic::INC,    { { Register::D,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x43 */ { Mnemonic::INC,    { { Register::B,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x44 */ { Mnemonic::INC,    { { Register::SP,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x45 */ { Mnemonic::INC,    { { Register::BP,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x46 */ { Mnemonic::INC,    { { Register::SI,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x47 */ { Mnemonic::INC,    { { Register::DI,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x48 */ { Mnemonic::DEC,    { { Register::A,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x49 */ { Mnemonic::DEC,    { { Register::C,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4A */ { Mnemonic::DEC,    { { Register::D,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4B */ { Mnemonic::DEC,    { { Register::B,         Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4C */ { Mnemonic::DEC,    { { Register::SP,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4D */ { Mnemonic::DEC,    { { Register::BP,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4E */ { Mnemonic::DEC,    { { Register::SI,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x4F */ { Mnemonic::DEC,    { { Register::DI,        Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0x50 */ { Mnemonic::PUSH,   { { Register::A,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x51 */ { Mnemonic::PUSH,   { { Register::C,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x52 */ { Mnemonic::PUSH,   { { Register::D,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x53 */ { Mnemonic::PUSH,   { { Register::B,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x54 */ { Mnemonic::PUSH,   { { Register::SP,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x55 */ { Mnemonic::PUSH,   { { Register::BP,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x56 */ { Mnemonic::PUSH,   { { Register::SI,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x57 */ { Mnemonic::PUSH,   { { Register::DI,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },

/* 0x58 */ { Mnemonic::POP,    { { Register::A,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x59 */ { Mnemonic::POP,    { { Register::C,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5A */ { Mnemonic::POP,    { { Register::D,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5B */ { Mnemonic::POP,    { { Register::B,         Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5C */ { Mnemonic::POP,    { { Register::SP,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5D */ { Mnemonic::POP,    { { Register::BP,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5E */ { Mnemonic::POP,    { { Register::SI,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x5F */ { Mnemonic::POP,    { { Register::DI,        Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
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

/* 0x68 */ { Mnemonic::PUSH,   { { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x69 */ { Mnemonic::IMUL,   { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::z } } },
/* 0x6A */ { Mnemonic::PUSH,   { { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x6B */ { Mnemonic::IMUL,   { { AddressingMethod::G, Size::v }, { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::b } } },
/* 0x6C */ { Mnemonic::INS,    { { AddressingMethod::Y, Size::b }, { AddressingMethod::D, Size::x }, { AddressingMethod::_, Size::_ } } },
/* 0x6D */ { Mnemonic::INS,    { { AddressingMethod::Y, Size::z }, { AddressingMethod::D, Size::x }, { AddressingMethod::_, Size::_ } } },
/* 0x6E */ { Mnemonic::OUTS,   { { AddressingMethod::D, Size::x }, { AddressingMethod::X, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0x6F */ { Mnemonic::OUTS,   { { AddressingMethod::D, Size::x }, { AddressingMethod::X, Size::z }, { AddressingMethod::_, Size::_ } } },
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
/* 0x81 */ { Group::Immediate, { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
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
/* 0x90 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::A,         Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x91 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::C,         Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x92 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::D,         Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x93 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::B,         Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x94 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::SP,        Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x95 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::BP,        Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x96 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::SI,        Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0x97 */ { Mnemonic::XCHG,   { { Register::A,         Size::v }, { Register::DI,        Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0x98 */ { Mnemonic::CBW,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x99 */ { Mnemonic::CWD,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9A */ { Mnemonic::CALL,   { { AddressingMethod::A, Size::p }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9B */ { Mnemonic::WAIT,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9C */ { Mnemonic::PUSHF,  { { AddressingMethod::F, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9D */ { Mnemonic::POPF,   { { AddressingMethod::F, Size::v }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9E */ { Mnemonic::SAHF,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0x9F */ { Mnemonic::LAHF,   { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xA0 */ { Mnemonic::MOV,    { { Register::A,         Size::b }, { AddressingMethod::O, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA1 */ { Mnemonic::MOV,    { { Register::A,         Size::v }, { AddressingMethod::O, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xA2 */ { Mnemonic::MOV,    { { AddressingMethod::O, Size::b }, { Register::A,         Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA3 */ { Mnemonic::MOV,    { { AddressingMethod::O, Size::v }, { Register::A,         Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xA4 */ { Mnemonic::MOVS,   { { AddressingMethod::Y, Size::b }, { AddressingMethod::X, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA5 */ { Mnemonic::MOVS,   { { AddressingMethod::Y, Size::v }, { AddressingMethod::X, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xA6 */ { Mnemonic::CMPS,   { { AddressingMethod::X, Size::b }, { AddressingMethod::Y, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA7 */ { Mnemonic::CMPS,   { { AddressingMethod::X, Size::v }, { AddressingMethod::Y, Size::v }, { AddressingMethod::_, Size::_ } } },

/* 0xA8 */ { Mnemonic::TEST,   { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xA9 */ { Mnemonic::TEST,   { { Register::A,         Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },
/* 0xAA */ { Mnemonic::STOS,   { { AddressingMethod::Y, Size::b }, { Register::A,         Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xAB */ { Mnemonic::STOS,   { { AddressingMethod::Y, Size::v }, { Register::A,         Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xAC */ { Mnemonic::LODS,   { { Register::A,         Size::b }, { AddressingMethod::X, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xAD */ { Mnemonic::LODS,   { { Register::A,         Size::v }, { AddressingMethod::X, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xAE */ { Mnemonic::SCAS,   { { Register::A,         Size::b }, { AddressingMethod::Y, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xAF */ { Mnemonic::SCAS,   { { Register::A,         Size::v }, { AddressingMethod::Y, Size::v }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xB0 */ { Mnemonic::MOV,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB1 */ { Mnemonic::MOV,    { { Register::C,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB2 */ { Mnemonic::MOV,    { { Register::D,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB3 */ { Mnemonic::MOV,    { { Register::B,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB4 */ { Mnemonic::MOV,    { { Register::SP,        Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB5 */ { Mnemonic::MOV,    { { Register::BP,        Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB6 */ { Mnemonic::MOV,    { { Register::SI,        Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xB7 */ { Mnemonic::MOV,    { { Register::DI,        Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },

/* 0xB8 */ { Mnemonic::MOV,    { { Register::A,         Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xB9 */ { Mnemonic::MOV,    { { Register::C,         Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBA */ { Mnemonic::MOV,    { { Register::D,         Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBB */ { Mnemonic::MOV,    { { Register::B,         Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBC */ { Mnemonic::MOV,    { { Register::SP,        Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBD */ { Mnemonic::MOV,    { { Register::BP,        Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBE */ { Mnemonic::MOV,    { { Register::SI,        Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/* 0xBF */ { Mnemonic::MOV,    { { Register::DI,        Size::v }, { AddressingMethod::I, Size::v }, { AddressingMethod::_, Size::_ } } },
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
/* 0xC0 */ { Group::Shift,     { { AddressingMethod::E, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC1 */ { Group::Shift,     { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC2 */ { Mnemonic::RET,    { { AddressingMethod::I, Size::w }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xC3 */ { Mnemonic::RET,    { { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xC4 */ { Mnemonic::LES,    { { AddressingMethod::G, Size::z }, { AddressingMethod::M, Size::p }, { AddressingMethod::_, Size::_ } } },
/* 0xC5 */ { Mnemonic::LDS,    { { AddressingMethod::G, Size::z }, { AddressingMethod::M, Size::p }, { AddressingMethod::_, Size::_ } } },
/* 0xC6 */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xC7 */ { Mnemonic::MOV,    { { AddressingMethod::E, Size::v }, { AddressingMethod::I, Size::z }, { AddressingMethod::_, Size::_ } } },

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
/* 0xD2 */ { Group::Shift,     { { AddressingMethod::E, Size::b }, { Register::C,         Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xD3 */ { Group::Shift,     { { AddressingMethod::E, Size::v }, { Register::C,         Size::b }, { AddressingMethod::_, Size::_ } } },
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
/* 0xE4 */ { Mnemonic::IN,     { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xE5 */ { Mnemonic::IN,     { { Register::A,         Size::z }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xE6 */ { Mnemonic::OUT,    { { Register::A,         Size::b }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xE7 */ { Mnemonic::OUT,    { { Register::A,         Size::z }, { AddressingMethod::I, Size::b }, { AddressingMethod::_, Size::_ } } },

/* 0xE8 */ { Mnemonic::CALL,   { { AddressingMethod::J, Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xE9 */ { Mnemonic::JMP,    { { AddressingMethod::J, Size::z }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xEA */ { Mnemonic::JMP,    { { AddressingMethod::A, Size::p }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xEB */ { Mnemonic::JMP,    { { AddressingMethod::J, Size::b }, { AddressingMethod::_, Size::_ }, { AddressingMethod::_, Size::_ } } },
/* 0xEC */ { Mnemonic::IN,     { { Register::A,         Size::b }, { Register::D,         Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0xED */ { Mnemonic::IN,     { { Register::A,         Size::z }, { Register::D,         Size::w }, { AddressingMethod::_, Size::_ } } },
/* 0xEE */ { Mnemonic::OUT,    { { Register::D,         Size::w }, { Register::A,         Size::b }, { AddressingMethod::_, Size::_ } } },
/* 0xEF */ { Mnemonic::OUT,    { { Register::D,         Size::w }, { Register::A,         Size::z }, { AddressingMethod::_, Size::_ } } },
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
	/* 100 */ { Mnemonic::MUL,    { { AddressingMethod::$, Size::$ }, { Register::A,         Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 101 */ { Mnemonic::IMUL,   { { AddressingMethod::$, Size::$ }, { Register::A,         Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 110 */ { Mnemonic::DIV,    { { AddressingMethod::$, Size::$ }, { Register::A,         Size::$ }, { AddressingMethod::_, Size::_ } } },
	/* 111 */ { Mnemonic::IDIV,   { { AddressingMethod::$, Size::$ }, { Register::A,         Size::$ }, { AddressingMethod::_, Size::_ } } }
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

#endif