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
    Width = 65
    Height = 13
    Caption = 'Size of queue'
  end
  object Label2: TLabel
    Left = 408
    Top = 16
    Width = 70
    Height = 13
    Caption = 'Size of queues'
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
    Top = 272
    Width = 121
    Height = 21
    DoubleBuffered = False
    ParentDoubleBuffered = False
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
    Height = 199
    ColCount = 2
    TabOrder = 3
  end
  object StringGrid2: TStringGrid
    Left = 408
    Top = 67
    Width = 217
    Height = 216
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object Button1: TButton
    Left = 8
    Top = 361
    Width = 193
    Height = 25
    Caption = 'Delete an item from the begining'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 299
    Width = 121
    Height = 25
    Caption = 'Add element'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 40
    Top = 330
    Width = 121
    Height = 25
    Caption = 'Delete the queue'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 480
    Top = 38
    Width = 145
    Height = 25
    Caption = 'Create queues'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 408
    Top = 289
    Width = 136
    Height = 25
    Caption = 'Insert 2 in 1'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 550
    Top = 289
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 10
    OnClick = Button7Click
  end
end
