//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2023-2024
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
#include "Defaults.h"


#pragma region CommandLineParameters
static const std::wstring kCats = L"/cat";							// the best option of them all

static const std::wstring kLoadConfig = L"/loadconfig";				// loads a configuration from a file
static const std::wstring kSaveConfig = L"/saveconfig";				// saves configuration to a file

static const std::wstring kElevation = L"/elevation";				// set a minimum airport elevation
static const std::wstring kContinent = L"/continent";				// filter airports by specified continent
static const std::wstring kCountry = L"/country";					// filter airports by a specified country
static const std::wstring kRegion = L"/region";						// filter airports by a specified region

static const std::wstring kLatitudeMax = L"/latfrom";				// from -> to goes North to South
static const std::wstring kLatitudeMin = L"/latto";					//
static const std::wstring kLongitudeMax = L"/longfrom";				// from -> to goes clockwise around Earth
static const std::wstring kLongitudeMin = L"/longto";				// 

static const std::wstring kNoSmallAiports = L"/nosmall";			// ignore small aiports
static const std::wstring kNoMediumAiports = L"/nomedium";			// ignore medium airports
static const std::wstring kNoLargeAiports = L"/nolarge";			// ignore large airports
static const std::wstring kNoHeliports = L"/noheliports";			// ignore heliports

static const std::wstring kOnlySmallAiports = L"/onlysmall";		// only load small aiports
static const std::wstring kOnlyMediumAiports = L"/onlymedium";		// only load medium airports
static const std::wstring kOnlyLargeAiports = L"/onlylarge";		// only large airports
static const std::wstring kOnlyHeliports = L"/onlyheliports";       // only heliports, switches aircraft type to helicopters

static const std::wstring kAtoB = L"/atob";							// activate route generation
static const std::wstring kRealWorld = L"/real";					// search real-world routes
static const std::wstring kSimpleCount = L"/simple";				// how many of the simple routes to display
static const std::wstring kLegs = L"/legs";							// number of legs per route (default is 1)
static const std::wstring kRange = L"/range";						// set maximum leg distance nm
static const std::wstring kStartAirport = L"/startairport";			// optionally start the route at a specified aiport ICAO
static const std::wstring kEndAirport = L"/endairport";				// optionally end the the route at a specified aiport ICAO
static const std::wstring kStartFromFavourite = L"/favourite";		// pick a random airport from favourites.txt
static const std::wstring kCount = L"/number";						// number of multi-leg routes to generate
static const std::wstring kBearing = L"/bearing";					// set bearing to travel (with some margin of error)
static const std::wstring kDirection = L"/direction";               // direction to travel (with some margin of error)
static const std::wstring kRoute = L"/route";
static const std::wstring kExtraDetail = L"/extra";					// extra detail for console output

static const std::wstring kInternal = L"/internal";
static const std::wstring kExternal = L"/external";
static const std::wstring kAirline = L"/airline";

static const std::wstring kDay = L"/day";							// find airports currently in daylight
static const std::wstring kNight = L"/night";						// find airports currently in night
static const std::wstring kTime = L"/time";							// find a route that takes a certain time to fly

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
static const std::wstring kAircraftSeaplanes = L"/seaplanes";		// only seaplanes and allows seaplane bases
static const std::wstring kAircraftMaximumSpeed = L"/maxspeed";		// minimum cruise speed
static const std::wstring kAircraftMinimumSpeed = L"/minspeed";		// minimum cruise speed
static const std::wstring kAllowExcessRange = L"/allowexcessrange";	// if a route is longer than the max range of the aircraft it will fail, this bypass the checks

static const std::wstring kMSFSPlanFile = L"/exportmsfs";			// export each generated route to an MSFS-format pln file
static const std::wstring kTextItinerary = L"/exporttext";			// export a text itinerary
static const std::wstring kXPlaneFMSFile = L"/exportxplane";		// export to an#Plane v11 Flight Plane (.fms)

static const std::wstring kNoDefaultAircraft = L"/nodefault";		// exclude default aircraft
static const std::wstring kNoCustomAircraft = L"/nocustom";			// exclude custom aircraft

static const std::wstring kKeepTrying = L"/keeptrying";				// will expand user direction and range until options exhausted
static const std::wstring kMoreRandom = L"/morerandom";				// choses a new source/destination for each route (single leg only)

static const std::wstring kFindNearest = L"/findnearest";			// find nearest airports
static const std::wstring kListAirports = L"/list";

static const std::wstring kSilent = L"/q";							// silences non-route-related output
static const std::wstring kAddStartToFav = L"/astf";                // add startairport to favourites
static const std::wstring kAddEndToFav = L"/aetf";                  // add endairport to favourites

static const std::wstring kHelp = L"/help";							// 
static const std::wstring kHelpLazy = L"/?";						//

static const std::wstring kCustomAircraftFile = L"/fsacca";			// creates custom_aircraft.txt from user's community folder

static const std::wstring kFSACXAirports = L"/fsacxa";				// builds the fsac airports file file from two input files
static const std::wstring kFSACXRunways  = L"/fsacxr";				// builds the fsac airports file file from two input files
static const std::wstring kFSACXRoutes   = L"/fsacxf";

static const std::wstring kGetVersion = L"/version";


enum class ParameterOption {
	None = 0, Cats = 1, LoadConfig = 2, Elevation = 3, Continent = 4, Country = 5, Region = 6, NoSmall = 7, NoMedium = 8, NoLarge = 9,
	NoHeliports = 10, OnlySmall = 11, OnlyMedium = 12, OnlyLarge = 13, OnlyHeliports = 14, AToB = 15, Legs = 16, Range = 17, StartAirport = 18, EndAirport = 19, Count = 20, Bearing = 21,
	Direction = 22, UseAircraftRange = 23, AircraftRange = 24, MSFSVersion = 25, AircraftType = 26, NoAirliner = 27, NoMilitary = 28,
	GAOnly = 29, JAOnly = 30, TwinsOnly = 31, Props = 32, TurboProps = 33,
	MaxSpeed = 34, MinSpeed = 35, AllowExcessRange = 36,
	ExportMSFS = 37, ExportText = 38, ExportXPlane = 39,
	NoDefault = 40, NoCustom = 41, KeepTrying = 42, FindNearest = 43, Help = 44, SaveConfig = 45,
	Day = 46, Night = 47, StartFromFavourite = 48, SimpleRouteCount = 49, Silent = 50, ListAirports = 51,
	Time = 52, LatitudeMax = 53, LatitudeMin = 54, LongitudeMax = 55, LongitudeMin = 56,
	AddStartToFav = 57, AddEndToFav = 58, Seaplanes = 59, Route = 60, RealWorld = 61, Internal = 62, External = 63, Airline = 64,
	ExtraDetail = 65, MoreRandom = 66
};


static const int kCommandListCount = 67;

static const std::wstring CommandList[kCommandListCount] = { kCats, kLoadConfig, kElevation, kContinent, kCountry, kRegion, kNoSmallAiports, kNoMediumAiports, kNoLargeAiports,
	kNoHeliports, kOnlySmallAiports, kOnlyMediumAiports, kOnlyLargeAiports, kOnlyHeliports, kAtoB, kLegs, kRange, kStartAirport, kEndAirport, kCount, kBearing,
	kDirection, kUseAircraftRange, kAircraftRange, kMSFSVersion, kAircraftType, kAircraftNoAirliner, kAircraftNoMilitary,
	kAircraftGAOnly, kAircraftJetAirlinerOnly, kAircraftTwinsOnly, kAircraftPropsOnly, kAircraftTurbosOnly, 
	kAircraftMaximumSpeed, kAircraftMinimumSpeed, kAllowExcessRange,
	kMSFSPlanFile, kTextItinerary, kXPlaneFMSFile,
	kNoDefaultAircraft, kNoCustomAircraft, kKeepTrying, kFindNearest, kHelp, kHelpLazy, kSaveConfig, 
	kDay, kNight, kStartFromFavourite, kSimpleCount, kSilent, kListAirports,
	kTime, kLatitudeMax, kLatitudeMin, kLongitudeMax, kLongitudeMin, kAddStartToFav, kAddEndToFav,
	kAircraftSeaplanes, kRoute,
	kRealWorld, kInternal, kExternal, kAirline,
	kExtraDetail, kMoreRandom
};


static const ParameterOption ParameterReference[kCommandListCount] = { ParameterOption::Cats, ParameterOption::LoadConfig, ParameterOption::Elevation, ParameterOption::Continent, ParameterOption::Country, ParameterOption::Region, ParameterOption::NoSmall, ParameterOption::NoMedium, ParameterOption::NoLarge,
	ParameterOption::NoHeliports, ParameterOption::OnlySmall, ParameterOption::OnlyMedium, ParameterOption::OnlyLarge, ParameterOption::OnlyHeliports, ParameterOption::AToB, ParameterOption::Legs, ParameterOption::Range, ParameterOption::StartAirport, ParameterOption::EndAirport, ParameterOption::Count, ParameterOption::Bearing,
	ParameterOption::Direction, ParameterOption::UseAircraftRange, ParameterOption::AircraftRange, ParameterOption::MSFSVersion, ParameterOption::AircraftType, ParameterOption::NoAirliner, ParameterOption::NoMilitary,
	ParameterOption::GAOnly, ParameterOption::JAOnly, ParameterOption::TwinsOnly, ParameterOption::Props, ParameterOption::TurboProps, 
	ParameterOption::MaxSpeed, ParameterOption::MinSpeed, ParameterOption::AllowExcessRange,
	ParameterOption::ExportMSFS, ParameterOption::ExportText, ParameterOption::ExportXPlane,
	ParameterOption::NoDefault, ParameterOption::NoCustom, ParameterOption::KeepTrying, ParameterOption::FindNearest, ParameterOption::Help, ParameterOption::Help, ParameterOption::SaveConfig,
	ParameterOption::Day, ParameterOption::Night, ParameterOption::StartFromFavourite, ParameterOption::SimpleRouteCount, ParameterOption::Silent, ParameterOption::ListAirports,
	ParameterOption::Time,  ParameterOption::LatitudeMax, ParameterOption::LatitudeMin, ParameterOption::LongitudeMax, ParameterOption::LongitudeMin,
	ParameterOption::AddStartToFav, ParameterOption::AddEndToFav, ParameterOption::Seaplanes, ParameterOption::Route,
	ParameterOption::RealWorld, ParameterOption::Internal, ParameterOption::External, ParameterOption::Airline,
	ParameterOption::ExtraDetail, ParameterOption::MoreRandom
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
	int MaxSpeed = DataDefaults::MaxSpeed;				// maximum cruise speed

	int Type = -1;									// 0 = prop, 1 = jet, 2 = heli, 3 = glider, 4 = twin prop, 5 = turbo props, 6 = twin turbo props

	bool Airliner = true;
	bool Military = true;
	bool Seaplane = true;

	AircraftConstants::SpecialMode Special = AircraftConstants::SpecialMode::None;		// special options that combine other options in a cool way

	bool AllowExcessRange = false;					// allow routes longer than the aircraft's max range

	AircraftConstants::MSFSVersion Version = AircraftConstants::MSFSVersion::All;
};


struct AirportData {
	int Elevation = 0;								// minimum airport elevation in feet

	bool SmallAirports = true;
	bool MediumAirports = true;
	bool LargeAirports = true;
	bool Heliports = true;
	bool SeaplaneBases = false;

	std::wstring Continent = L"";					// ISO code
	std::wstring Country = L"";						// ISO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
	std::wstring Region = L"";						// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links for each country to available codes)

	bool KeepTrying = false;
	bool MoreRandom = false;

	double LongitudeFrom = 0;						// limit airports to a range of longitudes
	double LongitudeTo = 0;							//
	double LatitudeFrom = 0;						// limit airports to a range of latitudes
	double LatitudeTo = 0;							
	bool LongitudeFilter = false;
	bool LatitudeFilter = false;

	bool Day = false;
	bool Night = false;

	bool ListAirports = false;						// list all loaded airports
};


struct ExportData 
{
	bool MSFS = false;
	bool Text = false;
	bool XPlane = false;
};


struct RouteData 
{
	bool AtoB = false;								// route generation on (true) or off
	bool AtoBAutomatic = false;						// if it appears the user has forgotten to add /atob then FSAC will add it automagically
	bool RealWorld = false;							// selects from the ~60000 real world routes

	bool InternalOnly = false;						// used by realworld routes
	bool ExternalOnly = false;						// used by realworld routes

	double Range = DataDefaults::Range;				// nautical miles
	int Legs = 1;
	int Count = 1;									// how many multi-leg routes to generate
	double Direction = DataDefaults::Direction;		// travel direction, +20 degrees on each side
	std::wstring StartAirportICAO = L"";			// start journey at specified airport
	std::wstring EndAirportICAO = L"";				// end journey at specified airport

	std::wstring Airline = L"";						// only routes run by specified airline

	bool StartFromFavourite = false;				// will pick a random airport from Favourites.txt

	bool UseAircraftRange = false;

	double AircraftRangePercent = DataDefaults::AircraftRangePC;	// % modifier to apply to aircraft range to get usable range

	int SimpleRouteCount = -1;						// no need to set a default, -1 will tell the airporthandler to use its default

	std::wstring FindNearestICAO = L"";

	int RequestedFlightTime = 0;					// in minutes
};


struct MetaData {
	bool LoadedFromConfig = false;
	bool SaveToConfig = false;
	std::wstring SaveFileName = L"";
	bool ShowConfig = false;
	bool Silent = false;
	bool ExtraDetail = false;

	bool OnlyNeedAirports = false;					// used to stop aircraft, runways, and jobs loading if they're not needed.
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
	void HandleLatLong(const std::wstring, Constants::LatLongSelection);
	void HandleMSFSVersion(const std::wstring);
	void HandleRange(const std::wstring);
	void HandleRoute(const std::wstring);
	void HandleSimpleRouteCount(std::wstring);
	void HandleSpecial(const std::wstring);
	void HandleTime(const std::wstring);

	void SetLongitude(Constants::TimeOfDay, int);

	[[nodiscard]] bool LoadConfiguration(const std::wstring);
	[[nodiscard]] bool SaveConfiguration(const std::wstring);

	[[nodiscard]] std::wstring GetAsCommandLineParameters();

	[[nodiscard]] std::wstring GetFromFavourites();

	[[nodiscard]] bool AddToFavourite(const std::wstring);

public:

	AirportData Airport;
	AircraftData Aircraft;
	RouteData Route;
	ExportData Export;
	MetaData Meta;

	HelperFunctions Helpers;

	Configuration(int argc, wchar_t* argv[]);

	bool FindParameter(std::wstring);

	bool SetRangeFromTime(int, AircraftConstants::AircraftType);
};