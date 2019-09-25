#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include "../DisassemblerTypes.h"
#include "../Disassembler.h"

int main()
{
  // Load bytes from test file
  std::vector<unsigned char> bytes;
  std::ifstream test_file("./Example.bin", std::ios_base::in | std::ios_base::binary);
  unsigned char c = test_file.get();
  while (test_file.good())
  {
    bytes.push_back(c);
    c = test_file.get();
  }

  // Convert to simple array
  byte opcodes[bytes.size()];
  for (unsigned int i = 0; i < bytes.size(); i++)
    opcodes[i] = bytes[i];

  Disassembler disasm(opcodes, bytes.size());

  disasm.Print();

  return 0;
}
