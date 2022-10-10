#ifndef STATEROOMWORKER_H
#define STATEROOMWORKER_H

#include <QObject>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>

class StateRoomWorker : public QObject
{
    Q_OBJECT
public:
    explicit StateRoomWorker(QSqlDatabase& db, QObject *parent = nullptr);
public slots:
    void process();
signals:
private:
    QSqlDatabase& db;
    QDate date;
};

#endif // STATEROOMWORKER_H
