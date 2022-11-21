#ifndef FORMCHECKIN_H
#define FORMCHECKIN_H

#include <QWidget>
#include "../const.h"
#include "Form Menu/Check In/itemcheckin.h"

namespace Ui {
class FormCheckIn;
}

class FormCheckIn : public QWidget
{
    Q_OBJECT

public:
    explicit FormCheckIn(QWidget *parent = nullptr);
    ~FormCheckIn();
public slots:
    void slotGetData(QDataStream& in);
signals:
    void signalSendToServer(const QByteArray&);
private slots:
    void slotPrepareSendToServer(const QByteArray&);
private:
    QByteArray data;
    Ui::FormCheckIn *ui;
    std::unordered_map<QString, QString> map;
    QScopedPointer<ItemCheckIn> itm;
};

#endif // FORMCHECKIN_H
