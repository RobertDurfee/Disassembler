
# Disassembler
C++ class for disassembling Intel x86 assembly.

### Disclaimer
This is not production-worthy code! View this simply as a proof-of-concept.

### Speed Comparison
The `.hpp` versions of the classes utilize C++ structures such as std::vector, std::string, std::stringstream, and std::cout while the `.h` versions of the classes do not. These classes are substantially faster:

* Old Disassembler: 145.2145 seconds
* C++ Disassembler: 174.4245 seconds
* C   Disassembler:  13.3595 seconds

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
### Output Comparison
```   0:   55                      push   ebp
   1:   8b ec                   mov    ebp,esp
   3:   6a ff                   push   0xffffffff
   5:   68 50 78 43 00          push   0x437850
   a:   64 a1 00 00 00 00       mov    eax,fs:0x0
  10:   50                      push   eax
  11:   81 ec cc 00 00 00       sub    esp,0xcc
  17:   53                      push   ebx
  18:   56                      push   esi
  19:   57                      push   edi
  1a:   51                      push   ecx
  1b:   8d bd 28 ff ff ff       lea    edi,[ebp-0xd8]
  21:   b9 33 00 00 00          mov    ecx,0x33
  26:   b8 cc cc cc cc          mov    eax,0xcccccccc
  2b:   f3 ab                   rep stos DWORD PTR es:[edi],eax
  2d:   59                      pop    ecx
  2e:   a1 30 45 44 00          mov    eax,ds:0x444530
  33:   33 c5                   xor    eax,ebp
  35:   50                      push   eax
  36:   8d 45 f4                lea    eax,[ebp-0xc]
  39:   64 a3 00 00 00 00       mov    fs:0x0,eax
  3f:   89 4d ec                mov    DWORD PTR [ebp-0x14],ecx
  42:   8b 4d ec                mov    ecx,DWORD PTR [ebp-0x14]
  45:   e8 0c 50 ff ff          call   0xffff5056
  4a:   8b 4d ec                mov    ecx,DWORD PTR [ebp-0x14]
  4d:   e8 9a 5a ff ff          call   0xffff5aec
  52:   8b 45 ec                mov    eax,DWORD PTR [ebp-0x14]
  55:   8b 4d f4                mov    ecx,DWORD PTR [ebp-0xc]
  58:   64 89 0d 00 00 00 00    mov    DWORD PTR fs:0x0,ecx
  5f:   59                      pop    ecx
  60:   5f                      pop    edi
  61:   5e                      pop    esi
  62:   5b                      pop    ebx
  63:   81 c4 d8 00 00 00       add    esp,0xd8
  69:   3b ec                   cmp    ebp,esp
  6b:   e8 24 53 ff ff          call   0xffff5394
  70:   8b e5                   mov    esp,ebp
  72:   5d                      pop    ebp
  73:   c3                      ret
```
Provided is the output from `objdump` to affirm legitimacy.
