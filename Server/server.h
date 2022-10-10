#ifndef SERVER_H
#define SERVER_H
#include "authorization.h"
#include "checkin.h"
#include "mainmenu.h"
#include "report.h"
#include "settings.h"
#include "signup.h"
#include "booking.h"
#include "employee.h"
#include "rooms.h"
#include "checkin.h"
#include <QThread>
#include "stateroomworker.h"
#include "sqlworker.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <set>
class Server:public QTcpServer
{
    Q_OBJECT
public:
    Server();
    ~Server();
private:
    Command* createConcreteCommand(int idCommand, QDataStream& in);
private:
    QSqlDatabase db;
    QTcpSocket* socket;
    std::vector<QTcpSocket*>sockets;
    QByteArray data;

    SqlWorker* worker;
    QThread* thread;

    StateRoomWorker* worker2;
    QThread* thread2;
public slots:
    void incomingConnection(qintptr socketDescriptor)override;
    void slotReadyRead();
};

#endif // SERVER_H
