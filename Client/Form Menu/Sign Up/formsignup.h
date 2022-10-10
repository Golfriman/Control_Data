#ifndef FORMSIGNUP_H
#define FORMSIGNUP_H

#include <QWidget>
#include "../const.h"
namespace Ui {
class FormSignUp;
}

class FormSignUp : public QWidget
{
    Q_OBJECT

public:
    explicit FormSignUp(QWidget *parent = nullptr);
    ~FormSignUp();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);

private:
    QByteArray data;
    Ui::FormSignUp *ui;
};

#endif // FORMSIGNUP_H
