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
      'WITH EmployeeAggregates AS ('
      '    SELECT '
      '        emp.EmployeeID,'
      '        MAX(emp.FirstName) AS ime,'
      '        MAX(emp.LastName) AS prezime,'
      '        MAX(emp.DepartmentCode) AS odjel,'
      '        COUNT(tw.WarrantID) AS nalozi'
      '    FROM Employees AS emp '
      
        '    INNER JOIN TravelWarrants AS tw ON emp.EmployeeID = tw.Emplo' +
        'yeeID'
      '    GROUP BY emp.EmployeeID'
      ')'
      'SELECT '
      '    ea.ime,'
      '    ea.prezime,'
      '    ea.odjel,'
      '    ea.nalozi,'
      '    emp.* -- Select all columns from the Employees table'
      'FROM EmployeeAggregates AS ea'
      'INNER JOIN Employees AS emp ON ea.EmployeeID = emp.EmployeeID'
      'ORDER BY ea.nalozi DESC;')
    Left = 256
    Top = 120
    object EmployeeQueryEmployeeID: TAutoIncField
      FieldName = 'EmployeeID'
      ReadOnly = True
    end
    object EmployeeQueryFirstName: TWideStringField
      FieldName = 'FirstName'
      FixedChar = True
    end
    object EmployeeQueryLastName: TWideStringField
      FieldName = 'LastName'
      FixedChar = True
    end
    object EmployeeQueryIdentificationNumber: TWideStringField
      FieldName = 'IdentificationNumber'
      FixedChar = True
    end
    object EmployeeQueryDepartmentCode: TIntegerField
      FieldName = 'DepartmentCode'
    end
    object EmployeeQueryJobID: TIntegerField
      FieldName = 'JobID'
    end
    object EmployeeQueryEducation: TWideStringField
      FieldName = 'Education'
      FixedChar = True
      Size = 50
    end
    object EmployeeQueryDriverLicense: TBooleanField
      FieldName = 'DriverLicense'
    end
    object EmployeeQueryAddress: TWideStringField
      FieldName = 'Address'
      FixedChar = True
      Size = 50
    end
    object EmployeeQueryDepositAccountNumber: TWideStringField
      FieldName = 'DepositAccountNumber'
      FixedChar = True
      Size = 50
    end
    object EmployeeQueryTenure: TIntegerField
      FieldName = 'Tenure'
    end
    object EmployeeQueryUsername: TWideStringField
      FieldName = 'Username'
      FixedChar = True
    end
    object EmployeeQueryPassword: TWideStringField
      FieldName = 'Password'
      FixedChar = True
      Size = 100
    end
    object EmployeeQueryEmail: TWideStringField
      FieldName = 'Email'
      FixedChar = True
      Size = 50
    end
    object EmployeeQueryPhone: TWideStringField
      FieldName = 'Phone'
      FixedChar = True
    end
    object EmployeeQueryEmployeeDepartment: TStringField
      FieldKind = fkLookup
      FieldName = 'EmployeeDepartment'
      LookupDataSet = DepartmentsTable
      LookupKeyFields = 'DepartmentCode'
      LookupResultField = 'DepartmentName'
      KeyFields = 'DepartmentCode'
      Lookup = True
    end
    object EmployeeQueryime: TWideStringField
      FieldName = 'ime'
      ReadOnly = True
      FixedChar = True
    end
    object EmployeeQueryprezime: TWideStringField
      FieldName = 'prezime'
      ReadOnly = True
      FixedChar = True
    end
    object EmployeeQueryodjel: TIntegerField
      FieldName = 'odjel'
      ReadOnly = True
    end
    object EmployeeQuerynalozi: TIntegerField
      FieldName = 'nalozi'
      ReadOnly = True
    end
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
      'WITH AllExpenses AS ('
      '    SELECT tw.AttachmentID, tw.WarrantID,'
      
        '        CASE WHEN te.TransportationToll = 1 THEN '#39'Cestarina, '#39' E' +
        'LSE '#39#39' END +'
      
        #9#9'CASE WHEN te.Hospitality = 1 THEN '#39'Reprezentacija, '#39' ELSE '#39#39' E' +
        'ND +'
      #9#9'CASE WHEN te.Parking = 1 THEN '#39'Parking, '#39' ELSE '#39#39' END +'
      #9#9'CASE WHEN te.Accomodation = 1 THEN '#39'Smje'#353'taj '#39' ELSE '#39#39' END +'
      
        #9#9'CASE WHEN te.Other = 1 THEN '#39'Ostali tro'#353'kovi '#39' ELSE '#39#39' END AS ' +
        'expensesList'
      #9#9'FROM TravelExpenses AS te '
      
        '    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.Attach' +
        'mentID'
      ')'
      'select'#9'tw.*, '
      
        #9#9'RTRIM(emp.FirstName) + '#39' '#39' + RTRIM(emp.LastName) as imePrezime' +
        ', '
      #9#9'DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration, '
      
        #9#9'CASE WHEN tw.IsInternational = 1 THEN '#39'Da'#39' ELSE '#39'Ne'#39' END as "I' +
        'nozemno?",'
      
        #9#9'RTRIM(auth.FirstName) + '#39' '#39' + RTRIM(auth.LastName) as Authoriz' +
        'edByName,'
      #9#9'ae.AttachmentID, ae.expensesList'
      'from TravelWarrants as tw'
      'INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID'
      
        'INNER JOIN Departments as dep on emp.DepartmentCode = dep.Depart' +
        'mentCode'
      'LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID'
      
        'LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID' +
        ' -- Joining Employees table for AuthorizedBy name'
      'ORDER BY tw.Departure DESC;')
    Left = 256
    Top = 344
    object WarrantsQueryAuth: TStringField
      FieldKind = fkLookup
      FieldName = 'Auth'
      LookupDataSet = EmployeeTable
      LookupKeyFields = 'EmployeeID'
      LookupResultField = 'Username'
      KeyFields = 'AuthorizedBy'
      Lookup = True
    end
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
    object WarrantsQueryimePrezime: TWideStringField
      FieldName = 'imePrezime'
      ReadOnly = True
      Size = 41
    end
    object WarrantsQueryDuration: TIntegerField
      FieldName = 'Duration'
      ReadOnly = True
    end
    object WarrantsQueryInozemno: TStringField
      FieldName = 'Inozemno?'
      ReadOnly = True
      Size = 2
    end
    object WarrantsQueryexpensesList: TStringField
      FieldName = 'expensesList'
      ReadOnly = True
      Size = 61
    end
    object WarrantsQueryAuthorizedByName: TWideStringField
      FieldName = 'AuthorizedByName'
      ReadOnly = True
      Size = 41
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
    ReportOptions.LastChange = 45111.711624074100000000
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
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Segoe UI Semibold'
          Font.Style = [fsBold, fsItalic]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'IZVJE'#352#262'E O PUTNIM NALOZIMA ZA ZAPOSLENIKA')
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
          Font.Charset = DEFAULT_CHARSET
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
          Font.Charset = DEFAULT_CHARSET
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
          Width = 79.370130000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            #353'ifra naloga')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 94.488250000000000000
          Top = 102.047310000000000000
          Width = 166.299320000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Datum')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 272.126160000000000000
          Top = 102.047310000000000000
          Width = 170.078850000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Partneri')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 457.323130000000000000
          Top = 102.047310000000000000
          Width = 170.078850000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold]
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
        Height = 124.724490000000000000
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
          Width = 79.370130000000000000
          Height = 71.811070000000000000
          DataField = 'WarrantID'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = DEFAULT_CHARSET
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
          Left = 102.047310000000000000
          Top = 15.118120000000000000
          Width = 158.740260000000000000
          Height = 71.811070000000000000
          DataField = 'CreatedAt'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = DEFAULT_CHARSET
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
          Left = 272.126160000000000000
          Top = 15.118120000000000000
          Width = 170.078850000000000000
          Height = 71.811070000000000000
          DataField = 'Partners'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = DEFAULT_CHARSET
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
          Left = 457.323130000000000000
          Top = 15.118120000000000000
          Width = 166.299320000000000000
          Height = 71.811070000000000000
          DataField = 'Purposes'
          DataSet = WarrantDetail
          DataSetName = 'Warrants'
          Font.Charset = DEFAULT_CHARSET
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
    DataSource = EmployeeDataSource
    BCDToCurrency = False
    DataSetOptions = []
    Left = 776
    Top = 144
  end
  object JoinedReport: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'WITH AllExpenses AS ('
      '    SELECT tw.AttachmentID, tw.WarrantID,'
      
        '        CASE WHEN te.TransportationToll = 1 THEN '#39'Cestarina, '#39' E' +
        'LSE '#39#39' END +'
      
        #9#9'CASE WHEN te.Hospitality = 1 THEN '#39'Reprezentacija, '#39' ELSE '#39#39' E' +
        'ND +'
      #9#9'CASE WHEN te.Parking = 1 THEN '#39'Parking, '#39' ELSE '#39#39' END +'
      #9#9'CASE WHEN te.Accomodation = 1 THEN '#39'Smje'#353'taj '#39' ELSE '#39#39' END +'
      
        #9#9'CASE WHEN te.Other = 1 THEN '#39'Ostali tro'#353'kovi '#39' ELSE '#39#39' END AS ' +
        'expensesList'
      #9#9'FROM TravelExpenses AS te '
      
        '    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.Attach' +
        'mentID'
      ')'
      'select'#9'tw.*, '
      
        #9#9'RTRIM(emp.FirstName) + '#39' '#39' + RTRIM(emp.LastName) as imePrezime' +
        ','
      
        '                                RTRIM( dep.DepartmentName) AS De' +
        'partment,'
      #9#9'DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration, '
      
        #9#9'CASE WHEN tw.IsInternational = 1 THEN '#39'Da'#39' ELSE '#39'Ne'#39' END as "I' +
        'nozemno?",'
      
        #9#9'RTRIM(auth.FirstName) + '#39' '#39' + RTRIM(auth.LastName) as Authoriz' +
        'edByName,'
      #9#9'ae.AttachmentID, ae.expensesList'
      'from TravelWarrants as tw'
      'INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID'
      
        'INNER JOIN Departments as dep on emp.DepartmentCode = dep.Depart' +
        'mentCode'
      'LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID'
      'LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID'
      'WHERE tw.WarrantID = 700;')
    Left = 880
    Top = 80
    object JoinedReportWarrantID: TAutoIncField
      FieldName = 'WarrantID'
      ReadOnly = True
    end
    object JoinedReportEmployeeID: TIntegerField
      FieldName = 'EmployeeID'
    end
    object JoinedReportCreatedAt: TDateTimeField
      FieldName = 'CreatedAt'
    end
    object JoinedReportDeparture: TDateTimeField
      FieldName = 'Departure'
    end
    object JoinedReportArrival: TDateTimeField
      FieldName = 'Arrival'
    end
    object JoinedReportIsInternational: TBooleanField
      FieldName = 'IsInternational'
    end
    object JoinedReportPartners: TWideStringField
      FieldName = 'Partners'
      FixedChar = True
      Size = 100
    end
    object JoinedReportPurposes: TWideStringField
      FieldName = 'Purposes'
      FixedChar = True
      Size = 100
    end
    object JoinedReportAttachmentID: TIntegerField
      FieldName = 'AttachmentID'
    end
    object JoinedReportStartingOdometer: TIntegerField
      FieldName = 'StartingOdometer'
    end
    object JoinedReportEndingOdometer: TIntegerField
      FieldName = 'EndingOdometer'
    end
    object JoinedReportToll: TWideStringField
      FieldName = 'Toll'
      FixedChar = True
      Size = 50
    end
    object JoinedReportLicensePlate: TWideStringField
      FieldName = 'LicensePlate'
      FixedChar = True
    end
    object JoinedReportOtherVehicles: TWideStringField
      FieldName = 'OtherVehicles'
      FixedChar = True
      Size = 10
    end
    object JoinedReportAuthorizedBy: TIntegerField
      FieldName = 'AuthorizedBy'
    end
    object JoinedReportimePrezime: TWideStringField
      FieldName = 'imePrezime'
      ReadOnly = True
      Size = 41
    end
    object JoinedReportDuration: TIntegerField
      FieldName = 'Duration'
      ReadOnly = True
    end
    object JoinedReportInozemno: TStringField
      FieldName = 'Inozemno?'
      ReadOnly = True
      Size = 2
    end
    object JoinedReportAuthorizedByName: TWideStringField
      FieldName = 'AuthorizedByName'
      ReadOnly = True
      Size = 41
    end
    object JoinedReportexpensesList: TStringField
      FieldName = 'expensesList'
      ReadOnly = True
      Size = 61
    end
    object JoinedReportDepartment: TWideStringField
      FieldName = 'Department'
      ReadOnly = True
      Size = 50
    end
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
    ReportOptions.LastChange = 45149.423439340280000000
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
        Height = 128.504020000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Top = 30.236240000000000000
          Width = 718.110700000000000000
          Height = 30.236240000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Verdana'
          Font.Style = [fsBold, fsItalic, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'IZVJE'#352#262'E O SLU'#381'BENOM PUTOVANJU')
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          AllowVectorExport = True
          Top = 75.590600000000000000
          Width = 721.890230000000000000
          Height = 34.015770000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            #352'IFRA NALOGA:  [frxDBDataset1."WarrantID"]')
          ParentFont = False
        end
      end
      object AllInfo: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 869.291900000000000000
        Top = 207.874150000000000000
        Width = 718.110700000000000000
        DataSet = WarrantReport
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 517.795610000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'REGISTRACIJA VOZILA')
          ParentFont = False
        end
        object frxDBDataset1LicensePlate: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 449.764070000000000000
          Top = 517.795610000000000000
          Width = 113.385900000000000000
          Height = 22.677180000000000000
          DataField = 'LicensePlate'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."LicensePlate"]')
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 559.370440000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'STANJE BROJILA NA PO'#268'ETKU')
          ParentFont = False
        end
        object frxDBDataset1StartingOdometer: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 559.370440000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'StartingOdometer'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Verdana'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."StartingOdometer"]')
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 600.945270000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'STANJE BROJILA NA KRAJU')
          ParentFont = False
        end
        object frxDBDataset1EndingOdometer: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 600.945270000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'EndingOdometer'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Verdana'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."EndingOdometer"]')
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 642.520100000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'NA'#268'IN PLA'#262'ANJA CESTARINE')
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 389.291590000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'NAZIVI PARTNERA')
          ParentFont = False
        end
        object frxDBDataset1Partners: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 385.512060000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'Partners'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."Partners"]')
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 427.086890000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'RAZLOZI PUTOVANJA')
          ParentFont = False
        end
        object frxDBDataset1Purposes: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 427.086890000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'Purposes'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."Purposes"]')
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 56.692950000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'IME I PREZIME')
          ParentFont = False
        end
        object frxDBDataset1FullName: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 56.692950000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."imePrezime"]')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 94.488250000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'ODJEL')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 132.283550000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'DATUM PISANJA')
          ParentFont = False
        end
        object frxDBDataset1CreatedAt: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 132.283550000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'CreatedAt'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Verdana'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."CreatedAt"]')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 222.992270000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'DATUM I VRIJEME POLASKA')
          ParentFont = False
        end
        object frxDBDataset1Departure: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 222.992270000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'Departure'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Verdana'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."Departure"]')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 260.787570000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'DATUM I VRIJEME POVRATKA')
          ParentFont = False
        end
        object frxDBDataset1Arrival: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 260.787570000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataField = 'Arrival'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Verdana'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."Arrival"]')
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 298.582870000000000000
          Width = 238.110390000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          Memo.UTF8W = (
            'INOZEMNO PUTOVANJE')
          ParentFont = False
        end
        object frxDBDataset1IsInternational: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 404.409710000000000000
          Top = 298.582870000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."Inozemno?"]')
          ParentFont = False
        end
        object frxDBDataset1Toll: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 457.323130000000000000
          Top = 642.520100000000000000
          Width = 94.488250000000000000
          Height = 22.677180000000000000
          DataField = 'Toll'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset1."Toll"]')
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Left = 79.370130000000000000
          Top = 789.921770000000000000
          Width = 211.653680000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'ime i prezime podnositelja')
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          AllowVectorExport = True
          Left = 419.527830000000000000
          Top = 789.921770000000000000
          Width = 226.771800000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'ime i prezime odobravatelja')
          ParentFont = False
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Left = 71.811070000000000000
          Top = 782.362710000000000000
          Width = 226.771800000000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line2: TfrxLineView
          AllowVectorExport = True
          Left = 419.527830000000000000
          Top = 782.362710000000000000
          Width = 226.771800000000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object frxDBDataset1AuthorizedByName: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 359.055350000000000000
          Top = 748.346940000000000000
          Width = 351.496290000000000000
          Height = 30.236240000000000000
          DataField = 'AuthorizedByName'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Verdana'
          Font.Style = [fsBold, fsItalic]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."AuthorizedByName"]')
          ParentFont = False
        end
        object frxDBDataset1imePrezime: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 26.456710000000000000
          Top = 748.346940000000000000
          Width = 321.260050000000000000
          Height = 30.236240000000000000
          DataField = 'imePrezime'
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Verdana'
          Font.Style = [fsBold, fsItalic]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."imePrezime"]')
          ParentFont = False
        end
        object Line3: TfrxLineView
          AllowVectorExport = True
          Left = 151.181200000000000000
          Top = 162.519790000000000000
          Width = 438.425199290000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line4: TfrxLineView
          AllowVectorExport = True
          Left = 151.181200000000000000
          Top = 355.275820000000000000
          Width = 438.425199290000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line5: TfrxLineView
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 487.559370000000000000
          Width = 434.645669290000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo16: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 406.299475000000000000
          Top = 94.488250000000000000
          Width = 185.196970000000000000
          Height = 22.677180000000000000
          DataSet = WarrantReport
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."Department"]')
          ParentFont = False
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
    IndexFieldNames = 'EmployeeID'
    MasterFields = 'EmployeeID'
    MasterSource = EmployeeDataSource
    TableName = 'TravelWarrants'
    Left = 128
    Top = 272
  end
  object TCPClient: TIdTCPClient
    ConnectTimeout = 0
    Host = '127.0.0.1'
    Port = 26138
    ReadTimeout = -1
    Left = 776
    Top = 560
  end
  object UDPClient: TIdUDPClient
    Active = True
    Host = '127.0.0.1'
    Port = 16138
    Left = 856
    Top = 560
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
    Left = 704
    Top = 560
  end
  object SSLHandler: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 616
    Top = 560
  end
  object AsymCryptLib: TCryptographicLibrary
    Left = 1016
    Top = 560
  end
  object MultiQuery: TADOQuery
    Connection = Connection
    Parameters = <>
    Left = 256
    Top = 416
  end
  object AsymSign: TSignatory
    Codec = AsymCodec
    Left = 1016
    Top = 504
  end
  object AsymCodec: TCodec
    AsymetricKeySizeInBits = 512
    AdvancedOptions2 = []
    CryptoLibrary = AsymCryptLib
    Left = 1016
    Top = 448
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = 'native.CBC'
  end
  object SymCodec: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = AsymCryptLib
    Left = 1016
    Top = 616
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.CBC'
  end
  object HTTPBaseAuth: THTTPBasicAuthenticator
    Left = 616
    Top = 616
  end
  object RClient: TRESTClient
    Authenticator = HTTPBaseAuth
    BaseURL = 'http://localhost/RESTISAPI.dll/employees'
    Params = <>
    SynchronizedEvents = False
    Left = 704
    Top = 616
  end
  object RRequest: TRESTRequest
    Client = RClient
    Params = <>
    Response = RResponse
    SynchronizedEvents = False
    Left = 776
    Top = 616
  end
  object RResponse: TRESTResponse
    Left = 856
    Top = 616
  end
  object EmployeeTableDS: TDataSource
    DataSet = EmployeeTable
    Left = 520
    Top = 120
  end
  object ChartingQuery: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT YEAR(Departure) AS Year, '
      
        'COUNT(*) AS TotalWarrants, SUM(CASE WHEN IsInternational = 1 THE' +
        'N 1 ELSE 0 END) AS InternationalTravels,'
      
        'CAST(SUM(DATEDIFF(DAY, Departure, Arrival)) AS INT) / COUNT(*) A' +
        'S AvgDaysPerJourney,'
      
        'SUM(EndingOdometer - StartingOdometer) / COUNT(*) AS AvgMileageP' +
        'erWarrant'
      'FROM TravelWarrants'
      'WHERE EmployeeID = 55'
      'GROUP BY YEAR(Departure)')
    Left = 256
    Top = 488
    object ChartingQueryTotalWarrants: TIntegerField
      FieldName = 'TotalWarrants'
      ReadOnly = True
    end
    object ChartingQueryYear: TIntegerField
      FieldName = 'Year'
      ReadOnly = True
    end
    object ChartingQueryInternationalTravels: TIntegerField
      FieldName = 'InternationalTravels'
      ReadOnly = True
    end
    object ChartingQueryAvgDaysPerJourney: TIntegerField
      FieldName = 'AvgDaysPerJourney'
      ReadOnly = True
    end
    object ChartingQueryAvgMileagePerWarrant: TIntegerField
      FieldName = 'AvgMileagePerWarrant'
      ReadOnly = True
    end
  end
  object ChartingDataSource: TDataSource
    DataSet = ChartingQuery
    Left = 384
    Top = 488
  end
  object ChartingYearly: TADOQuery
    Active = True
    Connection = Connection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      ''
      '    SELECT '
      '    MONTH(Departure) AS Monthly, '
      '    COUNT(*) AS TotalWarrants, '
      
        '    SUM(CASE WHEN IsInternational = 1 THEN 1 ELSE 0 END) AS Inte' +
        'rnationalTravels, '
      '    SUM(DATEDIFF(DAY, Departure,Arrival)) AS TotalDaysSpent, '
      
        '    SUM(EndingOdometer - StartingOdometer) / COUNT(*) AS AvgMile' +
        'age '
      '    FROM TravelWarrants '
      '    WHERE EmployeeID = 55 '
      '    AND YEAR(Departure) = 2022'
      '    GROUP BY MONTH(Departure);')
    Left = 256
    Top = 560
  end
  object YearlyDataSource: TDataSource
    DataSet = ChartingYearly
    Left = 384
    Top = 560
  end
end
