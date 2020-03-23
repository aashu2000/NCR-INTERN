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
    sockaddr_in serveraddr;
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

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(8001);
    SOCKET s;
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
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
    b = bind(s, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
    if (b == 0)
    {
        cout << "Binding success" << endl;
    }
    else
    {
        cout << "Binding failed due to error: " <<WSAGetLastError()<< endl;
        return 0;
    }
    
    int Listening = listen(s, 2);
    if (Listening == SOCKET_ERROR)
    {
        cout << "Listen Fun Failed due to error no: " <<WSAGetLastError()<< endl;
        return 0;
        
    }
    else {
        cout << "Listen Function Success" << endl;
    }
    SOCKET sAcceptSocket;
    int Clen = sizeof(clientaddr);
    sAcceptSocket = accept(s,
        (SOCKADDR*)&clientaddr,
        &Clen);
    if (sAcceptSocket == INVALID_SOCKET)
    {
        cout << "Accept Failed due to error no : " <<WSAGetLastError()<< endl;
        return 0;
        
    }
    else {
        cout << "Connection Accepted" << endl;
    }


    char Sbuffer[512]="Hello from Server!!";
    char Rbuffer[512];
    int  Sending = send(sAcceptSocket, Sbuffer, strlen(Sbuffer)+1, 0);
    if (Sending == SOCKET_ERROR)
    {
        cout << "Sending Failed  due to error no : " << WSAGetLastError() << endl;
        return 0;
        
    }
    else {
        cout << "Data Sending Success " << endl;
    }

    int Receiving = recv(sAcceptSocket, Rbuffer, strlen(Rbuffer)+1, 0);
    if (Receiving == SOCKET_ERROR)
    {
        cout << "Receive Data Failed due to error no : " << WSAGetLastError() << endl;
        
    }
    else {
        cout << "DATA RECEIVED -> " << Rbuffer << endl;
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
