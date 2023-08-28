object frmStatsRoutes: TfrmStatsRoutes
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Route Stats'
  ClientHeight = 264
  ClientWidth = 783
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
  object Label2: TLabel
    Left = 130
    Top = 27
    Width = 79
    Height = 13
    Caption = 'Longest route'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lLongest: TLabel
    Left = 226
    Top = 27
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Label3: TLabel
    Left = 24
    Top = 194
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
    Top = 194
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
    Top = 194
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
    Top = 194
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
    Top = 194
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
    Top = 194
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
    Top = 194
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
  object Label10: TLabel
    Left = 342
    Top = 8
    Width = 68
    Height = 13
    Caption = 'Total length'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lTotal: TLabel
    Left = 438
    Top = 8
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Label12: TLabel
    Left = 342
    Top = 27
    Width = 87
    Height = 13
    Caption = 'Average length'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lAverage: TLabel
    Left = 438
    Top = 27
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Label11: TLabel
    Left = 130
    Top = 8
    Width = 83
    Height = 13
    Caption = 'Shortest route'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lShortest: TLabel
    Left = 226
    Top = 8
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Bevel2: TBevel
    Left = 24
    Top = 56
    Width = 736
    Height = 9
    Shape = bsTopLine
  end
  object lc1: TLabel
    Left = 118
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lc2: TLabel
    Left = 224
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lc3: TLabel
    Left = 330
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lc4: TLabel
    Left = 436
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lc5: TLabel
    Left = 542
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lc6: TLabel
    Left = 648
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object lc7: TLabel
    Left = 754
    Top = 69
    Width = 6
    Height = 13
    BiDiMode = bdRightToLeft
    Caption = '0'
    ParentBiDiMode = False
  end
  object Label1: TLabel
    Left = 554
    Top = 8
    Width = 87
    Height = 13
    Caption = 'Source airports'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lFrom: TLabel
    Left = 674
    Top = 8
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Label14: TLabel
    Left = 554
    Top = 27
    Width = 113
    Height = 13
    Caption = 'Destination airports'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lTo: TLabel
    Left = 674
    Top = 27
    Width = 12
    Height = 13
    Caption = '...'
  end
  object Button1: TButton
    Left = 700
    Top = 232
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Close'
    ModalResult = 1
    TabOrder = 0
  end
end
