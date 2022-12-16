#include "formreport.h"
#include "ui_formreport.h"
#include <QDate>

FormReport::FormReport(QString& idEmployee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormReport)
{
    (void)(idEmployee);
    ui->setupUi(this);
}

void FormReport::callSignal(QString filter)
{
    (void)(filter);
    emit signalSendToServer(data);
}

FormReport::~FormReport()
{
    delete ui;
}

void FormReport::slotGetData(QDataStream &in)
{
    int size = 0;
    in >> size;
    QString idRoom ="";
    QString infoVisitor = "FFOFOFOFOFOF";
    if(size > 0)
    {
        infoVisitor = "Сегодня заселились:<center><table border=\"1\" bordercolor=\"black\" cellpadding=\"5\"><tr><th>Номер</th><th>ФИО посетителя</th>";
        for(int i =0; i < size;i++)
        {
            QString new_idRoom;
            in >> new_idRoom;
            if(idRoom != new_idRoom)
            {
                idRoom = new_idRoom;
                infoVisitor += "<tr><td><center>" + idRoom + "</center></td><td>";
            }
            else infoVisitor += "</td></tr>";
            QString fullnameVisitor;
            in >> fullnameVisitor;
            infoVisitor += "<p>" + fullnameVisitor + "</p>";
        }
        infoVisitor += "</table></center>";
    }
    else infoVisitor = "<p>Сегодня никто не заслелился.</p>";

    QString infoWork = "FFPFPFPF";

    in >> size;
    if(size > 0)
    {
        infoWork = "Выполненая работа сегодня:<br><center><table border=\"1\" bordercolor=\"black\" cellpadding=\"5\"><tr><th>Работник</th><th>Название работы</th><th>Номер</th>";
        for(int i =0; i < size;i++)
        {
            QString fullname, work, idRoom;
            in >> fullname >> work >> idRoom;
            infoWork += "<tr><td>" + fullname + "</td><td>" + work + "</td><td><center>" + idRoom + "</center></td></tr>";
        }
        infoWork +="</table></center>";
    }
    else infoWork = "<p>Сегодня работы не было.</p>";
    doсument = QString("<b>Отчет за %1</b>").arg(QDate::currentDate().toString("dd.MM.yy")) + "<br/>" +infoVisitor + infoWork;
    ui->html->setText(doсument);
}

void FormReport::on_pushButton_clicked()
{
    doc.setHtml(doсument);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(QString("отчет за %1").arg(QDate::currentDate().toString("dd.MM.yy")) + ".pdf" );
    printer.setCreator("Dashboard Adminity");
    doc.print(&printer);
}


void FormReport::on_pushButton_2_clicked()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << Form::REPORT << Send::ONE << Type::VIEW;
    emit signalSendToServer(data);
}

