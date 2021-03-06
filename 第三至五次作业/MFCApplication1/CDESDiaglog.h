#pragma once


// CDESDiaglog 对话框

class CDESDiaglog : public CDialogEx
{
	DECLARE_DYNAMIC(CDESDiaglog)

public:
	CDESDiaglog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDESDiaglog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DES_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_MTEXT;
	CString m_KEY;
	CString m_CTEXT;
	afx_msg void OnBnClickedStartButton();
	CString m_ETEXT;
	afx_msg void OnBnClickedEButton();
	CString m_DText;
};
