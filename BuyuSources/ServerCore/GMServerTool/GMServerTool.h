
// GMServerTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGMServerToolApp: 
// �йش����ʵ�֣������ GMServerTool.cpp
//

class CGMServerToolApp : public CWinApp
{
public:
	CGMServerToolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGMServerToolApp theApp;