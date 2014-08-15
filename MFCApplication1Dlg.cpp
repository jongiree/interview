
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//Reverse String////////////////////////////////////////////////////////////////////////
string CMFCApplication1Dlg::Reverse(string str)
{
	string strReturn = "";
	for (int i = 0; i < (int)str.length(); i++)
	{
		strReturn = str[i] + strReturn;
	}
	return strReturn;
}

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	string str = "abcdef";
	string strReverse = Reverse(str);
	printf("Reverse = '%s'", strReverse);
}
//Reverse String////////////////////////////////////////////////////////////////////////

//Re Ordering int array////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::Ascending(int *array, int nCount)
{
 	int nTemp = 0;
	for (int i = 0; i < (nCount-1); i++)
	{
		for (int j = i + 1; j < nCount; j++)
		{
			if (array[i] > array[j])
			{
				nTemp = array[i];
				array[i] = array[j];
				array[j] = nTemp;
			}
		}
	}
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	int array[] = {9, 7, 10, 5, 6, 4, 1, 2};
	int nCount = sizeof(array) / sizeof(array[0]);
	Ascending(array, nCount);
}
//Re Ordering int array////////////////////////////////////////////////////////////////////////

//Reverse Sentence////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	char str[100] = "I come from London.";

 	revert_sentence(str);
 
// 	//cout << str << endl;

}

void CMFCApplication1Dlg::revert_str(char *start, char* end)
{
	while (*end != '\0' && *start != '\0' && end > start)
	{
		char t = *start;
		*start = *end;
		*end = t;
		start++;
		end--;
	}
}

bool CMFCApplication1Dlg::is_letter(char l)
{
	if ((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CMFCApplication1Dlg::revert_sentence(char *str)
{
	char *start = str;
	char *end = str;

	if (str == NULL)
	{
		return;
	}

	while (*end != '\0')
	{
		end++;
	}

	end--;

	while (*end != '\0' && *start != '\0' && end > start)
	{
		char t = *start;
		*start = *end;
		*end = t;
		start++;
		end--;
	}

	start = str;

	while (*start != '\0')
	{
		end = start;

		while (is_letter(*end))
		{
			end++;
		}

		end--;

		revert_str(start, end);

		end++;

		start = end;
		while (*start != '\0' && !is_letter(*start))
		{
			start++;
		}
	}
}
//Reverse Sentence////////////////////////////////////////////////////////////////////////

int FactorialFunc(int n);
//Factorial ////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButton4()
{
	int nRet = FactorialFunc(5);
}

int Factorial(int n)
{
	int i = 0;
	int nFactorial = 1;
	if (n <= 1)
	{
		return(1);
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			nFactorial = nFactorial*i;
		}
	}
}

int FactorialFunc(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * FactorialFunc(n - 1);
}
//Factorial ////////////////////////////////////////////////////////////////////////
