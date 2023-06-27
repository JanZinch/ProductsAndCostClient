#include "AddProductItemForm.h"

AddProductItemForm::AddProductItemForm(QWidget *parent): QWidget{parent}
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
    _addItemButton = new QPushButton("Add");

    _mainLayout->addWidget(_addItemButton);
    _mainLayout->addWidget(_messageLabel);
}
