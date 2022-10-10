#ifndef ITEMBOOKING_H
#define ITEMBOOKING_H

#include <QWidget>

namespace Ui {
class ItemBooking;
}

class ItemBooking : public QWidget
{
    Q_OBJECT

public:
    explicit ItemBooking(QString& id, QString& FIO, QWidget *parent = nullptr);
    ~ItemBooking();

private:
    Ui::ItemBooking *ui;
};

#endif // ITEMBOOKING_H
