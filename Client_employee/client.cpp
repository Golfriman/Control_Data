#include "client.h"
#include "qcoreapplication.h"
#include "qthread.h"
#include "QMessageBox"

Client::Client(QString address, uint16_t port, QWidget *parent)
    : QObject(parent), t(nullptr), address(address), port(port)
{
    createFormAuthorization();
    createSocket(address, port);
    if(!socket->waitForConnected())
    {
        authorization->showStatusConnection(false, socket->errorString());
    }
    setFocusWindow(authorization);
    createTrayMenu();
    createTrayIcon();
    createWorker();
}

Client::~Client()
{
    delete socket;
    delete authorization;
    delete menu;
    delete trayIcon;
    delete trayMenu;
}

void Client::createSocket(QString address, uint16_t port)
{
    socket = new QTcpSocket(this);
    socket->setProxy(QNetworkProxy::NoProxy);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnectToServer()));
    connect(socket, SIGNAL(connected()), this, SLOT(connectToServer()));
    socket->connectToHost(address, port);
}

void Client::createFormAuthorization()
{
    authorization  = new FormAuthorization;
    connectSocketToAuthorization();
    connectAuthorizationToSocket();
    authorization->setWindowTitle("Dashboard - Авторизация");
}

void Client::connectSocketToAuthorization()
{
    connect(this, SIGNAL(signalAuthorization(QDataStream&)), authorization, SLOT(update(QDataStream&)));
}

void Client::connectAuthorizationToSocket()
{
    connect(authorization, SIGNAL(request(QByteArray&)), this, SLOT(slotSendToServer(QByteArray&)));
    connect(authorization, SIGNAL(login(const QString&, const QString&)), this, SLOT(slotLogin(const QString&, const QString&)));
}

void Client::setFocusWindow(QMainWindow *w)
{
    w->show();
    window = w;
}

void Client::createFormMenu(const QString &idEmployee, const QString& fullname)
{
    menu = new FormWork(idEmployee, fullname);
    menu->setWindowTitle(fullname);
    connectSocketToFormMenuWidgets();
    connectFormMenuWidgetsToSocket();
    createLogoutAction();
    //connect(menu, SIGNAL(signalClose()), this, SLOT(slotActionShowHide()));
}

void Client::createTrayMenu()
{
    trayMenu = new QMenu;
    showAction = new QAction("Открыть", window);
    connect(showAction, SIGNAL(triggered()), this, SLOT(slotShowHide()));
    hideAction = new QAction("Скрыть", window);
    connect(hideAction, SIGNAL(triggered()), this, SLOT(slotShowHide()));
    logoutAction = new QAction("Сменить пользователя");
    connect(logoutAction, SIGNAL(triggered()), this, SLOT(slotLogoutSystem()));
    exitAction = new QAction("Выйти", window);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(slotQuit()));
    trayMenu->addAction(showAction);
    trayMenu->addAction(hideAction);
    trayMenu->addAction(logoutAction);
    trayMenu->addAction(exitAction);

    showAction->setVisible(false);
    logoutAction->setVisible(false);
}

void Client::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon;
    trayIcon->setToolTip("Dashboard");
    trayIcon->setContextMenu(trayMenu);
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
    trayIcon->setIcon(QPixmap(":/icon/logo.svg"));
    trayIcon->show();
}

void Client::connectSocketToFormMenuWidgets()
{
    connect(this, SIGNAL(signalRooms(QDataStream&)),    menu, SLOT(slotGetData(QDataStream&)));
}

void Client::connectFormMenuWidgetsToSocket()
{
    connect(menu, SIGNAL(signalSendToServer(QByteArray&)), this, SLOT(slotSendToServer(QByteArray&)));
}



void Client::createSignal(int id, QDataStream &in)
{
    switch(id)
    {
    case Form::AUTHORIZATION: emit signalAuthorization(in);   break;
    case Form::ROOMS:         emit signalRooms(in);           break;
    case Form::EMPLOYEE:
    {
        int type;
        QString result;
        in >>type >> result;
        qDebug() << type;
        QMessageBox::about(menu, "Результат", result);
        break;
    }
    default: break;
    }
}

void Client::createLogoutAction()
{
    logoutAction->setVisible(true);
}

void Client::removeLogoutAction()
{
    logoutAction->setVisible(false);
}

void Client::createWorker()
{
    worker = new WorkerConnect(address, port, socket);
    t = new QThread;
    connect(t, SIGNAL(started()), worker, SLOT(process()), Qt::UniqueConnection);
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    worker->moveToThread(t);
}

void Client::slotReadyRead()
{

    QDataStream in(socket);
    while(!in.atEnd())
    {
        int id;
        in >> id;
        createSignal(id, in);
    }
}

void Client::slotSendToServer(QByteArray& out)
{
    socket->write(out);
}

void Client::slotLogin(const QString& idEmployee, const QString &fullname)
{
    authorization->hide();
    createFormMenu(idEmployee, fullname);
    setFocusWindow(menu);
}

void Client::slotShowHide()
{
    window->setVisible(!window->isVisible());
    showAction->setVisible(!showAction->isVisible());
    hideAction->setVisible(!hideAction->isVisible());
}

void Client::slotActionShowHide()
{
    hideAction->setVisible(false);
    showAction->setVisible(true);
}

void Client::slotQuit()
{
    qApp->exit();
}

void Client::slotIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        window->show();
        break;
    default:
        break;
    }
}

void Client::slotLogoutSystem()
{
    if(menu)
    {
        delete menu;
        setFocusWindow(authorization);
        removeLogoutAction();
    }
}

void Client::disconnectToServer()
{
    if(window == authorization)
    {
        authorization->showStatusConnection(false, socket->errorString());
    }
    /*else if(window == menu)
    {
        menu->showStatusConnection(false, socket->errorString());
    }*/
    t->start();
}

void Client::connectToServer()
{
    if(window == authorization)
    {
        authorization->showStatusConnection(true);
    }
    /*else if(window == menu)
    {
        menu->showStatusConnection(true);
    }*/
}
