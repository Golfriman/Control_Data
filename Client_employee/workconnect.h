#ifndef WORKERCONNECT_H
#define WORKERCONNECT_H

#include <QObject>
#include <QTcpSocket>

class WorkerConnect : public QObject
{
    Q_OBJECT
public:
    explicit WorkerConnect(QString address, quint16 port, QTcpSocket* socket, QObject *parent = nullptr);
public slots:
    void process();
signals:
    void signalFinished();
private:
    QString address;
    quint16 port;
    QTcpSocket* socket;

};

#endif // WORKERCONNECT_H
