#include "service.h"
#include "qcheckbox.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "ui_service.h"
#include "../const.h"

Service::Service(QString idCheckin, QString idEmployee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service)
{
    this->setWindowTitle("Редактирование услуг");
    ui->setupUi(this);
    this->idCheckin = idCheckin;
    this->idEmployee = idEmployee;
}

Service::~Service()
{
    delete ui;
}

void Service::slotGetData(QDataStream &in)
{
    int size;
    in >> size;
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(int i =0;i < size; i++)
    {
        QString nameService;
        QString price;
        in >> nameService >> price;
        QCheckBox* box = new QCheckBox(nameService + " " + price);
        map.emplace(nameService+" " + price, nameService);
        connect(box, SIGNAL(stateChanged(int)), this, SLOT(slotChanged(int)));
        layout->addWidget(box);
    }
}

void Service::slotChanged(int state)
{
    auto itm = (QCheckBox*)(sender());
    switch(state)
    {
    case Qt::Checked:
    {
        this->selectedServices.emplace(map[itm->text()]);
        break;
    }
    case Qt::Unchecked:
    {
        if(selectedServices.find(itm->text())!=selectedServices.end())
        {
            selectedServices.erase(itm->text());
        }
        break;
    }
    }

}

void Service::on_pushButton_clicked()
{
    QString filter = "'{";
    for(auto& i: selectedServices)
        filter +='"' + i + '"' + ',';
    filter[filter.size()-1] = '}';
    filter+="\'";
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ADMINS << Type::ADD <<idCheckin <<  filter << idEmployee;
    emit this->signalSendToServer(data);
    this->hide();
}

