// LogonServer.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "FishServer.h"
bool strlHandler(DWORD fdwctrltype)
{
	switch (fdwctrltype)
	{
	case CTRL_CLOSE_EVENT://ֱ�ӹرճ���
		g_FishServer.SetServerClose();
		return true;
	}
	return true;
}
DWORD WINAPI MainUpdate(LPVOID pParam)
{
	g_FishServer.MainUpdate();
	printf("��ѭ���߳��뿪..");
	//std::cout << "��ѭ���߳��뿪..";
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 1)
	{
#ifdef _DEBUG
		printf("Debugģʽ�� �����������...");
		//std::cout << "Debugģʽ�� �����������...";
		getchar();
#endif
	}
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)strlHandler, true))
	{
		ASSERT(false);
		return 0;
	}

	DWORD Index = 0;
	if (argc == 2)
	{
		Index = _ttoi(argv[1]);
	}
	else
	{
		printf("�������½�����������к�:");
		//std::cout << "�������½�����������к�:";
		std::cin >> Index;
	}

	if (!g_FishServer.InitServer(Index))
	{
		ASSERT(false);
		return 0;
	}
	DWORD nThreadID;
	CreateThread(0, 0, &MainUpdate, NULL, 0, &nThreadID);
	//�ȴ����� ��������Ϊ "exit"  ��ִ���˳����� ���ҹر��߳�
	std::string str;
	do
	{
		printf("����̨ �������� exit Ϊ �˳����� :\n");
		//std::cout << "����̨ �������� exit Ϊ �˳����� :\n";
		std::cin >> str;
		if (str.compare("exit") == 0)
		{
			g_FishServer.SetServerClose();//���ڹر��߳�
			return 0;
		}
		else if (str.compare("reloadconfig") == 0)
		{
			g_FishServer.SetReloadConfig();
		}
		else
		{
			printf("δ֪�Ŀ���̨���� �޷����д���\n");
			//std::cout << "δ֪�Ŀ���̨���� �޷����д���\n";
		}

	} while (true);
	return 0;
}

