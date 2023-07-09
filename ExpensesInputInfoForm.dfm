object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 604
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object Title: TLabel
    Left = 200
    Top = 32
    Width = 205
    Height = 30
    Alignment = taCenter
    Caption = 'Expenses information'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object isToll: TCheckBox
    Left = 200
    Top = 89
    Width = 249
    Height = 17
    Caption = 'Toll (Road, Tunnel, Ferry, Vignette)'
    TabOrder = 0
  end
  object isHospitality: TCheckBox
    Left = 200
    Top = 127
    Width = 249
    Height = 17
    Caption = 'Entertainment (Hospitality) Expenses'
    TabOrder = 1
  end
  object isParking: TCheckBox
    Left = 200
    Top = 158
    Width = 249
    Height = 17
    Caption = 'Parking'
    TabOrder = 2
  end
  object isAccomodation: TCheckBox
    Left = 200
    Top = 189
    Width = 249
    Height = 17
    Caption = 'Accomodation'
    TabOrder = 3
  end
  object isOther: TCheckBox
    Left = 200
    Top = 220
    Width = 249
    Height = 17
    Caption = 'Other expenses'
    TabOrder = 4
  end
  object AttachmentPreview: TDBImage
    Left = 200
    Top = 287
    Width = 256
    Height = 209
    DataField = 'Attachments'
    DataSource = DataModule1.ExpensesDataSource
    TabOrder = 5
  end
  object Upload: TButton
    Left = 200
    Top = 256
    Width = 249
    Height = 25
    Caption = 'Save receipt'
    TabOrder = 6
    OnClick = UploadClick
  end
end
