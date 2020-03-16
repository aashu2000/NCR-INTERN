#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

int _tmain(int argc, WCHAR* argv[])
{
	BOOL bCreateProcess;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	bCreateProcess = CreateProcess(
		NULL,//Application name will be taken through cmd line argument
		argv[1],//command line argument
		NULL,//process not inheritable
		NULL,//thread not inheritable
		FALSE,//handle inheritance not possible
		0,//flags
		NULL,//environment variables
		NULL,//directory
		&si,//startup information
		&pi//process information
	);
	if (bCreateProcess == 0)
	{
		cout << "process creation failed with error no:  " << GetLastError() << endl;
	}
	else {
		cout << "process 1 creation success" << endl;
		cout << "ProcessId: " << GetProcessId(pi.hProcess) << endl;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	bCreateProcess = CreateProcess(
		NULL,//Application name will be taken through cmd line argument
		argv[2],//command line argument
		NULL,//process not inheritable
		NULL,//thread not inheritable
		FALSE,//handle inheritance not possible
		0,//flags
		NULL,//environment variables
		NULL,//directory
		&si,//startup information
		&pi//process information
	);
	if (bCreateProcess == 0)
	{
		cout << "process creation failed with error no:  "<< GetLastError() << endl;
	}
	else {
		cout << "Process 2 creation success" << endl;
		cout << "ProcessId: " << GetProcessId(pi.hProcess) << endl;
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}