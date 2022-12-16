#include "authorization.h"

Authorization::Authorization(QDataStream &stream, Send who, std::list<QTcpSocket *> &admins, std::list<QTcpSocket *> &maid, QTcpSocket* socket)
    :in(stream)
{
    stream >> login;
    stream >> password;
    if(who == Send::ADMIN)
    {
        this->who = "Администратор";
        if(std::find(admins.begin(), admins.end(), socket) == admins.end())
            admins.push_back(socket);

    }
    else {
        this->who = "Горничная";
        if(std::find(maid.begin(), maid.end(), socket) == maid.end())
            maid.push_back(socket);
    }

}

QString Authorization::createQuery()
{
    return QString("SELECT * FROM logining(\'%1\', \'%2\', \'%3\');").arg(login, password, who);
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
        *out << q.value(0).toString() << q.value(1).toBool() <<q.value(2).toString();
        if(!q.value(1).toBool())
        {
            while(!in.atEnd())
            {
                in.skipRawData(1);
            }
        }
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
}
