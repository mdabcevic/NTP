object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Form5'
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
    Left = 264
    Top = 16
    Width = 68
    Height = 15
    Caption = 'Departments'
  end
  object DepartmentsGrid: TDBGrid
    Left = 8
    Top = 48
    Width = 612
    Height = 120
    DataSource = DataModule1.DepartmentsDataSource
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'DepartmentCode'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DepartmentName'
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DepartmentHead'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DeputyHead'
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Telephone'
        Width = 95
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 184
    Width = 610
    Height = 25
    DataSource = DataModule1.DepartmentsDataSource
    TabOrder = 1
  end
end
