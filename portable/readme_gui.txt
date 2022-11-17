====================================================================================================================================
====================================================================================================================================
  Flight Simulator Adventure Creator 0.2.4 GUI Version
  (c) Paul Alan Freshney 2022

    paul@freshney.org
	
  Download the latest version from FlightSim.to
    https://flightsim.to/file/41477/flight-simulator-adventure-creator

  Source code, betas, and latest data files
    https://github.com/MaximumOctopus/FlightSimAdventureCreator
  
  Uses airport and runway data from Our Airports (without which this application couldn't exist)
    https://ourairports.com/data/
	
  November 17th 2022
====================================================================================================================================
====================================================================================================================================

This is an early beta version, there may be bugs. If you find one, or if you have an idea for a new feature, then please let me know at the email address above.

A powerful tool for creating random VFR routes for Flight Simulators (currently works best with MSFS 2020, but more will come online in future).

Features:

 - Pick a random aircraft and starting location
 - Create a selection of A -> B routes where B is within a specified range of A
 - Create random multi-leg routes where each leg of the journey is within a specified range
 - Export either route to an MSFS 2020 plan file
 
 - The GUI version has route display, more config options
 - Airport search system
 
Alter the route randomiser using various parameters: location, range, direction, number of legs, airport type, aircraft range, and more.
 
The randomly selected aircraft is not mandatory (it isn't part of the exported plan), but serves as a idea or starting point for your flight. It can also be used to tweak the route parameters.

=====================================================================================================================================
=====================================================================================================================================

List of files that come in the zip file:

    \Plans\                    all export flight plans will be saved in here
    \Reports\                  all exported flight itinerary files will be saved in here
    custom_aircraft.txt        a list of third party aircraft you own. editing instructions can be found inside
    default_aircraft.txt       a list of every aircraft that comes with MSFS and its various versions
    favourites.txt             store a list of your favourite airports (the ICAO code) in here
    fcas.csv                   airport data, this is a special version of ourairports.com's airport.csv which is limited to MSFS airports
    FSAC.exe                   command-line version
    FSAC_GUI.exe               the GUI version
    jobs.txt                   contains everything the application needs to generate jobs for your next flight
    readme.txt                 the readme for the command-line version
    readme_gui.txt             this file
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

Then it's possible the MSFS plan files won't work correctly, as they need a departure runway.

If you have the time, then you would help everyone by going over to ourairports.com and adding a runway to this target airport (it's usually possible to find this information online without too much trouble). Their runway data file is updated daily.

====================================================================================================================================
====================================================================================================================================

To-do list (in no particular order):

Fixing the UTF8 import of airport names.

Adding more valid MSFS aiports (if you find one that's not in the fcas list, then please tell me!).

Adding points of interest (POIs) to routes. 
Adding NavAids (VOR, DME, etc.).

More route customisation options.

Optimising the performance of route generation.

Multi-language support.

Support for X-Plane 11/12. Their flight plan file format seems very simple, if anyone can test this for me please get in touch.
(Export option exists in code, needs testing)
 
Support for IFR flying.

(if you dive in to the code you'll see that some of these have been started, so they aren't that far away from being released)

====================================================================================================================================
====================================================================================================================================

Written in C++ 17 with C++ Builder 10.4 Community Edition. This application is open source, code link at the top of the page.

While most of the code between the command-line and GUI versions is identical, there are enough differences (due to the different C++
targets and functionality) that the sources should be considered separate. 

====================================================================================================================================
====================================================================================================================================

 Credits:

   All coding       : Paul A Freshney
   Development Cats : Rutherford, Freeman, and Maxwell
   Data             : Our Airports (ourairports.com)
   Icon             : https://icon-icons.com
   GUI Icons        : https://learn.microsoft.com/en-us/windows/apps/design/style/segoe-ui-symbol-font
   Thanks           : Brian Bernacki for his MSFS airport data                      
                      r/MicrosoftFlightSim/
					  
   Dedicated to Julie, Adam, and Dyanne.

All of my software is free and open source; please consider donating to a local cat charity or shelter. Thanks.

====================================================================================================================================

Release History

0.2.4 / November 17th 2022

Added: New aircraft from the 40th anniversary update
Added: Three new options to the Aircraft->Set menu: Airliners (props), Helis, Gliders
Added: Icon, to match console version
Added: Brazil to the Region popup menu

Fixed: Aircraft selection logic (for military/seaplane/airliners)
Fixed: A bug where the aircraft used for route generation is not the one selected :(

0.2.3 / October 30th 2022

Added: PDF manual (these take a lot of time to make, so please read it :)
Added: Popup menu to Start and End Airport edit boxes. Right mouse button to open a menu, and click Select to open an airport search
       window where you can find a Start and End airport.
Added: "Home airport", this can be used in the Start and End airport edit boxes
Added: A popup menu for easy access to regions for several popular/large countries
Added: distance between start and end airports (if set manually) 	  
Added: Validity checks on direction value
Added: Popup menu for selecting distance angle or bearing (removed the dropdown and Set button)

Fixed: Airport search is now case-insensitive

Fixed a few minor issues.

0.2.1 / October 18th 2022

First official release.

====================================================================================================================================
====================================================================================================================================