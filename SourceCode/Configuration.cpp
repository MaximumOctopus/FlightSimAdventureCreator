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

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <string>

#include "Configuration.h"
#include "Constants.h"
#include "DateUtility.h"
#include "Formatting.h"
#include "Locations.h"
#include "Ini.h"
#include "Utility.h"

#ifdef _DEBUG
#include "Debug.h"
#endif

Configuration* GConfiguration;


Configuration::Configuration(int argc, wchar_t* argv[])
{
	if (argc != 0)
	{
		for (int t = 1; t < argc; t++)
		{
			std::wstring parameter = argv[t];

			if (IsValidParameter(parameter))
			{
				ParameterData pd;

				pd.command = GetCommandValue(parameter);
				pd.property = GetPropertyValue(parameter);
				pd.option = GetPropertyOption(pd.command);

				std::transform(pd.command.begin(), pd.command.end(), pd.command.begin(), ::tolower);

				Parameters.push_back(pd);
			}
			else
			{
				std::wcerr << std::format(L"Error, invalid parameter \"{0}\".\n", parameter);
			}
		}
	}

	SetFromCommandLine();

	if (!Meta.Silent)
	{
		ShowConfiguration();
	}

	if (Meta.SaveToConfig)
	{
		if (!SaveConfiguration(Meta.SaveFileName))
		{
			std::wcerr << std::format(L"Error saving configuration to \"{0}\".\n", Meta.SaveFileName);
		}
	}
}


void Configuration::ShowConfiguration()
{
	if (Meta.LoadedFromConfig)
	{
		std::wcout << L"    Config source    : Config file\n\n";
	}

    // == airport =====================================================================================

	std::wcout << L"    Small Airports   : " << Utility::BoolToYesNo(Airport.SmallAirports) << L"\n";
	std::wcout << L"    Medium Airports  : " << Utility::BoolToYesNo(Airport.MediumAirports) << L"\n";
	std::wcout << L"    Large Airports   : " << Utility::BoolToYesNo(Airport.LargeAirports) << L"\n";
	std::wcout << L"    Heliports        : " << Utility::BoolToYesNo(Airport.Heliports) << L"\n";

	if (Airport.Continent == L"" && Airport.Country == L"" && Airport.Region == L"")
	{
		std::wcout << L"    Continent        : All\n";
		std::wcout << L"    Country          : All\n";
		std::wcout << L"    Region           : All\n";

		if (Airport.LatitudeFilter)
		{
			std::wcout << L"    Latitude         : " << Airport.LatitudeFrom << L" to " << Airport.LatitudeTo << L"\n";
		}

		if (Airport.LongitudeFilter)
		{
			std::wcout << L"    Longitude        : " << Airport.LongitudeFrom << L" to " << Airport.LongitudeTo << L"\n";
		}
	}
	else
	{
		if (Airport.Day)
		{
			std::wcout << L"    Daylight mode    : latitude " << Airport.LongitudeFrom << L" to " << Airport.LongitudeTo << "L\n";

		}
		else if (Airport.Night)
		{
			std::wcout << L"    Night mode       : latitude " << Airport.LongitudeFrom << L" to " << Airport.LongitudeTo << "L\n";
		}
		else
		{
			if (Airport.Continent != L"")
			{
				std::wcout << L"    Continent        : " << Utility::GetContinentFromShortCode(Airport.Continent) << L" (" << Airport.Continent << L")\n";
			}

			if (Airport.Country != L"")
			{
				std::wcout << L"    Country          : " << Utility::GetCountryFromShortCode(Airport.Country) << L" (" << Airport.Country << L")\n";
			}

			if (Airport.Region != L"")
			{
				std::wcout << L"    Region           : " << Airport.Region << L"\n";
			}

			if (Airport.LatitudeFilter)
			{
				std::wcout << L"    Latitude         : " << Airport.LatitudeFrom << L" to " << Airport.LatitudeTo << L"\n";
			}

			if (Airport.LongitudeFilter)
			{
				std::wcout << L"    Longitude        : " << Airport.LongitudeFrom << L" to " << Airport.LongitudeTo << L"\n";
			}
		}
	}

	std::wcout << L"    Elevation        : >" << Airport.Elevation << L" feet\n";

	if (Airport.KeepTrying)
	{
		std::wcout << L"\n    Keep trying      : Yes\n";
	}

	std::wcout << "\n";

	// == aircraft ====================================================================================

	if (Aircraft.Default)
	{
		std::wcout << L"    Aircraft         : MSFS defaults\n";
	}

	if (Aircraft.Custom)
	{
		std::wcout << L"    Aircraft         : User custom\n";
	}

	std::wcout << L"    Max Cruise Speed : " << Aircraft.MaxSpeed << L" kts\n";
	std::wcout << L"    Min Cruise Speed : " << Aircraft.MinSpeed << L" kts\n";

	if (Aircraft.Special != AircraftConstants::SpecialMode::None)
	{
		switch (Aircraft.Special)
		{
		case AircraftConstants::SpecialMode::GA:
			std::wcout << L"    Aircraft Type    : Props, Twin Props, Turbo props, Twin turbo props\n";
			std::wcout << L"    Airliners        : No\n";
			std::wcout << L"    Military         : No\n";
			break;
		case AircraftConstants::SpecialMode::JetAirliners:
			std::wcout << L"    Aircraft Type    : Jets\n";
			std::wcout << L"    Airliners        : Yes\n";
			std::wcout << L"    Military         : No\n";
			break;
		case AircraftConstants::SpecialMode::Twins:
			std::wcout << L"    Aircraft Type    : Twin props and Twin turbo props\n";
			std::wcout << L"    Airliners        : Yes\n";
			std::wcout << L"    Military         : Yes\n";
			break;
		case AircraftConstants::SpecialMode::Props:
			std::wcout << L"    Aircraft Type    : Props and twin props\n";
			std::wcout << L"    Airliners        : No\n";
			std::wcout << L"    Military         : No\n";
			break;
		case AircraftConstants::SpecialMode::TurboProps:
			std::wcout << L"    Aircraft Type    : Turbo props and twin turbo props\n";
			std::wcout << L"    Airliners        : Yes\n";
			std::wcout << L"    Military         : Yes\n";
			break;
		}
	}
	else
	{
		if (Aircraft.Type != Defaults::DefaultAircraftSelection)
		{
			std::wcout << L"    Aircraft Type    : " << Utility::GetAircraftType(Aircraft.Type) << L"\n";
		}
		else
		{
			std::wcout << L"    Aircraft Type    : All (Props/Twins/Turbos/Jets/Helis/Gliders/Balloons)\n";
		}

		std::wcout << L"    Airliners        : " << Utility::BoolToYesNo(Aircraft.Airliner) << L"\n";
		std::wcout << L"    Military         : " << Utility::BoolToYesNo(Aircraft.Military) << L"\n";
	}

	if (Aircraft.Version != AircraftConstants::MSFSVersion::All)
	{
		if (Aircraft.Version == AircraftConstants::MSFSVersion::DeluxeAbove)
		{
			std::wcout << L"    MSFS             : Deluxe and above\n";
		}
		else if (Aircraft.Version == AircraftConstants::MSFSVersion::PremiumAbove)
		{
			std::wcout << L"    MSFS Version     : Premium Deluxe only\n";
		}
	}

	std::wcout << "\n";

	// == route =======================================================================================

	if (Route.AtoB)
	{
		if (Route.AtoBAutomatic)
		{
			std::wcout << L"    Route generation : Added automatically (looks like you forgot /atob)\n";
		}

		if (Route.RequestedFlightTime != 0)
		{
			std::wcout << L"    Range            : set from flight time (" << Route.RequestedFlightTime << L" mins. (+/- " << Defaults::DefaultRangeModifier << L"%)\n";
		}
		else
		{
			std::wcout << L"    Range            : " << Route.Range << L" nm (+/- " << Defaults::DefaultRangeModifier << L"%)\n";
		}		

		std::wcout << L"    Legs             : " << Route.Legs << L"\n";

		if (Route.Direction != Defaults::DefaultDirection)
		{
			std::wcout << L"    Direction        : " << Route.Direction << L"° (+- " << Defaults::DefaultDirectionMargin << L"°)\n";
		}
		else
		{
			std::wcout << L"    Direction        : Any\n";
		}

		std::wcout << L"    Create           : " << Route.Count << L" route(s)\n";

		if (Route.StartAirportICAO != L"")
		{
			std::wcout << L"    Start at         : " << Route.StartAirportICAO << L"\n";
		}
		else
		{
			std::wcout << L"    Start at         : Random\n";
		}

		if (Route.EndAirportICAO != L"")
		{
			std::wcout << L"    End at           : " << Route.EndAirportICAO << L"\n";
		}
		else
		{
			std::wcout << L"    End at           : Random\n";
		}

		if (Route.UseAircraftRange)
		{
			std::wcout << L"    Using Aircraft range (@ " << Route.AircraftRangePercent << L"%\n";
		}

		std::wcout << "\n";
	}

	// == export ======================================================================================

	if (Export.MSFS)
	{
		std::wcout << L"    Export           : MSFS Plan (.pln)\n";
	}

	if (Export.Text)
	{
		std::wcout << L"    Export           : Text itinerary (.txt)\n";
	}

	if (Export.XPlane)
	{
		std::wcout << L"    Export           : XPlane v11 Flight Plan (.fms)\n";
	}

	std::wcout << L"    Export           : To console\n";

	std::wcout << "\n";
}


void Configuration::SetFromCommandLine()
{
	if (Parameters.size() != 0)
	{
		for (int p = 0; p < Parameters.size(); p++)
		{
			#ifdef _DEBUG
			FSACDebug::Output(L"command: " + Parameters[p].command + L" value: " + Parameters[p].property);
			#endif

			switch (Parameters[p].option)
			{
			case ParameterOption::None:
			case ParameterOption::Cats:
			case ParameterOption::Help:
				// already handled, shouldn't even get here
				break;

			case ParameterOption::LoadConfig:
			{
				std::wstring file_name = Parameters[p].property;

				if (file_name.find(L'.') == std::wstring::npos)
				{
					file_name += L".txt";
				}

				Meta.LoadedFromConfig = LoadConfiguration(file_name);

				if (!Meta.LoadedFromConfig)
				{
					std::wcout << std::format(L"Error loading configuration file \"{0}\"", file_name) << L"\n";
				}

				break;
			}
			case ParameterOption::Elevation:
				HandleElevation(Parameters[p].property);
				break;
			case ParameterOption::Continent:
				HandleContinent(Parameters[p].property);
				break;
			case ParameterOption::Country:
				HandleCountry(Parameters[p].property);
				break;
			case ParameterOption::Region:
				if (Parameters[p].property.length() > 2)
				{
					Airport.Region = Parameters[p].property;
				}
				else
				{
					std::wcerr << std::format(L"Error, invalid region code \"{0}\". Expected AB-CD, AB-CDE, or AB-C-D.\n", Parameters[p].property);
				}
				break;
			case ParameterOption::NoSmall:
				Airport.SmallAirports = false;
				break;
			case ParameterOption::NoMedium:
				Airport.MediumAirports = false;
				break;
			case ParameterOption::NoLarge:
				Airport.LargeAirports = false;
				break;
			case ParameterOption::NoHeliports:
				Airport.Heliports = false;
				break;
			case ParameterOption::OnlySmall:
				Airport.SmallAirports = true;
				Airport.MediumAirports = false;
				Airport.LargeAirports = false;
				Airport.Heliports = false;
				break;
			case ParameterOption::OnlyMedium:
				Airport.SmallAirports = false;
				Airport.MediumAirports = true;
				Airport.LargeAirports = false;
				Airport.Heliports = false;
				break;
			case ParameterOption::OnlyLarge:
				Airport.SmallAirports = false;
				Airport.MediumAirports = false;
				Airport.LargeAirports = true;
				Airport.Heliports = false;
				break;
			case ParameterOption::OnlyHeliports:
				Airport.SmallAirports = false;
				Airport.MediumAirports = false;
				Airport.LargeAirports = false;
				Airport.Heliports = true;
				Aircraft.Type = AircraftConstants::AircraftTypeHeli;
				break;
			case ParameterOption::AToB:
				Route.AtoB = true;
				break;
			case ParameterOption::Legs:
				HandleLegs(Parameters[p].property);
				break;
			case ParameterOption::Range:
				HandleRange(Parameters[p].property);
				break;
			case ParameterOption::StartAirport:
			{
				std::wstring sa(Parameters[p].property);

				std::transform(sa.begin(), sa.end(), sa.begin(), ::toupper);

				Route.StartAirportICAO = sa;

				break;
			}
			case ParameterOption::EndAirport:
			{
				std::wstring ea(Parameters[p].property);

				std::transform(ea.begin(), ea.end(), ea.begin(), ::toupper);

				Route.EndAirportICAO = ea;
			}
			case ParameterOption::Count:
				HandleCount(Parameters[p].property);
				break;
			case ParameterOption::Bearing:
				HandleBearing(Parameters[p].property);
				break;
			case ParameterOption::Direction:
				HandleDirection(Parameters[p].property);
				break;
			case ParameterOption::UseAircraftRange:
				Route.UseAircraftRange = true;
				break;
			case ParameterOption::AircraftRange:
				HandleAircraftRangePercent(Parameters[p].property);
				break;
			case ParameterOption::MSFSVersion:
				HandleMSFSVersion(Parameters[p].property);
				break;
			case ParameterOption::AircraftType:
				HandleAircraftType(Parameters[p].property);
				break;
			case ParameterOption::NoAirliner:
				Aircraft.Airliner = false;
				break;
			case ParameterOption::NoMilitary:
				Aircraft.Military = false;
				break;
			case ParameterOption::GAOnly:
				Aircraft.Special = AircraftConstants::SpecialMode::GA;
				break;
			case ParameterOption::JAOnly:
				Aircraft.Special = AircraftConstants::SpecialMode::JetAirliners;
				break;
			case ParameterOption::TwinsOnly:
				Aircraft.Special = AircraftConstants::SpecialMode::Twins;
				break;
			case ParameterOption::Props:
				Aircraft.Special = AircraftConstants::SpecialMode::Props;
				break;
			case ParameterOption::TurboProps:
				Aircraft.Special = AircraftConstants::SpecialMode::TurboProps;
				break;
			case ParameterOption::MaxSpeed:
				HandleAircraftMaxSpeed(Parameters[p].property);
				break;
			case ParameterOption::MinSpeed:
				HandleAircraftMinSpeed(Parameters[p].property);
				break;
			case ParameterOption::AllowExcessRange:
				Aircraft.AllowExcessRange = true;
				break;
			case ParameterOption::ExportMSFS:
				Export.MSFS = true;
				break;
			case ParameterOption::ExportText:
				Export.Text = true;
				break;
			case ParameterOption::ExportXPlane:
				break;
			case ParameterOption::NoDefault:
				Aircraft.Default = false;
				break;
			case ParameterOption::NoCustom:
				Aircraft.Custom = false;
				break;
			case ParameterOption::KeepTrying:
				Airport.KeepTrying = true;
				break;
			case ParameterOption::FindNearest:	
				Helpers.FindNearest = true;
				
				Route.FindNearestICAO = Parameters[p].property;

				Meta.OnlyNeedAirports = true;
				break;
			case ParameterOption::SaveConfig:
			{
				std::wstring file_name = Parameters[p].property;

				if (file_name.find(L'.') == std::wstring::npos)
				{
					file_name += L".txt";
				}

				Meta.SaveFileName = file_name;
				Meta.SaveToConfig = true;

				break;
			}
			case ParameterOption::Day:
				Airport.Day = true;
				SetLongitude(Constants::TimeOfDay::Midday, DateUtility::GetMonth());
				break;
			case ParameterOption::Night:
				Airport.Night = true;
				SetLongitude(Constants::TimeOfDay::Midnight, DateUtility::GetMonth());
				break;
			case ParameterOption::StartFromFavourite:
				Route.StartFromFavourite = true;
				Route.StartAirportICAO = GetFromFavourites();
				break;
			case ParameterOption::SimpleRouteCount:
				HandleSimpleRouteCount(Parameters[p].property);
				break;
			case ParameterOption::Silent:
				Meta.Silent = true;
				break;
			case ParameterOption::ListAirports:
				Airport.ListAirports = true;
				break;
			case ParameterOption::Time:
				HandleTime(Parameters[p].property);
				break;
			case ParameterOption::LatitudeMax:
				HandleLatLong(Parameters[p].property, Constants::LatLongSelection::LatitudeFrom);
				break;
			case ParameterOption::LatitudeMin:
				HandleLatLong(Parameters[p].property, Constants::LatLongSelection::LatitudeTo);
				break;
			case ParameterOption::LongitudeMax:
				HandleLatLong(Parameters[p].property, Constants::LatLongSelection::LongitudeFrom);
				break;
			case ParameterOption::LongitudeMin:
				HandleLatLong(Parameters[p].property, Constants::LatLongSelection::LongitudeTo);
				break;
			case ParameterOption::AddStartToFav:
				if (!AddToFavourite(Route.StartAirportICAO))
				{

				}
				break;
			case ParameterOption::AddEndToFav:
				if (!AddToFavourite(Route.EndAirportICAO))
				{

				}
				break;

			default:
				std::wcout << L" Warning, parameter " << Parameters[p].command << " was unhandled.\n";
			}
		}

		// =====================================================================================================
		// == post-processing, these must be actioned after all parameters have been processed
		// =====================================================================================================

		if (!Airport.SmallAirports && !Airport.MediumAirports && !Airport.LargeAirports && Airport.Heliports)
		{
			Aircraft.Type = AircraftConstants::AircraftTypeHeli;
		}	

		// =====================================================================================================
		// == a few sanity checks, and let's help the user if they've forgotten a parameter
		// =====================================================================================================

		if (!Route.AtoB)
		{
			// the user has likely wanted a route but forgotten the /atob parameter
			if (Route.Range != Defaults::DefaultRange || Route.StartAirportICAO != L"" || Route.EndAirportICAO != L"" || Route.Direction != -1 || Route.Legs != 1)
			{
				Route.AtoB = true;
				Route.AtoBAutomatic = true;
			}
		}
	}
}


void Configuration::HandleAircraftMaxSpeed(const std::wstring speed)
{
	int Speed = SafelyGetIntFromString(speed, Defaults::DefaultMaxSpeed);

	if (Speed > 0)
	{
		Aircraft.MaxSpeed = Speed;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid aircraft maximum speed \"{0}\". Using {1} (default).\n", speed, Defaults::DefaultMaxSpeed);
	}
}


void Configuration::HandleAircraftMinSpeed(const std::wstring speed)
{
	int Speed = SafelyGetIntFromString(speed, 0);

	if (Speed > 0)
	{
		Aircraft.MinSpeed = Speed;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid aircraft minimum speed \"{0}\". Using 0 (default).\n", speed);
	}
}


void Configuration::HandleAircraftRangePercent(const std::wstring range_percent)
{
	double RangePC = Defaults::DefaultACPC;

	try
	{
		RangePC = stod(range_percent);
	}
	catch (...)
	{
		std::wcerr << std::format(L"Error, invalid aircraft range percent \"{0}\". Using {1} (default).\n", range_percent, Defaults::DefaultACPC);
	}

	if (RangePC > 0)
	{
		Route.Range = RangePC;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid aircraft range percent \"{0}\". Using {1} (default).\n", range_percent, Defaults::DefaultACPC);
	}
}


void Configuration::HandleAircraftType(const std::wstring aircraft_type)
{
	int Type = SafelyGetIntFromString(aircraft_type, Defaults::DefaultAircraftSelection);

	if (Type >= AircraftConstants::AircraftTypeMin && Type <= AircraftConstants::AircraftTypeMax)
	{
		Aircraft.Type = Type;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid aircraft type \"{0}\". Using all (default).\n", aircraft_type);
	}
}


// 0 degrees is west, 90 is north, etc.
void Configuration::HandleBearing(const std::wstring input)
{
	std::wstring bearing(input);
	std::transform(bearing.begin(), bearing.end(), bearing.begin(), ::toupper);

	for (int t = 0; t < 16; t++)
	{
		if (bearing == Constants::CompassBearings[t])
		{
			Route.Direction = Constants::CompassDegrees[t];

			return;
		}
	}

	std::wcerr << std::format(L"Error, invalid bearing \"{0}\". Direction disabled.\n", bearing);
}


void Configuration::HandleContinent(const std::wstring input)
{
	std::wstring continent(input);
	std::transform(continent.begin(), continent.end(), continent.begin(), ::toupper);

	bool isvalid = false;

	for (int t = 0; t < Location::ContinentCount; t++)
	{
		if (Location::ContinentShort[t] == continent)
		{
			isvalid = true;

			break;
		}
	}

	if (isvalid)
	{
		Airport.Continent = continent;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid continent \"{0}\". Disabling option.\n", input);
	}
}


void Configuration::HandleCount(const std::wstring count)
{
	int Count = SafelyGetIntFromString(count, 1);

	if (Count > 0)
	{
		Route.Count = Count;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid route count \"{0}\". Using 1 (default).\n", count);
	}
}


void Configuration::HandleCountry(const std::wstring input)
{
	std::wstring country(input);
	std::transform(country.begin(), country.end(), country.begin(), ::toupper);

	bool isvalid = false;

	for (int t = 0; t < Location::ISOCountriesCount; t++)
	{
		if (Location::ISOCountries[t][0] == country)
		{
			isvalid = true;

			break;
		}
	}

	if (isvalid)
	{
		Airport.Country = country;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid country \"{0}\". Disabling option.\n", input);
	}
}


void Configuration::HandleDirection(const std::wstring angle)
{
	if (angle != L"-1")
	{
		double Direction = Defaults::DefaultDirection;

		try
		{
			Direction = stod(angle);
		}
		catch(...)
		{ 
			std::wcerr << std::format(L"Error, invalid direction \"{0}\". Using any (default).\n", angle);
		}

		if (Direction >= 0 && Direction < 360)
		{
			Route.Direction = Direction;
		}
	}
}


void Configuration::HandleElevation(const std::wstring elevation)
{
	int Elevation = SafelyGetIntFromString(elevation, 0);

	if (Elevation > 0)
	{
		Airport.Elevation = Elevation;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid minimum elevation \"{0}\" ft. Using 0 (default).\n", elevation);
	}
}


void Configuration::HandleLegs(const std::wstring legs)
{
	int Legs = SafelyGetIntFromString(legs, 1);

	if (Legs > 0)
	{
		Route.Legs = Legs;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid leg count \"{0}\". Using 1 (default).\n", legs);
	}
}


void Configuration::HandleLatLong(const std::wstring input, Constants::LatLongSelection setting)
{
	double value = 999;

	try
	{
		value = stod(input);
	}
	catch (...)
	{
		std::wcerr << std::format(L"Error, invalid lat//long value \"{0}\". Disabling.\n", input);

		return;
	}

	switch (setting)
	{
	case Constants::LatLongSelection::LatitudeFrom:
		Airport.LatitudeFrom = value;
		Airport.LatitudeFilter = true;
		break;
	case Constants::LatLongSelection::LatitudeTo:
		Airport.LatitudeTo = value;
		Airport.LatitudeFilter = true;
		break;
	case Constants::LatLongSelection::LongitudeFrom:
		Airport.LongitudeFrom = value;
		Airport.LongitudeFilter = true;
		break;
	case Constants::LatLongSelection::LongitudeTo:
		Airport.LongitudeTo = value;
		Airport.LongitudeFilter = true;
		break;
	}
}


void Configuration::HandleMSFSVersion(const std::wstring version)
{
	int Version = SafelyGetIntFromString(version, 0);

	if (Version >= AircraftConstants::MSFSVersionMin && Version <= AircraftConstants::MSFSVersionMax)
	{
		switch (Version)
		{
		case 0:
			Aircraft.Version = AircraftConstants::MSFSVersion::All;
			break;
		case 1:
			Aircraft.Version = AircraftConstants::MSFSVersion::DeluxeAbove;
			break;
		case 2:
			Aircraft.Version = AircraftConstants::MSFSVersion::PremiumAbove;
			break;
		}
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid MSFS version \"{0}\". Using 0 (all, default).\n", version);
	}
}


void Configuration::HandleRange(const std::wstring input)
{
	bool ConvertFromK = false;
	std::wstring range = input;

	if (range.back() == L'K' || range.back() == L'k')
	{
		ConvertFromK = true;

		range = input.substr(0, input.length() - 1);
	}

	double Range = Defaults::DefaultRange;

	try
	{ 
		Range = stod(range);

		if (ConvertFromK)
		{
			// input in kilometers, convert to nm
			Range = Range / 1.852;
		}
	}
	catch (...)
	{
		std::wcerr << std::format(L"Error, invalid route range \"{0}\" nm. Using {1} (default).\n", range, Defaults::DefaultRange);
	}

	if (Range > 0)
	{
		Route.Range = Range;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid route range \"{0}\" nm. Using {1} (default).\n", range, Defaults::DefaultRange);
	}
}


void Configuration::HandleSimpleRouteCount(const std::wstring input)
{
	int Count = SafelyGetIntFromString(input, -1);

	if (Count > 0)
	{
		Route.SimpleRouteCount = Count;
	}	
	else
	{
		std::wcerr << std::format(L"Error, invalid simple route count \"{0}\". Using {1} (default).\n", input, Defaults::DefaultShortRoutesToShow);
	}
}


void Configuration::HandleSpecial(const std::wstring input)
{
	std::wstring special(input);
	std::transform(special.begin(), special.end(), special.begin(), ::tolower);

	if (input == L"ga")
	{
		Aircraft.Special = AircraftConstants::SpecialMode::GA;
	}
	else if (input == L"jetairliners")
	{
		Aircraft.Special = AircraftConstants::SpecialMode::JetAirliners;
	}
	else if (input == L"twins")
	{
		Aircraft.Special = AircraftConstants::SpecialMode::Twins;
	}
	else if (input == L"props")
	{
		Aircraft.Special = AircraftConstants::SpecialMode::Props;
	}
	else if (input == L"turbos")
	{
		Aircraft.Special = AircraftConstants::SpecialMode::TurboProps;
	}
}


void Configuration::HandleTime(const std::wstring input)
{
	int Time = SafelyGetIntFromString(input, 0);

	if (Time > 0)
	{
		Route.RequestedFlightTime = Time;
	}
	else
	{
		std::wcerr << std::format(L"Error, invalid flight time \"{0}\". Feature disable.\n", input);
	}
}


// this is very rough, I'll improve it over time...
// let's find midday on Earth (a good aproximation for the lightest part of the day)
// now let's extend out a number of degreess each side of this, based on the month
void Configuration::SetLongitude(Constants::TimeOfDay tod, int month)
{
	static const double DegreesPerHour = 15.0;	// assuming 24 hour earth rotation, 15' per hour

	double time = 0; // hours in 24-hour clock
	double HoursOfInterest = 0;

	if (tod == Constants::TimeOfDay::Midnight)
	{
		time = 0;
		HoursOfInterest = (double)(12 - DateUtility::HoursOfDayLightModifier[month]);
	}
	else
	{
		time = 12;
		HoursOfInterest = (double)(DateUtility::HoursOfDayLightModifier[month]);
	}

	double UTCHours = DateUtility::GetUTCHour();
	
	double deltaH = UTCHours - time;
	
	double MiddayLong = -deltaH * DegreesPerHour;

	Airport.LongitudeFrom = MiddayLong + (HoursOfInterest * DegreesPerHour);
	Airport.LongitudeTo = MiddayLong - (HoursOfInterest * DegreesPerHour);

	std::wcout << Airport.LongitudeFrom << L" " << Airport.LongitudeTo << "\n";

	if (Airport.LongitudeFrom > 180)
	{
		Airport.LongitudeFrom = (double)-180 + (Airport.LongitudeFrom - (double)180);
	}

	if (Airport.LongitudeTo > 180)
	{
		Airport.LongitudeTo = (double)-180 + (Airport.LongitudeTo - (double)180);
	}

	if (Airport.LongitudeFrom < -180)
	{
		Airport.LongitudeFrom = (double)180 + (Airport.LongitudeFrom + (double)180);
	}

	if (Airport.LongitudeTo < -180)
	{
		Airport.LongitudeTo = (double)180 + (Airport.LongitudeTo + (double)180);
	}

	#ifdef _DEBUG
	FSACDebug::Output(std::format(L"UTCH {0}, dH {1}, ML {2}: {3}, {4}\n\n", UTCHours, deltaH, MiddayLong, Airport.LongitudeFrom, Airport.LongitudeTo));
	#endif
}


// the range can't be set from time until we have an aircraft, so this
// function must be called once an aircraft has been generated
bool Configuration::SetRangeFromTime(int speed, AircraftConstants::AircraftType type)
{
	if (speed > 0)
	{
		double range = Utility::AircraftTimeToDistance(Route.RequestedFlightTime, speed, Route.Legs, type);

		if (range > 0)
		{
			Route.Range = range;

			return true;
		}
	}

	return false;
}


// because we can always trust users to correctly enter values in command-line parameters...
int Configuration::SafelyGetIntFromString(const std::wstring input, int default_value)
{
	int Value = default_value;

	try
	{
		Value = stoi(input);
	}
	catch (...)
	{

	}

	return Value;
}


std::wstring Configuration::GetCommandValue(const std::wstring input)
{
	size_t pos = input.find(';');

	if (pos == std::wstring::npos)
	{
		pos = input.find(':');
	}

	if (pos != std::wstring::npos)
	{
		return input.substr(0, pos);
	}

	return input;
}


std::wstring Configuration::GetPropertyValue(const std::wstring input)
{
	size_t pos = input.find(';');

	if (pos == std::wstring::npos)
	{
		pos = input.find(':');
	}

	if (pos != std::wstring::npos)
	{
		return input.substr(pos + 1);
	}

	return L"";
}


ParameterOption Configuration::GetPropertyOption(const std::wstring input)
{
	ParameterOption po = ParameterOption::None;

	for (int t = 0; t < kCommandListCount; t++)
	{
		if (CommandList[t].starts_with(input))
		{
			return ParameterReference[t];
		}
	}

	return po;
}


bool Configuration::IsValidParameter(const std::wstring input)
{
	std::wstring parameter = input;

	std::transform(parameter.begin(), parameter.end(), parameter.begin(), ::tolower);

	auto value_delimeter = parameter.find(L':');

	if (value_delimeter != std::wstring::npos)
	{
		parameter = parameter.substr(0, value_delimeter - 1);
	}

	for (int t = 0; t < kCommandListCount; t++)
	{
		if (CommandList[t].starts_with(parameter))
		{
			return true;
		}
	}

	return false;
}


bool Configuration::FindParameter(std::wstring parameter)
{
	std::transform(parameter.begin(), parameter.end(), parameter.begin(), ::tolower);

	for (int t = 0; t < Parameters.size(); t++)
	{
		std::wstring p = Parameters[t].command;

		std::transform(p.begin(), p.end(), p.begin(), ::tolower);

		if (p == parameter)
		{
			return true;
		}
	}

	return false;
}


bool Configuration::LoadConfiguration(const std::wstring file_name)
{
	Ini* config = new Ini(file_name);

	if (config->Loaded)
	{
		int IntegerKey = 0;
		std::wstring StringKey = L"";

		// == load from aircraft section ==============================================================

		IntegerKey = config->ReadInteger(L"Aircraft", L"Default", 1);
		if (config->LastKeyExist)
		{
			Aircraft.Default = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Custom", 1);
		if (config->LastKeyExist)
		{
			Aircraft.Custom = IntegerKey;
		}

		StringKey = config->ReadString(L"Aircraft", L"Type", std::to_wstring(Defaults::DefaultAircraftSelection));
		if (config->LastKeyExist)
		{
			HandleAircraftType(StringKey);
		}

		StringKey = config->ReadString(L"Aircraft", L"MaxSpeed", std::to_wstring(Defaults::DefaultMaxSpeed));
		if (config->LastKeyExist)
		{
			HandleAircraftMaxSpeed(StringKey);
		}

		StringKey = config->ReadString(L"Aircraft", L"MinSpeed", L"0");
		if (config->LastKeyExist)
		{
			HandleAircraftMinSpeed(StringKey);
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Airliner", 1);
		if (config->LastKeyExist)
		{
			Aircraft.Airliner = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Military", 1);
		if (config->LastKeyExist)
		{
			Aircraft.Military = IntegerKey;
		}

		StringKey = config->ReadString(L"Aircraft", L"Special", L"");
		if (config->LastKeyExist)
		{
			HandleSpecial(StringKey);
		}

		StringKey = config->ReadString(L"Aircraft", L"Version", L"0");
		if (config->LastKeyExist)
		{
			HandleMSFSVersion(StringKey);
		}

		// == load from airport section ===============================================================

		StringKey = config->ReadString(L"Airport", L"Continent", L"");
		if (config->LastKeyExist)
		{
			HandleContinent(StringKey);
		}

		StringKey = config->ReadString(L"Airport", L"Country", L"");
		if (config->LastKeyExist)
		{
			HandleCountry(StringKey);
		}

		StringKey = config->ReadString(L"Airport", L"Region", L"");
		if (config->LastKeyExist)
		{
			Airport.Region = StringKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Elevation", 0);
		if (config->LastKeyExist)
		{
			Airport.Elevation = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"SmallAirports", 1);
		if (config->LastKeyExist)
		{
			Airport.SmallAirports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"MediumAirports", 1);
		if (config->LastKeyExist)
		{
			Airport.MediumAirports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LargeAirports", 1);
		if (config->LastKeyExist)
		{
			Airport.LargeAirports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Heliports", 1);
		if (config->LastKeyExist)
		{
			Airport.Heliports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"KeepTrying", 0);
		if (config->LastKeyExist)
		{
			Airport.KeepTrying = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LatitudeFrom", 0);
		if (config->LastKeyExist)
		{
			Airport.LatitudeFrom = IntegerKey;
			Airport.LatitudeFilter = true;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LatitudeTo", 0);
		if (config->LastKeyExist)
		{
			Airport.LatitudeTo = IntegerKey;
			Airport.LatitudeFilter = true;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LongitudeFrom", 0);
		if (config->LastKeyExist)
		{
			Airport.LongitudeFrom = IntegerKey;
			Airport.LongitudeFilter = true;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LongitudeTo", 0);
		if (config->LastKeyExist)
		{
			Airport.LongitudeTo = IntegerKey;
			Airport.LongitudeFilter = true;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Day", 0);
		if (config->LastKeyExist)
		{
			Airport.Day = IntegerKey;

			if (Airport.Day)
			{
				SetLongitude(Constants::TimeOfDay::Midday, DateUtility::GetMonth());
			}
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Night", 0);
		if (config->LastKeyExist)
		{
			Airport.Night = IntegerKey;

			if (Airport.Night)
			{
				SetLongitude(Constants::TimeOfDay::Midnight, DateUtility::GetMonth());
			}
		}
				
		// == load from route section =================================================================

		IntegerKey = config->ReadInteger(L"Route", L"atob", 0);
		if (config->LastKeyExist)
		{
			Route.AtoB = IntegerKey;
		}

		StringKey = config->ReadString(L"Route", L"Range", std::to_wstring(Defaults::DefaultRange));
		if (config->LastKeyExist)
		{
			HandleRange(StringKey);
		}

		IntegerKey = config->ReadInteger(L"Route", L"Legs", 1);
		if (config->LastKeyExist)
		{
			Route.Legs = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"Numbers", 1);
		if (config->LastKeyExist)
		{
			Route.Count = IntegerKey;
		}

		StringKey = config->ReadString(L"Route", L"Direction", L"-1");
		if (config->LastKeyExist)
		{
			HandleDirection(StringKey);
		}

		StringKey = config->ReadString(L"Route", L"Bearing", L"");
		if (config->LastKeyExist)
		{
			HandleBearing(StringKey);
		}
		
		StringKey = config->ReadString(L"Route", L"StartAirport", L"");
		if (config->LastKeyExist)
		{
			Route.StartAirportICAO = StringKey;
		}

		StringKey = config->ReadString(L"Route", L"EndAirport", L"");
		if (config->LastKeyExist)
		{
			Route.EndAirportICAO = StringKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"StartFromFavourite", 0);
		if (config->LastKeyExist)
		{
			Route.StartFromFavourite = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"UseAircraftRange", 0);
		if (config->LastKeyExist)
		{
			Route.UseAircraftRange = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"Time", 0);
		if (config->LastKeyExist)
		{
			Route.RequestedFlightTime = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"AircraftRangePercent", Defaults::DefaultACPC);
		if (config->LastKeyExist)
		{
			Route.AircraftRangePercent = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"SimpleRouteCount", -1);
		if (config->LastKeyExist)
		{
			Route.SimpleRouteCount = IntegerKey;
		}

		// == load from export section ================================================================

		IntegerKey = config->ReadInteger(L"Export", L"MSFS", 0);
		if (config->LastKeyExist)
		{
			Export.MSFS = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Export", L"Text", 0);
		if (config->LastKeyExist)
		{
			Export.Text = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Export", L"XPlane", 0);
		if (config->LastKeyExist)
		{
			Export.XPlane = IntegerKey;
		}

		// ============================================================================================

		delete config;

		return true;
	}

	delete config;

	return false;
}


std::wstring Configuration::GetAsCommandLineParameters()
{
	if (Parameters.size() != 0)
	{
		std::wstring output = L"";

		for (int t = 0; t < Parameters.size(); t++)
		{
			if (Parameters[t].property == L"")
			{
				output += Parameters[t].command + L" ";
			}
			else
			{
				output += Parameters[t].command + L":" + Parameters[t].property + L" ";
			}			
		}

		return output;
	}

	return L"";
}


// are you really too lazy to make your own config file?!
// only writes out values that differ from the defaults
bool Configuration::SaveConfiguration(const std::wstring file_name)
{
	std::ofstream ofile(file_name);

	if (ofile)
	{
		std::wcout << L"Saving current configuration to file: " << file_name << L"\n\n";

		ofile << Formatting::to_utf8(L"// Created " + DateUtility::DateTime(kDisplayModeConsole) + L"\n");
		ofile << Formatting::to_utf8(L"// Original command-line input: " + GetAsCommandLineParameters() + L"\n\n");

		ofile << Formatting::to_utf8(L"[Aircraft]\n");

		if (!Aircraft.Default)										ofile << Formatting::to_utf8(L"Default=0\n");
		if (!Aircraft.Custom)										ofile << Formatting::to_utf8(L"Custom=0\n");
		if (Aircraft.Type != Defaults::DefaultAircraftSelection)	ofile << Formatting::to_utf8(L"Type=" + std::to_wstring(Aircraft.Type) + L"\n");
		if (Aircraft.MaxSpeed != Defaults::DefaultMaxSpeed)			ofile << Formatting::to_utf8(L"MaxSpeed=" + std::to_wstring(Aircraft.MaxSpeed) + L"\n");
		if (Aircraft.MinSpeed != 0)									ofile << Formatting::to_utf8(L"MinSpeed=" + std::to_wstring(Aircraft.MinSpeed) + L"\n");
		if (Aircraft.Airliner != 1)									ofile << Formatting::to_utf8(L"Airliner=0\n");
		if (Aircraft.Military != 1)									ofile << Formatting::to_utf8(L"Military=0\n");

		switch (Aircraft.Special)
		{
		case AircraftConstants::SpecialMode::GA:
			ofile << Formatting::to_utf8(L"Special=ga\n");
			break;
		case AircraftConstants::SpecialMode::JetAirliners:
			ofile << Formatting::to_utf8(L"Special=jetairliners\n");
			break;
		case AircraftConstants::SpecialMode::Twins:
			ofile << Formatting::to_utf8(L"Special=twins\n");
			break;
		case AircraftConstants::SpecialMode::Props:
			ofile << Formatting::to_utf8(L"Special=props\n");
			break;
		case AircraftConstants::SpecialMode::TurboProps:
			ofile << Formatting::to_utf8(L"Special=turbos\n");
			break;
		}

		switch (Aircraft.Version)
		{
		case AircraftConstants::MSFSVersion::DeluxeAbove:
			ofile << Formatting::to_utf8(L"Version=1\n");
			break;
		case AircraftConstants::MSFSVersion::PremiumAbove:
			ofile << Formatting::to_utf8(L"Version=2\n");
		}

		ofile << Formatting::to_utf8(L"\n");

		// == save to airport section =================================================================

		ofile << Formatting::to_utf8(L"[Airport]\n");

		if (Airport.Continent != L"")								ofile << Formatting::to_utf8(L"Continent=" + Airport.Continent + L"\n");
		if (Airport.Country != L"")									ofile << Formatting::to_utf8(L"Country=" + Airport.Country + L"\n");
		if (Airport.Region != L"")									ofile << Formatting::to_utf8(L"Region=" + Airport.Region + L"\n");
		if (Airport.Elevation != 0)									ofile << Formatting::to_utf8(L"Elevation=" + std::to_wstring(Airport.Elevation) + L"\n");
		if (Airport.SmallAirports != 1)								ofile << Formatting::to_utf8(L"SmallAirports=" + std::to_wstring(Airport.SmallAirports) + L"\n");
		if (Airport.MediumAirports != 1)							ofile << Formatting::to_utf8(L"MediumAirports=" + std::to_wstring(Airport.MediumAirports) + L"\n");
		if (Airport.LargeAirports != 1)								ofile << Formatting::to_utf8(L"LargeAirports=" + std::to_wstring(Airport.LargeAirports) + L"\n");
		if (Airport.Heliports != 1)									ofile << Formatting::to_utf8(L"Heliports=" + std::to_wstring(Airport.Heliports) + L"\n");
		if (Airport.KeepTrying != 0)								ofile << Formatting::to_utf8(L"KeepTrying=1\n");

		if (Airport.LatitudeFilter)
		{
			if (Airport.LatitudeFrom != 1)							ofile << Formatting::to_utf8(L"LatitudeFrom=" + std::to_wstring(Airport.LatitudeFrom) + L"\n");
			if (Airport.LatitudeTo != 1)							ofile << Formatting::to_utf8(L"LatitudeTo=" + std::to_wstring(Airport.LatitudeTo) + L"\n");
		}

		if (Airport.LongitudeFilter)
		{
			if (Airport.LongitudeFrom != 1)							ofile << Formatting::to_utf8(L"LongitudeFrom=" + std::to_wstring(Airport.LongitudeFrom) + L"\n");
			if (Airport.LongitudeTo != 1)							ofile << Formatting::to_utf8(L"LongitudeTo=" + std::to_wstring(Airport.LongitudeTo) + L"\n");
		}

		if (Airport.Day)											ofile << Formatting::to_utf8(L"Day=1\n");
		if (Airport.Night)											ofile << Formatting::to_utf8(L"Night=1\n");

		ofile << Formatting::to_utf8(L"\n");

		// == save to route section ===================================================================

		ofile << Formatting::to_utf8(L"[Route]\n");

		if (Route.AtoB != 0)										ofile << Formatting::to_utf8(L"atob=1\n");
		if (Route.Range != Defaults::DefaultRange)					ofile << Formatting::to_utf8(L"Range=" + std::to_wstring(static_cast<int>(Route.Range)) + L"\n");
		if (Route.Legs != 1)										ofile << Formatting::to_utf8(L"Legs=" + std::to_wstring(Route.Legs) + L"\n");
		if (Route.Count != 1)										ofile << Formatting::to_utf8(L"Number=" + std::to_wstring(Route.Count) + L"\n");
		if (Route.Direction != -1)									ofile << Formatting::to_utf8(L"Direction=" + std::to_wstring(Route.Direction) + L"\n");
		if (Route.StartAirportICAO != L"")							ofile << Formatting::to_utf8(L"StartAirport=" + Route.StartAirportICAO + L"\n");
		if (Route.EndAirportICAO != L"")							ofile << Formatting::to_utf8(L"EndAirport=" + Route.EndAirportICAO + L"\n");
		if (Route.UseAircraftRange != 0)							ofile << Formatting::to_utf8(L"UseAircraftRange=1\n");
		if (Route.RequestedFlightTime != 0)							ofile << Formatting::to_utf8(L"Time=" + std::to_wstring(Route.RequestedFlightTime) + L"\n");
		if (Route.AircraftRangePercent != Defaults::DefaultACPC)	ofile << Formatting::to_utf8(L"AircraftRangePercent=" + std::to_wstring(Route.AircraftRangePercent) + L"\n");
		if (Route.StartFromFavourite != 0)                          ofile << Formatting::to_utf8(L"StartFromFavourite=1");
		if (Route.SimpleRouteCount != -1)                           ofile << Formatting::to_utf8(L"SimpleRouteCount=" + std::to_wstring(Route.SimpleRouteCount) + L"\n");

		ofile << Formatting::to_utf8(L"\n");

		// == save to export section ==================================================================

		ofile << Formatting::to_utf8(L"[Export]\n");

		if (!Export.MSFS)											ofile << Formatting::to_utf8(L"MSFS=1\n");
		if (!Export.Text)											ofile << Formatting::to_utf8(L"Text=1\n");
		if (!Export.XPlane)											ofile << Formatting::to_utf8(L"XPlane=1\n");

		ofile.close();

		return true;
	}

	return false;
}


std::wstring Configuration::GetFromFavourites()
{
	std::vector<std::wstring> Favourites;

	std::wifstream file(SystemConstants::FavouritesFileName);

	if (file)
	{
		std::wstring s = L"";

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				if (s[0] == L'/')
				{
					// comment, do nothing
				}
				else
				{
					Favourites.push_back(s);
				}
			}
		}

		file.close();

		if (Favourites.size() != 0)
		{
			return Favourites[rand() % Favourites.size()];
		}
	}
	else
	{
		std::wcout << L"Couldn't locate \"" << SystemConstants::FavouritesFileName << L"\" :(\n";
	}

	return L"";
}


bool Configuration::AddToFavourite(const std::wstring icao)
{
	if (icao != L"")
	{
		std::ofstream ofile(SystemConstants::FavouritesFileName, std::ios::app);

		if (ofile)
		{
			ofile << Formatting::to_utf8(icao + L"\n");
			ofile.close();

			return true;
		}
	}

	return false; 
}