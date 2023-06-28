object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Test Window'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LoadIni_test: TButton
    Left = 8
    Top = 8
    Width = 185
    Height = 25
    Caption = 'Load INI settings TEST'
    TabOrder = 0
    OnClick = LoadIni_testClick
  end
  object SaveIni_Test: TButton
    Left = 8
    Top = 39
    Width = 185
    Height = 25
    Caption = 'Save INI settings TEST'
    TabOrder = 1
  end
  object LoadWR_Test: TButton
    Left = 8
    Top = 70
    Width = 185
    Height = 25
    Caption = 'Load WR settings TEST'
    TabOrder = 2
  end
end
