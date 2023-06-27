#include "NetworkManager.h"

NetworkManager::NetworkManager(int port, const char* ip)
{
    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_port = htons(port);
    _serverAddress.sin_addr.s_addr = inet_addr(ip);
}

bool NetworkManager::ConnectToServer()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD(2, 2);

    if (WSAStartup(wVersionRequested, &wsaData) != 0) {

        return false;
    }

    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(_serverSocket, (sockaddr*)&_serverAddress, sizeof(_serverAddress)) != 0) {

        return false;
    }
    else {

        char messageBuffer[MESSAGE_BUFFER_SIZE];
        strcpy_s(messageBuffer, PING);
        recv(_serverSocket, messageBuffer, sizeof(messageBuffer), 0);

        return strcmp(messageBuffer, PING) == 0;
    }

}

bool NetworkManager::VerifyProduct(ProductItem productItem)
{

    return true;
}

NetworkManager::~NetworkManager()
{
    closesocket(_serverSocket);
    WSACleanup();

    qDebug()<<"clean network";
}
