#include "itemroom.h"
#include "ui_itemroom.h"

ItemRoom::ItemRoom(QString _id, QString statusCleaning, QString statusRoom, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemRoom)
{
    ui->setupUi(this);
    ui->room->setText("Номер № " + _id);
    ui->statusRoom->setText(statusRoom);
    if(statusCleaning != "Требуется уборка")
        ui->statusCleaning->setCurrentIndex(1);

}

ItemRoom::~ItemRoom()
{
    delete ui;
}
