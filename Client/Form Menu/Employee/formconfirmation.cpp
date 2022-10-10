#include "formconfirmation.h"
#include "ui_formconfirmation.h"

FormConfirmation::FormConfirmation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConfirmation)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);


}

FormConfirmation::~FormConfirmation()
{
    delete ui;
}

void FormConfirmation::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == QString("ДОБАВИТЬ НОВОГО СОТРУДНИКА"))
    {
        emit signalYes();
    }
}


void FormConfirmation::on_pushButton_2_clicked()
{
    emit signalNo();
}

