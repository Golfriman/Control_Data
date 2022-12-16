#include "itemroom.h"
#include "ui_itemroom.h"

ItemRoom::ItemRoom(QString _id, QString statusCleaning, QString statusRoom, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemRoom)
{
    ui->setupUi(this);
    ui->room->setText("Номер № " + _id);
    ui->statusRoom->setText(statusRoom);
    ui->statusCleanning->setText(statusCleaning);
    if(statusCleaning == "Требуется уборка")
        ui->statusCleanning->setText(QString("<font color=\"red\">%1</font>").arg(statusCleaning));

}

ItemRoom::~ItemRoom()
{
    delete ui;
}
