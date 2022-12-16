#include "checkin.h"
#include <iostream>

CheckIn::CheckIn(int command)
{
    type = command;
}

CheckIn::CheckIn(QDataStream& stream)
{
    stream >> type;
    switch(type)
    {
    case Type::VIEW:    break;
    case Type::SHOW_CHECK_IN:
    {
        stream >> this->id;
        break;
    }
    case Type::CHECK_OUT_FROM:
    {
        stream >> this->id;
        break;
    }
    case Type::PAY:
    {
        stream >> this->empl >> this->id >> this->days;
        break;
    }
    case Type::ARCHIVE:
    {
        stream >> fullname >> series >> number;
        break;
    }
    case Type::CONSTANT:break;
    case Type::ADD:
    {
        stream >>id >> services>>empl;
        break;
    }
    default:break;
    }
}

QByteArray CheckIn::execute(QSqlDatabase &db)
{
    init();
    *out << Form::CHECK_IN << type;
    switch(type)
    {
    case Type::VIEW:
    {
        QSqlQuery q("SELECT _id, status FROM showCheckIn()", db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        break;
    }
    case Type::SHOW_CHECK_IN:
    {
        QString str = QString("SELECT * FROM show_checkin(%1);").arg(id);
        QSqlQuery q0(str, db);
        q0.next();
        *out << q0.value(0).toString() << q0.value(1).toString() << q0.value(2).toString() << q0.value(3).toString();

        QSqlQuery q(QString("SELECT fullname, phone FROM showPeople(%1);").arg(id), db);
        *out << id << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        QSqlQuery q2(QString("SELECT * FROM showServices(%1);").arg(id), db);
        *out << q2.size();
        while(q2.next())
        {
            *out << q2.value(0).toString() << q2.value(1).toString();
        }
        break;
    }
    case Type::CHECK_OUT_FROM:
    {
        QString strQuery = QString("SELECT makeCheckOut(%1);").arg(id);
        std::cout << strQuery.toStdString();
        QSqlQuery q(strQuery, db);
        q.next();
        *out << q.value(0).toString();
        break;
    }
    case Type::PAY:
    {
        QSqlQuery q(QString("SELECT payRoom(%1, %2, %3)").arg(id, empl, days), db);
        q.next();
        *out  << q.value(0).toString();
        break;
    }
    case Type::ARCHIVE:
    {
        QString strQuery = QString("SELECT * FROM findVisitor(\'%1\', \'%2\', \'%3\')").arg(fullname, series, number);
        QSqlQuery q(strQuery, db);
        *out << q.size();
        std::cout << strQuery.toStdString();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString() << q.value(2).toString() << q.value(3).toString();
        }
        break;

    }
    case Type::CONSTANT:
    {
        QString strQuery = QString("SELECT typeservice, price FROM service;");
        QSqlQuery q(strQuery, db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        break;
    }
    case Type::ADD:
    {
        QString strQuery = QString("SELECT ADDSERVICES(%1, %2, \'%3\');").arg(id, services, empl);
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
