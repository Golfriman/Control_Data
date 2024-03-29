#include "formauthorization.h"
#include "ui_formauthorization.h"
#include "validator.h"
#include <qmessagebox.h>

FormAuthorization::FormAuthorization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormAuthorization)
{
    this->setWindowTitle("Dashboard - Авторизация");
    ui->setupUi(this);
    createEffect();
    //ui->quitButton->setGraphicsEffect(effect);
    ui->pushButton->setGraphicsEffect(effect);
    ui->label_6->hide();
    lastConnectionToHost = true;
    ui->quitButton->hide();
    createValidation();

}
FormAuthorization::~FormAuthorization()
{
    delete ui;
}

void FormAuthorization::showStatusConnection(bool ans, const QString& str)
{
    if(ans)
    {
        ui->statusBar->showMessage("Вы подключены к серверу");
    }
    else
    {
        ui->statusBar->showMessage("Ошибка подключения: " + str);
    }
    if(lastConnectionToHost == ans)
    {
        return;
    }
    if(!ans)
    {
        ui->quitButton->show();
        ui->pushButton->hide();
    }
    else
    {
        ui->quitButton->hide();
        ui->pushButton->show();
    }
    lastConnectionToHost = ans;

}

void FormAuthorization::hideEvent(QHideEvent *)
{
    ui->login->setFocus();
    clearLineEdit();
}

void FormAuthorization::closeEvent(QCloseEvent *)
{
    qApp->exit();
}

void FormAuthorization::clearLineEdit()
{
    ui->login->clear();
    ui->password->clear();
}

void FormAuthorization::createEffect()
{
    effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(12);
    effect->setOffset(0,4);
    effect->setColor(qRgb(207, 213, 255));

}

void FormAuthorization::createValidation()
{
    auto validate = new Validator;
    ui->login->setValidator(validate);
    ui->password->setValidator(validate);
}

void FormAuthorization::update(QDataStream &in)
{
    in >> successful;
    if(successful)
    {
        bool result;
        QString fullname;
        in >> idEmployee >>result >> fullname;
        if(result)
            emit login(idEmployee, fullname);
        else QMessageBox::about(this, "Результат авторизации", "Вы не имеет прав доступа, для того чтобы пользоваться этим приложением");
    }
    else
    {
        ui->label_6->show();
    }
}

void FormAuthorization::on_pushButton_clicked()
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out <<  Form::AUTHORIZATION << Send::ONE << ui->login->text() << ui->password->text() <<
            Form::ROOMS         << Send::ONE << Type::VIEW;
    emit request(data);
}


void FormAuthorization::on_pushButton_pressed()
{
    effect->setEnabled(false);
}


void FormAuthorization::on_pushButton_released()
{
    effect->setEnabled(true);
}


void FormAuthorization::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->password->setEchoMode(QLineEdit::Password);
    }
}

void FormAuthorization::on_password_returnPressed()
{
    if(ui->quitButton->isVisible())
    {
        this->on_quitButton_clicked();
    }
    this->on_pushButton_clicked();
}

void FormAuthorization::on_quitButton_clicked()
{
    qApp->quit();
}

