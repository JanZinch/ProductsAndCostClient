#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{

    if (!ConnectToServer()){

        QMessageBox messageBox;
        messageBox.critical(this, "Error", CONNECTION_ERROR_MSG, QMessageBox::Ok);
        messageBox.setFixedSize(500, 200);

        throw exception("Initialization failed");
    }

    _query = new QListWidget(this);

    _mainLayout = new QVBoxLayout(this);

    _mainLayout->addWidget(_query);


    QString itemEntry;
    QTextStream sstream(&itemEntry);

    ProductItem *p = new ProductItem("first", 10);
    sstream << *p;

    _query->addItem(itemEntry);

    _buttonsLayout = new QHBoxLayout(this);

    InitButton(_addItemButton, "Add item", &MainWidget::ShowAddItemForm);
    InitButton(_editItemButton, "Edit item", nullptr);
    InitButton(_removeItemButton, "Remove item", nullptr);
    InitButton(_confirmItemButton, "Confirm query", nullptr);
    InitButton(_clearQueryButton, "Clear query", nullptr);

    _mainLayout->addLayout(_buttonsLayout);

    setLayout(_mainLayout);

}

bool MainWidget::ConnectToServer()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD(2, 2);

    if (WSAStartup(wVersionRequested, &wsaData) != 0) {

        return false;
    }

    sockaddr_in remoteAddress;
    remoteAddress.sin_family = AF_INET;
    remoteAddress.sin_port = htons(1280);
    remoteAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (global::connect(_serverSocket, (sockaddr*)&remoteAddress, sizeof(remoteAddress)) != 0) {

        return false;
    }
    else {

        char messageBuffer[MESSAGE_BUFFER_SIZE];
        strcpy_s(messageBuffer, PING);
        recv(_serverSocket, messageBuffer, sizeof(messageBuffer), 0);

        return strcmp(messageBuffer, PING) == 0;
    }

    return 0;
}

void MainWidget::InitButton(QPushButton* instance, QString text, void(MainWidget::*onClickFunc)())
{
    instance = new QPushButton(text);
    _buttonsLayout->addWidget(instance);
    QObject::connect(instance, &QPushButton::clicked, this, onClickFunc);
}

void MainWidget::ShowAddItemForm()
{
    AddProductItemForm* form = new AddProductItemForm();
    form->show();

}

MainWidget::~MainWidget()
{
    closesocket(_serverSocket);
    WSACleanup();

    qDebug()<<"clean";
}

