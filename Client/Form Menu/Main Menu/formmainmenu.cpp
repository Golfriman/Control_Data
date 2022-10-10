#include "formmainmenu.h"
#include "ui_formmainmenu.h"
#include <QDate>
#include <QEasingCurve>


FormMainMenu::FormMainMenu(QWidget *parent) :
    QWidget(parent),
    seriesBooking(nullptr),
    seriesLiving(nullptr),
    ui(new Ui::FormMainMenu)
{
    ui->setupUi(this);
    createView();
    ui->frame_4->layout()->addWidget(view);
    for(float i = 0; i < 30; i+=0.5)
    {
        *seriesBooking << QPointF(i, i + rand()% 2);
        *seriesLiving << QPointF(i, i + rand()%2);
    }
}

void FormMainMenu::callSignal(QString filter)
{
    emit signalSendToServer(data);
}

FormMainMenu::~FormMainMenu()
{
    delete ui;
}

void FormMainMenu::createSeries(QLineSeries *&series, QColor color, QString name)
{
    series = new QLineSeries();
    series->setPen(QPen(color));
    series->setName(name);
}

void FormMainMenu::createChart()
{
    chart = new QChart();
    chart->addSeries(seriesLiving);
    chart->addSeries(seriesBooking);

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 30);
    chart->axes(Qt::Horizontal).first()->setTitleText("Активность за последние 30 дней");
    chart->axes(Qt::Vertical).first()->setRange(0, 100);
    chart->axes(Qt::Vertical).first()->setTitleText("Количество занятых номеров");
    chart->setAnimationDuration(1000);
    chart->setAnimationOptions(QChart::SeriesAnimations);
}

void FormMainMenu::createView()
{
    createSeries(seriesBooking, Qt::red, "Бронирование");
    createSeries(seriesLiving, Qt::blue, "Заселение");
    createChart();
    view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
}

void FormMainMenu::slotGetData(QDataStream &in)
{
    qDebug() << "SLOT MAIN MENU";

    view->grab().save("Graphics.png", "PNG");
}
