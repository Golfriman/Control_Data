#include "server.h"
#include "qdatetime.h"
#include <QCoreApplication>


/*Придумать как отправить отправить вместе с данными о авторизации и также инициализация данных*/

Server::Server()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("8246");
    if(this->listen(QHostAddress::Any, 25600) && db.open())
    {
        qDebug() << "start";
    }
    else
    {
        qDebug("The Server is starting or the database isn't opening.");
    }
    worker = QSharedPointer<SqlWorker>(new SqlWorker(db), &QObject::deleteLater);
    thread = QSharedPointer<QThread>(new QThread, &QObject::deleteLater);

    connect(thread.get(), SIGNAL(started()), worker.get(), SLOT(process()));
    connect(thread.get(), SIGNAL(finished()), worker.get(), SLOT(deleteLater()));
    worker->moveToThread(thread.get());
    thread->start();
    timer = QSharedPointer<QTimer>(new QTimer(), &QObject::deleteLater);
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(slotChangeStatusRoom()));
    timer.get()->start(1);
}

Server::~Server()
{
}

Command *Server::createConcreteCommand(int idCommand, QDataStream &in)
{
    switch(idCommand)
    {
    case Form::AUTHORIZATION:    return new Authorization(in);
    case Form::MAIN_MENU:        return new MainMenu(in);
    case Form::EMPLOYEE:         return new Employee(in);
    case Form::BOOKING:          return new Booking(in);
    case Form::ROOMS:            return new Rooms(in);
    case Form::SIGN_UP:          return new SignUp(in);
    case Form::CHECK_IN:         return new CheckIn(in);
    case Form::REPORT:           return new Report(in);
    case Form::SETTINGS:         return new Settings(in);
    default:                     return nullptr;
    }
}

void Server::slotChangeStatusRoom()
{
    QSqlQuery updateStatus("CALL changeStatusRooms();");
                            //HH * minute * sec * msec
    timer.get()->start(24*60*60*1000);
}

void Server::slotDisconnectClient()
{
    auto itm = (QTcpSocket*)sender();
    const auto it = std::find_if(sockets.begin(), sockets.end(), [&itm](QTcpSocket* value)
    {
        return value == itm;
    });
    sockets.erase(it);
    delete itm;
    itm = nullptr;

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //Создается подключение клиента к серверу
    QTcpSocket* socket = new QTcpSocket;
    qDebug() << "Connection: " << socketDescriptor;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(socket, SIGNAL(disconnected()), this, SLOT(slotDisconnectClient()));
    sockets.push_back(std::move(socket));
}

void Server::slotReadyRead()
{
    //Информация от того кто отправил данные на сервер
    QTcpSocket* socket_client = (QTcpSocket*)sender();
    QDataStream in(socket_client);
    in.setVersion(QDataStream::Qt_6_2);
    while(!in.atEnd())
    {
        Command* command;
        int idCommand, type;
        in >> idCommand >> type;
        qDebug() << "ID COMMAND: " << idCommand;
        command = createConcreteCommand(idCommand, in);
        if(command == nullptr)
        {
            continue;
        }
        data.clear();
        data = command->execute(db);
        if (type == Send::ONE)
        {
            socket_client->write(data);
        }
        else if(type == Send::ALL)
        {
            socket_client->write(data);//Информация о том, что операция выполненна...

            data.clear();
            QByteArray data2;
            QDataStream request(&data2, QIODevice::ReadWrite);
            request << Type::VIEW;
            Command* command2 = createConcreteCommand(idCommand, request);
            data = command2->execute(db);
            for(auto& client: sockets)
            {
                client->write(data/*Обновленные данные*/);
            }
            delete command2;
        }
        delete command;
    }

}
