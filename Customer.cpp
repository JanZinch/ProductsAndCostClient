#include "Customer.h"

Customer::Customer(QWidget *viewParent, QBoxLayout *layout)
{
    _queryView = new QListWidget(viewParent);
    layout->addWidget(_queryView);
}

bool Customer::AddToQuery(ProductItem productItem)
{
    list<ProductItem>::iterator sameItem = find(_queryModel.begin(), _queryModel.end(), productItem);

    if (sameItem != _queryModel.end()){

        *sameItem = ProductItem(sameItem->Name(), sameItem->Amount() + productItem.Amount());

        _queryView->addItem((*sameItem).ToQString());        // TODO find and edit

    }
    else {

        _queryModel.emplace_back(productItem);
        _queryView->addItem(productItem.ToQString());
    }

    return true;

}
