#ifndef BOOKING_H
#define BOOKING_H

#include "command.h"

class Booking : public Command
{
public:
    Booking(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db) override;
private:
    enum Days
    {
        CURRENT = 0,
        WEEK = 7,
        MONTH = 30
    };
    QString queryViewBooking(qint16 endView = 0);
    QString queryUpdateBooking();
    QString currentDate(quint16 days = 0);
    uint16_t room;
    uint16_t checkIn;
    uint16_t checkOut;
    uint16_t numOfPeople;
    uint idBooking;
};

#endif // BOOKING_H
