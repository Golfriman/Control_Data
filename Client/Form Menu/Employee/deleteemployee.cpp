    #include "deleteemployee.h"
#include <QMessageBox>
#include "qradiobutton.h"
#include "ui_deleteemployee.h"

#include "../const.h"
DeleteEmployee::DeleteEmployee(QString idEmployee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteEmployee)
{
    ui->setupUi(this);
    isSelected = false;
    this->idEmployee = idEmployee;
}

DeleteEmployee::~DeleteEmployee()
{
    delete ui;
}

void DeleteEmployee::on_pushButton_2_clicked()
{
    this->deleteLater();
}

void DeleteEmployee::slotFire()
{
    isSelected = !isSelected;
    auto btn = (QRadioButton*)sender();
    this->selectedEmployee = ids[btn->text()];
}


void DeleteEmployee::on_pushButton_clicked()
{
    if(!isSelected)
    {
        QMessageBox::about(this, "Увольнение", "Сотрудник не выбран");
        return;
    }
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ALL << Type::DROP << selectedEmployee;
    emit signalSendToServer(data);


}
void DeleteEmployee::slotGetData(QDataStream &in)
{
    auto clear = [](QLayout* layout)
    {
        QLayoutItem* itm;
        while((itm = layout->takeAt(0))!= nullptr)
        {
            delete itm->widget();
            delete itm;
        }
    };
    clear(ui->scrollAreaWidgetContents->layout());
    int size;
    in >> size;
    qDebug() << size;
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(int i = 0; i < size; i++)
    {
        QString fullname, birth, phone, id;
        in >> fullname >> birth >> phone >> id;
        QString result = fullname + " Дата рождения:" + birth + " Тел:" + phone;
        ids.emplace(result, id);
        QRadioButton* btn = new QRadioButton(result);
        connect(btn, SIGNAL(clicked()), this, SLOT(slotFire()));
        layout->addWidget(btn);
    }


}


void DeleteEmployee::on_lineEdit_textChanged(const QString &arg1)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Send::ONE << Type::FIND_EMPLOYEE_FULLNAME << ui->lineEdit->text() + "%" << idEmployee;
    emit signalSendToServer(data);
}


