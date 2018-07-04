#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dizionario.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dizionario d ("C:\\Users\\giorgio\\Documents\\GitHub\\UpWords\\dizionario\\it_IT.txt");
    std::string test="CIAO";
    std::cout<< "verifica in corso "<<d.exist(test);

}

MainWindow::~MainWindow()
{
    delete ui;
}
