#ifndef SQLWORKER_H
#define SQLWORKER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <iostream>

class SqlWorker : public QObject
{
    Q_OBJECT
public:
    explicit SqlWorker(QSqlDatabase& db, QObject *parent = nullptr);
public slots:
    void process();
    void stop();
private:
    QSqlDatabase& db;

signals:

};

#endif // SQLWORKER_H
