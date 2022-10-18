//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

#include "pch.h"
#include "CppUnitTest.h"

#include "../../Utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FSACTestsMisc
{
	TEST_CLASS(FSACTestsMisc)
	{
	public:

		TEST_METHOD(TestBoolToStrTrue)
		{
			Assert::IsTrue(Utility::BoolToYesNo(true) == L"Yes");
		}

		TEST_METHOD(TestBoolToStrFalse)
		{
			Assert::IsTrue(Utility::BoolToYesNo(false) == L"No");
		}

		TEST_METHOD(TestReverseAngle1)
		{
			Assert::IsTrue(Utility::ReverseAngle(180) == 0);
		}

		TEST_METHOD(TestReverseAngle2)
		{
			Assert::IsTrue(Utility::ReverseAngle(270) == 90);
		}

		TEST_METHOD(TestReverseAngle3)
		{
			Assert::IsTrue(Utility::ReverseAngle(90) == 270);
		}

		TEST_METHOD(TestReverseAngle4)
		{
			Assert::IsTrue(Utility::ReverseAngle(0) == 180);
		}
	};
}