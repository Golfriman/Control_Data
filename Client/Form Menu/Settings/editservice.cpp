#include "editservice.h"
#include "ui_editservice.h"
#include "itemservice.h"

EditService::EditService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditService)
{
    ui->setupUi(this);
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(size_t i = 0u; i < 10u; i++)
    {
        layout->addWidget(new ItemService());
    }
}

EditService::~EditService()
{
    delete ui;
}

void EditService::on_pushButton_clicked()
{
    ui->scrollAreaWidgetContents->layout()->addWidget(new ItemService());
}

