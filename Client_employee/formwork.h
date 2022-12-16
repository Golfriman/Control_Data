#ifndef FORMWORK_H
#define FORMWORK_H

#include <QMainWindow>
#include "formcompletework.h"

namespace Ui {
class FormWork;
}

class FormWork : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormWork(const QString &idEmployee, QString fullname, QWidget *parent = nullptr);
    ~FormWork();
public slots:
    void slotGetData(QDataStream&);
signals:
    void signalSendToServer(QByteArray&);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void slotPrepareData(QByteArray&);

private:
    Ui::FormWork *ui;
    QScopedPointer<FormCompleteWork> window;
    QString employee;
    QString fullname;
};

#endif // FORMWORK_H
