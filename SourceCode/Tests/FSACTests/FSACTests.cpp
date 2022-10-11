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

namespace FSACTests
{
	TEST_CLASS(FSACTests)
	{
	public:

		double originX = 0;
		double originY = 0;
		
		TEST_METHOD(TestAngleBetweenNorth)
		{
			double pLat = 10 * (3.14159265358979323846 / 180);
			double North = 0;
			double n = Utility::AngleBetween(originX, originY, pLat, 0);
				
			Assert::AreEqual(North, n);
		}

		TEST_METHOD(TestAngleBetweenEast)
		{
			double pLong = 10 *(3.14159265358979323846 / 180);
			double East = 90;
			double e = Utility::AngleBetween(originX, originY, 0, pLong);

			Assert::AreEqual(East, e);
		}

		TEST_METHOD(TestAngleBetweenSouth)
		{
			double nLat = -10 * (3.14159265358979323846 / 180);
			double South = 180;

			double s = Utility::AngleBetween(originX, originY, nLat, 0);

			Assert::AreEqual(South, s);
		}

		TEST_METHOD(TestAngleBetweenWest)
		{
			double nLong = -10 * (3.14159265358979323846 / 180);
			double West = 270;

			double w = Utility::AngleBetween(originX, originY, 0, nLong);

			Assert::AreEqual(West, w);
		}

		// this compass direction doesn't return an exact value, so let's check for accuracy: 99.1% or greater
		TEST_METHOD(TestAngleBetweenNorthEast)
		{
			double pLat = 8 * (3.14159265358979323846 / 180);
			double NE = 45;
			double ne = Utility::AngleBetween(originX, originY, pLat, pLat);

			Assert::IsTrue((ne / NE) > 0.991);
		}

		// this compass direction doesn't return an exact value, so let's check for accuracy: 99.1% or greater
		TEST_METHOD(TestAngleBetweenSouthEast)
		{
			double pLong = 8 * (3.14159265358979323846 / 180);
			double nLat = -8 * (3.14159265358979323846 / 180);
			double SE = 135;
			double se = Utility::AngleBetween(originX, originY, nLat, pLong);

			Assert::IsTrue((se / SE) > 0.991);
		}

		// this compass direction doesn't return an exact value, so let's check for accuracy: 99.1% or greater
		TEST_METHOD(TestAngleBetweenSouthWest)
		{
			double nLong = -8 * (3.14159265358979323846 / 180);
			double nLat = -8 * (3.14159265358979323846 / 180);
			double SW = 225;
			double sw = Utility::AngleBetween(originX, originY, nLat, nLong);

			Assert::IsTrue((sw / SW) > 0.991);
		}

		// this compass direction doesn't return an exact value, so let's check for accuracy: 99.1% or greater
		TEST_METHOD(TestAngleBetweenNorthWest)
		{
			double nLong = -8 * (3.14159265358979323846 / 180);
			double pLat = 8 * (3.14159265358979323846 / 180);
			double NW = 315;
			double nw = Utility::AngleBetween(originX, originY, pLat, nLong);

			Assert::IsTrue((nw / NW) > 0.991);
		}

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