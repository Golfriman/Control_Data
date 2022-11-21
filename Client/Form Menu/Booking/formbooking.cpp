#include "formbooking.h"
#include "ui_formbooking.h"
FormBooking::FormBooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBooking)
{
    ui->setupUi(this);
}

void FormBooking::getData(QDataStream &in)
{
    int type;
    in >> type;
    auto showBooking = [&](auto layout)
    {
        int size;
        in>>size;
        layout->setAlignment(Qt::AlignTop);
        for(int i = 0; i < size; i++)
        {
            std::vector<QString> v(8, "");
            for(int j = 0; j < 8; j++) in >> v[j];

            QString name = "Бронирование №" + v[0];
            QPushButton* btn = new QPushButton(name);
            layout->addWidget(btn);
            connect(btn, &QPushButton::clicked, this, [&](){
                auto current = (QPushButton*)sender();
                auto i = current->text();
                window.reset(new ItemBooking(dict[i], services));
                connect(window.get(), SIGNAL(signalBooking(const QByteArray&)), this, SLOT(callSignal(const QByteArray&)));
                connect(window.get(), SIGNAL(signalBookingRoom(const QByteArray&)), this, SLOT(callFindRoom(const QByteArray&)));
                window->show();
            });
            int countServices;
            in >> countServices;
            for(int j = 0; j < countServices; j++)
            {
                QString service;
                in >> service;
                v.push_back(service);
            }
            dict.emplace(name, std::move(v));
        }
    };
    auto clear = [&](QLayout* layout)
    {
        QLayoutItem* itm;
        while((itm = layout->takeAt(0))!= nullptr)
        {
            delete itm->widget();
            delete itm;
        }
    };
    switch(type)
    {
    case Type::VIEW:
    {
        clear(ui->scrollAreaWidgetContents->layout());
        clear(ui->scrollAreaWidgetContents_4->layout());
        clear(ui->scrollAreaWidgetContents_5->layout());

        showBooking(ui->scrollAreaWidgetContents->layout());
        showBooking(ui->scrollAreaWidgetContents_4->layout());
        showBooking(ui->scrollAreaWidgetContents_5->layout());
        //ui->stackedWidget->setCurrentWidget(ui);
        break;
    }
    case Type::FIND:
        createBooking->slotGetFindResult(in);
        break;
    case Type::INSERT:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат создания бронирования:", info);
        break;
    }
    case Type::DROP:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат удаления брони:", info);
        break;
    }
        break;
    case Type::UPDATE:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат обновления брони:", info);
        break;
    }
        break;
    case Type::CONSTANT:
    {
        int countServices;
        in>>countServices;
        services.resize(countServices);
        for(auto& i: services)
            in >> i.first >> i.second;
        break;
    }
    case Type::FIND_ROOM:
    {
        if(isItemBooking) window->slotGetRooms(in);
        else createBooking->slotGetFindRoomResult(in);
        break;
    }
    case Type::ACCEPT:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат подтверждения брони", info);
        break;
    }
    default:
    {
        qDebug() << "Неизвестный ID:" << type;
        break;
    }
    }
}
//В out там должна быть о информация о типе запроса.
void FormBooking::callSignal(const QByteArray& out)
{  
    qDebug() << "ЗДАРОВА Я ТУТ";
    isItemBooking = false;
    data.clear();
    QDataStream outBooking(&data, QIODevice::WriteOnly);
    outBooking << Form::BOOKING;
    data.append(out);
    emit signalSendToServer(data);
}

void FormBooking::slotSignUp()
{
    emit signalSignUp();
}

void FormBooking::callFindRoom(const QByteArray &out)
{
    isItemBooking = true;
    data.clear();
    QDataStream outBooking(&data, QIODevice::WriteOnly);
    outBooking << Form::BOOKING;
    data.append(out);
    emit signalSendToServer(data);
}

FormBooking::~FormBooking()
{
    delete ui;
}

void FormBooking::on_pushButton_clicked()
{
    createBooking.reset(new FormCreateBooking(services));
    connect(createBooking.get(), SIGNAL(signalCreateBooking(const QByteArray&)), this, SLOT(callSignal(const QByteArray&)));
    // connect(createBooking.get(), SIGNAL(signalSignUp()), createBooking.get(), SLOT(deleteLater()));
    // connect(createBooking.get(), SIGNAL(signalSignUp()), this, SLOT(slotSignUp()));
    createBooking->show();
}


void FormBooking::on_comboBox_currentIndexChanged(int index)
{
   switch(index)
   {
   case 0:
       ui->stackedWidget->setCurrentWidget(ui->page);
       break;
   case 1:
       ui->stackedWidget->setCurrentWidget(ui->page_2);
       break;
   case 2:
       ui->stackedWidget->setCurrentWidget(ui->page_3);
       break;
   }
}

