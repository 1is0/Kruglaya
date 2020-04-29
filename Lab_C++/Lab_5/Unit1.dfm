object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 413
  ClientWidth = 719
  Color = clGradientInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 21
    Width = 81
    Height = 13
    Caption = #1056#1072#1079#1084#1077#1088' '#1086#1095#1077#1088#1077#1076#1080
  end
  object Label2: TLabel
    Left = 408
    Top = 16
    Width = 87
    Height = 13
    Caption = #1056#1072#1079#1084#1077#1088' '#1086#1095#1077#1088#1077#1076#1077#1081
  end
  object Edit1: TEdit
    Left = 40
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 0
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 40
    Top = 200
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 408
    Top = 40
    Width = 66
    Height = 21
    TabOrder = 2
    OnChange = Edit3Change
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 67
    Width = 145
    Height = 120
    ColCount = 2
    TabOrder = 3
  end
  object StringGrid2: TStringGrid
    Left = 408
    Top = 67
    Width = 217
    Height = 120
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object Button1: TButton
    Left = 8
    Top = 289
    Width = 193
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090' '#1080#1079' '#1085#1072#1095#1072#1083#1072' '#1086#1095#1077#1088#1077#1076#1080
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 227
    Width = 121
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 40
    Top = 258
    Width = 121
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1087#1080#1089#1086#1082
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 480
    Top = 38
    Width = 145
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1095#1077#1088#1077#1076#1080
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 408
    Top = 193
    Width = 136
    Height = 25
    Caption = #1042#1089#1090#1072#1074#1080#1090#1100' 2 '#1086#1095#1077#1088#1077#1076#1100' '#1074' 1'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 550
    Top = 193
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 10
    OnClick = Button7Click
  end
end
