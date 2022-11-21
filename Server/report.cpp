#include "report.h"

Report::Report(QDataStream& stream)
{
    stream >> type;
}

QByteArray Report::execute(QSqlDatabase &db)
{
    init();
    *out << Form::REPORT;
    return data;
}
