#include "itemroom.h"
#include "ui_itemroom.h"

ItemRoom::ItemRoom(QString _id, QString category, QString statusCleaning, QString statusRoom, QString price, QString size, QString cap, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemRoom)
{
    ui->setupUi(this);
    ui->room->setText("Номер № " + _id);
    ui->statusRoom->setText(statusRoom);
    ui->statusCleaning->setText(statusCleaning);
    ui->category->setText(category + ":");
    ui->label->setText(price + " руб");
    ui->size->setText("Размер: " + size + "м<sup><small>2</small></sup>");
    ui->cap->setText("Макс. человек: " + cap);
    if(statusCleaning == "Требуется уборка")
        ui->statusCleaning->setText(QString("<font color=\"red\">%1</font>").arg(statusCleaning));

}

ItemRoom::~ItemRoom()
{
    delete ui;
}
