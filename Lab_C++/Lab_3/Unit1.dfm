object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 422
  ClientWidth = 695
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 321
    Height = 217
    TabOrder = 0
    object Label1: TLabel
      Left = 19
      Top = 62
      Width = 37
      Height = 13
      Caption = #1057#1090#1088#1072#1085#1072
    end
    object Label2: TLabel
      Left = 184
      Top = 17
      Width = 96
      Height = 13
      Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1082#1086#1084#1072#1085#1076#1099
    end
    object Label3: TLabel
      Left = 16
      Top = 16
      Width = 30
      Height = 13
      Caption = #1048#1075#1088#1086#1082
    end
    object Label4: TLabel
      Left = 184
      Top = 63
      Width = 75
      Height = 13
      Caption = #1048#1075#1088#1086#1074#1086#1081' '#1085#1086#1084#1077#1088
    end
    object Label5: TLabel
      Left = 16
      Top = 109
      Width = 40
      Height = 13
      Caption = #1042#1086#1079#1088#1072#1089#1090
    end
    object Label6: TLabel
      Left = 119
      Top = 109
      Width = 45
      Height = 13
      Caption = #1056#1086#1089#1090' ('#1089#1084')'
    end
    object Label7: TLabel
      Left = 230
      Top = 109
      Width = 39
      Height = 13
      Caption = #1042#1077#1089' ('#1082#1075')'
    end
    object Edit1: TEdit
      Left = 184
      Top = 36
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 35
      Width = 145
      Height = 21
      HelpContext = 3
      TabOrder = 1
      OnSelect = ComboBox1Select
    end
    object Edit2: TEdit
      Left = 184
      Top = 80
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit3: TEdit
      Left = 16
      Top = 128
      Width = 65
      Height = 21
      TabOrder = 3
    end
    object Edit4: TEdit
      Left = 119
      Top = 128
      Width = 65
      Height = 21
      TabOrder = 4
    end
    object Edit5: TEdit
      Left = 230
      Top = 128
      Width = 65
      Height = 21
      TabOrder = 5
    end
    object Button7: TButton
      Left = 139
      Top = 169
      Width = 111
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1080#1075#1088#1086#1082#1072
      TabOrder = 6
      OnClick = Button7Click
    end
    object Edit9: TEdit
      Left = 16
      Top = 80
      Width = 121
      Height = 21
      TabOrder = 7
    end
    object Button1: TButton
      Left = 16
      Top = 169
      Width = 105
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1075#1088#1086#1082#1072
      TabOrder = 8
      OnClick = Button1Click
    end
  end
  object Memo1: TMemo
    Left = 360
    Top = 28
    Width = 313
    Height = 205
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 271
    Width = 217
    Height = 130
    TabOrder = 2
    object Label8: TLabel
      Left = 16
      Top = 55
      Width = 171
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1074#1077#1089#1086#1074#1091#1102' '#1082#1072#1090#1077#1075#1086#1088#1080#1102' ('#1082#1075')'
    end
    object Label10: TLabel
      Left = 72
      Top = 88
      Width = 14
      Height = 13
      Caption = #1044#1086
    end
    object Label11: TLabel
      Left = 3
      Top = 88
      Width = 14
      Height = 13
      Caption = #1054#1090
    end
    object Button2: TButton
      Left = 46
      Top = 16
      Width = 118
      Height = 25
      Caption = #1057#1087#1080#1089#1086#1082' '#1074#1089#1077#1093' '#1080#1075#1088#1086#1082#1086#1074
      TabOrder = 0
      OnClick = Button2Click
    end
    object Edit6: TEdit
      Left = 23
      Top = 74
      Width = 43
      Height = 21
      TabOrder = 1
    end
    object Button4: TButton
      Left = 139
      Top = 74
      Width = 75
      Height = 25
      Caption = #1055#1086#1080#1089#1082
      TabOrder = 2
      OnClick = Button4Click
    end
    object Edit8: TEdit
      Left = 90
      Top = 74
      Width = 43
      Height = 21
      TabOrder = 3
    end
  end
  object GroupBox3: TGroupBox
    Left = 239
    Top = 271
    Width = 233
    Height = 130
    TabOrder = 3
    object Label9: TLabel
      Left = 16
      Top = 13
      Width = 199
      Height = 13
      Caption = #1050#1086#1084#1072#1085#1076#1099' '#1089' '#1088#1086#1089#1090#1086#1084' '#1085#1077' '#1085#1080#1078#1077' '#1074#1074#1077#1076#1077#1085#1085#1086#1075#1086
    end
    object Label13: TLabel
      Left = 16
      Top = 104
      Width = 123
      Height = 13
      Caption = #1057#1072#1084#1072#1103' '#1084#1086#1083#1086#1076#1072#1103' '#1082#1086#1084#1072#1085#1076#1072
    end
    object Button5: TButton
      Left = 71
      Top = 59
      Width = 75
      Height = 25
      Caption = #1055#1086#1080#1089#1082
      TabOrder = 0
      OnClick = Button5Click
    end
    object Edit7: TEdit
      Left = 59
      Top = 32
      Width = 94
      Height = 21
      TabOrder = 1
    end
    object Button3: TButton
      Left = 155
      Top = 102
      Width = 75
      Height = 25
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100
      TabOrder = 2
      OnClick = Button3Click
    end
  end
  object Button6: TButton
    Left = 528
    Top = 239
    Width = 123
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1086#1083#1077
    TabOrder = 4
    OnClick = Button6Click
  end
end
