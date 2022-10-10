#ifndef FORMEMPLOYEE_H
#define FORMEMPLOYEE_H

#include "qlistwidget.h"
#include <QWidget>
#include <QAbstractListModel>
#include <QStringListModel>
#include <QList>
#include "../const.h"

namespace Ui {
class FormEmployee;
}

class FormEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit FormEmployee(QWidget *parent = nullptr);
    ~FormEmployee();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
private:
    void fillAllEmployee(QDataStream &in);
    void fillWorkHotel(QDataStream &in);
private slots:
    void on_pushButton_clicked();
    void slotCreateEmployee();

signals:
    void signalSendToServer(QByteArray&);
private:
    QByteArray data;

    Ui::FormEmployee *ui;
};

#endif // FORMEMPLOYEE_H
