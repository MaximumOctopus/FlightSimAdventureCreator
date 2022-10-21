object frmAirportSearchDialog: TfrmAirportSearchDialog
  Left = 0
  Top = 0
  Caption = 'Airport Search'
  ClientHeight = 607
  ClientWidth = 1241
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  DesignSize = (
    1241
    607)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox4: TGroupBox
    Left = 8
    Top = 8
    Width = 1225
    Height = 73
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Search Options'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 264
      Top = 15
      Width = 47
      Height = 13
      Caption = 'Continent'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 351
      Top = 15
      Width = 39
      Height = 13
      Caption = 'Country'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Bevel1: TBevel
      Left = 847
      Top = 16
      Width = 4
      Height = 50
      Shape = bsLeftLine
    end
    object Label4: TLabel
      Left = 903
      Top = 37
      Width = 30
      Height = 13
      Caption = 'nm of '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 985
      Top = 37
      Width = 69
      Height = 13
      Caption = '(airport ICAO)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Bevel2: TBevel
      Left = 541
      Top = 16
      Width = 4
      Height = 50
      Shape = bsLeftLine
    end
    object Bevel3: TBevel
      Left = 254
      Top = 16
      Width = 4
      Height = 50
      Shape = bsLeftLine
    end
    object Label3: TLabel
      Left = 103
      Top = 15
      Width = 22
      Height = 13
      Caption = 'Text'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object eSearch: TEdit
      Left = 103
      Top = 34
      Width = 145
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnKeyPress = eSearchKeyPress
    end
    object bSearch: TButton
      Left = 11
      Top = 29
      Width = 75
      Height = 32
      Caption = 'Search'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = bSearchClick
    end
    object cbContinent: TComboBox
      Left = 264
      Top = 34
      Width = 73
      Height = 21
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object cbCountry: TComboBox
      Left = 351
      Top = 34
      Width = 178
      Height = 21
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object cbLargeAirports: TCheckBox
      Left = 751
      Top = 14
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
      TabOrder = 4
    end
    object cbHeliports: TCheckBox
      Left = 551
      Top = 37
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
      TabOrder = 5
    end
    object cbSeaplaneBases: TCheckBox
      Left = 647
      Top = 37
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
      TabOrder = 6
    end
    object cbSmallAirports: TCheckBox
      Left = 551
      Top = 14
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
      TabOrder = 7
    end
    object cbMediumAirports: TCheckBox
      Left = 647
      Top = 14
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
      TabOrder = 8
    end
    object eRange: TEdit
      Left = 857
      Top = 34
      Width = 40
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      Text = '100'
      OnKeyPress = eSearchKeyPress
    end
    object eICAO: TEdit
      Left = 939
      Top = 34
      Width = 40
      Height = 21
      Alignment = taRightJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnKeyPress = eSearchKeyPress
    end
    object cbWithinRange: TCheckBox
      Left = 857
      Top = 14
      Width = 90
      Height = 17
      Caption = 'Within range of'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 11
    end
  end
  object sgResults: TStringGrid
    Left = 8
    Top = 87
    Width = 1225
    Height = 495
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 10
    FixedCols = 0
    TabOrder = 1
    ColWidths = (
      50
      39
      531
      35
      34
      64
      123
      124
      95
      64)
  end
  object sbSearch: TStatusBar
    Left = 0
    Top = 588
    Width = 1241
    Height = 19
    Panels = <>
    SimplePanel = True
  end
end
