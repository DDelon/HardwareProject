// DlgNotice.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GMServerTool.h"
#include "DlgNotice.h"
#include "afxdialogex.h"


// DlgNotice �Ի���

IMPLEMENT_DYNAMIC(DlgNotice, CDialogEx)

DlgNotice::DlgNotice(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SEND_MSG, pParent)
{

}

DlgNotice::~DlgNotice()
{
}

void DlgNotice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNotice, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgNotice::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgNotice ��Ϣ�������


void DlgNotice::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
