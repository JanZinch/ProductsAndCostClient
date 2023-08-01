#include "ProductItemForm.h"

ProductItemForm::ProductItemForm(QWidget *parent, function<void(ProductItem)> onCompleteCallback): QWidget(parent)
{
    setWindowTitle("Add product");
    resize(400, 100);

    _layout = new QGridLayout(this);

    _nameLabel = new QLabel("Name: ", this);
    _nameField = new QLineEdit(this);
    _nameField->setMaxLength(30);

    _amountLabel = new QLabel("Amount: ", this);
    _amountField = new QLineEdit(this);
    _amountField->setValidator(new QIntValidator(0, 9999, this));

    _createButton = new QPushButton("Add");

    _layout->addWidget(_nameLabel, 0, 0);
    _layout->addWidget(_nameField, 0, 1);
    _layout->addWidget(_amountLabel, 1, 0);
    _layout->addWidget(_amountField, 1, 1);

    _layout->addWidget(_createButton, 2, 0, 1, 2);

    QObject::connect(_createButton, &QPushButton::clicked, this, &ProductItemForm::CreateAndNotify);

    _onCompleteCallback = onCompleteCallback;
}

ProductItemForm::ProductItemForm(const ProductItem &editableItem, QWidget *parent, function<void (ProductItem)> onCompleteCallback)
{
    setWindowTitle("Edit product");
    resize(400, 100);

    _layout = new QGridLayout(this);

    _nameLabel = new QLabel("Name: ", this);
    _nameField = new QLineEdit(this);
    _nameField->setMaxLength(30);
    _nameField->setText(editableItem.Name());
    _nameField->setEnabled(false);

    _amountLabel = new QLabel("Amount: ", this);
    _amountField = new QLineEdit(this);
    _amountField->setValidator(new QIntValidator(0, 9999, this));

    _createButton = new QPushButton("Edit");

    _layout->addWidget(_nameLabel, 0, 0);
    _layout->addWidget(_nameField, 0, 1);
    _layout->addWidget(_amountLabel, 1, 0);
    _layout->addWidget(_amountField, 1, 1);

    _layout->addWidget(_createButton, 2, 0, 1, 2);

    QObject::connect(_createButton, &QPushButton::clicked, this, &ProductItemForm::CreateAndNotify);

    _onCompleteCallback = onCompleteCallback;

}

void ProductItemForm::CreateAndNotify()
{
    string name = _nameField->text().toStdString();
    int amount = _amountField->text().toInt();

    ProductItem createdProductItem = ProductItem(name.c_str(), amount);
    _onCompleteCallback(createdProductItem);
}

