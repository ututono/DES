// CDESDiaglog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CDESDiaglog.h"
#include "afxdialogex.h"


// CDESDiaglog 对话框

IMPLEMENT_DYNAMIC(CDESDiaglog, CDialogEx)

CDESDiaglog::CDESDiaglog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DES_Dialog, pParent)
	, m_MTEXT(_T(""))
	, m_KEY(_T(""))
	, m_CTEXT(_T(""))
	, m_ETEXT(_T(""))
	, m_DText(_T(""))
{

}

CDESDiaglog::~CDESDiaglog()
{
}

void CDESDiaglog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_InPMTEXT_EDIT, m_MTEXT);
	DDX_Text(pDX, IDC_InPKEY_EDIT, m_KEY);
	DDX_Text(pDX, IDC_OutCTEXT_EDIT, m_CTEXT);
	//DDX_Text(pDX, IDC_EText_EDIT1, m_ETEXT);
	DDX_Text(pDX, IDC_DText_EDIT1, m_DText);
}


BEGIN_MESSAGE_MAP(CDESDiaglog, CDialogEx)
	ON_BN_CLICKED(IDC_START_BUTTON, &CDESDiaglog::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_E_BUTTON, &CDESDiaglog::OnBnClickedEButton)
END_MESSAGE_MAP()


// CDESDiaglog 消息处理程序

extern void  DES_Efun(char input[8], char key_in[8], int output[64]);
extern void  DES_Dfun(int input[64], char key_in[8], char output[8]);
void CStrToCharstr(CString, char *);

void CDESDiaglog::OnBnClickedStartButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_CTEXT.Empty();
	char *MTstr;
	char *Key;
	int output[64] = { 0 };
	CString tmp;

	MTstr = (char*)malloc((m_MTEXT.GetLength() +1)* sizeof(char));
	Key = (char*)malloc((m_KEY.GetLength() +1)* sizeof(char));

	CStrToCharstr(m_MTEXT,MTstr );
	CStrToCharstr(m_KEY, Key);
	DES_Efun(MTstr, Key, output);
	for (int i = 0; i < 64; i++)
	{
		tmp.Format(_T("%d"), output[i]);
		m_CTEXT += tmp;
		if ((i + 1) % 8 == 0)
			m_CTEXT += "\r\n";
	}

	UpdateData(FALSE);
}

void CStrToCharstr(CString test, char *input) 
{
	char *inputstr;
	wchar_t *wChar = test.GetBuffer(test.GetLength());
	test.ReleaseBuffer();
	size_t len = wcslen(wChar) + 1;
	size_t converted = 0;
	inputstr = (char*)malloc(len * sizeof(char));
	wcstombs_s(&converted, inputstr, len, wChar, _TRUNCATE);
	strcpy(input, inputstr);
}

void CDESDiaglog::OnBnClickedEButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_DText.Empty();
	char Mtext[8];
	char *Key;
	char *MTstr;
	int output[64] = { 0 };
	CString tmp;

	MTstr = (char*)malloc((m_MTEXT.GetLength() + 1) * sizeof(char));
	Key = (char*)malloc((m_KEY.GetLength() + 1) * sizeof(char));

	CStrToCharstr(m_MTEXT, MTstr);
	CStrToCharstr(m_KEY, Key);
	DES_Efun(MTstr, Key, output);
	DES_Dfun(output, Key, Mtext);
	CString strData(Mtext);
	m_DText += Mtext;


	UpdateData(FALSE);
}
