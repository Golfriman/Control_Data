#include "itemworkhotel.h"
#include "ui_itemworkhotel.h"

ItemWorkHotel::ItemWorkHotel(QString &time, QString &namework, QString &room, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWorkHotel)
{
    ui->setupUi(this);
    ui->time->setText(time);
    ui->namework->setText(namework);
    ui->room->setText(room);
}

ItemWorkHotel::~ItemWorkHotel()
{
    delete ui;
}
