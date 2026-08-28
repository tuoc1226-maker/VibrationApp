# 振動計算機

[🇯🇵 日本語](README.md) | [🇺🇸 英語](README.en.md)

単自由度（SDOF）質量-ばね-ダンパー系の振動計算機です。
**同じ物理法則と計算式**を用いて2つのバージョンで実装されています。

1. **`MFC_CppApp/`** — Microsoft Visual C++ (MFC)**で構築されたWindowsデスクトップアプリケーション。

2. **`VBA_ExcelApp/`** — **Excel VBAユーザーフォーム**アプリケーションで、

計算ロジックは同一です。


## このプロジェクトについて

このリポジトリは、振動・音響エンジニアリングソフトウェア関連職種（例：SEA - 統計的エネルギー解析 - 自動車業界向けツール）で求められるスキルセットを実証するための小規模なポートフォリオです。

具体的には、以下のスキルセットが含まれます。

- Visual C++ 開発経験
- Microsoft Visual C++ (MFC) を用いた Windows デスクトップアプリケーション開発経験
- Excel VBA を用いたフォームベースアプリケーション開発経験
- 数値計算／エンジニアリング計算（振動・音響解析ツールの基盤となる数学）

## 物理法則

質量 `m​​`、剛性 `k`、粘性減衰係数 `c` を持つ 1 自由度系の場合：

```
固有振動数 (Hz)：f_n = (1 / 2π) * sqrt(k / m)
減衰比：ζ = c / (2 * sqrt(k * m))
減衰固有振動数：f_d = f_n * sqrt(1 - ζ²) (ζ < 1 の場合のみ)
```
C++版とVBA版はどちらも、ユーザー入力として `m`、`k`、`c` を受け取り、
`f_n`、`ζ`、`f_d` を出力します。そのため、どちらのツールでも同じエンジニアリング結果を再現し、
相互検証できます。これは、実際のソフトウェア開発チームでよく見られるパターンです。
Excel VBAでプロトタイプを作成・検証し、
C++で本番版を実装します。

## フォルダ構造

```
VibrationCalculatorProject/
├── README.md
├── MFC_CppApp/
│ ├── README.md <- Visual Studio のセットアップ手順
│ ├── framework.h
│ ├── pch.h / pch.cpp
│ ├── resource.h
│ ├── VibrationCalculator.rc
│ ├── VibrationCalculator.h / .cpp <- CWinApp
│ ├── VibrationCalculatorDlg.h / .cpp <- CDialogEx (メインロジック + UI)
│ └── VibrationCalculator.vcxproj
└── VBA_ExcelApp/

├── README.md <- VBA エディタのインポート手順

├── modVibrationMath.bas <- 共有計算関数

└── frmVibrationCalculator.txt <- ユーザーフォームのコードビハインド + コントロールレイアウト
```