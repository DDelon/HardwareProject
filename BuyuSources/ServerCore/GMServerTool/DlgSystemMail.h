#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// DlgSystemMail �Ի���

class DlgSystemMail : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSystemMail)

public:
	DlgSystemMail(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgSystemMail();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_SYSTEM_MAIL };
#endif
protected:
	CString _NickName;
	DWORD _UserID;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	void SetNickName(CString& NickName);
	void SetUserID(DWORD UserID);
public:
	CListBox _ListRewards;
	CListCtrl _ListCtrlRewardItems;
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnLbnSelchangeListRewardId();
	afx_msg void OnBnClickedOk();
	
};
