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
#include <stdio.h>
#include <string>
#include <urlmon.h>
#include <windows.h>

#include "Constants.h"
#include "DateUtility.h"
#include "VersionCheck.h"

#pragma comment(lib, "urlmon.lib")


// download the file as UTF-8, copy it to the 8-bit buffer (lpResult), then
// smash it out to the versionInfo wide string using built-in conversion routines
// http://www.rohitab.com/discuss/topic/28719-downloading-a-file-winsock-http-c/page-2
bool VersionCheck::IsNewVersion()
{
    // avoid caching issues by adding time as a parameter
    std::wstring url = L"http://maximumoctopus.com/versions/fsac.php?" + DateUtility::DateTime(kDisplayModeFile);

    LPSTR lpResult = NULL; // download buffer
    LPSTREAM lpStream;

    std::wcout << L"\n  Getting FSAC version information...\n\n";

    if(SUCCEEDED(CoInitialize(NULL))) {

        if (SUCCEEDED(URLOpenBlockingStream(NULL, url.c_str(), &lpStream, 0, NULL))) {

            STATSTG statStream;
            if (SUCCEEDED(lpStream->Stat(&statStream, STATFLAG_NONAME))) 
            {
                DWORD dwSize = statStream.cbSize.LowPart + 1;
                lpResult = (LPSTR)malloc(dwSize);

                if (lpResult) 
                {
                    LARGE_INTEGER liPos;
                    ZeroMemory(&liPos, sizeof(liPos));
                    ZeroMemory(lpResult, dwSize);
                    lpStream->Seek(liPos, STREAM_SEEK_SET, NULL);
                    lpStream->Read(lpResult, (dwSize) - 1, NULL);

                    std::wstring versionInfo;

                    for (int t = 0; t < dwSize; t++)
                    {
                        versionInfo += lpResult[t]; // lol, this is horrible (i couldn't believe it when it worked)
                    }

                    free(lpResult);

                    if (versionInfo.find(SystemConstants::FSACVersion) == std::wstring::npos)
                    {
                        std::wcout << L"    New version available!\n\n";
                        std::wcout << L"      This version        : " << SystemConstants::FSACDate << L", " << SystemConstants::FSACVersion << "\n";
                        std::wcout << L"      Most recent version : " << versionInfo << "\n";
                    }
                    else
                    {
                        std::wcout << L"    Your version is up-to-date." << "\n" << "\n";
                        std::wcout << L"      This version        : " << SystemConstants::FSACDate << L", " << SystemConstants::FSACVersion << "\n";
                        std::wcout << L"      Most recent version : " << versionInfo << "\n";
                    }
                }
                
                lpStream->Release();
            }
            else
            {
                std::wcout << L"  ... error with download." << "\n";
            }
        }
        else
        {
            std::wcout << L"  ... error downloading version file." << "\n";
        }

        CoUninitialize();
    }

    std::wcout << "\n";

    return true;
}