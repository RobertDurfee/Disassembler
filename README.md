
# Disassembler
C++ class for disassembling Intel x86 assembly.

### Disclaimer
This is not production-worthy code! View this simply as a proof-of-concept.

### Note
The `.hpp` versions of the classes utilize C++ structures such as std::vector, std::string, std::stringstream, and std::cout while the `.h` versions of the classes do not. These classes are substantially faster (approximately 12.3 times faster).

### Initialization
```C++
Disassembler(byte * opcodes, int length);
```
A `Disassembler` can be initialized by including the buffer of opcodes and the length of the buffer. The buffer is not copied into the object.

### Print
```C++
void Print()
```
This method converts the opcode buffer to Intel x86 Assembly language and prints it to the standard output stream.

### Example
```C++
#include "Disassembler.h"
#include "PortableExecutable.h"

int main()
{
	PortableExecutable pe("Test.exe");

	Disassembler disasm((char *)pe.GetSection(".text")->Data, pe.GetSection(".text")->Length);

	disasm.Print();
	
	return 0;
}
```
This example takes a sample executable called "Test.exe" and loads the ".text" section into the `Disassembler` and disassembles it. The `startingAddress` is equal to the `AddressOfEntryPoint` minus the `VirtualAddress` of the ".text" section (because `VirtualAddress` is the zero of the buffer to be disassembled). 20 instructions are disassembled and the `baseAddress` is equal to the `VirtualAddress` of the ".text" section.

### Output
```
...
0x0000B180: 55                      PUSH   EBP
0x0000B181: 8B EC                   MOV    EBP, ESP
0x0000B183: 6A FF                   PUSH   FFh
0x0000B185: 68 50 78 43 00          PUSH   00437850h
0x0000B18A: 64 A1 00 00 00 00       MOV    EAX, FS:00000000h
0x0000B190: 50                      PUSH   EAX
0x0000B191: 81 EC CC 00 00 00       SUB    ESP, 000000CCh
0x0000B197: 53                      PUSH   EBX
0x0000B198: 56                      PUSH   ESI
0x0000B199: 57                      PUSH   EDI
0x0000B19A: 51                      PUSH   ECX
0x0000B19B: 8D BD 28 FF FF FF       LEA    EDI, [EBP + FFFFFF28h]
0x0000B1A1: B9 33 00 00 00          MOV    ECX, 00000033h
0x0000B1A6: B8 CC CC CC CC          MOV    EAX, CCCCCCCCh
0x0000B1AB: F3 AB                   STOS   DWORD PTR ES:[EDI], EAX
0x0000B1AD: 59                      POP    ECX
0x0000B1AE: A1 30 45 44 00          MOV    EAX, DS:00444530h
0x0000B1B3: 33 C5                   XOR    EAX, EBP
0x0000B1B5: 50                      PUSH   EAX
0x0000B1B6: 8D 45 F4                LEA    EAX, [EBP + F4h]
0x0000B1B9: 64 A3 00 00 00 00       MOV    FS:00000000h, EAX
0x0000B1BF: 89 4D EC                MOV    DWORD PTR [EBP + ECh], ECX
0x0000B1C2: 8B 4D EC                MOV    ECX, DWORD PTR [EBP + ECh]
0x0000B1C5: E8 0C 50 FF FF          CALL   000001D6h
0x0000B1CA: 8B 4D EC                MOV    ECX, DWORD PTR [EBP + ECh]
0x0000B1CD: E8 9A 5A FF FF          CALL   00000C6Ch
0x0000B1D2: 8B 45 EC                MOV    EAX, DWORD PTR [EBP + ECh]
0x0000B1D5: 8B 4D F4                MOV    ECX, DWORD PTR [EBP + F4h]
0x0000B1D8: 64 89 0D 00 00 00 00    MOV    DWORD PTR FS:[00000000h], ECX
0x0000B1DF: 59                      POP    ECX
0x0000B1E0: 5F                      POP    EDI
0x0000B1E1: 5E                      POP    ESI
0x0000B1E2: 5B                      POP    EBX
0x0000B1E3: 81 C4 D8 00 00 00       ADD    ESP, 000000D8h
0x0000B1E9: 3B EC                   CMP    EBP, ESP
0x0000B1EB: E8 24 53 FF FF          CALL   00000514h
0x0000B1F0: 8B E5                   MOV    ESP, EBP
0x0000B1F2: 5D                      POP    EBP
0x0000B1F3: C3                      RET
...
```
Since the executable I selected in the above example went to a jump table, I just picked a random function in "Test.exe" to show as example output.
