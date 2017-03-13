#ifndef DISASSEMBLER_TYPES_HEADER
#define DISASSEMBLER_TYPES_HEADER

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;

template<typename T>
//Returns a value of type byte, word, or dword from a byte array at 'index' advancing 'index' depending on the size of the value read.
T Select(byte * source, int * index)
{
	int i = *index;

	*index += sizeof(T);

	return *(T *)&source[i];
}

template<typename T>
//Returns a value of type byte, word, or dword from a byte array at 'index' without affecting the value of 'index'.
T Peek(byte * source, int * index)
{
	return *(T *)&source[*index];
}

#endif