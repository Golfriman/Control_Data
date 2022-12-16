#ifndef FORMCHECKIN_H
#define FORMCHECKIN_H

#include <QWidget>
#include "../const.h"
#include "Form Menu/Check In/itemcheckin.h"
#include "formarchivecheckin.h"

namespace Ui {
class FormCheckIn;
}

class FormCheckIn : public QWidget
{
    Q_OBJECT

public:
    explicit FormCheckIn(QString &idEmployee, QWidget *parent = nullptr);
    ~FormCheckIn();
public slots:
    void slotGetData(QDataStream& in);
signals:
    void signalSendToServer(QByteArray&);
private slots:
    void slotPrepareSendToServer(const QByteArray&);
    void on_pushButton_clicked();

private:
    QByteArray data;
    Ui::FormCheckIn *ui;
    std::unordered_map<QString, QString> map;
    QScopedPointer<ItemCheckIn> itm;
    QScopedPointer<FormArchiveCheckIn> archive;
    QString idEmployee;
};

#endif // FORMCHECKIN_H
