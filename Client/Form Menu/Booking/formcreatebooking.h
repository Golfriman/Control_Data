#ifndef FORMCREATEBOOKING_H
#define FORMCREATEBOOKING_H

#include "calendar.h"
#include <QCalendarWidget>
#include <QtWidgets>
#include <set>

namespace Ui {
class FormCreateBooking;
}

class FormCreateBooking : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateBooking(std::vector<std::pair<QString, QString>>& services, QWidget *parent = nullptr);
    ~FormCreateBooking();
public slots:
    void slotGetFindResult(QDataStream& in);
    void slotGetFindRoomResult(QDataStream& in);
private:
    void createCalendar();
    void findRooms();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void slotCheckIn(QDate&d);
    void slotCheckOut(QDate&d);
    void on_pushButton_clicked();
    void slotClickServices(int index);
    void on_phone_textChanged(const QString &arg1);

    void on_filterView_currentIndexChanged(int index);

    void on_bathroom_stateChanged(int arg1);

    void on_aircond_stateChanged(int arg1);
    void slotSelectTypeRoom();
    void on_numPeople_currentIndexChanged(int index);

signals:
    void signalSignUp();
    void signalCreateBooking(const QByteArray&);
private:
    Ui::FormCreateBooking *ui;
    QScopedPointer<Calendar> calendar;
    QString dataCheckIn;
    QString dataCheckOut;
    QString filter;
    QString bath;
    QString air;
    QString phone;
    QString fullname;
    std::map<QString, int> prices;
    std::map<QString, int> priceService;
    std::map<QString, QString> idRooms;
    QString categories;
    std::set<QString> selectedServices;
};

#endif // FORMCREATEBOOKING_H
