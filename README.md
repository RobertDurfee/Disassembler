
# Disassembler
C++ class for disassembling Intel x86 assembly.

### Disclaimer
This is not production-worthy code! View this simply as a proof-of-concept.

This project is not yet completed as two-byte and three-byte opcodes are not supported and prefixes are not printed.

### Initialization
```C++
Disassembler(byte * opcodes, int length);
```
A `Disassembler` can be initialized by including the buffer of opcodes and the length of the buffer. The buffer is not copied into the object.

### Instructions
```C++
Instruction ** Instructions(int * numberOfInstructions);
```
This method converts the opcode buffer to Intel x86 Assembly language where each instruction is a element of an array of instructions. The number of instructions to output is specified through `numberOfInstructions`. If this number is `-1`, all instructions are output and after the method finishes executing, the number of instructions output is in `numberOfInstructions`. If this number is greater than the number of instructions, the `numberOfInstructions` will contain the actual number of instructions output.

### Strings
```C++
char ** Strings(int * numberOfLines);
```
This method converts the opcode buffer to Intel x86 Assembly language where each line is a element of an array of character pointers. The number of lines to output is specified through `numberOfLines`. If this number is `-1`, all lines are output and after the method finishes executing, the number of lines output is in `numberOfLines`. If this number is greater than the number of lines of instructions, the `numberOfLines` will contain the actual number of lines output. (The output is not a simple string as the time to execute would grow exponentially which is unrealistic. This output should be just as easy to process.)

### Print
```C++
void Print();
```
This method converts the opcode buffer to Intel x86 Assembly language and prints it to the standard output stream.

### Example
```C++
#include "Disassembler.h"
#include "PortableExecutable.h"

int main()
{
	PortableExecutable pe("Test.exe");

	Disassembler disasm(pe.GetSection(".text")->Data, pe.GetSection(".text")->Length);

	disasm.Print();
	
	return 0;
}
```
This example takes a sample executable called "Test.exe" and loads the ".text" section into the `Disassembler` and disassembles it, printing the results to the standard output stream.

### Output
```
0x00000000: 55                      PUSH   EBP
0x00000001: 8B EC                   MOV    EBP, ESP
0x00000003: 6A FF                   PUSH   FFh
0x00000005: 68 F2 7C 43 00          PUSH   00437CF2h
0x0000000A: 64 A1 00 00 00 00       MOV    EAX, FS:00000000h
0x00000010: 50                      PUSH   EAX
0x00000011: 81 EC E8 00 00 00       SUB    ESP, 000000E8h
0x00000017: 53                      PUSH   EBX
0x00000018: 56                      PUSH   ESI
0x00000019: 57                      PUSH   EDI
0x0000001A: 51                      PUSH   ECX
0x0000001B: 8D BD 0C FF FF FF       LEA    EDI, [EBP + FFFFFF0Ch]
0x00000021: B9 3A 00 00 00          MOV    ECX, 0000003Ah
0x00000026: B8 CC CC CC CC          MOV    EAX, CCCCCCCCh
0x0000002B: F3 AB                   STOS   ES:[EDI], EAX
0x0000002D: 59                      POP    ECX
0x0000002E: A1 30 45 44 00          MOV    EAX, DS:00444530h
0x00000033: 33 C5                   XOR    EAX, EBP
0x00000035: 50                      PUSH   EAX
0x00000036: 8D 45 F4                LEA    EAX, [EBP + F4h]
0x00000039: 64 A3 00 00 00 00       MOV    FS:00000000h, EAX
0x0000003F: 89 4D EC                MOV    DWORD PTR [EBP + ECh], ECX
0x00000042: 6A 18                   PUSH   18h
0x00000044: E8 BC DD FE FF          CALL   FFFEDE05h
0x00000049: 83 C4 04                ADD    ESP, 04h
0x0000004C: 89 85 14 FF FF FF       MOV    DWORD PTR [EBP + FFFFFF14h], EAX
0x00000052: C7 45 FC 00 00 00 00    MOV    DWORD PTR [EBP + FCh], 00000000h
0x00000059: 83 BD 14 FF FF FF 00    CMP    DWORD PTR [EBP + FFFFFF14h], 00h
0x00000060: 74 2E                   JZ     90h
0x00000062: 6A 18                   PUSH   18h
0x00000064: 8B 8D 14 FF FF FF       MOV    ECX, DWORD PTR [EBP + FFFFFF14h]
0x0000006A: E8 4D E0 FE FF          CALL   FFFEE0BCh
0x0000006F: 8B 45 EC                MOV    EAX, DWORD PTR [EBP + ECh]
0x00000072: 8B 08                   MOV    ECX, DWORD PTR [EAX]
0x00000074: 51                      PUSH   ECX
0x00000075: 8B 55 0C                MOV    EDX, DWORD PTR [EBP + 0Ch]
0x00000078: 52                      PUSH   EDX
0x00000079: 8B 45 08                MOV    EAX, DWORD PTR [EBP + 08h]
0x0000007C: 50                      PUSH   EAX
0x0000007D: 8B 8D 14 FF FF FF       MOV    ECX, DWORD PTR [EBP + FFFFFF14h]
0x00000083: E8 A7 E0 FE FF          CALL   FFFEE12Fh
0x00000088: 89 85 0C FF FF FF       MOV    DWORD PTR [EBP + FFFFFF0Ch], EAX
0x0000008E: EB 0A                   JMP    9Ah
0x00000090: C7 85 0C FF FF FF 00 +  MOV    DWORD PTR [EBP + FFFFFF0Ch], 00000000h
0x0000009A: 8B 8D 0C FF FF FF       MOV    ECX, DWORD PTR [EBP + FFFFFF0Ch]
0x000000A0: 89 8D 20 FF FF FF       MOV    DWORD PTR [EBP + FFFFFF20h], ECX
0x000000A6: C7 45 FC FF FF FF FF    MOV    DWORD PTR [EBP + FCh], FFFFFFFFh
0x000000AD: 8B 55 EC                MOV    EDX, DWORD PTR [EBP + ECh]
0x000000B0: 8B 85 20 FF FF FF       MOV    EAX, DWORD PTR [EBP + FFFFFF20h]
0x000000B6: 89 42 20                MOV    DWORD PTR [EDX + 20h], EAX
0x000000B9: 8B 4D F4                MOV    ECX, DWORD PTR [EBP + F4h]
0x000000BC: 64 89 0D 00 00 00 00    MOV    DWORD PTR FS:[00000000h], ECX
0x000000C3: 59                      POP    ECX
0x000000C4: 5F                      POP    EDI
0x000000C5: 5E                      POP    ESI
0x000000C6: 5B                      POP    EBX
0x000000C7: 81 C4 F4 00 00 00       ADD    ESP, 000000F4h
0x000000CD: 3B EC                   CMP    EBP, ESP
0x000000CF: E8 30 D9 FE FF          CALL   FFFEDA04h
0x000000D4: 8B E5                   MOV    ESP, EBP
0x000000D6: 5D                      POP    EBP
0x000000D7: C2 08 00                RET    0008h
```
Since the executable I selected in the above example went to a jump table, I just picked a random function in "Test.exe" to show as example output.
### Output Comparison
```
       0:   55                      push   ebp
       1:   8b ec                   mov    ebp,esp
       3:   6a ff                   push   0xffffffff
       5:   68 f2 7c 43 00          push   0x437cf2
       a:   64 a1 00 00 00 00       mov    eax,fs:0x0
      10:   50                      push   eax
      11:   81 ec e8 00 00 00       sub    esp,0xe8
      17:   53                      push   ebx
      18:   56                      push   esi
      19:   57                      push   edi
      1a:   51                      push   ecx
      1b:   8d bd 0c ff ff ff       lea    edi,[ebp-0xf4]
      21:   b9 3a 00 00 00          mov    ecx,0x3a
      26:   b8 cc cc cc cc          mov    eax,0xcccccccc
      2b:   f3 ab                   rep stos DWORD PTR es:[edi],eax
      2d:   59                      pop    ecx
      2e:   a1 30 45 44 00          mov    eax,ds:0x444530
      33:   33 c5                   xor    eax,ebp
      35:   50                      push   eax
      36:   8d 45 f4                lea    eax,[ebp-0xc]
      39:   64 a3 00 00 00 00       mov    fs:0x0,eax
      3f:   89 4d ec                mov    DWORD PTR [ebp-0x14],ecx
      42:   6a 18                   push   0x18
      44:   e8 bc dd fe ff          call   0xfffede05
      49:   83 c4 04                add    esp,0x4
      4c:   89 85 14 ff ff ff       mov    DWORD PTR [ebp-0xec],eax
      52:   c7 45 fc 00 00 00 00    mov    DWORD PTR [ebp-0x4],0x0
      59:   83 bd 14 ff ff ff 00    cmp    DWORD PTR [ebp-0xec],0x0
      60:   74 2e                   je     0x90
      62:   6a 18                   push   0x18
      64:   8b 8d 14 ff ff ff       mov    ecx,DWORD PTR [ebp-0xec]
      6a:   e8 4d e0 fe ff          call   0xfffee0bc
      6f:   8b 45 ec                mov    eax,DWORD PTR [ebp-0x14]
      72:   8b 08                   mov    ecx,DWORD PTR [eax]
      74:   51                      push   ecx
      75:   8b 55 0c                mov    edx,DWORD PTR [ebp+0xc]
      78:   52                      push   edx
      79:   8b 45 08                mov    eax,DWORD PTR [ebp+0x8]
      7c:   50                      push   eax
      7d:   8b 8d 14 ff ff ff       mov    ecx,DWORD PTR [ebp-0xec]
      83:   e8 a7 e0 fe ff          call   0xfffee12f
      88:   89 85 0c ff ff ff       mov    DWORD PTR [ebp-0xf4],eax
      8e:   eb 0a                   jmp    0x9a
      90:   c7 85 0c ff ff ff 00    mov    DWORD PTR [ebp-0xf4],0x0
      97:   00 00 00
      9a:   8b 8d 0c ff ff ff       mov    ecx,DWORD PTR [ebp-0xf4]
      a0:   89 8d 20 ff ff ff       mov    DWORD PTR [ebp-0xe0],ecx
      a6:   c7 45 fc ff ff ff ff    mov    DWORD PTR [ebp-0x4],0xffffffff
      ad:   8b 55 ec                mov    edx,DWORD PTR [ebp-0x14]
      b0:   8b 85 20 ff ff ff       mov    eax,DWORD PTR [ebp-0xe0]
      b6:   89 42 20                mov    DWORD PTR [edx+0x20],eax
      b9:   8b 4d f4                mov    ecx,DWORD PTR [ebp-0xc]
      bc:   64 89 0d 00 00 00 00    mov    DWORD PTR fs:0x0,ecx
      c3:   59                      pop    ecx
      c4:   5f                      pop    edi
      c5:   5e                      pop    esi
      c6:   5b                      pop    ebx
      c7:   81 c4 f4 00 00 00       add    esp,0xf4
      cd:   3b ec                   cmp    ebp,esp
      cf:   e8 30 d9 fe ff          call   0xfffeda04
      d4:   8b e5                   mov    esp,ebp
      d6:   5d                      pop    ebp
      d7:   c2 08 00                ret    0x8
```
Provided is the output from `objdump` to affirm legitimacy.
