#include "formsignup.h"
#include "ui_formsignup.h"
#include <QMessageBox>

FormSignUp::FormSignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSignUp)
{

    ui->setupUi(this);
    data.clear();
}

FormSignUp::~FormSignUp()
{
    delete ui;
}

void FormSignUp::slotGetData(QDataStream &in)
{
    QString info;
    in>>info;
    QMessageBox::about(this, "Статус регистрации", info);
}

void FormSignUp::on_pushButton_clicked()
{
        data.clear();
        QDataStream out(&data, QIODevice::WriteOnly);
        out << Form::SIGN_UP << Send::ONE << Type::INSERT
                             << ui->fullname->text()
                             << ui->passportSeries->text()
                             << ui->passportNumber->text()
                             << ui->phone->text();
        emit signalSendToServer(data);
}

