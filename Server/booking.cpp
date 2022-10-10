#include "booking.h"
#include <QDate>

Booking::Booking(QDataStream& stream)
{
}

QString Booking::queryViewBooking(qint16 endView)
{
    return QString ("SELECT booking.idbooking, visitor.fullname FROM BOOKING, visitor where booking.idvisitor = visitor.idvisitor;");
            //QString("SELECT* from booking where between checkin " + currentDate() + " and " + currentDate(endView));
}

QString Booking::queryUpdateBooking()
{
    return QString("UPDATE booking SET idroom = 1%,"
                   "checkin = 2%,"
                   "checkoutfrom = 3%,"
                   "numofpeople = 4%"
                   "where idBooking = 5%")
                    .arg(room)
                    .arg(currentDate(checkIn))
                    .arg(currentDate(checkOut))
                    .arg(numOfPeople)
                    .arg(idBooking);
}



QByteArray Booking::execute(QSqlDatabase &db)
{
    init();

    *out << Form::BOOKING;
    QSqlQuery todayBooking("SELECT booking.idbooking, visitor.fullname FROM BOOKING, visitor where booking.idvisitor = visitor.idvisitor ORDER BY booking.idbooking;", db);
    auto fillStream = [&](QSqlQuery& q)
    {
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
    };
    fillStream(todayBooking);
    return data;
}

QString Booking::currentDate(quint16 days)
{
    return "\'" + QDate::currentDate().addDays(days).toString("yyyy-MM-dd") + "\'";
}
