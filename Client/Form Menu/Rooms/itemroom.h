#ifndef ITEMROOM_H
#define ITEMROOM_H

#include <QWidget>

namespace Ui {
class ItemRoom;
}

class ItemRoom : public QWidget
{
    Q_OBJECT

public:
    explicit ItemRoom(QString _id,QString category, QString statusCleaning, QString statusRoom, QString price,QString size, QString cap, QWidget *parent = nullptr);
    ~ItemRoom();

private:
    Ui::ItemRoom *ui;
};

#endif // ITEMROOM_H
