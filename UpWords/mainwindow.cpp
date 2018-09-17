#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dizionario.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    dizionario f("C:\\Users\\giorgio\\Documents\\GitHub\\UpWords\\dizionario\\it_IT.txt");
    d=&f;
    terrain = new(Terreno);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_6_clicked()  //passa il turno
{
   if(MainWindow::turn_g<MainWindow::n_gamers)
     MainWindow::n_gamers++;
   else
       MainWindow::n_gamers=0;
}

void MainWindow::on_pushButton_7_clicked()  //suggerimento
{
    char letters[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
    for(std::size_t x=0;x<costanti::TERRAIN_SIZE_X;x++)
        for(std::size_t y=0;y<costanti::TERRAIN_SIZE_Y;y++)
          letters[x][y]=terrain->getElement(x,y);

    //c=new (Combinatore(giocatori.at(MainWindow::turn_g).,d,letters))//sostemare
}
