object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 439
  ClientWidth = 616
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object TCPServer: TIdTCPServer
    Active = True
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 26138
      end>
    DefaultPort = 0
    OnExecute = TCPServerExecute
    Left = 40
    Top = 32
  end
  object XmlDoc: TXMLDocument
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 40
    Top = 96
    DOMVendorDesc = 'ADOM XML v4'
  end
  object UDPServer: TIdUDPServer
    Active = True
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 16138
      end>
    DefaultPort = 0
    OnUDPRead = UDPServerUDPRead
    Left = 128
    Top = 32
  end
  object AsymCodec: TCodec
    AsymetricKeySizeInBits = 512
    AdvancedOptions2 = []
    CryptoLibrary = AsymLib
    Left = 536
    Top = 96
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = 'native.CBC'
  end
  object AsymLib: TCryptographicLibrary
    Left = 536
    Top = 32
  end
  object AsymSign: TSignatory
    Codec = AsymCodec
    Left = 536
    Top = 160
  end
  object UDPFileServer: TIdUDPServer
    Active = True
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 16686
      end>
    DefaultPort = 0
    OnUDPRead = UDPFileServerUDPRead
    Left = 128
    Top = 96
  end
  object SymCodec: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = AsymLib
    Left = 440
    Top = 96
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.CBC'
  end
end
