====================================================================================================================================
====================================================================================================================================
  Flight Simulator Adventure Creator 0.2
  (c) Paul Alan Freshney 2022

    paul@freshney.org

  Source code and latest data and exe files
    https://github.com/MaximumOctopus/FlightSimAdventureCreator
  
  Uses airport and runway data from Our Airports (without which this application couldn't exist)
    https://ourairports.com/data/
	
  October 5th 2022
====================================================================================================================================
====================================================================================================================================

Started on September 25th 2022.

This is an early beta version, there may be bugs. If you find one, or if you have an idea for a new feature, then please let me know at the email address above.

A powerful tool for creating random VFR routes for Flight Simulators (currently works best with MSFS 2020, but more will come online in future).

This is a command-line tool, you'll need to use it from a Windows console. Navigate to the folder where it's installed (in Windows Explorer), click in the folder path area (so the entire folder path is highlighted, type "cmd", then press enter. You'll now have a new console windows set to the location of FCAS!

A GUI version is on my to-do list.

Features:

 - Pick a random aircraft and starting location
 - Create a selection of A -> B routes where B is within a specified range of A
 - Create random multi-leg routes where each leg of the journey is within a specified range
 - Export either route to an MSFS 2020 plan file
 
Alter the route randomiser using various parameters: location, range, direction, number of legs, airport type, aircraft range, and more.
 
The randomly selected aircraft is not mandatory (it isn't part of the exported plan), but serves as a idea or starting point for your flight. It can also be used to tweak the route parameters.

If you'd like me to add aircraft details to create an MSFS Flight Plan (.flt), which locks the route to a specific aircraft, then please let me know.
 
  
  fsac /?

This will give you a detailed list of every command-line option and information on how to use them.

Please note that options that take a numeric value (eg range) will only accept integer values (42, 69, 1138). Real numbers (100.4, 42.01, 3.141) will be ignored.

When thinking about options, generally speaking the application starts by including everything. All airports, all aircraft. The command line options you select will act to remove either airports or aircraft from the final selection. The more options you add the smaller the selection pool will be.

=====================================================================================================================================
=====================================================================================================================================

Examples:

Not all options are demonstrated here; for a complete list use the help parameter, "FSAC /?".

  fsac /prop
  
Will pick a random prop aircraft and random starting airport. Does not generate a route (/atob does that).

  fsac /atob /continent:NA
  
Generate simple routes (from one airport to another) in the continent of North America.

  fsac /atob /continent:AS /minspeed:300
  
Generate simple routes (from one airport to another) in the continent of Asia, with a plane that has a minimum cruise speed of 300 kts.

  fsac /atob /continent:EU /nomedium
  
A simple route, in Europe, with medium airports disabled (leaving only large and small).
 
As mentioned below, the data available is larger than the number of valid airports in MSFS 2020. There is no definitive list of MSFS airports, but Brian Bernacki (many thanks) has done a lot of work to get this going. The data file for FSAC has around 23000 airports which is sizeable percentage of those advertised to exist in the sim (around 35000).
  
Generate simple routes (from one airport to another) in the continent of North America.

  fsac /atob /leg:2
  
Generate a route of two legs. Starting location can be anywhere, maximum distance between legs is 100 nm (default).

  fsac /atob /leg:2 /range:80
  
Generate a route of two leg. Starting location can be anywhere, maximum distance between legs is 80 nm.

  fsac /atob /leg:2 /range:80 /ga
  
As above, but will now limit the random aircraft selection to either prop or twin prop, ignores military and airliners.

  fsac /atob /leg:3 /range:200 /jet /noairliner
  
A route of 3 leg, where each leg is no more than 200 nm. Only jets, no airliners. Military jets allowed.
 
  fsac /atob /leg:3 /range:200 /jet /noairliner /country:GB
  
As above, but limit airports to Great Britian.

A complete list of ISO country codes can be found here: https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2

  fsac /atob /useaircraftrange /leg:3

Creates a three-leg journey where each leg length is determined by the chosen aircraft's max range. A modifier is first applied to the aircraft's max range (the default is 75%) before dividing the range by the number of legs.

So if an aircraft is chosen with a max range of 1000 nm, this becomes 750 nm (75% of 1000), then this gets divided by three. So each leg can be a maximum length of 250 nm.

Use the option /allowexcessrange to disable this behaviour, just don't forget to refuel!

  fsac /atob /range:50 /twins
    
A 50 mile route from airport A to B, and I only want to fly twin props or twin turbo props. Airliners and military are allowed.

  fsac /atob /day
  
A->B route but only airports in daylight will be added to the random selection pool. /night does the opposite.

This is very much a beta feature. It'll likely work better for Northern Hemisphere locations (the airport, not you), but you might find yourself in an airport after dusk or before dawn. A better implementation will appear very soon!

  fsac /atob /startairport:EKCH /bearing:N /legs:2 /range:200
  
So we start a 2-leg journey from Copenhagen (EKCH) and will fly north into Sweden. 

  fsac /atob /turbos /favourite
  
As you can guess by now, this one plots an A->B route (a single leg), and specifies only turbo props or twin turbo props. It will pick the starting airport from one of the airports in the "favourites.txt" file. As with all FSAC files, this is editable, and I suggest you fill it full of your own favourite places. It comes pre-populated with a selection of interesting aiports from across the world.

  fsac /atob /props /range:20 /keeptrying
  
A nice short route in a slow-but-fun prop (probably). There are plenty of places in the world where 20 miles between airports isn't going to cause a problem. There are plenty of places where <5 will work! But this isn't true for many remote locations. So, rather than not getting a route at all, try using /keeptrying. If a search finds no airports, then it will search again but will multiply range by 1.25 and (if set) increase the direction angle by 5 degrees plus and minus. If it still can't find an airport it will try again, modifying range and direction by the same amounts. It will give-up after 21 tries...

  /saveconfig:filename
  
This will save your route/aircraft configuration, using all of the options you've selected, to a file.

  /loadconfig:filename
  
This will load a previously saved or created configuration. You won't have to use command-line options again!

  fsac /cat
 
This option must NEVER be used.

====================================================================================================================================
====================================================================================================================================

You can combine as many parameters as you like, but some combinations won't make much sense and may lead to unwanted behaviour.

eg. /continent:NA /country:GB 
North America and in Great Britain? That's not going to work.

eg. /twins /jet
The parameters are processed in order (left to right), so the /twins parameter will be overruled by /jet.

eg. /day /night
Lol, but no.

====================================================================================================================================
====================================================================================================================================

List of files that come in the zip file:

    \Plans\                    all export flight plans will be saved in here
    config_GB_props.txt        an example config file that will find you a route in the UK
    config_KMIA_North.txt      an example config file, fly from North from Miami International
    config_readme.txt          details on how to edit config files, and creating your own
    custom_aircraft.txt        a list of third party aircraft you own. editing instructions can be found inside
    default_aircraft.txt       a list of every aircraft that comes with MSFS and its various versions
    favourites.txt             store a list of your favourite airports (the ICAO code) in here
    fcas.csv                   airport data, this is a special version of ourairports.com's airport.csv which is limited to MSFS airports
    FSAC.exe                   the application itself!
    jobs.txt                   contains everything the application needs to generate jobs for your next flight
    readme.txt                 this file
    runways.csv                runway data (latest version can be found at ourairports.com/data)

====================================================================================================================================
====================================================================================================================================

Known issues:

Non-latin characters are mangled when the data file is loaded. It won't affect your enjoyment of this product. The joys of C++'s not-that-great-UTF8-handling. It's high on the to-do list.

While the ability to narrow down starting location (continent, country, region) is quite powerful, it may not offer the level of granularity that some might require. For instance, you can't currently set two countries (eg Spain and France, that might get you a nice flight across the Pyrenees or the Bay of Biscay). An EndAirport is coming in the next update. More control over available airport locations will come very soon. However, you could set the start airport to Bilbao (LEBB) and a direction of north east (NE) (/atob /startairport:LEBB /bearing:NE /range:150), and see what happens (hint, it'll probably get you what you want!).

The data available from ourairports.com is larger than the number of valid airports in MSFS 2020. There is no definitive list of MSFS airports, but Brian Bernacki (many thanks) has done a lot of work to get a substantial amount of those airports listed. The data file for FSAC has around 23000 airports, which is sizeable percentage of those advertised to exist in the sim (around 35000). This file is a combination of ourairports.com data and cross-referenced against data created by Brian.

I can't vouch for the accuracy of this data (whether the airports that are tagged as being valid in MSFS do indeed exist in MSFS), but from the testing I've done so far it does seem highly accurate. It likely means some airports that exist in MSFS are missing, but this is much better than my original plan, which would have only given us around 5000 airports (with some of those most definitely not appearing in MSFS).

This means that there is still a very small chance that it might generate a random route to a destination that doesn't exist in MSFS2020. This is not great, but there's nothing I can do about that right now. The lack of definitive MSFS airport list is always going to be an issue (unless I've missed it, in which case please send me an email!). However, I think thanks to Brian's work this is likely not the problem it could have been.

If you find an airport that exists in MSFS but doesn't appear in the fcas.csv airports file then please let me know!

Theoretically there's a 34% chance that any given airport in MSFS will be missing from the FCAS data. I suspect it's not quite that simple, with most of the missing airports clustered in specific regions. However, in half an hour or so my friend and I found ten airports not in the FSAC list (and they were all in central England, but mostly very small grass strips). 

Some airports do not have corresponding runway information. If you get an error like this:

 "Couldn't get a runway for airport "ICAO" (exported files may not work correctly)"

Then it's possible the MSFS plan files won't work correctly as they need a departure runway.

If you have the time, then you would help everyone by going over to ourairports.com and adding a runway to this target airport (it's usually possible to find this information online without too much trouble). Their runway data file is updated daily.

So the High Performance Group decided to release a hot air ballon just as I was finalising the code. This isn't currently supported as its own type, but I'll add an aircraft filter category for it in the next update.

====================================================================================================================================
====================================================================================================================================

To-do list (in no particular order):

Unit tests (this one is in the correct order!)

A proper manual.

Fixing the UTF8 import of airport names.

Adding more valid MSFS aiports (if you find one that's not in the fcas list, then please tell me!).

Route generation based on flight time (eg /time:60 to get an hour's flight)

Adding points of interest (POIs) to routes. 

Optimising performance of route generation.

Automatic creation of custom_aircraft.txt by reading from the community folder.

More route customisation options.

A human-readable text document of a generated route.

Multi-language support.

Support for X-Plane 11/12. Their flight plan file format seems very simple, if anyone can test this for me please get in touch.

Support for IFR flying.

Mac version.

GUI version. (should be available before end of 2022)

(if you dive in to the code you'll see that some of these have been started, so they aren't that far away from being released)

====================================================================================================================================
====================================================================================================================================

Written in C++ 20 with Visual Studio 2022. This application is open source, code link at the top of the page.

====================================================================================================================================
====================================================================================================================================

 Credits:

   All coding       : Paul A Freshney
   Development Cats : Rutherford, Freeman, and Maxwell
   Data             : Our Airports (ourairports.com)
   Icon             : https://icon-icons.com
   Thanks           : Brian Bernacki for his MSFS airport data                      
                      r/MicrosoftFlightSim/
					  
   Dedicated to Julie, Adam, and Dyanne.

All of my softare is free and open source; please consider donating to a local cat charity or shelter. Thanks.

====================================================================================================================================

Release History

0.2 / October 5th 2022

First official release.

====================================================================================================================================
====================================================================================================================================