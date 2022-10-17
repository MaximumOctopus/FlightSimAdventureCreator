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
    Caption = 'Stats'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    ExplicitWidth = 1135
    object Label1: TLabel
      Left = 256
      Top = 16
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
      Left = 423
      Top = 16
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
    object eSearch: TEdit
      Left = 16
      Top = 35
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
      Left = 167
      Top = 33
      Width = 75
      Height = 25
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
      Left = 256
      Top = 35
      Width = 145
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
      Left = 423
      Top = 35
      Width = 145
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
      Left = 807
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
      Left = 607
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
      Left = 703
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
      Left = 607
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
      Left = 703
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
  end
  object sgResults: TStringGrid
    Left = 8
    Top = 87
    Width = 1225
    Height = 495
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 9
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
      95)
  end
  object sbSearch: TStatusBar
    Left = 0
    Top = 588
    Width = 1241
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitLeft = 464
    ExplicitTop = 592
    ExplicitWidth = 0
  end
end
