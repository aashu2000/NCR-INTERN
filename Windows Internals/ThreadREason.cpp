#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

DWORD WINAPI ThreadFun1(LPVOID Str)
{
	Sleep(4000);
	int i;
	for (i = 0; i < 10000; i++) {
		cout << i << endl;
	}
	cout << "In thread 1" << endl;
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID Str)
{
	Sleep(3000);
	int i;
	for (i = 0; i < 10000; i++) {
		cout << i << endl;
	}
	cout << "In thread 2"<<endl;
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle[2];
	int i;
	LPVOID Str = NULL;
	CreateThreadHandle[0] = CreateThread(NULL,
		0,
		ThreadFun1,
		Str,
		0,
		NULL);
	if (CreateThreadHandle[0] == NULL)
	{
		cout << "creation of thread  0 failed due to error (" << GetLastError() << ")" << endl;
	}
	CreateThreadHandle[1] = CreateThread(NULL,
		0,
		ThreadFun2,
		Str,
		0,
		NULL);
	if (CreateThreadHandle[1] == NULL)
	{
		cout << "creation of thread  1 failed due to error (" << GetLastError() << ")" << endl;
	}

	DWORD retval = WaitForMultipleObjects(2, CreateThreadHandle, FALSE, 2000);
	switch (retval) {
	case WAIT_ABANDONED:
		cout << "Thread excution was abandoned" << endl;
		break;
	case WAIT_OBJECT_0:
		cout << "Thread execution is successful" << endl;
		break;
	case WAIT_TIMEOUT:
		cout << "Timeout, Thread excution was exited forecefully" << endl;
		break;
	case WAIT_FAILED:
		cout << "Function has failed" << endl;
		break;
	}
	for (i = 0; i < 2; i++) {
		CloseHandle(CreateThreadHandle[i]);//close the handle after use
	}
	cout << "In main"<<endl;
	return 0;
}