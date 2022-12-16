#include "report.h"

Report::Report(QDataStream& stream)
{
    stream >> type;
}

QByteArray Report::execute(QSqlDatabase &db)
{
    init();
    *out << Form::REPORT;
    switch(type)
    {
        case Type::VIEW:
        QString strQuery = QString("SELECT * FROM showreportCheckin();");
        QSqlQuery q(strQuery, db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString();
        }
        QString strQuery2 = QString("SELECT * FROM showWorkInHotel(CURRENT_DATE);");
        QSqlQuery q2(strQuery2, db);
        *out << q2.size();
        while(q2.next())
        {
            *out << q2.value(0).toString() << q2.value(1).toString() << q2.value(2).toString();
        }
        break;
    }

    return data;
}
