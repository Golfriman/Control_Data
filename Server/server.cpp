#include "server.h"



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
    worker = new SqlWorker(db);
    thread = new QThread;

    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(thread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    worker->moveToThread(thread);
    thread->start();

    worker2 = new StateRoomWorker(db);
    thread2 = new QThread;
    connect(thread2, SIGNAL(started()), worker2, SLOT(process()));
    worker2->moveToThread(thread2);
    thread2->start();


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

void Server::incomingConnection(qintptr socketDescriptor)
{
    //Создается подключение клиента к серверу
    socket = new QTcpSocket;
    qDebug() << "Connection: " << socketDescriptor;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    sockets.push_back(socket);
}

void Server::slotReadyRead()
{
    //Информация от того кто отправил данные на сервер
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
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
            break;
        }
        data = command->execute(db);
        if (type == Send::ONE)
        {
            socket->write(data);
        }
        else if(type == Send::ALL)
        {
            for(auto& client: sockets)
            {
                client->write(data);
            }
        }
        delete command;
    }

}
