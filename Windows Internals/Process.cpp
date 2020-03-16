#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
int main()
{
    HANDLE hprocess = NULL;
	HANDLE hthread=NULL;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwProcessId = 0;
	DWORD dwThreadId = 0;
	ZeroMemory(&si, sizeof(si));//initializes all the structure members to zero.
	ZeroMemory(&pi, sizeof(pi));
	BOOL bCreateProcess = NULL;//return type of this process is a boolean value. If it does not succeed then we can print the error using GetLastError().
	bCreateProcess = CreateProcess(
		L"C:\\Users\\SM185572\\source\\repos\\Stack\\Debug\\Stack.exe",//lpApplicationName
		NULL,//lpCommandLine
		NULL,//lpProcessAttributes
		NULL,//lpThreadAttributes
		FALSE,//bInheritHandles
		0,//dwCreationFlags--flags that control the priority class and priority process
		NULL,//lpEnvironment
		NULL,//lpCurrentDirectory
		&si,//lpStartupInfo
		&pi);//lpProcessInfo
	system("PAUSE");
	if (bCreateProcess == FALSE)
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "success" << endl;
	}
	cout << "process id: " << pi.dwProcessId << endl;
	cout << "thread id: " << pi.dwThreadId << endl;
	cout << "GetCurrentProcessid: " << GetCurrentProcessId() << endl;
	cout << "GetCurrentThreadid: " << GetCurrentThreadId() << endl;
	//cout << "GetProcessIdOfThread: " << GetProcessIdOfThread(hprocess) << endl;
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

