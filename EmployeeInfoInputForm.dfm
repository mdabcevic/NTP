object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Employee Information'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 176
    Top = 32
    Width = 295
    Height = 15
    Alignment = taCenter
    Caption = 'Please enter employee information'
  end
  object FirstNameLabel: TLabel
    Left = 176
    Top = 75
    Width = 63
    Height = 15
    Caption = 'First Name: '
  end
  object LastNameLabel: TLabel
    Left = 176
    Top = 104
    Width = 62
    Height = 15
    Caption = 'Last Name: '
  end
  object IDNumberLabel: TLabel
    Left = 176
    Top = 133
    Width = 120
    Height = 15
    Caption = 'Identification Number:'
  end
  object EducationLabel: TLabel
    Left = 176
    Top = 162
    Width = 79
    Height = 15
    Caption = 'Qualifications: '
  end
  object AddressLabel: TLabel
    Left = 176
    Top = 191
    Width = 45
    Height = 15
    Caption = 'Address:'
  end
  object DepositAccountLabel: TLabel
    Left = 176
    Top = 220
    Width = 138
    Height = 15
    Caption = 'Deposit Account Number:'
  end
  object DepartmentCodeLabel: TLabel
    Left = 175
    Top = 249
    Width = 66
    Height = 15
    Caption = 'Department:'
  end
  object TenureLabel: TLabel
    Left = 175
    Top = 278
    Width = 38
    Height = 15
    Caption = 'Tenure:'
  end
  object DriverLicenseLabel: TLabel
    Left = 175
    Top = 310
    Width = 76
    Height = 15
    Caption = 'Driver License:'
  end
  object EmployeeActionButton: TButton
    Left = 175
    Top = 344
    Width = 297
    Height = 25
    Caption = 'Add or edit employee'
    TabOrder = 0
    OnClick = EmployeeActionButtonClick
  end
  object FirstNameBox: TEdit
    Left = 328
    Top = 72
    Width = 145
    Height = 23
    TabOrder = 1
  end
  object LastNameBox: TEdit
    Left = 328
    Top = 101
    Width = 145
    Height = 23
    TabOrder = 2
  end
  object IDNumberBox: TEdit
    Left = 328
    Top = 130
    Width = 145
    Height = 23
    TabOrder = 3
  end
  object EducationBox: TEdit
    Left = 328
    Top = 159
    Width = 145
    Height = 23
    TabOrder = 4
  end
  object AddressBox: TEdit
    Left = 328
    Top = 188
    Width = 145
    Height = 23
    TabOrder = 5
  end
  object DepositAccBox: TEdit
    Left = 328
    Top = 217
    Width = 145
    Height = 23
    TabOrder = 6
  end
  object DepartmentLookup: TDBLookupComboBox
    Left = 328
    Top = 246
    Width = 145
    Height = 23
    KeyField = 'DepartmentCode'
    ListField = 'DepartmentName'
    ListSource = DataModule1.DepartmentsDataSource
    TabOrder = 7
  end
  object TenureBox: TNumberBox
    Left = 328
    Top = 275
    Width = 129
    Height = 23
    TabOrder = 8
  end
  object UpDown1: TUpDown
    Left = 455
    Top = 275
    Width = 16
    Height = 23
    Associate = TenureBox
    TabOrder = 9
  end
  object isDriver: TCheckBox
    Left = 384
    Top = 304
    Width = 17
    Height = 21
    TabOrder = 10
  end
end
