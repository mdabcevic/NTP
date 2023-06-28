object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Login'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
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
end
