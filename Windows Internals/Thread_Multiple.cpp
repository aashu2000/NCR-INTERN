#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
int i = 0;
int a, b, c;

DWORD WINAPI ThreadFun(LPVOID Str)
{
	i++;
	a = 5;
	b = 2;
	Sleep(1000);
	return 0;
}

DWORD WINAPI ThreadFun1(LPVOID Str)
{
	i++;
	c = a + b;
	Sleep(1000);
	return 0;
}
int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle[2];
	DWORD ReturnVal;
	CreateThreadHandle[0] = CreateThread(NULL,
		0,
		ThreadFun,
		NULL,
		0,
		NULL);
	if (CreateThreadHandle[0] == NULL)
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	CreateThreadHandle[1] = CreateThread(NULL,
		0,
		ThreadFun1,
		NULL,
		0,
		NULL);
	if (CreateThreadHandle[1] == NULL)
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	ReturnVal = WaitForMultipleObjects(2, CreateThreadHandle, TRUE, 2000);
	switch (ReturnVal)
	{
	case WAIT_ABANDONED_0:cout << "wait abondened" << endl;
		break;
	case WAIT_TIMEOUT:cout << "wait timedout and object is not signalled yet" << endl;
		break;
	case WAIT_FAILED:cout << "wait failed due to error (" << GetLastError() << ")" << endl;
		break;
	case WAIT_OBJECT_0:cout << "wait succedded and object is signalled" << endl;
		cout << "Value of i: " << i << endl;
		cout << "Sum of the numbers given is: " << c << endl;
		break;
	default:cout << "unhandled return value" << endl;
	}
	cout << "Value of i: " << i << endl;
	cout << "Sum of the numbers given is: " << c << endl;
	CloseHandle(CreateThreadHandle[0]);
	CloseHandle(CreateThreadHandle[1]);
	return 0;
}