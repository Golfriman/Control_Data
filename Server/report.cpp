#include "report.h"

Report::Report(QDataStream& stream)
{

}

QByteArray Report::execute(QSqlDatabase &db)
{
    init();
    *out << Form::REPORT;
    return data;
}
