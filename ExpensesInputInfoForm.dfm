object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 298
  ClientWidth = 572
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object Title: TLabel
    Left = 24
    Top = 16
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
  object ExpenseID: TLabel
    Left = 312
    Top = 62
    Width = 97
    Height = 15
    Caption = 'Identification: '
  end
  object isToll: TCheckBox
    Left = 24
    Top = 73
    Width = 249
    Height = 17
    Caption = 'Toll (Road, Tunnel, Ferry, Vignette)'
    TabOrder = 0
  end
  object isHospitality: TCheckBox
    Left = 24
    Top = 111
    Width = 249
    Height = 17
    Caption = 'Entertainment (Hospitality) Expenses'
    TabOrder = 1
  end
  object isParking: TCheckBox
    Left = 24
    Top = 142
    Width = 249
    Height = 17
    Caption = 'Parking'
    TabOrder = 2
  end
  object isAccomodation: TCheckBox
    Left = 24
    Top = 173
    Width = 249
    Height = 17
    Caption = 'Accomodation'
    TabOrder = 3
  end
  object isOther: TCheckBox
    Left = 24
    Top = 204
    Width = 249
    Height = 17
    Caption = 'Other expenses'
    TabOrder = 4
  end
  object AttachmentPreview: TDBImage
    Left = 312
    Top = 88
    Width = 224
    Height = 177
    DataField = 'Attachments'
    DataSource = DataModule1.ExpensesDataSource
    Stretch = True
    TabOrder = 5
  end
  object Upload: TButton
    Left = 24
    Top = 240
    Width = 249
    Height = 25
    Caption = 'Save receipt'
    TabOrder = 6
    OnClick = UploadClick
  end
  object ExpenseIDVal: TDBEdit
    Left = 415
    Top = 59
    Width = 121
    Height = 23
    DataField = 'ExpensesID'
    DataSource = DataModule1.ExpensesDataSource
    ReadOnly = True
    TabOrder = 7
  end
end
