Attribute VB_Name = "modVibrationMath"
Option Explicit

'==============================================================================
' modVibrationMath
'
' Pure calculation functions for a single-degree-of-freedom (SDOF)
' mass-spring-damper system. These mirror, formula-for-formula, the C++
' implementation in MFC_CppApp/VibrationCalculatorDlg.cpp, so the two
' applications (this VBA app and the MFC desktop app) always agree.
'==============================================================================

Private Const PI As Double = 3.14159265358979

' Natural frequency f_n (Hz) = (1 / 2*pi) * sqrt(k / m)
Public Function CalcNaturalFrequency(ByVal massKg As Double, ByVal stiffnessNPerM As Double) As Double
    CalcNaturalFrequency = (1# / (2# * PI)) * Sqr(stiffnessNPerM / massKg)
End Function

' Damping ratio zeta = c / (2 * sqrt(k * m))
Public Function CalcDampingRatio(ByVal massKg As Double, ByVal stiffnessNPerM As Double, ByVal dampingNsPerM As Double) As Double
    CalcDampingRatio = dampingNsPerM / (2# * Sqr(stiffnessNPerM * massKg))
End Function

' Damped natural frequency f_d = f_n * sqrt(1 - zeta^2), valid only for zeta < 1 (underdamped).
' Returns 0 for critically damped / overdamped systems (no oscillation).
Public Function CalcDampedFrequency(ByVal naturalFrequencyHz As Double, ByVal dampingRatio As Double) As Double
    If dampingRatio < 1# Then
        CalcDampedFrequency = naturalFrequencyHz * Sqr(1# - dampingRatio ^ 2)
    Else
        CalcDampedFrequency = 0#
    End If
End Function

' Entry point to launch the form.
Public Sub ShowVibrationCalculator()
    frmVibrationCalculator.Show
End Sub
