#include "formchangecleanningroom.h"
#include "ui_formchangecleanningroom.h"
#include "../const.h"

FormChangeCleanningRoom::FormChangeCleanningRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChangeCleanningRoom)
{
    ui->setupUi(this);
    for(int i =1; i <= 26; i++)
        ui->rooms->addItem(QString::number(i));
}

FormChangeCleanningRoom::~FormChangeCleanningRoom()
{
    delete ui;
}

void FormChangeCleanningRoom::on_pushButton_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    out << Form::ROOMS << Send::ADMINS << Type::CHANGE_CLEAN <<ui->rooms->currentText() << ui->comboBox->currentText();
    emit signalSendToServer(data);
}

