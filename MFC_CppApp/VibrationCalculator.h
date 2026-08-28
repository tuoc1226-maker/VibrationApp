// VibrationCalculator.h : main header file for the application
//
#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CVibrationCalculatorApp:
// See VibrationCalculator.cpp for the implementation of this class
//

class CVibrationCalculatorApp : public CWinApp
{
public:
	CVibrationCalculatorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CVibrationCalculatorApp theApp;
