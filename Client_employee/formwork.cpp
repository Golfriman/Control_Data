#include "formwork.h"
#include "itemroom.h"
#include "ui_formwork.h"
#include "../const.h"

FormWork::FormWork(const QString& idEmployee,QString fullname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormWork)
{
    ui->setupUi(this);
    this->employee = idEmployee;
    this->fullname = fullname;
    setWindowTitle("Пользователь :" + fullname);
}

FormWork::~FormWork()
{
    delete ui;
}

void FormWork::slotGetData(QDataStream & in)
{
    int type;
    in >> type;
    if(type!= Type::VIEW)return;
    auto layout = ui->scrollAreaWidgetContents->layout();
    QLayoutItem* itm;
    while((itm = layout->takeAt(0))!= nullptr)
    {
        delete itm->widget();
        delete itm;
    }
    int size;
    in >> size;
    for(int i = 0; i < size; i++)
    {
        QString idRoom;
        QString statusCleaning;
        QString statusRoom;
        QString templ;
        //in >> idRoom >>category>> statusCleaning >> price >> size >> cap >> statusRoom;
        in >> idRoom >> templ >> statusCleaning >>templ>>templ>>templ>> statusRoom;
        //std::cout << idRoom.toStdString();
        layout->addWidget(new ItemRoom(idRoom, statusCleaning, statusRoom));
    }
}

void FormWork::on_pushButton_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::ROOMS << Send::ONE << Type::VIEW;
    emit signalSendToServer(data);
}


void FormWork::on_pushButton_2_clicked()
{
    window.reset(new FormCompleteWork(employee));
    connect(window.get(), SIGNAL(signalSendToServer(QByteArray&)), this, SLOT(slotPrepareData(QByteArray&)));
    window->show();
}

void FormWork::slotPrepareData(QByteArray &data)
{
    emit signalSendToServer(data);
}

