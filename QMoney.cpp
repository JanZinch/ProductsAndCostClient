#include "QMoney.h"

namespace MoneyLogic
{
    QMoney::QMoney() : Money(){}

    QTextStream& operator<<(QTextStream& out, const QMoney &moneyObject) {

        return out << moneyObject._count << " " << moneyObject._currency;
    }

    QString QMoney::ToQString() const
    {
        QString result;
        QTextStream textStream(&result);
        textStream << *this;

        return result;

    }

}

