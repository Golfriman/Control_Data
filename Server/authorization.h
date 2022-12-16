#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "command.h"
#include "qtcpsocket.h"
class Authorization: public Command
{
private:
    QString login;
    QString password;
    QDataStream& in;
    QString who;
public:
    Authorization(QDataStream& stream, Send who, std::list<QTcpSocket*>& admins, std::list<QTcpSocket*>& maid, QTcpSocket *socket);
    QString createQuery();
    QByteArray execute(QSqlDatabase& db)override;
    ~Authorization();
};

#endif // AUTHORIZATION_H
