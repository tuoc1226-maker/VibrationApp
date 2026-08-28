// VibrationCalculatorDlg.h : header file
//

#pragma once


// CVibrationCalculatorDlg dialog
class CVibrationCalculatorDlg : public CDialogEx
{
// Construction
public:
	CVibrationCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIBRATIONCALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButtonCalc();
	DECLARE_MESSAGE_MAP()

private:
	// --- Vibration math helpers ---------------------------------------
	// These three functions mirror modVibrationMath.bas in the VBA app
	// (VBA_ExcelApp/modVibrationMath.bas) exactly, so both applications
	// produce identical results for the same inputs.

	// Natural frequency f_n (Hz) = (1 / 2*pi) * sqrt(k / m)
	static double CalcNaturalFrequency(double massKg, double stiffnessNPerM);

	// Damping ratio zeta = c / (2 * sqrt(k * m))
	static double CalcDampingRatio(double massKg, double stiffnessNPerM, double dampingNsPerM);

	// Damped natural frequency f_d = f_n * sqrt(1 - zeta^2), valid for zeta < 1 (underdamped)
	static double CalcDampedFrequency(double naturalFrequencyHz, double dampingRatio);
};
