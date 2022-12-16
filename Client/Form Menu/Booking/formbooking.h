#ifndef FORMBOOKING_H
#define FORMBOOKING_H
#include "../const.h"
#include "Form Menu/Booking/formcreatebooking.h"
#include "itembooking.h"
#include <QtWidgets>
#include <set>

namespace Ui {
class FormBooking;
}

class FormBooking : public QWidget
{
    Q_OBJECT

public:
    explicit FormBooking(QString& idEmployee, QWidget *parent = nullptr);
    void getData(QDataStream&);
    ~FormBooking();
public slots:
    void callSignal(const QByteArray& out);
    void slotSignUp();
    void callFindRoom(const QByteArray& out);
private slots:
    void on_pushButton_clicked();
    void on_comboBox_currentIndexChanged(int index);

signals:
    void signalSendToServer(QByteArray&);
    void signalSignUp();
private:
    QString idEmployee;
    bool isItemBooking;
    std::vector<std::pair<QString, QString>> services;
    std::vector<QString> price;
    QListWidget widget;
    QScopedPointer<ItemBooking> window;
    QScopedPointer<FormCreateBooking> createBooking;
    std::map<QString, std::vector<QString>> dict;
    QStandardItemModel* model;
    QByteArray data;
    Ui::FormBooking *ui;
};

#endif // FORMBOOKING_H
