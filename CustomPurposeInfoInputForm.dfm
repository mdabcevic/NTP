object Form11: TForm11
  Left = 0
  Top = 0
  Caption = 'Purpose information'
  ClientHeight = 314
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 165
    Width = 26
    Height = 15
    Caption = 'code'
  end
  object Label2: TLabel
    Left = 24
    Top = 24
    Width = 153
    Height = 30
    Caption = 'Add a purpose...'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object purposeNameBox: TLabeledEdit
    Left = 24
    Top = 88
    Width = 241
    Height = 23
    EditLabel.Width = 30
    EditLabel.Height = 15
    EditLabel.Caption = 'name'
    MaxLength = 50
    TabOrder = 0
    Text = ''
  end
  object purposeDescBox: TLabeledEdit
    Left = 24
    Top = 136
    Width = 369
    Height = 23
    EditLabel.Width = 59
    EditLabel.Height = 15
    EditLabel.Caption = 'description'
    MaxLength = 200
    TabOrder = 1
    Text = ''
  end
  object purposeCodeBox: TNumberBox
    Left = 24
    Top = 184
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object UpDown1: TUpDown
    Left = 145
    Top = 184
    Width = 16
    Height = 23
    Associate = purposeCodeBox
    TabOrder = 3
  end
  object isClassified: TCheckBox
    Left = 24
    Top = 224
    Width = 369
    Height = 17
    Caption = 'classified'
    TabOrder = 4
  end
  object Button1: TButton
    Left = 24
    Top = 264
    Width = 369
    Height = 25
    Caption = 'Submit'
    TabOrder = 5
    OnClick = Button1Click
  end
end
