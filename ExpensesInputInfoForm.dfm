object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 200
    Top = 32
    Width = 249
    Height = 30
    Alignment = taCenter
    Caption = 'Expenses information'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object CheckBox1: TCheckBox
    Left = 200
    Top = 89
    Width = 249
    Height = 17
    Caption = 'Toll (Road, Tunnel, Ferry, Vignette)'
    TabOrder = 0
  end
  object CheckBox2: TCheckBox
    Left = 200
    Top = 127
    Width = 249
    Height = 17
    Caption = 'Entertainment (Hospitality) Expenses'
    TabOrder = 1
  end
  object CheckBox3: TCheckBox
    Left = 200
    Top = 158
    Width = 249
    Height = 17
    Caption = 'Parking'
    TabOrder = 2
  end
  object CheckBox4: TCheckBox
    Left = 200
    Top = 189
    Width = 249
    Height = 17
    Caption = 'Accomodation'
    TabOrder = 3
  end
  object CheckBox5: TCheckBox
    Left = 200
    Top = 220
    Width = 249
    Height = 17
    Caption = 'Other expenses'
    TabOrder = 4
  end
end
