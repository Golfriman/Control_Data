#include "formcheckin.h"
#include "ui_formcheckin.h"

FormCheckIn::FormCheckIn(QString& idEmployee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCheckIn)
{
    ui->setupUi(this);
    this->idEmployee = idEmployee;
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
        QLayoutItem* itm;
        while((itm = ui->scrollAreaWidgetContents->layout()->takeAt(0))!= nullptr)
        {
            delete itm->widget();
            delete itm;
        }
        int size;
        in >> size;
        auto layout = ui->scrollAreaWidgetContents->layout();
        layout->setAlignment(Qt::AlignTop);
        for(int i = 0; i < size; i++)
        {
            QString id;
            QString status;
            in >> id >> status;
            QString value = "Заселение №" + id + " " + status;
            QPushButton* btn = new QPushButton(value);
            map.emplace(value, id);
            connect(btn, &QPushButton::clicked, this, [this](){
                auto btn = (QPushButton*)sender();
                QByteArray data;
                QDataStream out(&data, QIODevice::WriteOnly);
                out << Form::CHECK_IN << Send::ONE << Type::SHOW_CHECK_IN << map[btn->text()];
                qDebug() <<"Hello world!";
                emit this->signalSendToServer(data);
            });
            layout->addWidget(btn);

        }
        break;
    }
    case Type::SHOW_CHECK_IN:
    {
        itm.reset(new ItemCheckIn(idEmployee, in));
        itm.get()->show();
        connect(itm.get(), SIGNAL(sendToServer(const QByteArray&)), this, SLOT(slotPrepareSendToServer(const QByteArray&)));
        break;
    }
    case Type::ARCHIVE:
    {
        archive->slotGetData(in);
        break;
    }
    case Type::CONSTANT:
    {
        itm->getConstant(in);
        break;
    }

    case Type::ADD:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат добавления услуг", info);
        break;
    }
    case Type::CHECK_OUT_FROM:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат выселения", info);
        break;
    }
    case Type::PAY:
    {
        QString info;
        in >> info;
        QMessageBox::about(this, "Результат продления заселения", info);
        break;
    }
    default:
        break;
    }
}

void FormCheckIn::slotPrepareSendToServer(const QByteArray &data)
{
    QByteArray newData;
    QDataStream out(&newData, QIODevice::WriteOnly);
    out << Form::CHECK_IN;
    newData.append(data);
    emit signalSendToServer(newData);
}

void FormCheckIn::on_pushButton_clicked()
{
    archive.reset(new FormArchiveCheckIn());
    connect(archive.get(), SIGNAL(signalArchive(const QByteArray&)), this, SLOT(slotPrepareSendToServer(const QByteArray&)));
    archive->show();
}

