#ifndef ITEMCHECKIN_H
#define ITEMCHECKIN_H

#include <QtWidgets>
#include "../const.h"

namespace Ui {
class ItemCheckIn;
}

class ItemCheckIn : public QWidget
{
    Q_OBJECT

public:
    ItemCheckIn() = default;
    explicit ItemCheckIn(QDataStream& in, QWidget *parent = nullptr);
    ~ItemCheckIn();
signals:
    void sendToServer(const QByteArray&);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ItemCheckIn *ui;
    QString id;
};

#endif // ITEMCHECKIN_H
