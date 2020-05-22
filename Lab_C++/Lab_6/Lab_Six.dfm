object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 444
  ClientWidth = 1029
  Color = clTeal
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
    Left = 24
    Top = 0
    Width = 68
    Height = 13
    Caption = 'Group 953502'
  end
  object Label2: TLabel
    Left = 400
    Top = 8
    Width = 22
    Height = 13
    Caption = 'Tree'
  end
  object Label3: TLabel
    Left = 20
    Top = 269
    Width = 66
    Height = 13
    Caption = 'Personal data'
  end
  object Label4: TLabel
    Left = 143
    Top = 269
    Width = 104
    Height = 13
    Caption = #8470'  the student ticket'
  end
  object Label5: TLabel
    Left = 23
    Top = 351
    Width = 101
    Height = 13
    Caption = #8470' the student ticket'
  end
  object Label6: TLabel
    Left = 865
    Top = 11
    Width = 128
    Height = 13
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102' '#1074' '
  end
  object Label7: TLabel
    Left = 632
    Top = 272
    Width = 182
    Height = 13
    Caption = 'Amount of nodes have two daughters'
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 19
    Width = 330
    Height = 247
    ColCount = 3
    RowCount = 10
    TabOrder = 0
    ColWidths = (
      64
      128
      115)
    RowHeights = (
      24
      24
      24
      23
      24
      24
      24
      24
      24
      24)
  end
  object TreeView1: TTreeView
    Left = 344
    Top = 27
    Width = 258
    Height = 225
    Indent = 19
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 624
    Top = 27
    Width = 249
    Height = 225
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 16
    Top = 288
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 143
    Top = 288
    Width = 90
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 64
    Top = 315
    Width = 121
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 20
    Top = 370
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Button2: TButton
    Left = 147
    Top = 346
    Width = 90
    Height = 25
    Caption = 'Find'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 879
    Top = 95
    Width = 101
    Height = 42
    Caption = #1086#1073#1088#1072#1090#1085#1086#1084' '#1074#1080#1076#1077
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 879
    Top = 159
    Width = 101
    Height = 42
    Caption = #1087#1086#1088#1103#1076#1082#1077' '#1074#1086#1079#1088#1072#1089#1090'.'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 392
    Top = 258
    Width = 153
    Height = 37
    Caption = 'Show Tree'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 879
    Top = 30
    Width = 101
    Height = 43
    Caption = #1087#1088#1103#1084#1086#1084' '#1074#1080#1076#1077
    TabOrder = 11
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 147
    Top = 385
    Width = 90
    Height = 25
    Caption = 'Delete'
    TabOrder = 12
    OnClick = Button7Click
  end
  object Button9: TButton
    Left = 632
    Top = 286
    Width = 241
    Height = 25
    Caption = 'Show'
    TabOrder = 13
    OnClick = Button9Click
  end
end
