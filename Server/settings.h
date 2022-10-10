#ifndef SETTINGS_H
#define SETTINGS_H

#include "command.h"

class Settings : public Command
{
public:
    Settings(QDataStream& in);
    QByteArray execute(QSqlDatabase& db)override;
};

#endif // SETTINGS_H
