#include "mainwindow.h"
#include <QApplication>

#include <dizionario.h>
#include <chrono>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    //start grafica. il codice dizionario si trova in mainwindows.cpp
    w.show();
    return a.exec();
}
