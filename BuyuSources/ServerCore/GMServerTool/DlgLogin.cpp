// DlgLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "DlgLogin.h"
#include "afxdialogex.h"


// DlgLogin �Ի���

IMPLEMENT_DYNAMIC(DlgLogin, CDialogEx)

DlgLogin::DlgLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
{

}

DlgLogin::~DlgLogin()
{
}

void DlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &DlgLogin::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &DlgLogin::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// DlgLogin ��Ϣ�������


void DlgLogin::OnBnClickedBtnLogin()
{
	CString acc;
	CString password;
	GetDlgItemText(IDC_EDT_ACCOUNT, acc);
	GetDlgItemText(IDC_EDT_PASSWORD, password);
	char * acc_temp = NULL;
	g_GMToolManager.StringToChar(acc, acc_temp);
	char * pd = NULL;
	g_GMToolManager.StringToChar(password, pd);
	g_GMToolManager.SendLoginReq(acc_temp, pd);
	delete[] acc_temp;
	delete[] pd;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void DlgLogin::OnBnClickedBtnCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
