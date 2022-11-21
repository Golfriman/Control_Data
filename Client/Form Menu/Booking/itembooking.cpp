#include "itembooking.h"
#include "qcheckbox.h"
#include <QScopedPointer>
#include "ui_itembooking.h"

ItemBooking::ItemBooking(std::vector<QString> &v, const std::vector<std::pair<QString, QString>> &services, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemBooking)
{
    ui->setupUi(this);
    setWindowTitle("Подробная информация о бронировании");
    setWindowModality(Qt::ApplicationModal);

    filterBath = "null";
    filterAir = "null";
    filterView = "%";
    ui->checkBox->setCheckState(Qt::PartiallyChecked);
    ui->checkBox_2->setCheckState(Qt::PartiallyChecked);
    this->id = v[0];
    this->FIO = v[3];
    this->idV = v[2];
    this->idRoom = v[1];
    this->checkIn = v[4];
    this->checkOut = v[5];
    this->nums = v[6];
    this->phone = v[7];
    for(int i = 8; i < v.size(); i++)
    {
        selectingServices.emplace(v[i]);
    }
    ui->name->setText("Бронирование №" + id);
    ui->FIO->setText("<strong>" + FIO + "</strong>");
    ui->phone->setText("Тел: <strong>" + phone + "</strong>" );
    ui->room->setText("Номер: <strong>" + idRoom + "</strong>");
    ui->checkInData->setText(checkIn);
    ui->checkOutData->setText(checkOut);
    ui->numsData->setCurrentText(nums);
    auto layout = ui->scrollAreaWidgetContents->layout();
    layout->setAlignment(Qt::AlignTop);
    for(const auto& i: services)
    {
        auto chBox = new QCheckBox(i.first);
        if(selectingServices.find(i.first) != selectingServices.end()) chBox->setCheckState(Qt::Checked);
        layout->addWidget(chBox);
        connect(chBox, &QCheckBox::stateChanged, this, [&](auto state){
            auto send = (QCheckBox*)sender();
            auto key = send->text();
            auto it = selectingServices.find(key);
            switch(state)
            {
            case Qt::Unchecked:
                if(it!=selectingServices.end())
                    selectingServices.erase(it);
                break;
            case Qt::Checked:
                if(it == selectingServices.end())
                    selectingServices.emplace(key);
                break;
            }
        });
    }

    if(checkIn != QDate::currentDate().toString("yyyy-MM-dd"))
        ui->accept->setEnabled(false);

}

ItemBooking::~ItemBooking()
{
    delete ui;
}

void ItemBooking::slotGetRooms(QDataStream &in)
{
    QLayoutItem* itm;
    while((itm = ui->scrollAreaWidgetContents->layout()->takeAt(0))!= nullptr)
    {
        delete itm->widget();
        delete itm;
    }
    int size;
    in >> size;
    for(int i = 0; i < size; i++)
    {
        int price;
        QString category;
        in >> category >> price;
        if(prices.find(category) == prices.end()) prices.emplace(category, price);
        ui->scrollAreaWidgetContents->layout()->addWidget(new QRadioButton(category));
    }
}

void ItemBooking::on_pushButton_2_clicked()
{
    calendar.reset(new Calendar());
    calendar->setGridVisible(true);
    connect(calendar.get(), SIGNAL(signalCheckIn(QDate&)), this, SLOT(slotCheckIn(QDate&)));
    connect(calendar.get(), SIGNAL(signalCheckOut(QDate&)), this, SLOT(slotCheckOut(QDate&)));
    connect(calendar.get(), SIGNAL(finished()), calendar.get(), SLOT(deleteLater()));
    calendar->show();
}

void ItemBooking::slotCheckIn(QDate &d)
{
    ui->checkInData->setText(d.toString("yyyy-MM-dd"));
    ui->checkOutData->clear();
}

void ItemBooking::slotCheckOut(QDate &d)
{
    ui->checkOutData->setText(d.toString("yyyy-MM-dd"));
}


void ItemBooking::on_pushButton_clicked()
{
}


void ItemBooking::on_delete_2_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ALL << Type::DROP << id;
    emit signalBooking(data);
    this->hide();
}


void ItemBooking::on_update_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    out << Send::ALL << Type::UPDATE <<
           id << idV << idRoom << checkIn << checkOut << nums;
    QString _data;
    for(const auto& i: selectingServices)
        _data += i + '|';
    _data.push_front('(');
    _data[_data.size()-1] = ')';
    qDebug() << _data;
    out << _data;
    emit signalBooking(data);
    this->hide();
}


void ItemBooking::on_accept_clicked()
{
    accept.reset(new acceptBooking(id, nums.toInt()));
    connect(accept.get(), SIGNAL(signalLiving(const QByteArray&)), this, SLOT(slotPrepareSend(const QByteArray&)));
    connect(accept.get(), SIGNAL(closeMe()), this, SLOT(deleteLater()));
    accept.get()->show();
}


void ItemBooking::on_checkBox_stateChanged(int arg1)
{
    switch(arg1)
    {
      case Qt::PartiallyChecked:
        filterBath = "null";
        break;
    case Qt::Checked:
        filterBath = "true";
        break;
    case Qt::Unchecked:
        filterBath = "false";
    }
    findRoom();
}

void ItemBooking::findRoom()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ONE << Type::FIND_ROOM <<ui->comboBox->currentText() <<  filterView << filterBath << filterAir << ui->checkInData->text() << ui->checkOutData->text();
    emit signalBooking(data);
}


void ItemBooking::on_checkBox_2_stateChanged(int arg1)
{
    switch(arg1)
    {
      case Qt::PartiallyChecked:
        filterAir = "null";
        break;
    case Qt::Checked:
        filterAir = "true";
        break;
    case Qt::Unchecked:
        filterAir = "false";
    }
    findRoom();
}


void ItemBooking::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 0)
        filterView = "%";
    else filterView = ui->comboBox_2->currentText();
    findRoom();
}

void ItemBooking::slotPrepareSend(const QByteArray &data)
{
    emit signalBooking(data);
}

