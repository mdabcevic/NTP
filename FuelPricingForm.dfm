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
    Width = 193
    Height = 426
    Lines.Strings = (
      '{"ok":true,"url":"https://f.mirror-'
      'ai.net/x/qSHYP2yuGHGNPOO0wD_'
      '_32mEn057amSJ7j7nnyVH71NrunR'
      'YHQwfRTrHPDr0y6a-'
      'gO75Xsnaqh6cLNhehkw-'
      '9Cjk48Ax70uOkU5Pbfq6NP39DSriPl'
      'uYTf_gJ5iatVpk"}')
    TabOrder = 0
  end
  object RESTClient1: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 'https://public-api.mirror-ai.net/v2'
    Params = <>
    SynchronizedEvents = False
    Left = 544
    Top = 72
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <
      item
        Name = 'face_id'
        Value = 'enNn3xpnTW2n5dVNy_gLZA'
      end
      item
        Name = 'sticker'
        Value = 'selfie_in_the_elevator'
      end
      item
        Name = 'loc'
        Value = 'en'
      end
      item
        Kind = pkHTTPHEADER
        Name = 'X-Token'
        Value = '306f8bab7c75449ea6750e67c4e187dd'
      end
      item
        Name = 'accept'
        Value = 'application/json'
      end>
    Resource = 'sticker'
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 544
    Top = 136
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 544
    Top = 200
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 540
    Top = 285
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTResponse1
      FieldName = 'Content'
      Control = Memo1
      Track = False
    end
  end
end
