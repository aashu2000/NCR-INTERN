#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE semaphore;


DWORD WINAPI threadProc(LPVOID lpParam) {
    DWORD waitResult;
    waitResult = WaitForSingleObject(semaphore, 0L);

    Sleep(2000);

    switch (waitResult)
    {
    case WAIT_OBJECT_0:
        printf("Thread %d: wait succeeded\n", GetCurrentThreadId());

        //releasing semaphore
        if (!ReleaseSemaphore(
            semaphore,
            1,
            NULL
        )) {
            cout << "Release semaphore error: " << GetLastError() << endl;
        }

        break;

    case WAIT_TIMEOUT:
        printf("Thread %d: wait timed out\n", GetCurrentThreadId());
        break;
    }

    return 0;
}


int main()
{
    HANDLE tHandle[4];
    DWORD tID;

    //creating semaphore
    semaphore = CreateSemaphore(
        NULL,
        2,
        2,
        NULL
    );

    if (semaphore == NULL) {
        cout << "CreateSemaphore error: " << GetLastError() << endl;
        return 0;
    }

    //creating 4 threads
    for (int i = 0; i < 4; i++) {
        tHandle[i] = CreateThread(
            NULL,
            0,
            threadProc,
            NULL,
            0,
            &tID
        );

        if (tHandle[i] == NULL) {
            cout << "Create thread error: " << GetLastError() << endl;
            return 0;
        }
    }

    WaitForMultipleObjects(4, tHandle, TRUE, INFINITE);

    for (int i = 0; i < 4; i++) {
        CloseHandle(tHandle[i]);
    }

    CloseHandle(semaphore);

    return 0;
}