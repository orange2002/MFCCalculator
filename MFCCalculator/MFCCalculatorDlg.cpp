
// MFCCalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCCalculator.h"
#include "MFCCalculatorDlg.h"
#include "afxdialogex.h"
#include "expr.h"
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


// CMFCCalculatorDlg 对话框



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Text(pDX, IDC_EDIT2, m_result);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_E, &CMFCCalculatorDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_PI, &CMFCCalculatorDlg::OnBnClickedButtonPi)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CMFCCalculatorDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CMFCCalculatorDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CMFCCalculatorDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_SIN, &CMFCCalculatorDlg::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_COS, &CMFCCalculatorDlg::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_tan, &CMFCCalculatorDlg::OnBnClickedButtontan)
	ON_BN_CLICKED(IDC_BUTTON_COT, &CMFCCalculatorDlg::OnBnClickedButtonCot)
	ON_BN_CLICKED(IDC_BUTTON_SEC, &CMFCCalculatorDlg::OnBnClickedButtonSec)
	ON_BN_CLICKED(IDC_BUTTON_CSC, &CMFCCalculatorDlg::OnBnClickedButtonCsc)
	ON_BN_CLICKED(IDC_BUTTON_POW, &CMFCCalculatorDlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_ABS, &CMFCCalculatorDlg::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_ln, &CMFCCalculatorDlg::OnBnClickedButtonln)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CMFCCalculatorDlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_FACT, &CMFCCalculatorDlg::OnBnClickedButtonFact)
	ON_BN_CLICKED(IDC_BUTTON_LG, &CMFCCalculatorDlg::OnBnClickedButtonLg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CMFCCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CMFCCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CMFCCalculatorDlg::OnBnClickedButtonEqu)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCCalculatorDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMFCCalculatorDlg 消息处理程序

BOOL CMFCCalculatorDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCCalculatorDlg::OnPaint()
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
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCalculatorDlg::OnBnClickedButtonE()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += 'e';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonPi()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "pi";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '(';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonRight()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += ')';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Empty();
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Delete(m_str.GetLength() - 1, 1);
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonSin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "sin(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonCos()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "cos(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtontan()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "tan(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonCot()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "cot(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonSec()
{
	// TODO: 在此添加控件通知处理程序代码

	m_str += "sec(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonCsc()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "csc(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '^';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "abs(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonln()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "ln(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonMod()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '%';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonFact()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "fact(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonLg()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += "lg(";
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '+';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '-';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '*';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '/';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '1';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '2';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '3';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '4';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '5';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '6';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '7';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '8';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '9';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '.';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str += '0';
	UpdateData(FALSE);
}


void CMFCCalculatorDlg::OnBnClickedButtonEqu()
{
	// TODO: 在此添加控件通知处理程序代码
	std::string stmp=m_str.GetBuffer();
	try
	{
	m_result.Format("%lf",evaluate(stmp));
	}
	catch (int)
	{
		m_result = "ERROR";
	}

	UpdateData(FALSE);
	m_str.Empty();
}


void CMFCCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}
