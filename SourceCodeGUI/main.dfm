object frmMain: TfrmMain
  Left = 0
  Top = 0
  Cursor = crArrow
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'frmMain'
  ClientHeight = 770
  ClientWidth = 1215
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object gbAircraft: TGroupBox
    Left = 8
    Top = 47
    Width = 375
    Height = 329
    Caption = 'Aircraft'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    object Bevel12: TBevel
      Left = 11
      Top = 144
      Width = 350
      Height = 73
      Shape = bsFrame
      Style = bsRaised
    end
    object lMinSpeed: TLabel
      Left = 27
      Top = 162
      Width = 53
      Height = 13
      Caption = 'Min. Speed'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 27
      Top = 189
      Width = 57
      Height = 13
      Caption = 'Max. Speed'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 132
      Top = 162
      Width = 14
      Height = 13
      Caption = 'kts'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 132
      Top = 189
      Width = 14
      Height = 13
      Caption = 'kts'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Bevel8: TBevel
      Left = 11
      Top = 22
      Width = 350
      Height = 116
      Shape = bsFrame
      Style = bsRaised
    end
    object lAircraftStats: TLabel
      Left = 27
      Top = 261
      Width = 12
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label26: TLabel
      Left = 185
      Top = 162
      Width = 103
      Height = 13
      Hint = 'aircraft excess range'
      Caption = 'Aircraft excess range'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label25: TLabel
      Left = 336
      Top = 162
      Width = 11
      Height = 13
      Caption = '%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Bevel14: TBevel
      Left = 238
      Top = 33
      Width = 12
      Height = 98
      Shape = bsLeftLine
    end
    object lExcessRange: TLabel
      Left = 294
      Top = 186
      Width = 12
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object eMinSpeed: TEdit
      Left = 90
      Top = 159
      Width = 36
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      NumbersOnly = True
      ParentFont = False
      TabOrder = 13
      Text = '1'
      OnChange = cbAircraftTypePropsClick
      OnExit = eLegsExit
    end
    object cbAircraftTypeProps: TCheckBox
      Left = 29
      Top = 33
      Width = 97
      Height = 17
      Caption = 'Props'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 0
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeTwinProps: TCheckBox
      Left = 29
      Top = 56
      Width = 97
      Height = 19
      Caption = 'Twin props'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 1
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeTurboProps: TCheckBox
      Left = 29
      Top = 79
      Width = 97
      Height = 17
      Caption = 'Turbo props'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 2
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeHelicopter: TCheckBox
      Left = 148
      Top = 56
      Width = 80
      Height = 17
      Caption = 'Helicopter'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 3
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeGlider: TCheckBox
      Left = 148
      Top = 102
      Width = 80
      Height = 17
      Caption = 'Glider'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 4
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeAirliners: TCheckBox
      Left = 262
      Top = 33
      Width = 68
      Height = 17
      Caption = 'Airliners'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 5
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeMilitary: TCheckBox
      Left = 262
      Top = 56
      Width = 68
      Height = 17
      Caption = 'Military'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 6
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeTwinTurboProps: TCheckBox
      Left = 29
      Top = 102
      Width = 97
      Height = 17
      Caption = 'Twin turbo props'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 7
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeJet: TCheckBox
      Left = 148
      Top = 33
      Width = 80
      Height = 17
      Caption = 'Jet'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 8
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftTypeBalloon: TCheckBox
      Left = 148
      Top = 79
      Width = 80
      Height = 17
      Caption = 'Balloon'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 9
      OnClick = cbAircraftTypePropsClick
    end
    object cbAircraftList: TComboBox
      Left = 11
      Top = 234
      Width = 350
      Height = 21
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnChange = cbAircraftListChange
    end
    object bUpdateAircraft: TButton
      Left = 286
      Top = 295
      Width = 75
      Height = 25
      Caption = 'Refresh'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 6
      Images = il16x16
      ParentFont = False
      TabOrder = 11
      OnClick = bUpdateAircraftClick
    end
    object cbAircraftTypeSeaplanes: TCheckBox
      Left = 262
      Top = 79
      Width = 80
      Height = 17
      Caption = 'Seaplanes'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 12
      OnClick = cbAircraftTypePropsClick
    end
    object eMaxSpeed: TEdit
      Left = 90
      Top = 186
      Width = 36
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      NumbersOnly = True
      ParentFont = False
      TabOrder = 14
      Text = '9999'
      OnChange = cbAircraftTypePropsClick
      OnExit = eLegsExit
    end
    object cbMSFSVersion: TComboBox
      Left = 262
      Top = 102
      Width = 88
      Height = 21
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 15
      Text = 'All'
      OnChange = cbAircraftTypePropsClick
      Items.Strings = (
        'All'
        'Deluxe'
        'Premium')
    end
    object eAircraftRangeModifier: TEdit
      Left = 294
      Top = 159
      Width = 36
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      PopupMenu = puPercentage
      TabOrder = 16
      Text = '0'
      OnChange = cbAircraftTypePropsClick
      OnExit = eAircraftRangeModifierExit
    end
    object bRandomAircraft: TButton
      Left = 257
      Top = 295
      Width = 23
      Height = 25
      Hint = 'pick a random aircraft'
      ImageIndex = 4
      Images = il16x16
      TabOrder = 17
      OnClick = bRandomAircraftClick
    end
    object bLockAircraft: TButton
      Left = 17
      Top = 295
      Width = 23
      Height = 25
      Hint = 'lock the selected aircraft'
      ImageAlignment = iaCenter
      ImageIndex = 2
      Images = il16x16
      TabOrder = 18
      OnClick = bLockAircraftClick
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1215
    Height = 41
    ButtonHeight = 38
    ButtonWidth = 39
    Caption = 'ToolBar1'
    Images = ImageList1
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    object tbNew: TToolButton
      Left = 0
      Top = 0
      Hint = 'Reset all parameters'
      ImageIndex = 2
      OnClick = tbNewClick
    end
    object ToolButton4: TToolButton
      Left = 39
      Top = 0
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object tbSave: TToolButton
      Left = 47
      Top = 0
      Hint = 'Save current configuration'
      Caption = 'tbSave'
      ImageIndex = 0
      OnClick = tbSaveClick
    end
    object tbOpen: TToolButton
      Left = 86
      Top = 0
      Hint = 'Load configuration'
      Caption = 'tbOpen'
      ImageIndex = 1
      OnClick = tbOpenClick
    end
    object ToolButton3: TToolButton
      Left = 125
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object tbExport: TToolButton
      Left = 133
      Top = 0
      Hint = 'Export all routes to MSFS plans (.pln)'
      ImageIndex = 3
      OnClick = tbExportClick
    end
    object tbExportItinerary: TToolButton
      Left = 172
      Top = 0
      Hint = 'Export all routes to text files'
      ImageIndex = 4
      OnClick = tbExportItineraryClick
    end
    object ToolButton2: TToolButton
      Left = 211
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object tbCodeTest: TToolButton
      Left = 219
      Top = 0
      Caption = 'tbCodeTest'
      Visible = False
      OnClick = tbCodeTestClick
    end
  end
  object sbMain: TStatusBar
    Left = 0
    Top = 751
    Width = 1215
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object mMain: TMemo
    Left = 797
    Top = 422
    Width = 412
    Height = 215
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      'Click the button marked "Go!" below'
      '(or press F9) to generate some random'
      'routes.'
      ''
      'Once you have some routes, selecting a '
      'route in the table above will show details '
      'of the route in this box...')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object gbGo: TGroupBox
    Left = 797
    Top = 643
    Width = 292
    Height = 102
    Caption = 'Random Route Generation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object Label23: TLabel
      Left = 44
      Top = 84
      Width = 17
      Height = 13
      Caption = 'Go!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object bGenerate: TButton
      Left = 14
      Top = 24
      Width = 75
      Height = 56
      Hint = 'generate random routes! (F9)'
      ImageAlignment = iaCenter
      ImageIndex = 5
      Images = ImageList1
      TabOrder = 0
      OnClick = bGenerateClick
    end
    object cbKeepTrying: TCheckBox
      Left = 103
      Top = 33
      Width = 75
      Height = 17
      Hint = 'increases the likelihood of finding routes'
      Caption = 'Keep trying'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
  end
  object GroupBox4: TGroupBox
    Left = 1095
    Top = 643
    Width = 114
    Height = 102
    Caption = 'Stats'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    object Label21: TLabel
      Left = 15
      Top = 19
      Width = 36
      Height = 13
      Cursor = crHandPoint
      Caption = 'Aircraft'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = lStatsAircraftClick
    end
    object Label22: TLabel
      Left = 15
      Top = 38
      Width = 38
      Height = 13
      Cursor = crHandPoint
      Caption = 'Airports'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = lStatsAirportClick
    end
    object lStatsAircraft: TLabel
      Left = 59
      Top = 19
      Width = 36
      Height = 13
      Cursor = crHandPoint
      Alignment = taRightJustify
      AutoSize = False
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = lStatsAircraftClick
    end
    object lStatsAirport: TLabel
      Left = 59
      Top = 38
      Width = 36
      Height = 13
      Cursor = crHandPoint
      Alignment = taRightJustify
      AutoSize = False
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = lStatsAirportClick
    end
    object lStatsRunways: TLabel
      Left = 59
      Top = 57
      Width = 36
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label30: TLabel
      Left = 15
      Top = 57
      Width = 44
      Height = 13
      Caption = 'Runways'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label36: TLabel
      Left = 15
      Top = 76
      Width = 34
      Height = 13
      Cursor = crHandPoint
      Caption = 'Routes'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = lStatsRoutesClick
    end
    object lStatsRoutes: TLabel
      Left = 59
      Top = 76
      Width = 36
      Height = 13
      Cursor = crHandPoint
      Alignment = taRightJustify
      AutoSize = False
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = lStatsRoutesClick
    end
  end
  object gbAirports: TGroupBox
    Left = 389
    Top = 47
    Width = 402
    Height = 329
    Caption = 'Airports'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    object Bevel13: TBevel
      Left = 11
      Top = 250
      Width = 378
      Height = 70
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel5: TBevel
      Left = 11
      Top = 186
      Width = 378
      Height = 58
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel6: TBevel
      Left = 11
      Top = 137
      Width = 378
      Height = 43
      Shape = bsFrame
      Style = bsRaised
    end
    object Label24: TLabel
      Left = 248
      Top = 152
      Width = 30
      Height = 13
      Caption = '(beta)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 31
      Top = 264
      Width = 67
      Height = 13
      Caption = 'Min. Elevation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label20: TLabel
      Left = 151
      Top = 264
      Width = 12
      Height = 13
      Caption = 'ft.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lMinElevationRange: TLabel
      Left = 188
      Top = 264
      Width = 12
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label33: TLabel
      Left = 31
      Top = 291
      Width = 71
      Height = 13
      Caption = 'Max. Elevation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label34: TLabel
      Left = 151
      Top = 291
      Width = 12
      Height = 13
      Caption = 'ft.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lMaxElevationRange: TLabel
      Left = 188
      Top = 289
      Width = 12
      Height = 13
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGray
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object bUpdateAirports: TButton
      Left = 304
      Top = 342
      Width = 75
      Height = 25
      Caption = 'Refresh'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = bUpdateAirportsClick
    end
    object cbLargeAirports: TCheckBox
      Left = 47
      Top = 196
      Width = 90
      Height = 17
      Caption = 'Large Airports'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 1
      OnClick = cbContinentAFClick
    end
    object cbMediumAirports: TCheckBox
      Left = 143
      Top = 196
      Width = 90
      Height = 17
      Caption = 'Medium Airports'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 2
      OnClick = cbContinentAFClick
    end
    object cbSmallAirports: TCheckBox
      Left = 255
      Top = 196
      Width = 90
      Height = 17
      Caption = 'Small Airports'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 3
      OnClick = cbContinentAFClick
    end
    object cbHeliports: TCheckBox
      Left = 47
      Top = 219
      Width = 90
      Height = 17
      Caption = 'Heliports'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 4
      OnClick = cbContinentAFClick
    end
    object cbSeaplaneBases: TCheckBox
      Left = 143
      Top = 219
      Width = 90
      Height = 17
      Caption = 'Seaplane bases'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 5
      OnClick = cbContinentAFClick
    end
    object cbTimeOfDay: TCheckBox
      Tag = 1
      Left = 29
      Top = 151
      Width = 74
      Height = 17
      Caption = 'Time of Day'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = cbTimeOfDayClick
    end
    object rbDay: TRadioButton
      Left = 128
      Top = 151
      Width = 41
      Height = 17
      Caption = 'Day'
      Checked = True
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      TabStop = True
      OnClick = cbContinentAFClick
    end
    object rbNight: TRadioButton
      Left = 175
      Top = 151
      Width = 41
      Height = 17
      Caption = 'Night'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = cbContinentAFClick
    end
    object eMinElevation: TEdit
      Left = 104
      Top = 261
      Width = 41
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      NumbersOnly = True
      ParentFont = False
      TabOrder = 9
      Text = '-2000'
      OnChange = cbContinentAFClick
      OnExit = eMinElevationExit
    end
    object eMagicCode: TEdit
      Left = 24
      Top = 344
      Width = 290
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      Visible = False
    end
    object eMaxElevation: TEdit
      Left = 104
      Top = 288
      Width = 41
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      NumbersOnly = True
      ParentFont = False
      TabOrder = 11
      Text = '15000'
      OnChange = cbContinentAFClick
      OnExit = eMaxElevationExit
    end
    object cbAirportTypeAutomatic: TCheckBox
      Left = 255
      Top = 219
      Width = 90
      Height = 17
      Caption = 'Automatic!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 12
      OnClick = cbAirportTypeAutomaticClick
    end
    object pcGeography: TPageControl
      Left = 11
      Top = 22
      Width = 378
      Height = 109
      ActivePage = TabSheet3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
      OnChange = pcGeographyChange
      object TabSheet7: TTabSheet
        Caption = 'None'
        ImageIndex = 4
        object Label19: TLabel
          Left = 15
          Top = 12
          Width = 274
          Height = 13
          Caption = 'Only the "time of day" setting will select airport locations.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label35: TLabel
          Left = 15
          Top = 31
          Width = 346
          Height = 13
          Caption = 
            'Time of Day (below) must be selected if the "None" option is bei' +
            'ng used.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Continent'
        object cbContinentAF: TCheckBox
          Left = 15
          Top = 16
          Width = 74
          Height = 17
          Caption = 'Africa'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 0
          OnClick = cbContinentAFClick
        end
        object cbContinentNA: TCheckBox
          Left = 15
          Top = 39
          Width = 90
          Height = 17
          Caption = 'North America'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 1
          OnClick = cbContinentAFClick
        end
        object cbContinentAN: TCheckBox
          Left = 111
          Top = 16
          Width = 82
          Height = 17
          Caption = 'Antarctica'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 2
          OnClick = cbContinentAFClick
        end
        object cbContinentOC: TCheckBox
          Left = 111
          Top = 39
          Width = 82
          Height = 17
          Caption = 'Oceania'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 3
          OnClick = cbContinentAFClick
        end
        object cbContinentAS: TCheckBox
          Left = 199
          Top = 16
          Width = 50
          Height = 17
          Caption = 'Asia'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 4
          OnClick = cbContinentAFClick
        end
        object cbContinentSA: TCheckBox
          Left = 199
          Top = 39
          Width = 97
          Height = 17
          Caption = 'South America'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 5
          OnClick = cbContinentAFClick
        end
        object cbContinentEU: TCheckBox
          Left = 294
          Top = 16
          Width = 59
          Height = 17
          Caption = 'Europe'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 6
          OnClick = cbContinentAFClick
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'Country'
        ImageIndex = 1
        object cbCountryList: TComboBox
          Left = 14
          Top = 18
          Width = 340
          Height = 21
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnChange = cbContinentAFClick
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Region'
        ImageIndex = 2
        object Label31: TLabel
          Left = 88
          Top = 20
          Width = 207
          Height = 13
          Cursor = crHandPoint
          Caption = '(https://en.wikipedia.org/wiki/ISO_3166-2)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = Label31Click
        end
        object Bevel3: TBevel
          Left = 15
          Top = 177
          Width = 370
          Height = 43
          Shape = bsFrame
          Style = bsRaised
        end
        object eRegionICO: TEdit
          Left = 14
          Top = 18
          Width = 59
          Height = 21
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puRegionSelect
          TabOrder = 0
          OnChange = cbContinentAFClick
        end
      end
      object TabSheet6: TTabSheet
        Caption = 'Longitude && Latitude'
        ImageIndex = 3
        object Label5: TLabel
          Left = 11
          Top = 17
          Width = 64
          Height = 13
          Caption = 'Latitude from'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label7: TLabel
          Left = 11
          Top = 44
          Width = 72
          Height = 13
          Caption = 'Longitude from'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label6: TLabel
          Left = 169
          Top = 17
          Width = 10
          Height = 13
          Caption = 'to'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object labellongto: TLabel
          Left = 169
          Top = 44
          Width = 10
          Height = 13
          Caption = 'to'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object eLatFrom: TEdit
          Left = 89
          Top = 14
          Width = 75
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puLatitude
          TabOrder = 0
          Text = '0'
          OnChange = cbContinentAFClick
        end
        object eLatTo: TEdit
          Left = 185
          Top = 14
          Width = 75
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puLatitude
          TabOrder = 1
          Text = '0'
          OnChange = cbContinentAFClick
        end
        object eLongTo: TEdit
          Left = 185
          Top = 41
          Width = 75
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puLongitude
          TabOrder = 2
          Text = '0'
          OnChange = cbContinentAFClick
        end
        object eLongFrom: TEdit
          Left = 89
          Top = 41
          Width = 75
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puLongitude
          TabOrder = 3
          Text = '0'
          OnChange = cbContinentAFClick
        end
      end
    end
  end
  object GroupBox2: TGroupBox
    Left = 797
    Top = 48
    Width = 412
    Height = 368
    Caption = 'Route'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    object pcRoute: TPageControl
      Left = 11
      Top = 24
      Width = 390
      Height = 337
      ActivePage = TabSheet2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = pcRouteChange
      object TabSheet1: TTabSheet
        Caption = 'Random'
        object Bevel10: TBevel
          Left = 3
          Top = 192
          Width = 372
          Height = 63
          Shape = bsFrame
          Style = bsRaised
        end
        object Bevel7: TBevel
          Left = 3
          Top = 3
          Width = 372
          Height = 63
          Shape = bsFrame
          Style = bsRaised
        end
        object Label9: TLabel
          Left = 22
          Top = 12
          Width = 31
          Height = 13
          Hint = 'the maximum distance between legs'
          Caption = 'Range'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label10: TLabel
          Left = 139
          Top = 15
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
        object Label16: TLabel
          Left = 139
          Top = 39
          Width = 21
          Height = 13
          Caption = 'mins'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Bevel9: TBevel
          Left = 3
          Top = 72
          Width = 372
          Height = 114
          Shape = bsFrame
          Style = bsRaised
        end
        object Label11: TLabel
          Left = 22
          Top = 83
          Width = 60
          Height = 13
          Caption = 'Start Airport'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label13: TLabel
          Left = 139
          Top = 83
          Width = 34
          Height = 13
          Caption = '(ICAO)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label29: TLabel
          Left = 22
          Top = 138
          Width = 174
          Height = 13
          Caption = 'When Start and End set, use which?'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label14: TLabel
          Left = 139
          Top = 110
          Width = 34
          Height = 13
          Caption = '(ICAO)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label12: TLabel
          Left = 22
          Top = 110
          Width = 54
          Height = 13
          Caption = 'End Airport'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object lDistanceStartEnd: TLabel
          Left = 22
          Top = 163
          Width = 12
          Height = 13
          Caption = '...'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label4: TLabel
          Left = 22
          Top = 203
          Width = 22
          Height = 13
          Caption = 'Legs'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label17: TLabel
          Left = 22
          Top = 230
          Width = 59
          Height = 13
          Caption = 'Route count'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Bevel11: TBevel
          Left = 3
          Top = 261
          Width = 372
          Height = 43
          Shape = bsFrame
          Style = bsRaised
        end
        object Label28: TLabel
          Left = 139
          Top = 275
          Width = 5
          Height = 13
          Alignment = taRightJustify
          Caption = #176
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label32: TLabel
          Left = 168
          Top = 275
          Width = 167
          Height = 13
          Caption = '10'#176' margin applied when searching'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cbUseFlightTime: TCheckBox
          Left = 21
          Top = 36
          Width = 67
          Height = 17
          Caption = 'Flight time'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = cbUseFlightTimeClick
        end
        object eRange: TEdit
          Left = 94
          Top = 12
          Width = 42
          Height = 21
          Hint = 'the maximum distance between legs'
          Alignment = taRightJustify
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          PopupMenu = puRange
          TabOrder = 1
          Text = '100'
          OnExit = eLegsExit
        end
        object eFlightTime: TEdit
          Left = 94
          Top = 36
          Width = 42
          Height = 21
          Hint = 
            'calculate the distance between legs bsaed on aircraft flight tim' +
            'e'
          Alignment = taRightJustify
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 2
          Text = '60'
          OnExit = eLegsExit
        end
        object cbUseAircraftRange: TCheckBox
          Left = 204
          Top = 11
          Width = 114
          Height = 17
          Hint = 'set leg distance based on selected aircraft'#39's range'
          Caption = 'Use aircraft range'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 3
          OnClick = cbUseFlightTimeClick
        end
        object cbAllowExcessRange: TCheckBox
          Left = 204
          Top = 38
          Width = 114
          Height = 17
          Hint = 'allow a route longer than the aircraft maximum'
          Caption = 'Allow excess range'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 4
        end
        object eStartAirportICAO: TEdit
          Left = 94
          Top = 80
          Width = 42
          Height = 21
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puSelectICAO
          TabOrder = 5
          OnExit = eEndAirportICAOExit
        end
        object cbStartFromFavourite: TCheckBox
          Left = 204
          Top = 82
          Width = 142
          Height = 17
          Caption = 'Start at random favourite'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 6
        end
        object cbEndAtFavourite: TCheckBox
          Left = 204
          Top = 109
          Width = 142
          Height = 17
          Caption = 'End at random favourite'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 7
        end
        object rbStartEndRange: TRadioButton
          Left = 250
          Top = 136
          Width = 51
          Height = 17
          Caption = 'Range'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          OnClick = cbContinentAFClick
        end
        object rbStartEndLegs: TRadioButton
          Left = 203
          Top = 136
          Width = 41
          Height = 17
          Caption = 'Legs'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          TabStop = True
          OnClick = cbContinentAFClick
        end
        object eEndAirportICAO: TEdit
          Left = 94
          Top = 107
          Width = 42
          Height = 21
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puSelectICAO
          TabOrder = 10
          OnExit = eEndAirportICAOExit
        end
        object eLegs: TEdit
          Left = 94
          Top = 200
          Width = 42
          Height = 21
          Hint = 'number of legs of your journey'
          Alignment = taRightJustify
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 11
          Text = '0'
          OnExit = eLegsExit
        end
        object eCount: TEdit
          Left = 94
          Top = 227
          Width = 42
          Height = 21
          Hint = 'generate this many random routes'
          Alignment = taRightJustify
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 12
          Text = '0'
          OnExit = eLegsExit
        end
        object cbUseDirection: TCheckBox
          Left = 22
          Top = 274
          Width = 69
          Height = 17
          Caption = 'Direction'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 13
          OnClick = cbUseDirectionClick
        end
        object eDirection: TEdit
          Left = 94
          Top = 272
          Width = 42
          Height = 21
          Hint = 'fly the generated routes in this direction'
          Alignment = taRightJustify
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puDirection
          TabOrder = 14
          Text = '0'
          OnExit = eDirectionExit
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Real-world'
        ImageIndex = 1
        object Bevel16: TBevel
          Left = 3
          Top = 72
          Width = 372
          Height = 65
          Shape = bsFrame
          Style = bsRaised
        end
        object Bevel18: TBevel
          Left = 3
          Top = 190
          Width = 372
          Height = 43
          Shape = bsFrame
          Style = bsRaised
        end
        object Label8: TLabel
          Left = 22
          Top = 12
          Width = 31
          Height = 13
          Hint = 'the maximum distance between legs'
          Caption = 'Range'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Bevel15: TBevel
          Left = 3
          Top = 3
          Width = 372
          Height = 63
          Shape = bsFrame
          Style = bsRaised
        end
        object Label15: TLabel
          Left = 139
          Top = 15
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
        object Label27: TLabel
          Left = 139
          Top = 39
          Width = 21
          Height = 13
          Caption = 'mins'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Bevel17: TBevel
          Left = 3
          Top = 143
          Width = 372
          Height = 41
          Shape = bsFrame
          Style = bsRaised
        end
        object Label37: TLabel
          Left = 139
          Top = 110
          Width = 34
          Height = 13
          Caption = '(ICAO)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label39: TLabel
          Left = 22
          Top = 204
          Width = 59
          Height = 13
          Caption = 'Route count'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label38: TLabel
          Left = 21
          Top = 110
          Width = 33
          Height = 13
          Hint = '(optional)'
          Caption = 'Airport'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object eRWRouteCount: TEdit
          Left = 94
          Top = 201
          Width = 42
          Height = 21
          Hint = 'generate this many random routes'
          Alignment = taRightJustify
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 7
          Text = '0'
          OnExit = eLegsExit
        end
        object eRWRange: TEdit
          Left = 94
          Top = 12
          Width = 42
          Height = 21
          Hint = 'the maximum distance between legs'
          Alignment = taRightJustify
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          PopupMenu = puRange
          TabOrder = 0
          Text = '100'
          OnExit = eLegsExit
        end
        object cbRWUseAircraftRange: TCheckBox
          Left = 204
          Top = 11
          Width = 114
          Height = 17
          Hint = 'set leg distance based on selected aircraft'#39's range'
          Caption = 'Use aircraft range'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = cbRWUseFlightTimeClick
        end
        object cbRWUseFlightTime: TCheckBox
          Left = 22
          Top = 36
          Width = 67
          Height = 17
          Caption = 'Flight time'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = cbRWUseFlightTimeClick
        end
        object eRWFlightTime: TEdit
          Left = 94
          Top = 36
          Width = 42
          Height = 21
          Hint = 
            'calculate the distance between legs bsaed on aircraft flight tim' +
            'e'
          Alignment = taRightJustify
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 3
          Text = '60'
          OnExit = eLegsExit
        end
        object cbRWAllowExcessRange: TCheckBox
          Left = 204
          Top = 38
          Width = 114
          Height = 17
          Hint = 'all a route longer than the aircraft maximum'
          Caption = 'Allow excess range'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 4
        end
        object cbRWAirlines: TComboBox
          Left = 94
          Top = 153
          Width = 246
          Height = 21
          Style = csDropDownList
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          OnChange = cbContinentAFClick
        end
        object eRWAirport: TEdit
          Left = 94
          Top = 107
          Width = 42
          Height = 21
          CharCase = ecUpperCase
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PopupMenu = puSelectICAO
          TabOrder = 6
          OnExit = eRWAirportExit
        end
        object rbRWFromICAO: TRadioButton
          Left = 21
          Top = 84
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
          TabOrder = 8
          TabStop = True
        end
        object rbRWToICAO: TRadioButton
          Left = 68
          Top = 84
          Width = 41
          Height = 17
          Caption = 'To'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
        end
        object cbRWAirline: TCheckBox
          Left = 21
          Top = 155
          Width = 55
          Height = 17
          Caption = 'Airline'
          TabOrder = 10
          OnClick = cbRWAirlineClick
        end
        object cbRWRouteType: TComboBox
          Left = 204
          Top = 107
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
          TabOrder = 11
          Text = 'Any route'
          OnChange = cbContinentAFClick
          Items.Strings = (
            'Any route'
            'Internal only'
            'External only')
        end
      end
    end
  end
  object gbGeneratedRoutes: TGroupBox
    Left = 8
    Top = 382
    Width = 783
    Height = 363
    Caption = 'Generated Routes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    object Image1: TImage
      Left = 759
      Top = 88
      Width = 18
      Height = 18
      AutoSize = True
      Picture.Data = {
        07544269746D617026040000424D260400000000000036000000280000001200
        0000120000000100180000000000F0030000120B0000120B0000000000000000
        0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF737373747474
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FF909090000000000000909090FF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF7200FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FF9090900000000000000000000000008F8F8FFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FF4D00FF00FFFF00FFFF00FFFF00FFFF00FF90909000000000
        0000000000000000000000000000909090FF00FFFF00FFFF00FFFF00FFFF00FF
        0000FF00FFFF00FFFF00FFFF00FF9090900000000000004444440F0F0F101010
        4444440000000000008F8F8FFF00FFFF00FFFF00FFFF00FF7400FF00FFFF00FF
        FF00FF909090000000000000888888FF00FF050505050505FF00FF8888880000
        00000000909090FF00FFFF00FFFF00FF0000FF00FFFF00FF9595950000000000
        006B6B6BFF00FFFF00FF000000000000FF00FFFF00FF6A6A6A00000000000096
        9696FF00FFFF00FF0000FF00FFFF00FFFF00FF0505054F4F4FFF00FFFF00FFFF
        00FF000000000000FF00FFFF00FFFF00FF4F4F4F050505FF00FFFF00FFFF00FF
        0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FF000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FF0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FF000000000000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
        0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000FF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FF000000000000FF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF0000}
      Transparent = True
    end
    object bExportSelected: TButton
      Left = 755
      Top = 142
      Width = 25
      Height = 22
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
      TabOrder = 0
      OnClick = bExportSelectedClick
    end
    object bExportSelectedText: TButton
      Left = 755
      Top = 166
      Width = 25
      Height = 22
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
      TabOrder = 1
      OnClick = bExportSelectedTextClick
    end
    object bOpenStartMap: TButton
      Left = 755
      Top = 64
      Width = 25
      Height = 22
      Hint = 'open departure airport'#39's location on google maps'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageAlignment = iaCenter
      ImageIndex = 5
      Images = il16x16
      ParentFont = False
      TabOrder = 2
      OnClick = bOpenStartMapClick
    end
    object bOpenEndMap: TButton
      Left = 755
      Top = 110
      Width = 25
      Height = 22
      Hint = 'open arrival airport'#39's location on google maps'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageAlignment = iaCenter
      ImageIndex = 5
      Images = il16x16
      ParentFont = False
      TabOrder = 3
      OnClick = bOpenEndMapClick
    end
    object bSaveRoutes: TButton
      Left = 755
      Top = 24
      Width = 25
      Height = 22
      Hint = 'export routes to a CSV file'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageAlignment = iaCenter
      ImageIndex = 7
      Images = il16x16
      ParentFont = False
      TabOrder = 4
      OnClick = bSaveRoutesClick
    end
    object sgRoutes: TStringGrid
      Left = 6
      Top = 22
      Width = 745
      Height = 341
      ColCount = 10
      DefaultRowHeight = 22
      FixedCols = 0
      RowCount = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect, goFixedRowDefAlign]
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 5
      OnClick = sgRoutesClick
      ColWidths = (
        189
        59
        41
        53
        10
        64
        64
        64
        60
        64)
    end
    object bExportSelectedXPlane: TButton
      Left = 755
      Top = 190
      Width = 25
      Height = 22
      Hint = 'export selected route to text file'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageAlignment = iaCenter
      ImageIndex = 8
      Images = il16x16
      ParentFont = False
      TabOrder = 6
      OnClick = bExportSelectedXPlaneClick
    end
    object mRouteDebug: TMemo
      Left = 6
      Top = 293
      Width = 745
      Height = 67
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Courier New'
      Font.Style = []
      Lines.Strings = (
        'Selected route parameters will '
        'be shown here...')
      ParentFont = False
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 7
      Visible = False
    end
    object bShowSearchParameters: TButton
      Left = 755
      Top = 338
      Width = 25
      Height = 22
      Hint = 'export selected route to text file'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageAlignment = iaCenter
      Images = il16x16
      ParentFont = False
      TabOrder = 8
      Visible = False
      OnClick = bShowSearchParametersClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 312
    Top = 65532
    object File1: TMenuItem
      Caption = 'File'
      object miNew: TMenuItem
        Caption = 'New'
        OnClick = tbNewClick
      end
      object N15: TMenuItem
        Caption = '-'
      end
      object File2: TMenuItem
        Caption = 'Open...'
        OnClick = tbOpenClick
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object N17: TMenuItem
        Caption = 'Save...'
        OnClick = tbSaveClick
      end
      object Exit2: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
      end
      object N16: TMenuItem
        Caption = '-'
      end
    end
    object Edit4: TMenuItem
      Caption = 'Edit'
      object Reset1: TMenuItem
        Caption = 'Reset'
        object miResetAircraft: TMenuItem
          Caption = 'Aircraft'
          OnClick = miResetAircraftClick
        end
        object miResetAirports: TMenuItem
          Caption = 'Airports'
          OnClick = miResetAirportsClick
        end
        object miResetRoute: TMenuItem
          Caption = 'Route'
          OnClick = miResetRouteClick
        end
      end
    end
    object Searcg1: TMenuItem
      Caption = 'Search'
      object Airports1: TMenuItem
        Caption = 'Airports...'
        OnClick = Airports1Click
      end
    end
    object Ai1: TMenuItem
      Caption = 'Aircraft'
      object Set1: TMenuItem
        Caption = 'Set'
        object GA2: TMenuItem
          Tag = 1
          Caption = 'Airliners (Jet)'
          OnClick = miSetGAClick
        end
        object AirlinersPropTurbo1: TMenuItem
          Tag = 10
          Caption = 'Airliners (Prop/Turbo)'
          OnClick = miSetGAClick
        end
        object miSetGA: TMenuItem
          Caption = 'GA'
          OnClick = miSetGAClick
        end
        object Gliders1: TMenuItem
          Tag = 8
          Caption = 'Gliders'
          OnClick = miSetGAClick
        end
        object Helicopters1: TMenuItem
          Tag = 9
          Caption = 'Helicopters'
          OnClick = miSetGAClick
        end
        object Props1: TMenuItem
          Tag = 2
          Caption = 'Props'
          OnClick = miSetGAClick
        end
        object urbos1: TMenuItem
          Tag = 3
          Caption = 'Turbos'
          OnClick = miSetGAClick
        end
        object wins1: TMenuItem
          Tag = 4
          Caption = 'Twins'
          OnClick = miSetGAClick
        end
        object Seaplanes1: TMenuItem
          Tag = 5
          Caption = 'Seaplanes'
          OnClick = miSetGAClick
        end
        object N2: TMenuItem
          Caption = '-'
        end
        object Militaryjets1: TMenuItem
          Tag = 6
          Caption = 'Military jets'
          OnClick = miSetGAClick
        end
        object Militarypropsturbo1: TMenuItem
          Tag = 7
          Caption = 'Military props (+ turbo)'
          OnClick = miSetGAClick
        end
      end
    end
    object Routes1: TMenuItem
      Caption = 'Routes'
      object miRouteBrowser: TMenuItem
        Caption = 'Browser...'
        OnClick = miRouteBrowserClick
      end
      object N22: TMenuItem
        Caption = '-'
      end
      object miOpenRouteFolder: TMenuItem
        Caption = 'Open saved routes folder...'
        OnClick = miOpenRouteFolderClick
      end
    end
    object ools1: TMenuItem
      Caption = 'Tools'
      object Createcustomaircrafttxt1: TMenuItem
        Caption = 'Create "custom_aircraft.txt"'
        OnClick = Createcustomaircrafttxt1Click
      end
      object N12: TMenuItem
        Caption = '-'
      end
      object DistancefromAtoB1: TMenuItem
        Caption = 'Distance from A to B...'
        OnClick = DistancefromAtoB1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Favourites1: TMenuItem
        Caption = 'Favourites...'
        OnClick = Favourites1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object miShowTooltips: TMenuItem
        AutoCheck = True
        Caption = 'Show tooltips'
        Checked = True
        OnClick = miShowTooltipsClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object About1: TMenuItem
        Caption = 'About...'
        OnClick = About1Click
      end
    end
  end
  object ImageList1: TImageList
    Height = 32
    Width = 32
    Left = 1080
    Top = 65532
    Bitmap = {
      494C010106000800040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000800000004000000001002000000000000080
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000681E68003E0E3E0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007222
      7200200020005517550000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000712171002000
      20006F216F000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000071217100200020007121
      7100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000072227200200020006F216F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000072227200200020006E206E00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D72ED700962C9600370B
      3700200020002000200044104400962C9600E02BE00000000000000000000000
      0000000000000000000071217100200020006F216F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C930C9002000200020002000000000000000
      0000000000000000000000000000000000002000200027032700C831C8000000
      0000000000007121710020002000712171000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FE03FE0071217100200020000000000050505000A2A2A200DBDB
      DB00F2F2F200F2F2F200DBDBDB00A6A6A6004F4F4F0000000000200020008828
      880088288800200020006F216F00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000045114500000000002F2F2F00C2C2C200FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C5C5C500333333000000
      0000000000008226820000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000691F69002000200045454500FBFBFB00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004A4A
      4A00000000008327830000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000C930
      C9002000200020202000FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF002222220020002000C431C400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000002000
      200000000000CECECE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00CFCFCF000000000020002000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000DB2EDB002000
      200048484800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF004B4B4B0020002000D82FD8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      00000000000000000000000000000000000000000000000000008D298D000000
      0000ADADAD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00B2B2B20000000000892989000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      00000000000000000000000000000000000000000000000000003E0E3E000000
      0000DCDCDC00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00DCDCDC0000000000370B37000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000200020000000
      0000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F4F4F40000000000200020000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000200020000000
      0000F6F6F600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F6F6F60000000000200020000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000410F41000000
      0000DADADA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00DDDDDD0000000000330933000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      00000000000000000000000000000000000000000000000000008E2A8E000000
      00009E9E9E00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00AAAAAA00000000008B298B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E12CE1002000
      200038383800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF004747470020002000D72ED7000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000002101
      210000000000C3C3C300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00CDCDCD000000000020002000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CD30
      CD00200020001C1C1C00FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF002323230020002000CB30CB00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000722272002000200045454500F7F7F700FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FAFAFA004747
      4700200020006B1F6B0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000521652002000200026262600C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C1C1C1002C2C2C002000
      2000521652000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000008026800020002000000000004D4D4D00A1A1A100DBDB
      DB00F2F2F200F2F2F200DBDBDB009F9F9F005353530000000000200020007824
      7800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000CB30CB002000200020002000000000000000
      0000000000000000000000000000000000002000200021012100C930C9000000
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
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DA2DDA009A2C9A00410F
      410020002000200020003E0E3E00952B9500DD2CDD0000000000000000000000
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000131313000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001313
      1300000000000000000000000000000000000000000000000000000000000000
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
      00000F0F0F00000000000F0F0F00111111001111110011111100111111001111
      1100111111001111110011111100111111001111110013131300131313001111
      1100111111001111110011111100111111001111110010101000000000000F0F
      0F00000000000000000000000000000000000000000000000000000000000000
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
      00000101010000000000EBEBEB00F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500ECECEC00000000000000
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
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000001111110011111100080808000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000B0B0B009F9F9F00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000202
      0200000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000009090900F8F8F8000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009E9E9E0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000039393900F8F8
      F800F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F5004F4F4F0000000000969696000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000181818000000
      0000DADADA00FFFFFF00F0F0F000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000C5C5
      C500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D3D3D300000000000A0A0A00F8F8
      F800000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000ABABAB000000
      00006E6E6E00FFFFFF00FFFFFF0018181800000000009D9D9D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000002F2F
      2F00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004F4F4F00000000009797
      9700000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00F0F0F0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000001D1D1D001B1B1B000000
      0000B8B8B800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D3D3D300000000000909
      0900F8F8F8000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF0018181800000000009E9E9E000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000047474700AAAAAA000000
      000028282800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004F4F4F000000
      0000969696000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      000000000000000000000000000000000000F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001717
      170000000000DADADA00FFFFFF00FFFFFF00F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000024242400FCFCFC003D3D
      3D0000000000B8B8B800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D2D2D2000000
      00000A0A0A00F8F8F80000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000018181800000000000000
      0000000000000000000000000000000000009D9D9D000000000000000000ABAB
      AB00000000006D6D6D00FFFFFF00FFFFFF00FFFFFF0018181800000000009E9E
      9E00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000E0E0E00FFFFFF00C9C9
      C9000000000028282800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004F4F
      4F00000000009696960000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      00000000000000000000000000000000000000000000F0F0F000000000000000
      0000FFFFFF00FFFFFF00F1F1F100000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00F0F0F000000000000000
      000000000000000000000000000000000000000000000000000032323200DADA
      DA00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000F0F0F00FEFEFE00FFFF
      FF002929290000000000B8B8B800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D3D3
      D300000000000A0A0A00F8F8F800000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000181818000000
      00009D9D9D00FFFFFF00FFFFFF00181818000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00181818000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000474747000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00B8B8B8000000000028282800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF004F4F4F000000000096969600000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000F0F0F0000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C3C3C3000000
      000000000000DADADA0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F4F4F400FFFF
      FF00FFFFFF002828280000000000B8B8B800FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00D3D3D300000000000A0A0A00F8F8F8000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000001818
      1800000000009D9D9D00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C4C4
      C400000000003232320000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00B8B8B8000000000028282800FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF006161610000000000959595000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000009D9D
      9D000000000018181800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF002828280000000000AAAAAA00F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F7F7F700C8C8C80000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F0F0F000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004747
      4700000000007F7F7F0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00B8B8B800000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001111110011111100000000000000
      0000000000000808080000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      00000000000000000000000000000000000000000000000000009D9D9D000000
      000018181800FFFFFF00FFFFFF009E9E9E000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF009D9D9D000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00FFFFFF007F7F7F000404040000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000002C2C2C00000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F0F0F000FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F0F0F0000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500ECECEC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      000000000000000000000000000000000000000000009E9E9E00000000000000
      000000000000000000000000000000000000181818000000000000000000DADA
      DA000000000018181800FFFFFF00FFFFFF00FFFFFF009D9D9D00000000001818
      1800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F0F0F00000000000000000006D6D
      6D0000000000ABABAB00FFFFFF00FFFFFF00FFFFFF000000000000000000F0F0
      F000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000012121200F5F5F500FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF009D9D9D0000000000171717000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDFD
      FD00F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500ECECEC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000F0F0F0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000013131300FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00949494002121
      2100000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000F0F0F00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DADADA000000
      000018181800FFFFFF00FFFFFF009E9E9E000000000018181800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000F0F0F00ECECEC00F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500CECECE0047474700000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002D2D2D0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000006E6E6E000000
      0000ABABAB00FFFFFF00FFFFFF000000000000000000F0F0F000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000202020000000000000000000000
      0000000000000000000000000000000000000000000000000000474747000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000EDEDED00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001818180000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF0000000000000000000000000000000000000000002B2B2B00000000000000
      0000000000000000000000000000000000002121210094949400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000041414100000000003C3C3C00F2F2F200FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F1F1F10000000000000000000000
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
      0000000000003A3A3A00000000003A3A3A00F2F2F200FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000181818000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000DADADA0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000393939000000000039393900E3E3E300F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500ECECEC00000000000101
      0100000000000000000000000000000000000000000000000000000000000000
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
      00000000000000000000000000003A3A3A000000000001010100111111001212
      1200121212001111110011111100111111001111110011111100111111001111
      1100111111001111110011111100111111001212120010101000000000000F0F
      0F00000000000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000003E3E3E0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001313
      1300000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000400000000100010000000000000400000000000000000000
      000000000000000000000000FFFFFF00C000000FFFFFFFFF0000000000000000
      C000000FFFFFFFFF0000000000000000C000000FFFFFFFF30000000000000000
      C000000FFFFFFFE30000000000000000C000000FFFFFFFC70000000000000000
      C000000FFFFFFF8F0000000000000000C000000FFFFFFF1F0000000000000000
      C000000FFFFFFE3F0000000000000000C000000FFF807C7F0000000000000000
      C000000FFE0018FF0000000000000000C000000FF80001FF0000000000000000
      C000000FF80003FF0000000000000000C000000FF00003FF0000000000000000
      C000000FE00001FF0000000000000000C000000FE00001FF0000000000000000
      C000000FC00000FF0000000000000000C000000FC00000FF0000000000000000
      C000000FC00000FF0000000000000000C000000FC00000FF0000000000000000
      C000000FC00000FF0000000000000000C000000FC00000FF0000000000000000
      C000000FC00000FF0000000000000000C000000FC00000FF0000000000000000
      C000000FE00001FF0000000000000000C000001FE00001FF0000000000000000
      C000003FF00003FF0000000000000000C000007FF80007FF0000000000000000
      C00000FFFC000FFF0000000000000000C00001FFFE001FFF0000000000000000
      C00003FFFF807FFF0000000000000000C00007FFFFFFFFFF0000000000000000
      C0000FFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFFF000000FFFFFFFFF
      FFFFFFFFFFFFFFFFF000000FFFFFFFFFF8000003FFFFFFFFF000000FFFFFFFFF
      F0000003FFFFFFFFF000000FFFFFFFFFE00000030000003FF000000FFFC0FFFF
      C00000030000001FF000000FFFC07FFFC00000030000001FF000000FFFC07FFF
      C00000030000000FF000000FFFC03FFFC00000030000000FF000000FFFE03FFF
      C000000300000007F000000FFFE01FFFC000000300000007F000000F00E01FFF
      C000000300000003F000000F80600FFFC000000300000003F000000F8000000F
      C000000300000001F000000FC0000007C000000300000001F000000FC0000003
      C000000300000000F000000FE0000003C000000300000000F000000FE0000003
      C000000300000000F000000FE0000003C000000300000000F000000FC0000007
      C000000300000001F000000FC0000007C00000030000003FF000000F80600FFF
      C00000030000003FF000000F80600FFFC00000030000003FF000000FFFE01FFF
      C00000030000003FF000000FFFE01FFFC00000030000003FF000000FFFC03FFF
      C00000030000007FF000000FFFC03FFFC0000003001FFFFFF000000FFFC07FFF
      C0000003803FFFFFF000000FFFC07FFFC0000003FFFFFFFFF800000FFFFFFFFF
      C0000003FFFFFFFFFC00000FFFFFFFFFFFFFFFFFFFFFFFFFFE00000FFFFFFFFF
      FFFFFFFFFFFFFFFFFF00000FFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object sdMain: TSaveDialog
    Filter = 'FSAC configuration files|*.config'
    Left = 1176
  end
  object odMain: TOpenDialog
    Filter = 'FSAC configuration files|*.config'
    Left = 1136
  end
  object il16x16: TImageList
    Left = 1024
    Top = 65532
    Bitmap = {
      494C010109001800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000AAAA
      AA0000000000B8B8B80000000000000000000000000000000000B8B8B8000000
      0000AAAAAA000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00005858580042424200000000000000000000000000F4F4F400262626005858
      5800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000D1D1D10000000000AAAAAA000000000000000000AAAAAA0000000000D1D1
      D100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008D8D8D0026262600F4F4F400E9E9E900000000009C9C9C000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F4F4F400262626009C9C9C006B6B6B0026262600F4F4F4000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000AAAAAA000000000000000000B8B8B800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000DDDDDD000000000000000000F4F4F400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000006B6B6B0042424200424242007D7D7D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000B8B8B80000000000B8B8B800B8B8B80000000000D1D1D1000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F4F4F400424242006B6B6B0000000000000000006B6B6B0042424200F4F4
      F400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000AAAAAA0000000000D1D1D1000000000000000000DDDDDD0000000000AAAA
      AA00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E9E9
      E900000000007D7D7D00000000000000000000000000000000008D8D8D000000
      0000DDDDDD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E9E9
      E900D1D1D100F4F4F40000000000000000000000000000000000F4F4F400D1D1
      D100E9E9E9000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000A0A0A0005E5E5E009F9F9F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F8F8F80035353500111111000505050029292900F6F6
      F600000000000000000000000000000000000000000000000000000000000000
      0000AFAFAF006C6C6C003939390017171700202020000F0F0F0064646400C7C7
      C70000000000000000000000000000000000000000002D2D2D78000000F10101
      01F1000000F1000000F1000000F1000000F1000000F1000000F1000000F10000
      00F1000000F1000000F1000000F1000000E40000000000000000000000000000
      0000A0A0A0002F2F2F001C1C1C00000000001B1B1B002F2F2F00A0A0A0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F3F3F3005A5A5A0050505000000000000000
      0000000000000000000000000000000000000000000000000000000000008B8B
      8B00060606005A5A5A000000000000000000ECECEC00D7D7D7008D8D8D000404
      04007777770000000000000000000000000013131377000000FFD1D1D1FF5F5F
      5FFF6E6E6EFFB2B2B2FF0C0C0CFFDDDDDDFFDDDDDDFFDDDDDDFF272727FF6E6E
      6EFFDDDDDDFFDDDDDDFFC0C0C0FF000000FF0000000000000000A1A1A1002727
      270027272700A9A9A900F3F3F30046464600F2F2F200A8A8A800272727002727
      2700A2A2A2000000000000000000000000000000000000000000000000000000
      0000000000009D9D9D004B4B4B005C5C5C003D3D3D002A2A2A005D5D5D009E9E
      9E00000000000000000000000000000000000000000000000000111111002323
      230000000000000000000000000000000000000000000000000000000000EAEA
      EA0024242400191919000000000000000000000000FFC4C4C4FFFFFFFFFF5D5D
      5DFF919191FFD7D7D7FF000000FFFFFFFFFFFFFFFFFFFFFFFFFF333333FF8A8A
      8AFFFFFFFFFFFFFFFFFFF1F1F1FF000000F1000000004B4B4B0027272700A0A0
      A000FFFFFF00FFFFFF00ECECEC001B1B1B00ECECEC00FFFFFF00FFFFFF00A1A1
      A100262626004C4C4C000000000000000000000000000000000000000000DFDF
      DF002121210049494900AEAEAE00C1C1C100D2D2D200D1D1D100AEAEAE004343
      4300545454009D9D9D0079797900000000000000000062626200191919000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000525252007474740000000000000000F5EEEEEEFFFFFFFFFF4848
      48FF737373FFFFFFFFFFD1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFF363636FF7777
      77FFFFFFFFFFFFFFFFFFDDDDDDFF000000F10000000000000000FDFDFD00FFFF
      FF00FFFFFF00FFFFFF00E6E6E60026262600E5E5E500FFFFFF00FFFFFF00FFFF
      FF00FDFDFD000000000000000000000000000000000000000000E1E1E1000000
      00009C9C9C00EBEBEB0089898900717171005C5C5C007A7A7A009B9B9B00F6F6
      F6005E5E5E0000000000A2A2A20000000000D7D7D70000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000F1DDDDDDFFFFFFFFFF5050
      50FF000000FF8A8A8AFFA8A8A8FF7F7F7FFF7F7F7FFF7F7F7FFF000000FF7F7F
      7FFFFFFFFFFFFFFFFFFFDDDDDDFF000000F10000000013131300FCFCFC00FFFF
      FF00FFFFFF00FFFFFF00E6E6E60026262600E5E5E500FFFFFF00FFFFFF00FFFF
      FF00FCFCFC00131313000000000000000000000000000000000000000000A2A2
      A200ECECEC00161616000000000040404000D2D2D20030303000000000000808
      080042424200C6C6C60000000000000000006161610065656500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000A2A2A20057575700000000F1DDDDDDFFFFFFFFFFB3B3
      B3FF565656FF2E2E2EFF2E2E2EFF2E2E2EFF2E2E2EFF2E2E2EFF5D5D5DFFC7C7
      C7FFFFFFFFFFFFFFFFFFDDDDDDFF000000F10000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00ECECEC0029292900ECECEC00FFFFFF00FFFFFF00FFFF
      FF00F5F5F500121212000000000000000000000000009595950035353500FFFF
      FF0000000000CFCFCF00FFFFFF001A1A1A000000000084848400D9D9D900A4A4
      A40000000000FBFBFB00000000000000000015151500E3E3E300000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000DDDDDD000E0E0E00000000F1DCDCDCFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFDCDCDCFF000000F10000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00EDEDED0000000000EDEDED00FFFFFF00FFFFFF00FFFF
      FF00F5F5F500111111000000000000000000000000002A2A2A00C3C3C3008282
      820000000000FFFFFF00B9B9B90028282800262626007F7F7F00FFFFFF00FDFD
      FD00000000006767670000000000000000001414140000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F5F5F50026262600000000F1DFDFDFFFFAFAFAFFF3F3
      F3FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFEEEE
      EEFFF1F1F1FFFAFAFAFFDFDFDFFF000000F10000000009090900FDFDFD00FFFF
      FF00FFFFFF00A1A1A100272727002A2A2A0027272700A0A0A000FFFFFF00FFFF
      FF00FDFDFD000A0A0A000000000000000000F3F3F30036363600D5D5D5005F5F
      5F005C5C5C00353535001B1B1B00EBEBEB00FFFFFF00070707007D7D7D008080
      80003F3F3F0050505000F5F5F500000000001D1D1D00F9F9F900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000001C1C1C00000000F1F4F4F4FF8A8A8AFF0A0A
      0AFF020202FF020202FF020202FF020202FF020202FF020202FF020202FF0202
      02FF0A0A0AFF8A8A8AFFF4F4F4FF000000F10000000025252500FFFFFF00A9A9
      A9002727270027272700A5A5A500FDFDFD00A6A6A6002727270027272700A8A8
      A800FFFFFF00262626000000000000000000DFDFDF0042424200CACACA005B5B
      5B00EEEEEE000000000000000000FFFFFF00FFFFFF00FFFFFF00000000000000
      0000EEEEEE0047474700DFDFDF00000000000F0F0F00CFCFCF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000EBEBEB000A0A0A00000000F1F7F7F7FF4F4F4FFF5858
      58FFCECECEFFCECECEFFCECECEFFCECECEFFCECECEFFCECECEFFCECECEFFCECE
      CEFF585858FF4F4F4FFFF7F7F7FF000000F100000000000000004D4D4D005E5E
      5E00A9A9A900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A9A9A9005D5D
      5D004D4D4D00000000000000000000000000F1F1F10036363600D5D5D5006A6A
      6A003F3F3F00818181007E7E7E0007070700FFFFFF00EBEBEB001B1B1B003636
      36005C5C5C0042424200F6F6F600000000002D2D2D008D8D8D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000008C8C8C0028282800000000F1F6F6F6FF4E4E4EFF8A8A
      8AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF8A8A8AFF4E4E4EFFF6F6F6FF000000F1000000004343430000000000A8A8
      A800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A9A9
      A900000000004343430000000000000000000000000024242400C9C9C9009999
      990000000000FDFDFD00FFFFFF00808080002626260029292900B9B9B900FFFF
      FF00000000004B4B4B000000000000000000B9B9B90000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F9F9F90000000000C2C2C200000000F1F6F6F6FF545454FF7F7F
      7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF7F7F7FFF545454FFF6F6F6FF000000F10000000000000000BABABA003434
      340027272700A0A0A000FFFFFF00FFFFFF00FFFFFF00A0A0A000272727003535
      3500BABABA0000000000000000000000000000000000888888003B3B3B00FFFF
      FF000C0C0C00A3A3A300D8D8D800878787000000000019191900FFFFFF00D1D1
      D10000000000D7D7D70000000000000000000000000046464600676767000000
      0000000000001E1E1E0000000000000000000000000000000000000000000000
      000000000000464646005B5B5B0000000000000000F1F6F6F6FF545454FF7F7F
      7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF7F7F7FFF545454FFF6F6F6FF000000F10000000000000000000000000000
      0000A1A1A100272727002E2E2E007E7E7E002E2E2E0027272700A1A1A1000000
      00000000000000000000000000000000000000000000000000003D3D3D008585
      850038383800000000000000000030303000D2D2D20040404000000000000000
      0000B3B3B3000000000000000000000000000000000000000000323232008A8A
      8A00F3F3F3002424240000000000000000000000000000000000000000000000
      0000343434002E2E2E000000000000000000000000F2FFFFFFFF5C5C5CFF8A8A
      8AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF8A8A8AFF5C5C5CFFFFFFFFFF000000F20000000000000000000000000000
      000000000000000000009A9A9A003E3E3E009A9A9A0000000000000000000000
      0000000000000000000000000000000000000000000000000000929292000000
      0000C6C6C600E9E9E900727272005C5C5C0045454500515151005C5C5C00D7D7
      D700000000000000000000000000000000000000000000000000E6E6E6001C1C
      1C00151515003030300000000000000000000000000000000000565656000000
      000070707000000000000000000000000000000000FFD5D5D5FF474747FF6E6E
      6EFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDD
      DDFF6E6E6EFF474747FFD5D5D5FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFAFAF00ACAC
      AC00000000000000000000000000F8F8F800E6E6E600FAFAFA00000000000000
      0000000000000000000000000000000000000000000000000000343434004343
      430001010100151515000000000000000000000000000000000069696900A7A7
      A700000000000000000000000000000000000D0D0DB2000000F1000000F10000
      00F1000000F1000000F1000000F1000000F1000000F1000000F1000000F10000
      00F1000000F1000000F1000000F10D0D0DB20000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F4F4F400131313001010
      1000111111001111110011111100111111001111110011111100111111001111
      11000F0F0F0013131300F4F4F4000000000000000000F4F4F400131313001010
      1000111111001111110011111100111111001111110011111100111111001111
      11000F0F0F0013131300F4F4F400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000000000000000000000000000E6E6E60024242400DCDC
      DC00F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500DCDCDC0024242400E7E7E7000000000000000000E6E6E60024242400DCDC
      DC00F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5F500F5F5
      F500DCDCDC0024242400E7E7E700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000000000000000000000000000E4E4E40027272700F3F3
      F300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00F3F3F30027272700E3E3E3000000000000000000E4E4E40027272700F3F3
      F300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00F3F3F30027272700E3E3E300000000000000000000000000000000000000
      00000000000000000000FFFFFF009E9E9E001818180000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000000000000000000000000000E6E6E60026262600E5E5
      E500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E50025252500E5E5E5000000000000000000E6E6E60026262600E5E5
      E500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E50025252500E5E5E500000000000000000000000000000000000000
      0000000000006D6D6D00ABABAB00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000000000000000000000000000E5E5E50025252500E6E6
      E600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E50026262600E5E5E5000000000000000000E5E5E50025252500E6E6
      E600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E50026262600E5E5E500000000009E9E9E0000000000000000000000
      0000000000000000000000000000FFFFFF009D9D9D0018181800000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000000000000000000000000000E6E6E60025252500E5E5
      E500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E50025252500E6E6E6000000000000000000E6E6E60025252500E5E5
      E500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5E5E50025252500E6E6E600000000000000000000000000FFFFFF009E9E
      9E00000000000000000000000000FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000000000000000000000000000E3E3E30027272700F2F2
      F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00F3F3F30027272700E4E4E4000000000000000000E3E3E30027272700F2F2
      F200FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00F3F3F30027272700E4E4E40000000000000000009E9E9E0018181800FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F1F1F10000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000000000000000000000000000E5E5E50006060600CDCD
      CD00E6E6E600E5E5E500E5E5E500E6E6E600E5E5E500E6E6E600E8E8E800F3F3
      F300CECECE0006060600E5E5E5000000000000000000E5E5E50006060600CDCD
      CD00E6E6E600E5E5E500E5E5E500E6E6E600E5E5E500E6E6E600E8E8E800F3F3
      F300CECECE0006060600E5E5E5000000000000000000F1F1F10000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000000000000000000000000000F5F5F500262626002424
      2400262626002626260026262600262626002626260026262600242424001515
      15002121210026262600F5F5F5000000000000000000F5F5F500262626002424
      2400262626002626260026262600262626002626260026262600242424001515
      15002121210026262600F5F5F500000000000000000000000000FFFFFF00F1F1
      F100000000000000000000000000FFFFFF00FFFFFF0000000000000000000000
      00000000000000000000F0F0F000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000F4F4F400E8E8
      E800E6E6E600E5E5E500E6E6E600E5E5E500E5E5E500E5E5E500CDCDCD000404
      0400CECECE00F4F4F40000000000000000000000000000000000F4F4F400CDCD
      CD0004040400CECECE00E6E6E600E5E5E500E5E5E500E5E5E500CDCDCD000404
      0400CECECE00F4F4F4000000000000000000F1F1F10000000000000000000000
      0000000000000000000000000000FFFFFF00F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000F3F3F3002828
      2800F3F3F300000000000000000000000000000000000000000000000000F3F3
      F30028282800F3F3F30000000000000000000000000000000000F3F3F3002828
      2800F3F3F3000000000000000000000000000000000000000000000000000000
      000000000000ABABAB006D6D6D00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000000000000000000000000000FFFFFF0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FBFB
      FB00F6F6F6000000000000000000000000000000000000000000ECECEC002525
      2500E1E1E100000000000000000000000000000000000000000000000000ECEC
      EC0025252500E1E1E10000000000000000000000000000000000ECECEC002525
      2500E1E1E1000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00F0F0F0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000EEEE
      EE0026262600ECECEC0000000000000000000000000000000000EBEBEB001313
      1300ECECEC00000000000000000000000000000000000000000000000000EBEB
      EB0013131300ECECEC0000000000000000000000000000000000EBEBEB001313
      1300ECECEC000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000050505007272720000000000000000000000000000000000747474002323
      2300000000000000000000000000000000000000000000000000000000000000
      0000050505007272720000000000000000000000000000000000747474002323
      2300000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000D1D1D100000000007F7F7F00F1F1F100F1F1F1007F7F7F0000000000D1D1
      D100000000000000000000000000000000000000000000000000000000000000
      0000D1D1D100000000007F7F7F00F1F1F100F1F1F1007F7F7F0000000000D1D1
      D100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D4D4D400393939000C0C0C000C0C0C0039393900D3D3D3000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D4D4D400393939000C0C0C000C0C0C0039393900D3D3D3000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF00FFFF000000000000FFFF000000000000
      E3C7000000000000F38F000000000000F18F000000000000F81F000000000000
      F81F000000000000FC3F000000000000FC3F000000000000FC3F000000000000
      F81F000000000000F18F000000000000F18F000000000000E3C7000000000000
      E3C7000000000000FFFF000000000000FC7FFC0FF00F0000F01FFE3FE3070000
      C007F80FCFE300008003E0019FF900008003C0013FFD00008003C0033FFC0000
      800380033FFC0000800380037FFC0000800300013FFE0000800300013FFC0000
      800300013FFC0000800380033FF80000C00780039BF90000F01FC007C3F30000
      FC7FC00FC3C70000FFFFCE3FC3CF0000FFFF800380018001FFFF800380018001
      F8FF800380018001F87F800380018001F87F8003800180010C3F800380018001
      80038003800180018001800380018001800180038001800180018003C003C003
      0C3F8003FFC7E3C7F87F8003E7C7E3C7F87F8007E3C7E3C7F8FF800FF3CFF3CF
      FFFF801FF00FF00FFFFF803FF81FF81F00000000000000000000000000000000
      000000000000}
  end
  object puSelectICAO: TPopupMenu
    Tag = 57
    OnPopup = puSelectICAOPopup
    Left = 472
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
    object N8: TMenuItem
      Caption = 'Clear'
      OnClick = N8Click
    end
    object N13: TMenuItem
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
  object puRegionSelect: TPopupMenu
    Left = 392
    object Australia1: TMenuItem
      Caption = 'Australia'
      object NewSouthWales1: TMenuItem
        Tag = 55
        Caption = 'New South Wales'
        OnClick = England1Click
      end
      object NewSouthWales2: TMenuItem
        Tag = 56
        Caption = 'Queensland'
        OnClick = England1Click
      end
      object SouthAustralia1: TMenuItem
        Tag = 57
        Caption = 'South Australia'
        OnClick = England1Click
      end
      object SouthAustralia2: TMenuItem
        Tag = 58
        Caption = 'Tasmania'
        OnClick = England1Click
      end
      object Vistoria1: TMenuItem
        Tag = 59
        Caption = 'Vistoria'
        OnClick = England1Click
      end
      object Vistoria2: TMenuItem
        Tag = 60
        Caption = 'Western Australia'
        OnClick = England1Click
      end
    end
    object Brazil1: TMenuItem
      Caption = 'Brazil'
      object N11: TMenuItem
        Tag = 122
        Caption = 'Acre'
        OnClick = England1Click
      end
      object Alagoas1: TMenuItem
        Tag = 123
        Caption = 'Alagoas'
        OnClick = England1Click
      end
      object Alagoas2: TMenuItem
        Tag = 124
        Caption = 'Amap'#225
        OnClick = England1Click
      end
      object Amazonas1: TMenuItem
        Tag = 125
        Caption = 'Amazonas'
        OnClick = England1Click
      end
      object Amazonas2: TMenuItem
        Tag = 126
        Caption = 'Bahia'
        OnClick = England1Click
      end
      object Cear1: TMenuItem
        Tag = 127
        Caption = 'Cear'#225
        OnClick = England1Click
      end
      object Cear2: TMenuItem
        Tag = 128
        Caption = 'Esp'#237'rito Santo'
        OnClick = England1Click
      end
      object Gois1: TMenuItem
        Tag = 129
        Caption = 'Goi'#225's'
        OnClick = England1Click
      end
      object Maranho1: TMenuItem
        Tag = 130
        Caption = 'Maranh'#227'o'
        OnClick = England1Click
      end
      object MatoGrosso1: TMenuItem
        Tag = 131
        Caption = 'Mato Grosso'
        OnClick = England1Click
      end
      object MatoGrossodoSul1: TMenuItem
        Tag = 132
        Caption = 'Mato Grosso do Sul'
        OnClick = England1Click
      end
      object MinasGerais1: TMenuItem
        Tag = 133
        Caption = 'Minas Gerais'
        OnClick = England1Click
      end
      object Par1: TMenuItem
        Tag = 134
        Caption = 'Par'#225
        OnClick = England1Click
      end
      object Paraba1: TMenuItem
        Tag = 135
        Caption = 'Para'#237'ba'
        OnClick = England1Click
      end
      object Paran1: TMenuItem
        Tag = 136
        Caption = 'Paran'#225
        OnClick = England1Click
      end
      object Pernambuco1: TMenuItem
        Tag = 137
        Caption = 'Pernambuco'
        OnClick = England1Click
      end
      object Piau1: TMenuItem
        Tag = 138
        Caption = 'Piau'#237
        OnClick = England1Click
      end
      object RiodeJaneiro1: TMenuItem
        Tag = 139
        Caption = 'Rio de Janeiro'
        OnClick = England1Click
      end
      object RioGrandedoNorte1: TMenuItem
        Tag = 140
        Caption = 'Rio Grande do Norte'
        OnClick = England1Click
      end
      object RioGrandedoSul1: TMenuItem
        Tag = 141
        Caption = 'Rio Grande do Sul'
        OnClick = England1Click
      end
      object Rondnia1: TMenuItem
        Tag = 142
        Caption = 'Rond'#244'nia'
        OnClick = England1Click
      end
      object Roraima1: TMenuItem
        Tag = 143
        Caption = 'Roraima'
        OnClick = England1Click
      end
      object SantaCatarina1: TMenuItem
        Tag = 144
        Caption = 'Santa Catarina'
        OnClick = England1Click
      end
      object SoPaulo1: TMenuItem
        Tag = 145
        Caption = 'S'#227'o Paulo'
        OnClick = England1Click
      end
      object Sergipe1: TMenuItem
        Tag = 146
        Caption = 'Sergipe'
        OnClick = England1Click
      end
      object ocantins1: TMenuItem
        Tag = 147
        Caption = 'Tocantins'
        OnClick = England1Click
      end
    end
    object Canada1: TMenuItem
      Caption = 'Canada'
      object Alberta1: TMenuItem
        Tag = 61
        Caption = 'Alberta'
        OnClick = England1Click
      end
      object Alberta2: TMenuItem
        Tag = 62
        Caption = 'British Columbia'
        OnClick = England1Click
      end
      object Manitoba1: TMenuItem
        Tag = 63
        Caption = 'Manitoba'
        OnClick = England1Click
      end
      object Manitoba2: TMenuItem
        Tag = 64
        Caption = 'New Brunswick'
        OnClick = England1Click
      end
      object NewfoundlandandLabrador1: TMenuItem
        Tag = 65
        Caption = 'Newfoundland and Labrador'
        OnClick = England1Click
      end
      object NewfoundlandandLabrador2: TMenuItem
        Tag = 66
        Caption = 'Nova Scotia'
        OnClick = England1Click
      end
      object Ontario1: TMenuItem
        Tag = 67
        Caption = 'Ontario'
        OnClick = England1Click
      end
      object PrinceEdwardIsland1: TMenuItem
        Tag = 68
        Caption = 'Prince Edward Island'
        OnClick = England1Click
      end
      object Quebec1: TMenuItem
        Tag = 69
        Caption = 'Quebec'
        OnClick = England1Click
      end
      object Quebec2: TMenuItem
        Tag = 70
        Caption = 'Saskatchewan'
        OnClick = England1Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object NorthwestTerritories1: TMenuItem
        Tag = 71
        Caption = 'Northwest Territories'
        OnClick = England1Click
      end
      object NorthwestTerritories2: TMenuItem
        Tag = 72
        Caption = 'Nunavut'
        OnClick = England1Click
      end
      object Ontario2: TMenuItem
        Tag = 73
        Caption = 'Yukon'
        OnClick = England1Click
      end
    end
    object France1: TMenuItem
      Caption = 'France'
      object Ain1: TMenuItem
        Tag = 90
        Caption = 'Auvergne-Rh'#244'ne-Alpes'
        OnClick = England1Click
      end
      object Ain2: TMenuItem
        Tag = 91
        Caption = 'Bourgogne-Franche-Comt'#233
        OnClick = England1Click
      end
      object Bretagne1: TMenuItem
        Tag = 92
        Caption = 'Bretagne'
        OnClick = England1Click
      end
      object CentreValdeLoire1: TMenuItem
        Tag = 93
        Caption = 'Centre-Val de Loire'
        OnClick = England1Click
      end
      object Corse1: TMenuItem
        Tag = 94
        Caption = 'Corse'
        OnClick = England1Click
      end
      object Corse2: TMenuItem
        Tag = 95
        Caption = 'Grand-Est'
        OnClick = England1Click
      end
      object HautsdeFrance1: TMenuItem
        Tag = 96
        Caption = 'Hauts-de-France'
        OnClick = England1Click
      end
      object HautsdeFrance2: TMenuItem
        Tag = 97
        Caption = #206'le-de-France'
        OnClick = England1Click
      end
      object Normandie1: TMenuItem
        Tag = 98
        Caption = 'Normandie'
        OnClick = England1Click
      end
      object Normandie2: TMenuItem
        Tag = 99
        Caption = 'Nouvelle-Aquitaine'
        OnClick = England1Click
      end
      object Occitanie1: TMenuItem
        Tag = 100
        Caption = 'Occitanie'
        OnClick = England1Click
      end
      object Occitanie2: TMenuItem
        Tag = 101
        Caption = 'Pays-de-la-Loire'
        OnClick = England1Click
      end
      object ProvenceAlpesCtedAzur1: TMenuItem
        Tag = 102
        Caption = 'Provence-Alpes-C'#244'te-d'#8217'Azur'
        OnClick = England1Click
      end
    end
    object NewZealand1: TMenuItem
      Caption = 'New Zealand'
      object Auckland1: TMenuItem
        Tag = 74
        Caption = 'Auckland'
        OnClick = England1Click
      end
      object Auckland2: TMenuItem
        Tag = 75
        Caption = 'Bay of Plenty'
        OnClick = England1Click
      end
      object Canterbury1: TMenuItem
        Tag = 76
        Caption = 'Canterbury'
        OnClick = England1Click
      end
      object Canterbury2: TMenuItem
        Tag = 77
        Caption = 'Gisborne'
        OnClick = England1Click
      end
      object HawkesBay1: TMenuItem
        Tag = 78
        Caption = 'Hawke'#39's Bay'
        OnClick = England1Click
      end
      object HawkesBay2: TMenuItem
        Tag = 79
        Caption = 'Marlborough'
        OnClick = England1Click
      end
      object ManawatuWanganui1: TMenuItem
        Tag = 80
        Caption = 'Manawatu-Wanganui'
        OnClick = England1Click
      end
      object ManawatuWanganui2: TMenuItem
        Tag = 81
        Caption = 'Nelson'
        OnClick = England1Click
      end
      object Northland1: TMenuItem
        Tag = 82
        Caption = 'Northland'
        OnClick = England1Click
      end
      object Northland2: TMenuItem
        Tag = 83
        Caption = 'Otago'
        OnClick = England1Click
      end
      object Southland1: TMenuItem
        Tag = 84
        Caption = 'Southland'
        OnClick = England1Click
      end
      object Southland2: TMenuItem
        Tag = 85
        Caption = 'Tasman'
        OnClick = England1Click
      end
      object aranaki1: TMenuItem
        Tag = 86
        Caption = 'Taranaki'
        OnClick = England1Click
      end
      object aranaki2: TMenuItem
        Tag = 87
        Caption = 'Waikato'
        OnClick = England1Click
      end
      object Wellington1: TMenuItem
        Tag = 88
        Caption = 'Wellington'
        OnClick = England1Click
      end
      object Wellington2: TMenuItem
        Tag = 89
        Caption = 'West Coast'
        OnClick = England1Click
      end
    end
    object Spain1: TMenuItem
      Caption = 'Spain'
      object Andaluca1: TMenuItem
        Tag = 103
        Caption = 'Andaluc'#237'a'
        OnClick = England1Click
      end
      object Andaluca2: TMenuItem
        Tag = 104
        Caption = 'Arag'#243'n'
        OnClick = England1Click
      end
      object AsturiasPrincipadode1: TMenuItem
        Tag = 105
        Caption = 'Asturias, Principado de'
        OnClick = England1Click
      end
      object AsturiasPrincipadode2: TMenuItem
        Tag = 106
        Caption = 'Canarias'
        OnClick = England1Click
      end
      object Cantabria1: TMenuItem
        Tag = 107
        Caption = 'Cantabria'
        OnClick = England1Click
      end
      object Cantabria2: TMenuItem
        Tag = 108
        Caption = 'Castilla y Le'#243'n'
        OnClick = England1Click
      end
      object CastillaLaMancha1: TMenuItem
        Tag = 109
        Caption = 'Castilla-La Mancha'
        OnClick = England1Click
      end
      object CatalunyacaCatalua1: TMenuItem
        Tag = 110
        Caption = 'Catalunya [Catalu'#241'a]'
        OnClick = England1Click
      end
      object CatalunyacaCatalua2: TMenuItem
        Tag = 111
        Caption = 'Ceuta'
        OnClick = England1Click
      end
      object Extremadura1: TMenuItem
        Tag = 112
        Caption = 'Extremadura'
        OnClick = England1Click
      end
      object Extremadura2: TMenuItem
        Tag = 113
        Caption = 'Galicia [Galicia]'
        OnClick = England1Click
      end
      object llesBalearscaIslasBaleares1: TMenuItem
        Tag = 114
        Caption = 'lles Balears [Islas Baleares]'
        OnClick = England1Click
      end
      object llesBalearscaIslasBaleares2: TMenuItem
        Tag = 115
        Caption = 'La Rioja'
        OnClick = England1Click
      end
      object MadridComunidadde1: TMenuItem
        Tag = 116
        Caption = 'Madrid, Comunidad de'
        OnClick = England1Click
      end
      object MadridComunidadde2: TMenuItem
        Tag = 117
        Caption = 'Melilla'
        OnClick = England1Click
      end
      object MurciaReginde1: TMenuItem
        Tag = 118
        Caption = 'Murcia, Regi'#243'n de'
        OnClick = England1Click
      end
      object MurciaReginde2: TMenuItem
        Tag = 119
        Caption = 'Navarra, Comunidad Foral de'
        OnClick = England1Click
      end
      object asVasco1: TMenuItem
        Tag = 120
        Caption = 'Pa'#237's Vasco'
        OnClick = England1Click
      end
      object ValencianaComunitat1: TMenuItem
        Tag = 121
        Caption = 'Valenciana, Comunitat'
        OnClick = England1Click
      end
    end
    object UnitedKingdom1: TMenuItem
      Caption = 'United Kingdom'
      object England1: TMenuItem
        Caption = 'England'
        OnClick = England1Click
      end
      object NorthernIreland1: TMenuItem
        Tag = 1
        Caption = 'Northern Ireland'
        OnClick = England1Click
      end
      object England2: TMenuItem
        Tag = 2
        Caption = 'Scotland'
        OnClick = England1Click
      end
      object NorthernIreland2: TMenuItem
        Tag = 3
        Caption = 'Wales'
        OnClick = England1Click
      end
    end
    object UnitedStatesofAmerica1: TMenuItem
      Tag = 60
      Caption = 'United States of America'
      object Alabama1: TMenuItem
        Tag = 4
        Caption = 'Alabama'
        OnClick = England1Click
      end
      object Alabama2: TMenuItem
        Tag = 5
        Caption = 'Alaska'
        OnClick = England1Click
      end
      object Arizona1: TMenuItem
        Tag = 6
        Caption = 'Arizona'
        OnClick = England1Click
      end
      object Arizona2: TMenuItem
        Tag = 7
        Caption = 'Arkansas'
        OnClick = England1Click
      end
      object California1: TMenuItem
        Tag = 8
        Caption = 'California'
        OnClick = England1Click
      end
      object California2: TMenuItem
        Tag = 9
        Caption = 'Colorado'
        OnClick = England1Click
      end
      object Connecticut1: TMenuItem
        Tag = 10
        Caption = 'Connecticut'
        OnClick = England1Click
      end
      object Connecticut2: TMenuItem
        Tag = 11
        Caption = 'Delaware'
        OnClick = England1Click
      end
      object Florida1: TMenuItem
        Tag = 12
        Caption = 'Florida'
        OnClick = England1Click
      end
      object Florida2: TMenuItem
        Tag = 13
        Caption = 'Georgia'
        OnClick = England1Click
      end
      object Hawaii1: TMenuItem
        Tag = 14
        Caption = 'Hawaii'
        OnClick = England1Click
      end
      object Hawaii2: TMenuItem
        Tag = 15
        Caption = 'Idaho'
        OnClick = England1Click
      end
      object Illinois1: TMenuItem
        Tag = 16
        Caption = 'Illinois'
        OnClick = England1Click
      end
      object Illinois2: TMenuItem
        Tag = 17
        Caption = 'Indiana'
        OnClick = England1Click
      end
      object Iowa1: TMenuItem
        Tag = 18
        Caption = 'Iowa'
        OnClick = England1Click
      end
      object Iowa2: TMenuItem
        Tag = 19
        Caption = 'Kansas'
        OnClick = England1Click
      end
      object Kentucky1: TMenuItem
        Tag = 20
        Caption = 'Kentucky'
        OnClick = England1Click
      end
      object Kentucky2: TMenuItem
        Tag = 21
        Caption = 'Louisiana'
        OnClick = England1Click
      end
      object Maine1: TMenuItem
        Tag = 22
        Caption = 'Maine'
        OnClick = England1Click
      end
      object Maine2: TMenuItem
        Tag = 23
        Caption = 'Maryland'
        OnClick = England1Click
      end
      object Massachusetts1: TMenuItem
        Tag = 24
        Caption = 'Massachusetts'
        OnClick = England1Click
      end
      object Massachusetts2: TMenuItem
        Tag = 25
        Caption = 'Michigan'
        OnClick = England1Click
      end
      object Minnesota1: TMenuItem
        Tag = 26
        Caption = 'Minnesota'
        OnClick = England1Click
      end
      object Minnesota2: TMenuItem
        Tag = 27
        Caption = 'Mississippi'
        OnClick = England1Click
      end
      object Missouri1: TMenuItem
        Tag = 28
        Caption = 'Missouri'
        OnClick = England1Click
      end
      object Missouri2: TMenuItem
        Tag = 29
        Caption = 'Montana'
        OnClick = England1Click
      end
      object Nebraska1: TMenuItem
        Tag = 30
        Caption = 'Nebraska'
        OnClick = England1Click
      end
      object Nevada1: TMenuItem
        Tag = 31
        Caption = 'Nevada'
        OnClick = England1Click
      end
      object Nebraska2: TMenuItem
        Tag = 32
        Caption = 'New Hampshire'
        OnClick = England1Click
      end
      object NewJersey1: TMenuItem
        Tag = 33
        Caption = 'New Jersey'
        OnClick = England1Click
      end
      object NewJersey2: TMenuItem
        Tag = 34
        Caption = 'New Mexico'
        OnClick = England1Click
      end
      object NewYork1: TMenuItem
        Tag = 35
        Caption = 'New York'
        OnClick = England1Click
      end
      object NewYork2: TMenuItem
        Tag = 36
        Caption = 'North Carolina'
        OnClick = England1Click
      end
      object NorthDakota1: TMenuItem
        Tag = 37
        Caption = 'North Dakota'
        OnClick = England1Click
      end
      object NorthDakota2: TMenuItem
        Tag = 38
        Caption = 'Ohio'
        OnClick = England1Click
      end
      object Oklahoma1: TMenuItem
        Tag = 39
        Caption = 'Oklahoma'
        OnClick = England1Click
      end
      object Oklahoma2: TMenuItem
        Tag = 40
        Caption = 'Oregon'
        OnClick = England1Click
      end
      object Pennsylvania1: TMenuItem
        Tag = 41
        Caption = 'Pennsylvania'
        OnClick = England1Click
      end
      object Pennsylvania2: TMenuItem
        Tag = 42
        Caption = 'Rhode Island'
        OnClick = England1Click
      end
      object SouthCarolina1: TMenuItem
        Tag = 43
        Caption = 'South Carolina'
        OnClick = England1Click
      end
      object SouthCarolina2: TMenuItem
        Tag = 44
        Caption = 'South Dakota'
        OnClick = England1Click
      end
      object ennessee1: TMenuItem
        Tag = 45
        Caption = 'Tennessee'
        OnClick = England1Click
      end
      object ennessee2: TMenuItem
        Tag = 46
        Caption = 'Texas'
        OnClick = England1Click
      end
      object Utah1: TMenuItem
        Tag = 47
        Caption = 'Utah'
        OnClick = England1Click
      end
      object Utah2: TMenuItem
        Tag = 48
        Caption = 'Vermont'
        OnClick = England1Click
      end
      object Virginia1: TMenuItem
        Tag = 49
        Caption = 'Virginia'
        OnClick = England1Click
      end
      object Virginia2: TMenuItem
        Tag = 50
        Caption = 'Washington'
        OnClick = England1Click
      end
      object WestVirginia1: TMenuItem
        Tag = 51
        Caption = 'West Virginia'
        OnClick = England1Click
      end
      object WestVirginia2: TMenuItem
        Tag = 52
        Caption = 'Wisconsin'
        OnClick = England1Click
      end
      object Wyoming1: TMenuItem
        Tag = 53
        Caption = 'Wyoming'
        OnClick = England1Click
      end
      object Wyoming2: TMenuItem
        Caption = '-'
      end
      object DisctrictofColumbia1: TMenuItem
        Tag = 54
        Caption = 'Disctrict of Columbia'
        OnClick = England1Click
      end
    end
  end
  object puDirection: TPopupMenu
    Left = 536
    object SetDirection1: TMenuItem
      Caption = 'Set Direction'
      Enabled = False
    end
    object SetDirection2: TMenuItem
      Caption = '-'
    end
    object Fromangle1: TMenuItem
      Caption = 'From angle'
      object N01: TMenuItem
        Caption = '0'#176
        OnClick = N9Click
      end
      object N02: TMenuItem
        Tag = 2
        Caption = '45'#176
        OnClick = N9Click
      end
      object N901: TMenuItem
        Tag = 4
        Caption = '90'#176
        OnClick = N9Click
      end
      object N902: TMenuItem
        Tag = 6
        Caption = '135'#176
        OnClick = N9Click
      end
      object N1801: TMenuItem
        Tag = 8
        Caption = '180'#176
        OnClick = N9Click
      end
      object N1802: TMenuItem
        Tag = 10
        Caption = '225'#176
        OnClick = N9Click
      end
      object N2701: TMenuItem
        Tag = 12
        Caption = '270'#176
        OnClick = N9Click
      end
      object N2702: TMenuItem
        Tag = 14
        Caption = '315'#176
        OnClick = N9Click
      end
    end
    object Frombearing1: TMenuItem
      Caption = 'From bearing'
      object N9: TMenuItem
        Caption = 'N'
        OnClick = N9Click
      end
      object N10: TMenuItem
        Tag = 1
        Caption = 'NNE'
        OnClick = N9Click
      end
      object NE1: TMenuItem
        Tag = 2
        Caption = 'NE'
        OnClick = N9Click
      end
      object NE2: TMenuItem
        Tag = 3
        Caption = 'ENE'
        OnClick = N9Click
      end
      object E1: TMenuItem
        Tag = 4
        Caption = 'E'
        OnClick = N9Click
      end
      object E2: TMenuItem
        Tag = 5
        Caption = 'ESE'
        OnClick = N9Click
      end
      object SE1: TMenuItem
        Tag = 6
        Caption = 'SE'
        OnClick = N9Click
      end
      object SE2: TMenuItem
        Tag = 7
        Caption = 'SSE'
        OnClick = N9Click
      end
      object S1: TMenuItem
        Tag = 8
        Caption = 'S'
        OnClick = N9Click
      end
      object S2: TMenuItem
        Tag = 9
        Caption = 'SSW'
        OnClick = N9Click
      end
      object SW1: TMenuItem
        Tag = 10
        Caption = 'SW'
        OnClick = N9Click
      end
      object SW2: TMenuItem
        Tag = 11
        Caption = 'WSW'
        OnClick = N9Click
      end
      object W1: TMenuItem
        Tag = 12
        Caption = 'W'
        OnClick = N9Click
      end
      object W2: TMenuItem
        Tag = 13
        Caption = 'WNW'
        OnClick = N9Click
      end
      object NW1: TMenuItem
        Tag = 14
        Caption = 'NW'
        OnClick = N9Click
      end
      object NW2: TMenuItem
        Tag = 15
        Caption = 'NNW'
        OnClick = N9Click
      end
    end
  end
  object puRange: TPopupMenu
    Left = 592
    object Range1: TMenuItem
      Caption = 'Range'
      Enabled = False
    end
    object N19: TMenuItem
      Caption = '-'
    end
    object miRange1: TMenuItem
      Tag = 50
      Caption = 'Short (50nm)'
      OnClick = miRange1Click
    end
    object Cityhop100nm1: TMenuItem
      Tag = 100
      Caption = 'City hop (100nm)'
      OnClick = miRange1Click
    end
    object Crosscountry200nm1: TMenuItem
      Tag = 200
      Caption = 'Cross country (200nm)'
      OnClick = miRange1Click
    end
    object Domestic500nm1: TMenuItem
      Tag = 500
      Caption = 'Domestic (500nm)'
      OnClick = miRange1Click
    end
    object International1500nm1: TMenuItem
      Tag = 800
      Caption = 'Short-haul (800nm)'
      OnClick = miRange1Click
    end
    object Mediumhaul1: TMenuItem
      Tag = 1800
      Caption = 'Medium-haul (1800nm)'
      OnClick = miRange1Click
    end
    object Longhaul26001: TMenuItem
      Tag = 2600
      Caption = 'Long-haul (2600nm)'
      OnClick = miRange1Click
    end
    object International5000nm1: TMenuItem
      Tag = 5000
      Caption = 'International (5000nm)'
      OnClick = miRange1Click
    end
  end
  object puLongitude: TPopupMenu
    Left = 656
    object Longitude1: TMenuItem
      Caption = 'Longitude'
      Enabled = False
    end
    object N20: TMenuItem
      Caption = '-'
    end
    object AustraliaCanberra1: TMenuItem
      Caption = 'Australia (Canberra)'
      OnClick = AustraliaCanberra1Click
    end
    object AustraliaCanberra2: TMenuItem
      Tag = 1
      Caption = 'Austria (Vienna)'
      OnClick = AustraliaCanberra1Click
    end
    object BahamasNassau1: TMenuItem
      Tag = 2
      Caption = 'Bahamas (Nassau)'
      OnClick = AustraliaCanberra1Click
    end
    object SenegalDakar2: TMenuItem
      Tag = 3
      Caption = 'Brazil (Recife)'
      OnClick = AustraliaCanberra1Click
    end
    object CanadaOttawa1: TMenuItem
      Tag = 4
      Caption = 'Canada (Ottawa)'
      OnClick = AustraliaCanberra1Click
    end
    object CanadaVancouver1: TMenuItem
      Tag = 5
      Caption = 'Canada (Vancouver)'
      OnClick = AustraliaCanberra1Click
    end
    object CocosIslands1: TMenuItem
      Tag = 6
      Caption = 'Cocos Islands (West Island)'
      OnClick = AustraliaCanberra1Click
    end
    object CookIslandsAvarua1: TMenuItem
      Tag = 7
      Caption = 'Cook Islands (Avarua)'
      OnClick = AustraliaCanberra1Click
    end
    object CaymanIslandsGeorgeTown1: TMenuItem
      Tag = 8
      Caption = 'Cayman Islands (George Town)'
      OnClick = AustraliaCanberra1Click
    end
    object CyprusNicosia1: TMenuItem
      Tag = 9
      Caption = 'Cyprus (Nicosia)'
      OnClick = AustraliaCanberra1Click
    end
    object DenmarkCopenhagen1: TMenuItem
      Tag = 10
      Caption = 'Denmark (Copenhagen)'
      OnClick = AustraliaCanberra1Click
    end
    object FijiSuva1: TMenuItem
      Tag = 11
      Caption = 'Fiji (Suva)'
      OnClick = AustraliaCanberra1Click
    end
    object FranceParis1: TMenuItem
      Tag = 12
      Caption = 'France (Paris)'
      OnClick = AustraliaCanberra1Click
    end
    object GermanyBerlin1: TMenuItem
      Tag = 13
      Caption = 'Germany (Berlin)'
      OnClick = AustraliaCanberra1Click
    end
    object IcelandReykjavk1: TMenuItem
      Tag = 14
      Caption = 'Iceland (Reykjav'#237'k)'
      OnClick = AustraliaCanberra1Click
    end
    object ItalyRome1: TMenuItem
      Tag = 15
      Caption = 'Italy (Rome)'
      OnClick = AustraliaCanberra1Click
    end
    object JapanTokyo1: TMenuItem
      Tag = 16
      Caption = 'Japan (Tokyo)'
      OnClick = AustraliaCanberra1Click
    end
    object UkraineKyiv2: TMenuItem
      Tag = 17
      Caption = 'Oman (Muscat)'
      OnClick = AustraliaCanberra1Click
    end
    object PolandWarsaw1: TMenuItem
      Tag = 18
      Caption = 'Poland (Warsaw)'
      OnClick = AustraliaCanberra1Click
    end
    object SenegalDakar1: TMenuItem
      Tag = 19
      Caption = 'Senegal (Dakar)'
      OnClick = AustraliaCanberra1Click
    end
    object SolomonIslands1: TMenuItem
      Tag = 20
      Caption = 'Solomon Islands (Honiara)'
      OnClick = AustraliaCanberra1Click
    end
    object urkiyeAnkara1: TMenuItem
      Tag = 21
      Caption = 'Turkiye (Ankara)'
      OnClick = AustraliaCanberra1Click
    end
    object UkraineKyiv1: TMenuItem
      Tag = 22
      Caption = 'Ukraine (Kyiv)'
      OnClick = AustraliaCanberra1Click
    end
    object UnitedKingdomLondon1: TMenuItem
      Tag = 23
      Caption = 'United Kingdom (London)'
      OnClick = AustraliaCanberra1Click
    end
    object USAAnchorage1: TMenuItem
      Tag = 24
      Caption = 'USA (Anchorage)'
      OnClick = AustraliaCanberra1Click
    end
    object USA2: TMenuItem
      Tag = 25
      Caption = 'USA (Boston)'
      OnClick = AustraliaCanberra1Click
    end
    object USAWalesAlaska1: TMenuItem
      Tag = 26
      Caption = 'USA (Wales, Alaska)'
      OnClick = AustraliaCanberra1Click
    end
  end
  object puLatitude: TPopupMenu
    Left = 720
    object MenuItem1: TMenuItem
      Caption = 'Latitude'
      Enabled = False
    end
    object MenuItem2: TMenuItem
      Caption = '-'
    end
    object asmaniaHobart2: TMenuItem
      Caption = 'Australia (Darwin)'
      OnClick = asmaniaHobart2Click
    end
    object BarbadosBridgetown1: TMenuItem
      Tag = 1
      Caption = 'Barbados (Bridgetown)'
      OnClick = asmaniaHobart2Click
    end
    object SvalbardandJanMayenLongyearbyen2: TMenuItem
      Tag = 2
      Caption = 'Bolivia (La Paz)'
      OnClick = asmaniaHobart2Click
    end
    object CanadaVancouver2: TMenuItem
      Tag = 3
      Caption = 'Canada (Vancouver)'
      OnClick = asmaniaHobart2Click
    end
    object CameroonYaounde2: TMenuItem
      Tag = 4
      Caption = 'Cuba (Havana)'
      OnClick = asmaniaHobart2Click
    end
    object DenmarkCopenhagen2: TMenuItem
      Tag = 5
      Caption = 'Denmark (Copenhagen)'
      OnClick = asmaniaHobart2Click
    end
    object Equator1: TMenuItem
      Tag = 6
      Caption = 'Equator'
      OnClick = asmaniaHobart2Click
    end
    object FaroeIslandsTorshavn1: TMenuItem
      Tag = 7
      Caption = 'Faroe Islands (Torshavn)'
      OnClick = asmaniaHobart2Click
    end
    object HeardIslandandMcDonaldIslands1: TMenuItem
      Tag = 8
      Caption = 'Heard Island and McDonald Islands'
      OnClick = asmaniaHobart2Click
    end
    object CanadaVancouver3: TMenuItem
      Tag = 9
      Caption = 'Iceland (Reykjavik)'
      OnClick = asmaniaHobart2Click
    end
    object MarshallIslandsMajuro2: TMenuItem
      Tag = 10
      Caption = 'Japan (Tokyo)'
      OnClick = asmaniaHobart2Click
    end
    object MarshallIslandsMajuro1: TMenuItem
      Tag = 11
      Caption = 'Marshall Islands (Majuro)'
      OnClick = asmaniaHobart2Click
    end
    object MoroccoTangier1: TMenuItem
      Tag = 12
      Caption = 'Morocco (Tangier)'
      OnClick = asmaniaHobart2Click
    end
    object MoroccoTangier2: TMenuItem
      Tag = 13
      Caption = 'South Africa (Cape Town)'
      OnClick = asmaniaHobart2Click
    end
    object SvalbardandJanMayenLongyearbyen1: TMenuItem
      Tag = 14
      Caption = 'Svalbard and Jan Mayen (Longyearbyen)'
      OnClick = asmaniaHobart2Click
    end
    object asmaniaHobart1: TMenuItem
      Tag = 15
      Caption = 'Tasmania (Hobart)'
      OnClick = asmaniaHobart2Click
    end
    object BarbadosBridgetown2: TMenuItem
      Tag = 16
      Caption = 'USA (New York)'
      OnClick = asmaniaHobart2Click
    end
  end
  object puPercentage: TPopupMenu
    Left = 792
    object Excessrange1: TMenuItem
      Caption = 'Excess range'
      Enabled = False
    end
    object N21: TMenuItem
      Caption = '-'
    end
    object N51: TMenuItem
      Tag = 5
      Caption = '5%'
      OnClick = miRange1Click
    end
    object N101: TMenuItem
      Tag = 10
      Caption = '10%'
      OnClick = miRange1Click
    end
    object N151: TMenuItem
      Tag = 15
      Caption = '15%'
      OnClick = miRange1Click
    end
    object N201: TMenuItem
      Tag = 20
      Caption = '20%'
      OnClick = miRange1Click
    end
    object N251: TMenuItem
      Tag = 25
      Caption = '25%'
      OnClick = miRange1Click
    end
    object N252: TMenuItem
      Tag = 30
      Caption = '30%'
      OnClick = miRange1Click
    end
    object N502: TMenuItem
      Tag = 40
      Caption = '40%'
      OnClick = miRange1Click
    end
    object N501: TMenuItem
      Tag = 50
      Caption = '50%'
      OnClick = miRange1Click
    end
    object N751: TMenuItem
      Tag = 75
      Caption = '75%'
      OnClick = miRange1Click
    end
    object N1001: TMenuItem
      Tag = 100
      Caption = '100%'
      OnClick = miRange1Click
    end
  end
end
