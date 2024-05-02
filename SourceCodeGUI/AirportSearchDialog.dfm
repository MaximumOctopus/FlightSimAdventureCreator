object frmAirportSearchDialog: TfrmAirportSearchDialog
  Left = 0
  Top = 0
  Caption = 'Airport Search'
  ClientHeight = 606
  ClientWidth = 1211
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  DesignSize = (
    1211
    606)
  TextHeight = 13
  object GroupBox4: TGroupBox
    Left = 8
    Top = 8
    Width = 1191
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
    ExplicitWidth = 1199
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
    object Bevel4: TBevel
      Left = 1060
      Top = 16
      Width = 4
      Height = 50
      Shape = bsLeftLine
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
      CharCase = ecUpperCase
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
    object bSelect: TButton
      Left = 1108
      Top = 29
      Width = 83
      Height = 32
      Caption = 'Select!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageAlignment = iaRight
      ImageIndex = 0
      Images = ImageList1
      ParentFont = False
      TabOrder = 12
      Visible = False
      OnClick = bSelectClick
    end
    object bSave: TButton
      Left = 1070
      Top = 29
      Width = 32
      Height = 32
      ImageAlignment = iaCenter
      ImageIndex = 1
      Images = ImageList1
      TabOrder = 13
      OnClick = bSaveClick
    end
  end
  object sgResults: TStringGrid
    Left = 8
    Top = 87
    Width = 1191
    Height = 494
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 10
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect, goFixedRowDefAlign]
    TabOrder = 1
    OnDblClick = sgResultsDblClick
    ExplicitWidth = 1199
    ExplicitHeight = 495
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
    Top = 587
    Width = 1211
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitTop = 588
    ExplicitWidth = 1215
  end
  object ImageList1: TImageList
    Left = 304
    Top = 104
    Bitmap = {
      494C010102000800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000002D2D2D78000000F10101
      01F1000000F1000000F1000000F1000000F1000000F1000000F1000000F10000
      00F1000000F1000000F1000000F1000000E40000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000B8B8B800DCDCDC00D9D9
      D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9
      D900D9D9D900DCDCDC00B8B8B8000000000013131377000000FFD1D1D1FF5F5F
      5FFF6E6E6EFFB2B2B2FF0C0C0CFFDDDDDDFFDDDDDDFFDDDDDDFF272727FF6E6E
      6EFFDDDDDDFFDDDDDDFFC0C0C0FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F2F2F200FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F2F2F20000000000000000FFC4C4C4FFFFFFFFFF5D5D
      5DFF919191FFD7D7D7FF000000FFFFFFFFFFFFFFFFFFFFFFFFFF333333FF8A8A
      8AFFFFFFFFFFFFFFFFFFF1F1F1FF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D9D9D90000000000000000F5EEEEEEFFFFFFFFFF4848
      48FF737373FFFFFFFFFFD1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFF363636FF7777
      77FFFFFFFFFFFFFFFFFFDDDDDDFF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00FFFF
      FF00FFFFFF00DDDDDD0090909000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D9D9D90000000000000000F1DDDDDDFFFFFFFFFF5050
      50FF000000FF8A8A8AFFA8A8A8FF7F7F7FFF7F7F7FFF7F7F7FFF000000FF7F7F
      7FFFFFFFFFFFFFFFFFFFDDDDDDFF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00FFFF
      FF00F0F0F00000000000000000007C7C7C00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D9D9D90000000000000000F1DDDDDDFFFFFFFFFFB3B3
      B3FF565656FF2E2E2EFF2E2E2EFF2E2E2EFF2E2E2EFF2E2E2EFF5D5D5DFFC7C7
      C7FFFFFFFFFFFFFFFFFFDDDDDDFF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00E0E0
      E000030303003D3D3D00B9B9B900000000006E6E6E00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D9D9D90000000000000000F1DCDCDCFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFDCDCDCFF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DFDFDF00FFFFFF001D1D
      1D0019191900FFFFFF00FFFFFF00BBBBBB00000000006E6E6E00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D9D9D90000000000000000F1DFDFDFFFFAFAFAFFF3F3
      F3FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFF0F0F0FFEEEE
      EEFFF1F1F1FFFAFAFAFFDFDFDFFF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DBDBDB00FFFFFF00C1C1
      C100F8F8F800FFFFFF00FFFFFF00FFFFFF00BDBDBD00000000006E6E6E00FFFF
      FF00FFFFFF00FFFFFF00D9D9D90000000000000000F1F4F4F4FF8A8A8AFF0A0A
      0AFF020202FF020202FF020202FF020202FF020202FF020202FF020202FF0202
      02FF0A0A0AFF8A8A8AFFF4F4F4FF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D8D8D800FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD00000000007070
      7000FFFFFF00FFFFFF00D7D7D70000000000000000F1F7F7F7FF4F4F4FFF5858
      58FFCECECEFFCECECEFFCECECEFFCECECEFFCECECEFFCECECEFFCECECEFFCECE
      CEFF585858FF4F4F4FFFF7F7F7FF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDBDBD000000
      000053535300FFFFFF00DEDEDE0000000000000000F1F6F6F6FF4E4E4EFF8A8A
      8AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF8A8A8AFF4E4E4EFFF6F6F6FF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A6A6
      A60055555500FFFFFF00DEDEDE0000000000000000F1F6F6F6FF545454FF7F7F
      7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF7F7F7FFF545454FFF6F6F6FF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D9D9D900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00D7D7D70000000000000000F1F6F6F6FF545454FF7F7F
      7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF7F7F7FFF545454FFF6F6F6FF000000F10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F2F2F200FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F2F2F20000000000000000F2FFFFFFFF5C5C5CFF8A8A
      8AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF8A8A8AFF5C5C5CFFFFFFFFFF000000F20000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000B8B8B800DCDCDC00D9D9
      D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9D900D9D9
      D900D9D9D900DCDCDC00B8B8B80000000000000000FFD5D5D5FF474747FF6E6E
      6EFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDDDDFFDDDD
      DDFF6E6E6EFF474747FFD5D5D5FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000D0D0DB2000000F1000000F10000
      00F1000000F1000000F1000000F1000000F1000000F1000000F1000000F10000
      00F1000000F1000000F1000000F10D0D0DB20000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000}
  end
  object sdSearch: TSaveDialog
    Left = 360
    Top = 112
  end
end
