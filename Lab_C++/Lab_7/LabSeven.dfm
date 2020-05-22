object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1061#1077#1096#1080#1088#1086#1074#1072#1085#1080#1077
  ClientHeight = 339
  ClientWidth = 573
  Color = clCream
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
    Left = 424
    Top = 13
    Width = 80
    Height = 13
    Caption = 'Amount of Items'
  end
  object Label2: TLabel
    Left = 424
    Top = 96
    Width = 104
    Height = 13
    Caption = 'Size of the hash table'
  end
  object Label3: TLabel
    Left = 32
    Top = 248
    Width = 45
    Height = 13
    Caption = 'Find Item'
  end
  object Label4: TLabel
    Left = 192
    Top = 248
    Width = 56
    Height = 13
    Caption = 'Delete Item'
  end
  object Label5: TLabel
    Left = 350
    Top = 248
    Width = 44
    Height = 13
    Caption = 'Add Item'
  end
  object Memo1: TMemo
    Left = 32
    Top = 16
    Width = 137
    Height = 209
    Enabled = False
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 424
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 424
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 32
    Top = 261
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Button1: TButton
    Left = 32
    Top = 288
    Width = 121
    Height = 25
    Caption = 'Find'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Edit4: TEdit
    Left = 192
    Top = 261
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Button2: TButton
    Left = 192
    Top = 288
    Width = 121
    Height = 25
    Caption = 'Delete'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 424
    Top = 154
    Width = 121
    Height = 41
    Caption = 'Create'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 424
    Top = 201
    Width = 121
    Height = 41
    Caption = 'Show'
    TabOrder = 8
    OnClick = Button4Click
  end
  object RichEdit1: TRichEdit
    Left = 192
    Top = 16
    Width = 185
    Height = 209
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    TabOrder = 9
    Zoom = 100
  end
  object Edit5: TEdit
    Left = 350
    Top = 261
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object Button5: TButton
    Left = 350
    Top = 288
    Width = 121
    Height = 25
    Caption = 'Add'
    TabOrder = 11
    OnClick = Button5Click
  end
end
