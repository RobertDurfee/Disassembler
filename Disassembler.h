#ifndef DISASSEMBLER_HEADER
#define DISASSEMBLER_HEADER

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

enum Size { EIGHT, SIXTEEN, THIRTYTWO, MM, XMM };

#define		OPERAND_PREFIX	0x0001
#define		TWO_BYTE_PREFIX	0x0002
#define		ADDRESS_PREFIX	0x0004
#define		WAIT_PREFIX		0x0008
#define		LOCK_PREFIX		0x0010
#define		REPE_PREFIX		0x0020
#define		REPNE_PREFIX	0x0040
#define		ES_PREFIX		0x0080
#define		CS_PREFIX		0x0100
#define		SS_PREFIX		0x0200
#define		DS_PREFIX		0x0400
#define		FS_PREFIX		0x0800
#define		GS_PREFIX		0x1000

struct Instruction
{
	void Clear()
	{
		this->Base = 0xFFFFFFFF;
		this->Prefixes = 0x0000;
		this->OperandSize;
		this->Operator = "NULL";
		this->Operand1 = "NULL";
		this->Operand2 = "NULL";
		this->Operand3 = "NULL";
		this->Operand4 = "NULL";
		this->Hex.clear();
		this->REG = (unsigned char)0xFF;
		this->MOD_RM = (unsigned char)0xFF;
	}
	int Base = 0xFFFFFFFF;
	short Prefixes = 0x0000;
	Size OperandSize;
	string Operator = "NULL";
	string Operand1 = "NULL";
	string Operand2 = "NULL";
	string Operand3 = "NULL";
	string Operand4 = "NULL";
	vector<string> Hex;
	char REG = (unsigned char)0xFF;
	char MOD_RM = (unsigned char)0xFF;
};

#define		DISASSEMBLER_NONE	0x00000000
#define		DISASSEMBLER_PRINT	0x00000001
#define		DISASSEMBLER_STRING	0x00000002

class Disassembler
{
public:
	Disassembler(char * input, int length)
	{
		this->SetBuffer(input, length);
	}
	~Disassembler()
	{
		delete[] this->bufferToDisassemble;
	}
	void SetBuffer(char * input, int length)
	{
		this->~Disassembler();

		this->bufferLength = length;
		this->bufferToDisassemble = new char[length];
		memcpy(this->bufferToDisassemble, input, length);
	}
	string Disassemble(int startingAddress = 0x0, int length = 0xFFFFFFFF, int instructions = 0xFFFFFFFF, int flags = 0x0, int baseAddress = 0x0)
	{
		stringstream ss;

		if (!(flags & DISASSEMBLER_STRING))
			ss << "NULL";

		this->baseAddress = baseAddress;
		this->currentOpcode = startingAddress;
		this->nextByteToRead = startingAddress;

		int maximumLength;
		if (length == 0xFFFFFFFF)
			maximumLength = (int)this->bufferLength;
		else
			maximumLength = length;

		this->instructions.clear();

		while (this->currentOpcode < maximumLength && (instructions == 0xFFFFFFFF) ? true : ((int)this->instructions.size() < instructions))
		{
			this->currentInstruction.Clear();
		REASSIGN:
			int returnValue = this->oneByteOpcodeRoutines(this->PeekCurrentOpcode());
		REEVALUATE:
			if (returnValue == 0x01)
				goto REASSIGN;
			else if (returnValue == 0x02)
			{
				returnValue = this->twoByteOpcodeRoutines(this->PeekCurrentOpcode());
				goto REEVALUATE;
			}
			else if (returnValue == 0x03)
			{
				returnValue = this->threeByteOpcodeRoutines(this->PeekCurrentOpcode());
				goto REEVALUATE;
			}
			this->instructions.push_back(this->currentInstruction);
			if (flags & DISASSEMBLER_PRINT)
				this->PrintCurrentInstruction();
			if (flags & DISASSEMBLER_STRING)
				ss << InstructionToString(this->currentInstruction, this->baseAddress);
			this->currentOpcode = this->nextByteToRead;
		}
		return ss.str();
	}

private:
	int currentOpcode = 0;
	int nextByteToRead = 0;
	char * bufferToDisassemble;
	int bufferLength;
	Instruction currentInstruction;
	vector<Instruction> instructions;
	int baseAddress;

	void PrintInstruction(Instruction instruction, int baseAddress)
	{
		cout << "0x";
		cout.width(0x08);
		cout.fill('0');
		cout << hex << (int)(baseAddress + instruction.Base) << ":";
		int i = 0;
		for (i; i < 6 && i < (int)instruction.Hex.size(); i++)
			cout << " " << instruction.Hex[i];
		if (instruction.Hex.size() > 6)
			cout << "+";
		else
			cout << " ";
		for (int j = 0; j < 18 - (3 * i); j++)
			cout << " ";
		if (instruction.Operator != "NULL")
			cout << " " << instruction.Operator;
		else
			cout << "    ";
		if (instruction.Operand1 != "NULL")
		{
			cout << "\t" << instruction.Operand1;
			if (instruction.Operand2 != "NULL")
			{
				cout << ", " << instruction.Operand2;
				if (instruction.Operand3 != "NULL")
				{
					cout << ", " << instruction.Operand3;
					if (instruction.Operand4 != "NULL")
						cout << ", " << instruction.Operand4 << endl;
					else
						cout << endl;
				}
				else
					cout << endl;
			}
			else
				cout << endl;
		}
		else
			cout << endl;
	}
	string InstructionsToString(vector<Instruction> instruction, int baseAddress)
	{
		stringstream ss;

		for (int index = 0; index < (int)instruction.size(); index++)
		{
			ss << "0x";
			ss.width(0x08);
			ss.fill('0');
			ss << hex << (int)(baseAddress + instruction[index].Base) << ":";
			int i = 0;
			for (i; i < 6 && i < (int)instruction[index].Hex.size(); i++)
				ss << " " << instruction[index].Hex[i];
			if (instruction[index].Hex.size() > 6)
				ss << "+";
			else
				ss << " ";
			for (int j = 0; j < 18 - (3 * i); j++)
				ss << " ";
			if (instruction[index].Operator != "NULL")
				ss << " " << instruction[index].Operator;
			else
				ss << "    ";
			if (instruction[index].Operand1 != "NULL")
			{
				ss << "\t" << instruction[index].Operand1;
				if (instruction[index].Operand2 != "NULL")
				{
					ss << ", " << instruction[index].Operand2;
					if (instruction[index].Operand3 != "NULL")
					{
						ss << ", " << instruction[index].Operand3;
						if (instruction[index].Operand4 != "NULL")
							ss << ", " << instruction[index].Operand4 << endl;
						else
							ss << endl;
					}
					else
						ss << endl;
				}
				else
					ss << endl;
			}
			else
				ss << endl;
		}

		return ss.str();
	}
	string InstructionToString(Instruction instruction, int baseAddress)
	{
		stringstream ss;

		ss << "0x";
		ss.width(0x08);
		ss.fill('0');
		ss << hex << (int)(baseAddress + instruction.Base) << ":";
		int i = 0;
		for (i; i < 6 && i < (int)instruction.Hex.size(); i++)
			ss << " " << instruction.Hex[i];
		if (instruction.Hex.size() > 6)
			ss << "+";
		else
			ss << " ";
		for (int j = 0; j < 18 - (3 * i); j++)
			ss << " ";
		if (instruction.Operator != "NULL")
			ss << " " << instruction.Operator;
		else
			ss << "    ";
		if (instruction.Operand1 != "NULL")
		{
			ss << "\t" << instruction.Operand1;
			if (instruction.Operand2 != "NULL")
			{
				ss << ", " << instruction.Operand2;
				if (instruction.Operand3 != "NULL")
				{
					ss << ", " << instruction.Operand3;
					if (instruction.Operand4 != "NULL")
						ss << ", " << instruction.Operand4 << endl;
					else
						ss << endl;
				}
				else
					ss << endl;
			}
			else
				ss << endl;
		}
		else
			ss << endl;

		return ss.str();
	}

	int PeekCurrentOpcode()
	{
		return (int)(this->bufferToDisassemble[this->currentOpcode] & 0x000000FF);
	}
	int PeekNextByteToRead()
	{
		return (int)(this->bufferToDisassemble[this->nextByteToRead] & 0x000000FF);
	}
	void PrintCurrentInstruction()
	{
		cout << "0x";
		cout.width(0x08);
		cout.fill('0');
		cout << hex << (int)(this->baseAddress + this->currentInstruction.Base) << ":";
		int i = 0;
		for (i; i < 6 && i < (int)this->currentInstruction.Hex.size(); i++)
			cout << " " << this->currentInstruction.Hex[i];
		if (this->currentInstruction.Hex.size() > 6)
			cout << "+";
		else
			cout << " ";
		for (int j = 0; j < 18 - (3 * i); j++)
			cout << " ";
		if (this->currentInstruction.Operator != "NULL")
			cout << " " << this->currentInstruction.Operator;
		else
			cout << "    ";
		if (this->currentInstruction.Operand1 != "NULL")
		{
			cout << "\t" << this->currentInstruction.Operand1;
			if (this->currentInstruction.Operand2 != "NULL")
			{
				cout << ", " << this->currentInstruction.Operand2;
				if (this->currentInstruction.Operand3 != "NULL")
				{
					cout << ", " << this->currentInstruction.Operand3;
					if (this->currentInstruction.Operand4 != "NULL")
						cout << ", " << this->currentInstruction.Operand4 << endl;
					else
						cout << endl;
				}
				else
					cout << endl;
			}
			else
				cout << endl;
		}
		else
			cout << endl;
	}

	int oneByteOpcodeRoutines(int value)
	{
		switch (value)
		{
			case 0x00:
			case 0x01:
			case 0x02:
			case 0x03:
			case 0x04:
			case 0x05:
				return this->add();
			case 0x06:
			case 0x0E:
			case 0x16:
			case 0x1E:
			case 0x50:
			case 0x51:
			case 0x52:
			case 0x53:
			case 0x54:
			case 0x55:
			case 0x56:
			case 0x57:
			case 0x68:
			case 0x6A:
				return this->push();
			case 0x07:
			case 0x17:
			case 0x1F:
			case 0x58:
			case 0x59:
			case 0x5A:
			case 0x5B:
			case 0x5C:
			case 0x5D:
			case 0x5E:
			case 0x5F:
			case 0x8F:
				return this->pop();
			case 0x08:
			case 0x09:
			case 0x0A:
			case 0x0B:
			case 0x0C:
			case 0x0D:
				return this-> or ();
			case 0x0F:
				return this->twobytePrefix();
			case 0x10:
			case 0x11:
			case 0x12:
			case 0x13:
			case 0x14:
			case 0x15:
				return this->adc();
			case 0x18:
			case 0x19:
			case 0x1A:
			case 0x1B:
			case 0x1C:
			case 0x1D:
				return this->sbb();
			case 0x20:
			case 0x21:
			case 0x22:
			case 0x23:
			case 0x24:
			case 0x25:
				return this-> and ();
			case 0x26:
				return this->esPrefix();
			case 0x27:
				return this->daa();
			case 0x28:
			case 0x29:
			case 0x2A:
			case 0x2B:
			case 0x2C:
			case 0x2D:
				return this->sub();
			case 0x2E:
				return this->csPrefix();
			case 0x2F:
				return this->das();
			case 0x30:
			case 0x31:
			case 0x32:
			case 0x33:
			case 0x34:
			case 0x35:
				return this-> xor ();
			case 0x36:
				return this->ssPrefix();
			case 0x37:
				return this->aaa();
			case 0x38:
			case 0x39:
			case 0x3A:
			case 0x3B:
			case 0x3C:
			case 0x3D:
				return this->cmp();
			case 0x3E:
				return this->dsPrefix();
			case 0x3F:
				return this->aas();
			case 0x40:
			case 0x41:
			case 0x42:
			case 0x43:
			case 0x44:
			case 0x45:
			case 0x46:
			case 0x47:
				return this->inc();
			case 0x48:
			case 0x49:
			case 0x4A:
			case 0x4B:
			case 0x4C:
			case 0x4D:
			case 0x4E:
			case 0x4F:
				return this->dec();
			case 0x60:
				return this->pushad();
			case 0x61:
				return this->popad();
			case 0x62:
				return this->bound();
			case 0x63:
				return this->arpl();
			case 0x64:
				return this->fsPrefix();
			case 0x65:
				return this->gsPrefix();
			case 0x66:
				return this->operandPrefix();
			case 0x67:
				return this->addressPrefix();
			case 0x69:
			case 0x6B:
				return this->imul();
			case 0x6C:
			case 0x6D:
				return this->ins();
			case 0x6E:
			case 0x6F:
				return this->outs();
			case 0x70:
				return this->jo();
			case 0x71:
				return this->jno();
			case 0x72:
				return this->jb();
			case 0x73:
				return this->jnb();
			case 0x74:
				return this->jz();
			case 0x75:
				return this->jnz();
			case 0x76:
				return this->jbe();
			case 0x77:
				return this->jnbe();
			case 0x78:
				return this->js();
			case 0x79:
				return this->jns();
			case 0x7A:
				return this->jp();
			case 0x7B:
				return this->jnp();
			case 0x7C:
				return this->jl();
			case 0x7D:
				return this->jnl();
			case 0x7E:
				return this->jle();
			case 0x7F:
				return this->jnle();
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
				return this->_grp1();
			case 0x84:
			case 0x85:
			case 0xA8:
			case 0xA9:
				return this->test();
			case 0x86:
			case 0x87:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
				return this->xchg();
			case 0x88:
			case 0x89:
			case 0x8A:
			case 0x8B:
			case 0x8C:
			case 0x8E:
			case 0xA0:
			case 0xA1:
			case 0xA2:
			case 0xA3:
			case 0xB0:
			case 0xB1:
			case 0xB2:
			case 0xB3:
			case 0xB4:
			case 0xB5:
			case 0xB6:
			case 0xB7:
			case 0xB8:
			case 0xB9:
			case 0xBA:
			case 0xBB:
			case 0xBC:
			case 0xBD:
			case 0xBE:
			case 0xBF:
			case 0xC6:
			case 0xC7:
				return this->mov();
			case 0x8D:
				return this->lea();
			case 0x90:
				return this->_90h();
			case 0x98:
				return this->cwde();
			case 0x99:
				return this->cdq();
			case 0x9A:
			case 0xE8:
				return this->call();
			case 0x9B:
				return this->waitPrefix();
			case 0x9C:
				return this->pushfd();
			case 0x9D:
				return this->popfd();
			case 0x9E:
				return this->sahf();
			case 0x9F:
				return this->lahf();
			case 0xA4:
			case 0xA5:
				return this->movs();
			case 0xA6:
			case 0xA7:
				return this->cmps();
			case 0xAA:
			case 0xAB:
				return this->stos();
			case 0xAC:
			case 0xAD:
				return this->lods();
			case 0xAE:
			case 0xAF:
				return this->scas();
			case 0xC0:
			case 0xC1:
				return this->_grp2();
			case 0xC2:
			case 0xC3:
			case 0xCA:
			case 0xCB:
				return this->ret();
			case 0xC4:
				return this->les();
			case 0xC5:
				return this->lds();
			case 0xC8:
				return this->enter();
			case 0xC9:
				return this->leave();
			case 0xCC:
			case 0xCD:
			case 0xCE:
				return this->_int();
			case 0xCF:
				return this->iretd();
			case 0xD0:
			case 0xD1:
			case 0xD2:
			case 0xD3:
				return this->_grp2();
			case 0xD4:
				return this->aam();
			case 0xD5:
				return this->aad();
			case 0xD7:
				return this->xlat();
			case 0xE0:
				return this->loopne();
			case 0xE1:
				return this->loope();
			case 0xE2:
				return this->loop();
			case 0xE3:
				return this->jecxz();
			case 0xE4:
			case 0xE5:
			case 0xEC:
			case 0xED:
				return this->in();
			case 0xE6:
			case 0xE7:
			case 0xEE:
			case 0xEF:
				return this->out();
			case 0xE9:
			case 0xEA:
			case 0xEB:
				return this->jmp();
			case 0xF0:
				return this->lockPrefix();
			case 0xF2:
				return this->repnePrefix();
			case 0xF3:
				return this->repePrefix();
			case 0xF4:
				return this->hlt();
			case 0xF5:
				return this->cmc();
			case 0xF6:
			case 0xF7:
				return this->_grp3();
			case 0xF8:
				return this->clc();
			case 0xF9:
				return this->stc();
			case 0xFA:
				return this->cli();
			case 0xFB:
				return this->sti();
			case 0xFC:
				return this->cld();
			case 0xFD:
				return this->_std();
			case 0xFE:
				return this->_grp4();
			case 0xFF:
				return this->_grp5();
			default:
				return this->undf();
		}
	}
	int twoByteOpcodeRoutines(int value)
	{
		switch (value)
		{
			case 0x05:
				return this->syscall();
			case 0x07:
				return this->sysret();
			case 0x10:
			case 0x11:
				return this->movups_movupd_movss_movsd();
			case 0x13:
				return this->movlps_movlpd();
			case 0x1F:
				return this->nop();
			case 0x20:
			case 0x21:
			case 0x22:
			case 0x23:
				return this->mov();
			case 0x34:
				return this->sysenter();
			case 0x35:
				return this->sysexit();
			case 0x40:
				return this->cmovo();
			case 0x41:
				return this->cmovno();
			case 0x42:
				return this->cmovb();
			case 0x43:
				return this->cmovnb();
			case 0x44:
				return this->cmovz();
			case 0x45:
				return this->cmovnz();
			case 0x46:
				return this->cmovbe();
			case 0x47:
				return this->cmovnbe();
			case 0x48:
				return this->cmovs();
			case 0x49:
				return this->cmovns();
			case 0x4A:
				return this->cmovp();
			case 0x4B:
				return this->cmovnp();
			case 0x4C:
				return this->cmovl();
			case 0x4D:
				return this->cmovnl();
			case 0x4E:
				return this->cmovle();
			case 0x4F:
				return this->cmovnle();
			case 0x57:
				return this->xorps_xorpd();
			case 0x80:
				return this->jo();
			case 0x81:
				return this->jno();
			case 0x82:
				return this->jb();
			case 0x83:
				return this->jnb();
			case 0x84:
				return this->jz();
			case 0x85:
				return this->jnz();
			case 0x86:
				return this->jbe();
			case 0x87:
				return this->jnbe();
			case 0x88:
				return this->js();
			case 0x89:
				return this->jns();
			case 0x8A:
				return this->jp();
			case 0x8B:
				return this->jnp();
			case 0x8C:
				return this->jl();
			case 0x8D:
				return this->jnl();
			case 0x8E:
				return this->jle();
			case 0x8F:
				return this->jnle();
			case 0x90:
				return this->seto();
			case 0x91:
				return this->setno();
			case 0x92:
				return this->setb();
			case 0x93:
				return this->setnb();
			case 0x94:
				return this->setz();
			case 0x95:
				return this->setnz();
			case 0x96:
				return this->setbe();
			case 0x97:
				return this->setnbe();
			case 0x98:
				return this->sets();
			case 0x99:
				return this->setns();
			case 0x9A:
				return this->setp();
			case 0x9B:
				return this->setnp();
			case 0x9C:
				return this->setl();
			case 0x9D:
				return this->setnl();
			case 0x9E:
				return this->setle();
			case 0x9F:
				return this->setnle();
			case 0xA2:
				return this->cpuid();
			case 0xAF:
				return this->imul();
			case 0xB0:
			case 0xB1:
				return this->cmpxchg();
			case 0xB6:
			case 0xB7:
				return this->movzx();
			case 0xBE:
			case 0xBF:
				return this->movsx();
			default:
				return this->undf();
		}
	}
	int threeByteOpcodeRoutines(int value)
	{

		switch (value)
		{
			case 0x00:
				return this->undf();
			default:
				return this->undf();
		}
	}

	string modrmRoutines(int value)
	{
		switch (value)
		{
			case 0x00:
				return this->eax_bxsi();
			case 0x01:
				return this->ecx_bxdi();
			case 0x02:
				return this->edx_bpsi();
			case 0x03:
				return this->ebx_bpdi();
			case 0x04:
				return this->sib_si();
			case 0x05:
				return this->_32BitDisp_di();
			case 0x06:
				return this->esi_16BitDisp();
			case 0x07:
				return this->edi_bx();

			case 0x08:
				return this->eax_bxsi8BitDisp();
			case 0x09:
				return this->ecx_bxdi8BitDisp();
			case 0x0A:
				return this->edx_bpsi8BitDisp();
			case 0x0B:
				return this->ebx_bpdi8BitDisp();
			case 0x0C:
				return this->sib_si8BitDisp();
			case 0x0D:
				return this->ebp_di8BitDisp();
			case 0x0E:
				return this->esi_bp8BitDisp();
			case 0x0F:
				return this->edi_bx8BitDisp();

			case 0x10:
				return this->eax_bxsi32BitDisp();
			case 0x11:
				return this->ecx_bxdi32BitDisp();
			case 0x12:
				return this->edx_bpsi32BitDisp();
			case 0x13:
				return this->ebx_bpdi32BitDisp();
			case 0x14:
				return this->sib_si32BitDisp();
			case 0x15:
				return this->ebp_di32BitDisp();
			case 0x16:
				return this->esi_bp32BitDisp();
			case 0x17:
				return this->edi_bx32BitDisp();

			case 0x18:
				return this->aRegister();
			case 0x19:
				return this->cRegister();
			case 0x1A:
				return this->dRegister();
			case 0x1B:
				return this->bRegister();
			case 0x1C:
				return this->spRegister();
			case 0x1D:
				return this->bpRegister();
			case 0x1E:
				return this->siRegister();
			case 0x1F:
				return this->diRegister();
			default:
				return "UNDF";
		}
	}

	void SetModRegRm()
	{
		this->currentInstruction.REG = (this->bufferToDisassemble[this->nextByteToRead] >> 0x03) & 0x07;
		this->currentInstruction.MOD_RM = ((this->bufferToDisassemble[this->nextByteToRead] >> 0x03) & 0x18) | (this->bufferToDisassemble[this->nextByteToRead] & 0x07);
		this->nextByteToRead++;
	}

	string Read32BitToString()
	{
		stringstream ss;
		for (int i = 3; i >= 0; i--)
		{
			ss.width(0x02);
			ss.fill('0');
			ss << hex << (int)(this->bufferToDisassemble[this->nextByteToRead + i] & 0x000000FF);
		}
		this->nextByteToRead += 4;
		ss << 'h';
		return ss.str();
	}
	string Read16BitToString()
	{
		stringstream ss;
		for (int i = 1; i >= 0; i--)
		{
			ss.width(0x02);
			ss.fill('0');
			ss << hex << (int)(this->bufferToDisassemble[this->nextByteToRead + i] & 0x000000FF);
		}
		this->nextByteToRead += 2;
		ss << 'h';
		return ss.str();
	}
	string Read8BitToString()
	{
		stringstream ss;
		ss.width(0x02);
		ss.fill('0');
		ss << hex << (int)(this->bufferToDisassemble[this->nextByteToRead] & 0x000000FF);
		this->nextByteToRead++;
		ss << 'h';
		return ss.str();
	}
	char Read8Bit()
	{
		char result = this->bufferToDisassemble[this->nextByteToRead];
		this->nextByteToRead++;
		return result;
	}
	short Read16Bit()
	{
		short b = this->bufferToDisassemble[this->nextByteToRead] & 0x00FF, a = this->bufferToDisassemble[this->nextByteToRead + 1] & 0x00FF;
		this->nextByteToRead += 2;
		short result = (a << 8) | b;
		return result;
	}
	int Read32Bit()
	{
		int d = this->bufferToDisassemble[this->nextByteToRead] & 0x000000FF, c = this->bufferToDisassemble[this->nextByteToRead + 1] & 0x000000FF, b = this->bufferToDisassemble[this->nextByteToRead + 2] & 0x000000FF, a = this->bufferToDisassemble[this->nextByteToRead + 3] & 0x000000FF;
		this->nextByteToRead += 4;
		int result = (a << 24) | (b << 16) | (c << 8) | d;
		return result;
	}

	void SetHex()
	{
		stringstream ss;
		for (int index = this->currentInstruction.Base; index < this->nextByteToRead; index++)
		{
			ss.str("");
			ss.width(0x02);
			ss.fill('0');
			ss << hex << (int)(this->bufferToDisassemble[index] & 0x000000FF);
			this->currentInstruction.Hex.push_back(ss.str());
		}
	}

	//SIB
	string scales(int value)
	{
		switch (value)
		{
			case 0x00:
				return "1";
			case 0x01:
				return "2";
			case 0x02:
				return "4";
			case 0x03:
				return "8";
			default:
				return "UNDF";
		}
	}
	string indexes(int value)
	{
		switch (value)
		{
			case 0x00:
				return "eax";
			case 0x01:
				return "ecx";
			case 0x02:
				return "edx";
			case 0x03:
				return "ebx";
			case 0x04:
				return "NONE";
			case 0x05:
				return "ebp";
			case 0x06:
				return "esi";
			case 0x07:
				return "edi";
			default:
				return "UNDF";
		}
	}
	string bases(int value)
	{
		switch (value)
		{
			case 0x00:
				return "eax";
			case 0x01:
				return "ecx";
			case 0x02:
				return "edx";
			case 0x03:
				return "ebx";
			case 0x04:
				return "esp";
			case 0x05:
				return "ebp";
			case 0x06:
				return "esi";
			case 0x07:
				return "edi";
			default:
				return "UNDF";
		}
	}
	string SIB(char SIB)
	{
		char scale = (SIB >> 0x06) & 0x03;
		char index = (SIB >> 0x03) & 0x07;
		char base = SIB & 0x07;
		this->nextByteToRead++;
		stringstream ss;
		if (base == 0x05 && ((this->currentInstruction.MOD_RM >> 0x03) & 0x03) == 0x0)
			ss << this->Read32BitToString();
		else
			ss << this->bases(base);
		if (index != 0x04)
			ss << " + " << this->indexes(index) << " * " << this->scales(scale);
		ss << "]";
		return ss.str();
	}

	//SREG
	string sregs(int value)
	{
		switch (value)
		{
			case 0x00:
				return "es";
			case 0x01:
				return "cs";
			case 0x02:
				return "ss";
			case 0x03:
				return "ds";
			case 0x04:
				return "fs";
			case 0x05:
				return "gs";
			default:
				return "UNDF";
		}
	}

	//REG
	string regs(int value)
	{
		switch (value)
		{
			case 0x00:
				return "al";
			case 0x01:
				return "cl";
			case 0x02:
				return "dl";
			case 0x03:
				return "bl";
			case 0x04:
				return "ah";
			case 0x05:
				return "ch";
			case 0x06:
				return "dh";
			case 0x07:
				return "bh";

			case 0x08:
				return "ax";
			case 0x09:
				return "cx";
			case 0x0A:
				return "dx";
			case 0x0B:
				return "bx";
			case 0x0C:
				return "sp";
			case 0x0D:
				return "bp";
			case 0x0E:
				return "si";
			case 0x0F:
				return "di";

			case 0x10:
				return "eax";
			case 0x11:
				return "ecx";
			case 0x12:
				return "edx";
			case 0x13:
				return "ebx";
			case 0x14:
				return "esp";
			case 0x15:
				return "ebp";
			case 0x16:
				return "esi";
			case 0x17:
				return "edi";

			case 0x20:
				return "mm0";
			case 0x21:
				return "mm1";
			case 0x22:
				return "mm2";
			case 0x23:
				return "mm3";
			case 0x24:
				return "mm4";
			case 0x25:
				return "mm5";
			case 0x26:
				return "mm6";
			case 0x27:
				return "mm7";

			case 0x30:
				return "xmm0";
			case 0x31:
				return "xmm1";
			case 0x32:
				return "xmm2";
			case 0x33:
				return "xmm3";
			case 0x34:
				return "xmm4";
			case 0x35:
				return "xmm5";
			case 0x36:
				return "xmm6";
			case 0x37:
				return "xmm7";

			default:
				return "UNDF";
		}
	}

	//MOD-RM
	string eax_bxsi()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[bx + si]";
		else
			return "[eax]";
	}
	string ecx_bxdi()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[bx + di]";
		else
			return "[ecx]";
	}
	string edx_bpsi()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[bp + si]";
		else
			return "[edx]";
	}
	string ebx_bpdi()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[bp + di]";
		else
			return "[ebx]";
	}
	string sib_si()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[si]";
		else
		{
			stringstream ss;
			ss << "[" << SIB(this->PeekNextByteToRead());
			return ss.str();
		}
	}
	string _32BitDisp_di()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[di]";
		else
		{
			stringstream ss;
			ss << "[" << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string esi_16BitDisp()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			stringstream ss;
			ss << "[" << Read16BitToString() << "]";
			return ss.str();
		}
		else
			return "[esi]";
	}
	string edi_bx()
	{
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
			return "[bx]";
		else
			return "[edi]";
	}
	string eax_bxsi8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bx + si + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[eax + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string ecx_bxdi8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bx + di + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[ecx + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string edx_bpsi8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bp + si + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[edx + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string ebx_bpdi8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bp + di + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[ebx + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string sib_si8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[si + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			string sib = SIB(this->PeekNextByteToRead());
			ss << "[" << Read8BitToString() << " + " << sib;
			return ss.str();
		}
	}
	string ebp_di8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[di + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[ebp + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string esi_bp8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bp + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[esi + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string edi_bx8BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bx + " << Read8BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[edi + " << Read8BitToString() << "]";
			return ss.str();
		}
	}
	string eax_bxsi32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bx + si + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[eax + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string ecx_bxdi32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bx + di + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[ecx + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string edx_bpsi32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bp + si + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[edx + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string ebx_bpdi32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bp + di + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[ebx + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string sib_si32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[si + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			string sib = SIB(this->PeekNextByteToRead());
			ss << "[" << Read32BitToString() << " + " << sib;
			return ss.str();
		}
	}
	string ebp_di32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[di + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[ebp + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string esi_bp32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bp + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[esi + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string edi_bx32BitDisp()
	{
		stringstream ss;
		if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
		{
			ss << "[bx + " << Read16BitToString() << "]";
			return ss.str();
		}
		else
		{
			ss << "[edi + " << Read32BitToString() << "]";
			return ss.str();
		}
	}
	string aRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "al";
			case SIXTEEN:
				return "ax";
			case THIRTYTWO:
				return "eax";
			case MM:
				return "mm0";
			case XMM:
				return "xmm0";
			default:
				undf();
				return "ERROR";
		}
	}
	string cRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "cl";
			case SIXTEEN:
				return "cx";
			case THIRTYTWO:
				return "ecx";
			case MM:
				return "mm1";
			case XMM:
				return "xmm1";
			default:
				undf();
				return "ERROR";
		}
	}
	string dRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "dl";
			case SIXTEEN:
				return "dx";
			case THIRTYTWO:
				return "edx";
			case MM:
				return "mm2";
			case XMM:
				return "xmm2";
			default:
				undf();
				return "ERROR";
		}
	}
	string bRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "bl";
			case SIXTEEN:
				return "bx";
			case THIRTYTWO:
				return "ebx";
			case MM:
				return "mm3";
			case XMM:
				return "xmm3";
			default:
				undf();
				return "ERROR";
		}
	}
	string spRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "ah";
			case SIXTEEN:
				return "sp";
			case THIRTYTWO:
				return "esp";
			case MM:
				return "mm4";
			case XMM:
				return "xmm4";
			default:
				undf();
				return "ERROR";
		}
	}
	string bpRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "ch";
			case SIXTEEN:
				return "bp";
			case THIRTYTWO:
				return "ebp";
			case MM:
				return "mm5";
			case XMM:
				return "xmm5";
			default:
				undf();
				return "ERROR";
		}
	}
	string siRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "dh";
			case SIXTEEN:
				return "si";
			case THIRTYTWO:
				return "esi";
			case MM:
				return "mm6";
			case XMM:
				return "xmm6";
			default:
				undf();
				return "ERROR";
		}
	}
	string diRegister()
	{
		switch (this->currentInstruction.OperandSize)
		{
			case EIGHT:
				return "bh";
			case SIXTEEN:
				return "di";
			case THIRTYTWO:
				return "edi";
			case MM:
				return "mm7";
			case XMM:
				return "xmm7";
			default:
				undf();
				return "ERROR";
		}
	}

	//OPERANDS
	void AL_IMM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->currentInstruction.Operand1 = "al";
		this->currentInstruction.Operand2 = this->Read8BitToString();
	}
	void AX_IMM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->currentInstruction.Operand1 = "ax";
		this->currentInstruction.Operand2 = this->Read16BitToString();
	}
	void EAX_IMM32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->currentInstruction.Operand1 = "eax";
		this->currentInstruction.Operand2 = this->Read32BitToString();
	}

	void RM8_IMM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->Read8BitToString();
	}
	void RM16_IMM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->Read16BitToString();
	}
	void RM32_IMM32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->Read32BitToString();
	}
	void RM16_IMM8()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->Read8BitToString();
	}
	void RM32_IMM8()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->Read8BitToString();
	}

	void RM8_R8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG);
	}
	void RM16_R16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG + 8);
	}
	void RM32_R32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG + 16);
	}
	void R8_RM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void R16_RM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 8);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void R32_RM32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 16);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}

	void REL8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		stringstream ss;
		int address = this->baseAddress + this->currentInstruction.Base + (char)this->Read8Bit() + (this->nextByteToRead - this->currentInstruction.Base);
		ss << "0x";
		ss.width(0x08);
		ss.fill('0');
		ss << hex << (int)address;
		this->currentInstruction.Operand1 = ss.str();
		this->currentInstruction.Operand2 = "NULL";
	}
	void REL16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		stringstream ss;
		int address = this->baseAddress + this->currentInstruction.Base + (short)this->Read16Bit() + (this->nextByteToRead - this->currentInstruction.Base);
		ss << "0x";
		ss.width(0x08);
		ss.fill('0');
		ss << hex << (int)address;
		this->currentInstruction.Operand1 = ss.str();
	}
	void REL32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		stringstream ss;
		int address = this->baseAddress + this->currentInstruction.Base + (int)this->Read32Bit() + (this->nextByteToRead - this->currentInstruction.Base);
		ss << "0x";
		ss.width(0x08);
		ss.fill('0');
		ss << hex << (int)address;
		this->currentInstruction.Operand1 = ss.str();
	}

	void RM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void RM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void RM32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}

	void IMM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->currentInstruction.Operand1 = this->Read8BitToString();
	}
	void IMM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->currentInstruction.Operand1 = this->Read16BitToString();
	}
	void IMM32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->currentInstruction.Operand1 = this->Read32BitToString();
	}

	void R16_RM16_IMM8()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 8);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand3 = this->Read8BitToString();
	}
	void R32_RM32_IMM8()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 16);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand3 = this->Read8BitToString();
	}
	void R16_RM16_IMM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 8);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand3 = this->Read16BitToString();
	}
	void R32_RM32_IMM32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 16);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand3 = this->Read32BitToString();
	}

	void RM16_SREG()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->sregs(this->currentInstruction.REG);
	}
	void SREG_RM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->sregs(this->currentInstruction.REG);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}

	void AL_MOFFS8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		stringstream ss;
		this->currentInstruction.Operand1 = "al";
		ss << '[' << this->Read32BitToString() << ']';
		this->currentInstruction.Operand2 = ss.str();
	}
	void AX_MOFFS16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		stringstream ss;
		this->currentInstruction.Operand1 = "ax";
		ss << '[' << this->Read32BitToString() << ']';
		this->currentInstruction.Operand2 = ss.str();
	}
	void EAX_MOFFS32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		stringstream ss;
		this->currentInstruction.Operand1 = "eax";
		ss << '[' << this->Read32BitToString() << ']';
		this->currentInstruction.Operand2 = ss.str();
	}
	void MOFFS8_AL()
	{
		this->currentInstruction.OperandSize = EIGHT;
		stringstream ss;
		ss << '[' << this->Read32BitToString() << ']';
		this->currentInstruction.Operand1 = ss.str();
		this->currentInstruction.Operand2 = "al";
	}
	void MOFFS16_AX()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		stringstream ss;
		ss << '[' << this->Read32BitToString() << ']';
		this->currentInstruction.Operand1 = ss.str();
		this->currentInstruction.Operand2 = "ax";
	}
	void MOFFS32_EAX()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		stringstream ss;
		ss << '[' << this->Read32BitToString() << ']';
		this->currentInstruction.Operand1 = ss.str();
		this->currentInstruction.Operand2 = "eax";
	}

	void PTR16_16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		stringstream ss;
		string a, b;
		b = this->Read16BitToString();
		a = this->Read16BitToString();
		ss << a << ':' << b;
		this->currentInstruction.Operand1 = ss.str();
	}
	void PTR16_32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		stringstream ss;
		string a, b;
		b = this->Read32BitToString();
		a = this->Read16BitToString();
		ss << a << ':' << b;
		this->currentInstruction.Operand1 = ss.str();
	}

	void M16_16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		stringstream ss;
		ss << "far " << this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand1 = ss.str();
	}
	void M16_32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		stringstream ss;
		ss << "far " << this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand1 = ss.str();
	}

	void IMM16_IMM8()
	{
		this->currentInstruction.Operand1 = this->Read16BitToString();
		this->currentInstruction.Operand2 = this->Read8BitToString();
	}

	void R16_RM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 8);
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void R32_RM8()
	{
		this->currentInstruction.OperandSize = EIGHT;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 16);
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void R32_RM16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 16);
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}

	void XMM_XMMM128()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 48);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void XMMM128_XMM()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG + 48);
	}
	void XMM_XMMM64()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 48);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void XMMM64_XMM()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG + 48);
	}
	void XMM_XMMM32()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->regs(this->currentInstruction.REG + 48);
		this->currentInstruction.Operand2 = this->modrmRoutines(this->currentInstruction.MOD_RM);
	}
	void XMMM32_XMM()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG + 48);
	}
	void M64_XMM()
	{
		this->currentInstruction.OperandSize = XMM;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = this->regs(this->currentInstruction.REG + 48);
	}

	void R16_M16_16()
	{
		this->currentInstruction.OperandSize = SIXTEEN;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = regs(this->currentInstruction.REG + 8);
		stringstream ss;
		ss << "far " << this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = ss.str();
	}
	void R32_M16_32()
	{
		this->currentInstruction.OperandSize = THIRTYTWO;
		this->SetModRegRm();
		this->currentInstruction.Operand1 = regs(this->currentInstruction.REG + 16);
		stringstream ss;
		ss << "far " << this->modrmRoutines(this->currentInstruction.MOD_RM);
		this->currentInstruction.Operand2 = ss.str();
	}

	//OPCODES
	int add()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "add";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x04:
				this->AL_IMM8();
				break;
			case 0x05:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x00:
				this->RM8_R8();
				break;
			case 0x01:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x02:
				this->R8_RM8();
				break;
			case 0x03:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int push()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "push";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			case 0x50:
			case 0x51:
			case 0x52:
			case 0x53:
			case 0x54:
			case 0x55:
			case 0x56:
			case 0x57:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 8);
				else
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 16);
				break;
			case 0x6A:
				this->IMM8();
				break;
			case 0x68:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->IMM16();
				else
					this->IMM32();
				break;
			case 0x0E:
				this->currentInstruction.Operand1 = "cs";
				break;
			case 0x16:
				this->currentInstruction.Operand1 = "ss";
				break;
			case 0x1E:
				this->currentInstruction.Operand1 = "ds";
				break;
			case 0x06:
				this->currentInstruction.Operand1 = "es";
				break;
			case 0xA0:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->currentInstruction.Operand1 = "fs";
				else
					undf();
				break;
			case 0xA8:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->currentInstruction.Operand1 = "gs";
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int pop()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "pop";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x8F:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			case 0x58:
			case 0x59:
			case 0x5A:
			case 0x5B:
			case 0x5C:
			case 0x5D:
			case 0x5E:
			case 0x5F:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 8);
				else
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 16);
				break;
			case 0x1F:
				this->currentInstruction.Operand1 = "ds";
				break;
			case 0x07:
				this->currentInstruction.Operand1 = "es";
				break;
			case 0x17:
				this->currentInstruction.Operand1 = "ss";
				break;
			case 0xA1:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->currentInstruction.Operand1 = "fs";
				else
					undf();
				break;
			case 0xA9:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->currentInstruction.Operand1 = "gs";
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int or ()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "or";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x0C:
				this->AL_IMM8();
				break;
			case 0x0D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x08:
				this->RM8_R8();
				break;
			case 0x09:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x0A:
				this->R8_RM8();
				break;
			case 0x0B:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int twobytePrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= TWO_BYTE_PREFIX;
		return 2;
	}
	int adc()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "adc";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x14:
				this->AL_IMM8();
				break;
			case 0x15:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x10:
				this->RM8_R8();
				break;
			case 0x11:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x12:
				this->R8_RM8();
				break;
			case 0x13:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sbb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sbb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x1C:
				this->AL_IMM8();
				break;
			case 0x1D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x18:
				this->RM8_R8();
				break;
			case 0x19:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x1A:
				this->R8_RM8();
				break;
			case 0x1B:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int and()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "and";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x24:
				this->AL_IMM8();
				break;
			case 0x25:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x20:
				this->RM8_R8();
				break;
			case 0x21:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x22:
				this->R8_RM8();
				break;
			case 0x23:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int esPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= ES_PREFIX;
		return 1;
	}
	int daa()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "daa";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x27:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sub()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sub";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x2C:
				this->AL_IMM8();
				break;
			case 0x2D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x28:
				this->RM8_R8();
				break;
			case 0x29:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x2A:
				this->R8_RM8();
				break;
			case 0x2B:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int csPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= CS_PREFIX;
		return 1;
	}
	int das()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "das";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x2F:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int xor()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "xor";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x34:
				this->AL_IMM8();
				break;
			case 0x35:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x30:
				this->RM8_R8();
				break;
			case 0x31:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x32:
				this->R8_RM8();
				break;
			case 0x33:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int ssPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= SS_PREFIX;
		return 1;
	}
	int aaa()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "aaa";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x37:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x3C:
				this->AL_IMM8();
				break;
			case 0x3D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0x80:
				this->RM8_IMM8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			case 0x38:
				this->RM8_R8();
				break;
			case 0x39:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x3A:
				this->R8_RM8();
				break;
			case 0x3B:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int dsPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= DS_PREFIX;
		return 1;
	}
	int aas()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "aas";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x3F:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int inc()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "inc";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFE:
				this->RM8();
				break;
			case 0xFF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			case 0x40:
			case 0x41:
			case 0x42:
			case 0x43:
			case 0x44:
			case 0x45:
			case 0x46:
			case 0x47:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 8);
				else
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 16);
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int dec()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "dec";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFE:
				this->RM8();
				break;
			case 0xFF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			case 0x48:
			case 0x49:
			case 0x4A:
			case 0x4B:
			case 0x4C:
			case 0x4D:
			case 0x4E:
			case 0x4F:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 8);
				else
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 16);
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int pushad()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x60:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "pusha";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "pushad";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int popad()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x61:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "popa";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "popad";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int bound()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "bound";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x62:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int arpl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "arpl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x63:
				RM16_R16();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int fsPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= FS_PREFIX;
		return 1;
	}
	int gsPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= GS_PREFIX;
		return 1;
	}
	int operandPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= OPERAND_PREFIX;
		return 1;
	}
	int addressPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= ADDRESS_PREFIX;
		return 1;
	}
	int imul()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "imul";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF6:
				this->RM8();
				break;
			case 0xF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			case 0xAF:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			case 0x6B:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16_IMM8();
				else
					this->R32_RM32_IMM8();
				break;
			case 0x69:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16_IMM16();
				else
					this->R32_RM32_IMM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int ins()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x6C:
				this->currentInstruction.Operator = "insb";
				this->nextByteToRead++;
				break;
			case 0x6D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "insw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "insd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int outs()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x6E:
				this->currentInstruction.Operator = "outsb";
				this->nextByteToRead++;
				break;
			case 0x6F:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "outsw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "outsd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jo()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jo";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x70:
				this->REL8();
				break;
			case 0x80:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jno()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jno";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x71:
				this->REL8();
				break;
			case 0x81:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x72:
				this->REL8();
				break;
			case 0x82:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jnb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jnb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x73:
				this->REL8();
				break;
			case 0x83:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x74:
				this->REL8();
				break;
			case 0x84:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jnz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jnz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x75:
				this->REL8();
				break;
			case 0x85:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jbe()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jbe";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x76:
				this->REL8();
				break;
			case 0x86:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jnbe()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jnbe";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x77:
				this->REL8();
				break;
			case 0x87:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int js()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "js";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x78:
				this->REL8();
				break;
			case 0x88:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jns()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jns";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x79:
				this->REL8();
				break;
			case 0x89:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x7A:
				this->REL8();
				break;
			case 0x8A:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jnp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jnp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x7B:
				this->REL8();
				break;
			case 0x8B:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x7C:
				this->REL8();
				break;
			case 0x8C:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jnl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jnl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x7D:
				this->REL8();
				break;
			case 0x8D:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jle()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jle";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x7E:
				this->REL8();
				break;
			case 0x8E:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jnle()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jnle";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x7F:
				this->REL8();
				break;
			case 0x8F:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->REL16();
					else
						this->REL32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int rol()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "rol";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int ror()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "ror";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int rcl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "rcl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int rcr()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "rcr";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int shl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "shl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int shr()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "shr";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sal()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sal";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sar()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sar";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD0:
				this->RM8();
				this->currentInstruction.Operand2 = "01h";
				break;
			case 0xD2:
				this->RM8();
				this->currentInstruction.Operand2 = "cl";
				break;
			case 0xC0:
				this->RM8_IMM8();
				break;
			case 0xD1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "01h";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "01h";
				}
				break;
			case 0xD3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->RM16();
					this->currentInstruction.Operand2 = "cl";
				}
				else
				{
					this->RM32();
					this->currentInstruction.Operand2 = "cl";
				}
				break;
			case 0xC1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM8();
				else
					this->RM32_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int not()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "not";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF6:
				this->RM8();
				break;
			case 0XF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int neg()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "neg";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF6:
				this->RM8();
				break;
			case 0xF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int mul()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "mul";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF6:
				this->RM8();
				break;
			case 0xF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int div()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "div";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF6:
				this->RM8();
				break;
			case 0xF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int idiv()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "idiv";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF6:
				this->RM8();
				break;
			case 0xF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16();
				else
					this->RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _grp1()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				add();
				break;
			case 0x01:
				or ();
				break;
			case 0x02:
				adc();
				break;
			case 0x03:
				sbb();
				break;
			case 0x04:
				and ();
				break;
			case 0x05:
				sub();
				break;
			case 0x06:
				xor ();
				break;
			case 0x07:
				cmp();
				break;
			default:
				undf();
		}

		return 0;
	}
	int test()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "test";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xA8:
				this->AL_IMM8();
				break;
			case 0xA9:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0xF6:
				this->RM8_IMM8();
				break;
			case 0xF7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			case 0x84:
				this->RM8_R8();
				break;
			case 0x85:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int xchg()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "xchg";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x90:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operand1 = "ax";
					this->currentInstruction.Operand2 = this->regs((PeekCurrentOpcode() & 0x07) + 8);
				}
				else
				{
					this->currentInstruction.Operand1 = "eax";
					this->currentInstruction.Operand2 = this->regs((PeekCurrentOpcode() & 0x07) + 16);
				}
				break;
			case 0x86:
				this->RM8_R8();
				break;
			case 0x87:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int mov()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "mov";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x88:
				this->RM8_R8();
				break;
			case 0x89:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					RM16_R16();
				else
					this->RM32_R32();
				break;
			case 0x8A:
				this->R8_RM8();
				break;
			case 0x8B:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			case 0x8C:
				this->RM16_SREG();
				break;
			case 0x8E:
				this->SREG_RM16();
				break;
			case 0xA0:
				this->AL_MOFFS8();
				break;
			case 0xA1:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_MOFFS16();
				else
					this->EAX_MOFFS32();
				break;
			case 0xA2:
				this->MOFFS8_AL();
				break;
			case 0xA3:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->MOFFS16_AX();
				else
					this->MOFFS32_EAX();
				break;
			case 0xB0:
			case 0xB1:
			case 0xB2:
			case 0xB3:
			case 0xB4:
			case 0xB5:
			case 0xB6:
			case 0xB7:
				this->currentInstruction.Operand1 = this->regs(PeekCurrentOpcode() & 0x07);
				this->currentInstruction.Operand2 = this->Read8BitToString();
				break;
			case 0xB8:
			case 0xB9:
			case 0xBA:
			case 0xBB:
			case 0xBC:
			case 0xBD:
			case 0xBE:
			case 0xBF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 8);
					this->currentInstruction.Operand2 = this->Read16BitToString();
				}
				else
				{
					this->currentInstruction.Operand1 = this->regs((PeekCurrentOpcode() & 0x07) + 16);
					this->currentInstruction.Operand2 = this->Read32BitToString();
				}
				break;
			case 0xC6:
				this->RM8_IMM8();
				break;
			case 0xC7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->RM16_IMM16();
				else
					this->RM32_IMM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int lea()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "lea";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x8D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_RM16();
				else
					this->R32_RM32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int nop()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "nop";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x90:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int pause()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "pause";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x90:
				if (this->currentInstruction.Prefixes & REPE_PREFIX);
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _90h()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x90:
				if (this->currentInstruction.Prefixes & REPE_PREFIX)
					pause();
				else
					nop();
				break;
			default:
				undf();
		}

		return 0;
	}
	int cwde()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x98:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "cbw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "cwde";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cdq()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x99:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "cwd";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "cdq";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int call()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "call";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE8:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->REL16();
				else
					this->REL32();
				break;
			case 0xFF:
			{
				switch ((this->bufferToDisassemble[this->nextByteToRead] >> 0x03) & 0x07)
				{
					case 0x02:
						if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
							this->RM16();
						else
							this->RM32();
						break;
					case 0x03:
						if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
							this->M16_16();
						else
							this->M16_32();
						break;
					default:
						undf();
				}
				break;
			}
			case 0x9A:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->PTR16_16();
				else
					this->PTR16_32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int waitPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= WAIT_PREFIX;
		return 1;
	}
	int pushfd()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x9C:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "pushf";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "pushfd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int popfd()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x9D:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "popf";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "popfd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sahf()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sahf";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9E:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int lahf()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "lahf";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9F:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int movs()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xA4:
				this->currentInstruction.Operator = "movsb";
				this->nextByteToRead++;
				break;
			case 0xA5:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "movsw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "movsd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmps()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xA6:
				this->currentInstruction.Operator = "cmpsb";
				this->nextByteToRead++;
				break;
			case 0xA7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "cmpsw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "cmpsd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int stos()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xAA:
				this->currentInstruction.Operator = "stosb";
				this->nextByteToRead++;
				break;
			case 0xAB:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "stosw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "stosd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int lods()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xAC:
				this->currentInstruction.Operator = "lodsb";
				this->nextByteToRead++;
				break;
			case 0xAD:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "lodsw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "lodsd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int scas()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xAE:
				this->currentInstruction.Operator = "scasb";
				this->nextByteToRead++;
				break;
			case 0xAF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "scasw";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "scasd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _grp2()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				rol();
				break;
			case 0x01:
				ror();
				break;
			case 0x02:
				rcl();
				break;
			case 0x03:
				rcr();
				break;
			case 0x04:
				shl();
				break;
			case 0x05:
				shr();
				break;
			case 0x06:
				sal();
				break;
			case 0x07:
				sar();
				break;
			default:
				undf();
		}

		return 0;
	}
	int ret()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "ret";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xC3:
				break;
			case 0xCB:
				break;
			case 0xC2:
				this->IMM16();
				break;
			case 0xCA:
				this->IMM16();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int les()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "les";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xC4:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_M16_16();
				else
					this->R32_M16_32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int lds()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "lds";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xC5:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->R16_M16_16();
				else
					this->R32_M16_32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int enter()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "enter";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xC8:
				this->IMM16_IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int leave()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "leave";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xC9:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _int()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xCC:
				this->currentInstruction.Operator = "int";
				this->nextByteToRead++;
				this->currentInstruction.Operand1 = "3";
				break;
			case 0xCD:
				this->currentInstruction.Operator = "int";
				this->nextByteToRead++;
				this->IMM8();
				break;
			case 0xCE:
				this->currentInstruction.Operator = "into";
				this->nextByteToRead++;
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int iretd()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0xCF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operator = "iret";
					this->nextByteToRead++;
				}
				else
				{
					this->currentInstruction.Operator = "iretd";
					this->nextByteToRead++;
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _D0h()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				rol();
				break;
			case 0x01:
				ror();
				break;
			case 0x02:
				rcl();
				break;
			case 0x03:
				rcr();
				break;
			case 0x04:
				shl();
				break;
			case 0x05:
				shr();
				break;
			case 0x06:
				sal();
				break;
			case 0x07:
				sar();
				break;
			default:
				undf();
		}

		return 0;
	}
	int _D1h()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				rol();
				break;
			case 0x01:
				ror();
				break;
			case 0x02:
				rcl();
				break;
			case 0x03:
				rcr();
				break;
			case 0x04:
				shl();
				break;
			case 0x05:
				shr();
				break;
			case 0x06:
				sal();
				break;
			case 0x07:
				sar();
				break;
			default:
				undf();
		}

		return 0;
	}
	int _D2h()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				rol();
				break;
			case 0x01:
				ror();
				break;
			case 0x02:
				rcl();
				break;
			case 0x03:
				rcr();
				break;
			case 0x04:
				shl();
				break;
			case 0x05:
				shr();
				break;
			case 0x06:
				sal();
				break;
			case 0x07:
				sar();
				break;
			default:
				undf();
		}

		return 0;
	}
	int _D3h()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				rol();
				break;
			case 0x01:
				ror();
				break;
			case 0x02:
				rcl();
				break;
			case 0x03:
				rcr();
				break;
			case 0x04:
				shl();
				break;
			case 0x05:
				shr();
				break;
			case 0x06:
				sal();
				break;
			case 0x07:
				sar();
				break;
			default:
				undf();
		}

		return 0;
	}
	int aam()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "aam";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD4:
				this->IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int aad()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "aad";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD5:
				this->IMM8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int xlat()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "xlatb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xD7:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int loopne()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "loopne";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE0:
				this->REL8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int loope()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "loope";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE1:
				this->REL8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int loop()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "loop";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE2:
				this->REL8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jecxz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jecxz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE3:
				this->REL8();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int in()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "in";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE4:
				this->AL_IMM8();
				break;
			case 0xE5:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0xEC:
				this->currentInstruction.Operand1 = "al";
				this->currentInstruction.Operand2 = "dx";
				break;
			case 0xED:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operand1 = "ax";
					this->currentInstruction.Operand2 = "dx";
				}
				else
				{
					this->currentInstruction.Operand1 = "eax";
					this->currentInstruction.Operand2 = "dx";
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int out()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "out";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xE6:
				this->AL_IMM8();
				break;
			case 0xE7:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->AX_IMM16();
				else
					this->EAX_IMM32();
				break;
			case 0xEE:
				this->currentInstruction.Operand1 = "al";
				this->currentInstruction.Operand2 = "dx";
				break;
			case 0xEF:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
				{
					this->currentInstruction.Operand1 = "ax";
					this->currentInstruction.Operand2 = "dx";
				}
				else
				{
					this->currentInstruction.Operand1 = "eax";
					this->currentInstruction.Operand2 = "dx";
				}
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int jmp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "jmp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xEB:
				this->REL8();
				break;
			case 0xE9:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->REL16();
				else
					this->REL32();
				break;
			case 0xFF:
			{
				switch ((this->bufferToDisassemble[this->nextByteToRead] >> 0x03) & 0x07)
				{
					case 0x04:
						if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
							this->RM16();
						else
							this->RM32();
						break;
					case 0x05:
						if (this->currentInstruction.Prefixes & ADDRESS_PREFIX)
							this->M16_16();
						else
							this->M16_32();
						break;
					default:
						undf();
				}
				break;
			}
			case 0xEA:
				if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					this->PTR16_16();
				else
					this->PTR16_32();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int lockPrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= LOCK_PREFIX;
		return 1;
	}
	int repnePrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= REPNE_PREFIX;
		return 1;
	}
	int repePrefix()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;
		this->currentOpcode++; this->nextByteToRead++;
		this->currentInstruction.Prefixes |= REPE_PREFIX;
		return 1;
	}
	int hlt()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "hlt";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF4:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmc()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmc";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF5:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _grp3()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				test();
				break;
			case 0x01:
				test();
				break;
			case 0x02:
				not();
				break;
			case 0x03:
				neg();
				break;
			case 0x04:
				mul();
				break;
			case 0x05:
				imul();
				break;
			case 0x06:
				div();
				break;
			case 0x07:
				idiv();
				break;
			default:
				undf();
		}

		return 0;
	}
	int clc()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "clc";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF8:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int stc()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "stc";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xF9:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cli()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cli";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFA:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sti()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sti";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFB:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cld()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cld";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFC:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _std()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "std";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xFD:
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int _grp4()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				inc();
				break;
			case 0x01:
				dec();
				break;
			default:
				undf();
		}

		return 0;
	}
	int _grp5()
	{
		switch ((this->bufferToDisassemble[this->nextByteToRead + 1] >> 3) & 7)
		{
			case 0x00:
				inc();
				break;
			case 0x01:
				dec();
				break;
			case 0x02:
				call();
				break;
			case 0x03:
				call();
				break;
			case 0x04:
				jmp();
				break;
			case 0x05:
				jmp();
				break;
			case 0x06:
				push();
				break;
			default:
				undf();
		}

		return 0;
	}
	int undf()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "UNDF";
		this->nextByteToRead++;

		SetHex();
		
		return 0;
	}
	int syscall()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "syscall";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x05:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX);
				else
					undf();
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sysret()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sysret";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x07:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX);
				else
					undf();
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sysexit()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sysexit";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x35:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX);
				else
					undf();
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sysenter()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sysenter";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x34:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX);
				else
					undf();
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovo()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovo";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x40:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovno()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovno";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x41:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x42:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovnb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovnb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x43:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x44:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovnz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovnz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x45:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovbe()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovbe";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x46:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovnbe()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovnbe";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x47:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovs()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovs";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x48:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovns()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovns";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x49:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x4A:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovnp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovnp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x4B:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x4C:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovnl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovnl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x4D:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovle()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovle";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x4E:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmovnle()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmovnle";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x4F:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM16();
					else
						this->R32_RM32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int seto()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "seto";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x90:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setno()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setno";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x91:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x92:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setnb()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setnb";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x93:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x94:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setnz()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setnz";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x95:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setbe()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setbe";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x96:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setnbe()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setnbe";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x97:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int sets()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "sets";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x98:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setns()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setns";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x99:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9A:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setnp()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setnp";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9B:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9C:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setnl()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setnl";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9D:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setle()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setle";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9E:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int setnle()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "setnle";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0x9F:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int movzx()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "movzx";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xB6:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM8();
					else
						this->R32_RM8();
				else
					undf();
				break;
			case 0xB7:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->R32_RM16();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cmpxchg()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cmpxchg";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xB0:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->RM8_R8();
				else
					undf();
				break;
			case 0xB1:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->RM16_R16();
					else
						this->RM32_R32();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int xorps_xorpd()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x57:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					{
						this->currentInstruction.Operator = "xorpd";
						this->nextByteToRead++;

						this->XMM_XMMM128();
					}
					else
					{
						this->currentInstruction.Operator = "xorps";
						this->nextByteToRead++;

						this->XMM_XMMM128();
					}
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int movlps_movlpd()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x13:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					{
						this->currentInstruction.Operator = "movlpd";
						this->nextByteToRead++;

						this->M64_XMM();
					}
					else
					{
						this->currentInstruction.Operator = "movlps";
						this->nextByteToRead++;

						this->M64_XMM();
					}
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int movups_movupd_movss_movsd()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		switch (PeekCurrentOpcode())
		{
			case 0x10:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					{
						this->currentInstruction.Operator = "movupd";
						this->nextByteToRead++;

						this->XMM_XMMM128();
					}
					else if (this->currentInstruction.Prefixes & REPNE_PREFIX)
					{
						this->currentInstruction.Operator = "movsd";
						this->nextByteToRead++;

						this->XMM_XMMM64();
					}
					else if (this->currentInstruction.Prefixes & REPE_PREFIX)
					{
						this->currentInstruction.Operator = "movss";
						this->nextByteToRead++;

						this->XMM_XMMM32();
					}
					else
					{
						this->currentInstruction.Operator = "movups";
						this->nextByteToRead++;

						this->XMM_XMMM128();
					}
				else
					undf();
				break;
			case 0x11:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
					{
						this->currentInstruction.Operator = "movupd";
						this->nextByteToRead++;

						this->XMMM128_XMM();
					}
					else if (this->currentInstruction.Prefixes & REPNE_PREFIX)
					{
						this->currentInstruction.Operator = "movsd";
						this->nextByteToRead++;

						this->XMMM64_XMM();
					}
					else if (this->currentInstruction.Prefixes & REPE_PREFIX)
					{
						this->currentInstruction.Operator = "movss";
						this->nextByteToRead++;

						this->XMMM32_XMM();
					}
					else
					{
						this->currentInstruction.Operator = "movups";
						this->nextByteToRead++;

						this->XMMM128_XMM();
					}
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int movsx()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "movsx";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xBE:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					if (this->currentInstruction.Prefixes & OPERAND_PREFIX)
						this->R16_RM8();
					else
						this->R32_RM8();
				else
					undf();
				break;
			case 0xBF:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX)
					this->R32_RM16();
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
	int cpuid()
	{
		if (this->currentInstruction.Base == 0xFFFFFFFF)
			this->currentInstruction.Base = this->currentOpcode;

		this->currentInstruction.Operator = "cpuid";
		this->nextByteToRead++;

		switch (PeekCurrentOpcode())
		{
			case 0xA2:
				if (this->currentInstruction.Prefixes & TWO_BYTE_PREFIX);
				else
					undf();
				break;
			default:
				undf();
		}

		this->SetHex();

		return 0;
	}
};

#endif