#include "checkin.h"

CheckIn::CheckIn(QDataStream& stream)
{

}

QByteArray CheckIn::execute(QSqlDatabase &db)
{
    init();
    *out << Form::CHECK_IN;
    return data;
}
