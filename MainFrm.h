#pragma once
#include "ChildView.h"

class MainFrame : public CFrameWnd
{
public:
	MainFrame();
	virtual ~MainFrame();

protected:
	DECLARE_DYNAMIC(MainFrame)

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

	CToolBar m_wndToolBar;
	CStatusBar m_wndStatusBar;
	ChildView m_wndView;

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()
};


