#ifndef ITEMSERVICE_H
#define ITEMSERVICE_H

#include <QWidget>

namespace Ui {
class ItemService;
}

class ItemService : public QWidget
{
    Q_OBJECT

public:
    explicit ItemService(QWidget *parent = nullptr);
    ~ItemService();

private:
    Ui::ItemService *ui;
};

#endif // ITEMSERVICE_H
