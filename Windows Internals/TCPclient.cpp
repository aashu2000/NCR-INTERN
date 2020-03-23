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
    sockaddr_in clientaddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");//communication in the same system
    serveraddr.sin_port = htons(8001);
    SOCKET c;
    int Slen = sizeof(serveraddr);
    c = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (c == INVALID_SOCKET)
    {
        cout << "Socket Creation Failed" << endl;
    }
    else
    {
        cout << "Socket Creation Success" << endl;
    }
    int connection = connect(c, (SOCKADDR*)&serveraddr,Slen);
    if (connection == SOCKET_ERROR)
    {
        cout << "Connection establishment failed" << endl;
    }
    else {
        cout << "Connection success" << endl;
    }
    char Rbuffer[500];
    char Sbuffer[500] = "Hi from Client!!";
    int Receiving = recv(c, Rbuffer, strlen(Rbuffer)+1, 0);
    if (Receiving == SOCKET_ERROR)
    {
        cout << "Receive Data Failed due to error: " << WSAGetLastError() << endl;
    }
        
    cout << "DATA RECEIVED -> " << Rbuffer << endl;
    int Sending = send(c, Sbuffer, strlen(Sbuffer) + 1, 0);
    if (Sending == SOCKET_ERROR)
    {
        cout << "Sending Failed  due to error: " << WSAGetLastError() << endl;
    }
    cout << "Data Sending Success " << endl;
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
