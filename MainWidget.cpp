#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{

    _query = new QListWidget(this);

    _mainLayout = new QVBoxLayout(this);

    _mainLayout->addWidget(_query);


    _buttonsLayout = new QHBoxLayout(this);


//    void (MainWidget::*func1)() = &MainWidget::ShowAddItemForm;
//    (this->*func1)();

//    function<void (void)> func2;
//    func2 = bind(&MainWidget::ShowAddItemForm, this);
//    func2();


    InitButton(_addItemButton, "Add item", &MainWidget::ShowAddItemForm);
    InitButton(_editItemButton, "Edit item", nullptr);
    InitButton(_removeItemButton, "Remove item", nullptr);
    InitButton(_clearQueryButton, "Clear query", nullptr);

    _mainLayout->addLayout(_buttonsLayout);

    setLayout(_mainLayout);

}

void MainWidget::InitButton(QPushButton* instance, QString text, void(MainWidget::*onClickFunc)())
{
    instance = new QPushButton(text);
    _buttonsLayout->addWidget(instance);
    connect(instance, &QPushButton::clicked, this, onClickFunc);
}

void MainWidget::ShowAddItemForm()
{
    AddProductItemForm* form = new AddProductItemForm();
    form->show();



}

MainWidget::~MainWidget()
{
}

