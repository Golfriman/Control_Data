#ifndef CLIENT_H
#define CLIENT_H
#include <QMainWindow>
#include <QTcpSocket>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QNetworkProxy>
#include "Form Menu/formmenu.h"
#include "Form Authorization/formauthorization.h"
#include <thread>
#include "../const.h"
#include "workerconnect.h"


class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString address, uint16_t port, QWidget *parent = nullptr);
    ~Client();
private:
    void createSocket(QString address, uint16_t port);
    void createFormAuthorization();
    void connectSocketToAuthorization();
    void connectAuthorizationToSocket();
    void setFocusWindow(QMainWindow* w);
    void createFormMenu(const QString& firstName, const QString& secondName);
    void createTrayMenu();
    void createTrayIcon();
    void connectSocketToFormMenuWidgets();
    void connectFormMenuWidgetsToSocket();
    void createSignal(int id, QDataStream& in);
    void createLogoutAction();
    void removeLogoutAction();
    void createWorker();
signals:
    void signalAuthorization(QDataStream&);
    void signalMainMenu(QDataStream&);
    void signalEmployee(QDataStream&);
    void signalRooms(QDataStream&);
    void signalCheckIn(QDataStream&);
    void signalBooking(QDataStream&);
    void signalSignUp(QDataStream&);
    void signalReport(QDataStream&);
    void signalSettings(QDataStream&);
    void signalExit(QDataStream&);

    void signalFormAuthorization(bool, const QString&);
    void signalFormMenu(bool, const QString&);

public slots:
    void slotReadyRead();
    void slotSendToServer(QByteArray&);
    void slotLogin(const QString&, const QString&);
    void slotShowHide();
    void slotActionShowHide();
    void slotQuit();
    void slotIconActivated(QSystemTrayIcon::ActivationReason reason);
    void slotLogoutSystem();
private slots:
    void disconnectToServer();
    void connectToServer();
private:
    QThread* t;
    WorkerConnect* worker;

    QSystemTrayIcon* trayIcon;
    QMenu* trayMenu;

    QString address;
    uint16_t port;
    QTcpSocket* socket;

    QMainWindow* window;
    FormMenu* menu;
    FormAuthorization *authorization;

    QIcon* icon;

    QAction* exitAction;
    QAction* logoutAction;
    QAction* showAction;
    QAction* hideAction;
};
#endif // CLIENT_H
