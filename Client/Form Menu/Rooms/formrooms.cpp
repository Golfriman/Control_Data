#include "formrooms.h"
#include "Form Menu/Rooms/itemroom.h"
#include "ui_formrooms.h"

FormRooms::FormRooms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRooms)
{
    ui->setupUi(this);
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(size_t i = 0u; i < 10u; i++)
    {
        layout->addWidget(new ItemRoom());
    }
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

}
