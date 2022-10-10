#ifndef FORMCREATEBOOKING_H
#define FORMCREATEBOOKING_H

#include "calendar.h"
#include <QCalendarWidget>
#include <QWidget>

namespace Ui {
class FormCreateBooking;
}

class FormCreateBooking : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateBooking(QWidget *parent = nullptr);
    ~FormCreateBooking();
private:
    void createCalendar();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void slotCheckIn(QDate&d);
    void slotCheckOut(QDate&d);
    void on_pushButton_clicked();
signals:
    void signalSignUp();
    void signalCreateBooking(const QByteArray&);
private:
    Ui::FormCreateBooking *ui;
    Calendar* calendar;
};

#endif // FORMCREATEBOOKING_H
