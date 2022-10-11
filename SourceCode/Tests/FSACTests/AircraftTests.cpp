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

namespace FSACTestsAircraft
{
	TEST_CLASS(FSACTestsAircraft)
	{
	public:

		TEST_METHOD(TestAircraftProp)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::Prop);

			Assert::AreEqual(AircraftConstants::AircraftTypeProp, at);
		}

		TEST_METHOD(TestAircraftJet)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::Jet);

			Assert::AreEqual(AircraftConstants::AircraftTypeJet, at);
		}

		TEST_METHOD(TestAircraftHelicopter)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::Helicopter);

			Assert::AreEqual(AircraftConstants::AircraftTypeHeli, at);
		}

		TEST_METHOD(TestAircraftGlider)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::Glider);

			Assert::AreEqual(AircraftConstants::AircraftTypeGlider, at);
		}

		TEST_METHOD(TestAircraftTwinProp)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::TwinProp);

			Assert::AreEqual(AircraftConstants::AircraftTypeTwinProp, at);
		}

		TEST_METHOD(TestAircraftTurboProp)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::TurboProp);

			Assert::AreEqual(AircraftConstants::AircraftTypeTurboProp, at);
		}

		TEST_METHOD(TestAircraftTwinTurboProp)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::TwinTurboProp);

			Assert::AreEqual(AircraftConstants::AircraftTypeTwinTurboProp, at);
		}

		TEST_METHOD(TestAircraftBalloon)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::Balloon);

			Assert::AreEqual(AircraftConstants::AircraftTypeBalloon, at);
		}

		TEST_METHOD(TestAircraftNone)
		{
			int at = Utility::GetAircraftTypeToConfigType(AircraftConstants::AircraftType::None);

			Assert::AreEqual(-1, at);
		}
	};
}