#ifndef FORMCOMPLETEWORK_H
#define FORMCOMPLETEWORK_H

#include <QWidget>

namespace Ui {
class FormCompleteWork;
}

class FormCompleteWork : public QWidget
{
    Q_OBJECT

public:
    explicit FormCompleteWork(QString employee, QWidget *parent = nullptr);
    ~FormCompleteWork();
signals:
    void signalSendToServer(QByteArray&);

private slots:
    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::FormCompleteWork *ui;
    QString employee;
};

#endif // FORMCOMPLETEWORK_H
