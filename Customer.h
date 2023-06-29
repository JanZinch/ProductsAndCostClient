#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ProductItem.h"
#include <list>

#include <QBoxLayout>
#include <QListWidget>
#include <QDebug>

#include <algorithm>


using namespace std;

class Customer
{

private:

    QListWidget* _queryView = nullptr;
    list<ProductItem> _queryModel;

public:

    Customer(QWidget* viewParent, QBoxLayout* viewLayout);
    void AddToQuery(ProductItem productItem);
    void RemoveSelectedFromQuery();

};

#endif // CUSTOMER_H
