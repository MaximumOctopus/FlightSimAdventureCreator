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

#pragma once


#include <string>
#include <vector>

#include "AircraftConstants.h"
#include "Constants.h"
#include "ConfigurationConstants.h"


#pragma region CommandLineParameters
static const std::wstring kCats = L"/cat";							// the best option of them all

static const std::wstring kLoadConfig = L"/loadconfig";				// loads a configuration from a file
static const std::wstring kSaveConfig = L"/saveconfig";				// saves configuration to a file

static const std::wstring kElevation = L"/elevation";				// set a minimum airport elevation
static const std::wstring kContinent = L"/continent";				// filter airports by specified continent
static const std::wstring kCountry = L"/country";					// filter airports by a specified country
static const std::wstring kRegion = L"/region";						// filter airports by a specified region

static const std::wstring kNoSmallAiports = L"/nosmall";			// ignore small aiports
static const std::wstring kNoMediumAiports = L"/nomedium";			// ignore medium airports
static const std::wstring kNoLargeAiports = L"/nolarge";			// ignore large airports
static const std::wstring kNoHeliports = L"/noheliports";			// ignore heliports

static const std::wstring kOnlySmallAiports = L"/onlysmall";		// only load small aiports
static const std::wstring kOnlyMediumAiports = L"/onlymedium";		// only load medium airports
static const std::wstring kOnlyLargeAiports = L"/onlylarge";		// only large airports
static const std::wstring kOnlyHeliports = L"/onlyheliports";       // only heliports, switches aircraft type to helicopters

static const std::wstring kAtoB = L"/atob";							// activate route generation
static const std::wstring kSimpleCount = L"/simple";				// how many of the simple routes to display
static const std::wstring kLegs = L"/legs";							// number of legs per route (default is 1)
static const std::wstring kRange = L"/range";						// set maximum leg distance nm
static const std::wstring kStartAirport = L"/startairport";			// optionally start the route at a specified aiport ICAO
static const std::wstring kEndAirport = L"/endairport";				// optionally end the the route at a specified aiport ICAO
static const std::wstring kStartFromFavourite = L"/favourite";		// pick a random airport from favourites.txt
static const std::wstring kCount = L"/number";						// number of multi-leg routes to generate
static const std::wstring kBearing = L"/bearing";					// set bearing to travel (with some margin of error)
static const std::wstring kDirection = L"/direction";               // direction to travel (with some margin of error)
static const std::wstring kDay = L"/day";							// find airports currently in daylight
static const std::wstring kNight = L"/night";						// find airports currently in night

static const std::wstring kUseAircraftRange = L"/useaircraftrange";	// use random aircraft range for maximum leg distance
static const std::wstring kAircraftRange = L"/aircraftrange";		// set the % modifier to apply to max range to get above

static const std::wstring kMSFSVersion = L"/msfsversion";			// select aircraft based on MSFS version that appear in
static const std::wstring kAircraftType = L"/aircrafttype";			// specify a specific aircraft type
static const std::wstring kAircraftNoAirliner = L"/noairliner";		// no airliners
static const std::wstring kAircraftNoMilitary = L"/nomilitary";		// no military aircraft
static const std::wstring kAircraftGAOnly = L"/ga";					// only GA (which I define as props, twin, turbo prop, no airliner, no military)
static const std::wstring kAircraftJetAirlinerOnly = L"/ja";		// only jet airliners (jet, no military)
static const std::wstring kAircraftTwinsOnly = L"/twins";			// only twin props and twin turbo props (military and airliners allowed)
static const std::wstring kAircraftPropsOnly = L"/props";			// only twin props and twin turbo props (military and airliners allowed)
static const std::wstring kAircraftTurbosOnly = L"/turbos";			// only turbos and twin turbos (military and airliners allowed)
static const std::wstring kAircraftMaximumSpeed = L"/maxspeed";		// minimum cruise speed
static const std::wstring kAircraftMinimumSpeed = L"/minspeed";		// minimum cruise speed
static const std::wstring kAllowExcessRange = L"/allowexcessrange";	// if a route is longer than the max range of the aircraft it will fail, this bypass the checks

static const std::wstring kMSFSPlanFile = L"/exportmsfs";			// export each generated route to an MSFS-format pln file
static const std::wstring kTextItinerary = L"/exporttext";			// export a text itinerary to do
static const std::wstring kXPlaneFMSFile = L"/exportxplane";		// export to an#Plane v11 Flight Plane (.fms)

static const std::wstring kNoDefaultAircraft = L"/nodefault";		// exclude default aircraft
static const std::wstring kNoCustomAircraft = L"/nocustom";			// exclude custom aircraft

static const std::wstring kKeepTrying = L"/keeptrying";				// will expand user direction and range until options exhausted

static const std::wstring kFindNearest = L"/findnearest";			// find nearest airports
static const std::wstring kListAirports = L"/list";

static const std::wstring kSilent = L"/q";							// silences non-route-related output

static const std::wstring kHelp = L"/help";							// 
static const std::wstring kHelpLazy = L"/?";						//


enum class ParameterOption {
	None = 0, Cats = 1, LoadConfig = 2, Elevation = 3, Continent = 4, Country = 5, Region = 6, NoSmall = 7, NoMedium = 8, NoLarge = 9,
	NoHeliports = 10, OnlySmall = 11, OnlyMedium = 12, OnlyLarge = 13, OnlyHeliports = 14, AToB = 15, Legs = 16, Range = 17, StartAirport = 18, EndAirport = 19, Count = 20, Bearing = 21,
	Direction = 22, UseAircraftRange = 23, AircraftRange = 24, MSFSVersion = 25, AircraftType = 26, NoAirliner = 27, NoMilitary = 28,
	GAOnly = 29, JAOnly = 30, TwinsOnly = 31, Props = 32, TurboProps = 33,
	MaxSpeed = 34, MinSpeed = 35, AllowExcessRange = 36,
	ExportMSFS = 37, ExportXPlane = 38,
	NoDefault = 39, NoCustom = 40, KeepTrying = 41, FindNearest = 42, Help = 43, SaveConfig = 44,
	Day = 45, Night = 46, StartFromFavourite = 47, SimpleRouteCount = 48, Silent = 49, ListAirports = 50
};


static const int kCommandListCount = 51;

static const std::wstring CommandList[kCommandListCount] = { kCats, kLoadConfig, kElevation, kContinent, kCountry, kRegion, kNoSmallAiports, kNoMediumAiports, kNoLargeAiports,
	kNoHeliports, kOnlySmallAiports, kOnlyMediumAiports, kOnlyLargeAiports, kOnlyHeliports, kAtoB, kLegs, kRange, kStartAirport, kEndAirport, kCount, kBearing,
	kDirection, kUseAircraftRange, kAircraftRange, kMSFSVersion, kAircraftType, kAircraftNoAirliner, kAircraftNoMilitary,
	kAircraftGAOnly, kAircraftJetAirlinerOnly, kAircraftTwinsOnly, kAircraftPropsOnly, kAircraftTurbosOnly, 
	kAircraftMaximumSpeed, kAircraftMinimumSpeed, kAllowExcessRange,
	kMSFSPlanFile, kXPlaneFMSFile,
	kNoDefaultAircraft, kNoCustomAircraft, kKeepTrying, kFindNearest, kHelp, kHelpLazy, kSaveConfig, 
	kDay, kNight, kStartFromFavourite, kSimpleCount, kSilent, kListAirports
};


static const ParameterOption ParameterReference[kCommandListCount] = { ParameterOption::Cats, ParameterOption::LoadConfig, ParameterOption::Elevation, ParameterOption::Continent, ParameterOption::Country, ParameterOption::Region, ParameterOption::NoSmall, ParameterOption::NoMedium, ParameterOption::NoLarge,
	ParameterOption::NoHeliports, ParameterOption::OnlySmall, ParameterOption::OnlyMedium, ParameterOption::OnlyLarge, ParameterOption::OnlyHeliports, ParameterOption::AToB, ParameterOption::Legs, ParameterOption::Range, ParameterOption::StartAirport, ParameterOption::EndAirport, ParameterOption::Count, ParameterOption::Bearing,
	ParameterOption::Direction, ParameterOption::UseAircraftRange, ParameterOption::AircraftRange, ParameterOption::MSFSVersion, ParameterOption::AircraftType, ParameterOption::NoAirliner, ParameterOption::NoMilitary,
	ParameterOption::GAOnly, ParameterOption::JAOnly, ParameterOption::TwinsOnly, ParameterOption::Props, ParameterOption::TurboProps, 
	ParameterOption::MaxSpeed, ParameterOption::MinSpeed, ParameterOption::AllowExcessRange,
	ParameterOption::ExportMSFS, ParameterOption::ExportXPlane,
	ParameterOption::NoDefault, ParameterOption::NoCustom, ParameterOption::KeepTrying, ParameterOption::FindNearest, ParameterOption::Help, ParameterOption::Help, ParameterOption::SaveConfig,
	ParameterOption::Day, ParameterOption::Night, ParameterOption::StartFromFavourite, ParameterOption::SimpleRouteCount, ParameterOption::Silent, ParameterOption::ListAirports
};
#pragma endregion


struct ParameterData {
	std::wstring command = L"";
	std::wstring property = L"";

	ParameterOption option = ParameterOption::None;
};


struct HelperFunctions {
	bool FindNearest = false;
};


struct AircraftData {
	bool Default = true;							// default_aircraft.txt
	bool Custom = true;								// custom_aircraft.txt

	int MinSpeed = 0;								// minimum cruise speed
	int MaxSpeed = Defaults::DefaultMaxSpeed;		// maximum cruise speed

	int Type = -1;									// 0 = prop, 1 = jet, 2 = heli, 3 = glider, 4 = twin prop, 5 = turbo props, 6 = twin turbo props

	bool Airliner = true;
	bool Military = true;

	SpecialMode Special = SpecialMode::None;		// special options that combine other options in a cool way

	bool AllowExcessRange = false;					// allow routes longer than the aircraft's max range

	AircraftConstants::MSFSVersion Version = AircraftConstants::MSFSVersion::All;
};


struct AirportData {
	int Elevation = 0;								// minimum airport elevation in feet

	bool SmallAirports = true;
	bool MediumAirports = true;
	bool LargeAirports = true;
	bool Heliports = true;

	std::wstring Continent = L"";					// ISO code
	std::wstring Country = L"";						// ISO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
	std::wstring Region = L"";						// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links for each country to available codes)

	bool KeepTrying = false;

	double LongitudeFrom = 0;						// limit airports to a range of longitudes
	double LongitudeTo = 0;							//

	bool Day = false;
	bool Night = false;

	bool ListAirports = false;						// list all loaded airports
};


struct ExportData {
	bool MSFS = false;
	bool XPlane = false;
};


struct RouteData {
	bool AtoB = false;
	double Range = Defaults::DefaultRange;			// nautical miles
	int Legs = 1;
	int Count = 1;									// how many multi-leg routes to generate
	int Direction = Defaults::DefaultDirection;		// travel direction, +20 degrees on each side
	std::wstring StartAirportICAO = L"";			// start journey at specified airport
	std::wstring EndAirportICAO = L"";				// end journey at specified airport

	bool StartFromFavourite = false;				// will pick a random airport from Favourites.txt

	bool UseAircraftRange = false;

	double AircraftRangePercent = Defaults::DefaultACPC;	// % modifier to apply to aircraft range to get usable range

	int SimpleRouteCount = -1;						// no need to set a default, -1 will tell the airporthandler to use its default

	std::wstring FindNearestICAO = L"";
};


struct MetaData {
	bool LoadedFromConfig = false;
	bool SaveToConfig = false;
	std::wstring SaveFileName = L"";
	bool ShowConfig = false;
	bool Silent = false;
};


class Configuration
{
	std::vector<ParameterData> Parameters;

	void ShowConfiguration();
	void SetFromCommandLine();

	[[nodiscard]] int SafelyGetIntFromString(const std::wstring, int);

	[[nodiscard]] std::wstring GetCommandValue(const std::wstring);
	[[nodiscard]] std::wstring GetPropertyValue(const std::wstring);
	[[nodiscard]] ParameterOption GetPropertyOption(const std::wstring);

	[[nodiscard]] bool IsValidParameter(const std::wstring);

	void HandleAircraftMaxSpeed(const std::wstring);
	void HandleAircraftMinSpeed(const std::wstring);
	void HandleAircraftRangePercent(const std::wstring);
	void HandleAircraftType(const std::wstring);
	void HandleBearing(const std::wstring);
	void HandleContinent(const std::wstring);
	void HandleCount(const std::wstring);
	void HandleCountry(const std::wstring);
	void HandleDirection(const std::wstring);
	void HandleElevation(const std::wstring);
	void HandleLegs(const std::wstring);
	void HandleMSFSVersion(const std::wstring);
	void HandleRange(const std::wstring);
	void HandleSimpleRouteCount(std::wstring);
	void HandleSpecial(const std::wstring);

	void SetLongitude(Constants::TimeOfDay, int);

	[[nodiscard]] bool LoadConfiguration(const std::wstring);
	[[nodiscard]] bool SaveConfiguration(const std::wstring);

	[[nodiscard]] std::wstring GetAsCommandLineParameters();

	[[nodiscard]] std::wstring GetFromFavourites();

public:

	AirportData Airport;
	AircraftData Aircraft;
	RouteData Route;
	ExportData Export;
	MetaData Meta;

	HelperFunctions Helpers;

	Configuration(int argc, wchar_t* argv[]);

	bool FindParameter(std::wstring);
};