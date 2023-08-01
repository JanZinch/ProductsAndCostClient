#ifndef QMONEY_H
#define QMONEY_H

#include "Money.h"

#include <QString>
#include <QTextStream>

namespace MoneyLogic
{
    class QMoney : public MoneyLogic::Money
    {
    public:

        QMoney();
        friend QTextStream& operator<<(QTextStream&, const QMoney&);
        QString ToQString() const;
    };
}

#endif // QMONEY_H
