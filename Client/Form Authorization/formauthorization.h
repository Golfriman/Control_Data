#ifndef FORMAUTHORIZATION_H
#define FORMAUTHORIZATION_H
#include "../const.h"
#include "qpushbutton.h"
#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QDataStream>

namespace Ui {
class FormAuthorization;
}

class FormAuthorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormAuthorization(QWidget *parent = nullptr);
    void showStatusConnection(bool ans, const QString& str = "");
    ~FormAuthorization();
    QString getFullname()
    {
        return fullname;
    }
protected:
    virtual void hideEvent(QHideEvent*)override;
    virtual void closeEvent(QCloseEvent*)override;
private:
    void clearLineEdit();
    void createEffect();
    void createValidation();
public slots:
    void update(QDataStream& in);
signals:
    void request(QByteArray&);
    void login(const QString&);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_checkBox_stateChanged(int arg1);
    void on_password_returnPressed();
    void on_quitButton_clicked();

private:
    QString fullname;
    bool lastConnectionToHost;
    QString idEmployee;
    bool successful{false};
    Ui::FormAuthorization *ui;
    QByteArray data;
    QGraphicsDropShadowEffect* effect;
};

#endif // FORMAUTHORIZATION_H
