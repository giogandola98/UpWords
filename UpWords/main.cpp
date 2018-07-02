
//settings
#define DEBUG false
#define STATISTICS false
#define DEBUG_DIZIONARIO false;
#define DIM_CAMPO_GIOCO 10
#define DATA_PATH  "DATA.dat"
#define PATH_SFX "C:\\Users\\giorgio\\Desktop\\dizionario\\it_IT.aff"
//end settings
#include "mainwindow.h"
#include <QApplication>
#include <dizionario.h>
#include <chrono>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    auto start = std::chrono::high_resolution_clock::now();
    dizionario d ("C:\\Users\\giorgio\\Desktop\\dizionario\\it_IT.txt");
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "dizionario_time: " << elapsed.count() << std::endl;
    w.show();
    return a.exec();
}
