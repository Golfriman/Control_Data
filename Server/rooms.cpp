#include "rooms.h"

Rooms::Rooms(QDataStream& stream)
{
    stream >> type;
    switch(type)
    {
    case Type::VIEW: break;
    case Type::FILTER_ROOMS:
        stream >> status;
        break;
    case Type::CHANGE_CLEAN:
        stream >> idRoom >> status;
        break;
    }
}

QString Rooms::createViewQuery()
{
    return QString("SELECT * FROM showRooms() ORDER BY _ID");
}

QByteArray Rooms::execute(QSqlDatabase &db)
{
    init();
    *out << Form::ROOMS << type;
    switch(type)
    {
    case Type::VIEW:
    {
        QSqlQuery qView(createViewQuery(), db);
        *out << qView.size();
        while(qView.next())
        {
            *out << qView.value(0).toString() << qView.value(1).toString() << qView.value(2).toString() << qView.value(3).toString() << qView.value(4).toString()<< qView.value(5).toString()<< qView.value(6).toString();
        }
        break;
    }
    case Type::FILTER_ROOMS:
    {

        QSqlQuery qView(QString("SELECT * FROM showRooms() WHERE _statusRoom LIKE \'%1\' ORDER BY _ID ").arg(status), db);
        *out << qView.size();
        while(qView.next())
        {
            *out << qView.value(0).toString() << qView.value(1).toString() << qView.value(2).toString() << qView.value(3).toString() << qView.value(4).toString()<< qView.value(5).toString()<< qView.value(6).toString();
        }
        break;
    }
    case Type::CHANGE_CLEAN:
    {
        QString strQuery = QString("SELECT changeCleanStatus(%1, \'%2\');").arg(idRoom, status);
        QSqlQuery q(strQuery, db);
        q.next();
        *out << q.value(0).toString();
        break;
    }
    }



    return data;
}
