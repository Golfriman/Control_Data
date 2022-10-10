#include "service.h"
#include "qcheckbox.h"
#include "ui_service.h"

Service::Service(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service)
{
    this->setWindowTitle("Редактирование услуг");
    ui->setupUi(this);
    auto layout = ui->scrollAreaWidgetContents->layout();

}

Service::~Service()
{
    delete ui;
}
