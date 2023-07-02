object Form10: TForm10
  Left = 0
  Top = 0
  Caption = 'Clients'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Title: TLabel
    Left = 192
    Top = 24
    Width = 240
    Height = 30
    Caption = 'Information about clients'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object ListView1: TListView
    Left = 8
    Top = 88
    Width = 608
    Height = 150
    Columns = <
      item
        AutoSize = True
        Caption = 'Company Name'
      end
      item
        Caption = 'Address'
        Width = 120
      end
      item
        Caption = 'ID Number'
        Width = 120
      end
      item
        Caption = 'Email'
        Width = 120
      end
      item
        Caption = 'Contact Person'
        Width = 120
      end>
    TabOrder = 0
    ViewStyle = vsReport
  end
end
