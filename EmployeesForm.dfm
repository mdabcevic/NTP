object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Employees'
  ClientHeight = 451
  ClientWidth = 634
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClick = Sort
  TextHeight = 15
  object Title: TLabel
    Left = 256
    Top = 24
    Width = 92
    Height = 25
    Caption = 'Employees'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object SortingBox: TGroupBox
    Left = 8
    Top = 221
    Width = 185
    Height = 148
    Caption = 'Sorting field'
    TabOrder = 4
    object NoSortOption: TRadioButton
      Left = 40
      Top = 104
      Width = 113
      Height = 17
      Caption = 'None'
      TabOrder = 0
      OnClick = Sort
    end
    object DepartmentSortOption: TRadioButton
      Left = 40
      Top = 81
      Width = 113
      Height = 17
      Caption = 'Department Name'
      TabOrder = 1
      OnClick = Sort
    end
    object LnSortOption: TRadioButton
      Left = 40
      Top = 58
      Width = 113
      Height = 17
      Caption = 'Last Name'
      TabOrder = 2
      OnClick = Sort
    end
    object FnSortOption: TRadioButton
      Left = 40
      Top = 35
      Width = 113
      Height = 17
      Caption = 'First Name'
      TabOrder = 3
      OnClick = Sort
    end
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 64
    Width = 609
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
        Width = 140
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LastName'
        Width = 140
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
        Width = 140
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DepartmentName'
        Width = 140
        Visible = True
      end>
  end
  object AddButton: TButton
    Left = 8
    Top = 190
    Width = 193
    Height = 25
    Caption = 'Add employee'
    TabOrder = 1
    OnClick = AddButtonClick
  end
  object DeleteButton: TButton
    Left = 207
    Top = 190
    Width = 202
    Height = 25
    Caption = 'Delete selected employee'
    TabOrder = 2
    OnClick = DeleteButtonClick
  end
  object EditButton: TButton
    Left = 415
    Top = 190
    Width = 202
    Height = 25
    Caption = 'Edit Selected employee'
    TabOrder = 3
    OnClick = EditButtonClick
  end
  object Sorting2Box: TGroupBox
    Left = 199
    Top = 221
    Width = 185
    Height = 148
    Caption = 'Sorting direction'
    TabOrder = 5
    object AscSortOption: TRadioButton
      Left = 32
      Top = 51
      Width = 113
      Height = 17
      Caption = 'Ascending'
      TabOrder = 0
      OnClick = Sort
    end
    object DescSortOption: TRadioButton
      Left = 32
      Top = 74
      Width = 113
      Height = 17
      Caption = 'Descending'
      TabOrder = 1
      OnClick = Sort
    end
  end
  object FilteringBox: TGroupBox
    Left = 390
    Top = 221
    Width = 227
    Height = 121
    Caption = 'Filtering field'
    TabOrder = 6
  end
  object FnFilterOption: TRadioButton
    Left = 424
    Top = 249
    Width = 113
    Height = 17
    Caption = 'First Name'
    TabOrder = 7
    OnClick = Sort
  end
  object LnFilterOption: TRadioButton
    Left = 424
    Top = 272
    Width = 113
    Height = 17
    Caption = 'Last Name'
    TabOrder = 8
    OnClick = Sort
  end
  object DepartmentFilterOption: TRadioButton
    Left = 424
    Top = 295
    Width = 129
    Height = 17
    Caption = 'Department Name'
    TabOrder = 9
    OnClick = Sort
  end
  object FilterBox: TEdit
    Left = 390
    Top = 346
    Width = 121
    Height = 23
    TabOrder = 10
    OnChange = Filter
  end
  object ClearFilter: TButton
    Left = 512
    Top = 345
    Width = 105
    Height = 25
    Caption = 'Clear filter'
    TabOrder = 11
    OnClick = ClearFilterClick
  end
  object ReportPrint: TButton
    Left = 8
    Top = 376
    Width = 609
    Height = 25
    Caption = 'Print reports for selected employee'
    TabOrder = 12
    OnClick = ReportPrintClick
  end
end
