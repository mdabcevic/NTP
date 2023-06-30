object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Test Window'
  ClientHeight = 422
  ClientWidth = 614
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LoadIni_test: TButton
    Left = 0
    Top = 0
    Width = 185
    Height = 25
    Caption = 'Load INI settings TEST'
    TabOrder = 0
    OnClick = LoadIni_testClick
  end
  object SaveIni_Test: TButton
    Left = 0
    Top = 31
    Width = 185
    Height = 25
    Caption = 'Save INI settings TEST'
    TabOrder = 1
    OnClick = SaveIni_TestClick
  end
  object LoadWR_Test: TButton
    Left = 0
    Top = 62
    Width = 185
    Height = 25
    Caption = 'Load WR settings TEST'
    TabOrder = 2
    OnClick = LoadWR_TestClick
  end
  object Button1: TButton
    Left = 0
    Top = 93
    Width = 185
    Height = 25
    Caption = 'Delete WR settings TEST'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 124
    Width = 185
    Height = 25
    Caption = 'Save WR settings TEST'
    TabOrder = 4
    OnClick = Button2Click
  end
  object ListView1: TListView
    Left = 2
    Top = 211
    Width = 604
    Height = 94
    Columns = <
      item
        Caption = 'License plate'
      end
      item
        Caption = 'Internal name'
      end
      item
        Caption = 'Assigned to'
      end
      item
        Caption = 'Current user'
      end
      item
        Caption = 'Location'
      end>
    Ctl3D = True
    RowSelect = True
    TabOrder = 5
    ViewStyle = vsReport
  end
  object Button3: TButton
    Left = 2
    Top = 311
    Width = 105
    Height = 25
    Caption = 'Load all cars'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 155
    Width = 185
    Height = 25
    Caption = 'Reset to Default INI TEST'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 113
    Top = 311
    Width = 104
    Height = 25
    Caption = 'Add car'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 223
    Top = 311
    Width = 154
    Height = 25
    Caption = 'Remove selected car'
    TabOrder = 9
    OnClick = Button6Click
  end
end
