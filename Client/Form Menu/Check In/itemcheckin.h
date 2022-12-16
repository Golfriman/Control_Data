#ifndef ITEMCHECKIN_H
#define ITEMCHECKIN_H

#include <QtWidgets>
#include "../const.h"
#include "service.h"

namespace Ui {
class ItemCheckIn;
}

class ItemCheckIn : public QWidget
{
    Q_OBJECT

public:
    ItemCheckIn() = default;
    explicit ItemCheckIn(QString idEmployee, QDataStream& in, QWidget *parent = nullptr);
    void getConstant(QDataStream& in);
    ~ItemCheckIn();
signals:
    void sendToServer(const QByteArray&);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void slotPrepareSend(const QByteArray&);

private:
    Ui::ItemCheckIn *ui;
    QString checkin;
    QString checkout;
    QString id;
    QString number;
    QScopedPointer<Service> window;
    QString idEmployee;
    QString idRoom;
};

#endif // ITEMCHECKIN_H
