#include "itememployee.h"
#include "ui_itememployee.h"

ItemEmployee::ItemEmployee(QString &pos, QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEmployee)
{
    ui->setupUi(this);
    ui->position->setText(pos);
    ui->name->setText(name);
}

ItemEmployee::~ItemEmployee()
{
    delete ui;
}
