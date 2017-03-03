#ifndef PORTABLE_EXECUTABLE_HEADER
#define PORTABLE_EXECUTABLE_HEADER

#include <iostream>     //cout, endl
#include <fstream>      //ifstream, ofstream
#include <sstream>      //stringstream

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
	unsigned char * DOSProgram;
	EXECUTABLE_FILE_HEADER fileHeader;
	EXECUTABLE_OPTIONAL_HEADER optionalHeader;
	
	EXECUTABLE_SECTION_HEADER * sectionHeaders;
	Section * sections;
};

PortableExecutable::PortableExecutable()
{

}
PortableExecutable::PortableExecutable(string filename)
{
	Open(filename);
}
PortableExecutable::~PortableExecutable()
{
	delete[] DOSProgram;
	for (int i = 0; i < fileHeader.NumberOfSections; i++)
		delete[] sections[i].Data;
	delete[] sectionHeaders;
	delete[] sections;
}
void PortableExecutable::Open(string filename)
{
	this->~PortableExecutable();

	ifstream ifile(filename, ios::binary);

	ifile.read((char *)&dosHeader, sizeof(EXECUTABLE_DOS_HEADER));

	DOSProgram = new unsigned char[dosHeader.AddressOfNewEXEHeader - sizeof(EXECUTABLE_DOS_HEADER)];

	ifile.read((char *)DOSProgram, dosHeader.AddressOfNewEXEHeader - sizeof(EXECUTABLE_DOS_HEADER));

	ifile.read((char *)&fileHeader, sizeof(EXECUTABLE_FILE_HEADER));

	ifile.read((char *)&optionalHeader, sizeof(EXECUTABLE_OPTIONAL_HEADER));

	sectionHeaders = new EXECUTABLE_SECTION_HEADER[fileHeader.NumberOfSections];

	for (int i = 0; i < fileHeader.NumberOfSections; i++)
		ifile.read((char *)&sectionHeaders[i], sizeof(EXECUTABLE_SECTION_HEADER));

	sections = new Section[fileHeader.NumberOfSections];

	for (int i = 0; i < fileHeader.NumberOfSections; i++)
	{
		sections[i].Data = new unsigned char[sectionHeaders[i].SizeOfRawData];
		sections[i].Length = sectionHeaders[i].SizeOfRawData;
		int j = 0;
		ifile.seekg(sectionHeaders[i].PointerToRawData);
		while (ifile.tellg() < sectionHeaders[i].PointerToRawData + sectionHeaders[i].SizeOfRawData)
			ifile.read((char *)&sections[i].Data[j++], sizeof(unsigned char));
	}
}
void PortableExecutable::Save(string filename)
{
	ofstream ofile(filename, ios::binary);

	ofile.write((char *)&dosHeader, sizeof(EXECUTABLE_DOS_HEADER));

	ofile.write((char *)DOSProgram, dosHeader.AddressOfNewEXEHeader - sizeof(EXECUTABLE_DOS_HEADER));

	ofile.write((char *)&fileHeader, sizeof(EXECUTABLE_FILE_HEADER));

	ofile.write((char *)&optionalHeader, sizeof(EXECUTABLE_OPTIONAL_HEADER));

	for (int i = 0; i < fileHeader.NumberOfSections; i++)
		ofile.write((char *)&sectionHeaders[i], sizeof(EXECUTABLE_SECTION_HEADER));

	for (int i = 0; i < fileHeader.NumberOfSections; i++)
	{
		int j = 0;
		ofile.seekp(sectionHeaders[i].PointerToRawData);
		while (ofile.tellp() < sectionHeaders[i].PointerToRawData + sectionHeaders[i].SizeOfRawData)
			ofile.write((char *)&sections[i].Data[j++], sizeof(unsigned char));
	}
}
string PortableExecutable::ToString(int command = (0x00 << 24) | (0xFF << 16) | DOS_HEADER | FILE_HEADER | OPTIONAL_HEADER | SECTION_HEADER | SECTION_DATA)
{
	stringstream ss;
	int startingSection = (command >> 24) & 0xFF;
	int endingSection = (command >> 16) & 0xFF;
	if (command & DOS_HEADER)
	{
		ss << "Dos Header:" << endl;
		ss << endl;
		ss << "MagicNumber:                 0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.MagicNumber << endl;
		ss << "UsedBytesInTheLastPage:      0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.UsedBytesInTheLastPage << endl;
		ss << "FileSizeInPages:             0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.FileSizeInPages << endl;
		ss << "NumberOfRelocationItems:     0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.NumberOfRelocationItems << endl;
		ss << "HeaderSizeInParagraphs:      0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.HeaderSizeInParagraphs << endl;
		ss << "MinimumExtraParagraphs:      0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.MinimumExtraParagraphs << endl;
		ss << "MaximumExtraParagraphs:      0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.MaximumExtraParagraphs << endl;
		ss << "InitialRelativeSS:           0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.InitialRelativeSS << endl;
		ss << "InitialSP:                   0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.InitialSP << endl;
		ss << "Checksum:                    0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.Checksum << endl;
		ss << "InitialIP:                   0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.InitialIP << endl;
		ss << "InitialRelativeCS:           0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.InitialRelativeCS << endl;
		ss << "AddressOfRelocationTable:    0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.AddressOfRelocationTable << endl;
		ss << "OverlayNumber:               0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.OverlayNumber << endl;
		ss << "OEMID:                       0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.OEMID << endl;
		ss << "OEMInfo:                     0x"; ss.width(4); ss.fill('0'); ss << hex << dosHeader.OEMInfo << endl;
		ss << "AddressOfNewEXEHeader:       0x"; ss.width(8); ss.fill('0'); ss << hex << dosHeader.AddressOfNewEXEHeader << endl;
		ss << endl;
	}
	if (command & FILE_HEADER)
	{
		ss << "File Header:" << endl;
		ss << endl;
		ss << "FileType:                    " << (unsigned char *)&fileHeader.FileType << endl;
		ss << "Machine:                     0x"; ss.width(4); ss.fill('0'); ss << hex << fileHeader.Machine << endl;
		ss << "NumberOfSections:            0x"; ss.width(4); ss.fill('0'); ss << hex << fileHeader.NumberOfSections << endl;
		ss << "TimeDateStamp:               0x"; ss.width(8); ss.fill('0'); ss << hex << fileHeader.TimeDateStamp << endl;
		ss << "PointToSymbolTable:          0x"; ss.width(8); ss.fill('0'); ss << hex << fileHeader.PointToSymbolTable << endl;
		ss << "NumberOfSymbols:             0x"; ss.width(8); ss.fill('0'); ss << hex << fileHeader.NumberOfSymbols << endl;
		ss << "SizeOfOptionalHeader:        0x"; ss.width(4); ss.fill('0'); ss << hex << fileHeader.SizeOfOptionalHeader << endl;
		ss << "Characteristics:             0x"; ss.width(4); ss.fill('0'); ss << hex << fileHeader.Characteristics << endl;
		ss << endl;
	}
	if (command & OPTIONAL_HEADER)
	{
		ss << "Optional Header:" << endl;
		ss << endl;
		ss << "MagicNumber:                 0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.Magic << endl;
		ss << "MajorLinkerVersion:          0x"; ss.width(2); ss.fill('0'); ss << hex << (unsigned short)optionalHeader.MajorLinkerVersion << endl;
		ss << "MinorLinkerVersion:          0x"; ss.width(2); ss.fill('0'); ss << hex << (unsigned short)optionalHeader.MinorLinkerVersion << endl;
		ss << "SizeOfCode:                  0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfCode << endl;
		ss << "SizeOfInitializedData:       0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfInitializedData << endl;
		ss << "SizeOfUnInitializedData:     0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfUninitializedData << endl;
		ss << "AddressOfEntryPoint:         0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.AddressOfEntryPoint << endl;
		ss << "BaseOfCode:                  0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.BaseOfCode << endl;
		ss << "BaseOfData:                  0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.BaseOfData << endl;
		ss << "ImageBase:                   0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.ImageBase << endl;
		ss << "SectionAlignment:            0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SectionAlignment << endl;
		ss << "FileAlignment:               0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.FileAlignment << endl;
		ss << "MajorOperatingSystemVersion: 0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.MajorOperatingSystemVersion << endl;
		ss << "MinorOperatingSystemVersion: 0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.MinorOperatingSystemVersion << endl;
		ss << "MajorImageVersion:           0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.MajorImageVersion << endl;
		ss << "MinorImageVersion:           0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.MinorImageVersion << endl;
		ss << "MajorSubsystemVersion:       0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.MajorSubsystemVersion << endl;
		ss << "MinorSubsystemVersion:       0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.MinorSubsystemVersion << endl;
		ss << "SizeOfImage:                 0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfImage << endl;
		ss << "SizeOfHeaders:               0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfHeaders << endl;
		ss << "Checksum:                    0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.CheckSum << endl;
		ss << "SubSystem:                   0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.SubSystem << endl;
		ss << "DllCharacteristics:          0x"; ss.width(4); ss.fill('0'); ss << hex << optionalHeader.DllCharacteristics << endl;
		ss << "SizeOfStackReserve:          0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfStackReserve << endl;
		ss << "SizeOfStackCommit:           0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfStackCommit << endl;
		ss << "SizeOfHeapReserve:           0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfHeapReserve << endl;
		ss << "SizeOfHeapCommit:            0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.SizeOfHeapCommit << endl;
		ss << "LoaderFlags:                 0x"; ss.width(8); ss.fill('0'); ss << hex << optionalHeader.LoaderFlags << endl;
		ss << endl;
	}

	if (endingSection == 0xFF)
		endingSection = fileHeader.NumberOfSections;

	for (int section = startingSection; section < endingSection; section++)
	{
		if (command & SECTION_HEADER)
		{
			string padding("                             ");

			ss << "Section #" << section + 1 << ": " << endl;
			ss << endl;
			ss << "Name:                        " << sectionHeaders[section].Name << endl;
			ss << "VirtualSize:                 0x"; ss.width(8); ss.fill('0'); ss << hex << sectionHeaders[section].VirtualSize << endl;
			ss << "VirtualAddress:              0x"; ss.width(8); ss.fill('0'); ss << hex << sectionHeaders[section].VirtualAddress << endl;
			ss << "SizeOfRawData:               0x"; ss.width(8); ss.fill('0'); ss << hex << sectionHeaders[section].SizeOfRawData << endl;
			ss << "PointerToRawData:            0x"; ss.width(8); ss.fill('0'); ss << hex << sectionHeaders[section].PointerToRawData << endl;
			ss << "PointerToRelocations:        0x"; ss.width(8); ss.fill('0'); ss << hex << sectionHeaders[section].PointerToRelocations << endl;
			ss << "PointerToLineNumbers:        0x"; ss.width(8); ss.fill('0'); ss << hex << sectionHeaders[section].PointerToLineNumbers << endl;
			ss << "NumberOfRelocations:         0x"; ss.width(4); ss.fill('0'); ss << hex << sectionHeaders[section].NumberOfRelocations << endl;
			ss << "NumberOfLineNumbers:         0x"; ss.width(4); ss.fill('0'); ss << hex << sectionHeaders[section].NumberOfLineNumbers << endl;
			ss << "Characteristics:             ";
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_NO_PAD)               ss << "No Pad" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_CODE)                 ss << "Code" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_INITIALIZED_DATA)     ss << "Initialized Data" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_UNINITIALIZED_DATA)   ss << "Uninitialized Data" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_OTHER)                ss << "Other" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_INFO)                 ss << "Info" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_REMOVE)               ss << "Remove" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_COMDAT)               ss << "COMDAT" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_NO_DEFER_SPEC_EXC)    ss << "No Defer Spec Exc" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_SHORT)                ss << "Short" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_PURGEABLE)            ss << "Purgeable" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_LOCKED)               ss << "Locked" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_PRELOAD)              ss << "Preload" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_EXTENDED_RELOCATIONS) ss << "Extended Relocations" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_DISCARDABLE)          ss << "Discardable" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_NOT_CACHED)           ss << "Not Cached" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_NOT_PAGED)            ss << "Not Paged" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_SHARED)               ss << "Shared" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_EXECUTE)              ss << "Execute" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_READ)                 ss << "Read" << endl << padding;
			if (sectionHeaders[section].Characteristics & EXECUTABLE_SECTION_HEADER_WRITE)                ss << "Write" << endl << padding;
			ss << endl;
		}
		if (command & SECTION_DATA)
		{
			int numberOfLines;

			numberOfLines = sectionHeaders[section].VirtualSize / 16;
			if (sectionHeaders[section].VirtualSize % 16 != 0)
				numberOfLines++;

			ss << "Virtual Data: " << endl;
			ss << endl;
			for (int i = 0; i < (numberOfLines * 16); i++)
			{
				if (i % 16 == 0)
				{
					ss << "0x";
					ss.width(8);
					ss.fill('0');
					ss << hex << sectionHeaders[section].VirtualAddress + i << "  ";
				}
				if ((i + 1) % 16 == 0)
				{
					if (i < (int)sectionHeaders[section].VirtualSize && i < (int)sectionHeaders[section].SizeOfRawData)
					{
						ss.width(2);
						ss.fill('0');
						ss << hex << (int)sections[section].Data[i] << "  ";
					}
					else if (i < (int)sectionHeaders[section].VirtualSize && i >= (int)sectionHeaders[section].SizeOfRawData)
						ss << "UU  ";
					else
						ss << "    ";
					for (int j = (i + 1) - 16; j < (i + 1); j++)
						if (j < (int)sectionHeaders[section].VirtualSize && j < (int)sectionHeaders[section].SizeOfRawData)
							if (sections[section].Data[j] > 32 && sections[section].Data[j] < 127)
								ss << sections[section].Data[j];
							else
								ss << ".";
						else if (j < (int)sectionHeaders[section].VirtualSize && j >= (int)sectionHeaders[section].SizeOfRawData)
							ss << ".";
						else
							ss << " ";
					ss << endl;
				}
				else if ((i + 1) % 8 == 0)
				{
					if (i < (int)sectionHeaders[section].VirtualSize && i < (int)sectionHeaders[section].SizeOfRawData)
					{
						ss.width(2);
						ss.fill('0');
						ss << hex << (int)sections[section].Data[i] << "  ";
					}
					else if (i < (int)sectionHeaders[section].VirtualSize && i >= (int)sectionHeaders[section].SizeOfRawData)
						ss << "UU  ";
					else
						ss << "    ";
				}
				else
				{
					if (i < (int)sectionHeaders[section].VirtualSize && i < (int)sectionHeaders[section].SizeOfRawData)
					{
						ss.width(2);
						ss.fill('0');
						ss << hex << (int)sections[section].Data[i] << " ";
					}
					else if (i < (int)sectionHeaders[section].VirtualSize && i >= (int)sectionHeaders[section].SizeOfRawData)
						ss << "UU ";
					else
						ss << "   ";
				}
			}
			ss << endl;
		}
	}
	return ss.str();
}
template<typename T>
T * PortableExecutable::GetHeader(int command)
{
	int section = (command >> 16) & 0xFFFF;

	if (command & DOS_HEADER)
		return (T*)&dosHeader;
	else if (command & FILE_HEADER)
		return (T*)&fileHeader;
	else if (command & OPTIONAL_HEADER)
		return (T*)&optionalHeader;
	else if (command & SECTION_HEADER)
		return (T*)&sectionHeaders[section];
	else
		return NULL;
}
Section * PortableExecutable::GetSection(int sectionNumber)
{
	if (sectionNumber >= 0 && sectionNumber < fileHeader.NumberOfSections)
		return &sections[sectionNumber];
	else
		throw;
}

Section * PortableExecutable::GetSection(string sectionName)
{
	return GetSection(GetSectionNumber(sectionName));
}
int PortableExecutable::GetSectionNumber(string sectionName)
{
	for (int i = 0; i < fileHeader.NumberOfSections; i++)
		if (string((char *)sectionHeaders[i].Name) == sectionName)
			return i;
	return 0xFFFFFFFF;
}

#endif