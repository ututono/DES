#pragma once


// CDiffAnalyse 对话框

class CDiffAnalyse : public CDialogEx
{
	DECLARE_DYNAMIC(CDiffAnalyse)

public:
	CDiffAnalyse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDiffAnalyse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DiffAnalyse_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_InKey;
	CString m_outKey;
	CString m_Process;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit3();
};
