#ifndef FORMCONCRETEEMPLOYEE_H
#define FORMCONCRETEEMPLOYEE_H

#include "qcalendar.h"
#include "qcalendarwidget.h"
#include <QWidget>
#include <QDate>

namespace Ui {
class FormConcreteEmployee;
}

class FormConcreteEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit FormConcreteEmployee(QWidget *parent = nullptr);
    ~FormConcreteEmployee();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();
    void slotDate(QDate);

signals:
    void signalSendToServer(const QByteArray&);

private:
    Ui::FormConcreteEmployee *ui;
    QScopedPointer<QCalendarWidget> calendar;
};

#endif // FORMCONCRETEEMPLOYEE_H
