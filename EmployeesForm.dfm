object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Employees'
  ClientHeight = 960
  ClientWidth = 652
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClick = Sort
  TextHeight = 15
  object Title: TLabel
    Left = 252
    Top = 16
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
  object Label1: TLabel
    Left = 16
    Top = 443
    Width = 165
    Height = 15
    Caption = 'Enter year for monthly analysis:'
  end
  object SortingBox: TGroupBox
    Left = 8
    Top = 252
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
    Top = 60
    Width = 609
    Height = 149
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
    Top = 221
    Width = 193
    Height = 25
    Caption = 'Add employee'
    TabOrder = 1
    OnClick = AddButtonClick
  end
  object DeleteButton: TButton
    Left = 207
    Top = 221
    Width = 202
    Height = 25
    Caption = 'Delete selected employee'
    TabOrder = 2
    OnClick = DeleteButtonClick
  end
  object EditButton: TButton
    Left = 415
    Top = 221
    Width = 202
    Height = 25
    Caption = 'Edit Selected employee'
    TabOrder = 3
    OnClick = EditButtonClick
  end
  object Sorting2Box: TGroupBox
    Left = 199
    Top = 252
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
    Top = 252
    Width = 227
    Height = 121
    Caption = 'Filtering field'
    TabOrder = 6
  end
  object FnFilterOption: TRadioButton
    Left = 424
    Top = 280
    Width = 113
    Height = 17
    Caption = 'First Name'
    TabOrder = 7
    OnClick = Sort
  end
  object LnFilterOption: TRadioButton
    Left = 424
    Top = 303
    Width = 113
    Height = 17
    Caption = 'Last Name'
    TabOrder = 8
    OnClick = Sort
  end
  object DepartmentFilterOption: TRadioButton
    Left = 424
    Top = 326
    Width = 129
    Height = 17
    Caption = 'Department Name'
    Enabled = False
    TabOrder = 9
    OnClick = Sort
  end
  object FilterBox: TEdit
    Left = 390
    Top = 377
    Width = 121
    Height = 23
    TabOrder = 10
    OnChange = Filter
  end
  object ClearFilter: TButton
    Left = 512
    Top = 376
    Width = 105
    Height = 25
    Caption = 'Clear filter'
    TabOrder = 11
    OnClick = ClearFilterClick
  end
  object ReportPrint: TButton
    Left = 8
    Top = 407
    Width = 376
    Height = 25
    Caption = 'Print reports for selected employee'
    TabOrder = 12
    OnClick = ReportPrintClick
  end
  object ReportBox: TGroupBox
    Left = 390
    Top = 406
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
  object DBChart1: TDBChart
    Left = 8
    Top = 711
    Width = 609
    Height = 235
    Title.Text.Strings = (
      'TDBChart')
    View3D = False
    TabOrder = 14
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      HoverElement = []
      Marks.Visible = False
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingQuery
      XLabelsSource = 'Year'
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Year'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'TotalWarrants'
    end
    object Series1: TBarSeries
      HoverElement = []
      Marks.Visible = False
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingQuery
      XLabelsSource = 'Year'
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Year'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'InternationalTravels'
    end
    object Series3: TLineSeries
      HoverElement = [heCurrent]
      DataSource = DataModule1.ChartingQuery
      SeriesColor = 13870501
      Shadow.Color = 2894892
      Shadow.Transparency = 0
      XLabelsSource = 'Year'
      Brush.BackColor = clDefault
      DrawStyle = dsCurve
      LinePen.Color = clDefault
      OutLine.Color = 3158064
      Pointer.HorizSize = 3
      Pointer.InflateMargins = False
      Pointer.Pen.Color = clDefault
      Pointer.Style = psCircle
      Pointer.VertSize = 3
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Year'
      YValues.Name = 'Y'
      YValues.Order = loNone
      YValues.ValueSource = 'AvgDaysPerJourney'
    end
    object Series4: TLineSeries
      HoverElement = [heCurrent]
      Active = False
      DataSource = DataModule1.ChartingQuery
      SeriesColor = 8388672
      Shadow.Color = 2894892
      Shadow.Transparency = 0
      XLabelsSource = 'Year'
      Brush.BackColor = clDefault
      DrawStyle = dsCurve
      LinePen.Color = clDefault
      OutLine.Color = 3158064
      Pointer.HorizSize = 3
      Pointer.InflateMargins = False
      Pointer.Pen.Color = clDefault
      Pointer.Style = psCircle
      Pointer.VertSize = 3
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Year'
      YValues.Name = 'Y'
      YValues.Order = loNone
      YValues.ValueSource = 'AvgMileagePerWarrant'
    end
  end
  object DBChart2: TDBChart
    Left = 8
    Top = 470
    Width = 609
    Height = 228
    Title.Text.Strings = (
      'TDBChart')
    LeftAxis.Increment = 1.000000000000000000
    View3D = False
    TabOrder = 15
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series5: TBarSeries
      HoverElement = []
      Marks.Visible = False
      DataSource = DataModule1.ChartingYearly
      XLabelsSource = 'Monthly'
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Monthly'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'TotalWarrants'
    end
    object Series6: TBarSeries
      HoverElement = []
      Marks.Visible = False
      DataSource = DataModule1.ChartingYearly
      XLabelsSource = 'Monthly'
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Monthly'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'InternationalTravels'
    end
    object Series7: TLineSeries
      HoverElement = [heCurrent]
      Active = False
      DataSource = DataModule1.ChartingYearly
      XLabelsSource = 'Monthly'
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Monthly'
      YValues.Name = 'Y'
      YValues.Order = loNone
      YValues.ValueSource = 'AvgMileage'
    end
    object Series8: TLineSeries
      HoverElement = [heCurrent]
      Active = False
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object YearSelection: TEdit
    Left = 187
    Top = 440
    Width = 197
    Height = 23
    NumbersOnly = True
    TabOrder = 16
    Text = '2022'
  end
  object Button1: TButton
    Left = 390
    Top = 439
    Width = 227
    Height = 25
    Caption = 'Generate analysis'
    TabOrder = 17
    OnClick = Button1Click
  end
  object DBCrossTabSource1: TDBCrossTabSource
    CaseSensitive = False
    Formula = gfCount
    GroupField = 'Year'
    HideSeries = False
    LabelField = 'Year'
    ValueField = 'Warrant'
    DataSet = DataModule1.ChartingQuery
    Left = 672
    Top = 8
  end
  object DBCrossTabSource2: TDBCrossTabSource
    GroupField = 'Year'
    HideSeries = False
    LabelField = 'Year'
    ValueField = 'Warrant'
    DataSet = DataModule1.ChartingQuery
    Left = 912
    Top = 8
  end
  object DBCrossTabSource3: TDBCrossTabSource
    DataSet = DataModule1.ChartingQuery
    Left = 792
    Top = 8
  end
end
