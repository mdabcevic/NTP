object DataModule1: TDataModule1
  Height = 480
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
end
