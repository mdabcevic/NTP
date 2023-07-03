object Form12: TForm12
  Left = 0
  Top = 0
  Caption = 'Company cars'
  ClientHeight = 441
  ClientWidth = 677
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 208
    Top = 32
    Width = 311
    Height = 30
    Caption = 'Information about company cars'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object ListView1: TListView
    Left = 8
    Top = 84
    Width = 662
    Height = 150
    Columns = <
      item
        Caption = 'License Plate'
      end
      item
        Caption = 'Internal Name'
      end
      item
        Caption = 'Accountable '
      end
      item
        Caption = 'Currently used by'
      end
      item
        Caption = 'Location'
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnSelectItem = ListView1SelectItem
  end
  object Button1: TButton
    Left = 8
    Top = 240
    Width = 161
    Height = 25
    Caption = 'Load all cars'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 175
    Top = 240
    Width = 161
    Height = 25
    Caption = 'Add new car'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 342
    Top = 240
    Width = 161
    Height = 25
    Caption = 'Edit selected car'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 509
    Top = 240
    Width = 161
    Height = 25
    Caption = 'Remove selected car'
    TabOrder = 4
    OnClick = Button4Click
  end
end
