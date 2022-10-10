#ifndef REPORT_H
#define REPORT_H

#include "command.h"

class Report : public Command
{
public:
    Report(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db) override;
};

#endif // REPORT_H
