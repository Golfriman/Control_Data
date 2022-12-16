#include "formemployee.h"
#include "formconfirmation.h"
#include "formconcreteemployee.h"
#include "ui_formemployee.h"
#include "employeedelegate.h"
#include "itemworkhotel.h"
#include "itememployee.h"
#include <QWhatsThis>
FormEmployee::FormEmployee(QString& idEmployee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmployee)
{
    ui->setupUi(this);
    //ui->listView->setItemDelegate(new EmployeeDelegate(ui->listView));
    ui->date->setDate(QDate::currentDate());
    this->idEmployee = idEmployee;
}

void FormEmployee::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormEmployee::~FormEmployee()
{
    delete ui;
}

void FormEmployee::slotGetData(QDataStream &in)
{
    int type;
    in >> type;
    switch(type)
    {
    case Type::FIND_EMPLOYEE:
        fillAllEmployee(in);
        break;
    case Type::VIEW:
        fillAllEmployee(in);
        fillWorkHotel(in);
        break;
    case Type::DROP:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат увольнения", info);
        break;
    }
    case Type::FIND_WORK:
    {
        fillWorkHotel(in);
        break;
    }
    case Type::FIND_EMPLOYEE_FULLNAME:
    {
        empl->slotGetData(in);
        break;
    }
    case Type::INSERT:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат добавления сотрудника в базу", info);
        break;
    }
    }


}

void FormEmployee::fillAllEmployee(QDataStream &in)
{
    int size;
    in >> size;
    auto layout = ui->all->layout();
    clear(layout);
    layout->setAlignment(Qt::AlignTop);
    for(int i = 0; i < size; i++)
    {
        QString name, birth, phone;
        in >> name >> birth >> phone;
        auto label = new QLabel(name + " Телефон: " + phone);
        //label->setWhatsThis("Телефон: " + phone + " Дата рождения: " + birth);
        layout->addWidget(label);
    }
}

void FormEmployee::fillWorkHotel(QDataStream &in)
{
    int size;
    in >> size;
    auto layout = ui->log->layout();
    clear(layout);
    layout->setAlignment(Qt::AlignTop);
    for(int i = 0; i < size; i++)
    {
        QString empl, namework, room;
        in >> empl >> namework >> room;
        room = "Команта № " + room;
        layout->addWidget(new ItemWorkHotel(empl, namework, room));
    }
}

void FormEmployee::on_pushButton_clicked()
{
    auto confirmation = new FormConfirmation;
    connect(confirmation, SIGNAL(signalYes()), this, SLOT(slotCreateEmployee()));
    connect(confirmation, SIGNAL(signalYes()), confirmation, SLOT(deleteLater()));
    connect(confirmation, SIGNAL(signalNo()), confirmation, SLOT(deleteLater()));
    confirmation->show();
}

void FormEmployee::slotCreateEmployee()
{
    auto form = new FormConcreteEmployee();
    connect(form, SIGNAL(signalSendToServer(const QByteArray&)), this, SLOT(slotPrepareData(const QByteArray&)));
    form->show();
}

void FormEmployee::slotPrepareData(const QByteArray &dataDeleteEmployee)
{
    QByteArray new_out;
    QDataStream out(&new_out, QIODevice::WriteOnly);
    out << Form::EMPLOYEE;
    new_out.append(dataDeleteEmployee);
    emit signalSendToServer(new_out);
}


void FormEmployee::on_pushButton_2_clicked()
{
    this->empl.reset(new DeleteEmployee(idEmployee));
    empl->show();
    connect(empl.get(), SIGNAL(signalSendToServer(const QByteArray&)), this, SLOT(slotPrepareData(const QByteArray&)));
}

void FormEmployee::clear(QLayout *layout)
{
    QLayoutItem* itm;
    while((itm = layout->takeAt(0))!= nullptr)
    {
        delete itm->widget();
        delete itm;
    }
}


void FormEmployee::on_date_userDateChanged(const QDate &date)
{
    ui->date->setDate(date);
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::EMPLOYEE << Send::ONE << Type::FIND_WORK << date.toString();
    emit signalSendToServer(data);
}


void FormEmployee::on_position_currentIndexChanged(int index)
{
    (void)(index);
}


void FormEmployee::on_position_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Любая") filter = "%";
    else filter = arg1;
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::EMPLOYEE << Send::ONE << Type::FIND_EMPLOYEE << filter;
    emit signalSendToServer(data);

}


void FormEmployee::on_pushButton_3_clicked()
{
    calendar.reset(new QCalendarWidget());
    connect(calendar.get(), SIGNAL(clicked(const QDate&)), this, SLOT(on_date_userDateChanged(const QDate&)));
    calendar->show();
}

