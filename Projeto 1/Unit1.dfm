﻿object rgReta: TrgReta
  Left = 0
  Top = -62
  Caption = 'rgReta'
  ClientHeight = 761
  ClientWidth = 1286
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 17
    Top = 20
    Width = 45
    Height = 13
    Caption = 'Poligonos'
  end
  object Label2: TLabel
    Left = 160
    Top = 20
    Width = 33
    Height = 13
    Caption = 'Pontos'
  end
  object lbVp: TLabel
    Left = 990
    Top = 536
    Width = 12
    Height = 13
    Caption = 'Vp'
  end
  object lbMundo: TLabel
    Left = 504
    Top = 536
    Width = 32
    Height = 13
    Caption = 'Mundo'
  end
  object Label28: TLabel
    Left = 200
    Top = 86
    Width = 29
    Height = 13
    Caption = 'Eixo Z'
  end
  object Panel1: TPanel
    Left = 503
    Top = 20
    Width = 502
    Height = 502
    Caption = 'Panel1'
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitTop = 10
    end
    object Button12: TButton
      Left = -144
      Top = 288
      Width = 75
      Height = 25
      Caption = 'Button12'
      TabOrder = 0
    end
    object Button13: TButton
      Left = -88
      Top = 256
      Width = 75
      Height = 25
      Caption = 'Button13'
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 72
    Top = 170
    Width = 137
    Height = 40
    Caption = 'Incluir Poligono'
    TabOrder = 1
    OnClick = Button1Click
  end
  object lbPoligonos: TListBox
    Left = 8
    Top = 39
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 2
    OnClick = lbPoligonosClick
  end
  object lbPontos: TListBox
    Left = 160
    Top = 39
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 3
  end
  object GroupBox1: TGroupBox
    Left = 653
    Top = 555
    Width = 352
    Height = 190
    Caption = 'Zoons e deslocamentos'
    TabOrder = 4
    object Label7: TLabel
      Left = 18
      Top = 32
      Width = 38
      Height = 16
      Caption = 'Passo:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 20
      Top = 119
      Width = 104
      Height = 16
      Caption = 'Zoom automatico:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 179
      Top = 120
      Width = 113
      Height = 16
      Caption = 'Zoom com o passo:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object lbValor: TEdit
      Left = 78
      Top = 32
      Width = 43
      Height = 21
      TabOrder = 0
    end
    object btnLeft: TButton
      Left = 176
      Top = 48
      Width = 53
      Height = 25
      Caption = 'Left'
      TabOrder = 1
      OnClick = btnLeftClick
    end
    object btnRight: TButton
      Left = 243
      Top = 48
      Width = 54
      Height = 25
      Caption = 'Right'
      TabOrder = 2
      OnClick = btnRightClick
    end
    object btnUp: TButton
      Left = 213
      Top = 17
      Width = 45
      Height = 25
      Caption = 'Up'
      TabOrder = 3
      OnClick = btnUpClick
    end
    object btnDown: TButton
      Left = 216
      Top = 79
      Width = 49
      Height = 25
      Caption = 'Down'
      TabOrder = 4
      OnClick = btnDownClick
    end
    object btnIn: TButton
      Left = 80
      Top = 148
      Width = 33
      Height = 25
      Caption = '+'
      TabOrder = 5
      OnClick = btnInClick
    end
    object Button3: TButton
      Left = 23
      Top = 149
      Width = 36
      Height = 25
      Caption = '-'
      TabOrder = 6
      OnClick = Button3Click
    end
    object Button2: TButton
      Left = 264
      Top = 150
      Width = 33
      Height = 25
      Caption = '+'
      TabOrder = 7
      OnClick = Button2Click
    end
  end
  object Button4: TButton
    Left = 829
    Top = 705
    Width = 36
    Height = 25
    Caption = '-'
    TabOrder = 5
    OnClick = Button4Click
  end
  object rgRetas: TRadioGroup
    Left = 8
    Top = 240
    Width = 264
    Height = 105
    Caption = 'Tipos de retas:'
    ItemIndex = 0
    Items.Strings = (
      'Line To'
      'DDA'
      'Bresenham')
    TabOrder = 6
  end
  object gpTransformações: TGroupBox
    Left = 8
    Top = 375
    Width = 264
    Height = 362
    Caption = 'Transforma'#231#245'es'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    object Label5: TLabel
      Left = 14
      Top = 34
      Width = 57
      Height = 14
      Caption = 'Transla'#231#227'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 14
      Top = 54
      Width = 29
      Height = 13
      Caption = 'Eixo X'
    end
    object Label8: TLabel
      Left = 96
      Top = 54
      Width = 29
      Height = 13
      Caption = 'Eixo Y'
    end
    object Label9: TLabel
      Left = 14
      Top = 202
      Width = 44
      Height = 14
      Caption = 'Rota'#231#227'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 64
      Top = 222
      Width = 5
      Height = 13
      Caption = #186
    end
    object Label11: TLabel
      Left = 14
      Top = 112
      Width = 82
      Height = 14
      Caption = 'Escalonamento'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 16
      Top = 141
      Width = 29
      Height = 13
      Caption = 'Eixo X'
    end
    object Label13: TLabel
      Left = 96
      Top = 140
      Width = 29
      Height = 13
      Caption = 'Eixo Y'
    end
    object Label14: TLabel
      Left = 14
      Top = 272
      Width = 46
      Height = 14
      Caption = 'Reflex'#227'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 14
      Top = 292
      Width = 29
      Height = 13
      Caption = 'Eixo X'
    end
    object Label16: TLabel
      Left = 92
      Top = 292
      Width = 29
      Height = 13
      Caption = 'Eixo Y'
    end
    object Edit1: TEdit
      Left = 14
      Top = 73
      Width = 56
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 96
      Top = 73
      Width = 56
      Height = 21
      TabOrder = 1
    end
    object edit10: TEdit
      Left = 14
      Top = 222
      Width = 46
      Height = 21
      TabOrder = 2
    end
    object Button5: TButton
      Left = 96
      Top = 216
      Width = 75
      Height = 25
      Caption = 'Rotacionar'
      TabOrder = 3
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 166
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Transladar'
      TabOrder = 4
      OnClick = Button6Click
    end
    object Edit4: TEdit
      Left = 14
      Top = 160
      Width = 56
      Height = 21
      TabOrder = 5
    end
    object Edit5: TEdit
      Left = 96
      Top = 159
      Width = 56
      Height = 21
      TabOrder = 6
    end
    object Button7: TButton
      Left = 158
      Top = 160
      Width = 75
      Height = 25
      Caption = 'Escalonar'
      TabOrder = 7
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 158
      Top = 296
      Width = 75
      Height = 25
      Caption = 'Espelhar X'
      TabOrder = 8
      OnClick = Button8Click
    end
    object Edit6: TEdit
      Left = 14
      Top = 311
      Width = 46
      Height = 21
      TabOrder = 9
      Text = 'Edit6'
    end
    object Edit7: TEdit
      Left = 92
      Top = 311
      Width = 46
      Height = 21
      TabOrder = 10
    end
    object Button10: TButton
      Left = 177
      Top = 216
      Width = 75
      Height = 25
      Caption = 'Homogenea'
      TabOrder = 11
      OnClick = Button10Click
    end
    object Button26: TButton
      Left = 158
      Top = 327
      Width = 75
      Height = 25
      Caption = 'Espelhar Y'
      TabOrder = 12
      OnClick = Button26Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 304
    Top = 555
    Width = 153
    Height = 190
    Caption = 'Circunferencia'
    TabOrder = 8
    object Label17: TLabel
      Left = 16
      Top = 42
      Width = 29
      Height = 13
      Caption = 'Eixo X'
    end
    object Label18: TLabel
      Left = 83
      Top = 42
      Width = 29
      Height = 13
      Caption = 'Eixo Y'
    end
    object Label19: TLabel
      Left = 16
      Top = 101
      Width = 21
      Height = 13
      Caption = 'Raio'
    end
    object lbxc: TEdit
      Left = 16
      Top = 61
      Width = 49
      Height = 21
      TabOrder = 0
    end
    object lbyc: TEdit
      Left = 87
      Top = 61
      Width = 49
      Height = 21
      TabOrder = 1
    end
    object Button9: TButton
      Left = 32
      Top = 155
      Width = 75
      Height = 25
      Caption = 'Gerar'
      TabOrder = 2
      OnClick = Button9Click
    end
    object raio: TEdit
      Left = 16
      Top = 120
      Width = 49
      Height = 21
      TabOrder = 3
    end
  end
  object GroupBox3: TGroupBox
    Left = 478
    Top = 675
    Width = 153
    Height = 70
    Caption = 'Ponto central'
    TabOrder = 9
    object Button11: TButton
      Left = 35
      Top = 32
      Width = 81
      Height = 29
      Caption = 'Gerar '
      TabOrder = 0
      OnClick = Button11Click
    end
  end
  object GroupBox4: TGroupBox
    Left = 478
    Top = 555
    Width = 153
    Height = 76
    Caption = 'Clipping'
    TabOrder = 10
    object Button14: TButton
      Left = 32
      Top = 32
      Width = 75
      Height = 25
      Caption = 'Clippar'
      TabOrder = 0
      OnClick = Button14Click
    end
  end
  object GroupBox5: TGroupBox
    Left = 304
    Top = 239
    Width = 152
    Height = 282
    Caption = 'Atualiza mundo'
    TabOrder = 11
    object Label20: TLabel
      Left = 16
      Top = 24
      Width = 26
      Height = 13
      Caption = 'Xmax'
    end
    object Label21: TLabel
      Left = 16
      Top = 80
      Width = 22
      Height = 13
      Caption = 'Xmin'
    end
    object Label22: TLabel
      Left = 16
      Top = 192
      Width = 22
      Height = 13
      Caption = 'Ymin'
    end
    object Label23: TLabel
      Left = 16
      Top = 136
      Width = 26
      Height = 13
      Caption = 'Ymax'
    end
    object edxmax: TEdit
      Left = 16
      Top = 43
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object edxmin: TEdit
      Left = 16
      Top = 99
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object edymax: TEdit
      Left = 16
      Top = 155
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object edymin: TEdit
      Left = 16
      Top = 211
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Button15: TButton
      Left = 32
      Top = 254
      Width = 75
      Height = 25
      Caption = 'Atualizar'
      TabOrder = 4
      OnClick = Button15Click
    end
  end
  object GroupBox6: TGroupBox
    Left = 304
    Top = 21
    Width = 153
    Height = 198
    Caption = 'Curvas Param'#233'tricas '
    TabOrder = 12
    object Button16: TButton
      Left = 32
      Top = 18
      Width = 75
      Height = 25
      Caption = 'Casteljau'
      TabOrder = 0
      OnClick = Button16Click
    end
    object Button17: TButton
      Left = 32
      Top = 49
      Width = 75
      Height = 25
      Caption = 'Hermite'
      TabOrder = 1
      OnClick = Button17Click
    end
    object Button18: TButton
      Left = 32
      Top = 80
      Width = 75
      Height = 25
      Caption = 'Bezier'
      TabOrder = 2
      OnClick = Button18Click
    end
    object Button19: TButton
      Left = 32
      Top = 111
      Width = 75
      Height = 25
      Caption = ' B-spline'
      TabOrder = 3
      OnClick = Button19Click
    end
    object Button20: TButton
      Left = 32
      Top = 142
      Width = 75
      Height = 25
      Caption = 'Foward'
      TabOrder = 4
      OnClick = Button20Click
    end
  end
  object GroupBox7: TGroupBox
    Left = 1030
    Top = 416
    Width = 248
    Height = 337
    Caption = 'Representa'#231#245'es 3D'
    TabOrder = 13
    object Label24: TLabel
      Left = 27
      Top = 78
      Width = 29
      Height = 13
      Caption = 'Eixo X'
    end
    object Label25: TLabel
      Left = 104
      Top = 78
      Width = 29
      Height = 13
      Caption = 'Eixo Y'
    end
    object Label26: TLabel
      Left = 192
      Top = 78
      Width = 29
      Height = 13
      Caption = 'Eixo Z'
    end
    object Label27: TLabel
      Left = 90
      Top = 198
      Width = 5
      Height = 13
      Caption = #186
    end
    object Label29: TLabel
      Left = 32
      Top = 179
      Width = 33
      Height = 13
      Caption = 'Angulo'
    end
    object Label30: TLabel
      Left = 32
      Top = 245
      Width = 29
      Height = 13
      Caption = 'Eixo Z'
    end
    object Label31: TLabel
      Left = 112
      Top = 181
      Width = 23
      Height = 13
      Caption = 'Eixo '
    end
    object Button21: TButton
      Left = 47
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Piramide'
      TabOrder = 0
      OnClick = Button21Click
    end
    object Button22: TButton
      Left = 128
      Top = 23
      Width = 97
      Height = 25
      Caption = 'Paralelepipedo'
      TabOrder = 1
      OnClick = Button22Click
    end
    object Button23: TButton
      Left = 99
      Top = 142
      Width = 75
      Height = 25
      Caption = 'Transladar'
      TabOrder = 2
      OnClick = Button23Click
    end
    object Edit3: TEdit
      Left = 27
      Top = 97
      Width = 56
      Height = 21
      TabOrder = 3
    end
    object Edit8: TEdit
      Left = 107
      Top = 97
      Width = 56
      Height = 21
      TabOrder = 4
    end
    object Edit9: TEdit
      Left = 181
      Top = 97
      Width = 56
      Height = 21
      TabOrder = 5
    end
    object Edit11: TEdit
      Left = 38
      Top = 198
      Width = 46
      Height = 21
      TabOrder = 6
    end
    object Edit17: TEdit
      Left = 32
      Top = 264
      Width = 57
      Height = 21
      TabOrder = 7
    end
    object Button24: TButton
      Left = 182
      Top = 200
      Width = 63
      Height = 25
      Caption = 'Rotacionar'
      TabOrder = 8
      OnClick = Button24Click
    end
    object Edit13: TEdit
      Left = 112
      Top = 200
      Width = 49
      Height = 21
      TabOrder = 9
    end
    object Button25: TButton
      Left = 120
      Top = 264
      Width = 75
      Height = 25
      Caption = 'Escalonar'
      TabOrder = 10
      OnClick = Button25Click
    end
  end
end
