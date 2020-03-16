// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//UDP server socket

#include <iostream>
#include<Windows.h>
#include<winsock.h>
using namespace std;

int main()
{
    WSADATA lpwsadata;
    sockaddr_in clientaddr;
    int iWinsock;
    iWinsock = WSAStartup(MAKEWORD(2, 2), &lpwsadata);
    if (iWinsock == 0)
    {
        cout << "Initialization Success" << endl;
    }
    else
    {
        cout << "Initialization failed due to error: "<<WSAGetLastError() << endl;
    }

    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientaddr.sin_port = htons(8001);
    SOCKET s;
    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s == INVALID_SOCKET)
    {
        cout << "Socket Creation Failed" << endl;
        return 0;
    }
    else
    {
        cout << "Socket Creation Success" << endl;
    }
    int b;
    b = bind(s, (SOCKADDR*)&clientaddr, sizeof(clientaddr));
    if (b == 0)
    {
        cout << "Binding success" << endl;
    }
    else
    {
        cout << "Binding failed due to error: " <<WSAGetLastError()<< endl;
        return 0;
    }
    char buffer[512];
    int Clen = sizeof(clientaddr);
    int receive = recvfrom(s, buffer, strlen(buffer) + 1, MSG_PEEK, (SOCKADDR*)&clientaddr,&Clen);
    if (receive == SOCKET_ERROR)
    {
        cout << "Receive func failed due to error: " << WSAGetLastError() << endl;
        return 0;
    }
    else
    {
        cout << "Receive func success" << endl;
        cout << "Data Received-> " << buffer << endl;
    }
    int close = closesocket(s);
    if (close == 0)
    {
        cout<<"Socket successfully closed" << endl;
    }
    else {
        cout << "Not Closed due to error no: " << WSAGetLastError << endl;
    }
    int wsaclean=WSACleanup();
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
