#include "command.h"
#include <QIODevice>

void Command::init()
{
    data.clear();
    out = new QDataStream(&data, QIODevice::WriteOnly);
    out->setVersion(QDataStream::Qt_6_2);
    if(out->status()!=QDataStream::Ok)
    {
        qDebug() << out->status();
    }
}

Command::Command()
{

}
