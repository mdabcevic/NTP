object WebModule1: TWebModule1
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end
    item
      Name = 'ActEmployees'
      PathInfo = '/employees'
      OnAction = WebModule1ActEmployeesAction
    end
    item
      Name = 'ExpEmployee'
      PathInfo = '/export/employee'
      OnAction = WebModule1ExpEmployeeAction
    end
    item
      Name = 'ExpWarrant'
      PathInfo = '/export/warrant'
      OnAction = WebModule1ExpWarrantAction
    end>
  Height = 340
  Width = 527
  object Connection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLNCLI11.1;Persist Security Info=False;User ID=restapi' +
      ';Password=apiaccess;Initial Catalog=PutniNaloziDB;Data Source=lo' +
      'calhost\SQLEXPRESS;Initial File Name="";Server SPN="";'
    LoginPrompt = False
    Provider = 'SQLNCLI11.1'
    Left = 56
    Top = 24
  end
  object Query: TADOQuery
    Connection = Connection
    Parameters = <>
    Left = 144
    Top = 24
  end
end
