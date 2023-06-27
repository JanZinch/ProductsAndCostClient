#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ProductItem.h"
#include <list>

#include <QBoxLayout>
#include <QListWidget>

#include <algorithm>


using namespace std;

class Customer
{

private:

    QListWidget* _queryView = nullptr;
    list<ProductItem> _queryModel;

public:

    Customer(QWidget* viewParent, QBoxLayout* viewLayout);
    bool AddToQuery(ProductItem productItem);

};

#endif // CUSTOMER_H
