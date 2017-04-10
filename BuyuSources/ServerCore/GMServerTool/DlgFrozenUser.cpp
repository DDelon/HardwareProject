// DlgFrozenUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "DlgFrozenUser.h"
#include "afxdialogex.h"


// DlgFrozenUser �Ի���

IMPLEMENT_DYNAMIC(DlgFrozenUser, CDialogEx)

DlgFrozenUser::DlgFrozenUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FROZEN_USER, pParent)
{

}

DlgFrozenUser::~DlgFrozenUser()
{
}

void DlgFrozenUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BOOL DlgFrozenUser::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemInt(IDC_EDIT_FROZEN_TIME, 0);
	SetDlgItemInt(IDC_EDIT_USER_ID, _UserID);
	return TRUE;
}



void DlgFrozenUser::SetNickName(CString NickName)
{
	_NickName = NickName;
}
void DlgFrozenUser::SetUserID(DWORD UserID)
{
	_UserID = UserID;	
}
BEGIN_MESSAGE_MAP(DlgFrozenUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgFrozenUser::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgFrozenUser ��Ϣ�������


void DlgFrozenUser::OnBnClickedOk()
{
	int FrozenTime = GetDlgItemInt(IDC_EDIT_FROZEN_TIME);
	g_GMToolManager.KickUser(_UserID, FrozenTime);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
