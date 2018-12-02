
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_editInDiffer;
	CString m_editOutDiffer;
	afx_msg void OnEnChangeOutdifferEdit2();
	afx_msg void OnBnClickedresultButton1();
	CEdit m_OutDiffer_Controlle;
	CButton m_S1;
	CButton m_S2;
	CButton m_S3;
	CButton m_S4;
	CButton m_S5;
	CButton m_S6;
	CButton m_S7;
	CButton m_S8;
};
