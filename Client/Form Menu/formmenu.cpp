#include "formmenu.h"
#include "ui_formmenu.h"
#include <QtWidgets>
#include <iostream>
FormMenu::FormMenu(const QString &firstName, const QString &secondName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormMenu)
{
    this->setWindowTitle("Dashboard - Главное меню");
    ui->setupUi(this);
    //ui->username->setText(firstName + " " + secondName);
    lastClick = ui->mainMenu;
    createPages();
    fillList();
    addWidgetsInStack();

}

void FormMenu::showStatusConnection(bool ans, const QString &str)
{
    if(ans)
    {

    }
    else
    {

    }
}

std::list<QWidget *> &FormMenu::getListWidget()
{
    return list;
}

FormMainMenu *FormMenu::getMainMenu()
{
    return mainMenu;
}

FormBooking *FormMenu::getBooking()
{
    return booking;
}

FormEmployee *FormMenu::getEmployee()
{
    return employee;
}

FormRooms *FormMenu::getRooms()
{
    return rooms;
}

FormReport *FormMenu::getReport()
{
    return report;
}

FormSignUp *FormMenu::getSignUp()
{
    return signUp;
}

FormCheckIn *FormMenu::getCheckIn()
{
    return checkIn;
}

FormSettings *FormMenu::getSettings()
{
    return settings;
}

FormMenu::~FormMenu()
{
    delete ui;
    for(auto& form: list)
    {
        delete form;
        form = nullptr;
    }
}

void FormMenu::closeEvent(QCloseEvent *)
{
    emit signalClose();
}

void FormMenu::fillList()
{
    list.push_back(mainMenu);
    list.push_back(employee);
    list.push_back(rooms);
    list.push_back(checkIn);
    list.push_back(signUp);
    list.push_back(booking);
    list.push_back(report);
    list.push_back(settings);
}

void FormMenu::addStack(QWidget *w)
{
    ui->stackedWidget->addWidget(w);
}

void FormMenu::createPages()
{
    mainMenu = new FormMainMenu(this);
    employee = new FormEmployee(this);
    rooms = new FormRooms(this);
    checkIn = new FormCheckIn(this);
    signUp = new FormSignUp(this);
    booking = new FormBooking(this);
    connect(booking, &FormBooking::signalSignUp, this, [&](){
        ui->stackedWidget->setCurrentWidget(signUp);
        ui->booking->setChecked(false);
        ui->signUp->setChecked(true);
    });
    report = new FormReport(this);
    settings = new FormSettings(this);
}

void FormMenu::addWidgetsInStack()
{
    for(auto& form: list)
    {
        addStack(form);
    }
}

void FormMenu::on_logOut_clicked()
{
    qApp->exit();
}

void FormMenu::doNonChecked()
{
    lastClick->setChecked(false);
    QPushButton* nowClick = (QPushButton*)sender();
    nowClick->setChecked(true);
    lastClick = nowClick;
}

 void FormMenu::animateChange(QWidget *next)
 {
    QPropertyAnimation* anim1 = new QPropertyAnimation(ui->stackedWidget->currentWidget(), "geometry");
    anim1->setDuration(250);
    QRect r = ui->stackedWidget->currentWidget()->geometry();
    anim1->setStartValue(r);
    anim1->setEndValue(QRect(-r.width(), 0, r.width(), r.height()));
    anim1->setEasingCurve(QEasingCurve::Linear);
    ui->stackedWidget->setCurrentWidget(next);
    anim1->start(QAbstractAnimation::DeleteWhenStopped);
    QPropertyAnimation* anim2 = new QPropertyAnimation(next, "geometry");
    anim2->setDuration(250);
    anim2->setStartValue(QRect(-r.width(), 0, r.width(), r.height()));
    anim2->setEndValue(r);
    anim2->setEasingCurve(QEasingCurve::Linear);
    anim2->start(QAbstractAnimation::DeleteWhenStopped);
 }

 void FormMenu::animateNext(QWidget *next)
 {
     if(changePressed())
     {
         animateChange(next);
     }
 }

 bool FormMenu::changePressed()
 {
     if(lastClick == (QPushButton*)sender())
     {
         lastClick->setChecked(true);
         return false;
     }
     doNonChecked();
     return true;
 }

 void FormMenu::slotMainMenu(QDataStream &in)
 {
     mainMenu->slotGetData(in);
 }

 void FormMenu::slotBooking(QDataStream &in)
 {
     booking->getData(in);
 }

 void FormMenu::slotEmployee(QDataStream &in)
 {
     employee->slotGetData(in);
 }

 void FormMenu::slotRooms(QDataStream &in)
 {
     rooms->slotGetData(in);
 }

 void FormMenu::slotReport(QDataStream &in)
 {
     report->slotGetData(in);
 }

 void FormMenu::slotCheckIn(QDataStream &in)
 {
     checkIn->slotGetData(in);
 }

 void FormMenu::slotSignUp(QDataStream &in)
 {
     signUp->slotGetData(in);
 }

 void FormMenu::slotSettings(QDataStream &in)
 {
    settings->slotGetData(in);
 }

void FormMenu::on_mainMenu_clicked()
{
    this->setWindowTitle("Dashboard - Главное меню");
    animateNext(mainMenu);
}

void FormMenu::on_booking_clicked()
{
    this->setWindowTitle("Dashboard - Бронирование");
    animateNext(booking);
}

void FormMenu::on_employee_clicked()
{
    this->setWindowTitle("Dashboard - Сотрудники");
    animateNext(employee);
}

void FormMenu::on_rooms_clicked()
{
    this->setWindowTitle("Dashboard - Номера");
    animateNext(rooms);
}

void FormMenu::on_signUp_clicked()
{
    this->setWindowTitle("Dashboard - Регистрация");
    animateNext(signUp);
}

void FormMenu::on_checkIn_clicked()
{
    this->setWindowTitle("Dashboard - Заселение");
    animateNext(checkIn);
}

void FormMenu::on_report_clicked()
{
    this->setWindowTitle("Dashboard - Отчет");
    animateNext(report);
}

void FormMenu::on_settings_clicked()
{
    this->setWindowTitle("Dashboard - Настройки");
    animateNext(settings);
}

