object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 441
  ClientWidth = 1111
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
        FieldName = 'FirstName'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LastName'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DepartmentName'
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 8
    Top = 190
    Width = 193
    Height = 25
    Caption = 'Add employee'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 207
    Top = 190
    Width = 202
    Height = 25
    Caption = 'Delete selected employee'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 415
    Top = 190
    Width = 202
    Height = 25
    Caption = 'Edit Selected employee'
    TabOrder = 3
    OnClick = Button3Click
  end
end
