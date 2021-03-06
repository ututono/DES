// CMainDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CMainDialog.h"
#include"MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include"CDESDiaglog.h"
#include"CDiffAnalyse.h"

// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
	ON_BN_CLICKED(IDC_Differ_BUTTON, &CMainDialog::OnBnClickedDifferButton)
	ON_BN_CLICKED(IDOK, &CMainDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_DES_BUTTON, &CMainDialog::OnBnClickedDesButton)
	ON_BN_CLICKED(IDC_DiffAnalyse_BUTTON1, &CMainDialog::OnBnClickedDiffanalyseButton1)
END_MESSAGE_MAP()


// CMainDialog 消息处理程序




void CMainDialog::OnBnClickedDifferButton()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CMFCApplication1Dlg differDlg;
	nRes = differDlg.DoModal();
	if (IDCANCEL == nRes) return;

}

void CMainDialog::OnBnClickedDesButton()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CDESDiaglog desDlg;
	nRes = desDlg.DoModal();
	if (IDCANCEL == nRes) return;
}

void CMainDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}





void CMainDialog::OnBnClickedDiffanalyseButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CDiffAnalyse desDlg;
	nRes = desDlg.DoModal();
	if (IDCANCEL == nRes) return;
}
