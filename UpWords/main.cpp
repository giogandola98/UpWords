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
