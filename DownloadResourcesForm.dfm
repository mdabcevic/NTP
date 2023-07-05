object Form13: TForm13
  Left = 0
  Top = 0
  Caption = 'Downloader'
  ClientHeight = 488
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClick = RadioButton1Click
  TextHeight = 15
  object Label1: TLabel
    Left = 40
    Top = 104
    Width = 562
    Height = 30
    Alignment = taCenter
    Caption = 'USE ONLY TO DOWNLOAD RELEVANT CAR INFORMATION'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 40
    Top = 248
    Width = 117
    Height = 15
    Caption = 'Select download limit:'
  end
  object Download: TButton
    Left = 473
    Top = 168
    Width = 129
    Height = 25
    Caption = 'Download'
    TabOrder = 0
    OnClick = DownloadClick
  end
  object Link: TEdit
    Left = 40
    Top = 169
    Width = 427
    Height = 23
    TabOrder = 1
    Text = 'https://www.high-d.com/dataset/Cars.json'
  end
  object ProgressBar1: TProgressBar
    Left = 40
    Top = 216
    Width = 562
    Height = 17
    TabOrder = 2
  end
  object RadioButton1: TRadioButton
    Left = 176
    Top = 248
    Width = 89
    Height = 17
    Caption = 'Max (default)'
    TabOrder = 3
    OnClick = RadioButton1Click
  end
  object speed10: TRadioButton
    Left = 376
    Top = 248
    Width = 65
    Height = 17
    Caption = '10 kb/s'
    TabOrder = 4
    OnClick = RadioButton1Click
  end
  object speed20: TRadioButton
    Left = 462
    Top = 248
    Width = 63
    Height = 17
    Caption = '20 kb/s'
    TabOrder = 5
    OnClick = RadioButton1Click
  end
  object speed30: TRadioButton
    Left = 539
    Top = 248
    Width = 63
    Height = 17
    Caption = '30 kb/s'
    TabOrder = 6
    OnClick = RadioButton1Click
  end
  object speed5: TRadioButton
    Left = 295
    Top = 248
    Width = 65
    Height = 17
    Caption = '5 kb/s'
    TabOrder = 7
    OnClick = RadioButton1Click
  end
  object HTTP: TIdHTTP
    Intercept = Throttler
    IOHandler = IdSSLIOHandlerSocketOpenSSL1
    OnWork = HTTPWork
    OnWorkBegin = HTTPWorkBegin
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 512
    Top = 368
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    Intercept = Throttler
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 512
    Top = 424
  end
  object Throttler: TIdInterceptThrottler
    BitsPerSec = 0
    RecvBitsPerSec = 0
    SendBitsPerSec = 0
    Left = 512
    Top = 312
  end
end
