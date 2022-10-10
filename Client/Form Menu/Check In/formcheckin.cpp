#include "formcheckin.h"
#include "Form Menu/Check In/itemcheckin.h"
#include "ui_formcheckin.h"

FormCheckIn::FormCheckIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCheckIn)
{
    ui->setupUi(this);
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(size_t i = 0u; i < 10u; i++)
    {
        layout->addWidget(new ItemCheckIn({"Билли", "Стив", "Dungeon Master"}));
    }
}

FormCheckIn::~FormCheckIn()
{
    delete ui;
}

void FormCheckIn::slotGetData(QDataStream &in)
{
    (void)in;
}
