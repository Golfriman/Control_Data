#ifndef SIGNUP_H
#define SIGNUP_H

#include "command.h"

class SignUp : public Command
{
public:
    SignUp(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db) override;
private:
    QString fullname;
    QString passportSeries;
    QString passportNumber;
    QString phone;
    int type;
};

#endif // SIGNUP_H
