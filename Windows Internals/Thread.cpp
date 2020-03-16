#include<iostream>
#include<Windows.h>
using namespace std;

DWORD WINAPI ThreadFun(LPVOID lpParam)
{
    for (int i = 1; i <= 1000; i++)
    {
        cout << i<< endl;
    }
    //cout << "\n Thread Running" << endl;
    return 0;
}

int main()
{
	HANDLE hthread = NULL;
	DWORD ThreadId = 0;
    // GetExitCodeThread(hthread, lpExitCode);
    hthread = CreateThread(NULL,//Security Attribute
        0,//Default Stack Size
        &ThreadFun,//ThreadStart Address
        NULL,//Parameter
        CREATE_SUSPENDED,//Flags
        &ThreadId);
    //Sleep(5000);
    if (hthread == NULL)
    {
        cout << "Thread Creation Failed due to error no: " << GetLastError() << endl;
    }
        getchar();
        Sleep(5000);
        ResumeThread(hthread);
        WaitForSingleObject(hthread, INFINITE);
         cout << "ThreadId: " << ThreadId << endl;
    CloseHandle(hthread);
	return 0;
}