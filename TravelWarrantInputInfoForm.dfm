object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Travel Warrant Information'
  ClientHeight = 439
  ClientWidth = 616
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object TitleGeneral: TLabel
    Left = 16
    Top = 16
    Width = 194
    Height = 30
    Alignment = taCenter
    Caption = 'General information'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object DepartureLabel: TLabel
    Left = 16
    Top = 72
    Width = 55
    Height = 15
    Caption = 'Departure:'
  end
  object ArrivalLabel: TLabel
    Left = 320
    Top = 74
    Width = 37
    Height = 15
    Caption = 'Arrival:'
  end
  object isInternationalLabel: TLabel
    Left = 16
    Top = 218
    Width = 104
    Height = 15
    Caption = 'International travel?'
  end
  object PurposeLabel: TLabel
    Left = 320
    Top = 104
    Width = 51
    Height = 15
    Caption = 'Purposes:'
  end
  object OdometerStartLabel: TLabel
    Left = 337
    Top = 324
    Width = 130
    Height = 15
    Caption = 'Starting odometer value:'
  end
  object OdometerEndLabel: TLabel
    Left = 337
    Top = 355
    Width = 126
    Height = 15
    Caption = 'Ending odometer value:'
  end
  object CarTitle: TLabel
    Left = 337
    Top = 240
    Width = 245
    Height = 30
    Alignment = taCenter
    Caption = 'Company car information'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object TollInfoLabel: TLabel
    Left = 16
    Top = 264
    Width = 73
    Height = 15
    Caption = 'Toll paid with:'
  end
  object AttachmentTitle: TLabel
    Left = 16
    Top = 296
    Width = 229
    Height = 30
    Alignment = taCenter
    Caption = 'Attachment information'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object DepartureDateTime: TDateTimePicker
    Left = 104
    Top = 64
    Width = 186
    Height = 23
    Date = 45109.000000000000000000
    Time = 0.544409791669750100
    TabOrder = 0
  end
  object ArrivalDateTime: TDateTimePicker
    Left = 408
    Top = 64
    Width = 186
    Height = 25
    Date = 45109.000000000000000000
    Time = 0.544543865740706700
    TabOrder = 1
  end
  object isInternational: TCheckBox
    Left = 193
    Top = 211
    Width = 16
    Height = 31
    TabOrder = 2
  end
  object PartnersList: TCheckListBox
    Left = 104
    Top = 104
    Width = 186
    Height = 97
    ItemHeight = 17
    TabOrder = 3
  end
  object PurposesList: TCheckListBox
    Left = 408
    Top = 104
    Width = 186
    Height = 97
    ItemHeight = 17
    TabOrder = 4
  end
  object CarSelection: TButtonedEdit
    Left = 490
    Top = 290
    Width = 104
    Height = 23
    ReadOnly = True
    TabOrder = 5
  end
  object OdometerStart: TNumberBox
    Left = 490
    Top = 321
    Width = 87
    Height = 23
    TabOrder = 6
  end
  object OdometerEnd: TNumberBox
    Left = 490
    Top = 352
    Width = 87
    Height = 23
    TabOrder = 7
  end
  object UpDownStart: TUpDown
    Left = 577
    Top = 321
    Width = 16
    Height = 23
    Associate = OdometerStart
    TabOrder = 8
  end
  object UpDownEnd: TUpDown
    Left = 577
    Top = 352
    Width = 16
    Height = 23
    Associate = OdometerEnd
    TabOrder = 9
  end
  object AddAttachments: TButton
    Left = 16
    Top = 339
    Width = 274
    Height = 25
    Caption = 'Provide attachments'
    TabOrder = 10
    OnClick = AddAttachmentsClick
  end
  object WarrantAction: TButton
    Left = 16
    Top = 392
    Width = 595
    Height = 33
    Caption = 'Add / Edit Travel Warrant'
    TabOrder = 11
    OnClick = NewWarrant
  end
  object TollInfo: TComboBox
    Left = 104
    Top = 261
    Width = 186
    Height = 23
    Style = csDropDownList
    TabOrder = 12
  end
  object CarSelect: TButton
    Left = 337
    Top = 290
    Width = 130
    Height = 25
    Caption = 'Select Car'
    TabOrder = 13
    OnClick = CarSelectClick
  end
  object PartnersButton: TButton
    Left = 8
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Partners'
    TabOrder = 14
    OnClick = PartnersListClick
  end
end
