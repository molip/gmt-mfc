
#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "GMT.h"
#include "MainFrm.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(GMTApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &GMTApp::OnAppAbout)
END_MESSAGE_MAP()

GMTApp theApp;

GMTApp::GMTApp()
{
	SetAppID(L"GMT.AppID.NoVersion");
}

BOOL GMTApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	EnableTaskbarInteraction(FALSE);
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	MainFrame* pFrame = new MainFrame;
	if (!pFrame)
		return FALSE;

	m_pMainWnd = pFrame;
	pFrame->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr, nullptr);
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

class AboutDlg : public CDialogEx
{
public:
	AboutDlg();

protected:
	enum { IDD = IDD_ABOUTBOX };

	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
};

AboutDlg::AboutDlg() : CDialogEx(AboutDlg::IDD)
{
}

void AboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(AboutDlg, CDialogEx)
END_MESSAGE_MAP()

void GMTApp::OnAppAbout()
{
	AboutDlg aboutDlg;
	aboutDlg.DoModal();
}

BOOL GMTApp::OnIdle(LONG lCount)
{
	int ret = __super::OnIdle(lCount);
	ChildView::s_instance->Pump();
	return ret;
}


