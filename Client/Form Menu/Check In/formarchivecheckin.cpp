#include "formarchivecheckin.h"
#include "ui_formarchivecheckin.h"
#include "../const.h"

FormArchiveCheckIn::FormArchiveCheckIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormArchiveCheckIn)
{
    ui->setupUi(this);
}

FormArchiveCheckIn::~FormArchiveCheckIn()
{
    delete ui;
}

void FormArchiveCheckIn::slotGetData(QDataStream &in)
{
    list.clear();
    int size;
    in >> size;
    for(int i = 0; i < size; i++)
    {
        QString fio, room, checkin, checkout;
        in >> fio >> room >> checkin >> checkout;
        list << QString("ФИО: %1 Номер: %2, Дата засления: %3, Выезд: %4").arg(fio, room, checkin, checkout);
    }
    model.setStringList(list);
    ui->list_visitor->setModel(&model);
}

void FormArchiveCheckIn::on_pushButton_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    out << Send::ONE << Type::ARCHIVE << ui->fullname->text() +"%" << ui->series->text() + "%" << ui->number->text() + "%";
    emit signalArchive(data);
}

