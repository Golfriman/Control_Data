#ifndef SERVICE_H
#define SERVICE_H

#include <QWidget>
#include <set>
#include <map>

namespace Ui {
class Service;
}

class Service : public QWidget
{
    Q_OBJECT
public:
    explicit Service(QString idCheckin,QString idEmployee, QWidget *parent = nullptr);
    ~Service();
public slots:
    void slotGetData(QDataStream& in);
    void slotChanged(int state);
signals:
    void signalSendToServer(const QByteArray& out);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Service *ui;
    std::map<QString, QString> map;
    QString idCheckin;
    std::set<QString> selectedServices;
    QString idEmployee;
};

#endif // SERVICE_H
