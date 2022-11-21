#ifndef ACCEPTBOOKING_H
#define ACCEPTBOOKING_H

#include <QtWidgets>

namespace Ui {
class acceptBooking;
}

class acceptBooking : public QWidget
{
    Q_OBJECT

public:
    explicit acceptBooking(int num, QWidget *parent = nullptr);
    ~acceptBooking();

private slots:
    void on_pushButton_clicked();
signals:
    void signalLiving(const QByteArray&);
private:
    std::map<int, QScopedPointer<QLineEdit>> fullname;
    std::map<int, QScopedPointer<QLineEdit>> seriesPass;
    std::map<int, QScopedPointer<QLineEdit>> numberPass;
    std::map<int, QScopedPointer<QLineEdit>> phone;
    std::vector<QVBoxLayout*> vert;
    std::vector<QHBoxLayout*> gHor;
    std::vector<QGroupBox*> hor;
    Ui::acceptBooking *ui;
};

#endif // ACCEPTBOOKING_H
