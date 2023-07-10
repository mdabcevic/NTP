object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Travel Warrants'
  ClientHeight = 440
  ClientWidth = 1115
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
    Left = 8
    Top = 60
    Width = 1103
    Height = 120
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
        FieldName = 'EmployeeID'
        Width = 88
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Departure'
        Width = 126
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Arrival'
        Width = 129
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Partners'
        Width = 178
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Purposes'
        Width = 145
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LicensePlate'
        Width = 133
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Mileage'
        Width = 149
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Toll'
        Width = 120
        Visible = True
      end>
  end
  object DeleteButton: TButton
    Left = 295
    Top = 186
    Width = 282
    Height = 25
    Caption = 'Delete selected warrant'
    TabOrder = 1
    OnClick = DeleteButtonClick
  end
  object EditButton: TButton
    Left = 8
    Top = 186
    Width = 281
    Height = 25
    Caption = 'Edit selected warrant'
    TabOrder = 2
    OnClick = EditButtonClick
  end
  object ReportWarrant: TButton
    Left = 583
    Top = 186
    Width = 296
    Height = 25
    Caption = 'Generate report for selected warrant'
    TabOrder = 3
    OnClick = ReportWarrantClick
  end
  object GroupBox1: TGroupBox
    Left = 885
    Top = 186
    Width = 222
    Height = 25
    TabOrder = 4
    object PDFOption: TRadioButton
      Left = 51
      Top = 5
      Width = 46
      Height = 17
      Caption = 'PDF'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RTFOption: TRadioButton
      Left = 123
      Top = 5
      Width = 46
      Height = 17
      Caption = 'RTF'
      TabOrder = 1
    end
  end
end
