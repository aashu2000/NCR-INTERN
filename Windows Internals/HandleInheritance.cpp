#include<Windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	SECURITY_ATTRIBUTES Attribute;
	Attribute.nLength = sizeof(Attribute);
	Attribute.bInheritHandle = TRUE;
	Attribute.lpSecurityDescriptor = NULL;
	HANDLE CreateFileHandler;
	CreateFileHandler = CreateFile(argv[1],
		GENERIC_READ,
		0,
		&Attribute,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (CreateFileHandler == INVALID_HANDLE_VALUE)
	{
		cout << "handler initiation failed due to error : " << GetLastError() << endl;
		wcout << "failed to open file: " << argv[1] << endl;
	}
	else
	{
		STARTUPINFO StartUpInfo;
		PROCESS_INFORMATION ProcessInfo;
		ZeroMemory(&StartUpInfo, sizeof(StartUpInfo));
		ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
		StartUpInfo.cb = sizeof(StartUpInfo);
		BOOL Status = 0;
		Status = CreateProcess(NULL,
			argv[2],
			&Attribute,
			NULL,
			TRUE,
			0,
			NULL,
			NULL,
			&StartUpInfo,
			&ProcessInfo);
		if (Status == 0)
		{
			cout << "creation of process failed due to error:" << GetLastError() << endl;
		}
		else
		{
			cout << "creation of process succedded" << endl;
			cout << "handle value is " << ProcessInfo.hProcess << endl;
			cout << "handle value of create file handler is " << CreateFileHandler << endl;
		}
		WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
		CloseHandle(ProcessInfo.hProcess);
	}
}