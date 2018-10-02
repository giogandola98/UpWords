#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dizionario.h"
#include "costanti.h"
#include "terreno.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new dizionario("C:\\Users\\giorgio\\Documents\\GitHub\\UpWords\\dizionario\\it_IT.txt");
    terrain=new(Terreno);
    s = new(sacchetto);
    terrainWidgetInit();
    //QMessageBox::information(this, "",QString::number(terrain->getElement(1,1)));
    UpdateTerrain(terrain);
    game_started=false;
}
void MainWindow::terrainWidgetInit()
{
    ui->tableWidget->setRowCount(costanti::DIM_CAMPOGIOCO);
    ui->tableWidget->setColumnCount(costanti::DIM_CAMPOGIOCO);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setOffset(0);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(45);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(45);
    ui->tableWidget->verticalHeader()->setOffset(0);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}
MainWindow::~MainWindow()
{
    delete ui;
    delete d;
    delete terrain;
}
void MainWindow::fillGamerHand(giocatore g)
{
    while(!g.hand_full()&&(!s->this_is_empty()))
    {
        g.add_letter(s->convert_to_char(s->extract_letter()));
    }
}
void MainWindow::onTurnSwitched()
{
  //riempio la mano del nuovo giocatore
  fillGamerHand(giocatori.at(turno_giocatore));
  //cambio il punteggio a video con quello del nuovo giocatore
  ui->points_txt->setText(QString::number(giocatori.at(turno_giocatore).get_points()));
  //cambio le lettere a video con quelle del nuovo giocatore
  ui->lettere_table->clear();
  for(std::size_t i = 0; i< costanti::MAX_LETTERS_HAND;i++)
  {
    QString item;
    item.append(giocatori.at(turno_giocatore).get_letter(i));
    ui->lettere_table->setItem(0,i,new QTableWidgetItem(item));
  }

  ui->turno_giocatore->setText(QString::number(turno_giocatore+1));
  //qui devo fare lo switch del giocatore nell'array giocatori

}
void MainWindow::on_pushButton_6_clicked()  //passa il turno
{
    if(game_started)
    {
        if(MainWindow::turno_giocatore<giocatori.size())
            MainWindow::turno_giocatore++;
        else
            MainWindow::turno_giocatore=0;
        onTurnSwitched();
    }
}
void MainWindow::UpdateTerrain(Terreno *terrain)
{
    for(std::size_t x = 0;x<costanti::DIM_CAMPOGIOCO;x++)
        for(std::size_t y =0;y<costanti::DIM_CAMPOGIOCO;y++)
        {
            QString item;
            item.append(terrain->getElement(x,y));
            ui->tableWidget->setItem(x,y,new QTableWidgetItem(item));
            item.clear();
        }
    ui->tableWidget->update();
    ui->tableWidget->show();

}
void MainWindow::on_pushButton_7_clicked()  //suggerimento
{
    if(game_started)
    {
        char letters[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
        for(std::size_t x=0;x<costanti::TERRAIN_SIZE_X;x++)
            for(std::size_t y=0;y<costanti::TERRAIN_SIZE_Y;y++)
                letters[x][y]=terrain->getElement(x,y);

        //chamo il combinatore
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(game_started)
    {

    }

}
void MainWindow::start_game()
{
    if(giocatori.size()>costanti::MIN_PLAYERS)
    {
        game_started=true;
        turno_giocatore=0;
        onTurnSwitched();
    }
}
void MainWindow::add_player()
{
  //aprire la finestra per inserimento giocatore (se possibile)
}

