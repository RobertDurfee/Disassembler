#include <CppUnitTest.h>
#include "SIB\SIB.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(SIBTest)
{
public:
	TEST_METHOD(Zero)
	{
		byte data[1] = { 0x00 };
		int index = 0;

		SIB sib(data, &index, Mod::NoDisp);

		Assert::AreEqual("EAX + EAX", sib.GetString().c_str(), "SIB", LINE_INFO());
	}
};
