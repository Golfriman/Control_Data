#ifndef MAINMENU_H
#define MAINMENU_H

#include "command.h"

class MainMenu: public Command
{
    QSqlQuery *q;
public:
    MainMenu(int command);
    MainMenu()=default;
    MainMenu(QDataStream& stream);
    QByteArray execute(QSqlDatabase& db)override;
    ~MainMenu();
};

#endif // MAINMENU_H
