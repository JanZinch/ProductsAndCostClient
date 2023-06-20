#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{

    _query = new QListWidget(this);

    _mainLayout = new QVBoxLayout(this);

    _mainLayout->addWidget(_query);


    _buttonsLayout = new QHBoxLayout(this);

//    function<void ()> f;
//    f = ShowAddItemForm;

    InitButton(_addItemButton, "Add item", [this](){ShowAddItemForm();});

    InitButton(_editItemButton, "Edit item", nullptr);

    InitButton(_removeItemButton, "Remove item", nullptr);
    InitButton(_clearQueryButton, "Clear query", nullptr);

    _mainLayout->addLayout(_buttonsLayout);

    setLayout(_mainLayout);

}

void MainWidget::InitButton(QPushButton* instance, QString text, function<void ()> onClickFunc)
{
    instance = new QPushButton(text);
    _buttonsLayout->addWidget(instance);
    connect(instance, &QPushButton::clicked, this, onClickFunc);
}

void MainWidget::ShowAddItemForm()
{

}

MainWidget::~MainWidget()
{
}

