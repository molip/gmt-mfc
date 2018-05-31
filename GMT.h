#pragma once

#include "resource.h"

class GMTApp : public CWinApp
{
public:
	GMTApp();

protected:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount) override;

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern GMTApp theApp;
