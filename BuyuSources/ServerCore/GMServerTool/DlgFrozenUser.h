#pragma once


// DlgFrozenUser �Ի���

class DlgFrozenUser : public CDialogEx
{
	DECLARE_DYNAMIC(DlgFrozenUser)

public:
	DlgFrozenUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgFrozenUser();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FROZEN_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

protected:
	DWORD _UserID;
	int FrozenTime;

	DECLARE_MESSAGE_MAP()
};
