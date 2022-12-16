#include "client.h"

#include <QApplication>
#include <QDataStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFontDatabase::addApplicationFont(":/font/Inter-Regular.otf");
    Client client("localhost", 25600);
    QApplication::setQuitOnLastWindowClosed(false);
    return a.exec();
}
