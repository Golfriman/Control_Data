#ifndef CHECKIN_H
#define CHECKIN_H

#include "command.h"

class CheckIn : public Command
{
public:
    CheckIn(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db) override;
private:
    QString id;
    QString days;

};

#endif // CHECKIN_H
