#include "AddProductItemForm.h"

AddProductItemForm::AddProductItemForm(QWidget *parent, function<void(ProductItem)> onCreatedCallback): QWidget(parent)
{
    _mainLayout = new QVBoxLayout(this);

    _nameField = new QLineEdit(this);
    _amountField = new QLineEdit(this);

    _fieldsLayout = new QHBoxLayout(this);
    _fieldsLayout->addWidget(_nameField);
    _fieldsLayout->addWidget(_amountField);

    _nameField->setMaxLength(30);
    _amountField->setValidator(new QIntValidator(0, 9999, this));

    _mainLayout->addLayout(_fieldsLayout);

    _messageLabel = new QLabel("Input data");
    _createButton = new QPushButton("Add");

    QObject::connect(_createButton, &QPushButton::clicked, this, &AddProductItemForm::CreateAndNotify);

    _mainLayout->addWidget(_createButton);
    _mainLayout->addWidget(_messageLabel);

    _onCreatedCallback = onCreatedCallback;
}

void AddProductItemForm::CreateAndNotify()
{
    string name = _nameField->text().toStdString();
    int amount = _amountField->text().toInt();

    ProductItem createdProductItem = ProductItem(name.c_str(), amount);
    _onCreatedCallback(createdProductItem);
}


