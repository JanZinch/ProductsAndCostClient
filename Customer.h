#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ProductItem.h"

#include <list>
#include <algorithm>
#include <QBoxLayout>
#include <QListWidget>
#include <QDebug>

using namespace std;

class Customer
{

private:

    QListWidget* _queryView = nullptr;
    list<ProductItem> _queryModel;

public:

    Customer(QWidget* viewParent, QBoxLayout* viewLayout);
    void AddToQuery(ProductItem productItem);
    void UpdateProduct(ProductItem productItem);

    ProductItem GetSelected();
    void RemoveSelectedFromQuery();   
    list<ProductItem> GetQuery() const;
    void ClearQuery();

};

#endif // CUSTOMER_H
