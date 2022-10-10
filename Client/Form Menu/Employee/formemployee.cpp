#include "formemployee.h"
#include "formconfirmation.h"
#include "formconcreteemployee.h"
#include "ui_formemployee.h"
#include "employeedelegate.h"
#include "itemworkhotel.h"
#include "itememployee.h"
FormEmployee::FormEmployee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmployee)
{
    ui->setupUi(this);
    //ui->listView->setItemDelegate(new EmployeeDelegate(ui->listView));

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

    fillAllEmployee(in);
    fillWorkHotel(in);
}

void FormEmployee::fillAllEmployee(QDataStream &in)
{
    int size;
    in >> size;
    auto layout = ui->all->layout();
    for(int i = 0; i < size; i++)
    {
        QString name, position;
        in >> name >> position;
        layout->addWidget(new ItemEmployee(position, name));
    }
}

void FormEmployee::fillWorkHotel(QDataStream &in)
{
    int size;
    in >> size;
    auto layout = ui->logWork->layout();
    for(int i = 0; i < size; i++)
    {
        QString namework, time;
        in >> namework >> time;
        layout->addWidget(new ItemWorkHotel(time, namework));
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
    form->show();
}

