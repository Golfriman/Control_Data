#ifndef CHECKIN_H
#define CHECKIN_H

#include "command.h"

class CheckIn : public Command
{
public:
    CheckIn(int command);
    CheckIn(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db) override;
private:
    QString fullname;
    QString series;
    QString number;
    QString id;
    QString days;
    QString services;
    QString empl;

};

#endif // CHECKIN_H
