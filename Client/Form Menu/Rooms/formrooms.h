#ifndef FORMROOMS_H
#define FORMROOMS_H

#include <QWidget>
#include "../const.h"
namespace Ui {
class FormRooms;
}

class FormRooms : public QWidget
{
    Q_OBJECT

public:
    explicit FormRooms(QWidget *parent = nullptr);
    ~FormRooms();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);

private:
    QByteArray data;

    Ui::FormRooms *ui;
};

#endif // FORMROOMS_H
