#include "sqlworker.h"
#include <iomanip>

SqlWorker::SqlWorker(QSqlDatabase &db, QObject *parent): QObject(parent), db(db)
{

}

void SqlWorker::process()
{
    system("chcp 65001 > nul");

    QSqlQuery q(db);
    while(true)
    {
        std::string line;

        //std::cout << "SQL: ";
        std::getline(std::cin, line);
        if(line.empty())
        {
            continue;
        }
        if(line == "?")
        {
            std::cout << "SQL terminal for working with the database. Here you need to enter queries to the database." << std::endl;
            continue;
        }
        if(line == "cls")
        {
            system("cls");
            continue;
        }
        std::time_t start = clock();
        q.exec(QString::fromStdString(line));
        std::time_t end = clock();
        if(!q.isActive())
        {
            std::cout << "Error query, " ;
        }
        else
        {
            std::cout << "Success query, ";
        }
        std::cout << (end - start) << " ms." << std::endl;
    }
}

void SqlWorker::stop()
{
}
