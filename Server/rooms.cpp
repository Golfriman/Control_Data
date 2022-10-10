#include "rooms.h"

Rooms::Rooms(QDataStream& stream)
{

}

QString Rooms::createViewQuery()
{
    return QString("SELECT category, status, viewfromthewindow, CASE "
                                                                "WHEN EXISTS(SELECT * FROM booking NATURAL JOIN room"
                                                                    "WHERE current_date() BETWEEN booking.checkin AND booking.checkoutfrom"
                                                                        "THEN \'Занято\'"
                                                                "ELSE \'Свободно\'"
                    "FROM room");
}

QByteArray Rooms::execute(QSqlDatabase &db)
{
    init();
    *out << Form::ROOMS;

    QSqlQuery qView(createViewQuery(), db);
    *out << qView.size();
    while(qView.next())
    {
        *out << qView.value(0).toString() << qView.value(1).toString() << qView.value(2).toString() << qView.value(3).toString();
    }

    return data;
}
