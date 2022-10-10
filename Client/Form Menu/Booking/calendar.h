#ifndef CALENDAR_H
#define CALENDAR_H

#include <QCalendarWidget>
#include <QTextCharFormat>

class Calendar : public QCalendarWidget
{
    Q_OBJECT
public:
    Calendar(QObject* parent = nullptr);
public slots:
    void dateClicked(QDate);
signals:
    void signalCheckIn(QDate&);
    void signalCheckOut(QDate&);
    void finished();
private:
    void formatRange(QTextCharFormat format = QTextCharFormat());
private:
    QTextCharFormat highlight;
    QDate beginDate;
    QDate endDate;
};

#endif // CALENDAR_H
