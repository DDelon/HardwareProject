#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// DlgGMToolListPage �Ի���

class DlgGMToolListPage : public CDialogEx
{
	DECLARE_DYNAMIC(DlgGMToolListPage)

public:
	DlgGMToolListPage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgGMToolListPage();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CMD_LIST };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::map<std::string, CDialogEx*> _CMD_Dlgs;
	DECLARE_MESSAGE_MAP()
public:
	CListBox _CMD_LIST;
	afx_msg void OnLbnSelchangeListCmd();
	CListCtrl m_ListCtrlRoles;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	void RefrashRoleList();
};
