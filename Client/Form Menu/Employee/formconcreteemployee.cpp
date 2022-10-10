#include "formconcreteemployee.h"
#include "ui_formconcreteemployee.h"

FormConcreteEmployee::FormConcreteEmployee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConcreteEmployee)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

FormConcreteEmployee::~FormConcreteEmployee()
{
    delete ui;
}

void FormConcreteEmployee::on_pushButton_2_clicked()
{
    deleteLater();
}

