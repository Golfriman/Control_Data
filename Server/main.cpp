#include <QCoreApplication>
#include "server.h"
#include <QFile>
#include <QDateTime>

void messageToFile(QtMsgType                 type,
                   const QMessageLogContext& context,
                   const QString&            msg);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInstallMessageHandler(messageToFile);
    Server s;
    return a.exec();
}


void messageToFile(QtMsgType                 type,
                   const QMessageLogContext& context,
                   const QString&            msg)
{
    (void)type;
    QFile file("protocol.log");
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QString strDateTime = QDateTime::currentDateTime().toString("dd.MM.yy-hh:mm");

    QTextStream out(&file);
    out << strDateTime  << " " << msg << ", " << context.file << '\n';

}
