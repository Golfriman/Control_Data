#ifndef ITEMBOOKING_H
#define ITEMBOOKING_H

#include <QWidget>
#include "Form Menu/Booking/acceptbooking.h"
#include "calendar.h"
#include <set>
#include "../../const.h"
namespace Ui {
class ItemBooking;
}

class ItemBooking : public QWidget
{
    Q_OBJECT
public:
    explicit ItemBooking(QString& idEmployee, std::vector<QString>& v, const std::vector<std::pair<QString, QString>>& services, QWidget *parent = nullptr);
    ~ItemBooking();
public slots:
    void slotGetRooms(QDataStream& in);

private slots:
    void on_pushButton_2_clicked();
    void slotCheckIn(QDate&);
    void slotCheckOut(QDate&);
    void on_pushButton_clicked();

    void on_delete_2_clicked();

    void on_update_clicked();

    void on_accept_clicked();
    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void slotPrepareSend(const QByteArray&);

signals:
    void signalBooking(const QByteArray&);
    void signalBookingRoom(const QByteArray&);
private:
    Ui::ItemBooking *ui;
    void findRoom();
    std::set<QString> selectingServices;
    QScopedPointer<QWidget> changeTypeRoom;
    QString id;
    QString idV;
    QString FIO;
    QString idRoom;
    QString checkIn;
    QString checkOut;
    QString nums;
    QString phone;
    QScopedPointer<Calendar> calendar;
    QScopedPointer<acceptBooking> accept;
    QString filterBath;
    QString filterAir;
    QString filterView;
    std::map<QString, int> prices;
    QString idEmployee;
};

#endif // ITEMBOOKING_H
