
// GMServerToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "GMServerToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGMServerToolDlg �Ի���



CGMServerToolDlg::CGMServerToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GMSERVERTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGMServerToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGMServerToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGMServerToolDlg ��Ϣ�������

BOOL CGMServerToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	g_dlg = this;
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	DlgLogin *DlgLoginTemp = new DlgLogin(this);
	DlgLoginTemp->Create(IDD_DIALOG_LOGIN, this);	
	DlgLoginTemp->ShowWindow(1);
	SetTimer(0, 100, 0);
	_dlgs[LoginDlg_Type] = DlgLoginTemp;	
	DlgGMToolListPage * DlgGMToolList = new DlgGMToolListPage(this);
	DlgGMToolList->Create(IDD_DIALOG_CMD_LIST, this);
	_dlgs[CmdPage_Type] = DlgGMToolList;
	std::map<DlgType, CDialogEx*>::iterator it = _dlgs.begin();
	for (; it != _dlgs.end(); ++ it)
	{
		CDialogEx* dlg = it->second;
		dlg->ActivateTopParent();
	}
	g_GMToolManager.Init();
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CGMServerToolDlg::LoginSucessful()
{
	
	_dlgs[LoginDlg_Type]->ShowWindow(FALSE);
	_dlgs[CmdPage_Type]->ShowWindow(TRUE);
}

void CGMServerToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGMServerToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGMServerToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


DlgLogin* CGMServerToolDlg::GetLogin()
{
	return (DlgLogin*)_dlgs[LoginDlg_Type];
}
DlgGMToolListPage* CGMServerToolDlg::GetGMTool()
{
	return (DlgGMToolListPage*)_dlgs[CmdPage_Type];
}


void CGMServerToolDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);
	CRect rcClient;
	GetClientRect(rcClient);
	ClientToScreen(rcClient);
	rcClient.left = rcClient.left + 210;
	std::map<DlgType, CDialogEx*>::iterator it = _dlgs.begin();
	for (; it != _dlgs.end(); ++ it)
	{
		CDialogEx* dlg = it->second;
		dlg->MoveWindow(rcClient);	
	}

	// TODO: �ڴ˴������Ϣ����������
}


void CGMServerToolDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnTimer(nIDEvent);
	g_GMToolManager.Update();
}


void CGMServerToolDlg::Notice(CString notice)
{
	_Notices.push_front(notice);
	if (_Notices.size() >= 15)
	{
		_Notices.pop_back();
	}

	CString curText = TEXT("");
	std::list<CString>::iterator it = _Notices.begin();
	for (; it != _Notices.end(); ++ it)
	{
		if (curText.IsEmpty() == false)
		{
			curText += TEXT("/r/n");
		}	
		curText += (*it);
	}
	SetDlgItemText(IDC_EDIT_NOTICE, curText);
}