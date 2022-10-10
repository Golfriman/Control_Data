#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include "../const.h"
namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget
{
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();
signals:
    void signalSendToServer(QByteArray&);
public slots:
    void callSignal(QString filter = "");
    void slotGetData(QDataStream& in);
private slots:
    void on_pushButton_clicked();

private:
    QByteArray data;
    Ui::FormSettings *ui;
};

#endif // FORMSETTINGS_H
