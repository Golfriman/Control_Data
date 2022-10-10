#include "authorization.h"

Authorization::Authorization(QDataStream &stream)
    :in(stream)
{
    stream >> login;
    stream >> password;
}

QString Authorization::createQuery()
{
    return QString("SELECT firstname, secondname FROM authorizationinsystem where login = \'%1\' and password = crypt('\%2\', password)").arg(login).arg(password);
}

QByteArray Authorization::execute(QSqlDatabase& db)
{
    init();
    QSqlQuery q(createQuery(), db);
    q.next();
    bool ans = (q.size() == 1);
    *out << Form::AUTHORIZATION << ans;
    if(ans)
    {
        *out << q.value(0).toString() << q.value(1).toString();
    }
    else
    {
        while(!in.atEnd())
        {
            in.skipRawData(1);
        }
    }
    return data;
}

Authorization::~Authorization()
{
    delete out;
}
