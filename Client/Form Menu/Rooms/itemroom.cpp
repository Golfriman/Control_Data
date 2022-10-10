#include "itemroom.h"
#include "ui_itemroom.h"

ItemRoom::ItemRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemRoom)
{
    ui->setupUi(this);
}

ItemRoom::~ItemRoom()
{
    delete ui;
}
