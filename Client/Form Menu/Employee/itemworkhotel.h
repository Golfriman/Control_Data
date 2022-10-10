#ifndef ITEMWORKHOTEL_H
#define ITEMWORKHOTEL_H

#include <QWidget>

namespace Ui {
class ItemWorkHotel;
}

class ItemWorkHotel : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWorkHotel(QString& time, QString& namework, QWidget *parent = nullptr);
    ~ItemWorkHotel();

private:
    Ui::ItemWorkHotel *ui;
};

#endif // ITEMWORKHOTEL_H
