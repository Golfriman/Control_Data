#include "formbooking.h"
#include "ui_formbooking.h"
#include "formcreatebooking.h"
FormBooking::FormBooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBooking)
{
    ui->setupUi(this);
}

void FormBooking::getData(QDataStream &in)
{
    int SIZE;
    in >> SIZE;
    qDebug() << SIZE;
    auto layout = ui->scrollAreaWidgetContents->layout();
    for(size_t i = 0u; i < SIZE; i++)
    {
        QString id, fio;
        in >> id >> fio;
        id = "Бронирование №" + id;
        layout->addWidget(new ItemBooking(id, fio));
    }
}
//В out там должна быть о информация о типе запроса.
void FormBooking::callSignal(const QByteArray& out)
{
    data.clear();
    QDataStream outBooking(&data, QIODevice::WriteOnly);
    outBooking << Form::BOOKING << Send::ALL << out ;
    emit signalSendToServer(data);
}

void FormBooking::slotSignUp()
{
    emit signalSignUp();
}

FormBooking::~FormBooking()
{
    delete ui;
}

void FormBooking::on_pushButton_clicked()
{
    FormCreateBooking* createBooking = new FormCreateBooking;
    connect(createBooking, SIGNAL(signalCreateBooking(const QByteArray&)), this, SLOT(callSignal(const QByteArray&)));
    connect(createBooking, SIGNAL(signalSignUp()), createBooking, SLOT(deleteLater()));
    connect(createBooking, SIGNAL(signalSignUp()), this, SLOT(slotSignUp()));
    createBooking->show();
}

