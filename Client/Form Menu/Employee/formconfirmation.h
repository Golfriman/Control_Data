#ifndef FORMCONFIRMATION_H
#define FORMCONFIRMATION_H

#include <QWidget>

namespace Ui {
class FormConfirmation;
}

class FormConfirmation : public QWidget
{
    Q_OBJECT

public:
    explicit FormConfirmation(QWidget *parent = nullptr);
    ~FormConfirmation();
signals:
    void signalYes();
    void signalNo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormConfirmation *ui;
};

#endif // FORMCONFIRMATION_H
