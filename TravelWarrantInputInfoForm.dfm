object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Form7'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 578
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
  object Label2: TLabel
    Left = 16
    Top = 72
    Width = 55
    Height = 15
    Caption = 'Departure:'
  end
  object Label3: TLabel
    Left = 320
    Top = 74
    Width = 37
    Height = 15
    Caption = 'Arrival:'
  end
  object Label4: TLabel
    Left = 16
    Top = 218
    Width = 104
    Height = 15
    Caption = 'International travel?'
  end
  object Label5: TLabel
    Left = 16
    Top = 104
    Width = 46
    Height = 15
    Caption = 'Partners:'
  end
  object Label6: TLabel
    Left = 320
    Top = 104
    Width = 51
    Height = 15
    Caption = 'Purposes:'
  end
  object Label7: TLabel
    Left = 337
    Top = 293
    Width = 53
    Height = 15
    Caption = 'Select car:'
  end
  object Label8: TLabel
    Left = 337
    Top = 324
    Width = 130
    Height = 15
    Caption = 'Starting odometer value:'
  end
  object Label9: TLabel
    Left = 337
    Top = 355
    Width = 126
    Height = 15
    Caption = 'Ending odometer value:'
  end
  object Label10: TLabel
    Left = 337
    Top = 240
    Width = 257
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
  object Label11: TLabel
    Left = 16
    Top = 264
    Width = 73
    Height = 15
    Caption = 'Toll paid with:'
  end
  object Label12: TLabel
    Left = 16
    Top = 296
    Width = 274
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
  object DateTimePicker1: TDateTimePicker
    Left = 104
    Top = 64
    Width = 186
    Height = 23
    Date = 45109.000000000000000000
    Time = 0.544409791669750100
    TabOrder = 0
  end
  object DateTimePicker2: TDateTimePicker
    Left = 408
    Top = 64
    Width = 186
    Height = 25
    Date = 45109.000000000000000000
    Time = 0.544543865740706700
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 193
    Top = 211
    Width = 16
    Height = 31
    TabOrder = 2
  end
  object CheckListBox1: TCheckListBox
    Left = 104
    Top = 104
    Width = 186
    Height = 97
    ItemHeight = 15
    TabOrder = 3
  end
  object CheckListBox2: TCheckListBox
    Left = 408
    Top = 104
    Width = 186
    Height = 97
    ItemHeight = 15
    TabOrder = 4
  end
  object ButtonedEdit1: TButtonedEdit
    Left = 490
    Top = 290
    Width = 104
    Height = 23
    TabOrder = 5
  end
  object NumberBox1: TNumberBox
    Left = 490
    Top = 321
    Width = 104
    Height = 23
    TabOrder = 6
  end
  object NumberBox2: TNumberBox
    Left = 490
    Top = 352
    Width = 104
    Height = 23
    TabOrder = 7
  end
  object UpDown1: TUpDown
    Left = 594
    Top = 319
    Width = 17
    Height = 25
    TabOrder = 8
  end
  object UpDown2: TUpDown
    Left = 594
    Top = 350
    Width = 17
    Height = 25
    TabOrder = 9
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 104
    Top = 256
    Width = 186
    Height = 23
    TabOrder = 10
  end
  object Button1: TButton
    Left = 16
    Top = 339
    Width = 274
    Height = 25
    Caption = 'Provide attachments'
    TabOrder = 11
  end
  object Button2: TButton
    Left = 16
    Top = 392
    Width = 595
    Height = 33
    Caption = 'Add / Edit Travel Warrant'
    TabOrder = 12
  end
end