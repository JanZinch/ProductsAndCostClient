#include "Customer.h"

Customer::Customer(QWidget *viewParent, QBoxLayout *layout)
{
    _queryView = new QListWidget(viewParent);
    layout->addWidget(_queryView);
}

void Customer::AddToQuery(ProductItem productItem)
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
}

void Customer::UpdateProduct(ProductItem productItem)
{
    list<ProductItem>::iterator sameItem = find(_queryModel.begin(), _queryModel.end(), productItem);

    if (sameItem != _queryModel.end()){

        QListWidgetItem* sameItemView = _queryView->findItems(sameItem->ToQString(), Qt::MatchExactly).at(0);

        *sameItem = ProductItem(sameItem->Name(), productItem.Amount());
        sameItemView->setText((*sameItem).ToQString());
    }

}

ProductItem Customer::GetSelected()
{
    QListWidgetItem *currentItemView = _queryView->currentItem();

    qDebug() << QString("Current: %1").arg(currentItemView->text());

    if (currentItemView != nullptr){

        list<ProductItem>::iterator item = find_if(_queryModel.begin(), _queryModel.end(), [&currentItemView](const ProductItem &other){

            // equals but not

            qDebug() << QString("Cmp: %1 = %2").arg(currentItemView->text()).arg(other.ToQString());
            qDebug() << QString("Current: %1").arg(QString::compare(currentItemView->text(), other.ToQString()));

            return QString::compare(currentItemView->text(), other.ToQString());
        });

        return *item;
    }
    else {

        return ProductItem();
    }
}

void Customer::RemoveSelectedFromQuery()
{
    int currentRow = _queryView->currentRow();

    if (currentRow != -1){

        qDebug() << QString("CR: %1").arg(currentRow);

        QListWidgetItem *itemView = _queryView->takeItem(currentRow);


        list<ProductItem>::iterator item = find_if(_queryModel.begin(), _queryModel.end(), [&itemView](const ProductItem &other){

            return QString::compare(itemView->text(), other.ToQString());
        });

        _queryModel.erase(item);

        delete itemView;

    }

}

void Customer::ClearQuery()
{
    _queryModel.clear();
    _queryView->clear();
}
