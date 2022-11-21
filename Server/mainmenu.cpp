#include "mainmenu.h"

MainMenu::MainMenu(QDataStream& stream)
{
    stream >> type;
}

QByteArray MainMenu::execute(QSqlDatabase& db)
{
    init();
    *out << Form::MAIN_MENU;
    return data;
}

MainMenu::~MainMenu()
{
    delete out;
}
