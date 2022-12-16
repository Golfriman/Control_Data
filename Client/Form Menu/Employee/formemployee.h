#ifndef FORMEMPLOYEE_H
#define FORMEMPLOYEE_H

#include "qdatetime.h"
#include "qlistwidget.h"
#include <QWidget>
#include <QAbstractListModel>
#include <QStringListModel>
#include <QList>
#include "../const.h"
#include "deleteemployee.h"
#include <QCalendarWidget>
namespace Ui {
class FormEmployee;
}

class FormEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit FormEmployee(QString &idEmployee, QWidget *parent = nullptr);
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
    void slotPrepareData(const QByteArray&);

    void on_pushButton_2_clicked();

    void on_date_userDateChanged(const QDate &date);

    void on_position_currentIndexChanged(int index);

    void on_position_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

signals:
    void signalSendToServer(QByteArray&);
private:
    void clear(QLayout* layout);
    QByteArray data;
    QScopedPointer<DeleteEmployee> empl;
    Ui::FormEmployee *ui;
    QString filter;
    QScopedPointer<QCalendarWidget> calendar;
    QString idEmployee;
};

#endif // FORMEMPLOYEE_H
