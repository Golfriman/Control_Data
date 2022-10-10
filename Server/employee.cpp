#include "employee.h"

Employee::Employee(QDataStream& stream)
{

}

QString Employee::queryAllEmployee()
{
    return QString("SELECT fullname, positioninthehotel from employee LIMIT 10");
}

QString Employee::queryWorkHotel()
{
    return QString("SELECT namework, time from workhotel");
}

QByteArray Employee::execute(QSqlDatabase &db)
{
    init();
    QSqlQuery q(queryAllEmployee(), db);
    *out << Form::EMPLOYEE << q.size();
    while(q.next())
    {
        *out << q.value(0).toString() << q.value(1).toString();
    }

    QSqlQuery q2(queryWorkHotel(), db);
    qDebug() << q2.size();
    *out << q2.size();
    while(q2.next())
    {
        *out << q2.value(0).toString() << q2.value(1).toString();
    }

    return data;
}
