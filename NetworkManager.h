#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#include "ProductItem.h"
#include <QDebug>

#define global

#define PING "@ping"
#define COMPLETE_SESSION "@complete_session"
#define MESSAGE_BUFFER_SIZE 500
#define CONNECTION_ERROR_MSG "Connection error was occurred"


class NetworkManager
{

private:

    sockaddr_in _serverAddress;
    SOCKET _serverSocket;

public:

    NetworkManager(int port, const char* ip);
    bool ConnectToServer();
    bool VerifyProduct(ProductItem productItem);
    ~NetworkManager();
};

#endif // NETWORKMANAGER_H
