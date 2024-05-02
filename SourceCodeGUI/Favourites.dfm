object frmFavourites: TfrmFavourites
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Favourites'
  ClientHeight = 367
  ClientWidth = 468
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 457
    Height = 322
    Caption = 'Manage'
    TabOrder = 0
    object Label1: TLabel
      Left = 151
      Top = 152
      Width = 32
      Height = 13
      Caption = 'Name'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lName: TLabel
      Left = 223
      Top = 152
      Width = 12
      Height = 13
      Caption = '...'
    end
    object Label3: TLabel
      Left = 151
      Top = 171
      Width = 55
      Height = 13
      Caption = 'Continent'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lContinent: TLabel
      Left = 223
      Top = 171
      Width = 12
      Height = 13
      Caption = '...'
    end
    object Label5: TLabel
      Left = 151
      Top = 190
      Width = 45
      Height = 13
      Caption = 'Country'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lCountry: TLabel
      Left = 223
      Top = 190
      Width = 12
      Height = 13
      Caption = '...'
    end
    object Label7: TLabel
      Left = 151
      Top = 209
      Width = 39
      Height = 13
      Caption = 'Region'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lRegion: TLabel
      Left = 223
      Top = 209
      Width = 12
      Height = 13
      Caption = '...'
    end
    object lbFavourites: TListBox
      Left = 16
      Top = 32
      Width = 81
      Height = 273
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemHeight = 19
      ParentFont = False
      TabOrder = 0
      OnClick = lbFavouritesClick
    end
    object bAdd: TButton
      Left = 120
      Top = 45
      Width = 25
      Height = 25
      ImageIndex = 0
      Images = ImageList1
      TabOrder = 1
      OnClick = bAddClick
    end
    object bDelete: TButton
      Left = 120
      Top = 87
      Width = 25
      Height = 25
      ImageIndex = 1
      Images = ImageList1
      TabOrder = 2
      OnClick = bDeleteClick
    end
    object eICAO: TEdit
      Left = 151
      Top = 47
      Width = 41
      Height = 21
      TabOrder = 3
    end
    object Button1: TButton
      Left = 151
      Top = 228
      Width = 25
      Height = 25
      Hint = 'show on google maps'
      ImageIndex = 2
      Images = ImageList1
      TabOrder = 4
      OnClick = Button1Click
    end
  end
  object bCancel: TButton
    Left = 389
    Top = 335
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object bOK: TButton
    Left = 308
    Top = 335
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 2
    OnClick = bOKClick
  end
  object ImageList1: TImageList
    Left = 24
    Top = 320
    Bitmap = {
      494C010103000800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F8F8F80035353500111111000505050029292900F6F6
      F600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000090909000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00090909000000000000000000090909000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00090909000000000000000000000000000000000000000
      0000000000000000000000000000F3F3F3005A5A5A0050505000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DBDBDB00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DBDBDB000000000000000000DBDBDB00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DBDBDB00000000000000000000000000000000000000
      0000000000009D9D9D004B4B4B005C5C5C003D3D3D002A2A2A005D5D5D009E9E
      9E00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00BFBFBF00BFBFBF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C00000000000000000000000000000000000DFDF
      DF002121210049494900AEAEAE00C1C1C100D2D2D200D1D1D100AEAEAE004343
      4300545454009D9D9D0079797900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF001C1C1C001C1C1C00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C000000000000000000000000000E1E1E1000000
      00009C9C9C00EBEBEB0089898900717171005C5C5C007A7A7A009B9B9B00F6F6
      F6005E5E5E0000000000A2A2A200000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF003434340034343400FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C00000000000000000000000000000000000A2A2
      A200ECECEC00161616000000000040404000D2D2D20030303000000000000808
      080042424200C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF003E3E3E003E3E3E00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C00000000000000000009595950035353500FFFF
      FF0000000000CFCFCF00FFFFFF001A1A1A000000000084848400D9D9D900A4A4
      A40000000000FBFBFB0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00BFBF
      BF003636360036363600363636000B0B0B000B0B0B0036363600363636003636
      3600BFBFBF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00BFBF
      BF003636360036363600363636000B0B0B000B0B0B0036363600363636003636
      3600BFBFBF00FFFFFF00C0C0C00000000000000000002A2A2A00C3C3C3008282
      820000000000FFFFFF00B9B9B90028282800262626007F7F7F00FFFFFF00FDFD
      FD00000000006767670000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00BFBF
      BF003636360036363600363636000B0B0B000B0B0B0036363600363636003636
      3600BFBFBF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00BFBF
      BF003636360036363600363636000B0B0B000B0B0B0036363600363636003636
      3600BFBFBF00FFFFFF00C0C0C00000000000F3F3F30036363600D5D5D5005F5F
      5F005C5C5C00353535001B1B1B00EBEBEB00FFFFFF00070707007D7D7D008080
      80003F3F3F0050505000F5F5F500000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF003E3E3E003E3E3E00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C00000000000DFDFDF0042424200CACACA005B5B
      5B00EEEEEE000000000000000000FFFFFF00FFFFFF00FFFFFF00000000000000
      0000EEEEEE0047474700DFDFDF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF003434340034343400FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C00000000000F1F1F10036363600D5D5D5006A6A
      6A003F3F3F00818181007E7E7E0007070700FFFFFF00EBEBEB001B1B1B003636
      36005C5C5C0042424200F6F6F600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF001C1C1C001C1C1C00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C000000000000000000024242400C9C9C9009999
      990000000000FDFDFD00FFFFFF00808080002626260029292900B9B9B900FFFF
      FF00000000004B4B4B0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00BFBFBF00BFBFBF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00C0C0C0000000000000000000888888003B3B3B00FFFF
      FF000C0C0C00A3A3A300D8D8D800878787000000000019191900FFFFFF00D1D1
      D10000000000D7D7D70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000DBDBDB00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DBDBDB000000000000000000DBDBDB00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DBDBDB000000000000000000000000003D3D3D008585
      850038383800000000000000000030303000D2D2D20040404000000000000000
      0000B3B3B3000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000090909000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00090909000000000000000000090909000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00090909000000000000000000000000000929292000000
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
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF0000000000FC0F000000000000FE3F0000
      00000000F80F000000000000E001000000000000C001000000000000C0030000
      0000000080030000000000008003000000000000000100000000000000010000
      00000000000100000000000080030000000000008003000000000000C0070000
      00000000C00F000000000000CE3F000000000000000000000000000000000000
      000000000000}
  end
end
