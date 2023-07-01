object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Form6'
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
    Left = 216
    Top = 32
    Width = 184
    Height = 15
    Caption = 'Please enter employee information'
  end
  object Label2: TLabel
    Left = 216
    Top = 75
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 216
    Top = 104
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label4: TLabel
    Left = 216
    Top = 133
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label5: TLabel
    Left = 216
    Top = 162
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label6: TLabel
    Left = 216
    Top = 191
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label7: TLabel
    Left = 216
    Top = 220
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label8: TLabel
    Left = 216
    Top = 256
    Width = 34
    Height = 15
    Caption = 'Label8'
  end
  object Button1: TButton
    Left = 232
    Top = 328
    Width = 161
    Height = 25
    Caption = 'Add or edit employee'
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 288
    Top = 72
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 288
    Top = 101
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'Edit1'
  end
  object Edit3: TEdit
    Left = 288
    Top = 130
    Width = 121
    Height = 23
    TabOrder = 3
    Text = 'Edit1'
  end
  object Edit4: TEdit
    Left = 288
    Top = 159
    Width = 121
    Height = 23
    TabOrder = 4
    Text = 'Edit1'
  end
  object Edit5: TEdit
    Left = 288
    Top = 188
    Width = 121
    Height = 23
    TabOrder = 5
    Text = 'Edit1'
  end
  object Edit6: TEdit
    Left = 288
    Top = 217
    Width = 121
    Height = 23
    TabOrder = 6
    Text = 'Edit1'
  end
  object DepartmentLookup: TDBLookupComboBox
    Left = 288
    Top = 246
    Width = 145
    Height = 23
    KeyField = 'DepartmentCode'
    ListField = 'DepartmentName'
    ListSource = DataModule1.DepartmentsDataSource
    TabOrder = 7
  end
end
