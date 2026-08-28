// VibrationCalculator.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "VibrationCalculator.h"
#include "VibrationCalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CVibrationCalculatorApp

BEGIN_MESSAGE_MAP(CVibrationCalculatorApp, CWinApp)
END_MESSAGE_MAP()


// CVibrationCalculatorApp construction

CVibrationCalculatorApp::CVibrationCalculatorApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

// The one and only CVibrationCalculatorApp object

CVibrationCalculatorApp theApp;


// CVibrationCalculatorApp initialization

BOOL CVibrationCalculatorApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles. Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	CVibrationCalculatorDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// Handle OK
	}
	else if (nResponse == IDCANCEL)
	{
		// Handle Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	// application, rather than start the application's message pump.
	return FALSE;
}
