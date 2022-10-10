#include "formsignup.h"
#include "ui_formsignup.h"

FormSignUp::FormSignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSignUp)
{

    ui->setupUi(this);
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::SIGN_UP << Send::ONE;
}

void FormSignUp::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormSignUp::~FormSignUp()
{
    delete ui;
}

void FormSignUp::slotGetData(QDataStream &in)
{

}
