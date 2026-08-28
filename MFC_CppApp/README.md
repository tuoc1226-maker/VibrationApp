# VibrationCalculator (MFC / Visual C++)

A dialog-based MFC desktop application. Enter mass, stiffness, and damping;
the app computes the natural frequency, damping ratio, and damped natural
frequency of a single-degree-of-freedom vibrating system.

## How to build in Visual Studio

Because a full MFC project also needs Visual Studio–generated GUIDs and
manifest/resource plumbing that isn't practical to hand-write outside the
IDE, the cleanest way to build this is:

1. In Visual Studio: **File → New → Project → MFC App**.
   - Name the project `VibrationCalculator`.
   - In the wizard, choose **Dialog based** application, uncheck
     "Document/View architecture support", and finish.
2. Visual Studio will generate its own `VibrationCalculator.h/.cpp`,
   `VibrationCalculatorDlg.h/.cpp`, `pch.h/.cpp` (or `stdafx.h/.cpp` on
   older VS), `resource.h`, and `.rc` file.
3. Replace the contents of those generated files with the corresponding
   files in this folder (same file names). The `.vcxproj` here is provided
   for reference / diffing — it's usually simplest to keep the
   wizard-generated `.vcxproj` and just swap in the source files.
4. Open `VibrationCalculator.rc` in the resource editor and confirm the
   dialog has the following controls (the `.rc` file already defines
   these, but if you rebuild the dialog visually, match these IDs):

| Control              | Type      | Resource ID           |
|-----------------------|-----------|------------------------|
| Mass (kg)              | Edit Box  | `IDC_EDIT_MASS`        |
| Stiffness (N/m)        | Edit Box  | `IDC_EDIT_STIFFNESS`   |
| Damping (N·s/m)        | Edit Box  | `IDC_EDIT_DAMPING`     |
| Calculate              | Button    | `IDC_BUTTON_CALC`      |
| Natural Frequency result | Static  | `IDC_STATIC_FN`        |
| Damping Ratio result   | Static    | `IDC_STATIC_ZETA`      |
| Damped Frequency result| Static    | `IDC_STATIC_FD`        |

5. Build and run (x64 or Win32, Debug or Release).

## Where the logic lives

All calculation logic is in `VibrationCalculatorDlg.cpp`, inside
`OnBnClickedButtonCalc()` and the three small helper functions above it
(`CalcNaturalFrequency`, `CalcDampingRatio`, `CalcDampedFrequency`) —
these mirror the VBA functions in `VBA_ExcelApp/modVibrationMath.bas`
exactly, so the two apps are easy to compare side by side.
