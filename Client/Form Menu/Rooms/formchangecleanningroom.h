#ifndef FORMCHANGECLEANNINGROOM_H
#define FORMCHANGECLEANNINGROOM_H

#include <QWidget>

namespace Ui {
class FormChangeCleanningRoom;
}

class FormChangeCleanningRoom : public QWidget
{
    Q_OBJECT

public:
    explicit FormChangeCleanningRoom(QWidget *parent = nullptr);
    ~FormChangeCleanningRoom();
signals:
    void signalSendToServer(QByteArray&);

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormChangeCleanningRoom *ui;
};

#endif // FORMCHANGECLEANNINGROOM_H
