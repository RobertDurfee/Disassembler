#ifndef DISASSEMBLER_FUNCTIONS_HEADER
#define DISASSEMBLER_FUNCTIONS_HEADER

#define _CRT_SECURE_NO_WARNINGS //Necessary to use snprintf() and sprintf()

#include "DisassemblerTypes.h" //byte, word, dword

#include <stdlib.h>            //malloc(), free()
#include <string.h>            //strlen(), memcpy()
#include <stdio.h>             //sprintf(), snprintf()

template<typename T>
//Returns a value of type byte, word, or dword from a byte array at 'index' advancing 'index' depending on the size of the value read.
T Select(byte * source, int * index)
{
	int i = *index;

	*index += sizeof(T);

	return *(T *)&source[i];
}

//'back' must have been allocated using malloc()
void Append(char ** front, char * back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = (back == nullptr) ? 0 : strlen(back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	if (back != nullptr)
		memcpy(&output[frontLength], back, backLength + 1);
	else
		output[frontLength] = '\0';

	free(back);
	free(*front);

	*front = output;
}
//Same as above except 'back' is not allocated using malloc()
void Append(char ** front, const char * back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = (back == nullptr) ? 0 : strlen(back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr) memcpy(output, *front, frontLength);

	if (back != nullptr)
		memcpy(&output[frontLength], back, backLength + 1);
	else
		output[frontLength] = '\0';

	free(*front);

	*front = output;
}
void Append(char ** front, char * format, dword back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = snprintf(nullptr, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(*front);

	*front = output;
}
//'back' must have been allocated using malloc()
void Append(char ** front, char * format, char * back)
{
	int frontLength = (*front == nullptr) ? 0 : strlen(*front);
	int backLength = snprintf(nullptr, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)	memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(back);
	free(*front);

	*front = output;
}
//Same as above except 'back' is not allocated using malloc()
void Append(char ** front, char * format, const char * back)
{
	int frontLength;
	if (*front != nullptr)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength = snprintf(nullptr, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != nullptr)
		memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(*front);

	*front = output;
}

//Output must be freed by calling free()
void RemoveLast(char ** string, int count)
{
	if (*string != nullptr)
	{
		int length = strlen(*string);

		char * output = (char *)malloc(length - count + 1);

		memcpy(output, *string, length - count);

		output[length - count] = '\0';

		free(*string);

		*string = output;
	}
}

#endif