#include "mainmenu.h"
#include <iostream>

MainMenu::MainMenu(QDataStream& stream)
{
    stream >> type;
}

QByteArray MainMenu::execute(QSqlDatabase& db)
{
    init();
    *out << Form::MAIN_MENU;
    QSqlQuery q("SELECT * FROM showHotelStatus()", db);
    q.next();

    *out << q.value(0).toString() << //Свободно
            q.value(1).toString() << //заселено
            q.value(2).toString() << //забронировано
            q.value(3).toString();   //просроченная аренда
    QSqlQuery q2("SELECT * FROM statisticCheckInHotel();", db);
    q2.next();
    *out << 31;
    for(int i = 0; i < 31; i++)
    {
        if(q2.value(1).toInt() == i)
        {
            *out << q2.value(0).toInt();
            q2.next();
        }
        else
            *out << 0;
    }
    QSqlQuery q3("SELECT sumMoneyToday()", db);
    q3.next();
    *out << q3.value(0).toString();
    return data;
}

MainMenu::~MainMenu()
{
    delete out;
}
