#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include <ostream>
#include <string>
#include <QTextStream>

using namespace std;

class ProductItem
{
private:

    char _name[30] = "not_set";
    int _count = 0;

public:

    ProductItem();
    ProductItem(const char *, int);
    friend QTextStream& operator<<(QTextStream&, const ProductItem&);
    friend ostream& operator<<(ostream&, const ProductItem&);
    string ToString() const;
};

#endif // PRODUCTITEM_H
