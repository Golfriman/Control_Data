#ifndef FORMCONCRETEEMPLOYEE_H
#define FORMCONCRETEEMPLOYEE_H

#include <QWidget>

namespace Ui {
class FormConcreteEmployee;
}

class FormConcreteEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit FormConcreteEmployee(QWidget *parent = nullptr);
    ~FormConcreteEmployee();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::FormConcreteEmployee *ui;
};

#endif // FORMCONCRETEEMPLOYEE_H
