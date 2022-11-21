#include "itemcheckin.h"
#include "ui_itemcheckin.h"
#include "service.h"

ItemCheckIn::ItemCheckIn(QDataStream &in, QWidget *parent)
{
    in >> id;
    int size;
    in >> size;
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(int i = 0; i < size; i++)
    {
        QString fullname;
        QString phone;
        layout->addWidget(new QLabel(fullname + "\t" + phone));
    }
}

ItemCheckIn::~ItemCheckIn()
{
    delete ui;
}


void ItemCheckIn::on_pushButton_3_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ALL << Type::CHECK_OUT_FROM << id;

}


void ItemCheckIn::on_pushButton_2_clicked()
{
    if(ui->numberOfPaid->text().isEmpty())
        return;
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ALL << Type::PAY << id << ui->numberOfPaid->text();
}

