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
    end>
  Height = 230
  Width = 415
end
