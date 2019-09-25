#ifndef PORTABLE_EXECUTABLE_HEADER
#define PORTABLE_EXECUTABLE_HEADER

struct EXECUTABLE_DOS_HEADER
{
	unsigned short MagicNumber;
	unsigned short UsedBytesInTheLastPage;
	unsigned short FileSizeInPages;
	unsigned short NumberOfRelocationItems;
	unsigned short HeaderSizeInParagraphs;
	unsigned short MinimumExtraParagraphs;
	unsigned short MaximumExtraParagraphs;
	unsigned short InitialRelativeSS;
	unsigned short InitialSP;
	unsigned short Checksum;
	unsigned short InitialIP;
	unsigned short InitialRelativeCS;
	unsigned short AddressOfRelocationTable;
	unsigned short OverlayNumber;
	unsigned short Reserved1[4];
	unsigned short OEMID;
	unsigned short OEMInfo;
	unsigned short Reserved2[10];
	unsigned long AddressOfNewEXEHeader;
};

struct EXECUTABLE_FILE_HEADER
{
	unsigned long FileType;
	unsigned short Machine;
	unsigned short NumberOfSections;
	unsigned long TimeDateStamp;
	unsigned long PointToSymbolTable;
	unsigned long NumberOfSymbols;
	unsigned short SizeOfOptionalHeader;
	unsigned short Characteristics;
};

struct EXECUTABLE_DATA_DIRECTORY
{
	unsigned long VirtualAddress;
	unsigned long Size;
};

struct EXECUTABLE_OPTIONAL_HEADER
{
	unsigned short Magic;
	unsigned char MajorLinkerVersion;
	unsigned char MinorLinkerVersion;
	unsigned long SizeOfCode;
	unsigned long SizeOfInitializedData;
	unsigned long SizeOfUninitializedData;
	unsigned long AddressOfEntryPoint;
	unsigned long BaseOfCode;
	unsigned long BaseOfData;
	unsigned long ImageBase;
	unsigned long SectionAlignment;
	unsigned long FileAlignment;
	unsigned short MajorOperatingSystemVersion;
	unsigned short MinorOperatingSystemVersion;
	unsigned short MajorImageVersion;
	unsigned short MinorImageVersion;
	unsigned short MajorSubsystemVersion;
	unsigned short MinorSubsystemVersion;
	unsigned long Reserved;
	unsigned long SizeOfImage;
	unsigned long SizeOfHeaders;
	unsigned long CheckSum;
	unsigned short SubSystem;
	unsigned short DllCharacteristics;
	unsigned long SizeOfStackReserve;
	unsigned long SizeOfStackCommit;
	unsigned long SizeOfHeapReserve;
	unsigned long SizeOfHeapCommit;
	unsigned long LoaderFlags;
	unsigned long NumberOfDirectories;
	EXECUTABLE_DATA_DIRECTORY DataDirectory[16];
};

struct EXECUTABLE_SECTION_HEADER
{
	unsigned char Name[8];
	unsigned long VirtualSize;
	unsigned long VirtualAddress;
	unsigned long SizeOfRawData;
	unsigned long PointerToRawData;
	unsigned long PointerToRelocations;
	unsigned long PointerToLineNumbers;
	unsigned short NumberOfRelocations;
	unsigned short NumberOfLineNumbers;
	unsigned long Characteristics;
#define EXECUTABLE_SECTION_HEADER_NO_PAD                0x00000008
#define EXECUTABLE_SECTION_HEADER_CODE                  0x00000020
#define EXECUTABLE_SECTION_HEADER_INITIALIZED_DATA      0x00000040
#define EXECUTABLE_SECTION_HEADER_UNINITIALIZED_DATA    0x00000080
#define EXECUTABLE_SECTION_HEADER_OTHER                 0x00000100
#define EXECUTABLE_SECTION_HEADER_INFO                  0x00000200
#define EXECUTABLE_SECTION_HEADER_REMOVE                0x00000800
#define EXECUTABLE_SECTION_HEADER_COMDAT                0x00001000
#define EXECUTABLE_SECTION_HEADER_NO_DEFER_SPEC_EXC     0x00004000
#define EXECUTABLE_SECTION_HEADER_SHORT                 0x00008000
#define EXECUTABLE_SECTION_HEADER_PURGEABLE             0x00020000
#define EXECUTABLE_SECTION_HEADER_LOCKED                0x00040000
#define EXECUTABLE_SECTION_HEADER_PRELOAD               0x00080000
#define EXECUTABLE_SECTION_HEADER_EXTENDED_RELOCATIONS  0x01000000
#define EXECUTABLE_SECTION_HEADER_DISCARDABLE           0x02000000
#define EXECUTABLE_SECTION_HEADER_NOT_CACHED            0x04000000
#define EXECUTABLE_SECTION_HEADER_NOT_PAGED             0x08000000
#define EXECUTABLE_SECTION_HEADER_SHARED                0x10000000
#define EXECUTABLE_SECTION_HEADER_EXECUTE               0x20000000
#define EXECUTABLE_SECTION_HEADER_READ                  0x40000000
#define EXECUTABLE_SECTION_HEADER_WRITE                 0x80000000
};

struct Section
{
	unsigned char * Data;
	unsigned long Length;
};

#define DOS_HEADER          0x00000001
#define FILE_HEADER         0x00000002
#define OPTIONAL_HEADER     0x00000004
#define SECTION_HEADER      0x00000008
#define SECTION_DATA        0x00000010

using namespace std;

class PortableExecutable
{
public:
	PortableExecutable();
	PortableExecutable(string filename);

	~PortableExecutable();

	void Open(string filename);
	void Save(string filename);

	string ToString(int command);
	
	template<typename T>
	T * GetHeader(int command);
	Section * GetSection(int sectionNumber);
	Section * GetSection(string sectionName);
	int GetSectionNumber(string sectionName);

private:
	EXECUTABLE_DOS_HEADER dosHeader;
	unsigned char * DOSProgram = nullptr;
	EXECUTABLE_FILE_HEADER fileHeader;
	EXECUTABLE_OPTIONAL_HEADER optionalHeader;
	
	EXECUTABLE_SECTION_HEADER * sectionHeaders = nullptr;
	Section * sections = nullptr;
};

#endif
