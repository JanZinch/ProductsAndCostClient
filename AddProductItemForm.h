#ifndef ADDPRODUCTITEMFORM_H
#define ADDPRODUCTITEMFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QIntValidator>

class AddProductItemForm : public QWidget
{
    Q_OBJECT

private:

    QVBoxLayout* _mainLayout = nullptr;

    QHBoxLayout* _fieldsLayout = nullptr;
    QLineEdit* _nameField = nullptr;
    QLineEdit* _amountField = nullptr;


    QPushButton* _addItemButton = nullptr;
    QLabel* _messageLabel = nullptr;

public:

    explicit AddProductItemForm(QWidget *parent = nullptr);

signals:

};

#endif // ADDPRODUCTITEMFORM_H
