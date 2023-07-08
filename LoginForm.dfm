object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Login'
  ClientHeight = 542
  ClientWidth = 608
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
    Top = 256
    Width = 122
    Height = 15
    Caption = 'password confirmation'
    Visible = False
  end
  object emailLabel: TLabel
    Left = 208
    Top = 312
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
  object isAdmin: TCheckBox
    Left = 208
    Top = 184
    Width = 185
    Height = 17
    Caption = 'I'#39'm an administrator'
    TabOrder = 3
  end
  object pwConfirmBox: TEdit
    Left = 208
    Top = 277
    Width = 185
    Height = 23
    PasswordChar = '*'
    TabOrder = 4
    Visible = False
  end
  object emailBox: TEdit
    Left = 208
    Top = 333
    Width = 185
    Height = 23
    TabOrder = 5
    Visible = False
  end
  object loginButton: TButton
    Left = 208
    Top = 376
    Width = 185
    Height = 25
    Caption = 'Login'
    TabOrder = 6
    OnClick = loginButtonClick
  end
  object isRememberMe: TCheckBox
    Left = 208
    Top = 216
    Width = 185
    Height = 18
    Caption = 'Remember me'
    TabOrder = 7
    OnClick = isRememberMeClick
  end
  object Button1: TButton
    Left = 432
    Top = 251
    Width = 132
    Height = 25
    Caption = 'Employees'
    TabOrder = 8
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 432
    Top = 283
    Width = 132
    Height = 25
    Caption = 'Departments'
    TabOrder = 9
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 432
    Top = 314
    Width = 132
    Height = 25
    Caption = 'Add expenses'
    TabOrder = 10
    OnClick = Button3Click
  end
  object B: TButton
    Left = 432
    Top = 345
    Width = 132
    Height = 25
    Caption = 'Add warrant'
    TabOrder = 11
    OnClick = BClick
  end
  object Button4: TButton
    Left = 432
    Top = 220
    Width = 132
    Height = 25
    Caption = 'Travel Warrants'
    TabOrder = 12
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 432
    Top = 376
    Width = 132
    Height = 25
    Caption = 'Clients'
    TabOrder = 13
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 24
    Top = 148
    Width = 137
    Height = 25
    Caption = 'Button6'
    TabOrder = 14
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 24
    Top = 180
    Width = 137
    Height = 25
    Caption = 'Button7'
    TabOrder = 15
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 24
    Top = 211
    Width = 137
    Height = 25
    Caption = 'Button8'
    TabOrder = 16
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 24
    Top = 242
    Width = 137
    Height = 25
    Caption = 'Button9'
    TabOrder = 17
    OnClick = Button9Click
  end
  object MainMenu1: TMainMenu
    Left = 96
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
