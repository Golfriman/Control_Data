#include "stateroomworker.h"
StateRoomWorker::StateRoomWorker(QSqlDatabase &db, QObject *parent)
    :QObject(parent),
      db(db)
{
    date = QDate::currentDate().addDays(-1);
}

void StateRoomWorker::process()
{
    while(true)
    {
        if(date != QDate::currentDate())
        {
            date = QDate::currentDate();
            QSqlQuery q("UPDATE room, workhotel set room.status = \'Требуется уборка\'"
                            "where (room.idroom = workhotel.idroom) and (workhotel.namework = \'Уборка\')"
                            "and (current_date() <= (3 + (select max(time) from workhotel where workhotel.idroom = room.idroom))", db);
        }
        QThread::sleep(3600);
    }
}
