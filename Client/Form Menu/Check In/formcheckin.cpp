#include "formcheckin.h"
#include "ui_formcheckin.h"

FormCheckIn::FormCheckIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCheckIn)
{
    ui->setupUi(this);
}

FormCheckIn::~FormCheckIn()
{
    delete ui;
}

void FormCheckIn::slotGetData(QDataStream &in)
{
    int type;
    in >> type;
    switch(type)
    {
    case Type::VIEW:
    {
        int size;
        in >> size;
        auto layout = ui->scrollAreaWidgetContents->layout();
        for(int i = 0; i < size; i++)
        {
            QString id;
            QString status;
            in >> id >> status;
            QString value = "Заселение" + id + "\t" + status;
            QPushButton* btn = new QPushButton(value);
            map.emplace(value, id);
            connect(btn, &QPushButton::clicked, this, [this](){
                auto btn = (QPushButton*)sender();
                QByteArray data;
                QDataStream out(&data, QIODevice::WriteOnly);
                out << Form::CHECK_IN << Send::ONE << Type::SHOW_CHECK_IN << map[btn->text()];
                emit this->signalSendToServer(data);
            });
            layout->addWidget(btn);

        }
        break;
    }
    case Type::SHOW_CHECK_IN:
    {
        itm.reset(new ItemCheckIn(in));
        itm->show();
        connect(itm.get(), SIGNAL(sendToServer(const QByteArray&)), this, SLOT(slotPrepareSendToServer(const QByteArray&)));
        break;
    }
    default:
        break;
    }
}

void FormCheckIn::slotPrepareSendToServer(const QByteArray &)
{
    QByteArray newData;
    QDataStream out(&newData, QIODevice::WriteOnly);
    out << Form::CHECK_IN;
    newData.append(data);
    emit signalSendToServer(newData);
}
