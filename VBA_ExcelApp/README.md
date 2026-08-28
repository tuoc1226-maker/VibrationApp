# VibrationCalculator (Excel VBA UserForm)

The same SDOF mass–spring–damper calculation as the MFC app, implemented
as an Excel VBA UserForm application.

## Files

- **`modVibrationMath.bas`** — a standard module with the three pure
  calculation functions (importable as-is via the VBA editor).
- **`frmVibrationCalculator.txt`** — the UserForm's code-behind, plus a
  description of exactly which controls to draw on the form. (A UserForm's
  visual layout lives in a binary `.frx` file that isn't practical to
  hand-write outside the VBA IDE, so the form itself is described here and
  the code is provided separately — this is the standard way VBA UserForm
  source is shared/reviewed without opening Excel.)

## How to set this up in Excel

1. Open Excel → **Developer tab → Visual Basic** (or `Alt+F11`).
2. **File → Import File…** and import `modVibrationMath.bas`. This adds a
   standard module with the shared math functions.
3. **Insert → UserForm**. Rename it `frmVibrationCalculator` (Properties
   window → `(Name)`).
4. Add the following controls to the form (drag from the Toolbox), and set
   their `(Name)` property exactly as listed:

   | Control      | Type          | Name              |
   |--------------|---------------|-------------------|
   | Label        | Label         | `lblMass`         |
   | Text box     | TextBox       | `txtMass`         |
   | Label        | Label         | `lblStiffness`    |
   | Text box     | TextBox       | `txtStiffness`    |
   | Label        | Label         | `lblDamping`      |
   | Text box     | TextBox       | `txtDamping`      |
   | Button       | CommandButton | `cmdCalculate`    |
   | Button       | CommandButton | `cmdClose`        |
   | Label        | Label         | `lblResultFn`     |
   | Label        | Label         | `lblResultZeta`   |
   | Label        | Label         | `lblResultFd`     |

5. Double-click the form (or right-click → **View Code**) and paste in the
   code from `frmVibrationCalculator.txt`.
6. Add a normal module (or reuse `modVibrationMath.bas`) with:

   ```vba
   Sub ShowVibrationCalculator()
       frmVibrationCalculator.Show
   End Sub
   ```

   Run `ShowVibrationCalculator` (F5, with the cursor inside it) to launch
   the form.

## Where the logic lives

`modVibrationMath.bas` contains the three functions
(`CalcNaturalFrequency`, `CalcDampingRatio`, `CalcDampedFrequency`) that
are numerically identical to the C++ versions in
`MFC_CppApp/VibrationCalculatorDlg.cpp`.
