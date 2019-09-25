################################################################################
# Summary ######################################################################
################################################################################

This program is a simple linear-sweep disassembler for 32-bit binaries.

################################################################################
# Known Issues #################################################################
################################################################################

- The disassembly output is in pseudo-Intel syntax. (There are some minor
  inconsistencies like the use of all uppercase letters instead of lowercase,
  etc.) 
- Many modern and two-byte opcodes are not handled in this implementation.
- If an opcode cannot be decoded, it's likely the remaining opcodes will be
  improperly decoded because of the linear-sweep behavior.
- Prefixes (like REPNE) are handled, but not output to the screen.
- The design of this program is not very good. There's a lot of global state
  and methods with side effects going on here. This was implemented prior to
  formal education in design patterns and OOP. This does, however, act as a
  reasonable indicator of my understanding of C/C++. But, if demonstration of
  knowledge of OOP and design patterns is wanted, please look at some of my
  more recent projects.

################################################################################
# Build Instructions ###########################################################
################################################################################

This was not designed to be a standalone project. Rather, it was meant to be
included into other projects as a library of sorts. As a result, please look in
the `Example` folder for a demonstration of how this project could be used.

For more information about different methods in `Disassembler`, take a look at
the `README.md` file.

If the target binaries are from Windows, the `PortableExecutable.h` also
provides some helpful methods for parsing the binaries. If in Linux, however,
I never implemented ELF support, which is why the Example uses hand-written
bytecode.

