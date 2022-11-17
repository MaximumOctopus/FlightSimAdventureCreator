#  FlightSimulatorAdventureCreator 
CLI v0.5, GUI v0.2.4 beta.
  (c) Paul Alan Freshney 2022 / paul@freshney.org
```
Source code and latest data and exe files
https://github.com/MaximumOctopus/FlightSimAdventureCreator
  
Uses airport and runway data from Our Airports (without which this application couldn't exist)
https://ourairports.com/data/
```	
  November 17th 2022

------------------------------------------------------------------------------------------------------------------------------------

Started on September 25th 2022.

This is an early beta version, there may be bugs. If you find one, or if you have an idea for a new feature, then please let me know at the email address above.

A powerful tool for creating random VFR routes for Flight Simulators (currently works best with MSFS 2020, but more will come online in future).

There are two tools available now. 

A command-line tool, you'll need to use it from a Windows console. Navigate to the folder where it's installed (in Windows Explorer), click in the folder path area (so the entire folder path is highlighted, type "cmd", then press enter. You'll now have a new console windows set to the location of FCAS!

A Windows GUI version that has all of the same features as the command-line version, but in an easier to use format. It also contains an airport search system, and future updates will continue to take advantage of the extra functionality available to a GUI-based application.

Features:

 - Pick a random aircraft and starting location
 - Create a selection of A -> B routes where B is within a specified range of A
 - Create random multi-leg routes where each leg of the journey is within a specified range
 - Export either route to an MSFS 2020 plan file
 
Alter the route randomiser using various parameters: location, range, direction, number of legs, airport type, aircraft range, and more.
 
The randomly selected aircraft is not mandatory (it isn't part of the exported plan), but serves as a idea or starting point for your flight. It can also be used to tweak the route parameters.

If you'd like me to add aircraft details to create an MSFS Flight Plan (.flt), which locks the route to a specific aircraft, then please let me know.
 
Please read the readmes and enclosed PDF for details on how to use these tools.

------------------------------------------------------------------------------------------------------------------------------------

List of files that come in the zip file:

    \Plans\                    all export flight plans will be saved in here
    config_readme.txt          details on how to edit config files, and creating your own
    custom_aircraft.txt        a list of third party aircraft you own. editing instructions can be found inside
    default_aircraft.txt       a list of every aircraft that comes with MSFS and its various versions
    favourites.txt             store a list of your favourite airports (the ICAO code) in here
    fcas.csv                   airport data, this is a special version of ourairports.com's airport.csv which is limited to MSFS airports
    FSAC.exe                   the command-line application
    FSAC_gui.exe               the Windows GUI version
    FSAC.pdf                   Detailed manual for the command-line version (GUI manual coming soon)
    jobs.txt                   contains everything the application needs to generate jobs for your next flight
    readme.txt                 command-line help
    readme_gui.txt             GUI readme
    runways.csv                runway data (latest version can be found at ourairports.com/data)

------------------------------------------------------------------------------------------------------------------------------------

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

------------------------------------------------------------------------------------------------------------------------------------

To-do list (in no particular order):

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

(if you dive in to the code you'll see that some of these have been started, so they aren't that far away from being released)

------------------------------------------------------------------------------------------------------------------------------------

The command-line tool is wrritten in C++ 20 with Visual Studio 2022. 

The GUI version is written with C++ 17 in C++ Builder 10.4 Community Edition (free).

While most of the code between the command-line and GUI versions is identical, there are enough differences (due to the different C++
targets and functionality) that the sources should be considered separate. 

------------------------------------------------------------------------------------------------------------------------------------

 Credits
```
Paul A Freshney (all coding)
Rutherford, Freeman, and Maxwell (all-important Development Cats)
Our Airports (ourairports.com) (data)
https://icon-icons.com (icon)
```

Thanks to Brian Bernacki for his MSFS airport data and r/MicrosoftFlightSim/ for ideas.

Dedicated to Julie, Adam, and Dyanne.

All of my softare is free and open source; please consider donating to a local cat charity or shelter. Thanks.

------------------------------------------------------------------------------------------------------------------------------------

Release History

See version readmes for more information.
