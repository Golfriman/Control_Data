#include "formrooms.h"
#include "Form Menu/Rooms/itemroom.h"
#include "qmessagebox.h"
#include "ui_formrooms.h"
#include <iostream>
FormRooms::FormRooms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRooms)
{
    ui->setupUi(this);
}

void FormRooms::callSignal(QString filter)
{
    (void)filter;
    emit signalSendToServer(data);
}

FormRooms::~FormRooms()
{
    delete ui;
}

void FormRooms::slotGetData(QDataStream &in)
{
    int type;
    in >> type;
    if(type == Type::CHANGE_CLEAN)
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Измение статуса", info);
        return;
    }
    auto clear = [&](QLayout* layout)
    {
        QLayoutItem* itm;
        while((itm = layout->takeAt(0))!= nullptr)
        {
            delete itm->widget();
            delete itm;
        }
    };
    auto layout = ui->scrollAreaWidgetContents->layout();
    layout->setAlignment(Qt::AlignTop);
    clear(layout);
    int size;
    in >> size;
    for(int i = 0; i < size; i++)
    {
        QString idRoom;
        QString statusCleaning;
        QString statusRoom;
        QString category;
        QString price;
        QString size;
        QString cap;
        in >> idRoom >>category>> statusCleaning >> price >> size >> cap >> statusRoom;
        layout->addWidget(new ItemRoom(idRoom,category, statusCleaning, statusRoom, price, size, cap));
    }
}

void FormRooms::on_pushButton_clicked()
{
    window.reset(new FormChangeCleanningRoom);
    connect(window.get(), SIGNAL(signalSendToServer(QByteArray&)), this, SLOT(slotPrepareSignal(QByteArray&)));
    window->show();
}

void FormRooms::slotPrepareSignal(QByteArray &data)
{
    emit signalSendToServer(data);
}


void FormRooms::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="все")
        filter = "%";
    else
        filter = arg1;
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::ROOMS << Send::ONE << Type::FILTER_ROOMS << filter;
    emit signalSendToServer(data);
}

