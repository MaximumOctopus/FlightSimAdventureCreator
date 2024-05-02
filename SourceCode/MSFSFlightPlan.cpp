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

// https://docs.flightsimulator.com/html/Programming_Tools/SimConnect/SimConnect_XML_Definition.htm
// https://mariusbancila.ro/blog/2008/10/20/writing-utf-8-files-in-c/ 

#include <fstream>
#include <iostream>
#include <string>

#include "Constants.h"
#include "Formatting.h"
#include "MSFSFlightPlan.h"
#include "Utility.h"


namespace MSFSFlightPlan
{
	bool Export(std::vector<Airport>& airports, const std::wstring file_name)
	{
		std::ofstream ofile(file_name);

        if (ofile)
        {
            std::wcout << L"      Saving MSFS Flight Plan: \"" << file_name << L"\"\n";

            ofile << Formatting::to_utf8(L"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\n");
            //ofile << Formatting::to_utf8(L"<!-- generated with FlightSimAdventureCreator " + __FSACVersion + L" - " + __FSACDate + L" -->\n");
            //ofile << Formatting::to_utf8(L"<!-- https://github.com/MaximumOctopus/FlightSimAdventureCreator - Paul A Freshney -->\n\n");

            if (airports.size() == 2)
            {
                ofile << Formatting::to_utf8(L"<SimBase.Document Type=\"AceXML\" version=\"1,0\">\n");
                ofile << Formatting::to_utf8(L"    <Descr>AceXML Document</Descr>\n");
                ofile << Formatting::to_utf8(L"    <FlightPlan.FlightPlan>\n");
                ofile << Formatting::to_utf8(L"        <Title>" + airports[0].Ident + L" to " + airports.back().Ident + L"</Title>\n");
                ofile << Formatting::to_utf8(L"        <FPType>VFR</FPType>\n");
                ofile << Formatting::to_utf8(L"        <CruisingAlt>2100.000</CruisingAlt>\n");
                ofile << Formatting::to_utf8(L"        <DepartureID>" + airports[0].Ident + L"</DepartureID>\n");
                ofile << Formatting::to_utf8(L"        <DepartureLLA>" + Utility::DegreesToDMS(airports[0].LongitudeD, airports[0].LatitudeD) + L",+000000.00</DepartureLLA>\n");
                ofile << Formatting::to_utf8(L"        <DestinationID>" + airports.back().Ident + L"</DestinationID>\n");
                ofile << Formatting::to_utf8(L"        <DestinationLLA>" + Utility::DegreesToDMS(airports.back().LongitudeD, airports.back().LatitudeD) + L",+000000.00</DestinationLLA>\n");
                ofile << Formatting::to_utf8(L"        <Descr>" + airports[0].Ident + L" to " + airports.back().Ident + L"</Descr>\n");
                ofile << Formatting::to_utf8(L"        <DeparturePosition>" + airports[0].Runway.Name + L"</DeparturePosition>\n");
                ofile << Formatting::to_utf8(L"        <DepartureName>" + airports[0].Ident + L"</DepartureName>\n");
                ofile << Formatting::to_utf8(L"        <DestinationName>" + airports.back().Ident + L"</DestinationName>\n");
                ofile << Formatting::to_utf8(L"        <AppVersion>\n");
                ofile << Formatting::to_utf8(L"            <AppVersionMajor>11</AppVersionMajor>\n");
                ofile << Formatting::to_utf8(L"            <AppVersionBuild>282174</AppVersionBuild>\n");
                ofile << Formatting::to_utf8(L"        </AppVersion>\n");
                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"" + airports[0].Ident + L"\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>Airport</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition>" + Utility::DegreesToDMS(airports[0].LongitudeD, airports[0].LatitudeD) + L",+000000.00</WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"            <ICAO>\n");
                ofile << Formatting::to_utf8(L"                <ICAOIdent>" + airports[0].Ident + L"</ICAOIdent>\n");
                ofile << Formatting::to_utf8(L"            </ICAO>\n");
                ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");
                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"TIMECLIMB\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>User</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition></WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");
                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"TIMECRUIS\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>User</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition></WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"            </ATCWaypoint>\n");
                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"TIMEDSCNT\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>User</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition></WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");
                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"TIMEAPPROACH\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>User</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition></WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"            </ATCWaypoint>\n");
                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"" + airports.back().Ident + L"\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>Airport</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition>" + Utility::DegreesToDMS(airports.back().LongitudeD, airports.back().LatitudeD) + L",+000000.00</WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"            <ICAO>\n");
                ofile << Formatting::to_utf8(L"                <ICAOIdent>" + airports.back().Ident + L"</ICAOIdent>\n");
                ofile << Formatting::to_utf8(L"            </ICAO>\n");
                ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");
                ofile << Formatting::to_utf8(L"        </FlightPlan.FlightPlan>\n");
                ofile << Formatting::to_utf8(L"</SimBase.Document>\n");
            }
            else
            {
                ofile << Formatting::to_utf8(L"<SimBase.Document Type=\"AceXML\" version=\"1,0\">\n");
                ofile << Formatting::to_utf8(L"    <Descr>AceXML Document</Descr>\n");
                ofile << Formatting::to_utf8(L"    <FlightPlan.FlightPlan>\n");
                ofile << Formatting::to_utf8(L"        <Title>" + airports[0].Ident + L" to " + airports.back().Ident + L"</Title>\n");
                ofile << Formatting::to_utf8(L"        <FPType>VFR</FPType>\n");
                ofile << Formatting::to_utf8(L"        <CruisingAlt>2100.000</CruisingAlt>\n");
                ofile << Formatting::to_utf8(L"        <DepartureID>" + airports[0].Ident + L"</DepartureID>\n");
                ofile << Formatting::to_utf8(L"        <DepartureLLA>" + Utility::DegreesToDMS(airports[0].LongitudeD, airports[0].LatitudeD) + L",+000000.00</DepartureLLA>\n");
                ofile << Formatting::to_utf8(L"        <DestinationID>" + airports.back().Ident + L"</DestinationID>\n");
                ofile << Formatting::to_utf8(L"        <DestinationLLA>" + Utility::DegreesToDMS(airports.back().LongitudeD, airports.back().LatitudeD) + L",+000000.00</DestinationLLA>\n");
                ofile << Formatting::to_utf8(L"        <Descr>" + airports[0].Ident + L" to " + airports.back().Ident + L"</Descr>\n");
                ofile << Formatting::to_utf8(L"        <DeparturePosition>" + airports[0].Runway.Name + L"</DeparturePosition>\n");
                ofile << Formatting::to_utf8(L"        <DepartureName>" + airports[0].Ident + L"</DepartureName>\n");
                ofile << Formatting::to_utf8(L"        <DestinationName>" + airports.back().Ident + L"</DestinationName>\n");
                ofile << Formatting::to_utf8(L"        <AppVersion>\n");
                ofile << Formatting::to_utf8(L"            <AppVersionMajor>11</AppVersionMajor>\n");
                ofile << Formatting::to_utf8(L"            <AppVersionBuild>282174</AppVersionBuild>\n");
                ofile << Formatting::to_utf8(L"        </AppVersion>\n");

                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"" + airports[0].Ident + L"\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>Airport</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition>" + Utility::DegreesToDMS(airports[0].LongitudeD, airports[0].LatitudeD) + L",+000000.00</WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                //ofile << Formatting::to_utf8(L"            <RunwayNumberFP>" + airports[0].RunwayNumber() + L"</RunwayNumberFP>\n");              // this is in the spec, and some files generated in MSFS include it, but..
                //ofile << Formatting::to_utf8(L"            <RunwayDesignatorFP>" + airports[0].RunwayDesignator() + L"</RunwayDesignatorFP>\n");  // i find that it stops them being loaded in MSFS... weird, will investigate!
                ofile << Formatting::to_utf8(L"            <ICAO>\n");
                ofile << Formatting::to_utf8(L"                <ICAOIdent>" + airports[0].Ident + L"</ICAOIdent>\n");
                ofile << Formatting::to_utf8(L"            </ICAO>\n");
                ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");

                for (int t = 1; t < airports.size() - 1; t++)
                {
                    ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"" + airports[t].Ident + L"\">\n");
                    ofile << Formatting::to_utf8(L"            <ATCWaypointType>Airport</ATCWaypointType>\n");
                    ofile << Formatting::to_utf8(L"            <WorldPosition>" + Utility::DegreesToDMS(airports[t].LongitudeD, airports[t].LatitudeD) + L",+000000.00</WorldPosition>\n");
                    ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                    ofile << Formatting::to_utf8(L"            <ICAO>\n");
                    ofile << Formatting::to_utf8(L"                <ICAOIdent>" + airports[t].Ident + L"</ICAOIdent>\n");
                    ofile << Formatting::to_utf8(L"            </ICAO>\n");
                    ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");
                }

                ofile << Formatting::to_utf8(L"        <ATCWaypoint id=\"" + airports.back().Ident + L"\">\n");
                ofile << Formatting::to_utf8(L"            <ATCWaypointType>Airport</ATCWaypointType>\n");
                ofile << Formatting::to_utf8(L"            <WorldPosition>" + Utility::DegreesToDMS(airports.back().LongitudeD, airports.back().LatitudeD) + L",+000000.00</WorldPosition>\n");
                ofile << Formatting::to_utf8(L"            <SpeedMaxFP>-1</SpeedMaxFP>\n");
                ofile << Formatting::to_utf8(L"            <ICAO>\n");
                ofile << Formatting::to_utf8(L"                <ICAOIdent>" + airports.back().Ident + L"</ICAOIdent>\n");
                ofile << Formatting::to_utf8(L"            </ICAO>\n");
                ofile << Formatting::to_utf8(L"        </ATCWaypoint>\n");
                 
                ofile << Formatting::to_utf8(L"    </FlightPlan.FlightPlan>\n");
                ofile << Formatting::to_utf8(L"</SimBase.Document>\n");
            }

            ofile.close();

            return true;
        }
		else
		{
            // error
		}

        return false;
	}
}