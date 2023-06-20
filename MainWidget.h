#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <string>
#include <functional>

using namespace std;

class MainWidget : public QWidget
{
    Q_OBJECT

private:

    QVBoxLayout* _mainLayout = nullptr;

    QListWidget* _query = nullptr;

    QHBoxLayout* _buttonsLayout = nullptr;

    QPushButton* _addItemButton = nullptr;
    QPushButton* _editItemButton = nullptr;
    QPushButton* _removeItemButton = nullptr;
    QPushButton* _clearQueryButton = nullptr;


public:

    MainWidget(QWidget *parent = nullptr);
    void InitButton(QPushButton* instance, QString text, function<void(void)> onClickFunc);

    ~MainWidget();
};
#endif // MAINWIDGET_H