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
    explicit FormReport(QWidget *parent = nullptr);
    ~FormReport();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);
private slots:
    void on_pushButton_clicked();

private:
    QTextDocument doc;
    QByteArray data;
    Ui::FormReport *ui;
};

#endif // FORMREPORT_H
