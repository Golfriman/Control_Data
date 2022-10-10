#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include "command.h"
class Authorization: public Command
{
private:
    QString login;
    QString password;
    QDataStream& in;
public:
    Authorization(QDataStream& stream);
    QString createQuery();
    QByteArray execute(QSqlDatabase& db)override;
    ~Authorization();
};

#endif // AUTHORIZATION_H
