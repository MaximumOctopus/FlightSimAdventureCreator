object frmStatsAircraft: TfrmStatsAircraft
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Aircraft Stats'
  ClientHeight = 265
  ClientWidth = 884
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 24
    Top = 194
    Width = 26
    Height = 13
    Caption = 'Prop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 130
    Top = 194
    Width = 18
    Height = 13
    Caption = 'Jet'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 236
    Top = 194
    Width = 58
    Height = 13
    Caption = 'Helicopter'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 342
    Top = 194
    Width = 33
    Height = 13
    Caption = 'Glider'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 448
    Top = 194
    Width = 55
    Height = 13
    Caption = 'Twin Prop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 554
    Top = 194
    Width = 62
    Height = 13
    Caption = 'Turbo Prop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 660
    Top = 194
    Width = 91
    Height = 13
    Caption = 'Twin Turbo Prop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object g1: TGauge
    Left = 24
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object g2: TGauge
    Left = 130
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object g3: TGauge
    Left = 236
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object g4: TGauge
    Left = 342
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object g5: TGauge
    Left = 448
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object g6: TGauge
    Left = 554
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object g7: TGauge
    Left = 660
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object Label1: TLabel
    Left = 766
    Top = 194
    Width = 41
    Height = 13
    Caption = 'Balloon'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object g8: TGauge
    Left = 766
    Top = 88
    Width = 100
    Height = 100
    Progress = 50
  end
  object Label2: TLabel
    Left = 236
    Top = 8
    Width = 77
    Height = 13
    Caption = 'Lowest cruise'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 236
    Top = 27
    Width = 80
    Height = 13
    Caption = 'Highest cruise'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lLowestCruise: TLabel
    Left = 324
    Top = 8
    Width = 12
    Height = 13
    Caption = '...'
  end
  object lHighestCruise: TLabel
    Left = 324
    Top = 27
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Label11: TLabel
    Left = 448
    Top = 8
    Width = 76
    Height = 13
    Caption = 'Lowest range'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 448
    Top = 27
    Width = 79
    Height = 13
    Caption = 'Highest range'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lLowestRange: TLabel
    Left = 536
    Top = 8
    Width = 12
    Height = 13
    Caption = '...'
  end
  object lHighestRange: TLabel
    Left = 536
    Top = 27
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Bevel2: TBevel
    Left = 24
    Top = 56
    Width = 842
    Height = 9
    Shape = bsTopLine
  end
  object lt1: TLabel
    Left = 118
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt2: TLabel
    Left = 224
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt4: TLabel
    Left = 436
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt3: TLabel
    Left = 330
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt6: TLabel
    Left = 648
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt5: TLabel
    Left = 542
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt8: TLabel
    Left = 860
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lt7: TLabel
    Left = 754
    Top = 71
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
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
  object Button1: TButton
    Left = 791
    Top = 232
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Close'
    ModalResult = 1
    TabOrder = 0
  end
end
