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

bool NetworkManager::VerifyProduct(const ProductItem & productItem)
{
    char messageBuffer[MESSAGE_BUFFER_SIZE];
    strcpy_s(messageBuffer, VERIFY_PRODUCT);
    strcat_s(messageBuffer, sizeof(messageBuffer), productItem.Name());

    send(_serverSocket, messageBuffer, sizeof(messageBuffer), 0);
    recv(_serverSocket, messageBuffer, sizeof(messageBuffer), 0);

    return strcmp(messageBuffer, STR_TRUE) == 0;
}

QMoney NetworkManager::CalculateQueryCost(const list<ProductItem> &productsQuery)
{
    const char QueryWordsDelimiter = '|';

    stringstream messageStream;
    messageStream << CALCULATE_QUERY_COST;

    for (ProductItem productItem : productsQuery){

        messageStream << productItem.Name();
        messageStream << QueryWordsDelimiter;
        messageStream << to_string(productItem.Amount());
        messageStream << QueryWordsDelimiter;
    }

    send(_serverSocket, messageStream.str().c_str(), MESSAGE_BUFFER_SIZE, 0);

    char messageBuffer[MESSAGE_BUFFER_SIZE];
    recv(_serverSocket, messageBuffer, sizeof(messageBuffer), 0);

    stringstream messageBufferStream;
    messageBufferStream.str(messageBuffer);

    QMoney cost;
    messageBufferStream >> cost;

    return cost;
}

NetworkManager::~NetworkManager()
{
    char messageBuffer[MESSAGE_BUFFER_SIZE];
    strcpy_s(messageBuffer, COMPLETE_SESSION);
    send(_serverSocket, messageBuffer, sizeof(messageBuffer), 0);

    closesocket(_serverSocket);
    WSACleanup();

    qDebug()<<"clean network";
}
