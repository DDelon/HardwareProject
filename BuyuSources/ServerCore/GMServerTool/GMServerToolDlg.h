
// GMServerToolDlg.h : ͷ�ļ�
//

#pragma once
enum DlgType
{
	LoginDlg_Type,
	CmdPage_Type,
};

class DlgLogin;
class DlgGMToolListPage;

// CGMServerToolDlg �Ի���
class CGMServerToolDlg : public CDialogEx
{
// ����
public:
	CGMServerToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GMSERVERTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	std::map<DlgType, CDialogEx*> _dlgs;
	std::list<CString> _Notices;
	
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMove(int x, int y);
	DlgLogin* GetLogin();
	DlgGMToolListPage* GetGMTool();
	void LoginSucessful();
	void Notice(CString notice);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
