#include "formsettings.h"
#include "Form Menu/Settings/editservice.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSettings)
{
    ui->setupUi(this);
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::SETTINGS << Send::ONE;
}

void FormSettings::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormSettings::~FormSettings()
{
    delete ui;
}

void FormSettings::slotGetData(QDataStream &in)
{

}

void FormSettings::on_pushButton_clicked()
{
    EditService* form = new EditService;
    form->show();

}

