#include "formconcreteemployee.h"
#include "ui_formconcreteemployee.h"
#include "../const.h"
#include <QMessageBox>

FormConcreteEmployee::FormConcreteEmployee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConcreteEmployee)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

FormConcreteEmployee::~FormConcreteEmployee()
{
    delete ui;
}

void FormConcreteEmployee::on_pushButton_2_clicked()
{
    deleteLater();
}


void FormConcreteEmployee::on_pushButton_clicked()
{
    if(ui->fullname->text().isEmpty() || ui->phone->text().isEmpty() || ui->birth->text().isEmpty())
    {
        QMessageBox::about(this,"Добавления нового сотрудника", "Не заполнены все поля");
        return;
    }
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ALL << Type::INSERT << ui->fullname->text() << ui->phone->text() << ui->birth->text() << ui->position->currentText();
    emit signalSendToServer(data);
    deleteLater();
}


void FormConcreteEmployee::on_pushButton_3_clicked()
{
    calendar.reset(new QCalendarWidget());
    calendar->setDateRange(QDate::currentDate().addYears(-120), QDate::currentDate().addYears(-18));
    calendar->setWindowModality(Qt::ApplicationModal);
    connect(calendar.get(), SIGNAL(clicked(QDate)), this, SLOT(slotDate(QDate)));
    calendar->show();
}

void FormConcreteEmployee::slotDate(QDate date)
{
    ui->birth->setText(date.toString("dd.MM.yyyy"));
}

