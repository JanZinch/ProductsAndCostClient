#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include <ostream>
#include <string>
#include <QTextStream>

using namespace std;

struct ProductItem
{
private:

    char _name[30] = "not_set";
    int _amount = 0;

public:

    ProductItem();
    ProductItem(const char *, int);
    const char* Name() const;
    const int Amount() const;
    bool operator ==(const ProductItem&);
    friend QTextStream& operator<<(QTextStream&, const ProductItem&);
    QString ToQString() const;
};

#endif // PRODUCTITEM_H
