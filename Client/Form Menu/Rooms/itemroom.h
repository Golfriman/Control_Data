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
    explicit ItemRoom(QWidget *parent = nullptr);
    ~ItemRoom();

private:
    Ui::ItemRoom *ui;
};

#endif // ITEMROOM_H
