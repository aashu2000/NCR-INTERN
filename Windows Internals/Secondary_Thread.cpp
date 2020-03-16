#include<iostream>
#include<Windows.h>
using namespace std;
DWORD ExitCode;
int i;

DWORD WINAPI ThreadFun(LPVOID lpParam)
{
    i = i + 1;
    ExitThread(ExitCode);
    //cout << "\n Thread Running" << endl;
    return i;
}

int main()
{
	HANDLE hthread = NULL;
	DWORD ThreadId = 0;
    i = 0;
    cout << "i in main: " << i << endl;
    hthread = CreateThread(NULL,//Security Attribute
        0,//Default Stack Size
        &ThreadFun,//ThreadStart Address
        &i,//Parameter
        CREATE_SUSPENDED,//Flags
        &ThreadId);
    //Sleep(5000);
    if (hthread == NULL)
    {
        cout << "Thread Creation Failed due to error no: " << GetLastError() << endl;
    }
    int j;
    j = GetExitCodeThread(hthread, &ExitCode);
    if (j == 0)
    {
        cout << "ExitThread Failed due to error: " << GetLastError() << endl;
    }
    WaitForSingleObject(hthread, 5000);
    cout << "Exit code:" << ExitCode << endl;
    cout << "i after thread execution : " << i << endl;
    cout << "ThreadID :" << ThreadId << endl;
    CloseHandle(hthread);
	return 0;
}