#include "ProductItem.h"

ProductItem::ProductItem() = default;

ProductItem::ProductItem(const char *name, int count)
{
    strcpy_s(this->_name, name);
    this->_count = count;
}

string ProductItem::ToString() const
{

    return string("Name: ") + string(_name) + string("  Count: ") + to_string(_count);
}

QTextStream& operator<<(QTextStream& out, const ProductItem &productItem) {

    return out <<
        "Name: " << productItem._name <<
            "  Count: " << productItem._count;
}

ostream& operator<<(ostream& out, const ProductItem &productItem) {

    return out <<
        "Name: " << productItem._name <<
            "  Count: " << productItem._count;
}

