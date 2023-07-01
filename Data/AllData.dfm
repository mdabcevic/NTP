object DataModule1: TDataModule1
  Height = 480
  Width = 640
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
      'SELECT e.FirstName, e.LastName, e.Email, d.DepartmentName'
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
end
