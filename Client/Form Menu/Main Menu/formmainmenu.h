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
    void createSeries(QScopedPointer<QLineSeries> &series, QColor color, QString name);
    void createChart();
    void createView();
public slots:
    void slotGetData(QDataStream& in);
    void callSignal(QString filter = "");
signals:
    void signalSendToServer(QByteArray&);
private:
    QString money;
    QString free;
    QString vacant;
    QString booked;
    QString overdue;
    QScopedPointer<QChart> chart;
    QScopedPointer<QChartView> view;
    QScopedPointer<QLineSeries> seriesLiving;
    //QLineSeries* seriesLiving;
    QByteArray data;
    Ui::FormMainMenu *ui;
};

#endif // FORMMAINMENU_H
