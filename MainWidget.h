#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "AddProductItemForm.h"
#include "ProductItem.h"
#include "NetworkManager.h"

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

#include <memory>

using namespace std;

class MainWidget : public QWidget
{
    Q_OBJECT

private:

    shared_ptr<NetworkManager> _networkManager = nullptr;

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

    void InitButton(QPushButton* instance, QString text, void(MainWidget::*onClickFunc)());
    void ShowAddItemForm();

};
#endif // MAINWIDGET_H
