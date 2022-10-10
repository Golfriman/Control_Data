#ifndef ITEMCHECKIN_H
#define ITEMCHECKIN_H

#include <QtWidgets>

namespace Ui {
class ItemCheckIn;
}

class ItemCheckIn : public QWidget
{
    Q_OBJECT

public:
    explicit ItemCheckIn(const std::list<QString>& persons, QWidget *parent = nullptr);
    ~ItemCheckIn();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::ItemCheckIn *ui;
};

#endif // ITEMCHECKIN_H
