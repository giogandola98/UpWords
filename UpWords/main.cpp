#include "mainwindow.h"
#include <QApplication>

#include <dizionario.h>
#include <chrono>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    std::cout<<"STARTING"<<std::endl;
    dizionario d ("C:\\Users\\giorgio\\Documents\\GitHub\\UpWords\\dizionario\\it_IT.txt");
    std::string test="CIAO";
    std::cout<< "verifica in corso "<<d.exist(test);




    //start grafica
    w.show();
    return a.exec();
}
