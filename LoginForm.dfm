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
    Top = 232
    Width = 122
    Height = 15
    Caption = 'password confirmation'
  end
  object emailLabel: TLabel
    Left = 208
    Top = 288
    Width = 34
    Height = 15
    Caption = 'e-mail'
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
    TabOrder = 1
  end
  object isRegister: TCheckBox
    Left = 208
    Top = 152
    Width = 185
    Height = 17
    Caption = 'I'#39'd like to register'
    TabOrder = 2
  end
  object isAdmin: TCheckBox
    Left = 208
    Top = 192
    Width = 185
    Height = 17
    Caption = 'I'#39'm an administrator'
    TabOrder = 3
  end
  object pwConfirmBox: TEdit
    Left = 208
    Top = 253
    Width = 185
    Height = 23
    TabOrder = 4
  end
  object emailBox: TEdit
    Left = 208
    Top = 309
    Width = 185
    Height = 23
    TabOrder = 5
  end
  object loginButton: TButton
    Left = 208
    Top = 352
    Width = 185
    Height = 25
    Caption = 'Login'
    TabOrder = 6
  end
end
