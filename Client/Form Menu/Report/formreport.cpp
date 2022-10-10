#include "formreport.h"
#include "ui_formreport.h"
#include <QDate>

FormReport::FormReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormReport)
{
    ui->setupUi(this);
    doc.setHtml("<div style=\"margin:0 auto;\">"
                "<img src = \"Graphics.png\" alt = \"график\" width = \"600\" height = \"300\">"
                "</div>");

}

void FormReport::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormReport::~FormReport()
{
    delete ui;
}

void FormReport::slotGetData(QDataStream &in)
{

}

void FormReport::on_pushButton_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(QString("отчет за" + QDate::currentDate().toString("dd.MM.yyyy")) + ".pdf");
    doc.print(&printer);

}

