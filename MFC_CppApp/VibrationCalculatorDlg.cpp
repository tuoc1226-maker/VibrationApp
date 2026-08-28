// VibrationCalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "VibrationCalculator.h"
#include "VibrationCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace
{
	constexpr double kPi = 3.14159265358979323846;
}

// CVibrationCalculatorDlg dialog

CVibrationCalculatorDlg::CVibrationCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIBRATIONCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVibrationCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVibrationCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALC, &CVibrationCalculatorDlg::OnBnClickedButtonCalc)
END_MESSAGE_MAP()


// CVibrationCalculatorDlg message handlers

BOOL CVibrationCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// Reasonable defaults so the app is usable immediately on launch
	SetDlgItemText(IDC_EDIT_MASS, _T("1.0"));
	SetDlgItemText(IDC_EDIT_STIFFNESS, _T("1000.0"));
	SetDlgItemText(IDC_EDIT_DAMPING, _T("5.0"));

	return TRUE;
}

void CVibrationCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CVibrationCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// --- Vibration math -----------------------------------------------------
// Mirrors VBA_ExcelApp/modVibrationMath.bas function-for-function.

double CVibrationCalculatorDlg::CalcNaturalFrequency(double massKg, double stiffnessNPerM)
{
	return (1.0 / (2.0 * kPi)) * std::sqrt(stiffnessNPerM / massKg);
}

double CVibrationCalculatorDlg::CalcDampingRatio(double massKg, double stiffnessNPerM, double dampingNsPerM)
{
	return dampingNsPerM / (2.0 * std::sqrt(stiffnessNPerM * massKg));
}

double CVibrationCalculatorDlg::CalcDampedFrequency(double naturalFrequencyHz, double dampingRatio)
{
	if (dampingRatio < 1.0)
	{
		return naturalFrequencyHz * std::sqrt(1.0 - dampingRatio * dampingRatio);
	}
	// Critically damped or overdamped: no oscillation, so no damped frequency.
	return 0.0;
}

// --- UI event handler -----------------------------------------------------

void CVibrationCalculatorDlg::OnBnClickedButtonCalc()
{
	CString strMass, strStiffness, strDamping;
	GetDlgItemText(IDC_EDIT_MASS, strMass);
	GetDlgItemText(IDC_EDIT_STIFFNESS, strStiffness);
	GetDlgItemText(IDC_EDIT_DAMPING, strDamping);

	// Basic input validation, mirroring the checks in the VBA UserForm
	wchar_t* endPtr = nullptr;
	double mass = wcstod(strMass, &endPtr);
	bool massValid = (endPtr != strMass.GetString() && mass > 0.0);

	double stiffness = wcstod(strStiffness, &endPtr);
	bool stiffnessValid = (endPtr != strStiffness.GetString() && stiffness > 0.0);

	double damping = wcstod(strDamping, &endPtr);
	bool dampingValid = (endPtr != strDamping.GetString() && damping >= 0.0);

	if (!massValid || !stiffnessValid || !dampingValid)
	{
		MessageBox(_T("Please enter a positive number for mass and stiffness, and a non-negative number for damping."),
			_T("Invalid input"), MB_ICONEXCLAMATION);
		return;
	}

	double fn = CalcNaturalFrequency(mass, stiffness);
	double zeta = CalcDampingRatio(mass, stiffness, damping);
	double fd = CalcDampedFrequency(fn, zeta);

	CString result;

	result.Format(_T("Natural Frequency: %.4f Hz"), fn);
	SetDlgItemText(IDC_STATIC_FN, result);

	result.Format(_T("Damping Ratio: %.4f"), zeta);
	SetDlgItemText(IDC_STATIC_ZETA, result);

	if (zeta < 1.0)
	{
		result.Format(_T("Damped Frequency: %.4f Hz"), fd);
	}
	else
	{
		result = _T("Damped Frequency: N/A (system is critically/overdamped)");
	}
	SetDlgItemText(IDC_STATIC_FD, result);
}
