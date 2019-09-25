################################################################################
# Summary ######################################################################
################################################################################

This is a simple demonstration of the Disassembler. The file `Example.cpp` will
load in a binary file `Example.bin` which is the bytecode for the following
super-simple 32-bit C program:
```
int main()
{
    return 0;
}
```

################################################################################
# Build Instructions ###########################################################
################################################################################

To build the disassembler, type:
```
make
```

To make the binary file `Example.bin`, type:
```
chmod +x Example.sh
./Example.sh
```
This script simply constructs the binary file by hand using escape characters.

################################################################################
# Run Instructions #############################################################
################################################################################

To run, type:
```
./Example
```

################################################################################
# Expected Behavior ############################################################
################################################################################

The following output should be produced after running:
```
0x00000000: 55                      PUSH   EBP
0x00000001: 8B EC                   MOV    EBP, ESP
0x00000003: B8 00 00 00 00          MOV    EAX, 00000000h
0x00000008: 5D                      POP    EBP
0x00000009: C3                      RET    
```
