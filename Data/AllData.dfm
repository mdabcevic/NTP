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
    Left = 152
    Top = 120
  end
  object EmployeeDataSource: TDataSource
    DataSet = EmployeeTable
    Left = 280
    Top = 120
  end
end
