# Vibration Calculator

[🇯🇵 日本語](README.md) | [🇺🇸 English](README.en.md)

A single-degree-of-freedom (SDOF) mass–spring–damper vibration calculator,
implemented twice with the **same physics and the same formulas**:

1. **`MFC_CppApp/`** — a Windows desktop application built with
   **Microsoft Visual C++ (MFC)**.
2. **`VBA_ExcelApp/`** — an **Excel VBA UserForm** application with
   identical calculation logic.

## Why this project

This repo is a small portfolio piece built to demonstrate the exact skill
combination often requested for vibration/acoustics engineering software
roles (e.g. SEA — Statistical Energy Analysis — tooling for the automotive
industry):

- Visual C++ development experience
- Building Windows desktop applications with Microsoft Visual C++ (MFC)
- Building form-based applications with Excel VBA
- Numerical/engineering computation (the kind of math that underlies
  vibration & acoustics analysis tools)

## The physics

For a single-degree-of-freedom system with mass `m`, stiffness `k`, and
viscous damping coefficient `c`:

```
Natural frequency (Hz):     f_n   = (1 / 2π) * sqrt(k / m)
Damping ratio:               ζ     = c / (2 * sqrt(k * m))
Damped natural frequency:    f_d   = f_n * sqrt(1 - ζ²)   (only if ζ < 1)
```

Both the C++ and VBA versions take `m`, `k`, `c` as user input and report
`f_n`, `ζ`, and `f_d` — so the same engineering result can be reproduced
and cross-checked in either tool. This is a common pattern in real
engineering software teams: prototype/validate in Excel VBA, then
implement the production version in C++.

## Folder structure

```
VibrationCalculatorProject/
├── README.md
├── MFC_CppApp/
│   ├── README.md               <- setup instructions for Visual Studio
│   ├── framework.h
│   ├── pch.h / pch.cpp
│   ├── resource.h
│   ├── VibrationCalculator.rc
│   ├── VibrationCalculator.h / .cpp     <- CWinApp
│   ├── VibrationCalculatorDlg.h / .cpp  <- CDialogEx (main logic + UI)
│   └── VibrationCalculator.vcxproj
└── VBA_ExcelApp/
    ├── README.md               <- import instructions for the VBA editor
    ├── modVibrationMath.bas    <- shared calculation functions
    └── frmVibrationCalculator.txt  <- UserForm code-behind + control layout
```
