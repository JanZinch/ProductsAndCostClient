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

    QLabel* _nameLabel = nullptr;
    QLabel* _amountLabel = nullptr;

    QLineEdit* _nameField = nullptr;
    QLineEdit* _amountField = nullptr;

    QPushButton* _createButton = nullptr;
    QLabel* _messageLabel = nullptr;

    function<void(ProductItem)> _onCreatedCallback;


public:

    explicit ProductItemForm(QWidget *parent = nullptr, function<void(ProductItem)> onCreatedCallback = nullptr);
    void CreateAndNotify();

signals:

};

#endif // PRODUCTITEMFORM_H
