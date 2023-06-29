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

        QListWidgetItem* sameItemView = _queryView->findItems(sameItem->ToQString(), Qt::MatchExactly).at(0);

        *sameItem = ProductItem(sameItem->Name(), sameItem->Amount() + productItem.Amount());
        sameItemView->setText((*sameItem).ToQString());
    }
    else {

        _queryModel.emplace_back(productItem);
        _queryView->addItem(productItem.ToQString());
    }

    return true;

}
