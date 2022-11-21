#include "rooms.h"

Rooms::Rooms(QDataStream& stream)
{
    stream >> type;
}

QString Rooms::createViewQuery()
{
    return QString("SELECT * FROM showRooms() ORDER BY _ID");
}

QByteArray Rooms::execute(QSqlDatabase &db)
{
    init();
    *out << Form::ROOMS;

    QSqlQuery qView(createViewQuery(), db);
    *out << qView.size();
    while(qView.next())
    {
        *out << qView.value(0).toString() << qView.value(1).toString() << qView.value(2).toString();
    }

    return data;
}
