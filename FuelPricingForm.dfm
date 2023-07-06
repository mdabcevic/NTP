object Form14: TForm14
  Left = 0
  Top = 0
  Caption = 'Form14'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Memo1: TMemo
    Left = 0
    Top = 8
    Width = 353
    Height = 426
    TabOrder = 0
  end
  object RESTClient1: TRESTClient
    Params = <>
    SynchronizedEvents = False
    Left = 544
    Top = 72
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 552
    Top = 160
  end
  object RESTResponse1: TRESTResponse
    Left = 544
    Top = 232
  end
end
