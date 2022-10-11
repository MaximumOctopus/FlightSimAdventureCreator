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

#include "../../DateUtility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FSACTestsDateTime
{
	TEST_CLASS(FSACTestsDateTime)
	{
	public:

		TEST_METHOD(TestCurrentMonth)
		{
			int month = DateUtility::GetMonth();

			Assert::AreEqual(month, 10);	
			//                      ^^   <<--- THIS NEEDS CHANGING TO THE CURRENT MONTH!!!			                      
		}
	};
}