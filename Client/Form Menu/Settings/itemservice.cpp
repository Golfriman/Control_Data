#include "itemservice.h"
#include "ui_itemservice.h"

ItemService::ItemService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemService)
{
    ui->setupUi(this);
}

ItemService::~ItemService()
{
    delete ui;
}
