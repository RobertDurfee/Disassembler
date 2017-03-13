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

#include <stdlib.h>                    //malloc(), free()
#include <stdio.h>                     //sprintf()
#include <string.h>                    //strlen(), memcpy()

void Append(char ** front, char * back)
{
	int frontLength;
	if (*front != NULL)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength;
	if (back != NULL)
		backLength = strlen(back);
	else
		backLength = 0;

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != NULL)
		memcpy(output, *front, frontLength);

	if (back != NULL)
		memcpy(&output[frontLength], back, backLength + 1);
	else
		output[frontLength] = '\0';

	free(back);
	free(*front);

	*front = output;
}
void Append(char ** front, const char * back)
{
	int frontLength;
	if (*front != NULL)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength;
	if (back != NULL)
		backLength = strlen(back);
	else
		backLength = 0;

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != NULL)
		memcpy(output, *front, frontLength);

	if (back != NULL)
		memcpy(&output[frontLength], back, backLength + 1);
	else
		output[frontLength] = '\0';

	free(*front);

	*front = output;
}
void Append(char ** front, char * format, dword back)
{
	int frontLength;
	if (*front != NULL)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength = snprintf(NULL, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != NULL)
		memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(*front);

	*front = output;
}
void Append(char ** front, char * format, char * back)
{
	int frontLength;
	if (*front != NULL)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength = snprintf(NULL, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != NULL)
		memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(back);
	free(*front);

	*front = output;
}
void Append(char ** front, char * format, const char * back)
{
	int frontLength;
	if (*front != NULL)
		frontLength = strlen(*front);
	else
		frontLength = 0;
	int backLength = snprintf(NULL, 0, format, back);

	char * output = (char *)malloc(frontLength + backLength + 1);

	if (*front != NULL)
		memcpy(output, *front, frontLength);

	sprintf(&output[frontLength], format, back);

	free(*front);

	*front = output;
}

void RemoveLast(char ** string, int count) //free()
{
	if (*string != NULL)
	{
		int length = strlen(*string);
		char * output = (char *)malloc(length - count + 1);
		memcpy(output, *string, length - count);
		output[length - count] = '\0';

		if (*string != NULL)
			free(*string);

		*string = output;
	}
}

#endif