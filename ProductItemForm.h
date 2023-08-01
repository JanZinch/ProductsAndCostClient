#ifndef PRODUCTITEMFORM_H
#define PRODUCTITEMFORM_H

#include "ProductItem.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QIntValidator>

#include <functional>

class ProductItemForm : public QWidget
{
    Q_OBJECT

private:

    QVBoxLayout* _mainLayout = nullptr;

    QHBoxLayout* _fieldsLayout = nullptr;

    QGridLayout* _layout = nullptr;

    QLabel* _nameLabel = nullptr;
    QLabel* _amountLabel = nullptr;

    QLineEdit* _nameField = nullptr;
    QLineEdit* _amountField = nullptr;

    QPushButton* _createButton = nullptr;
    QLabel* _messageLabel = nullptr;

    function<void(ProductItem)> _onCompleteCallback;

    void CreateAndNotify();
    void EditAndNotify();

public:

    explicit ProductItemForm(QWidget *parent = nullptr, function<void(ProductItem)> onCreatedCallback = nullptr);
    explicit ProductItemForm(const ProductItem &editableItem, QWidget *parent = nullptr, function<void(ProductItem)> onEditedCallback = nullptr);


signals:

};

#endif // PRODUCTITEMFORM_H
