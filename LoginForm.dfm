object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Login'
  ClientHeight = 633
  ClientWidth = 1070
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnShow = FormShow
  TextHeight = 15
  object usernameLabel: TLabel
    Left = 208
    Top = 32
    Width = 52
    Height = 15
    Caption = 'username'
  end
  object pwLabel: TLabel
    Left = 208
    Top = 88
    Width = 50
    Height = 15
    Caption = 'password'
  end
  object pwConfirmLabel: TLabel
    Left = 208
    Top = 224
    Width = 122
    Height = 15
    Caption = 'password confirmation'
    Visible = False
  end
  object emailLabel: TLabel
    Left = 208
    Top = 280
    Width = 34
    Height = 15
    Caption = 'e-mail'
    Visible = False
  end
  object ImgHr: TImage
    Left = 524
    Top = 22
    Width = 31
    Height = 25
    Center = True
    Stretch = True
  end
  object ImgEn: TImage
    Left = 561
    Top = 22
    Width = 31
    Height = 25
    Stretch = True
  end
  object ActionLabel: TLabel
    Left = 16
    Top = 382
    Width = 314
    Height = 30
    Alignment = taCenter
    Caption = 'What would you like to do?'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object WarrantsBox: TGroupBox
    Left = 24
    Top = 418
    Width = 314
    Height = 69
    Caption = 'Warrants...'
    TabOrder = 8
    object AuthorizeButton: TButton
      Left = 207
      Top = 25
      Width = 90
      Height = 25
      Caption = 'Authorize'
      Enabled = False
      TabOrder = 0
    end
    object AllWarrants: TButton
      Left = 16
      Top = 24
      Width = 91
      Height = 25
      Caption = 'See all'
      TabOrder = 1
      OnClick = AllWarrantsClick
    end
    object NewWarrant: TButton
      Left = 113
      Top = 24
      Width = 88
      Height = 25
      Caption = 'Add new'
      TabOrder = 2
      OnClick = NewWarrantClick
    end
  end
  object usernameBox: TEdit
    Left = 208
    Top = 53
    Width = 185
    Height = 23
    TabOrder = 0
  end
  object pwBox: TEdit
    Left = 208
    Top = 109
    Width = 185
    Height = 23
    PasswordChar = '*'
    TabOrder = 1
  end
  object isRegister: TCheckBox
    Left = 208
    Top = 152
    Width = 185
    Height = 17
    Caption = 'I'#39'd like to register'
    TabOrder = 2
    OnClick = isRegisterClick
  end
  object pwConfirmBox: TEdit
    Left = 208
    Top = 245
    Width = 185
    Height = 23
    PasswordChar = '*'
    TabOrder = 3
    Visible = False
  end
  object emailBox: TEdit
    Left = 208
    Top = 301
    Width = 185
    Height = 23
    TabOrder = 4
    Visible = False
  end
  object loginButton: TButton
    Left = 208
    Top = 344
    Width = 185
    Height = 25
    Caption = 'Login'
    TabOrder = 5
    OnClick = loginButtonClick
  end
  object isRememberMe: TCheckBox
    Left = 208
    Top = 185
    Width = 185
    Height = 18
    Caption = 'Remember me'
    TabOrder = 6
    OnClick = isRememberMeClick
  end
  object UserInfoRibbon: TGroupBox
    Left = 608
    Top = 72
    Width = 193
    Height = 526
    TabOrder = 7
    Visible = False
    object Image1: TImage
      Left = 16
      Top = 66
      Width = 145
      Height = 135
    end
    object Label1: TLabel
      Left = 16
      Top = 20
      Width = 145
      Height = 30
      Alignment = taCenter
      Caption = 'Welcome!'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 216
      Width = 145
      Height = 15
      Caption = 'Username: '
    end
    object Label3: TLabel
      Left = 16
      Top = 253
      Width = 145
      Height = 15
      Caption = 'First Name: '
    end
    object Label4: TLabel
      Left = 16
      Top = 290
      Width = 145
      Height = 15
      Caption = 'Last Name: '
    end
    object Label5: TLabel
      Left = 16
      Top = 333
      Width = 145
      Height = 15
      Caption = 'Email:'
    end
    object Label6: TLabel
      Left = 16
      Top = 374
      Width = 145
      Height = 15
      Caption = 'Phone:'
    end
    object Label7: TLabel
      Left = 16
      Top = 411
      Width = 145
      Height = 15
      Caption = 'Department:'
    end
    object Label8: TLabel
      Left = 16
      Top = 448
      Width = 145
      Height = 15
      Caption = 'PID:'
    end
    object Label9: TLabel
      Left = 16
      Top = 479
      Width = 145
      Height = 15
      Caption = 'Code:'
    end
  end
  object EmployeesBox: TGroupBox
    Left = 24
    Top = 493
    Width = 314
    Height = 132
    Caption = 'Employees, clients and cars'
    TabOrder = 9
    object AllEmployees: TButton
      Left = 16
      Top = 30
      Width = 138
      Height = 25
      Caption = 'See all employees'
      TabOrder = 0
      OnClick = AllEmployeesClick
    end
    object Button1: TButton
      Left = 160
      Top = 30
      Width = 143
      Height = 25
      Caption = 'Add new employee'
      TabOrder = 1
    end
    object SeeClients: TButton
      Left = 16
      Top = 64
      Width = 138
      Height = 25
      Caption = 'See all clients'
      TabOrder = 2
      OnClick = SeeClientsClick
    end
    object AddClient: TButton
      Left = 160
      Top = 64
      Width = 143
      Height = 25
      Caption = 'Add new client'
      TabOrder = 3
    end
    object AllCars: TButton
      Left = 16
      Top = 95
      Width = 138
      Height = 25
      Caption = 'See all company cars'
      TabOrder = 4
      OnClick = AllCarsClick
    end
    object Button6: TButton
      Left = 160
      Top = 95
      Width = 143
      Height = 25
      Caption = 'Add new company car'
      TabOrder = 5
    end
  end
  object GroupBox1: TGroupBox
    Left = 344
    Top = 418
    Width = 258
    Height = 207
    Caption = 'Something else...'
    TabOrder = 10
    object AddPurposeButton: TButton
      Left = 11
      Top = 32
      Width = 238
      Height = 25
      Caption = 'Add a purpose'
      TabOrder = 0
      OnClick = AddPurposeButtonClick
    end
    object DownloadButton: TButton
      Left = 11
      Top = 63
      Width = 238
      Height = 25
      Caption = 'Download company resources'
      TabOrder = 1
      OnClick = DownloadButtonClick
    end
    object CreateAvatarButton: TButton
      Left = 11
      Top = 94
      Width = 238
      Height = 25
      Caption = 'Create new profile picture'
      TabOrder = 2
      OnClick = CreateAvatarButtonClick
    end
    object AddExpensesButton: TButton
      Left = 11
      Top = 125
      Width = 238
      Height = 25
      Caption = 'Upload travel expenses'
      Enabled = False
      TabOrder = 3
      OnClick = CreateAvatarButtonClick
    end
    object SeeDepartments: TButton
      Left = 11
      Top = 156
      Width = 238
      Height = 25
      Caption = 'See all departments'
      TabOrder = 4
      OnClick = SeeDepartmentsClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 544
    Top = 56
    object Settings1: TMenuItem
      Caption = 'Settings...'
      object hemeSettings1: TMenuItem
        Caption = 'Theme Settings'
        object Dark1: TMenuItem
          Caption = 'Dark'
          OnClick = Dark1Click
        end
        object Light1: TMenuItem
          Caption = 'Light'
          OnClick = Light1Click
        end
        object Default1: TMenuItem
          Caption = 'Default'
          OnClick = Default1Click
        end
      end
      object FontSettings1: TMenuItem
        Caption = 'Font Settings'
        object Small1: TMenuItem
          Caption = 'Small'
          OnClick = Small1Click
        end
        object Medium1: TMenuItem
          Caption = 'Medium'
          OnClick = Medium1Click
        end
        object Medium2: TMenuItem
          Caption = 'Large'
          OnClick = Medium2Click
        end
      end
    end
    object ResetOptions1: TMenuItem
      Caption = 'Reset Options'
      object ResetTheme1: TMenuItem
        Caption = 'Reset Theme'
        OnClick = ResetTheme1Click
      end
      object ResetFont1: TMenuItem
        Caption = 'Reset Font'
        OnClick = ResetFont1Click
      end
      object ResetFont2: TMenuItem
        Caption = 'Reset Everything'
        OnClick = ResetFont2Click
      end
    end
    object Announcements1: TMenuItem
      Caption = 'Announcements'
      object Checkforannouncements1: TMenuItem
        Caption = 'Check for announcements'
      end
      object Makeanannouncement1: TMenuItem
        Caption = 'Make an announcement'
      end
    end
    object Reset: TMenuItem
      Caption = 'Other'
      object Help1: TMenuItem
        Caption = 'Help'
      end
      object About1: TMenuItem
        Caption = 'About'
      end
    end
  end
end
