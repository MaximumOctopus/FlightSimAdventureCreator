#include "pch.h"
#include "CppUnitTest.h"

#include "../../AircraftConstants.h"
#include "../../Utility.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FSACTests
{
	TEST_CLASS(FSACTests)
	{
	public:

		std::wstring small_airport = L"small_airport";
		std::wstring medium_airport = L"medium_airport";
		std::wstring large_airport = L"large_airport";
		std::wstring heliport = L"heliport";
		std::wstring seaplane_base = L"seaplane_base";

		TEST_METHOD(TestAirportSmall)
		{
			std::wstring at = Utility::GetAirportType(Utility::GetAirportType(small_airport));

			Assert::AreEqual(at, small_airport);
		}
	};
}

/*

std::wstring GetAirportType(AirportConstants::AirportType type)
{
	switch (type)
	{
	case AirportConstants::AirportType::None:
		return L"none";
	case AirportConstants::AirportType::Small:
		return L"small_airport";
	case AirportConstants::AirportType::Medium:
		return L"medium_airport";
	case AirportConstants::AirportType::Large:
		return L"large_airport";
	case AirportConstants::AirportType::Heliport:
		return L"heliport";
	case AirportConstants::AirportType::SeaplaneBase:
		return L"seaplane_base";
	}

	return L"!unknown!";
}


AirportConstants::AirportType GetAirportType(std::wstring name)
{
	if (name == L"small_airport")
	{
		return AirportConstants::AirportType::Small;
	}
	else if (name == L"medium_airport")
	{
		return AirportConstants::AirportType::Medium;
	}
	else if (name == L"large_airport")
	{
		return AirportConstants::AirportType::Large;
	}
	else if (name == L"heliport")
	{
		return AirportConstants::AirportType::Heliport;
	}
	else if (name == L"seaplane_base")
	{
		return AirportConstants::AirportType::SeaplaneBase;
	}

	return AirportConstants::AirportType::None;
}

*/