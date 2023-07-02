object Form10: TForm10
  Left = 0
  Top = 0
  Caption = 'Clients'
  ClientHeight = 492
  ClientWidth = 620
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Title: TLabel
    Left = 192
    Top = 24
    Width = 240
    Height = 30
    Caption = 'Information about clients'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object ListView1: TListView
    Left = 8
    Top = 88
    Width = 608
    Height = 150
    Columns = <
      item
        AutoSize = True
        Caption = 'Company Name'
      end
      item
        Caption = 'Address'
        Width = 120
      end
      item
        Caption = 'ID Number'
        Width = 120
      end
      item
        Caption = 'Email'
        Width = 120
      end
      item
        Caption = 'Contact Person'
        Width = 120
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
  end
  object AddClient: TButton
    Left = 8
    Top = 244
    Width = 202
    Height = 25
    Caption = 'Add new client'
    TabOrder = 1
    OnClick = AddClientClick
  end
  object EditClient: TButton
    Left = 216
    Top = 244
    Width = 192
    Height = 25
    Caption = 'Edit selected client'
    TabOrder = 2
  end
  object DeleteClient: TButton
    Left = 414
    Top = 244
    Width = 202
    Height = 25
    Caption = 'Delete selected client'
    TabOrder = 3
    OnClick = DeleteClientClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 275
    Width = 297
    Height = 198
    Caption = 'Enter client information'
    TabOrder = 4
    object Label1: TLabel
      Left = 40
      Top = 24
      Width = 52
      Height = 15
      Caption = 'Company'
    end
    object Label2: TLabel
      Left = 40
      Top = 140
      Width = 81
      Height = 15
      Caption = 'Contact Person'
    end
    object Label3: TLabel
      Left = 40
      Top = 111
      Width = 29
      Height = 15
      Caption = 'Email'
    end
    object Label4: TLabel
      Left = 40
      Top = 82
      Width = 70
      Height = 15
      Caption = 'Identification'
    end
    object Label5: TLabel
      Left = 40
      Top = 53
      Width = 42
      Height = 15
      Caption = 'Address'
    end
    object CompanyNameBox: TEdit
      Left = 144
      Top = 24
      Width = 121
      Height = 23
      TabOrder = 0
    end
    object AddressBox: TEdit
      Left = 144
      Top = 53
      Width = 121
      Height = 23
      TabOrder = 1
    end
    object IDBox: TEdit
      Left = 144
      Top = 82
      Width = 121
      Height = 23
      TabOrder = 2
    end
    object EmailBox: TEdit
      Left = 144
      Top = 111
      Width = 121
      Height = 23
      TabOrder = 3
    end
    object ContactPersonBox: TEdit
      Left = 144
      Top = 140
      Width = 121
      Height = 23
      TabOrder = 4
    end
  end
end
