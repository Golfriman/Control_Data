#ifndef FORMROOMS_H
#define FORMROOMS_H

#include <QWidget>
#include "../const.h"
#include "formchangecleanningroom.h"
namespace Ui {
class FormRooms;
}

class FormRooms : public QWidget
{
    Q_OBJECT

public:
    explicit FormRooms(QWidget *parent = nullptr);
    ~FormRooms();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);

private slots:
    void on_pushButton_clicked();
    void slotPrepareSignal(QByteArray& data);
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    QString html;
    QByteArray data;
    QString filter;
    Ui::FormRooms *ui;
    QScopedPointer<FormChangeCleanningRoom> window;
};

#endif // FORMROOMS_H
