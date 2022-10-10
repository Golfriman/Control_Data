#include "calendar.h"
#include <QApplication>

Calendar::Calendar(QObject *parent)
{
    highlight.setBackground(this->palette().brush(QPalette::Highlight));
    highlight.setForeground(this->palette().brush(QPalette::HighlightedText));
    connect(this, SIGNAL(clicked(QDate)), this, SLOT(dateClicked(QDate)));
    setDateRange(QDate::currentDate(), QDate::currentDate().addDays(30));
    beginDate = (QDate::currentDate().addDays(-1));
    endDate = beginDate;
    setWindowTitle("Календарь");
    setWindowModality(Qt::ApplicationModal);

}

void Calendar::dateClicked(QDate date)
{
    if(beginDate < QDate::currentDate())
    {

        beginDate = minimumDate();
        endDate = maximumDate();
        formatRange();
        beginDate = date;
        emit signalCheckIn(beginDate);

    }
    else if(beginDate < date)
    {
        endDate = date;
        emit signalCheckOut(endDate);
        formatRange(highlight);
    }
    else{
        beginDate = date;
        emit signalCheckIn(beginDate);
    }

}

void Calendar::formatRange(QTextCharFormat format)
{
    while(beginDate <= endDate)
    {
        setDateTextFormat(beginDate, format);
        beginDate = beginDate.addDays(1);
    }
    beginDate = QDate::currentDate().addDays(-1);
}
