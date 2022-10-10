#include "itembooking.h"
#include "ui_itembooking.h"

ItemBooking::ItemBooking(QString& id, QString& FIO, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemBooking)
{
    ui->setupUi(this);
    ui->idBooking->setText(id);
    ui->FIO->setText(FIO);
}

ItemBooking::~ItemBooking()
{
    delete ui;
}
