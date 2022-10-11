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

namespace FSACTestsDateTime
{
	TEST_CLASS(FSACTestsLongLat)
	{
	public:

		#ifdef _DEBUG
		TEST_METHOD(TestLongLat1)
		{
			Assert::IsTrue(Utility::IsWithinLongLat(0, 10, -10));	                      
		}

		TEST_METHOD(TestLongLat2)
		{
			Assert::IsTrue(Utility::IsWithinLongLat(180, -160, 160));
		}

		TEST_METHOD(TestLongLat3)
		{
			Assert::IsTrue(Utility::IsWithinLongLat(90, 120, -5));
		}

		TEST_METHOD(TestLongLat4)
		{
			Assert::IsTrue(Utility::IsWithinLongLat(-90, -10, -100));
		}

		TEST_METHOD(TestLongLat5)
		{
			Assert::IsTrue(Utility::IsWithinLongLat(0, -160, -10));
		}
		#endif
	};
}