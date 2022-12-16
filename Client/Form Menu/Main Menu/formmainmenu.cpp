#include "formmainmenu.h"
#include "ui_formmainmenu.h"
#include <QDate>
#include <QEasingCurve>


FormMainMenu::FormMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMainMenu)
{
    ui->setupUi(this);
    createView();
    ui->frame_4->layout()->addWidget(view.get());
}

void FormMainMenu::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormMainMenu::~FormMainMenu()
{
    delete ui;
}

void FormMainMenu::createSeries(QScopedPointer<QLineSeries>&series, QColor color, QString name)
{
    series.reset(new QLineSeries());
    series->setPen(QPen(color));
    series->setName(name);
}

void FormMainMenu::createChart()
{
    chart.reset(new QChart());

    createSeries(seriesLiving, Qt::blue, "Заселение за последние 30 дней");
    chart->addSeries(seriesLiving.get());
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 30);
    chart->axes(Qt::Horizontal).first()->setTitleText("Активность за последние 30 дней");
    chart->axes(Qt::Vertical).first()->setRange(0, 26);
    chart->axes(Qt::Vertical).first()->setTitleText("Количество занятых номеров");
    chart->setAnimationDuration(1000);
    chart->setAnimationOptions(QChart::SeriesAnimations);
}

void FormMainMenu::createView()
{
    this->createChart();
    view.reset(new QChartView(chart.get()));
    view->setRenderHint(QPainter::Antialiasing);
}

void FormMainMenu::slotGetData(QDataStream &in)
{
    seriesLiving->clear();
    in >> free >> vacant >> booked >> overdue;
    ui->free->setText(free);
    ui->vacant->setText(vacant);
    ui->booked->setText(booked);
    ui->overdue->setText(overdue);
    int size;
    in >> size;
    for(int i = 0; i < size;i++)
    {
        int x,y;
        in >> y;
        in >> x;
        seriesLiving->append(x, y);
    }
    in >> money;
    ui->money->setText(money);
    //view->grab().save("Graphics.png", "PNG");
}
