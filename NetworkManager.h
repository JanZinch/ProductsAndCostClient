#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#include "ProductItem.h"
#include <QDebug>

#define global

#define PING "@ping_______________"
#define COMPLETE_SESSION "@complete_session___"
#define VERIFY_PRODUCT "@verify_product_____"
#define COMMAND_SIZE 20
#define MESSAGE_BUFFER_SIZE 500
#define CONNECTION_ERROR_MSG "Connection error was occurred"
#define STR_TRUE "1"
#define STR_FALSE "0"

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
