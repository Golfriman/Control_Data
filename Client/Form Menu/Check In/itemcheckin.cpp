#include "itemcheckin.h"
#include "ui_itemcheckin.h"
#include "service.h"

ItemCheckIn::ItemCheckIn(const std::list<QString>& persons, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemCheckIn)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    auto layout = ui->frame->layout();
    for(auto& i: persons)
    {
        layout->addWidget(new QLabel(i));
    }
}

ItemCheckIn::~ItemCheckIn()
{
    delete ui;
}

void ItemCheckIn::on_checkBox_stateChanged(int arg1)
{
    switch(arg1)
    {
        case Qt::Unchecked:
        {
            ui->frame->setVisible(false);
            break;
        }
        case Qt::Checked:
        {
            ui->frame->setVisible(true);
            break;
        }
        default:
        break;
    }
}


void ItemCheckIn::on_pushButton_clicked()
{
    Service* form = new Service();
    form->show();
}

