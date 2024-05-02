object frmRouteBrowser: TfrmRouteBrowser
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Route Browser'
  ClientHeight = 516
  ClientWidth = 921
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  TextHeight = 13
  object Bevel3: TBevel
    Left = 8
    Top = 473
    Width = 900
    Height = 5
    Shape = bsTopLine
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 409
    Height = 451
    Caption = 'Route Filter'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object Bevel5: TBevel
      Left = 16
      Top = 26
      Width = 370
      Height = 70
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel1: TBevel
      Left = 16
      Top = 178
      Width = 370
      Height = 121
      Shape = bsFrame
      Style = bsRaised
    end
    object Label1: TLabel
      Left = 359
      Top = 219
      Width = 14
      Height = 13
      Caption = 'nm'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 359
      Top = 255
      Width = 14
      Height = 13
      Caption = 'nm'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 32
      Top = 65
      Width = 62
      Height = 13
      Caption = 'Airport ICAO'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 32
      Top = 190
      Width = 62
      Height = 13
      Caption = 'Route length'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Min: TLabel
      Left = 32
      Top = 221
      Width = 16
      Height = 13
      Caption = 'Min'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 32
      Top = 257
      Width = 20
      Height = 13
      Caption = 'Max'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Bevel2: TBevel
      Left = 16
      Top = 305
      Width = 370
      Height = 98
      Shape = bsFrame
      Style = bsRaised
    end
    object lDestinationCountry: TLabel
      Left = 32
      Top = 313
      Width = 94
      Height = 13
      Caption = 'Destination country'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Bevel4: TBevel
      Left = 16
      Top = 102
      Width = 370
      Height = 70
      Shape = bsFrame
      Style = bsRaised
    end
    object Label6: TLabel
      Left = 32
      Top = 108
      Width = 29
      Height = 13
      Caption = 'Airline'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lInvalid: TLabel
      Left = 163
      Top = 65
      Width = 67
      Height = 13
      Caption = 'Invalid airport'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object lStatus: TLabel
      Left = 293
      Top = 419
      Width = 12
      Height = 13
      Alignment = taRightJustify
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object eICAO: TEdit
      Left = 100
      Top = 62
      Width = 57
      Height = 21
      CharCase = ecUpperCase
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      PopupMenu = puSelectICAO
      TabOrder = 0
      OnExit = eICAOExit
      OnKeyDown = eICAOKeyDown
    end
    object rbFromICAO: TRadioButton
      Left = 104
      Top = 39
      Width = 41
      Height = 17
      Caption = 'From'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = True
      OnClick = rbFromICAOClick
    end
    object rbToICAO: TRadioButton
      Left = 151
      Top = 39
      Width = 41
      Height = 17
      Caption = 'To'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = rbToICAOClick
    end
    object tbMin: TTrackBar
      Left = 100
      Top = 216
      Width = 205
      Height = 30
      Max = 80
      TabOrder = 3
      OnChange = tbMinChange
    end
    object tbMax: TTrackBar
      Left = 100
      Top = 255
      Width = 205
      Height = 34
      Max = 80
      Position = 10
      TabOrder = 4
      OnChange = tbMaxChange
    end
    object eMin: TEdit
      Left = 311
      Top = 216
      Width = 42
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      NumbersOnly = True
      ParentFont = False
      TabOrder = 5
    end
    object eMax: TEdit
      Left = 311
      Top = 252
      Width = 42
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      NumbersOnly = True
      ParentFont = False
      TabOrder = 6
    end
    object bSearchFromICAO: TButton
      Left = 311
      Top = 414
      Width = 75
      Height = 25
      Caption = 'Search'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = bSearchFromICAOClick
    end
    object cbCountryList: TComboBox
      Left = 63
      Top = 370
      Width = 314
      Height = 21
      Style = csDropDownList
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
    end
    object cbAirlineList: TComboBox
      Left = 63
      Top = 135
      Width = 314
      Height = 21
      Style = csDropDownList
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
    end
    object cbAirlineFilter: TCheckBox
      Tag = 1
      Left = 30
      Top = 137
      Width = 18
      Height = 17
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = cbAirlineFilterClick
    end
    object cbCountryFilter: TCheckBox
      Left = 30
      Top = 372
      Width = 27
      Height = 17
      TabOrder = 11
      OnClick = cbCountryFilterClick
    end
    object cbRouteType: TComboBox
      Left = 63
      Top = 343
      Width = 133
      Height = 21
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 12
      Text = 'Any route'
      OnChange = cbRouteTypeChange
      Items.Strings = (
        'Any route'
        'Internal only'
        'External only')
    end
  end
  object sgRoutes: TStringGrid
    Left = 423
    Top = 8
    Width = 485
    Height = 451
    DefaultRowHeight = 22
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect, goFixedRowDefAlign]
    ScrollBars = ssVertical
    TabOrder = 0
    ColWidths = (
      185
      102
      53
      46
      73)
  end
  object Button1: TButton
    Left = 833
    Top = 484
    Width = 75
    Height = 25
    Caption = 'Close'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 2
  end
  object bExportSelected: TButton
    Left = 795
    Top = 484
    Width = 25
    Height = 25
    Hint = 'export selected route to MSFS plan file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ImageAlignment = iaCenter
    ImageIndex = 0
    Images = il16x16
    ParentFont = False
    TabOrder = 3
    OnClick = bExportSelectedClick
  end
  object bExportSelectedText: TButton
    Left = 764
    Top = 484
    Width = 25
    Height = 25
    Hint = 'export selected route to text file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ImageAlignment = iaCenter
    ImageIndex = 1
    Images = il16x16
    ParentFont = False
    TabOrder = 4
    OnClick = bExportSelectedTextClick
  end
  object puSelectICAO: TPopupMenu
    Tag = 57
    Left = 608
    object PopupMenu11: TMenuItem
      Caption = 'Select ICAO'
      Enabled = False
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object Select1: TMenuItem
      Caption = 'Search...'
      OnClick = Select1Click
    end
    object N5: TMenuItem
      Caption = '-'
    end
    object miUseHomeAirport: TMenuItem
      Caption = 'Use Home airport'
      OnClick = miUseHomeAirportClick
    end
    object SetasHomeairport1: TMenuItem
      Caption = 'Set as Home airport'
      OnClick = SetasHomeairport1Click
    end
    object N7: TMenuItem
      Caption = '-'
    end
    object N14: TMenuItem
      Caption = 'Hand-crafted airports'
      object Africa1: TMenuItem
        Caption = 'Africa'
        object PrincessJulianaInternationalAirport2: TMenuItem
          Caption = 'South Africa'
          object CapeTownInternationalAirport1: TMenuItem
            Tag = 65
            Caption = 'Cape Town International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Uganda1: TMenuItem
          Caption = 'Uganda'
          object EntebbeInternationalAirport1: TMenuItem
            Tag = 75
            Caption = 'Entebbe International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object MariscalSucreInternationalAirport2: TMenuItem
          Caption = 'Egypt'
          object CairoInternationalAirport1: TMenuItem
            Tag = 20
            Caption = 'Cairo International Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
      object Asia1: TMenuItem
        Caption = 'Asia'
        object Bhutan1: TMenuItem
          Caption = 'Bhutan'
          object ParoInternationalAirport1: TMenuItem
            Tag = 8
            Caption = 'Paro International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object GibraltarInternationalAirport2: TMenuItem
          Caption = 'Hong Kong'
          object KaiTakInternationalAirport1: TMenuItem
            Tag = 40
            Caption = 'Kai Tak International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Indonesia1: TMenuItem
          Caption = 'Indonesia'
          object AdisumarmoInternationalAirport1: TMenuItem
            Tag = 115
            Caption = 'Adisumarmo International Airport'
            OnClick = BarraAirport1Click
          end
          object BugalagaAirstrip1: TMenuItem
            Tag = 42
            Caption = 'Bugalaga Airstrip'
            OnClick = BarraAirport1Click
          end
        end
        object Japan1: TMenuItem
          Caption = 'Japan'
          object HachijojimaAirport1: TMenuItem
            Tag = 48
            Caption = 'Hachijojima Airport'
            OnClick = BarraAirport1Click
          end
          object HachijojimaAirport2: TMenuItem
            Tag = 49
            Caption = 'Haneda Airport'
            OnClick = BarraAirport1Click
          end
          object KeramaAirport1: TMenuItem
            Tag = 50
            Caption = 'Kerama Airport'
            OnClick = BarraAirport1Click
          end
          object KeramaAirport2: TMenuItem
            Tag = 51
            Caption = 'Kushiro Airport'
            OnClick = BarraAirport1Click
          end
          object NagasakiAirport1: TMenuItem
            Tag = 52
            Caption = 'Nagasaki Airport'
            OnClick = BarraAirport1Click
          end
          object NagasakiAirport2: TMenuItem
            Tag = 53
            Caption = 'Shimojishima Airport'
            OnClick = BarraAirport1Click
          end
          object SuwanosejimaAirport1: TMenuItem
            Tag = 54
            Caption = 'Suwanosejima Airport'
            OnClick = BarraAirport1Click
          end
        end
        object RotterdamTheHagueAirport2: TMenuItem
          Caption = 'Nepal'
          object enzingHillaryAirport1: TMenuItem
            Tag = 58
            Caption = 'Tenzing-Hillary Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
      object Australasia1: TMenuItem
        Caption = 'Australasia'
        object Australia2: TMenuItem
          Caption = 'Australia'
          object CambridgeBayAirport1: TMenuItem
            Tag = 2
            Caption = 'Cambridge Bay Airport'
            OnClick = BarraAirport1Click
          end
          object CambridgeBayAirport2: TMenuItem
            Tag = 3
            Caption = 'Longreach Airport'
            OnClick = BarraAirport1Click
          end
          object ParaburdooAirport1: TMenuItem
            Tag = 4
            Caption = 'Paraburdoo Airport'
            OnClick = BarraAirport1Click
          end
          object ShellharbourAirport1: TMenuItem
            Tag = 5
            Caption = 'Shellharbour Airport'
            OnClick = BarraAirport1Click
          end
          object SydneyKingsfordSmithAirport1: TMenuItem
            Tag = 6
            Caption = 'Sydney Kingsford Smith Airport'
            OnClick = BarraAirport1Click
          end
        end
        object enzingHillaryAirport2: TMenuItem
          Caption = 'New Zealand'
          object GorgeRiverAirstrip1: TMenuItem
            Tag = 102
            Caption = 'Gorge River Airstrip'
            OnClick = BarraAirport1Click
          end
          object GisborneAirport1: TMenuItem
            Tag = 99
            Caption = 'Gisborne Airport'
            OnClick = BarraAirport1Click
          end
          object LakeTekapoAirport1: TMenuItem
            Tag = 104
            Caption = 'Lake Tekapo Airport'
            OnClick = BarraAirport1Click
          end
          object MartinsBayAerodrome1: TMenuItem
            Tag = 101
            Caption = 'Martins Bay Aerodrome'
            OnClick = BarraAirport1Click
          end
          object MilfordSoundAirport1: TMenuItem
            Tag = 100
            Caption = 'Milford Sound Airport'
            OnClick = BarraAirport1Click
          end
          object RotoruaAirport1: TMenuItem
            Tag = 103
            Caption = 'Rotorua Airport'
            OnClick = BarraAirport1Click
          end
          object QueenstownAirport1: TMenuItem
            Tag = 59
            Caption = 'Queenstown Airport'
            OnClick = BarraAirport1Click
          end
          object QuintinLodgeAirstrip1: TMenuItem
            Tag = 107
            Caption = 'Quintin Lodge Airstrip'
            OnClick = BarraAirport1Click
          end
          object WestportAirport1: TMenuItem
            Tag = 106
            Caption = 'Westport Airport'
            OnClick = BarraAirport1Click
          end
          object WhangareiAirport1: TMenuItem
            Tag = 105
            Caption = 'Whangarei Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
      object Europe1: TMenuItem
        Caption = 'Europe'
        object UAE2: TMenuItem
          Caption = 'Austria'
          object InnsbruckAirport1: TMenuItem
            Caption = 'Innsbruck Airport'
            OnClick = BarraAirport1Click
          end
          object InnsbruckAirport2: TMenuItem
            Tag = 1
            Caption = 'Klagenfurt Airport'
            OnClick = BarraAirport1Click
          end
        end
        object SydneyKingsfordSmithAirport2: TMenuItem
          Caption = 'Belgium'
          object GustafIIIAirport1: TMenuItem
            Tag = 7
            Caption = 'Gustaf III Airport'
            OnClick = BarraAirport1Click
          end
        end
        object SirenaAerodrome2: TMenuItem
          Caption = 'Denmark'
          object BornholmAirport1: TMenuItem
            Tag = 18
            Caption = 'Bornholm Airport'
            OnClick = BarraAirport1Click
          end
        end
        object VaasaAirport2: TMenuItem
          Caption = 'France'
          object CharlesdeGaulleAirport1: TMenuItem
            Tag = 22
            Caption = 'Charles de Gaulle Airport'
            OnClick = BarraAirport1Click
          end
          object CharlesdeGaulleAirport2: TMenuItem
            Tag = 23
            Caption = 'Courchevel Altiport'
            OnClick = BarraAirport1Click
          end
          object MegveAltiport1: TMenuItem
            Tag = 24
            Caption = 'Meg'#232've Altiport'
            OnClick = BarraAirport1Click
          end
          object MegveAltiport2: TMenuItem
            Tag = 25
            Caption = 'Nice C'#244'te d'#39'Azur Airport'
            OnClick = BarraAirport1Click
          end
        end
        object CairoInternationalAirport2: TMenuItem
          Caption = 'Finland'
          object VaasaAirport1: TMenuItem
            Tag = 21
            Caption = 'Vaasa Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Germany1: TMenuItem
          Caption = 'Germany'
          object FrankfurtAirport1: TMenuItem
            Tag = 26
            Caption = 'Frankfurt Airport'
            OnClick = BarraAirport1Click
          end
          object FrankfurtAirport2: TMenuItem
            Tag = 27
            Caption = 'Kassel Airport'
            OnClick = BarraAirport1Click
          end
          object LeipzigHalleAirport1: TMenuItem
            Tag = 28
            Caption = 'Leipzig/Halle Airport'
            OnClick = BarraAirport1Click
          end
          object LeipzigHalleAirport2: TMenuItem
            Tag = 29
            Caption = 'L'#252'beck Airport'
            OnClick = BarraAirport1Click
          end
          object MemmingenAirport1: TMenuItem
            Tag = 30
            Caption = 'Memmingen Airport'
            OnClick = BarraAirport1Click
          end
          object MemmingenAirport2: TMenuItem
            Tag = 31
            Caption = 'Stuttgart Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Gibraltar1: TMenuItem
          Caption = 'Gibraltar'
          object GibraltarInternationalAirport1: TMenuItem
            Tag = 32
            Caption = 'Gibraltar International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object GreatBritain1: TMenuItem
          Caption = 'Great Britain'
          object BarraAirport1: TMenuItem
            Tag = 33
            Caption = 'Barra Airport'
            OnClick = BarraAirport1Click
          end
          object BarraAirport2: TMenuItem
            Tag = 34
            Caption = 'Heathrow Airport'
            OnClick = BarraAirport1Click
          end
          object LandsEndAirport1: TMenuItem
            Tag = 35
            Caption = 'Land'#39's End Airport'
            OnClick = BarraAirport1Click
          end
          object LandsEndAirport2: TMenuItem
            Tag = 36
            Caption = 'Liverpool John Lennon Airport'
            OnClick = BarraAirport1Click
          end
          object ManchesterCityAirportHeliport1: TMenuItem
            Tag = 37
            Caption = 'Manchester City Airport & Heliport'
            OnClick = BarraAirport1Click
          end
          object ManchesterCityAirportHeliport2: TMenuItem
            Tag = 38
            Caption = 'Out Skerries Airstrip'
            OnClick = BarraAirport1Click
          end
        end
        object DonegalAirport2: TMenuItem
          Caption = 'Iceland'
          object safjrurAirport1: TMenuItem
            Tag = 41
            Caption = #205'safj'#246'r'#240'ur Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Ireland1: TMenuItem
          Caption = 'Ireland'
          object DonegalAirport1: TMenuItem
            Tag = 43
            Caption = 'Donegal Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Italy1: TMenuItem
          Caption = 'Italy'
          object BolzanoAirport1: TMenuItem
            Tag = 44
            Caption = 'Bolzano Airport'
            OnClick = BarraAirport1Click
          end
          object BolzanoAirport2: TMenuItem
            Tag = 45
            Caption = 'Falcone Borsellino Airport'
            OnClick = BarraAirport1Click
          end
          object IloiloInternationalAirport1: TMenuItem
            Tag = 46
            Caption = 'Iloilo International Airport'
            OnClick = BarraAirport1Click
          end
          object IloiloInternationalAirport2: TMenuItem
            Tag = 47
            Caption = 'Marina di Campo Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Netherlads1: TMenuItem
          Caption = 'Netherlands'
          object AmsterdamAirportSchiphol1: TMenuItem
            Tag = 55
            Caption = 'Amsterdam Airport Schiphol'
            OnClick = BarraAirport1Click
          end
          object AmsterdamAirportSchiphol2: TMenuItem
            Tag = 56
            Caption = 'Juancho E. Yrauquin Airport'
            OnClick = BarraAirport1Click
          end
          object RotterdamTheHagueAirport1: TMenuItem
            Tag = 57
            Caption = 'Rotterdam The Hague Airport'
            OnClick = BarraAirport1Click
          end
        end
        object BugalagaAirstrip2: TMenuItem
          Caption = 'Portugal'
          object CristianoRonaldoMadeiraInternationalAirport1: TMenuItem
            Tag = 61
            Caption = 'Cristiano Ronaldo Madeira International Airport'
            OnClick = BarraAirport1Click
          end
          object CristianoRonaldoMadeiraInternationalAirport2: TMenuItem
            Tag = 62
            Caption = 'Faro Airport'
            OnClick = BarraAirport1Click
          end
          object PicoAirport1: TMenuItem
            Tag = 63
            Caption = 'Pico Airport'
            OnClick = BarraAirport1Click
          end
        end
        object CapeTownInternationalAirport2: TMenuItem
          Caption = 'Spain'
          object ACoruaAirport1: TMenuItem
            Tag = 66
            Caption = 'A Coru'#241'a Airport'
            OnClick = BarraAirport1Click
          end
          object ACoruaAirport2: TMenuItem
            Tag = 67
            Caption = 'Adolfo Su'#225'rez Madrid-Barajas Airport'
            OnClick = BarraAirport1Click
          end
          object AndorraLaSeudUrgellAirport1: TMenuItem
            Tag = 68
            Caption = 'Andorra-La Seu d'#39'Urgell Airport'
            OnClick = BarraAirport1Click
          end
        end
        object AndorraLaSeudUrgellAirport2: TMenuItem
          Caption = 'Svalbard'
          object SvalbardAirport1: TMenuItem
            Tag = 69
            Caption = 'Svalbard Airport'
            OnClick = BarraAirport1Click
          end
        end
        object SvalbardAirport2: TMenuItem
          Caption = 'Sweden'
          object StockholmArlandaAirport1: TMenuItem
            Tag = 70
            Caption = 'Stockholm Arlanda Airport'
            OnClick = BarraAirport1Click
          end
        end
        object StockholmArlandaAirport2: TMenuItem
          Caption = 'Switzerland'
          object LuganoAirport1: TMenuItem
            Tag = 71
            Caption = 'Lugano Airport'
            OnClick = BarraAirport1Click
          end
          object LuganoAirport2: TMenuItem
            Tag = 72
            Caption = 'Luzern-Beromunster Airport'
            OnClick = BarraAirport1Click
          end
          object StGallenAltenrheinAirport1: TMenuItem
            Tag = 73
            Caption = 'St. Gallen-Altenrhein Airport'
            OnClick = BarraAirport1Click
          end
          object ZurichAirport1: TMenuItem
            Tag = 74
            Caption = 'Zurich Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
      object MiddleEast1: TMenuItem
        Caption = 'Middle East'
        object UAE1: TMenuItem
          Caption = 'UAE'
          object DubaiInternationalAirport1: TMenuItem
            Tag = 76
            Caption = 'Dubai International Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
      object Pacific1: TMenuItem
        Caption = 'Pacific'
        object BoraBoraAirport1: TMenuItem
          Tag = 111
          Caption = 'Bora Bora Airport '
          OnClick = BarraAirport1Click
        end
        object CookIslandsAitutakiAirport1: TMenuItem
          Tag = 113
          Caption = 'Cook Islands (Aitutaki Airport)'
          OnClick = BarraAirport1Click
        end
        object EasterIsland1: TMenuItem
          Tag = 108
          Caption = 'Easter Island (Mataveri International Airport)'
          OnClick = BarraAirport1Click
        end
        object Hawaii3: TMenuItem
          Tag = 109
          Caption = 'Hawai'#699'i (Kona International Airport)'
          OnClick = BarraAirport1Click
        end
        object IslandofMoorea1: TMenuItem
          Tag = 112
          Caption = 'Island of Moorea'
          OnClick = BarraAirport1Click
        end
        object PohnpeiIsland1: TMenuItem
          Tag = 114
          Caption = 'Pohnpei Island (Pohnpei International Airport)'
          OnClick = BarraAirport1Click
        end
        object SolomanIslandsNusatupeAirport1: TMenuItem
          Tag = 110
          Caption = 'Soloman Islands (Nusatupe Airport)'
          OnClick = BarraAirport1Click
        end
      end
      object NorthAmerica1: TMenuItem
        Caption = 'North America'
        object Canada2: TMenuItem
          Caption = 'Canada'
          object BellaCoolaAirport1: TMenuItem
            Tag = 10
            Caption = 'Bella Coola Airport'
            OnClick = BarraAirport1Click
          end
          object BillyBishopTorontoCityAirport1: TMenuItem
            Tag = 11
            Caption = 'Billy Bishop Toronto City Airport'
            OnClick = BarraAirport1Click
          end
          object BillyBishopTorontoCityAirport2: TMenuItem
            Tag = 12
            Caption = 'Castlegar Airport'
            OnClick = BarraAirport1Click
          end
          object DawsonCityAirport1: TMenuItem
            Tag = 13
            Caption = 'Dawson City Airport'
            OnClick = BarraAirport1Click
          end
          object DawsonCityAirport2: TMenuItem
            Tag = 14
            Caption = 'Deer Lake Airport'
            OnClick = BarraAirport1Click
          end
          object IqaluitInternationalAirport1: TMenuItem
            Tag = 15
            Caption = 'Iqaluit International Airport'
            OnClick = BarraAirport1Click
          end
          object StewartAerodrome1: TMenuItem
            Tag = 16
            Caption = 'Stewart Aerodrome'
            OnClick = BarraAirport1Click
          end
        end
        object USA1: TMenuItem
          Caption = 'USA'
          object AspenPitkinCountyAirport1: TMenuItem
            Tag = 77
            Caption = 'Aspen-Pitkin County Airport'
            OnClick = BarraAirport1Click
          end
          object AspenPitkinCountyAirport2: TMenuItem
            Tag = 78
            Caption = 'Block Island Airport'
            OnClick = BarraAirport1Click
          end
          object CatalinaAirport1: TMenuItem
            Tag = 79
            Caption = 'Catalina Airport'
            OnClick = BarraAirport1Click
          end
          object CatalinaAirport2: TMenuItem
            Tag = 80
            Caption = 'Dallas-Fort Worth International Airport'
            OnClick = BarraAirport1Click
          end
          object DenverInternationalAirport1: TMenuItem
            Tag = 81
            Caption = 'Denver International Airport'
            OnClick = BarraAirport1Click
          end
          object FirstFlightAirportKittyHawk1: TMenuItem
            Tag = 82
            Caption = 'First Flight Airport "Kitty Hawk"'
            OnClick = BarraAirport1Click
          end
          object FirstFlightAirportKittyHawk2: TMenuItem
            Tag = 83
            Caption = 'Friday Harbor Airport'
            OnClick = BarraAirport1Click
          end
          object HartsfieldJacksonAtlantaInternationalAirport1: TMenuItem
            Tag = 84
            Caption = 'Hartsfield-Jackson Atlanta International Airport'
            OnClick = BarraAirport1Click
          end
          object HartsfieldJacksonAtlantaInternationalAirport2: TMenuItem
            Tag = 85
            Caption = 'John F. Kennedy International Airport'
            OnClick = BarraAirport1Click
          end
          object LakeTahoeAirport1: TMenuItem
            Tag = 86
            Caption = 'Lake Tahoe Airport'
            OnClick = BarraAirport1Click
          end
          object LakeTahoeAirport2: TMenuItem
            Tag = 87
            Caption = 'Los Angeles International Airport'
            OnClick = BarraAirport1Click
          end
          object MarineCorpsAirStationMiramar1: TMenuItem
            Tag = 88
            Caption = 'Marine Corps Air Station Miramar'
            OnClick = BarraAirport1Click
          end
          object MarineCorpsAirStationMiramar2: TMenuItem
            Tag = 89
            Caption = 'Meigs Field'
            OnClick = BarraAirport1Click
          end
          object OHareInternationalAirport1: TMenuItem
            Tag = 90
            Caption = 'O'#39'Hare International Airport'
            OnClick = BarraAirport1Click
          end
          object OHareInternationalAirport2: TMenuItem
            Tag = 91
            Caption = 'Orlando International Airport'
            OnClick = BarraAirport1Click
          end
          object PatrickSpaceForceBase1: TMenuItem
            Tag = 92
            Caption = 'Patrick Space Force Base'
            OnClick = BarraAirport1Click
          end
          object PatrickSpaceForceBase2: TMenuItem
            Tag = 93
            Caption = 'San Francisco International Airport'
            OnClick = BarraAirport1Click
          end
          object SeattleTacomaInternationalAirport1: TMenuItem
            Tag = 94
            Caption = 'Seattle-Tacoma International Airport'
            OnClick = BarraAirport1Click
          end
          object SeattleTacomaInternationalAirport2: TMenuItem
            Tag = 95
            Caption = 'Sedona Airport'
            OnClick = BarraAirport1Click
          end
          object StewartInternationalAirport1: TMenuItem
            Tag = 96
            Caption = 'Stewart International Airport'
            OnClick = BarraAirport1Click
          end
          object StewartInternationalAirport2: TMenuItem
            Tag = 97
            Caption = 'Telluride Regional Airport'
            OnClick = BarraAirport1Click
          end
          object ValdezAirport1: TMenuItem
            Tag = 98
            Caption = 'Valdez Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
      object SouthAmerica1: TMenuItem
        Caption = 'South America'
        object GustafIIIAirport2: TMenuItem
          Caption = 'Brazil'
          object RiodeJaneiroGaleoInternationalAirport1: TMenuItem
            Tag = 9
            Caption = 'Rio de Janeiro/Gale'#227'o International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object CostaRica1: TMenuItem
          Caption = 'Costa Rica'
          object SirenaAerodrome1: TMenuItem
            Tag = 17
            Caption = 'Sirena Aerodrome'
            OnClick = BarraAirport1Click
          end
        end
        object BornholmAirport2: TMenuItem
          Caption = 'Ecuador'
          object MariscalSucreInternationalAirport1: TMenuItem
            Tag = 19
            Caption = 'Mariscal Sucre International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object Honduras1: TMenuItem
          Caption = 'Honduras'
          object oncontinInternationalAirport1: TMenuItem
            Tag = 39
            Caption = 'Toncontin International Airport'
            OnClick = BarraAirport1Click
          end
        end
        object QueenstownAirport2: TMenuItem
          Caption = 'Peru'
          object hagualAirport1: TMenuItem
            Tag = 60
            Caption = 'Chagual Airport'
            OnClick = BarraAirport1Click
          end
        end
        object PicoAirport2: TMenuItem
          Caption = 'Saint Martin'
          object PrincessJulianaInternationalAirport1: TMenuItem
            Tag = 64
            Caption = 'Princess Juliana International Airport'
            OnClick = BarraAirport1Click
          end
        end
      end
    end
  end
  object il16x16: TImageList
    Left = 17
    Top = 468
    Bitmap = {
      494C010102000800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF009E9E9E001818180000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000006D6D6D00ABABAB00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009E9E9E0000000000000000000000
      0000000000000000000000000000FFFFFF009D9D9D0018181800000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF009E9E
      9E00000000000000000000000000FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009E9E9E0018181800FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F1F1F10000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F1F1F10000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00F1F1
      F100000000000000000000000000FFFFFF00FFFFFF0000000000000000000000
      00000000000000000000F0F0F000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F1F1F10000000000000000000000
      0000000000000000000000000000FFFFFF00F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000ABABAB006D6D6D00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000000000000000000000000000FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00F0F0F0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFF800300000000FFFF800300000000
      F8FF800300000000F87F800300000000F87F8003000000000C3F800300000000
      8003800300000000800180030000000080018003000000008001800300000000
      0C3F800300000000F87F800300000000F87F800700000000F8FF800F00000000
      FFFF801F00000000FFFF803F0000000000000000000000000000000000000000
      000000000000}
  end
  object sdMain: TSaveDialog
    Filter = 'FSAC configuration files|*.config'
    Left = 65
    Top = 464
  end
end
