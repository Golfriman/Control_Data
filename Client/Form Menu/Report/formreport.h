#ifndef FORMREPORT_H
#define FORMREPORT_H

#include <QWidget>
#include "../const.h"
#include <QPrinter>
#include <QTextDocument>
namespace Ui {
class FormReport;
}

class FormReport : public QWidget
{
    Q_OBJECT

public:
    explicit FormReport(QString &idEmployee, QWidget *parent = nullptr);
    ~FormReport();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QString doсument;
    QTextDocument doc;
    QByteArray data;
    Ui::FormReport *ui;
    QString html;
};

#endif // FORMREPORT_H
