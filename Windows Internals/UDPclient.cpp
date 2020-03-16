//UDP client socket
#include <iostream>
#include<Windows.h>
#include<winsock.h>
using namespace std;
int main()
{
    WSADATA lpwsadata;
    int iWinsock;
    iWinsock=WSAStartup(MAKEWORD(2, 2), &lpwsadata);
    if (iWinsock == 0)
    {
        cout << "Initialization Success" << endl;
    }
    else
    {
        cout << "Initialization failed due to error: " << WSAGetLastError() << endl;
    }
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");//communication in the same system
    serveraddr.sin_port = htons(8001);
    SOCKET c;
    c = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (c == INVALID_SOCKET)
    {
        cout << "Socket Creation Failed" << endl;
    }
    else
    {
        cout << "Socket Creation Success" << endl;
    }
    char buffer[500]="Msg from Client";
    int Slen = sizeof(serveraddr);
    int send = sendto(c, buffer, strlen(buffer) + 1, MSG_DONTROUTE, (SOCKADDR*)&serveraddr, Slen);
    if (send == SOCKET_ERROR)
    {
        cout << "Send func failed due to error: " << WSAGetLastError() << endl;
    }
    else
    {
        cout << "Send func success" << endl;
    }
    int close = closesocket(c);
    if (close == 0)
    {
        cout << "Socket successfully closed" << endl;
    }
    else {
        cout << "Not Closed due to error no: " << WSAGetLastError() << endl;
    }
    int wsaclean = WSACleanup();
    if (wsaclean == 0)
    {
        cout << "CleanUp Success" << endl;
    }
    else {
        cout << "CleanUp failed due to error: " << WSAGetLastError() << endl;
    }
    system("PAUSE");
    return 0;



}
