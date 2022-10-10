#ifndef FORMCHECKIN_H
#define FORMCHECKIN_H

#include <QWidget>
#include "../const.h"
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
    void signalSendToServer(QByteArray&);
private:
    QByteArray data;
    Ui::FormCheckIn *ui;
};

#endif // FORMCHECKIN_H
