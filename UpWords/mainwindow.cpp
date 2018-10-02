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
    UpdateTerrain(terrain);
    game_started=false;
    add_player();
    add_player();
    add_player();
    add_player();
    start_game();
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
void MainWindow::fillGamerHand(giocatore &g)
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
        if(MainWindow::turno_giocatore<giocatori.size()-1)
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
        std::string hand="";
        for(std::size_t i =0;i<costanti::MAX_LETTERS_HAND;i++)
            hand+=(giocatori.at(turno_giocatore).get_letter(i));
        //chamo il combinatore
        Combinatore c (hand,d,letters);
        QMessageBox::information(this, "SUGGERIMENTO",QString::fromStdString(c.suggerimento()));
    }
}
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(game_started)
    {

    }

}
void MainWindow::setPlayerLabel()
{
   ui->giocatori_table->setRowCount(1);
   ui->giocatori_table->setColumnCount(giocatori.size());
   ui->giocatori_table->verticalHeader()->setVisible(false);
   ui->giocatori_table->horizontalHeader()->setOffset(0);
   ui->giocatori_table->horizontalHeader()->setDefaultSectionSize((ui->giocatori_table->maximumWidth()/giocatori.size())-ui->giocatori_table->maximumWidth()%giocatori.size());
   ui->giocatori_table->verticalHeader()->setDefaultSectionSize(ui->giocatori_table->maximumHeight());
   ui->giocatori_table->verticalHeader()->setOffset(0);
   ui->giocatori_table->horizontalHeader()->setVisible(false);
   ui->giocatori_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
   for(std::size_t i = 0;i<giocatori.size();i++)
   {
        giocatore g = giocatori.at(i);
        ui->giocatori_table->setItem(0,i,new QTableWidgetItem(QString::fromStdString(g.get_name())));
    }
}
void MainWindow::setLettersTable()
{
    ui->lettere_table->setRowCount(1);
    ui->lettere_table->setColumnCount(costanti::MAX_LETTERS_HAND);
    ui->lettere_table->verticalHeader()->setVisible(false);
    ui->lettere_table->horizontalHeader()->setOffset(0);
    ui->lettere_table->horizontalHeader()->setDefaultSectionSize((ui->lettere_table->width()/costanti::MAX_LETTERS_HAND)-(ui->giocatori_table->width()%costanti::MAX_LETTERS_HAND));
    ui->lettere_table->verticalHeader()->setDefaultSectionSize(ui->lettere_table->height());
    ui->lettere_table->verticalHeader()->setOffset(0);
    ui->lettere_table->horizontalHeader()->setVisible(false);
    ui->lettere_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void MainWindow::start_game()
{
    if(giocatori.size()>costanti::MIN_PLAYERS)
    {
        game_started=true;
        turno_giocatore=0;
        setLettersTable();
        setPlayerLabel();
        onTurnSwitched();
    }
}
void MainWindow::add_player()
{
  //aprire la finestra per inserimento giocatore (se possibile)
    if(giocatori.size()<costanti::MAX_PLAYERS)
    {
        //.....
        std::string nome="c";
        giocatore g(nome);
        giocatori.push_back(g);
    }
}

