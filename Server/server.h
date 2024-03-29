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
#include "sqlworker.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <set>
#include <QDateTime>
#include <QSharedPointer>
#include <QTimer>
class Server:public QTcpServer
{
    Q_OBJECT
public:
    Server();
    ~Server();
private:
    Command* createConcreteCommand(int idCommand, QDataStream& in, QTcpSocket *socket);
private:
    Send type;
    QSqlDatabase db;
    std::list<QTcpSocket*>unknown;
    std::list<QTcpSocket*>admins;
    std::list<QTcpSocket*>maid;
    QByteArray data;

    QSharedPointer<SqlWorker> worker;
    QSharedPointer<QThread> thread;

    QDateTime now{QDateTime::currentDateTime()};
    QSharedPointer<QTimer> timer;
private slots:
    void slotChangeStatusRoom();
    void slotDisconnectClient();
    void createMainMenuCommand();
public slots:
    void incomingConnection(qintptr socketDescriptor)override;
    void slotReadyRead();
};

#endif // SERVER_H
