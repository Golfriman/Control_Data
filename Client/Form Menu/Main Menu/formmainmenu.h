#ifndef FORMMAINMENU_H
#define FORMMAINMENU_H

#include <QWidget>
#include <QChart>
#include "../const.h"
#include <QChartView>
#include <QLineSeries>
namespace Ui {
class FormMainMenu;
}

class FormMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit FormMainMenu(QWidget *parent = nullptr);

    ~FormMainMenu();
private:
    void createSeries(QLineSeries *& series, QColor color, QString name);
    void createChart();
    void createView();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);
private:
    QChart* chart;
    QChartView* view;
    QLineSeries* seriesBooking;
    QLineSeries* seriesLiving;
    QByteArray data;
    Ui::FormMainMenu *ui;
};

#endif // FORMMAINMENU_H
