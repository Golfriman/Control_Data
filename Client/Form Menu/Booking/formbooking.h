#ifndef FORMBOOKING_H
#define FORMBOOKING_H
#include "../const.h"
#include "itembooking.h"
#include <QtWidgets>

namespace Ui {
class FormBooking;
}

class FormBooking : public QWidget
{
    Q_OBJECT

public:
    explicit FormBooking(QWidget *parent = nullptr);
    void getData(QDataStream&);
    ~FormBooking();
public slots:
    void callSignal(const QByteArray& out);
    void slotSignUp();
private slots:
    void on_pushButton_clicked();
signals:
    void signalSendToServer(QByteArray&);
    void signalSignUp();
private:
    QListWidget widget;
    QStandardItemModel* model;
    QByteArray data;
    Ui::FormBooking *ui;
};

#endif // FORMBOOKING_H
