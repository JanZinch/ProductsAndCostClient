#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    _networkManager = shared_ptr<NetworkManager>(new NetworkManager(1280, "127.0.0.1"));

    if (!_networkManager->ConnectToServer()){

        QMessageBox messageBox;
        messageBox.critical(this, "Error", CONNECTION_ERROR_MSG, QMessageBox::Ok);
        messageBox.setFixedSize(500, 200);

        //delete _networkManager;

        throw exception(CONNECTION_ERROR_MSG);
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


void MainWidget::InitButton(QPushButton* instance, QString text, void(MainWidget::*onClickFunc)())
{
    instance = new QPushButton(text);
    _buttonsLayout->addWidget(instance);
    QObject::connect(instance, &QPushButton::clicked, this, onClickFunc);
}

void MainWidget::ShowAddItemForm()
{
    AddProductItemForm* form = new AddProductItemForm(nullptr, [](ProductItem createdProductItem){

        qDebug() << "Data: " << createdProductItem.ToString().c_str();

    });

    form->show();

}

MainWidget::~MainWidget()
{

}

