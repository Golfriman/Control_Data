#ifndef COMMAND_H
#define COMMAND_H

#include<QDataStream>
#include<QString>
#include<QSqlQuery>
#include<QSqlDatabase>
#include "../const.h"
class Command
{
protected:
    QByteArray data;
    QDataStream* out;
    int type;
    void init();
public:
    Command();
    virtual QByteArray execute(QSqlDatabase&)=0;
    virtual ~Command() = default;
};

#endif // COMMAND_H
