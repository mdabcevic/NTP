object Form14: TForm14
  Left = 0
  Top = 0
  Caption = 'Form14'
  ClientHeight = 441
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object Memo1: TMemo
    Left = 8
    Top = 190
    Width = 633
    Height = 244
    Lines.Strings = (
      
        '{"ok":true,"url":"https://f.mirror-ai.net/x/NW_J5FhqBVHNylW-EKNk' +
        'BqtP0rgSyOgItyDnXxyQGN-'
      
        'fJ8AtkWg66ygQACiTEfWKB5ge0kpVo_lS_n62K8UwzPh76e1mw4-XJTL0F0c4L1y' +
        '9S9cZ3Qxqu-dyxck9OSaR"}')
    TabOrder = 0
  end
  object LabeledEdit1: TLabeledEdit
    Left = 8
    Top = 159
    Width = 241
    Height = 25
    EditLabel.Width = 175
    EditLabel.Height = 15
    EditLabel.Caption = 'Enter face ID to get avatar sticker:'
    TabOrder = 1
    Text = 'enNn3xpnTW2n5dVNy_gLZA'
  end
  object Button1: TButton
    Left = 487
    Top = 159
    Width = 154
    Height = 25
    Caption = 'Go'
    TabOrder = 2
  end
  object LabeledEdit2: TLabeledEdit
    Left = 255
    Top = 159
    Width = 226
    Height = 25
    EditLabel.Width = 107
    EditLabel.Height = 15
    EditLabel.Caption = 'Enter type of sticker:'
    TabOrder = 3
    Text = 'selfie_in_the_elevator'
  end
  object RESTClient1: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 'https://public-api.mirror-ai.net/v2'
    Params = <>
    SynchronizedEvents = False
    Left = 248
    Top = 16
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
    Left = 328
    Top = 16
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 416
    Top = 16
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 28
    Top = 13
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTResponse1
      FieldName = 'Content'
      Control = Memo1
      Track = False
    end
    object LinkControlToField2: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTRequest1
      FieldName = 'Params.face_id'
      Control = LabeledEdit1
      Track = True
    end
    object LinkControlToField3: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTRequest1
      FieldName = 'Params.sticker'
      Control = LabeledEdit2
      Track = True
    end
  end
end
