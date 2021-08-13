
// MFCCalculatorDlg.h: 头文件
//

#pragma once


// CMFCCalculatorDlg 对话框
class CMFCCalculatorDlg : public CDialogEx
{
// 构造
public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
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
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonPi();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonSin();
	afx_msg void OnBnClickedButtonCos();
	afx_msg void OnBnClickedButtontan();
	afx_msg void OnBnClickedButtonCot();
	afx_msg void OnBnClickedButtonSec();
	afx_msg void OnBnClickedButtonCsc();
	afx_msg void OnBnClickedButtonPow();
	afx_msg void OnBnClickedButtonAbs();
	afx_msg void OnBnClickedButtonln();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonFact();
	afx_msg void OnBnClickedButtonLg();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonEqu();
public:
	CString m_str;
	CString m_result;
	afx_msg void OnEnChangeEdit1();
};
