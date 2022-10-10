#ifndef ITEMEMPLOYEE_H
#define ITEMEMPLOYEE_H

#include <QWidget>

namespace Ui {
class ItemEmployee;
}

class ItemEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit ItemEmployee(QString& pos, QString& name, QWidget *parent = nullptr);
    ~ItemEmployee();

private:
    Ui::ItemEmployee *ui;
};

#endif // ITEMEMPLOYEE_H
