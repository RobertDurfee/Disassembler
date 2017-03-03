
# Disassembler
C++ class for disassembling Intel x86 assembly.

### Disclaimer
CThis is not production-worthy code! View this simply as a proof-of-concept.

In addition, I'd like to apologize to anyone who reads this code. I wrote this a few years ago when I was about 14-years-old. When I look at this code now, I want to cry. I am going to try to improve this code later on but it may too big of a task for right now. I am putting it on Github nonetheless, as it is an important project of my past and I don't want to lose it.

### Initialization
```C++
Disassembler();
Disassembler(char * input, int length);
```
A `Disassembler` can be initialized by default--where the buffer must be set later--or by including the buffer and the length right away. The buffer is copied into the object. (This may change in the future.)
E
### Disassemble
```C++
string Disassemble(int startingAddress = 0, int length = -1, int instructions = -1, int flags = 0, int baseAddress = 0)
```
The `Disassemble` method converts the buffer into Intel x86 Assembly language. 

The output can be a string (specified through the `flags` with `DISASSEMBLE_STRING`), printed to the standard output stream (specified through the `flags` with `DISASSEMBLE_PRINT`), or neither (leaving `flags` empty). 

The `startingAddress` tells the method where to start within the buffer relative to the beginning. 
S
The `length` tells the method how many bytes to read from the buffer. 

The `instruction` tells the method how many instructions to disassemble. 

The `baseAddress` tells the disassembler what the address of the first instruction should be when printed to a string or the standard output stream. 

### Setters
```C++
void SetBuffer(char * input, int length)
```
If the buffer needs to be changed after instantiation or has not been set yet, this method can be called. It sets `input` as the buffer to be disassembled and `length` to the size of the buffer. This method is called by the second constructor.

### Deinitialization
```C++
~Disassembler()
```
Since the buffer is copied into the object, this must be freed when destructed. This is accomplished by this method.

### Example
```C++
#include "Disassembler.h"
#include "PortableExecutable.h"

int main()
{
	PortableExecutable pe("Test.exe");

	Disassembler disasm((char *)pe.GetSection(".text")->Data, pe.GetSection(".text")->Length);

	disasm.Disassemble(pe.GetHeader<EXECUTABLE_OPTIONAL_HEADER>(OPTIONAL_HEADER)->AddressOfEntryPoint - pe.GetHeader<EXECUTABLE_SECTION_HEADER>(SECTION_HEADER | (pe.GetSectionNumber(".text") << 16))->VirtualAddress, -1, 20, DISASSEMBLER_PRINT, pe.GetHeader<EXECUTABLE_SECTION_HEADER>(SECTION_HEADER | (pe.GetSectionNumber(".text") << 16))->VirtualAddress);

	return 0;
}
```
This example takes a sample executable called "Test.exe" and loads the ".text" section into the `Disassembler` and disassembles it. The `startingAddress` is equal to the `AddressOfEntryPoint` minus the `VirtualAddress` of the ".text" section (because `VirtualAddress` is the zero of the buffer to be disassembled). 20 instructions are disassembled and the `baseAddress` is equal to the `VirtualAddress` of the ".text" section.

### Output
```
...
0x000029e0: 55                 push     ebp
0x000029e1: 8b ec              mov      ebp, esp
0x000029e3: 81 ec cc 00 00 00  sub      esp, 000000cch
0x000029e9: 53                 push     ebx
0x000029ea: 56                 push     esi
0x000029eb: 57                 push     edi
0x000029ec: 51                 push     ecx
0x000029ed: 8d bd 34 ff ff ff  lea      edi, [ebp + ffffff34h]
0x000029f3: b9 33 00 00 00     mov      ecx, 00000033h
0x000029f8: b8 cc cc cc cc     mov      eax, cccccccch
0x000029fd: f3 ab              stosd
0x000029ff: 59                 pop      ecx
0x00002a00: 89 4d f8           mov      [ebp + f8h], ecx
0x00002a03: 8b 4d f8           mov      ecx, [ebp + f8h]
0x00002a06: e8 2b d7 ff ff     call     0x00000136
0x00002a0b: 8b 4d f8           mov      ecx, [ebp + f8h]
0x00002a0e: e8 15 d6 ff ff     call     0x00000028
0x00002a13: 8b 45 f8           mov      eax, [ebp + f8h]
0x00002a16: 5f                 pop      edi
0x00002a17: 5e                 pop      esi
0x00002a18: 5b                 pop      ebx
0x00002a19: 81 c4 cc 00 00 00  add      esp, 000000cch
0x00002a1f: 3b ec              cmp      ebp, esp
0x00002a21: e8 f5 dd ff ff     call     0x0000081b
0x00002a26: 8b e5              mov      esp, ebp
0x00002a28: 5d                 pop      ebp
0x00002a29: c2 04 00           ret      0004h
...
```
Since the executable I selected in the above example went to a jump table, I just picked a random function in "Test.exe" to show as example output.
