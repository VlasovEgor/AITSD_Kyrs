#include "pch.h"
#include "CppUnitTest.h"
#include "../AISTD_KYRS1.3/AISTD_KYRS1.3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AISTDKYRSTEST
{
	TEST_CLASS(AISTDKYRSTEST)
	{
	public:
	};
	TEST_METHOD(test_1)
	{
		Queue* elements;
		cout << "(1+4)*3";
		double res = calculation(elements);
		Assert::AreEqual(res,15);
	}
	TEST_METHOD(test_2)
	{
		Queue* elements;
		cout << "(2+7)/(1+2)";
		double res = calculation(elements);
		Assert::AreEqual(res, 3);
	}
	TEST_METHOD(test_3)
	{
		Queue* elements;
		cout << "25+65";
		double rest = calculation(elements);
		Assert::AreEqual(res, 90);
	}
	TEST_METHOD(test_4)
	{
		Queue* elements;
		cout << "2^5";
		double res = calculation(elements);
		Assert::AreEqual(res, 32);
	}
}
