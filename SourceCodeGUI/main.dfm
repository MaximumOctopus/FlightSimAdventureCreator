object Form1: TForm1
  Left = 0
  Top = 0
  Hint = 'generate random routes!'
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 751
  ClientWidth = 1217
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label19: TLabel
    Left = 797
    Top = 155
    Width = 103
    Height = 13
    Caption = 'Generated Routes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Image1: TImage
    Left = 1090
    Top = 154
    Width = 16
    Height = 16
    AutoSize = True
    Picture.Data = {
      07544269746D617036030000424D360300000000000036000000280000001000
      000010000000010018000000000000030000120B0000120B0000000000000000
      0000FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFCFCFCD4D4D4FF00FFFF00FFFF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      F8F8F81010106C6C6CFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFDBDBDB000000757575FF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FF222222888888FF00FF6666666767676666666666666767
      676666666666666666666666666666666767676767677E7E7E5D5D5D0000007F
      7F7F666666666666676767666666666666666666676767666666666666676767
      6767676666667E7E7E5C5C5C0000007F7F7FFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF212121888888FF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFDADADA000000757575FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFF8F8F80F0F0F6B6B6BFF00FFFF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FCFCFCD4D4D4FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF
      FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
      FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
      00FF}
    Transparent = True
  end
  object gbAircraft: TGroupBox
    Left = 8
    Top = 47
    Width = 375
    Height = 329
    Caption = 'Aircraft'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 11
    object Bevel12: TBevel
      Left = 15
      Top = 144
      Width = 346
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
      Left = 15
      Top = 22
      Width = 346
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
      Left = 177
      Top = 189
      Width = 111
      Height = 13
      Caption = 'Aircraft Range Modifier'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label25: TLabel
      Left = 336
      Top = 189
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
      Width = 18
      Height = 86
      Shape = bsLeftLine
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
      Left = 17
      Top = 234
      Width = 346
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
      Top = 186
      Width = 36
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 16
      Text = '0'
      OnChange = cbAircraftTypePropsClick
      OnExit = eAircraftRangeModifierExit
    end
    object bRandomAircraft: TButton
      Left = 245
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
  object GroupBox3: TGroupBox
    Left = 8
    Top = 382
    Width = 375
    Height = 344
    Caption = 'Route'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object Bevel10: TBevel
      Left = 15
      Top = 207
      Width = 346
      Height = 63
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel9: TBevel
      Left = 15
      Top = 87
      Width = 346
      Height = 114
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel7: TBevel
      Left = 15
      Top = 18
      Width = 346
      Height = 63
      Shape = bsFrame
      Style = bsRaised
    end
    object Label4: TLabel
      Left = 34
      Top = 218
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
    object Label9: TLabel
      Left = 34
      Top = 27
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
      Left = 151
      Top = 27
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
    object Label11: TLabel
      Left = 34
      Top = 98
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
    object Label12: TLabel
      Left = 34
      Top = 125
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
    object Label13: TLabel
      Left = 151
      Top = 98
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
    object Label14: TLabel
      Left = 151
      Top = 125
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
    object Label15: TLabel
      Left = 132
      Top = 198
      Width = 3
      Height = 13
      Caption = #39
    end
    object Label16: TLabel
      Left = 151
      Top = 54
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
    object Label17: TLabel
      Left = 34
      Top = 245
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
      Left = 15
      Top = 276
      Width = 346
      Height = 43
      Shape = bsFrame
      Style = bsRaised
    end
    object Label28: TLabel
      Left = 151
      Top = 290
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
    object Label29: TLabel
      Left = 34
      Top = 153
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
    object lDistanceStartEnd: TLabel
      Left = 34
      Top = 178
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
    object Label32: TLabel
      Left = 180
      Top = 290
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
    object eLegs: TEdit
      Left = 109
      Top = 215
      Width = 36
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
      TabOrder = 0
      Text = '0'
      OnExit = eLegsExit
    end
    object eRange: TEdit
      Left = 109
      Top = 24
      Width = 36
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
      TabOrder = 1
      Text = '100'
      OnExit = eLegsExit
    end
    object eStartAirportICAO: TEdit
      Left = 109
      Top = 95
      Width = 36
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      PopupMenu = puSelectICAO
      TabOrder = 2
      OnExit = eEndAirportICAOExit
    end
    object eEndAirportICAO: TEdit
      Left = 109
      Top = 122
      Width = 36
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      PopupMenu = puSelectICAO
      TabOrder = 3
      OnExit = eEndAirportICAOExit
    end
    object cbUseAircraftRange: TCheckBox
      Left = 216
      Top = 26
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
      TabOrder = 4
    end
    object cbStartFromFavourite: TCheckBox
      Left = 216
      Top = 97
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
      TabOrder = 5
    end
    object cbUseDirection: TCheckBox
      Left = 34
      Top = 289
      Width = 69
      Height = 17
      Caption = 'Direction'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = cbUseDirectionClick
    end
    object eDirection: TEdit
      Left = 109
      Top = 287
      Width = 36
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
      TabOrder = 7
      Text = '0'
      OnExit = eDirectionExit
    end
    object cbAllowExcessRange: TCheckBox
      Left = 216
      Top = 53
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
      TabOrder = 8
    end
    object eCount: TEdit
      Left = 109
      Top = 242
      Width = 36
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
      TabOrder = 9
      Text = '0'
      OnExit = eLegsExit
    end
    object eFlightTime: TEdit
      Left = 109
      Top = 51
      Width = 36
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
      TabOrder = 10
      Text = '60'
      OnExit = eLegsExit
    end
    object cbUseFlightTime: TCheckBox
      Left = 34
      Top = 51
      Width = 67
      Height = 17
      Caption = 'Flight time'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
      OnClick = cbUseFlightTimeClick
    end
    object cbEndAtFavourite: TCheckBox
      Left = 216
      Top = 124
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
      TabOrder = 12
    end
    object rbStartEndLegs: TRadioButton
      Left = 215
      Top = 151
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
      TabOrder = 13
      TabStop = True
      OnClick = cbContinentAFClick
    end
    object rbStartEndRange: TRadioButton
      Left = 262
      Top = 151
      Width = 51
      Height = 17
      Caption = 'Range'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 14
      OnClick = cbContinentAFClick
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1217
    Height = 41
    ButtonHeight = 38
    ButtonWidth = 39
    Caption = 'ToolBar1'
    Images = ImageList1
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    object tbSave: TToolButton
      Left = 0
      Top = 0
      Hint = 'Save current configuration'
      Caption = 'tbSave'
      ImageIndex = 0
      OnClick = tbSaveClick
    end
    object tbOpen: TToolButton
      Left = 39
      Top = 0
      Hint = 'Load configuration'
      Caption = 'tbOpen'
      ImageIndex = 1
      OnClick = tbOpenClick
    end
    object ToolButton3: TToolButton
      Left = 78
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object tbReset: TToolButton
      Left = 86
      Top = 0
      Hint = 'Reset display to defaults'
      ImageIndex = 2
      OnClick = tbResetClick
    end
    object ToolButton1: TToolButton
      Left = 125
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 3
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
    Top = 732
    Width = 1217
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object sgRoutes: TStringGrid
    Left = 797
    Top = 174
    Width = 412
    Height = 379
    DefaultRowHeight = 22
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect, goFixedRowDefAlign]
    ScrollBars = ssVertical
    TabOrder = 2
    OnClick = sgRoutesClick
    ColWidths = (
      181
      41
      41
      53
      60)
  end
  object mMain: TMemo
    Left = 797
    Top = 559
    Width = 412
    Height = 167
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      'Click the button to the left marked "Go!" '
      'to generate some random routes.'
      ''
      'Once you have some routes, selecting a '
      'route in the table above will show details '
      'of the route in this box...')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object GroupBox1: TGroupBox
    Left = 797
    Top = 47
    Width = 292
    Height = 102
    Caption = 'Route Generation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
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
      Hint = 'generate random routes!'
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
      Caption = 'Keep Trying'
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
    Top = 47
    Width = 114
    Height = 102
    Caption = 'Stats'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    object Label21: TLabel
      Left = 15
      Top = 19
      Width = 36
      Height = 13
      Caption = 'Aircraft'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label22: TLabel
      Left = 15
      Top = 38
      Width = 38
      Height = 13
      Caption = 'Airports'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lStatsAircraft: TLabel
      Left = 59
      Top = 19
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
    object lStatsAirport: TLabel
      Left = 59
      Top = 38
      Width = 36
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = '99999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lStatsRunways: TLabel
      Left = 59
      Top = 57
      Width = 36
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = '99999'
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
  end
  object gbAirports: TGroupBox
    Left = 389
    Top = 47
    Width = 402
    Height = 571
    Caption = 'Airports'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    object Bevel13: TBevel
      Left = 15
      Top = 448
      Width = 370
      Height = 42
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel5: TBevel
      Left = 15
      Top = 384
      Width = 370
      Height = 58
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel4: TBevel
      Left = 15
      Top = 223
      Width = 370
      Height = 106
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel1: TBevel
      Left = 15
      Top = 19
      Width = 370
      Height = 100
      Shape = bsFrame
      Style = bsRaised
    end
    object Label5: TLabel
      Left = 47
      Top = 268
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
    object Label6: TLabel
      Left = 205
      Top = 268
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
    object Label7: TLabel
      Left = 47
      Top = 295
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
    object labellongto: TLabel
      Left = 205
      Top = 295
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
    object Bevel2: TBevel
      Left = 15
      Top = 125
      Width = 370
      Height = 43
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel3: TBevel
      Left = 15
      Top = 174
      Width = 370
      Height = 43
      Shape = bsFrame
      Style = bsRaised
    end
    object Bevel6: TBevel
      Left = 15
      Top = 335
      Width = 370
      Height = 43
      Shape = bsFrame
      Style = bsRaised
    end
    object Label24: TLabel
      Left = 264
      Top = 351
      Width = 30
      Height = 13
      Caption = '(beta)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 31
      Top = 462
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
      Top = 462
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
    object Label31: TLabel
      Left = 168
      Top = 189
      Width = 207
      Height = 13
      Cursor = crHandPoint
      Caption = '(https://en.wikipedia.org/wiki/ISO_3166-2)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Label31Click
    end
    object bUpdateAirports: TButton
      Left = 312
      Top = 536
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
    object cbContinentAF: TCheckBox
      Left = 47
      Top = 63
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
      TabOrder = 1
      OnClick = cbContinentAFClick
    end
    object cbContinentAN: TCheckBox
      Left = 143
      Top = 63
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
    object cbContinentAS: TCheckBox
      Left = 231
      Top = 63
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
      TabOrder = 3
      OnClick = cbContinentAFClick
    end
    object cbContinentEU: TCheckBox
      Left = 326
      Top = 63
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
      TabOrder = 4
      OnClick = cbContinentAFClick
    end
    object cbContinentNA: TCheckBox
      Left = 47
      Top = 86
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
      TabOrder = 5
      OnClick = cbContinentAFClick
    end
    object cbContinentOC: TCheckBox
      Left = 143
      Top = 86
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
      TabOrder = 6
      OnClick = cbContinentAFClick
    end
    object cbContinentSA: TCheckBox
      Left = 231
      Top = 86
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
      TabOrder = 7
      OnClick = cbContinentAFClick
    end
    object cbCountryFilter: TCheckBox
      Tag = 1
      Left = 29
      Top = 139
      Width = 18
      Height = 17
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = cbContinentFilterClick
    end
    object eLatFrom: TEdit
      Left = 125
      Top = 265
      Width = 75
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      Text = '0'
      OnChange = cbContinentAFClick
    end
    object cbLatLongFilter: TCheckBox
      Tag = 3
      Left = 29
      Top = 236
      Width = 114
      Height = 17
      Caption = 'Latitude / Longitude'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = cbContinentFilterClick
    end
    object eLatTo: TEdit
      Left = 221
      Top = 265
      Width = 75
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
      Text = '0'
      OnChange = cbContinentAFClick
    end
    object cbCountryList: TComboBox
      Left = 63
      Top = 137
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
      TabOrder = 12
      OnChange = cbContinentAFClick
    end
    object eLongFrom: TEdit
      Left = 125
      Top = 292
      Width = 75
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
      Text = '0'
      OnChange = cbContinentAFClick
    end
    object eLongTo: TEdit
      Left = 221
      Top = 292
      Width = 75
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 14
      Text = '0'
      OnChange = cbContinentAFClick
    end
    object cbLargeAirports: TCheckBox
      Left = 47
      Top = 394
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
      TabOrder = 15
      OnClick = cbContinentAFClick
    end
    object cbMediumAirports: TCheckBox
      Left = 143
      Top = 394
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
      TabOrder = 16
      OnClick = cbContinentAFClick
    end
    object cbSmallAirports: TCheckBox
      Left = 255
      Top = 394
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
      TabOrder = 17
      OnClick = cbContinentAFClick
    end
    object cbHeliports: TCheckBox
      Left = 47
      Top = 417
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
      TabOrder = 18
      OnClick = cbContinentAFClick
    end
    object cbSeaplaneBases: TCheckBox
      Left = 143
      Top = 417
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
      TabOrder = 19
      OnClick = cbContinentAFClick
    end
    object cbContinentFilter: TCheckBox
      Left = 29
      Top = 33
      Width = 74
      Height = 17
      Caption = 'Continent'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 20
      OnClick = cbContinentFilterClick
    end
    object cbRegionFilter: TCheckBox
      Tag = 2
      Left = 29
      Top = 188
      Width = 58
      Height = 17
      Caption = 'Region'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 21
      OnClick = cbContinentFilterClick
    end
    object eRegionICO: TEdit
      Left = 86
      Top = 186
      Width = 59
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      PopupMenu = puRegionSelect
      TabOrder = 22
      OnChange = cbContinentAFClick
    end
    object cbTimeOfDay: TCheckBox
      Tag = 1
      Left = 29
      Top = 349
      Width = 74
      Height = 17
      Caption = 'Time of Day'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 23
      OnClick = cbTimeOfDayClick
    end
    object rbDay: TRadioButton
      Left = 128
      Top = 349
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
      TabOrder = 24
      TabStop = True
      OnClick = cbContinentAFClick
    end
    object rbNight: TRadioButton
      Left = 175
      Top = 349
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
      TabOrder = 25
      OnClick = cbContinentAFClick
    end
    object eElevation: TEdit
      Left = 104
      Top = 459
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
      TabOrder = 26
      Text = '-2000'
      OnChange = cbContinentAFClick
      OnExit = eElevationExit
    end
    object eMagicCode: TEdit
      Left = 16
      Top = 539
      Width = 290
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 27
      Visible = False
    end
  end
  object bExportSelected: TButton
    Left = 1158
    Top = 152
    Width = 25
    Height = 18
    Hint = 'export selected row to MSFS plan file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ImageAlignment = iaCenter
    ImageIndex = 0
    Images = il16x16
    ParentFont = False
    TabOrder = 7
    OnClick = bExportSelectedClick
  end
  object bExportSelectedText: TButton
    Left = 1184
    Top = 152
    Width = 25
    Height = 18
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
    TabOrder = 8
    OnClick = bExportSelectedTextClick
  end
  object mRouteDebug: TMemo
    Left = 389
    Top = 624
    Width = 402
    Height = 102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      'Selected route parameters will be shown '
      'here...')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 9
  end
  object bOpenStartMap: TButton
    Left = 1062
    Top = 152
    Width = 25
    Height = 18
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
    TabOrder = 12
    OnClick = bOpenStartMapClick
  end
  object bOpenEndMap: TButton
    Left = 1110
    Top = 152
    Width = 25
    Height = 18
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
    TabOrder = 13
    OnClick = bOpenEndMapClick
  end
  object MainMenu1: TMainMenu
    Left = 392
    Top = 65532
    object File1: TMenuItem
      Caption = 'File'
      object File2: TMenuItem
        Caption = 'Open'
      end
      object Exit2: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
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
    object ools1: TMenuItem
      Caption = 'Tools'
      object Createcustomaircrafttxt1: TMenuItem
        Caption = 'Create "custom_aircraft.txt"'
        OnClick = Createcustomaircrafttxt1Click
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
    Left = 872
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
      0000000000000000000018181800B8B8B8000000000000000000000000000000
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
      000000000000000000000000000000000000000000009E9E9E00000000000000
      000000000000000000000000000000000000B8B8B80000000000000000000000
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
      0000000000000000000000000000ABABAB000000000000000000000000000000
      00000000000000000000B8B8B8000000000000000000B8B8B800000000000000
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
      0000000000000000000018181800000000000000000018181800F0F0F0003232
      3200000000000000000000000000B8B8B8000000000000000000B8B8B8000000
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
      000000000000000000000000000000000000E5E5E500FFFFFF00181818000000
      000090909000000000000000000000000000B8B8B8000000000000000000B8B8
      B800000000000000000000000000000000000000000000000000000000000000
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
      0000000000000000000018181800FFFFFF00FFFFFF00FFFFFF00000000000000
      00000000000000000000000000000000000000000000B8B8B800000000000000
      0000B8B8B8000000000000000000000000000000000000000000000000000000
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
      00000000000047474700FFFFFF00FFFFFF00FFFFFF0047474700000000009090
      9000000000000000000000000000000000000000000000000000B8B8B8000000
      000000000000B8B8B80000000000E4E4E4005D5D5D000000000018181800ABAB
      AB00000000000000000000000000000000000000000000000000000000000000
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
      00000000000000000000000000000000000000000000000000005C5C5C000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000B8B8
      B800000000000000000018181800000000000000000000000000000000000000
      000000000000B8B8B80000000000000000000000000000000000000000000000
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
      00000000000000000000000000000000000000000000F1F1F100000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B8B8B800000000000000000000000000B8B8B800FFFFFF00E4E4E4004747
      47000000000000000000B8B8B800000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000018181800000000009E9E
      9E00FFFFFF00FFFFFF00FFFFFF00FFFFFF009090900000000000909090000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000808080000000000017171700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DADADA000000000000000000000000000000000000000000000000000000
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
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF004747470000000000ABABAB000000000000000000000000000000
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
      0000000000000000000000000000000000008F8F8F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00E5E5E50000000000181818000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00B8B8B800000000005D5D5D000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000ABABAB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000E4E4E4000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000E5E5E5000000000000000000ABABAB00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00171717000000000018181800000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000B8B8B80000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E5E5E500000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
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
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
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
      0000000000000000000000000000000000003232320000000000000000000000
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
      000000000000000000000000000000000000DADADA0000000000000000000000
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
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F0F0
      F000FFFFFF00FFFFFF00FFFFFF00FFFFFF005D5D5D0000000000C4C4C400FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF001818180000000000B8B8B800000000000000000000000000000000000000
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
      000000000000000000000000000000000000000000009E9E9E00000000001818
      1800FFFFFF00FFFFFF00FFFFFF00FFFFFF00C4C4C4000000000032323200FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00E4E4
      E400000000000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000ABABAB00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00909090000000000048484800FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      000000000000B8B8B80000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000E4E4E4000000
      000000000000E5E5E500FFFFFF00FFFFFF00FFFFFF000000000000000000DADA
      DA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000E5E5E500FFFFFF00FFFFFF00FFFFFF00181818000000
      0000171717000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000000000009090
      90000000000000000000E5E5E500FFFFFF00FFFFFF00B8B8B800000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E4E4
      E4000000000000000000FFFFFF00FFFFFF00FFFFFF0032323200000000000000
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
      0000808080000000000000000000ABABAB00FFFFFF00FFFFFF00000000000000
      0000E5E5E500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000009E9E9E00FFFFFF00FFFFFF000000000000000000000000000000
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
      00000000000090909000000000000000000018181800F1F1F100ABABAB000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00ABABAB000000
      000000000000FFFFFF009E9E9E00000000000000000000000000000000000000
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
      00000000000000000000E5E5E500000000000000000000000000000000000000
      00000000000018181800FFFFFF00FFFFFF00FFFFFF00B8B8B800000000000000
      0000474747000000000000000000000000005C5C5C0000000000000000000000
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
      0000000000000000000000000000000000009E9E9E0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000018181800F0F0F0000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000DADADA003232
      3200000000000000000000000000000000000000000000000000000000000000
      0000909090000000000000000000000000000000000000000000000000000000
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
      0000B8B8B8005C5C5C000000000000000000000000005D5D5D009E9E9E00E4E4
      E400000000000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000090909000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000018181800E4E4E400000000000000000000000000000000000000
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
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFEFF00FFFEFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000909090000000000000000000000000000000
      00005C5C5C00B8B8B800F0F0F000FFFFFF00FFFFFF00CFCFCF009D9D9D001818
      180000000000000000000000000000000000F1F1F10000000000000000000000
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
      000000000000F1F1F10000000000000000000000000032323200F0F0F000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00B8B8B80000000000000000000000000090909000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000DADADA00000000000000000000000000F0F0F000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00ABABAB000000000000000000181818000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000DADA
      DA0000000000000000005D5D5D00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000001818
      1800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009E9E9E0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000F0F0F0000000
      00000000000080808000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000484848000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000181818000000
      0000DADADA00FFFFFF00F0F0F000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00006D6D6D00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      000000000000C4C4C40000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000ABABAB000000
      00006E6E6E00FFFFFF00FFFFFF0018181800000000009D9D9D00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00B8B8B800FFFFFF00FFFFFF00000000000000
      000000000000000000007F7F7F00000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DADA
      DA00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00F0F0F0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000B8B8B800FFFFFF00000000000000
      00000000000000000000000000007F7F7F00000000000000000000000000F1F1
      F100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00323232000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF0018181800000000009E9E9E000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00B8B8B8000000000000000000B8B8B800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00000000000000000000000000F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001717
      170000000000DADADA00FFFFFF00FFFFFF00F0F0F00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00B8B8B8000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF001818180000000000C4C4C4000000000018181800000000000000
      0000000000000000000000000000000000009D9D9D000000000000000000ABAB
      AB00000000006D6D6D00FFFFFF00FFFFFF00FFFFFF0018181800000000009E9E
      9E00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00B8B8B80000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00DADADA00F1F1F100FFFFFF0000000000F0F0F000000000000000
      0000FFFFFF00FFFFFF00F1F1F100000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00F0F0F000000000000000
      000000000000000000000000000000000000000000000000000032323200DADA
      DA00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00B9B9B900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000181818000000
      00009D9D9D00FFFFFF00FFFFFF00181818000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00181818000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000474747000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0B0C0000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000F0F0F0000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C3C3C3000000
      000000000000DADADA0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFDFF00FFF7FF00FF01FF000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000001818
      1800000000009D9D9D00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C4C4
      C400000000003232320000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFDFF00000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000009D9D
      9D000000000018181800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000F0F0F000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004747
      4700000000007F7F7F0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000009D9D9D000000
      000018181800FFFFFF00FFFFFF009E9E9E000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF009D9D9D000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000F0F0F000FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F0F0F0000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000006E6E6E0000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000009E9E9E00000000000000
      000000000000000000000000000000000000181818000000000000000000DADA
      DA000000000018181800FFFFFF00FFFFFF00FFFFFF009D9D9D00000000001818
      1800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000001818180000000000B8B8B800FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F0F0F00000000000000000006D6D
      6D0000000000ABABAB00FFFFFF00FFFFFF00FFFFFF000000000000000000F0F0
      F000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E4E4E4000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00B8B8B8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF009D9D9D0000000000171717000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009E9E
      9E00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000F0F0F0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      00000000000000000000000000000000000000000000F0F0F000000000000000
      0000F0F0F000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF003232
      3200000000003131310000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DADADA000000
      000018181800FFFFFF00FFFFFF009E9E9E000000000018181800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000006E6E6E000000
      0000ABABAB00FFFFFF00FFFFFF000000000000000000F0F0F000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001818
      18000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007F7F7F00000000000000
      0000E5E5E5000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001818180000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000181818000000000000000000E5E5E500FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00323232000000000000000000DADA
      DA00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F1F1F10000000000000000000000
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
      00000000000047474700000000000000000032323200FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00B8B8B800000000000000000000000000E4E4E4000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000181818000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000DADADA0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000C4C4C40000000000000000000000000018181800D0D0
      D000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00808080000000000000000000000000001717170000000000000000000000
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
      0000000000000000000000000000000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000E4E4E4000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000C4C4C4003232
      3200000000000000000000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000400000000100010000000000000400000000000000000000
      000000000000000000000000FFFFFF00C000000FFFFCFFFF0000000000000000
      C000000FFF9C7FFF0000000000000000C000000FFE1C3FFF0000000000000000
      C000000FFC0E1FFF0000000000000000C000000FF8070FFF0000000000000000
      C000000FF00F87FF0000000000000000C000000FE00FC20F0000000000000000
      C000000FC01FE0030000000000000000C000000F801FF0010000000000000000
      C000000F801FF0010000000000000000C000000F800030000000000000000000
      C000000F000030000000000000000000C000000F003FF0000000000000000000
      C000000F003FF0000000000000000000C000000F003FF0000000000000000000
      C000000F003FF0010000000000000000C000000F003FF8030000000000000000
      C000000F003FFC070000000000000000C000000F003FFFFF0000000000000000
      C000000F003FFFFF0000000000000000C000000F000000010000000000000000
      C000000F000000010000000000000000C000000F800000010000000000000000
      C000000F800000030000000000000000C000001FC00000030000000000000000
      C000003FC00000070000000000000000C000007FE000000F0000000000000000
      C00000FFF000001F0000000000000000C00001FFF800003F0000000000000000
      C00003FFFC00007F0000000000000000C00007FFFF0000FF0000000000000000
      C0000FFFFFC007FF0000000000000000FFFFFFFFC00000CFFFF00FFFFFFFFFFF
      FFFFFFFFC00000CFFF8001FFFFFFFFFFF8000003C000000FFE00007FFFFFFFFF
      F0000003C000000FF800003FFFFFFFFFE0000003C000000F3000001FFFC0FFFF
      C0000003C000000F2000000FFFC07FFFC0000003C000000F00000007FFC07FFF
      C0000003C000000F00000003FFC03FFFC0000003C000000D00000003FFE03FFF
      C0000003C000000800000001FFE01FFFC0000003C00000010000000100E01FFF
      C0000003C00000030000000080600FFFC0000003C0000007000000008000000F
      C0000003C000000F00000000C0000007C0000003C000001F00000000C0000003
      C0000003C000001F00000000E0000003C0000003C000000F00000000E0000003
      C0000003C000000F00000000E0000003C0000003C000000F00000000C0000007
      C0000003C000000F00000000C0000007C0000003C000000F0000000080600FFF
      C0000003C000000F0000000080600FFFC0000003C000000F00000000FFE01FFF
      C0000003C000000F80000000FFE01FFFC0000003C000001F80000000FFC03FFF
      C0000003C000003FC0000004FFC03FFFC0000003C000007FE0000004FFC07FFF
      C0000003C00000FFF000000CFFC07FFFC0000003C00001FFF800001FFFFFFFFF
      C0000003C00003FFFC00007FFFFFFFFFFFFFFFFFC00007FFFF0000FFFFFFFFFF
      FFFFFFFFC0000FFFFFC007FFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object sdMain: TSaveDialog
    Filter = 'FSAC configuration files|*.config'
    Left = 1072
  end
  object odMain: TOpenDialog
    Filter = 'FSAC configuration files|*.config'
    Left = 1032
    Top = 65528
  end
  object il16x16: TImageList
    Left = 928
    Top = 65532
    Bitmap = {
      494C010106000800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000A0A0A0005E5E5E009F9F9F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F8F8F80035353500111111000505050029292900F6F6
      F600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000A0A0A0002F2F2F001C1C1C00000000001B1B1B002F2F2F00A0A0A0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F3F3F3005A5A5A0050505000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A1A1A1002727
      270027272700A9A9A900F3F3F30046464600F2F2F200A8A8A800272727002727
      2700A2A2A2000000000000000000000000000000000000000000000000000000
      0000000000009D9D9D004B4B4B005C5C5C003D3D3D002A2A2A005D5D5D009E9E
      9E00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000004B4B4B0027272700A0A0
      A000FFFFFF00FFFFFF00ECECEC001B1B1B00ECECEC00FFFFFF00FFFFFF00A1A1
      A100262626004C4C4C000000000000000000000000000000000000000000DFDF
      DF002121210049494900AEAEAE00C1C1C100D2D2D200D1D1D100AEAEAE004343
      4300545454009D9D9D0079797900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FDFDFD00FFFF
      FF00FFFFFF00FFFFFF00E6E6E60026262600E5E5E500FFFFFF00FFFFFF00FFFF
      FF00FDFDFD000000000000000000000000000000000000000000E1E1E1000000
      00009C9C9C00EBEBEB0089898900717171005C5C5C007A7A7A009B9B9B00F6F6
      F6005E5E5E0000000000A2A2A200000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000013131300FCFCFC00FFFF
      FF00FFFFFF00FFFFFF00E6E6E60026262600E5E5E500FFFFFF00FFFFFF00FFFF
      FF00FCFCFC00131313000000000000000000000000000000000000000000A2A2
      A200ECECEC00161616000000000040404000D2D2D20030303000000000000808
      080042424200C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00ECECEC0029292900ECECEC00FFFFFF00FFFFFF00FFFF
      FF00F5F5F500121212000000000000000000000000009595950035353500FFFF
      FF0000000000CFCFCF00FFFFFF001A1A1A000000000084848400D9D9D900A4A4
      A40000000000FBFBFB0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000011111100F5F5F500FFFF
      FF00FFFFFF00FFFFFF00EDEDED0000000000EDEDED00FFFFFF00FFFFFF00FFFF
      FF00F5F5F500111111000000000000000000000000002A2A2A00C3C3C3008282
      820000000000FFFFFF00B9B9B90028282800262626007F7F7F00FFFFFF00FDFD
      FD00000000006767670000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000009090900FDFDFD00FFFF
      FF00FFFFFF00A1A1A100272727002A2A2A0027272700A0A0A000FFFFFF00FFFF
      FF00FDFDFD000A0A0A000000000000000000F3F3F30036363600D5D5D5005F5F
      5F005C5C5C00353535001B1B1B00EBEBEB00FFFFFF00070707007D7D7D008080
      80003F3F3F0050505000F5F5F500000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000025252500FFFFFF00A9A9
      A9002727270027272700A5A5A500FDFDFD00A6A6A6002727270027272700A8A8
      A800FFFFFF00262626000000000000000000DFDFDF0042424200CACACA005B5B
      5B00EEEEEE000000000000000000FFFFFF00FFFFFF00FFFFFF00000000000000
      0000EEEEEE0047474700DFDFDF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000004D4D4D005E5E
      5E00A9A9A900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A9A9A9005D5D
      5D004D4D4D00000000000000000000000000F1F1F10036363600D5D5D5006A6A
      6A003F3F3F00818181007E7E7E0007070700FFFFFF00EBEBEB001B1B1B003636
      36005C5C5C0042424200F6F6F600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000004343430000000000A8A8
      A800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A9A9
      A900000000004343430000000000000000000000000024242400C9C9C9009999
      990000000000FDFDFD00FFFFFF00808080002626260029292900B9B9B900FFFF
      FF00000000004B4B4B0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000BABABA003434
      340027272700A0A0A000FFFFFF00FFFFFF00FFFFFF00A0A0A000272727003535
      3500BABABA0000000000000000000000000000000000888888003B3B3B00FFFF
      FF000C0C0C00A3A3A300D8D8D800878787000000000019191900FFFFFF00D1D1
      D10000000000D7D7D70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000A1A1A100272727002E2E2E007E7E7E002E2E2E0027272700A1A1A1000000
      00000000000000000000000000000000000000000000000000003D3D3D008585
      850038383800000000000000000030303000D2D2D20040404000000000000000
      0000B3B3B3000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009A9A9A003E3E3E009A9A9A0000000000000000000000
      0000000000000000000000000000000000000000000000000000929292000000
      0000C6C6C600E9E9E900727272005C5C5C0045454500515151005C5C5C00D7D7
      D700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFAFAF00ACAC
      AC00000000000000000000000000F8F8F800E6E6E600FAFAFA00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
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
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00FC7FFC0F00000000F01FFE3F00000000
      C007F80F000000008003E001000000008003C001000000008003C00300000000
      8003800300000000800380030000000080030001000000008003000100000000
      80030001000000008003800300000000C007800300000000F01FC00700000000
      FC7FC00F00000000FFFFCE3F00000000FFFF800380018001FFFF800380018001
      F8FF800380018001F87F800380018001F87F8003800180010C3F800380018001
      80038003800180018001800380018001800180038001800180018003C003C003
      0C3F8003FFC7E3C7F87F8003E7C7E3C7F87F8007E3C7E3C7F8FF800FF3CFF3CF
      FFFF801FF00FF00FFFFF803FF81FF81F00000000000000000000000000000000
      000000000000}
  end
  object puSelectICAO: TPopupMenu
    OnPopup = puSelectICAOPopup
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
    object N8: TMenuItem
      Caption = 'Clear'
      OnClick = N8Click
    end
  end
  object puRegionSelect: TPopupMenu
    Left = 528
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
    Left = 688
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
end
