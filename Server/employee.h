#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "command.h"

class Employee : public Command
{
public:
    Employee(QDataStream& stream);
    QString queryAllEmployee();
    QString queryWorkHotel();
    QByteArray execute(QSqlDatabase&db) override;
};

#endif // EMPLOYEE_H
