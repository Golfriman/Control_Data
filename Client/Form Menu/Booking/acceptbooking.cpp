#include "acceptbooking.h"
#include "ui_acceptbooking.h"
#include "../const.h"

acceptBooking::acceptBooking(QString idEmployee, QString id, int num, QWidget *parent) :
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
    this->idEmployee = idEmployee;

}

acceptBooking::~acceptBooking()
{
    delete ui;
}

void acceptBooking::on_pushButton_clicked()
{
    if(!ui->countDays->text().toInt())
    {
        QMessageBox::about(this, "Заселение", "Не указано количество оплаченных дней");
        return;
    }
    if(ui->countDays->text().toInt() < 0 || ui->countDays->text().toInt() > 31)
    {
        QMessageBox::about(this, "Заселение", "Некорректные данные оплаченных дней");
        return;
    }
    qDebug() << "LIVING";
    QString arrayFIO = "'{";
    QString arrayPassSeries= "'{";
    QString arrayPassNumber= "'{";
    QString arrayPhone= "'{";

    for(auto& i: fullname)
    {
        if(i.second->text().isEmpty())
        {
          QMessageBox::about(this, "Заселение", "Забыли ввести ФИО посетителя " + QString::number(i.first+1));
          return;
        }
        arrayFIO +='"' + i.second->text() + '"' + ',';
    }
    arrayFIO[arrayFIO.size()-1] = '}';
    arrayFIO+="\'";

    for(auto& i: seriesPass)
        arrayPassSeries += (i.second->text().isEmpty()?"null":i.second->text()) + ",";
    arrayPassSeries[arrayPassSeries.size()-1] = '}';
    arrayPassSeries+="'";

    for(auto& i: numberPass)
        arrayPassNumber += (i.second->text().isEmpty()?"null":i.second->text()) + ",";
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
    out <<  Send::ADMINS << Type::ACCEPT << idEmployee <<  id << ui->countDays->text() << arrayFIO << arrayPassSeries << arrayPassNumber << arrayPhone;
    emit this->signalLiving(data);
    emit closeMe();
    deleteLater();

}

