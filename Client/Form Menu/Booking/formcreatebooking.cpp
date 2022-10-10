#include "formcreatebooking.h"
#include "ui_formcreatebooking.h"
#include "../const.h"
#include "phonevalidator.h"
FormCreateBooking::FormCreateBooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateBooking)
{
    ui->setupUi(this);
    setWindowTitle("Создание брони");
    setWindowModality(Qt::ApplicationModal);
    auto validate = new PhoneValidator;
    ui->phone->setValidator(validate);
}

FormCreateBooking::~FormCreateBooking()
{
    delete ui;
}

void FormCreateBooking::createCalendar()
{
    calendar = new Calendar();
    calendar->setGridVisible(true);
    connect(calendar, SIGNAL(signalCheckIn(QDate&)), this, SLOT(slotCheckIn(QDate&)));
    connect(calendar, SIGNAL(signalCheckOut(QDate&)), this, SLOT(slotCheckOut(QDate&)));
    connect(calendar, SIGNAL(finished()), calendar, SLOT(deleteLater()));
}

void FormCreateBooking::on_pushButton_2_clicked()
{
    QByteArray data;
    data.clear();
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
    out << Type::INSERT << text(ui->phone) << text(ui->checkIn) << text(ui->checkOut) << ui->typeRoom->currentText() << ui->numPeople->currentText();/*Информация о дате и тому подобное...*/
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
    ui->checkIn->setText(d.toString("dd.MM.yyyy"));
    ui->checkOut->clear();
}

void FormCreateBooking::slotCheckOut(QDate &d)
{
    ui->checkOut->setText(d.toString("dd.MM.yyyy"));
}


void FormCreateBooking::on_pushButton_clicked()
{
    emit signalSignUp();
}

