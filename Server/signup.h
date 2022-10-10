#ifndef SIGNUP_H
#define SIGNUP_H

#include "command.h"

class SignUp : public Command
{
public:
    SignUp(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db) override;
};

#endif // SIGNUP_H
