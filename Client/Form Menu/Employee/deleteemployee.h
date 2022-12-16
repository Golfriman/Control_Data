#ifndef DELETEEMPLOYEE_H
#define DELETEEMPLOYEE_H

#include <QWidget>

namespace Ui {
class DeleteEmployee;
}

class DeleteEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteEmployee(QString idEmployee, QWidget *parent = nullptr);
    ~DeleteEmployee();

private slots:
    void on_pushButton_2_clicked();
    void slotFire();
    void on_pushButton_clicked();
    void on_lineEdit_textChanged(const QString &arg1);

public slots:
    void slotGetData(QDataStream& in);
signals:
    void signalSendToServer(const QByteArray&);

private:
    Ui::DeleteEmployee *ui;
    bool isSelected;
    QString idEmployee;
    QString selectedEmployee;
    std::unordered_map<QString, QString> ids;
};

#endif // DELETEEMPLOYEE_H
