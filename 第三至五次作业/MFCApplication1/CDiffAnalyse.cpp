// CDiffAnalyse.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CDiffAnalyse.h"
#include "afxdialogex.h"


// CDiffAnalyse 对话框

IMPLEMENT_DYNAMIC(CDiffAnalyse, CDialogEx)

CDiffAnalyse::CDiffAnalyse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DiffAnalyse_DIALOG1, pParent)
	, m_InKey(_T(""))
	, m_outKey(_T(""))
	, m_Process(_T(""))
{

}

CDiffAnalyse::~CDiffAnalyse()
{
}

void CDiffAnalyse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_InKey);
	DDX_Text(pDX, IDC_EDIT2, m_outKey);
	DDX_Text(pDX, IDC_EDIT3, m_Process);
}


BEGIN_MESSAGE_MAP(CDiffAnalyse, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDiffAnalyse::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT3, &CDiffAnalyse::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CDiffAnalyse 消息处理程序


//十进制转换为二进制整型数组
extern void DecToBit(int Dec, int Bitarry[], int bits);

//二进制转换为十进制
extern void BitToDec(int Bitarry[], int & Dec, int bits);

extern void SearchKey(int input_1[6], int input_2[6], int Key[6], int Cout[64]);

//初始化差分列表，INPUT:SBox输入差分
void InitDiffGrap(int input[6], int DiffGrap[16][64]);

void Auftrag5_main(int Key[6], CString &Cprint, CString &CKey);

void CDiffAnalyse::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_outKey.Empty();
	m_Process.Empty();
	CString test;
	test = m_InKey;
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
	Auftrag5_main(inputint, m_Process, m_outKey);

	UpdateData(FALSE);
}

void Auftrag5_main(int Key[6],CString &Cprint,CString &CKey)
{
	const int times = 8;
	CString temp;
	int Cout[64] = { 0 };
	int result[6];
	for (int i = 0; i < times; i++)
	{
		int input1 = rand() % 64;
		int input2 = rand() % 64;
		int input1B[6];
		int input2B[6];
		DecToBit(input1, input1B, 6);
		DecToBit(input2, input2B, 6);
		SearchKey(input1B, input2B, Key, Cout);

		int print[6];
		temp.Format(_T("第%d轮差分：   "), i);
		Cprint += temp;
		for (int m = 0; m < 64; m++)
		{
			if (Cout[m] > 0)
			{
				DecToBit(m, print, 6);
				for (int k = 0; k < 6; k++)
				{
					temp.Format(_T("%d"), print[k]);
					Cprint += temp;
				}
				temp.Format(_T("%3d,  "), Cout[m]);
				Cprint += temp;
			}
		}
		Cprint += _T("\r\n");
	}
	Cprint += _T("\r\n");
	for (int i = 0; i < 64; i++)
	{
		if (Cout[i] == times)
		{
			DecToBit(i, result, 6);
			Cprint += _T("密钥是:");
			for (int j = 0; j < 6; j++)
			{
				temp.Format(_T("%d"), result[j]);
				Cprint += temp;
				CKey += temp;
			}
			Cprint += _T("\r\n");
		}
	}
}


void CDiffAnalyse::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
