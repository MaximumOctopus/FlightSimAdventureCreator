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

namespace FSACTestsAirport
{
	TEST_CLASS(FSACTestsAirport)
	{
	public:

		TEST_METHOD(TestAirportSmall)
		{
			std::wstring at = Utility::GetAirportType(AirportConstants::AirportType::Small);

			Assert::AreEqual(AirportConstants::SmallAirport, at);
		}

		TEST_METHOD(TestAirportMedium)
		{
			std::wstring at = Utility::GetAirportType(AirportConstants::AirportType::Medium);

			Assert::AreEqual(AirportConstants::MediumAirport, at);
		}

		TEST_METHOD(TestAirportLarge)
		{
			std::wstring at = Utility::GetAirportType(AirportConstants::AirportType::Large);

			Assert::AreEqual(AirportConstants::LargeAirport, at);
		}

		TEST_METHOD(TestAirportHeliport)
		{
			std::wstring at = Utility::GetAirportType(AirportConstants::AirportType::Heliport);

			Assert::AreEqual(AirportConstants::Heliport, at);
		}

		TEST_METHOD(TestAirportSeaplaneBase)
		{
			std::wstring at = Utility::GetAirportType(AirportConstants::AirportType::SeaplaneBase);

			Assert::AreEqual(AirportConstants::SeaplaneBase, at);
		}
	};
}