#include "workconnect.h"
#include <QThread>

WorkerConnect::WorkerConnect(QString address, quint16 port, QTcpSocket *socket, QObject *parent)
    : QObject(parent),
      address(address),
      port(port),
      socket(socket)
{

}

void WorkerConnect::process()
{
    while(!socket->waitForConnected())
    {
        socket->connectToHost(address, port);
        QThread::sleep(1);

    }
    emit signalFinished();
}
