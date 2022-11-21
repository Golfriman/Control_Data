#include "signup.h"

SignUp::SignUp(QDataStream& stream)
{
}

QByteArray SignUp::execute(QSqlDatabase &db)
{
    init();
    *out << Form::SIGN_UP;
    return data;
}
