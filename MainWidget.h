#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "AddProductItemForm.h"
#include "ProductItem.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#include <QDebug>
#include <QWindow>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <string>
#include <functional>
#include <sstream>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>

#define global

#define PING "@ping"
#define COMPLETE_SESSION "@complete_session"
#define MESSAGE_BUFFER_SIZE 500
#define CONNECTION_ERROR_MSG "Connection error was occurred"

using namespace std;

class MainWidget : public QWidget
{
    Q_OBJECT

private:

    SOCKET _serverSocket;

    QVBoxLayout* _mainLayout = nullptr;
    QListWidget* _query = nullptr;

    QHBoxLayout* _buttonsLayout = nullptr;

    QPushButton* _addItemButton = nullptr;
    QPushButton* _editItemButton = nullptr;
    QPushButton* _removeItemButton = nullptr;
    QPushButton* _confirmItemButton = nullptr;
    QPushButton* _clearQueryButton = nullptr;


public:

    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:

    bool ConnectToServer();
    void InitButton(QPushButton* instance, QString text, void(MainWidget::*onClickFunc)());
    void ShowAddItemForm();


};
#endif // MAINWIDGET_H
