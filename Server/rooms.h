#ifndef ROOMS_H
#define ROOMS_H

#include "command.h"

class Rooms : public Command
{
public:
    Rooms(QDataStream& stream);
    QString createViewQuery();
    QByteArray execute(QSqlDatabase& db) override;
private:
    QString status;
    QString idRoom;
};

#endif // ROOMS_H
