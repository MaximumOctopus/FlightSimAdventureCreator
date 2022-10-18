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

#include <iostream>

#include "ConfigurationConstants.h"
#include "Constants.h"
#include "Defaults.h"
#include "Help.h"


namespace Help
{
	void ConsoleHeader()
	{
		std::wcout << L"\n  FlightSimAdventureCreator " << SystemConstants::FSACVersion << L", " << SystemConstants::FSACDate << L" :: paul@freshney.org\n\n";
	}

	void Commands()
	{
		Header();

		std::wcout << L"  If you find any bugs or have a feature request then plese email me at the address above.\n";
		std::wcout << L"\n";
		std::wcout << L"  Usage:\n";
		std::wcout << "\n";
		std::wcout << L"    fsac" << "\n";
		std::wcout << L"      will pick a random aircraft and random airport.\n";
		std::wcout << "\n";
		std::wcout << L"    fsac /atob" << "\n";
		std::wcout << L"      will pick a random aircraft and random route with one leg (airport A to airport B).\n";
		std::wcout << "\n";
		std::wcout << L"    fsac /atob /legs:2" << "\n";
		std::wcout << L"      will pick a random aircraft and random route with two legs (airport A -> airport B -> airport C).\n";
		std::wcout << "\n";
		std::wcout << L"    /loadconfig:file_name     : instead of typing out the same parameters everytime, use a pre-configured\n";
		std::wcout << L"                                config file. see config_readme.txt for more information on creating them.\n";
		std::wcout << L"    /saveconfig:file_name     : save the configuration created from the selected command-line parameter\n";
		std::wcout << L"                                to a config file. Only options which differ from the defaults are saved.\n";
		std::wcout << "\n";
		std::wcout << L"  the following options affect airport selection/randomisation:\n\n";
		std::wcout << L"    /elevation:min_elevation  : minimum airport elevation, in feet.\n";
		std::wcout << L"    /continent:selection      : select a specific continent\n";
		std::wcout << L"                                  AF, AN, AS, EU, NA, OC, SA\n";
		std::wcout << L"    /country:selection        : select a specific country\n";
	    std::wcout << L"                                  see https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2\n";
		std::wcout << L"    /region:selection         : select a specific region of a country\n";
		std::wcout << L"                                  https://en.wikipedia.org/wiki/ISO_3166-2 (links to available codes for each location)\n";
		std::wcout << L"    /direction:angle          : set the direction to fly (with " << Defaults::DefaultDirectionMargin << L" degrees added on either side)\n";
		std::wcout << L"    /bearing:compass 		  : set the direction to fly (with " << Defaults::DefaultDirectionMargin << L" degrees added on either side)\n";
		std::wcout << L"                                  N, NNE, NE, ENE, E, ESE, SE, SSE, S, SSW, SW, WSW, W, WNW, NW, NNW \n";
		std::wcout << "\n";
		std::wcout << L"    /latfrom:latitude         : from -> to, should go clockwise around the earth (as seen from the North Pole).\n";
		std::wcout << L"    /latto:latitude           : 0' is the Greenwich Meridian, +/-180 is the international date line.\n";
		std::wcout << L"    /longfrom:longitude       : from -> to, should go around the Earth anti-clockwise as seen side-on (0' to the left).\n";
		std::wcout << L"    /longto:longitude         : 0' is the equator, +90 North Pole, -90 South Pole.\n";
		std::wcout << "\n";
		std::wcout << L"    /keeptrying               : expand range and/or direction if the route cannot be continued due to lack\n";
		std::wcout << L"                                of airports within range and/or direction.\n";
		std::wcout << "\n";
		std::wcout << L"    /nosmall                  : ignore small aiports\n";
		std::wcout << L"    /nomedium                 : ignore medium aiports\n";
		std::wcout << L"    /nolarge                  : ignore large aiports\n";
		std::wcout << L"    /noheliports              : ignore heliports aiports\n";
		std::wcout << "\n";
		std::wcout << L"    /onlysmall                : only load small aiports\n";
		std::wcout << L"    /onlymedium               : only load medium aiports\n";
		std::wcout << L"    /onlylarge                : only load large aiports\n";
		std::wcout << L"    /onlyheliports            : only load heliports; this also changes aircraft to helicopters only.\n";
		std::wcout << "\n";
		std::wcout << L"    /day                      : select from airports where it's currently light\n";
		std::wcout << L"    /night                    : select from airports where it's currently dark\n";
		std::wcout << "\n";
		std::wcout << L"  the following options dictate route generation:\n\n";
		std::wcout << L"    /atob                     : enable route generation\n";
		std::wcout << L"    /legs:number              : number of legs (airports to visit)\n";
		std::wcout << L"    /range:distance           : maximum distance between legs (in nm)\n";
		std::wcout << L"                                +/-10% will be used when searching\n";
		std::wcout << L"                                append a k (/range:50k) to specify range in kilometres.\n";
		std::wcout << L"    /time:minutes             : an alternative to setting route length, is to set a flight time, and let FSAC calculate\n";
		std::wcout << L"                                a range. uses the selected aircraft's cruise speed and some number magic.\n";
		std::wcout << L"    /startairport:ICAO        : start random route from here.\n";
		std::wcout << L"    /endairport:ICAO          : end route here.\n";
		std::wcout << L"    /number:count             : create \"count\" routes (default is 1).\n";
		std::wcout << L"    /simple:count             : set how many A->B, 2-leg only, routes are display (default is " << Defaults::DefaultShortRoutesToShow << L")\n";
		std::wcout << "\n";
		std::wcout << L"    /route:start_airport:range:legs:direction/bearing\n";
		std::wcout << "\n";
		std::wcout << L"                              : set several route settings within a single parameter.\n";
		std::wcout << L"                              : Accepts a direction angle or compass bearing.\n";
		std::wcout << L"                              : No setting is mandatory, just leave that bit blank. See manual for more details.\n";
		std::wcout << "\n";
		std::wcout << L"    /favourite                : pick a random airport from \"" << SystemConstants::FavouritesFileName << L"\".\n";
		std::wcout << "\n";
		std::wcout << L"    /useaircraftrange         : uses the randomly-selected aircraft range\n";
		std::wcout << L"                                for leg distance (uses, default " << Defaults::DefaultACPC << L"% of this value)\n";
		std::wcout << L"    /aircraftrange:percent    : change the default " << Defaults::DefaultACPC << L"% to a new value, 1 - 100\n";
		std::wcout << "\n";
		std::wcout << L"    /allowexcessrange         : allow routes longer than the selected aircraft's maximum range.\n";
		std::wcout << L"                                by default, the maximum leg length will be adjusted to fit.\n";
		std::wcout << "\n";
		std::wcout << L"  the following options affect aircraft selection:\n\n";
		std::wcout << L"    /nodefault                : ignores aircraft from \"" << SystemConstants::DefaultAircraft << L"\"\n";
		std::wcout << L"    /nocustom                 : ignores aircraft from \"" << SystemConstants::CustomAircraft << L"\n";
		std::wcout << L"    /msfsversion:version      : import based on which version of MSFS they are available in:\n";
		std::wcout << L"                                0 - all (including third party), 1 - deluxe, 2 - premium deluxe\n";
		std::wcout << "\n";
		std::wcout << L"    /maxspeed:speed           : maximum cruise speed in kts (default is " << Defaults::DefaultMaxSpeed << L" kts)\n";
		std::wcout << L"    /minspeed:speed           : minimum cruise speed in kts (default is 0 kts)\n";
		std::wcout << "\n";
		std::wcout << L"    /aircrafttype:type        : use only selected aircraft type:\n";
		std::wcout << L"                                0 - props, 1 - jets, 2 - heli, 3 - glider, 4 - twin prop\n";
		std::wcout << L"                                5 - turbo prop, 6 - twin turbo prop, 7 - balloon, 8 - seaplane\n";
		std::wcout << L"    /noairliner               : ignore airliners\n";
		std::wcout << L"    /nomilitary               : ignore military aircraft\n";
		std::wcout << "\n";
		std::wcout << L"    /ga                       : use only GA aircraft (all props, turbo props, twins, no military, no airliners)\n";
		std::wcout << L"    /ja                       : use only jet airliners (jet, airliners, no military)\n";
		std::wcout << L"    /twins                    : use only twin props (twin props and twin turbo props)\n";
		std::wcout << L"    /props                    : use only props (props and twin prop)\n";
		std::wcout << L"    /turbos                   : use only turbo props (turbo props and twin turbo props)\n";
		std::wcout << "\n";
		std::wcout << L"  the following are export options:\n\n";
		std::wcout << L"    /exportmsfs               : export all generated routes to MSFS plan files\n";
		std::wcout << L"                                \"\\plans\\icao_from_to_icao_to_yyyymmdd_hhmmss.pln\"\n";
		std::wcout << L"    /exporttext               : export your routes as an itinerary text file\n";
		std::wcout << L"                                \"\\reports\\icao_from_to_icao_to_yyyymmdd_hhmmss.txt\"\n";
		std::wcout << "\n";
		std::wcout << L"  miscellaneous options:\n\n";
		std::wcout << L"    /q                        : will silence some output (full config details, and loaded data stats).\n";
		std::wcout << L"    /fsacca                   : automatically generate the custom_aircraft.txt file. Edits will be lost.\n";
		std::wcout << "\n";
		std::wcout << L"  data analysis options (FSAC will exit after running these):\n\n";
		std::wcout << L"    /findnearest:selection    : show all airports within range of the selection. must be an ICAO code.\n";
		std::wcout << "\n";
		#ifdef _DEBUG
		std::wcout << "   the following are special magic:\n\n";
		std::wcout << L"    /fsacxa                   : merges aircraft.csv (from ourairports.com) and a file containing\n";
		std::wcout << L"                                MSFS compatibily data to create fsac.csv. Read the source code\n";
		std::wcout << L"                                before trying to use this one :) (FSACAirportData.cpp)\n";
		std::wcout << L"    /fsacxr                   : builds runway data.\n";
		std::wcout << "\n";
		#endif
	}


	void Header()
	{
		std::wcout << L"\n  FlightSimAdventureCreator " << SystemConstants::FSACVersion << " / " << SystemConstants::FSACDate << "\n\n";
		std::wcout << L"      https://github.com/MaximumOctopus/FlightSimAdventureCreator" << "\n";
		std::wcout << L"      paul@freshney.org" << "\n\n";
	}


	// all of my software is now free and open source. 
	// please donate to your local cat charity or shelter.
	void Cat()
	{
		std::wcout << "\n";
		std::wcout << L"               *        ,MMM8&&&.            *" << "\n";
		std::wcout << L"                       MMMM88&&&&&    ." << "\n";
		std::wcout << L"                      MMMM88&&&&&&&" << "\n";
		std::wcout << L"       *              MMM88&&&&&&&&" << "\n";
		std::wcout << L"                      MMM88&&&&&&&&" << "\n";
		std::wcout << L"                      'MMM88&&&&&&'" << "\n";
		std::wcout << L"                        'MMM8&&&'      *" << "\n";
		std::wcout << L"            |\\___/|" << "\n";
		std::wcout << L"            )     (             .              " << "\n";
		std::wcout << L"           =\\     /=" << "\n";
		std::wcout << L"             )===(       *" << "\n";
		std::wcout << L"            /     \\" << "\n";
		std::wcout << L"            |     |" << "\n";
		std::wcout << L"           /       \\" << "\n";
		std::wcout << L"           \\       /" << "\n";
		std::wcout << L"    _/\\_/\\_/\\__  _/_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_" << "\n";
		std::wcout << L"    |  |  |  |( (  |  |  |  |  |  |  |  |  |  |" << "\n";
		std::wcout << L"    |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |" << "\n";
		std::wcout << L"    |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |" << "\n";
		std::wcout << L"    |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << "\n";
		std::wcout << L"    |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << "\n";
		std::wcout << "\n";
		std::wcout << L"please donate to your local cat charity or shelter.\n\n";
		std::wcout << L"A big thanks to my cats: Rutherford, Freeman, and Maxwell" << "\n";
		std::wcout << "\n";
		std::wcout << L"        www.maximumoctopus.com/developmentcats.htm" << "\n";
		std::wcout << "\n";
	}
}