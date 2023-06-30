object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Car information'
  ClientHeight = 433
  ClientWidth = 444
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LicensePlate_Label: TLabel
    Left = 144
    Top = 48
    Width = 169
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Caption = 'License plate'
  end
  object InternalName_Label: TLabel
    Left = 144
    Top = 104
    Width = 169
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Caption = 'Internal name'
  end
  object Assigned_Label: TLabel
    Left = 144
    Top = 158
    Width = 169
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Caption = 'Officially assigned to'
  end
  object User_Label: TLabel
    Left = 144
    Top = 216
    Width = 169
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Caption = 'Currently used by'
  end
  object Location_Label: TLabel
    Left = 144
    Top = 272
    Width = 169
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Caption = 'Location'
  end
  object LicensePlate_Box: TEdit
    Left = 144
    Top = 69
    Width = 169
    Height = 23
    TabOrder = 0
  end
  object InternalName_Box: TEdit
    Left = 144
    Top = 123
    Width = 169
    Height = 23
    TabOrder = 1
  end
  object Assigned_Box: TEdit
    Left = 144
    Top = 179
    Width = 169
    Height = 23
    TabOrder = 2
  end
  object User_Box: TEdit
    Left = 144
    Top = 237
    Width = 169
    Height = 23
    TabOrder = 3
  end
  object Location_Box: TEdit
    Left = 144
    Top = 293
    Width = 169
    Height = 23
    TabOrder = 4
  end
  object SaveCarChanges_Button: TButton
    Left = 144
    Top = 330
    Width = 169
    Height = 25
    Caption = 'Add / Edit '
    TabOrder = 5
  end
end
