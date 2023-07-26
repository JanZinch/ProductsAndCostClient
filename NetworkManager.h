#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#include "ProductItem.h"
#include "Money.h"
#include <QDebug>

#define global

#define PING "@ping_______________"
#define COMPLETE_SESSION "@complete_session___"
#define VERIFY_PRODUCT "@verify_product_____"
#define CALCULATE_QUERY_COST "@calc_query_cost____"
#define COMMAND_SIZE 20
#define MESSAGE_BUFFER_SIZE 500
#define CONNECTION_ERROR_MSG "Connection error was occurred"
#define STR_TRUE "1"
#define STR_FALSE "0"

using namespace MoneyLogic;

class NetworkManager
{

private:

    sockaddr_in _serverAddress;
    SOCKET _serverSocket;

public:

    NetworkManager(int port, const char* ip);
    bool ConnectToServer();
    bool VerifyProduct(const ProductItem &productItem);
    Money CalculateQueryCost(const list<ProductItem> &productsQuery);
    ~NetworkManager();
};

#endif // NETWORKMANAGER_H
