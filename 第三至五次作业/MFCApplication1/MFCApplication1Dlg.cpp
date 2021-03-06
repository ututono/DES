
// MFCApplication1Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_editInDiffer(_T(""))
	, m_editOutDiffer(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_InDiffer_EDIT1, m_editInDiffer);
	DDX_Text(pDX, IDC_OutDiffer_EDIT2, m_editOutDiffer);
	DDX_Control(pDX, IDC_OutDiffer_EDIT2, m_OutDiffer_Controlle);
	DDX_Control(pDX, IDC_RADIO1, m_S1);
	DDX_Control(pDX, IDC_RADIO2, m_S2);
	DDX_Control(pDX, IDC_RADIO3, m_S3);
	DDX_Control(pDX, IDC_RADIO4, m_S4);
	DDX_Control(pDX, IDC_RADIO5, m_S5);
	DDX_Control(pDX, IDC_RADIO6, m_S6);
	DDX_Control(pDX, IDC_RADIO7, m_S7);
	DDX_Control(pDX, IDC_RADIO8, m_S8);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_result_BUTTON1, &CMFCApplication1Dlg::OnBnClickedresultButton1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CheckDlgButton(IDC_RADIO1, 1);
	OnBnClickedresultButton1();
	CString test;
	test = "只取从左到右6位数字";
	m_OutDiffer_Controlle.SetWindowTextW(test);	

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


extern void DecToBit(int Dec, int Bitarry[], int bits);
extern void BitToDec(int Bitarry[], int &Dec);
extern void _Box(int input[6], int output[4], int Boxnum);
extern void CharToBit(const char input[], int output[], int bits);
extern void BitToChar(const int intput[], char output[], int bits);
extern void  DES_Efun(char input[8], char key_in[8], int output[64]);
extern void  DES_Dfun(int input[64], char key_in[8], char output[8]);
extern int Euclidean_nonRecursion(int a, int b);

//input输入差分，返回输出差分分布
CString EditPrint(int input[6],int boxname);

void CMFCApplication1Dlg::OnBnClickedresultButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CString test;
	test = m_editInDiffer;

	char *inputstr;
	int inputint[6];
	int boxname = 0;
	if (test.GetLength() != 0)
	{				//将CString的输入转化成char*再转换成int*
		wchar_t *wChar = test.GetBuffer(test.GetLength());
		test.ReleaseBuffer();
		size_t len = wcslen(wChar) + 1;
		size_t converted = 0;
		inputstr = (char*)malloc(len * sizeof(char));
		wcstombs_s(&converted, inputstr, len, wChar, _TRUNCATE);
		for (int i = 0; i < 6; i++)
		{
			if (inputstr[i] != '0') inputint[i] = 1;
			else inputint[i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			inputint[i] = 0;
		}
		inputint[5] = 1;
	}


	if (1 == m_S1.GetCheck()) boxname = 0;
	else if (1 == m_S2.GetCheck()) boxname = 1;
	else if (1 == m_S3.GetCheck()) boxname = 2;
	else if (1 == m_S4.GetCheck()) boxname = 3;
	else if (1 == m_S5.GetCheck()) boxname = 4;
	else if (1 == m_S6.GetCheck()) boxname = 5;
	else if (1 == m_S7.GetCheck()) boxname = 6;
	else if (1 == m_S8.GetCheck()) boxname = 7;

	test = EditPrint(inputint, boxname);
	m_editOutDiffer = test;
	UpdateData(FALSE);

}

CString EditPrint(int input[6],int boxname)
{
	CString print,tmp;
	int input_1[6], input_2[6];
	int out_1[4], out_2[4], outDiff[4], outDiff_2[4];
	int Flag = 0;

		for (int i = 0; i < 16; i++)
		{
			DecToBit(i, outDiff_2, 4);
			int Count = 0;
			for (int z = 0; z < 4; z++)
			{
				tmp.Format(_T("%d"), outDiff_2[z]);
				print=print+tmp;			//打印当前的输出差分
			}
			print += "\t";
			for (int j = 0; j < 64; j++)
			{
				DecToBit(j, input_1, 6);			//将十进制转化成二进制按位存储在整型数组中
				for (int k = 0; k < 6; k++)
				{
					input_2[k] = input_1[k] ^ input[k];
				}
				_Box(input_1, out_1, boxname);			//获取输出比特串
				_Box(input_2, out_2, boxname);
				for (int k = 0; k < 4; k++)
				{
					outDiff[k] = out_1[k] ^ out_2[k];
				}
				Flag = 1;
				for (int k = 0; k < 4; k++)
				{
					if (outDiff[k] != outDiff_2[k])
					{
						Flag = 0;
						break;
					}
				}
				if (Flag == 1)				//Flag=1说明计算的输出差分和当前输出差分一致
				{
					Count++;
					for (int m = 0; m < 6; m++)
					{
						tmp.Format(_T("%d"), input_1[m]);
						print = print + tmp;
					}
					print+=_T(",");
				}
			}
			if (Count == 0) print+=_T("无输入");
			else
			{
				tmp.Format(_T("\t输入数量为:	%d"), Count);
				print += tmp;
			}
			print+="\r\n";
		}
		return print;
}
