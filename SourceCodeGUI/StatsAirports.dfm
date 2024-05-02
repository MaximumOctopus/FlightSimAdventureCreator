object frmStatsAirports: TfrmStatsAirports
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Airport Stats'
  ClientHeight = 435
  ClientWidth = 774
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poMainFormCenter
  OnCreate = FormCreate
  TextHeight = 13
  object Label1: TLabel
    Left = 236
    Top = 8
    Width = 40
    Height = 13
    Caption = 'Lowest'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 236
    Top = 27
    Width = 43
    Height = 13
    Caption = 'Highest'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lLowest: TLabel
    Left = 292
    Top = 8
    Width = 12
    Height = 13
    Caption = '...'
  end
  object lHighest: TLabel
    Left = 292
    Top = 27
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Label3: TLabel
    Left = 24
    Top = 362
    Width = 33
    Height = 13
    Caption = 'Africa'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 130
    Top = 362
    Width = 59
    Height = 13
    Caption = 'Antarctica'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 236
    Top = 362
    Width = 24
    Height = 13
    Caption = 'Asia'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 342
    Top = 362
    Width = 39
    Height = 13
    Caption = 'Europe'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 448
    Top = 362
    Width = 81
    Height = 13
    Caption = 'North America'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 554
    Top = 362
    Width = 45
    Height = 13
    Caption = 'Oceania'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 660
    Top = 362
    Width = 83
    Height = 13
    Caption = 'South America'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object gc1: TGauge
    Left = 24
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object gc2: TGauge
    Left = 130
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object gc3: TGauge
    Left = 236
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object gc4: TGauge
    Left = 342
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object gc5: TGauge
    Left = 448
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object gc6: TGauge
    Left = 554
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object gc7: TGauge
    Left = 660
    Top = 256
    Width = 100
    Height = 100
    Progress = 0
  end
  object lCount: TLabel
    Left = 24
    Top = 8
    Width = 9
    Height = 13
    Caption = '...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 130
    Top = 194
    Width = 31
    Height = 13
    Caption = 'Small'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 236
    Top = 194
    Width = 45
    Height = 13
    Caption = 'Medium'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 342
    Top = 194
    Width = 32
    Height = 13
    Caption = 'Large'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label13: TLabel
    Left = 448
    Top = 194
    Width = 45
    Height = 13
    Caption = 'Heliport'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label14: TLabel
    Left = 554
    Top = 194
    Width = 82
    Height = 13
    Caption = 'Seaplane base'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object gt1: TGauge
    Left = 130
    Top = 88
    Width = 100
    Height = 100
    Progress = 0
  end
  object gt2: TGauge
    Left = 236
    Top = 88
    Width = 100
    Height = 100
    Progress = 0
  end
  object gt3: TGauge
    Left = 342
    Top = 88
    Width = 100
    Height = 100
    Progress = 0
  end
  object gt4: TGauge
    Left = 448
    Top = 88
    Width = 100
    Height = 100
    Progress = 0
  end
  object gt5: TGauge
    Left = 554
    Top = 88
    Width = 100
    Height = 100
    Progress = 0
  end
  object lc1: TLabel
    Left = 118
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lc2: TLabel
    Left = 224
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lc3: TLabel
    Left = 330
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lc4: TLabel
    Left = 436
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lc5: TLabel
    Left = 542
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lc6: TLabel
    Left = 648
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lc7: TLabel
    Left = 754
    Top = 237
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object Bevel1: TBevel
    Left = 24
    Top = 224
    Width = 736
    Height = 9
    Shape = bsTopLine
  end
  object lt1: TLabel
    Left = 224
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lt2: TLabel
    Left = 330
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lt3: TLabel
    Left = 436
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lt4: TLabel
    Left = 542
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object lt5: TLabel
    Left = 648
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    Color = clGray
    ParentBiDiMode = False
    ParentColor = False
  end
  object Bevel2: TBevel
    Left = 24
    Top = 56
    Width = 736
    Height = 9
    Shape = bsTopLine
  end
  object Button1: TButton
    Left = 685
    Top = 405
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Close'
    ModalResult = 1
    TabOrder = 0
  end
end
