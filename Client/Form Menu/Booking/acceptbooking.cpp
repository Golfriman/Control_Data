#include "acceptbooking.h"
#include "ui_acceptbooking.h"
#include "../const.h"

acceptBooking::acceptBooking(QString id, int num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::acceptBooking)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    for(int i = 0; i < num; i++)
    {
        hor.push_back(new QGroupBox("Посетитель " + QString::number(i+1)));
        gHor.push_back(new QHBoxLayout());
        vert.push_back(new QVBoxLayout());
        vert.back()->addWidget(new QLabel("ФИО"));
        fullname.emplace(i, new QLineEdit);
        vert.back()->addWidget(fullname[i].get());
        gHor[i]->addLayout(vert[4*i]);

        vert.push_back(new QVBoxLayout());
        vert.back()->addWidget(new QLabel("Серия Паспорта"));
        seriesPass.emplace(i, new QLineEdit);
        vert.back()->addWidget(seriesPass[i].get());
        gHor[i]->addLayout(vert[4*i+1]);

        vert.push_back(new QVBoxLayout());
        vert.back()->addWidget(new QLabel("Номер Паспорта"));
        numberPass.emplace(i, new QLineEdit);
        vert.back()->addWidget(numberPass[i].get());
        gHor[i]->addLayout(vert[4*i+2]);

        vert.push_back(new QVBoxLayout());
        vert.back()->addWidget(new QLabel("Телефон"));
        phone.emplace(i, new QLineEdit);
        vert.back()->addWidget(phone[i].get());
        gHor[i]->addLayout(vert[4*i+3]);

        hor[i]->setLayout(gHor[i]);
        ui->layout->addWidget(hor[i]);
    }
    this->id = id;

}

acceptBooking::~acceptBooking()
{
    delete ui;
}

void acceptBooking::on_pushButton_clicked()
{
    qDebug() << "LIVING";
    QString arrayFIO = "'{";
    QString arrayPassSeries= "'{";
    QString arrayPassNumber= "'{";
    QString arrayPhone= "'{";

    for(auto& i: fullname)
        arrayFIO +='"' + i.second->text() + '"' + ',';
    arrayFIO[arrayFIO.size()-1] = '}';

    for(auto& i: seriesPass)
        arrayPassSeries += i.second->text() + ",";
    arrayPassSeries[arrayPassSeries.size()-1] = '}';
    arrayPassSeries+="'";

    for(auto& i: numberPass)
        arrayPassNumber += i.second->text() + ",";
    arrayPassNumber[arrayPassNumber.size()-1] = '}';
    arrayPassNumber+="'";


    for(auto& i: phone)
        arrayPhone += '"' + i.second->text() + '"' + ',';
    arrayPhone[arrayPhone.size()-1] = '}';
    arrayPhone += "'";
    qDebug() << arrayFIO;
    qDebug() << arrayPassSeries;
    qDebug() << arrayPassNumber;
    qDebug() << arrayPhone;
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out <<  Send::ALL << Type::ACCEPT << id << ui->countDays->text() << arrayFIO << arrayPassSeries << arrayPassNumber << arrayPhone;
    emit this->signalLiving(data);
    emit closeMe();
    deleteLater();

}

