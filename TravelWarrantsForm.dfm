object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Travel Warrants'
  ClientHeight = 441
  ClientWidth = 1119
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 520
    Top = 24
    Width = 154
    Height = 30
    Caption = 'Travel Warrants'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 60
    Width = 1103
    Height = 120
    DataSource = DataModule1.WarrantsDataSource
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'EmployeeID'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Departure'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Arrival'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Partners'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Purposes'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LicensePlate'
        Width = 75
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Mileage'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Toll'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'OtherVehicles'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'AuthorizedBy'
        Width = 100
        Visible = True
      end>
  end
  object Button2: TButton
    Left = 423
    Top = 186
    Width = 386
    Height = 25
    Caption = 'Delete selected warrant'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 186
    Width = 409
    Height = 25
    Caption = 'Edit selected warrant'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button1: TButton
    Left = 815
    Top = 186
    Width = 296
    Height = 25
    Caption = 'Generate report for selected warrant'
    TabOrder = 3
    OnClick = Button1Click
  end
end
