#include "formcompletework.h"
#include "ui_formcompletework.h"
#include "../const.h"

FormCompleteWork::FormCompleteWork(QString employee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCompleteWork)
{
    ui->setupUi(this);
    this->employee = employee;
    ui->another_lineEdit->hide();
    ui->another_text->hide();
    for(int i = 1; i <=26; i++)
        ui->comboBox->addItem(QString::number(i));
}
FormCompleteWork::~FormCompleteWork()
{
    delete ui;
}

void FormCompleteWork::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Другое")
    {
        ui->another_lineEdit->show();
        ui->another_text->show();
    }
    else
    {
        ui->another_lineEdit->hide();
        ui->another_text->hide();
    }
}


void FormCompleteWork::on_pushButton_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    data.clear();
    out << Form::EMPLOYEE << Send::ADMINS << Type::COMPLETE_WORK << this->employee;
    if(ui->comboBox_2->currentText() == "Другое")
        out << ui->another_lineEdit->text();

    else out << ui->comboBox_2->currentText();
    out << ui->comboBox->currentText();
    emit signalSendToServer(data);
    qDebug() << data;
}

