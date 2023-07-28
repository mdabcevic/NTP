object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Employees'
  ClientHeight = 601
  ClientWidth = 1100
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
    Top = 357
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
    Height = 249
    DataSource = DataModule1.EmployeeDataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
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
        FieldName = 'EmployeeDepartment'
        Visible = True
      end>
  end
  object AddButton: TButton
    Left = 8
    Top = 326
    Width = 193
    Height = 25
    Caption = 'Add employee'
    TabOrder = 1
    OnClick = AddButtonClick
  end
  object DeleteButton: TButton
    Left = 207
    Top = 326
    Width = 202
    Height = 25
    Caption = 'Delete selected employee'
    TabOrder = 2
    OnClick = DeleteButtonClick
  end
  object EditButton: TButton
    Left = 415
    Top = 326
    Width = 202
    Height = 25
    Caption = 'Edit Selected employee'
    TabOrder = 3
    OnClick = EditButtonClick
  end
  object Sorting2Box: TGroupBox
    Left = 199
    Top = 357
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
    Top = 357
    Width = 227
    Height = 121
    Caption = 'Filtering field'
    TabOrder = 6
  end
  object FnFilterOption: TRadioButton
    Left = 424
    Top = 385
    Width = 113
    Height = 17
    Caption = 'First Name'
    TabOrder = 7
    OnClick = Sort
  end
  object LnFilterOption: TRadioButton
    Left = 424
    Top = 408
    Width = 113
    Height = 17
    Caption = 'Last Name'
    TabOrder = 8
    OnClick = Sort
  end
  object DepartmentFilterOption: TRadioButton
    Left = 424
    Top = 431
    Width = 129
    Height = 17
    Caption = 'Department Name'
    Enabled = False
    TabOrder = 9
    OnClick = Sort
  end
  object FilterBox: TEdit
    Left = 390
    Top = 482
    Width = 121
    Height = 23
    TabOrder = 10
    OnChange = Filter
  end
  object ClearFilter: TButton
    Left = 512
    Top = 481
    Width = 105
    Height = 25
    Caption = 'Clear filter'
    TabOrder = 11
    OnClick = ClearFilterClick
  end
  object ReportPrint: TButton
    Left = 8
    Top = 512
    Width = 376
    Height = 25
    Caption = 'Print reports for selected employee'
    TabOrder = 12
    OnClick = ReportPrintClick
  end
  object ReportBox: TGroupBox
    Left = 390
    Top = 511
    Width = 227
    Height = 26
    TabOrder = 13
    object PDFRadio: TRadioButton
      Left = 40
      Top = 6
      Width = 57
      Height = 17
      Caption = 'PDF'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RDFRadio: TRadioButton
      Left = 135
      Top = 6
      Width = 50
      Height = 17
      Caption = 'RTF'
      TabOrder = 1
    end
  end
  object EmpTotalChart: TChart
    Left = 632
    Top = 64
    Width = 400
    Height = 233
    BackWall.Pen.Visible = False
    BottomWall.Brush.Gradient.EndColor = clSilver
    BottomWall.Brush.Gradient.StartColor = clGray
    BottomWall.Brush.Gradient.Visible = True
    BottomWall.Pen.Color = clGray
    BottomWall.Size = 4
    Gradient.Direction = gdFromTopLeft
    Gradient.EndColor = clWhite
    Gradient.StartColor = clSilver
    Gradient.Visible = True
    LeftWall.Brush.Gradient.EndColor = clSilver
    LeftWall.Brush.Gradient.StartColor = clGray
    LeftWall.Brush.Gradient.Visible = True
    LeftWall.Color = clWhite
    LeftWall.Pen.Color = clGray
    LeftWall.Size = 4
    MarginLeft = 4
    MarginRight = 4
    Title.Text.Strings = (
      'TChart')
    BottomAxis.Grid.Color = 14540253
    BottomAxis.LabelsFormat.Font.Color = clGray
    BottomAxis.LabelsFormat.Font.Height = -9
    BottomAxis.LabelStyle = talValue
    Frame.Visible = False
    LeftAxis.Grid.Color = 14540253
    LeftAxis.LabelsFormat.Font.Color = clGray
    LeftAxis.LabelsFormat.Font.Height = -9
    LeftAxis.LabelStyle = talValue
    Zoom.Animated = True
    BevelWidth = 2
    Color = clWhite
    TabOrder = 14
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      HoverElement = []
      Active = False
      DataSource = DBCrossTabSource1
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series2: TBarSeries
      HoverElement = []
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series3: TBarSeries
      HoverElement = []
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object Chart2: TChart
    Left = 632
    Top = 314
    Width = 400
    Height = 223
    Title.Text.Strings = (
      'TChart')
    TabOrder = 15
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
  end
  object DBCrossTabSource1: TDBCrossTabSource
    Active = True
    CaseSensitive = False
    Formula = gfCount
    GroupField = 'Yearly'
    LabelField = 'Yearly'
    Series = Series1
    ValueField = 'TotalWarrants'
    DataSet = DataModule1.ChartingQuery
    Left = 672
    Top = 8
  end
end
