//
// FSAC configuration file help, October 5th 2022
//
// if you use the same command-line options regularly then a config file is just the thing for you!
// it allows you to configure FSAC in a single file.
// not all of the following fields are required (and in fact using them all is likely to cause problems.
// (eg continent, country, and region used together makes no sense and could cause zero airports to be loaded)
// the defaults will be applied to all unset parameters (as they would be from using command-line parameters)
//
// to use your new and exciting config file:
//
//     fsac /loadconfig:file_name
//
// you can also create a config file from FSAC: just add /saveconfig:file_name after your parameter list
// to save your details to the file name specified.
//  

// set the pool of aircraft your random one will be picked from
[aircraft]
// use default aircraft (from default_aircraft.txt): 1 = yes, 0 = no
Default=1
// use custom aircraft (from custom_aircraft.txt): 1 = yes, 0 = no
Custom=1
// filter by a single aircraft type: 0 = prop, 1 = jet, 2 = heli, 3 = glider, 4 = twin prop, 5 = turbo prop, 6 = twin turbo prop
Type=-1
// include airliners: 1 = yes, 0 = no
Airliner=1
// include military: 1 = yes, 0 = no
Military=1
// maximum cruise speed required
MaxSpeed=9999
// minimum cruise speed required
MinSpeed=0
// this option sets several different parameters from a single option
// special: ga (props, twins, turbos, no military, no airliners)
//          jetairliners (jets, airliners, no military)
//          twins (twin props, twin turbo props, no military)
//          props (props and turbo props (no twins), no military, no airliners)
//          turbos (turbo props, twin turbo props; military and airliners are allowed)
Special=
// select only from a specific version of MSFS 0 = all, 1 = deluxe and above, 2 = premium and above
Version=
		 
[airport]
// filter airports by continent: AF, AN, AS, EU, NA, OC, SA
Continent=
// ISO country code, see here: https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
Country=
// ISO region code, https://en.wikipedia.org/wiki/ISO_3166-2 (has links for each country to available codes)
Region=
// minimum airport elevation, in feet
Elevation=0
// include by airport type, 1 = yes, 0 = no
SmallAirports=1
MediumAirports=1
LargeAirports=1
Heliports=0
// this flag will force the randomiser to expand range and/or direction if no valid airports can be found ( 1 = yes, 0 = no)
KeepTrying=0
// filter airports by latitude and location. angles only. from 0 to -180', 0 to +180'
LatitudeFrom=
LatitudeTo=
LongitudeFrom=
LongitudeTo=
// limit airports to those in daylight (beta!)
Day=0
// limit airports to those in darkness (beta!)
Night=0

[route]
// create routes, 1 = yes, 0 = no
AtoB=0
// maximum range between legs
Range=100
// number of legs to generate
Legs=1
// number of routes to generate
Number=1
// angle to travel (with 25' margin on each side of selected)
Direction=-1
// set a bearing instead of angle: N, NNE, NE, ENE, E, ESE, SE, SSE, S, SSW, SW, WSW, W, WNW, NW, NNW, (with same margin as above)
Bearing=
// ICAO code of the airport where you wish to start all journeys
StartAirport=
// ICAO code of the airport you wish to end your journeys
EndAirport=
// use selected aircraft range to decide maximum leg distance
UseAircraftRange=0
// set range based on selected aircraft travel time
Time=
// pick a random airport from "favourites.txt"
StartFromFavourite=
// use a modifier to determine maximum range, in percent of aircraft maximum
AircraftRangePercent=75
// by default, when there are two legs being generated the output
// will only show 5 of them. with larger ranges it's highly likely the number
// could be over 100 (hence why it doesn't show them all by default).
// to change this behaviour, specifty a maximum here
SimpleRouteCount=5

[export]
// export all routes to MSFS 2020 plan files, 1 = yes, 0 = no (which will saved to \Plans\icao_to_icao_yyyymmdd_hhmmss.pln)
MSFS=0
// export the routes to a text file (1 = yes, 0 = no), (saves to \Reports\icao_to_icao_yyyymmdd_hhmmss.txt)
Text=0