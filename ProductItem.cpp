#include "ProductItem.h"

ProductItem::ProductItem() = default;

ProductItem::ProductItem(const char *name, int count)
{
    strcpy_s(this->_name, name);
    this->_amount = count;
}

const char *ProductItem::Name() const
{
    return _name;
}

const int ProductItem::Amount() const
{
    return _amount;
}

bool ProductItem::operator==(const ProductItem &other){

    return strcmp(this->Name(), other.Name()) == 0;
}

QTextStream& operator<<(QTextStream& out, const ProductItem &productItem) {

    return out <<
        "Name: " << productItem._name <<
            "  Count: " << productItem._amount;
}

QString ProductItem::ToQString() const
{
    QString result;
    QTextStream textStream(&result);
    textStream << *this;

    return result;
}

bool ProductItem::IsDefault() const
{
    return strcmp(_name, NOT_SET) == 0;
}

