#include "formrooms.h"
#include "Form Menu/Rooms/itemroom.h"
#include "ui_formrooms.h"

FormRooms::FormRooms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRooms)
{
    ui->setupUi(this);
}

void FormRooms::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormRooms::~FormRooms()
{
    delete ui;
}

void FormRooms::slotGetData(QDataStream &in)
{
    auto layout = ui->scrollAreaWidgetContents->layout();
    int size;
    in >> size;
    for(int i = 0; i < size; i++)
    {
        QString idRoom;
        QString statusCleaning;
        QString statusRoom;
        in >> idRoom >> statusCleaning >> statusRoom;
        layout->addWidget(new ItemRoom(idRoom, statusCleaning, statusRoom));
    }
}
