#include "checkin.h"

CheckIn::CheckIn(QDataStream& stream)
{
    stream >> type;
    switch(type)
    {
    case Type::VIEW:
    {
            break;
    }
    case Type::SHOW_CHECK_IN:
    {
        stream >> this->id;
        break;
    }
    case Type::CHECK_OUT_FROM:
    {
        stream >> this->id;
    }
    case Type::PAY:
    {
        stream >> this->id >> this->days;
    }
    default:break;
    }
}

QByteArray CheckIn::execute(QSqlDatabase &db)
{
    init();
    *out << Form::CHECK_IN;
    switch(type)
    {
    case Type::VIEW:
    {
        QSqlQuery q("SELECT _id, status FROM showCheckIn()", db);
        *out << Type::VIEW << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        break;
    }
    case Type::SHOW_CHECK_IN:
    {
        QSqlQuery q(QString("SELECT fullname, phone FROM showPeople(%1);").arg(id), db);
        *out << Type::SHOW_CHECK_IN << id << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        break;
    }
    case Type::CHECK_OUT_FROM:
    {
        QSqlQuery q(QString("SELECT makeCheckOut(%1);").arg(id), db);
        *out << Type::CHECK_OUT_FROM << q.value(0).toString();
        break;
    }
    case Type::PAY:
    {
        QSqlQuery q(QString("SELECT payRoom(%1, %2)").arg(id, days), db);
        *out << Type::PAY << q.value(0).toString();
        break;
    }
    default:
        break;
    }


    return data;
}
