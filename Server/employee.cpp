 #include "employee.h"
#include <iostream>

Employee::Employee(QDataStream& stream)
{
    stream >> type;
    switch(type)
    {
    case Type::VIEW:
        break;
    case Type::FIND_EMPLOYEE:
        stream >> filter;
        break;
    case Type::FIND_WORK:
        stream >> date;
        break;
    case Type::DROP:
        stream >> id;
        break;
    case Type::FIND_EMPLOYEE_FULLNAME:
        stream >>filter >> id;
        break;
    case Type::INSERT:
        stream >> fullname >> phone >> birth >> position;
        break;
    case Type::COMPLETE_WORK:
        stream >> idEmployee >> description >> whereWork;
        break;
    }

}

QString Employee::queryEmployee()
{
    return QString("SELECT * FROM showEmployee(\'%1\');").arg(filter);
}

QString Employee::queryWorkHotel()
{
    return QString("SELECT * FROM showWorkInHotel(\'%1\');").arg(date);
}

QByteArray Employee::execute(QSqlDatabase &db)
{
    init();
    *out << Form::EMPLOYEE << type;
    switch(type)
    {
    case Type::VIEW:
    {
        filter = "%";
        date = "current_date";
        QSqlQuery q(queryEmployee(), db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString() << q.value(2).toString();
        }
        QSqlQuery q2(queryWorkHotel(), db);
        qDebug() << q2.size();
        *out << q2.size();
        while(q2.next())
        {
            *out << q2.value(0).toString() << q2.value(1).toString() << q2.value(2).toString();
        }
        break;
    }
    case Type::FIND_WORK:
    {
        QSqlQuery q(queryWorkHotel(), db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString() << q.value(2).toString();
        }
        break;
    }
    case Type::FIND_EMPLOYEE:
    {
        QSqlQuery q(queryEmployee(), db);
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString() << q.value(2).toString();
        }
        break;
    }
    case Type::FIND_EMPLOYEE_FULLNAME:
    {
        QString strQuery = QString("SELECT * FROM showEmployee_fullname( %1, \'" +filter+ "\');").arg(id);
        QSqlQuery q(strQuery, db);
        std::cout << strQuery.toStdString();
        *out << q.size();
        while(q.next())
        {
            *out << q.value(0).toString() << q.value(1).toString() << q.value(2).toString() << q.value(3).toString();
        }
        break;
    }
    case Type::DROP:
    {
        QSqlQuery q(QString("SELECT hireEmployee(%1);").arg(id), db);
        q.next();
        *out << q.value(0).toString();
        break;
    }
    case Type::INSERT:
    {
        QString strQuery = QString("SELECT * FROM addEmployee(\'%1\', \'%2\', \'%3\', \'%4\')").arg(fullname, phone, birth, position);
        QSqlQuery q(strQuery, db);
        q.next();
        *out << q.value(0).toString();
        break;
    }
    case Type::COMPLETE_WORK:
    {
        QString strQuery = QString("SELECT * FROM completeWork(%1, \'%2\', %3);").arg(idEmployee, description, whereWork);
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
