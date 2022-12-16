#ifndef FORMMENU_H
#define FORMMENU_H

#include "qpushbutton.h"
#include <QMainWindow>
#include "Main Menu/formmainmenu.h"
#include "Employee/formemployee.h"
#include "Rooms/formrooms.h"
#include "Booking/formbooking.h"
#include "Check In/formcheckin.h"
#include "Sign Up/formsignup.h"
#include "Report/formreport.h"
#include "Settings/formsettings.h"
#include <list>

namespace Ui {
class FormMenu;
}

class FormMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormMenu(const QString& idEmployee, const QString &fullname, QWidget *parent = nullptr);
    void showStatusConnection(bool ans, const QString& str = "");
    std::list<QWidget*> &getListWidget();
    FormMainMenu *getMainMenu();
    FormBooking *getBooking();
    FormEmployee *getEmployee();
    FormRooms *getRooms();
    FormReport *getReport();
    FormSignUp *getSignUp();
    FormCheckIn* getCheckIn();
    FormSettings* getSettings();
    ~FormMenu();
protected:
    virtual void closeEvent(QCloseEvent*)override;
private:
    void fillList();
    void addStack(QWidget* w);
    void createPages();
    void addWidgetsInStack();
    void doNonChecked();
    void animateChange(QWidget* next);
    void animateNext(QWidget* next);
    bool changePressed();
public slots:
    void slotMainMenu(QDataStream&);
    void slotBooking(QDataStream&);
    void slotEmployee(QDataStream&);
    void slotRooms(QDataStream&);
    void slotReport(QDataStream&);
    void slotCheckIn(QDataStream&);
    void slotSignUp(QDataStream&);
    void slotSettings(QDataStream&);
private slots:
    void on_logOut_clicked();
    void on_mainMenu_clicked();
    void on_booking_clicked();
    void on_employee_clicked();
    void on_rooms_clicked();
    void on_signUp_clicked();
    void on_checkIn_clicked();
    void on_report_clicked();
    void on_settings_clicked();

signals:
    void signalInitWidgets();
    void signalClose();
private:
    Ui::FormMenu *ui;
    FormMainMenu* mainMenu;
    FormEmployee* employee;
    FormRooms* rooms;
    FormCheckIn* checkIn;
    FormBooking* booking;
    FormSignUp* signUp;
    FormReport* report;
    FormSettings* settings;
    QString idEmployee;
    QString fullname;

    QPushButton* lastClick;
    QByteArray data;

    std::list<QWidget*> list;
};

#endif // FORMMENU_H
