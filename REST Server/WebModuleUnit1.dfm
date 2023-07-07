object WebModule1: TWebModule1
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end
    item
      Name = 'AuthAct'
      PathInfo = '/auth'
      OnAction = WebModule1AuthActAction
    end
    item
      Name = 'ReportAct'
      PathInfo = '/reports'
    end>
  Height = 230
  Width = 415
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 320
    Top = 48
  end
  object AsymSign: TSignatory
    Codec = AsymCodec
    Left = 320
    Top = 152
  end
  object AsymCodec: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 240
    Top = 152
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = ''
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=SQLNCLI11.1;Integrated Security=SSPI;Persist Security I' +
      'nfo=False;User ID="";Initial Catalog=PutniNaloziDB;Data Source=l' +
      'ocalhost\SQLExpress;Initial File Name="";Server SPN=""'
    Provider = 'SQLNCLI11.1'
    Left = 40
    Top = 32
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 40
    Top = 96
  end
end
