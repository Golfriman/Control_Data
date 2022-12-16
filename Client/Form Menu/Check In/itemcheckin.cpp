#include "itemcheckin.h"
#include "ui_itemcheckin.h"
#include "service.h"

ItemCheckIn::ItemCheckIn(QString idEmployee, QDataStream &in, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ItemCheckIn)
{
    this->idEmployee = idEmployee;
    ui->setupUi(this);
    in >> idRoom;
    ui->room->setText(ui->room->text() + idRoom);
    in >> checkin >> checkout >> number;

    ui->l_checkin->setText("Дата заселения: " + checkin);
    ui->l_checkout->setText("Дата выселения: " + checkout);
    ui->number->setText("Дней оплачено: " + number);
    in >> id;
    int size;
    in >> size;
    ui->label->setText(ui->label->text() + id);
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(int i = 0; i < size; i++)
    {
        QString fullname;
        QString phone;
        in >> fullname >> phone;

        layout->addWidget(new QLabel(fullname + "\t" + phone));
    }

    auto layout2 = ui->scrollAreaWidgetContents_2->layout();
    layout2->setAlignment(Qt::AlignTop);
    in >> size;
    for(int i = 0; i < size; i++)
    {
        QString type;
        QString count;
        in >> type >> count;
        layout2->addWidget(new QLabel(type + "  x" + count));
    }
}

void ItemCheckIn::getConstant(QDataStream &in)
{
    window->slotGetData(in);
}

ItemCheckIn::~ItemCheckIn()
{
    delete ui;
}


void ItemCheckIn::on_pushButton_3_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ADMINS << Type::CHECK_OUT_FROM << id;
    emit sendToServer(data);

}


void ItemCheckIn::on_pushButton_2_clicked()
{
    if(ui->numberOfPaid->text().isEmpty())
        return;
    if(!ui->numberOfPaid->text().toInt())
    {
        QMessageBox::about(this, "Продление заселения", "Указаны не числовые значения");
    }
    else if (ui->numberOfPaid->text().toInt() < 0)
    {
        QMessageBox::about(this, "Продления заселения", "Отрицательные значения запрещены!");
    }
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ADMINS << Type::PAY << idEmployee<< id << ui->numberOfPaid->text();
    emit sendToServer(data);
}


void ItemCheckIn::on_pushButton_clicked()
{
    window.reset(new Service(id, idEmployee));
    connect(window.get(), SIGNAL(signalSendToServer(const QByteArray&)), this, SLOT(slotPrepareSend(const QByteArray&)));
    window->show();
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    out << Send::ONE << Type::CONSTANT;
    emit sendToServer(data);

}

void ItemCheckIn::slotPrepareSend(const QByteArray &out)
{
    this->hide();
    emit sendToServer(out);
}

