#include "signup.h"
#include <iostream>

SignUp::SignUp(QDataStream& stream)
{
    stream >> type >> fullname >> passportSeries >> passportNumber >> phone;
}

QByteArray SignUp::execute(QSqlDatabase &db)
{
    init();
    *out << Form::SIGN_UP;
    switch(type)
    {
    case Type::INSERT:
    {
        QString strQuery = QString("SELECT addVisitor(\'%1\', %2, %3, \'%4\')").arg(fullname, passportSeries, passportNumber, phone);
        std::cout << strQuery.toStdString();
        QSqlQuery q(strQuery, db);
        q.next();
        *out << q.value(0).toString();
        break;
    }
    default:
        break;
    }

    return data;
}
