#ifndef MOD_REG_RM_STRINGS_HEADER
#define MOD_REG_RM_STRINGS_HEADER

#ifndef STRING_SIZE_OFFSETS
#define STRING_SIZE_OFFSETS

	#define EIGHT_BIT     0 +
	#define SIXTEEN_BIT   1 +
	#define THIRTYTWO_BIT 2 +

#endif

#ifndef GENERAL_REGISTER_STRING
#define GENERAL_REGISTER_STRING
extern const char * GeneralRegisterString[24];
#endif

extern const char * RMString[24];

#ifndef SEGMENT_REGISTER_STRING
#define SEGMENT_REGISTER_STRING
extern const char * SegmentRegisterString[24];
#endif

#endif
