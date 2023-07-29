object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Employees'
  ClientHeight = 960
  ClientWidth = 629
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
        FieldName = 'EmployeeID'
        Title.Caption = #353'ifra'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ime'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'prezime'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'EmployeeDepartment'
        Title.Caption = 'odjel'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'nalozi'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Username'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
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
    BackWall.Pen.Width = 0
    Border.Width = 0
    Title.Alignment = taRightJustify
    Title.Font.Color = clBlack
    Title.Font.Height = -13
    Title.Font.Name = 'Segoe UI'
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      'Total analysis')
    BottomAxis.Axis.Visible = False
    BottomAxis.Grid.Visible = False
    DepthAxis.Axis.Width = 0
    DepthTopAxis.Axis.Width = 0
    Frame.Width = 0
    LeftAxis.Axis.Width = 0
    LeftAxis.Axis.Visible = False
    Legend.Alignment = laBottom
    Legend.CheckBoxes = True
    Legend.Frame.Width = 0
    Legend.Symbol.Pen.Width = 0
    Legend.TextSymbolGap = 3
    View3D = False
    TabOrder = 14
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      HoverElement = []
      BarPen.Width = 0
      Marks.Visible = False
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingQuery
      Title = 'Svi nalozi'
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
      BarPen.Width = 0
      Marks.Visible = False
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingQuery
      Title = 'Inozemni nalozi'
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
      Legend.Text = 'Prosje'#269'no dana na terenu'
      LegendTitle = 'Prosje'#269'no dana na terenu'
      Marks.Font.Color = 8388672
      Marks.Font.Name = 'Segoe UI Light'
      Marks.Font.Style = [fsBold]
      Marks.Font.DefaultFont = True
      Marks.Font.OutLine.Width = 0
      Marks.Font.OutLine.Visible = True
      Marks.Frame.Visible = False
      Marks.Visible = True
      Marks.Margins.Left = 10
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingQuery
      SeriesColor = 13870501
      Shadow.Color = 2894892
      Shadow.Transparency = 0
      Title = 'Prosjek dana na terenu'
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
      Marks.Visible = True
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingQuery
      SeriesColor = 8388672
      Shadow.Color = 2894892
      Shadow.Transparency = 0
      Title = 'Prosje'#269'na kilometra'#382'a'
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
    BackWall.Pen.Width = 0
    LeftWall.Pen.Width = 0
    MarginBottom = 2
    MarginLeft = 2
    MarginRight = 2
    MarginTop = 2
    ScrollMouseButton = mbLeft
    Title.Alignment = taRightJustify
    Title.Font.Color = clBlack
    Title.Font.Height = -13
    Title.Font.Name = 'Segoe UI'
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      'Monthly analysis for chosen year')
    BottomAxis.Axis.Width = 0
    BottomAxis.Axis.Visible = False
    BottomAxis.Grid.Visible = False
    BottomAxis.Title.Pen.Visible = False
    BottomAxis.Items = {
      0C00000001045465787406034A616E0556616C7565050000000000000080FF3F
      0001045465787406034665620556616C75650500000000000000800040000104
      5465787406034D61720556616C75650500000000000000C00040000104546578
      7406034170720556616C75650500000000000000800140000104546578740605
      4D61790D0A0556616C75650500000000000000A001400001045465787406074A
      756E0D0A0D0A0556616C75650500000000000000C00140000104546578740603
      4A756C0556616C75650500000000000000E00140000104546578740605417567
      0D0A0556616C7565050000000000000080024000010454657874060353657005
      56616C756505000000000000009002400001045465787406034F63740556616C
      75650500000000000000A002400001045465787406034E6F760556616C756505
      00000000000000B002400001045465787406034465630556616C756505000000
      00000000C0024000}
    DepthAxis.Axis.Width = 0
    DepthAxis.Title.Pen.Visible = False
    DepthTopAxis.Axis.Width = 0
    DepthTopAxis.Title.Pen.Visible = False
    Frame.Width = 0
    LeftAxis.Axis.Width = 0
    LeftAxis.Axis.Visible = False
    LeftAxis.Increment = 1.000000000000000000
    LeftAxis.Title.Visible = False
    LeftAxis.Title.Pen.Width = 0
    Legend.Alignment = laBottom
    Legend.CheckBoxes = True
    Panning.MouseWheel = pmwNone
    RightAxis.Axis.Width = 0
    TopAxis.Axis.Width = 4
    View3D = False
    Zoom.MouseButton = mbRight
    ZoomWheel = pmwNormal
    TabOrder = 15
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series5: TBarSeries
      HoverElement = []
      BarPen.Width = 0
      Marks.Visible = False
      DataSource = DataModule1.ChartingYearly
      Title = 'Svi nalozi'
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
      Legend.Text = 'Inozemni nalozi'
      LegendTitle = 'Inozemni nalozi'
      BarPen.Width = 0
      Marks.Visible = False
      DataSource = DataModule1.ChartingYearly
      Title = 'Inozemni'
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
      Marks.Transparent = True
      Marks.Visible = True
      Marks.Style = smsValue
      DataSource = DataModule1.ChartingYearly
      Title = 'Ukupna kilometra'#382'a'
      XLabelsSource = 'Monthly'
      Brush.BackColor = clDefault
      Pointer.HorizSize = 3
      Pointer.InflateMargins = True
      Pointer.Style = psCircle
      Pointer.VertSize = 3
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'Monthly'
      YValues.Name = 'Y'
      YValues.Order = loNone
      YValues.ValueSource = 'AvgMileage'
    end
    object Series8: TLineSeries
      HoverElement = [heCurrent]
      Legend.Visible = False
      Active = False
      ShowInLegend = False
      Title = 'Dani na terenu'
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
    Caption = 'Refresh'
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
