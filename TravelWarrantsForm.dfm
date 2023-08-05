object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Travel Warrants'
  ClientHeight = 439
  ClientWidth = 1928
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Title: TLabel
    Left = 520
    Top = 24
    Width = 154
    Height = 30
    Caption = 'Travel Warrants'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 168
    Top = 60
    Width = 1761
    Height = 318
    DataSource = DataModule1.WarrantsDataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'WarrantID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'imePrezime'
        Title.Caption = 'Zaposlenik'
        Width = 134
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Departure'
        Title.Caption = 'Odlazak'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Arrival'
        Title.Caption = 'Povratak'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Duration'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Inozemo?'
        Title.Caption = 'Inozemno?'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Partners'
        Width = 141
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Purposes'
        Width = 188
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'StartingOdometer'
        Title.Caption = 'Po'#269'etno stanje brojila'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'EndingOdometer'
        Title.Caption = 'Krajnje stanje brojila'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Toll'
        Title.Caption = 'Cestarina'
        Width = 97
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LicensePlate'
        Title.Caption = 'Registarska oznaka'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'expensesList'
        Title.Caption = 'Tro'#353'kovi'
        Width = 205
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'AuthorizedBy'
        Title.Caption = 'Odobreno?'
        Width = 140
        Visible = True
      end>
  end
  object DeleteButton: TButton
    Left = 8
    Top = 353
    Width = 154
    Height = 25
    Caption = 'Delete selected warrant'
    TabOrder = 1
    OnClick = DeleteButtonClick
  end
  object EditButton: TButton
    Left = 8
    Top = 290
    Width = 154
    Height = 25
    Caption = 'Edit selected warrant'
    TabOrder = 2
    OnClick = EditButtonClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 173
    Width = 154
    Height = 111
    Caption = 'Ispis ozna'#269'enog naloga'
    TabOrder = 3
    object PDFOption: TRadioButton
      Left = 19
      Top = 52
      Width = 46
      Height = 17
      Caption = 'PDF'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RTFOption: TRadioButton
      Left = 19
      Top = 29
      Width = 46
      Height = 17
      Caption = 'RTF'
      TabOrder = 1
    end
    object ReportWarrant: TButton
      Left = 19
      Top = 75
      Width = 110
      Height = 25
      Caption = 'Generate'
      TabOrder = 2
      OnClick = ReportWarrantClick
    end
  end
  object Button1: TButton
    Left = 8
    Top = 142
    Width = 154
    Height = 25
    Caption = 'Potpi'#353'i ozna'#269'eni nalog'
    TabOrder = 4
  end
  object Button2: TButton
    Left = 8
    Top = 322
    Width = 154
    Height = 25
    Caption = 'A'#382'uriraj tro'#353'kove'
    TabOrder = 5
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 52
    Width = 154
    Height = 84
    Caption = 'Prikaz'
    TabOrder = 6
    object CheckBox1: TCheckBox
      Left = 17
      Top = 47
      Width = 97
      Height = 17
      Caption = 'Potpisani'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 17
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Nepotpisani'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
  end
end
