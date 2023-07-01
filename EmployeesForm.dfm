object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 442
  ClientWidth = 1115
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 264
    Top = 24
    Width = 60
    Height = 15
    Caption = 'Zaposlenici'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 64
    Width = 1017
    Height = 120
    DataSource = DataModule1.EmployeeDataSource
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
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'FirstName'
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LastName'
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IdentificationNumber'
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Address'
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Username'
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Phone'
        Width = 120
        Visible = True
      end>
  end
end
