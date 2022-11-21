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
    void fillShowingDays(QSqlDatabase& db, uint8_t dur);
    QString room;
    QString checkIn;
    QString checkOut;
    QString phone;
    QString numOfPeople;
    int idVisitor;
    QString idBooking;
    QString fullname;
    QString filter;
    QString air;
    QString bath;
    QString array_services;
    QString array_nums;
    QString array_series;
    QString countDays;
};

#endif // BOOKING_H
