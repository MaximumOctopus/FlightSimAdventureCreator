//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2024
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#pragma once


#include <string>


namespace Location
{
	static const int ContinentCount = 7;

	static const std::wstring ContinentNames[ContinentCount] = { L"Africa", L"Antarctica", L"Asia", L"Europe", L"North America", L"Oceania", L"South America" };
	static const std::wstring ContinentShort[ContinentCount] = { L"AF", L"AN", L"AS", L"EU", L"NA", L"OC", L"SA" };

	static const int ISOCountriesCount = 249;
	static const int ISRegionsCount = 148;

#pragma region Longitudes
	static const double CityLatitude[] = {
		-12.438056,
		-59.616667,
		-16.5,
		49.261111,
		23.11666667,
		55.66666667,
		0,
		62,
		-53.1,
		64.15,
		35.68333333,
		7.1,
		35.776667,
		-33.925278,
		78.22,
		-42.880556,
		40.712778
	};

	static const double CityLongitude[] = {
		149.133333,
		16.366667,
		-77.35,
		-34.9,
		-75.7,
		-123.113889,
		96.833333,
		-159.766667,
		-81.383333,
		33.366667,
		12.583333,
		178.416667,
		2.333333,
		13.4,
		-21.95,
		12.483333,
		139.75,
		58.583333,
		21,
		-17.633333,
		159.95,
		32.866667,
		30.516667,
		-0.083333,
		-149.893611,
		-71.057778,
		-168.089167
	};
#pragma end_region


#pragma region Hand-Crafted

	static const int HandCraftedICAOCount = 134;

	static const std::wstring HandCraftedICAO[] = {
	L"LOWI", L"LOWK",                    				// austria
	L"YMBT", L"YLRE", L"YPBO", L"YSHL", L"YSSY",        // australia
	L"TFFJ",                                            // belgium
	L"VQPR",                                            // bhutan
	L"SBGL",                                            // brazil
	L"CYBD", L"CYTZ", L"CYCG", L"CYDA", L"CYDF",        // canada
	L"CYFB", L"CZST",
	L"MRSN",                                            // costa rica
	L"EKRN",                                            // denmark
	L"SEQM",                                            // ecuador
	L"HECA",                                            // egypa
	L"EFVA",                                            // finland
	L"LFPG", L"LFLJ", L"LFHM", L"LFMN",                 // france
	L"EDDF", L"EDVK", L"EDDP", L"EDHL",                 // germany
	L"EDJA", L"EDDS",
	L"LXGB",                                            // gibraltar
	L"EGPR", L"EGLL", L"EGHC", L"EGGP", L"EGCB",        // great britain
	L"EG78",
	L"MHTG",                                            // honduras
	L"VHHX",                                            // hong kong
	L"BIIS",                                            // iceland
	L"WX53",                                            // indonesia
	L"EIDL",                                            // ireland
	L"LIPB", L"LICJ", L"LILO", L"LIRJ",                 // italy
	L"RJTH", L"RJTT", L"ROKR", L"RJCK", L"RJFU",        // japan
	L"RORS", L"RJX8",
	L"EHAM", L"TNCS", L"EHRD",                          // netherlands
	L"VNLK",                                            // nepal
	L"NZQN",                                            // new zealand
	L"SPGL",                                            // peru
	L"LPMA", L"LPFR", L"LPPI",                          // portugal
	L"TNCM",                                            // saint martin
	L"FACT",                                            // south africa
	L"LECO", L"LEMD", L"LESU",                          // spain
	L"ENSB",                                            // svalbard
	L"ESSA",                                            // sweden
	L"LSZA", L"LSZO", L"LSZR", L"LSZH",                 // switzerland
	L"HUEN",                                            // uganda
	L"OMDB",                                            // uae
	L"KASE", L"KBID", L"KAVX", L"KDFW", L"KDEN",        // usa
	L"KFFA", L"KFHR", L"KATL", L"KJFK", L"KTVL",
	L"KLAX", L"KNKX", L"KCGX", L"KORD", L"KMCO",
	L"KCOF", L"KSFO", L"KSEA", L"KSEZ", L"KSWF",
	L"KTEX", L"PAVD",
	L"NZGS", L"NZMF", L"NZMJ", L"NZQE", L"NZRO",        // World Update XII
	L"NZTL", L"NZWR", L"NZWS", L"T004",
	L"SCIP", L"PHKO", L"AGGN", L"NTTB", L"NTTM",        // World Update XIII
	L"NCAI", L"PTPN", L"WARQ",                          // WARQ or WAHQ or WRSQ (this airport has 3 ICAO tags?!)      (115)
	L"LFPB",                                            // City Update II: France                                     (116)
	L"LKKV", L"LZTT", L"LHPP", L"LDRI", L"LQPD",        // World Update XIV                                           (121)
	L"EDDK",                                            // City Update IV: Western Europe                             (122)
	L"BIAR", L"ENRA", L"ESNQ", L"EFIV", L"ENLK",        // World Update XV                                            (127)
	L"MUCL", L"MDPP", L"MTCA", L"MKJS", L"TTCP",        // World Update XVI                                           (134)
	L"MYEH", L"TFFS",
	};
#pragma end_region

#pragma region Countries
	static const std::wstring ISOCountriesOrdered[ISOCountriesCount][2] =
	{ { L"Afghanistan", L"AF" },
{ L"Albania", L"AL" },
{ L"Algeria", L"DZ" },
{ L"American Samoa", L"AS" },
{ L"Andorra", L"AD" },
{ L"Angola", L"AO" },
{ L"Anguilla", L"AI" },
{ L"Antarctica", L"AQ" },
{ L"Antigua and Barbuda", L"AG" },
{ L"Argentina", L"AR" },
{ L"Armenia", L"AM" },
{ L"Aruba", L"AW" },
{ L"Australia", L"AU" },
{ L"Austria", L"AT" },
{ L"Azerbaijan", L"AZ" },
{ L"Bahamas (the)", L"BS" },
{ L"Bahrain", L"BH" },
{ L"Bangladesh", L"BD" },
{ L"Barbados", L"BB" },
{ L"Belarus", L"BY" },
{ L"Belgium", L"BE" },
{ L"Belize", L"BZ" },
{ L"Benin", L"BJ" },
{ L"Bermuda", L"BM" },
{ L"Bhutan", L"BT" },
{ L"Bolivia (Plurinational State of)", L"BO" },
{ L"Bonaire, Sint Eustatius and Saba", L"BQ" },
{ L"Bosnia and Herzegovina", L"BA" },
{ L"Botswana", L"BW" },
{ L"Bouvet Island", L"BV" },
{ L"Brazil", L"BR" },
{ L"British Indian Ocean Territory (the)", L"IO" },
{ L"Brunei Darussalam", L"BN" },
{ L"Bulgaria", L"BG" },
{ L"Burkina Faso", L"BF" },
{ L"Burundi", L"BI" },
{ L"Cabo Verde", L"CV" },
{ L"Cambodia", L"KH" },
{ L"Cameroon", L"CM" },
{ L"Canada", L"CA" },
{ L"Cayman Islands (the)", L"KY" },
{ L"Central African Republic (the)", L"CF" },
{ L"Chad", L"TD" },
{ L"Chile", L"CL" },
{ L"China", L"CN" },
{ L"Christmas Island", L"CX" },
{ L"Cocos (Keeling) Islands (the)", L"CC" },
{ L"Colombia", L"CO" },
{ L"Comoros (the)", L"KM" },
{ L"Congo (the Democratic Republic of the)", L"CD" },
{ L"Congo (the)", L"CG" },
{ L"Cook Islands (the)", L"CK" },
{ L"Costa Rica", L"CR" },
{ L"Croatia", L"HR" },
{ L"Cuba", L"CU" },
{ L"Curaçao", L"CW" },
{ L"Cyprus", L"CY" },
{ L"Czechia", L"CZ" },
{ L"Côte d'Ivoire", L"CI" },
{ L"Denmark", L"DK", },
{ L"Djibouti", L"DJ" },
{ L"Dominica", L"DM" },
{ L"Dominican Republic (the)", L"DO" },
{ L"Ecuador", L"EC" },
{ L"Egypt", L"EG" },
{ L"El Salvador", L"SV" },
{ L"Equatorial Guinea", L"GQ" },
{ L"Eritrea", L"ER" },
{ L"Estonia", L"EE" },
{ L"Eswatini", L"SZ" },
{ L"Ethiopia", L"ET" },
{ L"Falkland Islands (the)", L"FK" },
{ L"Faroe Islands (the)", L"FO" },
{ L"Fiji", L"FJ" },
{ L"Finland", L"FI" },
{ L"France", L"FR" },
{ L"French Guiana", L"GF" },
{ L"French Polynesia", L"PF" },
{ L"French Southern Territories (the)", L"TF" },
{ L"Gabon", L"GA" },
{ L"Gambia (the)", L"GM" },
{ L"Georgia", L"GE" },
{ L"Germany", L"DE" },
{ L"Ghana", L"GH" },
{ L"Gibraltar", L"GI" },
{ L"Greece", L"GR" },
{ L"Greenland", L"GL" },
{ L"Grenada", L"GD" },
{ L"Guadeloupe", L"GP" },
{ L"Guam", L"GU" },
{ L"Guatemala", L"GT" },
{ L"Guernsey", L"GG" },
{ L"Guinea", L"GN" },
{ L"Guinea-Bissau", L"GW" },
{ L"Guyana", L"GY" },
{ L"Haiti", L"HT" },
{ L"Heard Island and McDonald Islands", L"HM" },
{ L"Holy See (the)", L"VA" },
{ L"Honduras", L"HN" },
{ L"Hong Kong", L"HK" },
{ L"Hungary", L"HU" },
{ L"Iceland", L"IS" },
{ L"India", L"IN" },
{ L"Indonesia", L"ID" },
{ L"Iran (Islamic Republic of)", L"IR" },
{ L"Iraq", L"IQ" },
{ L"Ireland", L"IE" },
{ L"Isle of Man", L"IM" },
{ L"Israel", L"IL" },
{ L"Italy", L"IT" },
{ L"Jamaica", L"JM" },
{ L"Japan", L"JP" },
{ L"Jersey", L"JE" },
{ L"Jordan", L"JO" },
{ L"Kazakhstan", L"KZ" },
{ L"Kenya", L"KE" },
{ L"Kiribati", L"KI" },
{ L"Korea (the Democratic People's Republic of)", L"KP" },
{ L"Korea (the Republic of)", L"KR" },
{ L"Kuwait", L"KW" },
{ L"Kyrgyzstan", L"KG" },
{ L"Lao People's Democratic Republic (the)", L"LA" },
{ L"Latvia", L"LV" },
{ L"Lebanon", L"LB" },
{ L"Lesotho", L"LS" },
{ L"Liberia", L"LR" },
{ L"Libya", L"LY" },
{ L"Liechtenstein", L"LI" },
{ L"Lithuania", L"LT" },
{ L"Luxembourg", L"LU" },
{ L"Macao", L"MO" },
{ L"Madagascar", L"MG" },
{ L"Malawi", L"MW" },
{ L"Malaysia", L"MY" },
{ L"Maldives", L"MV" },
{ L"Mali", L"ML" },
{ L"Malta", L"MT" },
{ L"Marshall Islands (the)", L"MH" },
{ L"Martinique", L"MQ" },
{ L"Mauritania", L"MR" },
{ L"Mauritius", L"MU" },
{ L"Mayotte", L"YT" },
{ L"Mexico", L"MX" },
{ L"Micronesia (Federated States of)", L"FM" },
{ L"Moldova (the Republic of)", L"MD" },
{ L"Monaco", L"MC" },
{ L"Mongolia", L"MN" },
{ L"Montenegro", L"ME" },
{ L"Montserrat", L"MS" },
{ L"Morocco", L"MA" },
{ L"Mozambique", L"MZ" },
{ L"Myanmar", L"MM" },
{ L"Namibia", L"NA" },
{ L"Nauru", L"NR" },
{ L"Nepal", L"NP" },
{ L"Netherlands (the)", L"NL" },
{ L"New Caledonia", L"NC" },
{ L"New Zealand", L"NZ" },
{ L"Nicaragua", L"NI" },
{ L"Niger (the)", L"NE" },
{ L"Nigeria", L"NG" },
{ L"Niue", L"NU" },
{ L"Norfolk Island", L"NF" },
{ L"Northern Mariana Islands (the)", L"MP" },
{ L"Norway", L"NO" },
{ L"Oman", L"OM" },
{ L"Pakistan", L"PK" },
{ L"Palau", L"PW" },
{ L"Palestine, State of", L"PS" },
{ L"Panama", L"PA" },
{ L"Papua New Guinea", L"PG" },
{ L"Paraguay", L"PY" },
{ L"Peru", L"PE" },
{ L"Philippines (the)", L"PH" },
{ L"Pitcairn", L"PN" },
{ L"Poland", L"PL" },
{ L"Portugal", L"PT" },
{ L"Puerto Rico", L"PR" },
{ L"Qatar", L"QA" },
{ L"Republic of North Macedonia", L"MK" },
{ L"Romania", L"RO" },
{ L"Russian Federation (the)", L"RU" },
{ L"Rwanda", L"RW" },
{ L"Réunion", L"RE" },
{ L"Saint Barthélemy", L"BL" },
{ L"Saint Helena, Ascension and Tristan da Cunha", L"SH" },
{ L"Saint Kitts and Nevis", L"KN" },
{ L"Saint Lucia", L"LC" },
{ L"Saint Martin (French part)", L"MF" },
{ L"Saint Pierre and Miquelon", L"PM" },
{ L"Saint Vincent and the Grenadines", L"VC" },
{ L"Samoa", L"WS" },
{ L"San Marino", L"SM" },
{ L"Sao Tome and Principe", L"ST" },
{ L"Saudi Arabia", L"SA" },
{ L"Senegal", L"SN" },
{ L"Serbia", L"RS" },
{ L"Seychelles", L"SC" },
{ L"Sierra Leone", L"SL" },
{ L"Singapore", L"SG" },
{ L"Sint Maarten (Dutch part)", L"SX" },
{ L"Slovakia", L"SK" },
{ L"Slovenia", L"SI" },
{ L"Solomon Islands", L"SB" },
{ L"Somalia", L"SO" },
{ L"South Africa", L"ZA" },
{ L"South Georgia and the South Sandwich Islands", L"GS" },
{ L"South Sudan", L"SS" },
{ L"Spain", L"ES" },
{ L"Sri Lanka", L"LK" },
{ L"Sudan (the)", L"SD" },
{ L"Suriname", L"SR" },
{ L"Svalbard and Jan Mayen", L"SJ" },
{ L"Sweden", L"SE" },
{ L"Switzerland", L"CH" },
{ L"Syrian Arab Republic", L"SY" },
{ L"Taiwan (Province of China)", L"TW" },
{ L"Tajikistan", L"TJ" },
{ L"Tanzania, United Republic of", L"TZ" },
{ L"Thailand", L"TH" },
{ L"Timor-Leste", L"TL" },
{ L"Togo", L"TG" },
{ L"Tokelau", L"TK" },
{ L"Tonga", L"TO" },
{ L"Trinidad and Tobago", L"TT" },
{ L"Tunisia", L"TN" },
{ L"Turkey", L"TR" },
{ L"Turkmenistan", L"TM" },
{ L"Turks and Caicos Islands (the)", L"TC" },
{ L"Tuvalu", L"TV" },
{ L"Uganda", L"UG" },
{ L"Ukraine", L"UA" },
{ L"United Arab Emirates (the)", L"AE" },
{ L"United Kingdom of Great Britain and Northern Ireland (the)", L"GB" },
{ L"United States Minor Outlying Islands (the)", L"UM" },
{ L"United States of America (the)", L"US" },
{ L"Uruguay", L"UY" },
{ L"Uzbekistan", L"UZ" },
{ L"Vanuatu", L"VU" },
{ L"Venezuela (Bolivarian Republic of)", L"VE" },
{ L"Viet Nam", L"VN" },
{ L"Virgin Islands (British)", L"VG" },
{ L"Virgin Islands (U.S.)", L"VI" },
{ L"Wallis and Futuna", L"WF" },
{ L"Western Sahara", L"EH" },
{ L"Yemen", L"YE" },
{ L"Zambia", L"ZM" },
{ L"Zimbabwe", L"ZW" },
{ L"Åland Islands", L"AX" } };
#pragma end_region

#pragma region Regions
static const std::wstring ISORegions[ISRegionsCount] =
{
	L"GB-ENG", L"GB-NIR", L"GB-SCT", L"GB-WLS", // 0 - 3

	L"US-AL", L"US-AK", L"US-AZ", L"US-AR", L"US-CA", L"US-CO", L"US-CT", L"US-DE", L"US-FL", L"US-GA", // 4 - 54
	L"US-HI", L"US-ID", L"US-IL", L"US-IN", L"US-IA", L"US-KS", L"US-KY", L"US-LA", L"US-ME", L"US-MD",
	L"US-MA", L"US-MI", L"US-MN", L"US-MS", L"US-MO", L"US-MT", L"US-NE", L"US-NV", L"US-NH", L"US-NJ",
	L"US-NM", L"US-NY", L"US-NC", L"US-ND", L"US-OH", L"US-OK", L"US-OR", L"US-PA", L"US-RI", L"US-SC",
	L"US-SD", L"US-TN", L"US-TX", L"US-UT", L"US-VT", L"US-VA", L"US-WA", L"US-WV", L"US-WI", L"US-WY",
	L"US-DC",

	L"AU-NSW", L"AU-QLD", L"AU-SA", L"AU-TAS", L"AU-VIC", L"AU-WA", // 55 - 60

	L"CA-AB", L"CA-BC", L"CA-MB", L"CA-NB", L"CA-NL", L"CA-NS", L"CA-ON", L"CA-PE", L"CA-QC", L"CA-SK", L"CA-NT", L"CA-NU", L"CA-YT", // 61 - 73

	L"NZ-AUK", L"NZ-BOP", L"NZ-CAN", L"NZ-GIS", L"NZ-HKB", L"NZ-MBH", L"NZ-MWT", L"NZ-NSN", L"NZ-NTL", L"NZ-OTA",   // 74 - 89
	L"NZ-STL", L"NZ-TAS", L"NZ-TKI", L"NZ-WKO", L"NZ-WGN", L"NZ-WTC",

	L"FR-ARA", L"FR-BFC", L"FR-BRE", L"FR-CVL", L"FR-20R", L"FR-GES", L"FR-HDF", L"FR-IDF", L"FR-NOR", L"FR-NAQ",  // 90 - 102
	L"FR-OCC", L"FR-PDL", L"FR-PAC",

	L"ES-AN", L"ES-AR", L"ES-AS", L"ES-CN", L"ES-CB", L"ES-CL", L"ES-CM", L"ES-CT", L"ES-CE", L"ES-EX", // 103 - 121
	L"ES-GA", L"ES-IB", L"ES-RI", L"ES-MD", L"ES-ML", L"ES-MC", L"ES-NC", L"ES-PV", L"ES-VC",

	L"BR-AC", L"BR-AL", L"BR-AP", L"BR-AM", L"BR-BA", L"BR-CE", L"BR-ES", L"BR-GO", L"BR-MA", L"BR-MT", // 122 - 147
	L"BR-MS", L"BR-MG", L"BR-PA", L"BR-PB", L"BR-PR", L"BR-PE", L"BR-PI", L"BR-RJ", L"BR-RN", L"BR-RS",
	L"BR-RO", L"BR-RR", L"BR-SC", L"BR-SP", L"BR-SE", L"BR-TO",
};

#pragma end_region
}