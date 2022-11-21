#include "formcreatebooking.h"
#include "ui_formcreatebooking.h"
#include "../const.h"
#include "phonevalidator.h"
#include <iostream>
FormCreateBooking::FormCreateBooking(std::vector<std::pair<QString, QString> > &services, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateBooking)
{
    ui->setupUi(this);
    price = 0;
    setWindowTitle("Создание брони");
    setWindowModality(Qt::ApplicationModal);
    auto validate = new PhoneValidator;
    ui->phone->setValidator(validate);

    air = "null";
    bath = "null";
    ui->aircond->setCheckState(Qt::PartiallyChecked);
    ui->bathroom->setCheckState(Qt::PartiallyChecked);
    filter = "%";
    ui->scrollServices->setLayout(new QVBoxLayout);
    for(const auto& i: services)
    {
        auto itm = new QCheckBox(i.first);
        connect(itm, SIGNAL(stateChanged(int)), this, SLOT(slotClickServices(int)));
        ui->scrollServices->layout()->addWidget(itm);
    }
    for(auto& i: services)
    {
        priceService.emplace(i.first, i.second.toInt());
    }

}

FormCreateBooking::~FormCreateBooking()
{
    delete ui;
}

void FormCreateBooking::slotGetFindResult(QDataStream &in)
{
    in >> phone >> fullname;
    ui->resultSearch->setText("Результат поиска: <strong>" + fullname + "\t" + phone + "</strong>");
}

void FormCreateBooking::slotGetFindRoomResult(QDataStream &in)
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
        QString idRoom;
        in >> category >> price >> idRoom;
        if(prices.find(category) == prices.end())
        {
            prices.emplace(category, price);
            idRooms.emplace(category, idRoom);
        }
        auto itm = new QRadioButton(category);
        connect(itm, SIGNAL(clicked()), this, SLOT(slotSelectTypeRoom()));
        ui->scrollAreaWidgetContents->layout()->addWidget(itm);
    }
}

void FormCreateBooking::createCalendar()
{
    calendar.reset(new Calendar());
    calendar->setGridVisible(true);
    connect(calendar.get(), SIGNAL(signalCheckIn(QDate&)), this, SLOT(slotCheckIn(QDate&)));
    connect(calendar.get(), SIGNAL(signalCheckOut(QDate&)), this, SLOT(slotCheckOut(QDate&)));
    connect(calendar.get(), SIGNAL(finished()), calendar.get(), SLOT(deleteLater()));
}

void FormCreateBooking::findRooms()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << Send::ONE << Type::FIND_ROOM << ui->numPeople->currentText() << filter << bath << air << dataCheckIn << dataCheckOut;
    emit signalCreateBooking(data);
}

void FormCreateBooking::on_pushButton_2_clicked()
{
    QByteArray data;
    auto checkLineEdit = [](QLineEdit& edit)->bool
    {
      if(edit.text().isEmpty())
      {
          edit.setStyleSheet("border-color:red;");
          return true;
      }
      return false;
    };
    if(checkLineEdit(*ui->phone) || checkLineEdit(*ui->checkIn) || checkLineEdit(*ui->checkOut))
    {
     return;
    }
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    auto text = [](QLineEdit* edit)->QString
    {
      return edit->text();
    };
    QString services = "(";
    for(auto& i: this->selectedServices)
    {
        services += i + "|";
    }
    services[services.size()-1] = ')';
    if(services.size()==1)
        services = "()";
    out << Send::ALL << Type::INSERT << idRooms[categories] << fullname << phone << text(ui->checkIn) << text(ui->checkOut)<< ui->numPeople->currentText() << services;/*Информация о дате и тому подобное...*/
    emit signalCreateBooking(data);
    deleteLater();
}


void FormCreateBooking::on_pushButton_3_clicked()
{
    deleteLater();
}


void FormCreateBooking::on_pushButton_4_clicked()
{
    createCalendar();
    calendar->show();
}

void FormCreateBooking::slotCheckIn(QDate &d)
{
    ui->checkIn->setText(d.toString("yyyy-MM-dd"));
    dataCheckIn = ui->checkIn->text();
    ui->checkOut->clear();
    intCheckIn = d.toJulianDay();
}

void FormCreateBooking::slotCheckOut(QDate &d)
{
    ui->checkOut->setText(d.toString("yyyy-MM-dd"));
    dataCheckOut = ui->checkOut->text();
    findRooms();
    intCheckout = d.toJulianDay();
}


void FormCreateBooking::on_pushButton_clicked()
{
    emit signalSignUp();
}

void FormCreateBooking::slotClickServices(int index)
{
    auto itm = (QCheckBox*)sender();
    switch(index)
    {
    case Qt::Checked:
        selectedServices.emplace(itm->text());
        price += priceService[itm->text()];
        break;
    case Qt::Unchecked:
        if(selectedServices.find(itm->text())!=selectedServices.end()) selectedServices.erase(itm->text());
        price -= priceService[itm->text()];
        break;
    }
    ui->price->setText(QString::number(price));
    //std::cout << itm->text().toStdString() << std::endl;
}

void FormCreateBooking::on_phone_textChanged(const QString &arg1)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out << Send::ONE <<Type::FIND << arg1;
    emit signalCreateBooking(data);
}


void FormCreateBooking::on_filterView_currentIndexChanged(int index)
{
    (void)index;
    if(ui->checkIn->text().isEmpty() || ui->checkOut->text().isEmpty())
        return;
    findRooms();
}


void FormCreateBooking::on_bathroom_stateChanged(int arg1)
{
    if(ui->checkIn->text().isEmpty() || ui->checkOut->text().isEmpty())
        return;
    switch(arg1)
    {
    case Qt::Unchecked:
        bath = "false";
        break;
    case Qt::PartiallyChecked:
        bath = "null";
        break;
    case Qt::Checked:
        bath = "true";
        break;
    }
    findRooms();
}


void FormCreateBooking::on_aircond_stateChanged(int arg1)
{
    if(ui->checkIn->text().isEmpty() || ui->checkOut->text().isEmpty())
        return;
    switch(arg1)
    {
    case Qt::Unchecked:
        air = "false";
        break;
    case Qt::PartiallyChecked:
        air = "null";
        break;
    case Qt::Checked:
        air = "true";
        break;
    }
    findRooms();
}

void FormCreateBooking::slotSelectTypeRoom()
{
    auto itm = (QRadioButton*)sender();
    categories = itm->text();
    ui->label_3->setText("Номер " + idRooms[categories]);
/*ТУТА*/

    price += prices[categories]* (intCheckout - intCheckIn);
    ui->price->setText(QString::number(price));
}


void FormCreateBooking::on_numPeople_currentIndexChanged(int index)
{
    (void)index;
    findRooms();
}

