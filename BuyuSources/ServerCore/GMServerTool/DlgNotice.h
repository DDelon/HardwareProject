#pragma once


// DlgNotice �Ի���

class DlgNotice : public CDialogEx
{
	DECLARE_DYNAMIC(DlgNotice)

public:
	DlgNotice(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgNotice();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEND_MSG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
