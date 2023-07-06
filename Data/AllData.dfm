object DataModule1: TDataModule1
  Height = 680
  Width = 1084
  object XmlDoc: TXMLDocument
    Active = True
    FileName = 
      'C:\Users\Maja\Documents\Embarcadero\Studio\Projects\NTP projekt\' +
      'companycars.xml'
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 40
    Top = 32
  end
  object Connection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLNCLI11.1;Integrated Security=SSPI;Persist Security I' +
      'nfo=False;User ID="";Initial Catalog=PutniNaloziDB;Data Source=l' +
      'ocalhost\SQLEXPRESS;Initial File Name="";Server SPN=""'
    LoginPrompt = False
    Provider = 'SQLNCLI11.1'
    Left = 40
    Top = 120
  end
  object EmployeeTable: TADOTable
    Active = True
    Connection = Connection
    CursorType = ctStatic
    TableName = 'Employees'
    Left = 128
    Top = 120
  end
  object EmployeeDataSource: TDataSource
    DataSet = EmployeeQuery
    Left = 384
    Top = 120
  end
  object EmployeeQuery: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT e.EmployeeID, e.FirstName, e.LastName, e.Email, d.Departm' +
        'entName'
      'FROM Employees as e'
      
        'INNER JOIN Departments as d ON e.DepartmentCode = d.DepartmentCo' +
        'de')
    Left = 256
    Top = 120
  end
  object DepartmentsQuery: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT d.DepartmentName, head.FirstName, head.LastName, deputy.F' +
        'irstName, deputy.LastName'
      'FROM Departments AS d '
      
        'INNER JOIN Employees AS head ON d.DepartmentHead = head.Employee' +
        'ID'
      
        'INNER JOIN Employees AS deputy ON d.DeputyHead = deputy.Employee' +
        'ID')
    Left = 256
    Top = 200
  end
  object DepartmentsDataSource: TDataSource
    DataSet = DepartmentsTable
    Left = 384
    Top = 200
  end
  object DepartmentsTable: TADOTable
    Active = True
    Connection = Connection
    CursorType = ctStatic
    TableName = 'Departments'
    Left = 128
    Top = 200
  end
  object OpenDialog1: TOpenDialog
    Left = 128
    Top = 32
  end
  object ExpensesQuery: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT *'
      'FROM TravelExpenses')
    Left = 256
    Top = 272
  end
  object ExpensesDataSource: TDataSource
    DataSet = ExpensesQuery
    Left = 384
    Top = 272
  end
  object WarrantsQuery: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    OnCalcFields = WarrantsQueryCalcFields
    Parameters = <>
    SQL.Strings = (
      'SELECT *'
      'FROM TravelWarrants')
    Left = 256
    Top = 344
    object WarrantsQueryMileage: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'Mileage'
      Calculated = True
    end
    object WarrantsQueryWarrantID: TAutoIncField
      FieldName = 'WarrantID'
      ReadOnly = True
    end
    object WarrantsQueryEmployeeID: TIntegerField
      FieldName = 'EmployeeID'
    end
    object WarrantsQueryCreatedAt: TDateTimeField
      FieldName = 'CreatedAt'
    end
    object WarrantsQueryDeparture: TDateTimeField
      FieldName = 'Departure'
    end
    object WarrantsQueryArrival: TDateTimeField
      FieldName = 'Arrival'
    end
    object WarrantsQueryIsInternational: TBooleanField
      FieldName = 'IsInternational'
    end
    object WarrantsQueryPartners: TWideStringField
      FieldName = 'Partners'
      FixedChar = True
      Size = 100
    end
    object WarrantsQueryPurposes: TWideStringField
      FieldName = 'Purposes'
      FixedChar = True
      Size = 100
    end
    object WarrantsQueryAttachmentID: TIntegerField
      FieldName = 'AttachmentID'
    end
    object WarrantsQueryStartingOdometer: TIntegerField
      FieldName = 'StartingOdometer'
    end
    object WarrantsQueryEndingOdometer: TIntegerField
      FieldName = 'EndingOdometer'
    end
    object WarrantsQueryToll: TWideStringField
      FieldName = 'Toll'
      FixedChar = True
      Size = 50
    end
    object WarrantsQueryLicensePlate: TWideStringField
      FieldName = 'LicensePlate'
      FixedChar = True
    end
    object WarrantsQueryOtherVehicles: TWideStringField
      FieldName = 'OtherVehicles'
      FixedChar = True
      Size = 10
    end
    object WarrantsQueryAuthorizedBy: TIntegerField
      FieldName = 'AuthorizedBy'
    end
  end
  object WarrantsDataSource: TDataSource
    DataSet = WarrantsQuery
    Left = 384
    Top = 344
  end
  object EmployeeLayout: TfrxReport
    Version = '2022.2.7'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 45109.764086875000000000
    ReportOptions.LastChange = 45111.711624074070000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 672
    Top = 216
    Datasets = <
      item
        DataSet = frxDBEmployee
        DataSetName = 'Employee'
      end
      item
        DataSet = WarrantDetail
        DataSetName = 'Warrants'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 56.692950000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 7.559060000000000000
          Width = 714.331170000000000000
          Height = 41.574830000000000000
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Segoe UI Semibold'
          Font.Style = [fsBold, fsItalic]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'IZVJESCE O PUTNIM NALOZIMA ZA ZAPOSLENIKA')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 151.181200000000000000
        Top = 136.063080000000000000
        Width = 718.110700000000000000
        DataSet = frxDBEmployee
        DataSetName = 'Employee'
        RowCount = 0
        object Shape1: TfrxShapeView
          AllowVectorExport = True
          Top = 98.267780000000000000
          Width = 737.008350000000000000
          Height = 34.015770000000000000
          Fill.BackColor = 13434828
          Fill.ForeColor = 13434828
          Frame.Typ = []
        end
        object EmployeeFirstName: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 7.559060000000000000
          Width = 309.921460000000000000
          Height = 41.574830000000000000
          DataField = 'FirstName'
          DataSet = frxDBEmployee
          DataSetName = 'Employee'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Segoe UI Semibold'
          Font.Style = [fsBold, fsItalic]
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[Employee."FirstName"]')
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 366.614410000000000000
          Top = 7.559060000000000000
          Width = 347.716760000000000000
          Height = 41.574830000000000000
          DataSet = frxDBEmployee
          DataSetName = 'Employee'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Segoe UI Semibold'
          Font.Style = [fsBold, fsItalic]
          Frame.Typ = []
          Memo.UTF8W = (
            '[Employee."LastName"]')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 102.047310000000000000
          Width = 154.960730000000000000
          Height = 26.456710000000000000
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Sifra naloga')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 170.078850000000000000
          Top = 102.047310000000000000
          Width = 166.299320000000000000
          Height = 26.456710000000000000
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Datum')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 343.937230000000000000
          Top = 102.047310000000000000
          Width = 170.078850000000000000
          Height = 26.456710000000000000
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Partneri')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 544.252320000000000000
          Top = 102.047310000000000000
          Width = 170.078850000000000000
          Height = 26.456710000000000000
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Razlog')
          ParentFont = False
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Left = 79.370130000000000000
          Top = 52.913420000000000000
          Width = 563.149970000000000000
          Color = clAppWorkSpace
          Frame.Typ = [ftTop]
        end
      end
      object DetailData1: TfrxDetailData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 71.811070000000000000
        Top = 309.921460000000000000
        Width = 718.110700000000000000
        DataSet = WarrantDetail
        DataSetName = 'Warrants'
        RowCount = 0
        object WarrantsWarrantID: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 15.118120000000000000
          Width = 154.960730000000000000
          Height = 22.677180000000000000
          DataField = 'WarrantID'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[Warrants."WarrantID"]')
          ParentFont = False
        end
        object WarrantsCreatedAt: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 192.756030000000000000
          Top = 15.118120000000000000
          Width = 143.622140000000000000
          Height = 22.677180000000000000
          DataField = 'CreatedAt'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[Warrants."CreatedAt"]')
          ParentFont = False
        end
        object WarrantsPartners: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 343.937230000000000000
          Top = 15.118120000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'Partners'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[Warrants."Partners"]')
          ParentFont = False
        end
        object WarrantsPurposes: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 544.252320000000000000
          Top = 15.118120000000000000
          Width = 170.078850000000000000
          Height = 22.677180000000000000
          DataField = 'Purposes'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[Warrants."Purposes"]')
          ParentFont = False
        end
      end
    end
  end
  object frxDBEmployee: TfrxDBDataset
    RangeBegin = rbCurrent
    RangeEnd = reCurrent
    UserName = 'Employee'
    CloseDataSource = False
    DataSet = EmployeeTable
    BCDToCurrency = False
    DataSetOptions = []
    Left = 776
    Top = 144
  end
  object JoinedReport: TADOQuery
    Connection = Connection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'WarrantID'
        Attributes = [paSigned, paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT'#9'ISNULL(e.FirstName + '#39' '#39', '#39#39') + ISNULL(e.LastName, '#39#39') AS' +
        ' FullName, '
      
        #9#9'd.DepartmentName, t.CreatedAt, t.Departure, t.Arrival, t.IsInt' +
        'ernational, '
      
        #9#9't.Partners, t.Purposes, t.StartingOdometer, t.EndingOdometer, ' +
        't.LicensePlate,'
      #9#9't.OtherVehicles'
      'FROM Employees as e '
      'INNER JOIN TravelWarrants as t ON e.EmployeeID = t.EmployeeID'
      
        'INNER JOIN Departments as d on e.DepartmentCode = d.DepartmentCo' +
        'de'
      'WHERE t.WarrantID = :WarrantID'
      '')
    Left = 880
    Top = 80
  end
  object WarrantReport: TfrxDBDataset
    RangeBegin = rbCurrent
    RangeEnd = reCurrent
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = JoinedReport
    BCDToCurrency = False
    DataSetOptions = []
    Left = 880
    Top = 144
  end
  object WarrantLayout: TfrxReport
    Version = '2022.2.7'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 45111.020645266200000000
    ReportOptions.LastChange = 45111.020645266200000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 880
    Top = 216
    Datasets = <
      item
        DataSet = WarrantReport
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 98.267780000000000000
          Top = 7.559060000000000000
          Width = 495.118430000000000000
          Height = 37.795300000000000000
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'IZVJE'#352#262'E O SLU'#381'BENOM PUTOVANJU')
        end
      end
      object AllInfo: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 759.685530000000000000
        Top = 102.047310000000000000
        Width = 718.110700000000000000
        DataSet = WarrantReport
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 495.118430000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'REGISTRACIJA VOZILA')
        end
        object frxDBDataset1LicensePlate: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 495.118430000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'LicensePlate'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."LicensePlate"]')
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 536.693260000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'BROJILO (PO'#268'ETAK)')
        end
        object frxDBDataset1StartingOdometer: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 536.693260000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'StartingOdometer'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."StartingOdometer"]')
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 578.268090000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'BROJILO (KRAJ)')
        end
        object frxDBDataset1EndingOdometer: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 578.268090000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'EndingOdometer'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."EndingOdometer"]')
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 619.842920000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'CESTARINA')
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 366.614410000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'NAZIVI PARTNERA')
        end
        object frxDBDataset1Partners: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 362.834880000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'Partners'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."Partners"]')
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 404.409710000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'RAZLOZI PUTOVANJA')
        end
        object frxDBDataset1Purposes: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 404.409710000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'Purposes'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."Purposes"]')
        end
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 34.015770000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'IME I PREZIME:')
        end
        object frxDBDataset1FullName: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 34.015770000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'FullName'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."FullName"]')
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 71.811070000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'ODJEL')
        end
        object frxDBDataset1DepartmentName: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 71.811070000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'DepartmentName'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."DepartmentName"]')
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 109.606370000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'DATUM PISANJA')
        end
        object frxDBDataset1CreatedAt: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 109.606370000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'CreatedAt'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."CreatedAt"]')
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 200.315090000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'POLAZAK')
        end
        object frxDBDataset1Departure: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 200.315090000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'Departure'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."Departure"]')
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 238.110390000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'POVRATAK')
        end
        object frxDBDataset1Arrival: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 238.110390000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'Arrival'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."Arrival"]')
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 11.338590000000000000
          Top = 275.905690000000000000
          Width = 173.858380000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'INOZEMNO PUTOVANJE')
        end
        object frxDBDataset1IsInternational: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 207.874150000000000000
          Top = 275.905690000000000000
          Width = 328.819110000000000000
          Height = 18.897650000000000000
          DataField = 'IsInternational'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."IsInternational"]')
        end
      end
    end
  end
  object PDFExport: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    EmbedFontsIfProtected = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 776
    Top = 296
  end
  object RTFExport: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    OpenAfterExport = False
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 776
    Top = 360
  end
  object WarrantDetail: TfrxDBDataset
    UserName = 'Warrants'
    CloseDataSource = False
    DataSet = WarrantsTable
    BCDToCurrency = False
    DataSetOptions = []
    Left = 672
    Top = 144
  end
  object WarrantsTable: TADOTable
    Active = True
    Connection = Connection
    CursorType = ctStatic
    TableName = 'TravelWarrants'
    Left = 128
    Top = 272
  end
  object TCPClient: TIdTCPClient
    ConnectTimeout = 0
    Host = '127.0.0.1'
    Port = 26138
    ReadTimeout = -1
    Left = 40
    Top = 472
  end
  object UDPClient: TIdUDPClient
    Active = True
    Host = '127.0.0.1'
    Port = 16138
    Left = 128
    Top = 472
  end
  object HTTP: TIdHTTP
    IOHandler = SSLHandler
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 112
    Top = 592
  end
  object SSLHandler: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 40
    Top = 592
  end
  object AsymCryptLib: TCryptographicLibrary
    Left = 704
    Top = 568
  end
  object MultiQuery: TADOQuery
    Connection = Connection
    Parameters = <>
    Left = 256
    Top = 416
  end
  object AsymSign: TSignatory
    Codec = AsymCodec
    Left = 704
    Top = 512
  end
  object AsymCodec: TCodec
    AsymetricKeySizeInBits = 512
    AdvancedOptions2 = []
    CryptoLibrary = AsymCryptLib
    Left = 704
    Top = 456
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = ''
  end
end
