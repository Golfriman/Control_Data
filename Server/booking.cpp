#include "booking.h"
#include <QDate>
#include <iostream>

Booking::Booking(QDataStream& stream)
{
    stream >> type;
    switch(type)
    {
    case Type::VIEW:
        break;
    case Type::UPDATE:
        stream >> idBooking >> idVisitor >> room >> checkIn >> checkOut >> numOfPeople;
        break;
    case Type::INSERT:
        stream >> room >> fullname >> phone >> checkIn >> checkOut >> numOfPeople >> array_services;
        break;
    case Type::DROP:
        stream >> idBooking;
        break;
    case Type::FIND:
        stream >> phone;
    case Type::CONSTANT:
        break;
    case Type::FIND_ROOM:
        stream >>numOfPeople>> filter >> bath >> air >> checkIn >> checkOut;
    default:
        break;
    }
}


QByteArray Booking::execute(QSqlDatabase &db)
{
    init();
    *out << Form::BOOKING;
    auto writeResult = [&](QSqlQuery& q)
    {
        q.next();
        *out << q.value(0).toString();
    };
    switch(type)
    {
    case Type::VIEW:
    {
        *out << Type::VIEW;
        fillShowingDays(db, CURRENT);
        fillShowingDays(db, WEEK);
        fillShowingDays(db, MONTH);
        break;
    }
    case Type::UPDATE:
    {
        *out << Type::UPDATE;
        QString strQuery = QString("SELECT updateBooking(%1, %2, \'%3\', \'%4\', %5);").
                arg(idBooking,
                    room,
                    checkIn,
                    checkOut,
                    numOfPeople);
        QSqlQuery q(strQuery, db);
        writeResult(q);
        break;
    }
    case Type::INSERT:
    {
        *out << Type::INSERT;
        QString strQuery = QString("SELECT insertBooking(%1, \'%2\', \'%3\', \'%4\', \'%5\', %6, \'%7\')").arg(room,fullname,phone,checkIn,checkOut,numOfPeople, array_services);
        QSqlQuery q(strQuery, db);
        std::cout << strQuery.toStdString() << std::endl;
        writeResult(q);
        break;
    }
    case Type::DROP:
    {
        *out << Type::DROP;
        QString strQuery = QString("SELECT deleteBooking(%1);").arg(idBooking);
        std::cout << strQuery.toStdString() << std::endl;
        QSqlQuery q(strQuery, db);
        writeResult(q);
        break;
    }
    case Type::FIND:
    {
        *out << Type::FIND;
        QString strQuery = QString("SELECT phone, fullname FROM findVisitor(\'%1\');").arg(phone);
        QSqlQuery q(strQuery, db);
        q.next();
        *out << q.value(0).toString() << q.value(1).toString();
        break;
    }
    case Type::CONSTANT:
    {
        *out << Type::CONSTANT;
        QString strQuery = QString("SELECT typeservice, price FROM service;");
        QSqlQuery q(strQuery, db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        break;
    }
    case Type::FIND_ROOM:
        *out << Type::FIND_ROOM;
        QString strQuery = QString("SELECT * FROM showTypeRoom(\'%1\', %2, %3, \'%4\', \'%5\', %6)").arg(filter, bath, air, checkIn, checkOut, numOfPeople);
        QSqlQuery q(strQuery, db);
        *out << q.size();
        std::cout << strQuery.toStdString() << std::endl;
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toInt() << q.value(2).toString();
        }
        break;
    }
    return data;
}

void Booking::fillShowingDays(QSqlDatabase &db, uint8_t dur)
{
    QString strQuery = QString("SELECT ID_BOOKING,\
                                       ID_ROOM,\
                                       ID_VISITOR,\
                                       FULLNAME,\
                                       CHECK_IN,\
                                       CHECK_OUT,\
                                       NUM_OF_PEOPLE,\
                                       _phone FROM showBooking(%1)").arg(QString::number(dur));

    QSqlQuery q(strQuery, db);
    *out << q.size();
    while(q.next())
    {
        *out << q.value(0).toString() //ID booking
             << q.value(1).toString() //ID room
             << q.value(2).toString() //ID visitor
             << q.value(3).toString() //Fullname
             << q.value(4).toString() //Check in
             << q.value(5).toString() //Check out
             << q.value(6).toString() //Num of people
             << q.value(7).toString();//Phone Visitor
       QString str2 = QString("SELECT typeService FROM findServiceBooking(%1)").arg(q.value(0).toString());
       QSqlQuery q2(str2, db);
       *out << q2.size();
       while(q2.next()) *out << q2.value(0).toString();
    }
}
