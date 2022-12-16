#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "command.h"

class Employee : public Command
{
public:
    Employee(QDataStream& stream);
    QString queryEmployee();
    QString queryWorkHotel();
    QByteArray execute(QSqlDatabase&db) override;
private:
    QString date;
    QString filter;
    QString id;
    QString fullname;
    QString phone;
    QString birth;
    QString position;
    QString passportSeries;
    QString passportNumber;
    QString idEmployee;
    QString description;
    QString whereWork;
};

#endif // EMPLOYEE_H
